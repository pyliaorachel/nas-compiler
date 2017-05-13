	// jump to main function unconditionally
	jmp	L000
	// garbage allocated with size 1
	// test allocated with size 25
	// i allocated with size 1
	// j allocated with size 1
	// function "main"
L000:
	// allocate space
	push	sp
	push	28
	add
	pop	sp

	// constant
	push	1
	// UMINUS
	neg
	// global identifier garbage
	push	sb
	pop	ac
	push	ac
	push	0
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	2
	// initialise test
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
	pop	ac
	// BEGIN FOR
	// constant
	push	0
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	26
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L002:
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	26
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	5
	// arithmetic
	compLT
	j0	L003
	// FOR BODY
	// BEGIN FOR
	// constant
	push	0
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	27
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L005:
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	27
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	5
	// arithmetic
	compLT
	j0	L006
	// FOR BODY
	// global identifier test
	push	sb
	pop	ac
	push	ac
	push	1
	add
	// array-to-pointer
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	26
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	push	5
	mul
	add
	// array-to-pointer
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	27
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
	puti	"%d "
L007:
	// FOR INCREMENT
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	27
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
	push	27
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L005
L006:
	// END FOR
L004:
	// FOR INCREMENT
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	26
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
	push	26
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L002
L003:
	// END FOR
	// literal
	push	"\n"
	// OUTPUT
	puts_
	// function call "double"
	call	L001, 0
	// global identifier garbage
	push	sb
	pop	ac
	push	ac
	push	0
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// literal
	push	"after function double():"
	// OUTPUT
	puts
	// BEGIN FOR
	// constant
	push	0
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	26
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L008:
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	26
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	5
	// arithmetic
	compLT
	j0	L009
	// FOR BODY
	// BEGIN FOR
	// constant
	push	0
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	27
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L011:
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	27
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	5
	// arithmetic
	compLT
	j0	L012
	// FOR BODY
	// global identifier test
	push	sb
	pop	ac
	push	ac
	push	1
	add
	// array-to-pointer
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	26
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	push	5
	mul
	add
	// array-to-pointer
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	27
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
	puti	"%d "
L013:
	// FOR INCREMENT
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	27
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
	push	27
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L011
L012:
	// END FOR
L010:
	// FOR INCREMENT
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	26
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
	push	26
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L008
L009:
	// END FOR
	// literal
	push	"\n"
	// OUTPUT
	puts_
	end
	// i allocated with size 1
	// j allocated with size 1
	// function "double"
L001:
	// allocate space
	push	sp
	push	2
	add
	pop	sp

	// BEGIN FOR
	// constant
	push	0
	// identifier i
	push	fp
	push	0
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L014:
	// identifier i
	push	fp
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	5
	// arithmetic
	compLT
	j0	L015
	// FOR BODY
	// BEGIN FOR
	// constant
	push	0
	// identifier j
	push	fp
	push	1
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L017:
	// identifier j
	push	fp
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	5
	// arithmetic
	compLT
	j0	L018
	// FOR BODY
	// global identifier test
	push	sb
	pop	ac
	push	ac
	push	1
	add
	// array-to-pointer
	// identifier i
	push	fp
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	push	5
	mul
	add
	// array-to-pointer
	// identifier j
	push	fp
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	2
	// arithmetic
	mul
	// global identifier test
	push	sb
	pop	ac
	push	ac
	push	1
	add
	// array-to-pointer
	// identifier i
	push	fp
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	push	5
	mul
	add
	// array-to-pointer
	// identifier j
	push	fp
	push	1
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

L019:
	// FOR INCREMENT
	// identifier j
	push	fp
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// identifier j
	push	fp
	push	1
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L017
L018:
	// END FOR
L016:
	// FOR INCREMENT
	// identifier i
	push	fp
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// identifier i
	push	fp
	push	0
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L014
L015:
	// END FOR
	// constant
	push	1
	// UMINUS
	neg
	ret
