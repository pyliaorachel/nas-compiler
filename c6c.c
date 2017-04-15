#include <stdio.h>
#include <stdarg.h>
#include "calc3.h"
#include "y.tab.h"

static int lbl;

int ex(nodeType *p, int nops, ...) {
    int lblx, lbly, lblz, lbl1, lbl2, lbl_init = lbl, lbl_kept;

    // retrieve lbl_kept
    va_list ap;
    va_start(ap, nops);
    for (int i = 0; i < nops; i++)
        lbl_kept = va_arg(ap, int);

    if (!p) return 0;
    switch(p->type) {
        case typeCon:       
            printf("\tpush\t%d\n", p->con.value); 
            break;
        case typeId:        
            printf("\tpush\t%c\n", p->id.i + 'a'); 
            break;
        case typeArr:
            ex(p->array.offset, 1, lbl_kept);
            printf("\tpushi\t%c\n", p->array.base + 'a'); 
            break;
        case typeOpr:
            switch(p->opr.oper) {
                case FOR:
                    lblz = lbl++;
                    lbly = lbl++;
                    lblx = lbl++;
                    ex(p->opr.op[0], 1, lbl_kept);
                    printf("L%03d:\n", lblx);
                    ex(p->opr.op[1], 1, lbl_kept);
                    printf("\tjz\tL%03d\n", lbly);
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
                    printf("\tjz\tL%03d\n", lbl2);
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
                        printf("\tjz\tL%03d\n", lbl1);
                        ex(p->opr.op[1], 1, lbl_kept);
                        printf("\tjmp\tL%03d\n", lbl2);
                        printf("L%03d:\n", lbl1);
                        ex(p->opr.op[2], 1, lbl_kept);
                        printf("L%03d:\n", lbl2);
                    } else {
                        /* if */
                        printf("\tjz\tL%03d\n", lbl1);
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
                case READ:
                    printf("\tread\n");
                    if (p->opr.op[0]->type == typeId) {
                        printf("\tpop\t%c\n", p->opr.op[0]->id.i + 'a');
                    } else if (p->opr.op[0]->type == typeArr) {
                        ex(p->opr.op[0]->array.offset, 1, lbl_kept);
                        printf("\tpopi\t%c\n", p->opr.op[0]->array.base + 'a');
                    }
                    break;
                case PRINT:     
                    ex(p->opr.op[0], 1, lbl_kept);
                    printf("\tprint\n");
                    break;
                case '=':       
                    ex(p->opr.op[1], 1, lbl_kept);
                    if (p->opr.op[0]->type == typeId) {
                        printf("\tpop\t%c\n", p->opr.op[0]->id.i + 'a');
                    } else if (p->opr.op[0]->type == typeArr) {
                        ex(p->opr.op[0]->array.offset, 1, lbl_kept);
                        printf("\tpopi\t%c\n", p->opr.op[0]->array.base + 'a');
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
