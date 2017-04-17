#include <stdio.h>
#include <stdarg.h>
#include "calc3.h"
#include "y.tab.h"
#include "strmap.h"

static int lbl;
static int globalSymIdx;
static int funcSymIdx;
static int funcCallLevel;

void programStarts() {
    globalSymTab = sm_new(GLOBAL_SIZE);
    funcSymTab = sm_new(FUNC_SIZE);
    globalSymIdx = 0;
    funcSymIdx = 0;
    funcCallLevel = 0; // global level
}

void programEnds() {
    sm_delete(globalSymTab);
    sm_delete(funcSymTab);
}

void getGlobalReg(char* reg, char* name) {
    if (sm_exists(globalSymTab, name)) {
        sm_get(globalSymTab, name, reg, 6);
    } else {
        sprintf(reg, "sb[%d]", globalSymIdx++);
        sm_put(globalSymTab, name, reg);
    }
}

void getLocalReg(char* reg, char* name) {

}

void getReg(char* reg, char* name) {
    if (funcCallLevel == 0) {
        getGlobalReg(reg, name);
    } else {

    }
}

int ex(nodeType *p, int nops, ...) {
    int lblx, lbly, lblz, lbl1, lbl2, lbl_init = lbl, lbl_kept;
    char reg[6];

    // retrieve lbl_kept
    va_list ap;
    va_start(ap, nops);
    for (int i = 0; i < nops; i++)
        lbl_kept = va_arg(ap, int);

    if (!p) return 0;
    switch(p->type) {
        case typeCon:       
            switch(p->con.type){
                case conTypeNull:
                case conTypeInt:
                    printf("\tpush\t%d\n", p->con.value); 
                    break;
                case conTypeChar:
                    printf("\tpush\t\'%c\'\n", (char) p->con.value); 
                    break;
                case conTypeStr:
                    printf("\tpush\t\"%s\"\n", p->con.strValue); 
                    break;
            }
            break;
        case typeId:      
            getGlobalReg(reg, p->id.varName);
            printf("\tpush\t%s\n", reg); 
            break;
        case typeArr:
            ex(p->array.offset, 1, lbl_kept);
            printf("\tpushi\t%s\n", p->array.baseName); 
            break;
        case typeFunc:

        case typeOpr:
            switch(p->opr.oper) {
                case FOR:
                    lblz = lbl++;
                    lbly = lbl++;
                    lblx = lbl++;
                    ex(p->opr.op[0], 1, lbl_kept);
                    printf("L%03d:\n", lblx);
                    ex(p->opr.op[1], 1, lbl_kept);
                    printf("\tj0\tL%03d\n", lbly);
                    ex(p->opr.op[3], 1, lbl_init);
                    printf("L%03d:\n", lblz); // for continue
                    ex(p->opr.op[2], 1, lbl_kept);
                    printf("\tjmp\tL%03d\n", lblx);
                    printf("L%03d:\n", lbly);
                    break;
                case WHILE:
                    lbl1 = lbl++;
                    lbl2 = lbl++; // consistent order continue_target -> break target, as with FOR
                    printf("L%03d:\n", lbl1);
                    ex(p->opr.op[0], 1, lbl_kept);
                    printf("\tj0\tL%03d\n", lbl2);
                    ex(p->opr.op[1], 1, lbl_init);
                    printf("\tjmp\tL%03d\n", lbl1);
                    printf("L%03d:\n", lbl2);
                    break;
                case IF:
                    lbl1 = lbl++;
                    ex(p->opr.op[0], 1, lbl_kept);
                    if (p->opr.nops > 2) {
                        lbl2 = lbl++;
                        /* if else */
                        printf("\tj0\tL%03d\n", lbl1);
                        ex(p->opr.op[1], 1, lbl_kept);
                        printf("\tjmp\tL%03d\n", lbl2);
                        printf("L%03d:\n", lbl1);
                        ex(p->opr.op[2], 1, lbl_kept);
                        printf("L%03d:\n", lbl2);
                    } else {
                        /* if */
                        printf("\tj0\tL%03d\n", lbl1);
                        ex(p->opr.op[1], 1, lbl_kept);
                        printf("L%03d:\n", lbl1);
                    }
                    break;
                case BREAK:
                    printf("\tjmp\tL%03d\n", lbl_kept + 1);
                    break;
                case CONTINUE:
                    printf("\tjmp\tL%03d\n", lbl_kept);
                    break;
                // case READ:
                //     printf("\tread\n");
                //     if (p->opr.op[0]->type == typeId) {
                //         printf("\tpop\t%s\n", p->opr.op[0]->id.varName);
                //     } else if (p->opr.op[0]->type == typeArr) {
                //         ex(p->opr.op[0]->array.offset, 1, lbl_kept);
                //         printf("\tpopi\t%s\n", p->opr.op[0]->array.baseName);
                //     }
                //     break;
                // case PRINT:     
                //     ex(p->opr.op[0], 1, lbl_kept);
                //     printf("\tputi\n");
                //     break;
                case GETI:
                    getReg(reg, p->opr.op[0]->id.varName);
                    printf("\tgeti\n"); 
                    break;
                case GETC: 
                    getReg(reg, p->opr.op[0]->id.varName);
                    printf("\tgetc\n"); 
                    break;
                case GETS: 
                    getReg(reg, p->opr.op[0]->id.varName);
                    printf("\tgets\n"); 
                    break;
                case PUTI: case PUTI_:
                    switch(p->opr.op[0]->type) {
                        case typeCon:
                            printf("\tpush\t%d\n", p->opr.op[0]->con.value);
                            if (p->opr.oper == PUTI) printf("\tputi\n"); else printf("\tputi_\n");
                            break;
                        case typeId:
                            getReg(reg, p->opr.op[0]->id.varName);
                            printf("\tpush\t%s\n", reg);
                            if (p->opr.oper == PUTI) printf("\tputi\n"); else printf("\tputi_\n");
                            break;
                        case typeArr:
                            getReg(reg, p->opr.op[0]->array.baseName);
                            printf("\tpush\t%s\n", reg);
                            if (p->opr.oper == PUTI) printf("\tputi\n"); else printf("\tputi_\n");
                        default:
                            ;
                    }
                    break;
                case PUTC: case PUTC_:
                    switch(p->opr.op[0]->type) {
                        case typeCon:
                            printf("\tpush\t\'%c\'\n", p->opr.op[0]->con.value);
                            if (p->opr.oper == PUTC) printf("\tputc\n"); else printf("\tputc_\n");
                            break;
                        case typeId:
                            getReg(reg, p->opr.op[0]->id.varName);
                            printf("\tpush\t%s\n", reg);
                            if (p->opr.oper == PUTC) printf("\tputc\n"); else printf("\tputc_\n");
                            break;
                        case typeArr:
                            getReg(reg, p->opr.op[0]->array.baseName);
                            printf("\tpush\t%s\n", reg);
                            if (p->opr.oper == PUTC) printf("\tputc\n"); else printf("\tputc_\n");
                        default:
                            ;
                    }
                    break;
                case PUTS: case PUTS_:
                    switch(p->opr.op[0]->type) {
                        case typeCon:
                            printf("\tpush\t\"%s\"\n", p->opr.op[0]->con.strValue);
                            if (p->opr.oper == PUTS) printf("\tputs\n"); else printf("\tputs_\n");
                            break;
                        case typeId:
                            getReg(reg, p->opr.op[0]->id.varName);
                            printf("\tpush\t%s\n", reg);
                            if (p->opr.oper == PUTS) printf("\tputs\n"); else printf("\tputs_\n");
                            break;
                        case typeArr:
                            getReg(reg, p->opr.op[0]->array.baseName);
                            printf("\tpush\t%s\n", reg);
                            if (p->opr.oper == PUTS) printf("\tputs\n"); else printf("\tputs_\n");
                        default:
                            ;
                    }
                    break;
                case '=':       
                    ex(p->opr.op[1], 1, lbl_kept);
                    if (p->opr.op[0]->type == typeId) {
                        getGlobalReg(reg, p->opr.op[0]->id.varName);
                        printf("\tpop\t%s\n", reg);
                    } else if (p->opr.op[0]->type == typeArr) {
                        ex(p->opr.op[0]->array.offset, 1, lbl_kept);
                        printf("\tpopi\t%s\n", p->opr.op[0]->array.baseName);
                    }
                    break;
                case UMINUS:    
                    ex(p->opr.op[0], 1, lbl_kept);
                    printf("\tneg\n");
                    break;
                default:
                    ex(p->opr.op[0], 1, lbl_kept);
                    ex(p->opr.op[1], 1, lbl_kept);
                    switch(p->opr.oper) {
                        case '+':   printf("\tadd\n"); break;
                        case '-':   printf("\tsub\n"); break; 
                        case '*':   printf("\tmul\n"); break;
                        case '/':   printf("\tdiv\n"); break;
                        case '%':   printf("\tmod\n"); break;
                        case '<':   printf("\tcompLT\n"); break;
                        case '>':   printf("\tcompGT\n"); break;
                        case GE:    printf("\tcompGE\n"); break;
                        case LE:    printf("\tcompLE\n"); break;
                        case NE:    printf("\tcompNE\n"); break;
                        case EQ:    printf("\tcompEQ\n"); break;
                        case AND:   printf("\tand\n"); break;
                        case OR:    printf("\tor\n"); break;
                    }
                }
    }
    return 0;
}
