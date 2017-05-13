	// jump to main function unconditionally
	jmp	L000
	// test1 allocated with size 100
	// test2 allocated with size 10
	// i allocated with size 1
	// j allocated with size 1
	// function "main"
L000:
	// allocate space
	push	sp
	push	112
	add
	pop	sp

	// constant
	push	90
	// initialise test1
	push	sp[-1]
	pop	fp[0]
	push	sp[-1]
	pop	fp[1]
	push	sp[-1]
	pop	fp[2]
	push	sp[-1]
	pop	fp[3]
	push	sp[-1]
	pop	fp[4]
	push	sp[-1]
	pop	fp[5]
	push	sp[-1]
	pop	fp[6]
	push	sp[-1]
	pop	fp[7]
	push	sp[-1]
	pop	fp[8]
	push	sp[-1]
	pop	fp[9]
	push	sp[-1]
	pop	fp[10]
	push	sp[-1]
	pop	fp[11]
	push	sp[-1]
	pop	fp[12]
	push	sp[-1]
	pop	fp[13]
	push	sp[-1]
	pop	fp[14]
	push	sp[-1]
	pop	fp[15]
	push	sp[-1]
	pop	fp[16]
	push	sp[-1]
	pop	fp[17]
	push	sp[-1]
	pop	fp[18]
	push	sp[-1]
	pop	fp[19]
	push	sp[-1]
	pop	fp[20]
	push	sp[-1]
	pop	fp[21]
	push	sp[-1]
	pop	fp[22]
	push	sp[-1]
	pop	fp[23]
	push	sp[-1]
	pop	fp[24]
	push	sp[-1]
	pop	fp[25]
	push	sp[-1]
	pop	fp[26]
	push	sp[-1]
	pop	fp[27]
	push	sp[-1]
	pop	fp[28]
	push	sp[-1]
	pop	fp[29]
	push	sp[-1]
	pop	fp[30]
	push	sp[-1]
	pop	fp[31]
	push	sp[-1]
	pop	fp[32]
	push	sp[-1]
	pop	fp[33]
	push	sp[-1]
	pop	fp[34]
	push	sp[-1]
	pop	fp[35]
	push	sp[-1]
	pop	fp[36]
	push	sp[-1]
	pop	fp[37]
	push	sp[-1]
	pop	fp[38]
	push	sp[-1]
	pop	fp[39]
	push	sp[-1]
	pop	fp[40]
	push	sp[-1]
	pop	fp[41]
	push	sp[-1]
	pop	fp[42]
	push	sp[-1]
	pop	fp[43]
	push	sp[-1]
	pop	fp[44]
	push	sp[-1]
	pop	fp[45]
	push	sp[-1]
	pop	fp[46]
	push	sp[-1]
	pop	fp[47]
	push	sp[-1]
	pop	fp[48]
	push	sp[-1]
	pop	fp[49]
	push	sp[-1]
	pop	fp[50]
	push	sp[-1]
	pop	fp[51]
	push	sp[-1]
	pop	fp[52]
	push	sp[-1]
	pop	fp[53]
	push	sp[-1]
	pop	fp[54]
	push	sp[-1]
	pop	fp[55]
	push	sp[-1]
	pop	fp[56]
	push	sp[-1]
	pop	fp[57]
	push	sp[-1]
	pop	fp[58]
	push	sp[-1]
	pop	fp[59]
	push	sp[-1]
	pop	fp[60]
	push	sp[-1]
	pop	fp[61]
	push	sp[-1]
	pop	fp[62]
	push	sp[-1]
	pop	fp[63]
	push	sp[-1]
	pop	fp[64]
	push	sp[-1]
	pop	fp[65]
	push	sp[-1]
	pop	fp[66]
	push	sp[-1]
	pop	fp[67]
	push	sp[-1]
	pop	fp[68]
	push	sp[-1]
	pop	fp[69]
	push	sp[-1]
	pop	fp[70]
	push	sp[-1]
	pop	fp[71]
	push	sp[-1]
	pop	fp[72]
	push	sp[-1]
	pop	fp[73]
	push	sp[-1]
	pop	fp[74]
	push	sp[-1]
	pop	fp[75]
	push	sp[-1]
	pop	fp[76]
	push	sp[-1]
	pop	fp[77]
	push	sp[-1]
	pop	fp[78]
	push	sp[-1]
	pop	fp[79]
	push	sp[-1]
	pop	fp[80]
	push	sp[-1]
	pop	fp[81]
	push	sp[-1]
	pop	fp[82]
	push	sp[-1]
	pop	fp[83]
	push	sp[-1]
	pop	fp[84]
	push	sp[-1]
	pop	fp[85]
	push	sp[-1]
	pop	fp[86]
	push	sp[-1]
	pop	fp[87]
	push	sp[-1]
	pop	fp[88]
	push	sp[-1]
	pop	fp[89]
	push	sp[-1]
	pop	fp[90]
	push	sp[-1]
	pop	fp[91]
	push	sp[-1]
	pop	fp[92]
	push	sp[-1]
	pop	fp[93]
	push	sp[-1]
	pop	fp[94]
	push	sp[-1]
	pop	fp[95]
	push	sp[-1]
	pop	fp[96]
	push	sp[-1]
	pop	fp[97]
	push	sp[-1]
	pop	fp[98]
	push	sp[-1]
	pop	fp[99]
	pop	ac
	// constant
	push	100
	// initialise test2
	push	sp[-1]
	pop	fp[100]
	push	sp[-1]
	pop	fp[101]
	push	sp[-1]
	pop	fp[102]
	push	sp[-1]
	pop	fp[103]
	push	sp[-1]
	pop	fp[104]
	push	sp[-1]
	pop	fp[105]
	push	sp[-1]
	pop	fp[106]
	push	sp[-1]
	pop	fp[107]
	push	sp[-1]
	pop	fp[108]
	push	sp[-1]
	pop	fp[109]
	pop	ac
	// literal
	push	"test1:\n"
	// OUTPUT
	puts_
	// BEGIN FOR
	// constant
	push	0
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	110
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L001:
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	110
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	10
	// arithmetic
	compLT
	j0	L002
	// FOR BODY
	// BEGIN FOR
	// constant
	push	0
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	111
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L004:
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	111
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	10
	// arithmetic
	compLT
	j0	L005
	// FOR BODY
	// global identifier test1
	push	sb
	pop	ac
	push	ac
	push	0
	add
	// array-to-pointer
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	110
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	push	10
	mul
	add
	// array-to-pointer
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	111
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// OUTPUT
	puti
L006:
	// FOR INCREMENT
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	111
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	111
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L004
L005:
	// END FOR
L003:
	// FOR INCREMENT
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	110
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	110
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L001
L002:
	// END FOR
	// literal
	push	"test2:\n"
	// OUTPUT
	puts_
	// BEGIN FOR
	// constant
	push	0
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	110
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L007:
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	110
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	10
	// arithmetic
	compLT
	j0	L008
	// FOR BODY
	// global identifier test2
	push	sb
	pop	ac
	push	ac
	push	100
	add
	// array-to-pointer
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	110
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// OUTPUT
	puti
L009:
	// FOR INCREMENT
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	110
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	110
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L007
L008:
	// END FOR
	// BEGIN FOR
	// constant
	push	0
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	110
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L010:
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	110
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	10
	// arithmetic
	compLT
	j0	L011
	// FOR BODY
	// BEGIN FOR
	// constant
	push	0
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	111
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L013:
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	111
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	10
	// arithmetic
	compLT
	j0	L014
	// FOR BODY
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	110
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	111
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// arithmetic
	add
	// global identifier test1
	push	sb
	pop	ac
	push	ac
	push	0
	add
	// array-to-pointer
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	110
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	push	10
	mul
	add
	// array-to-pointer
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	111
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

L015:
	// FOR INCREMENT
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	111
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	111
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L013
L014:
	// END FOR
L012:
	// FOR INCREMENT
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	110
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	110
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L010
L011:
	// END FOR
	// literal
	push	"========"
	// OUTPUT
	puts
	// BEGIN FOR
	// constant
	push	0
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	110
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L016:
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	110
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	10
	// arithmetic
	compLT
	j0	L017
	// FOR BODY
	// BEGIN FOR
	// constant
	push	0
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	111
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L019:
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	111
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	10
	// arithmetic
	compLT
	j0	L020
	// FOR BODY
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	110
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// OUTPUT
	puti
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	111
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// OUTPUT
	puti
	// global identifier test1
	push	sb
	pop	ac
	push	ac
	push	0
	add
	// array-to-pointer
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	110
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	push	10
	mul
	add
	// array-to-pointer
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	111
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// OUTPUT
	puti
	// literal
	push	"========"
	// OUTPUT
	puts
L021:
	// FOR INCREMENT
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	111
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	111
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L019
L020:
	// END FOR
L018:
	// FOR INCREMENT
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	110
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	110
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L016
L017:
	// END FOR
	end
