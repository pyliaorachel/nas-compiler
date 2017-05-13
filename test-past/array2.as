	// jump to main function unconditionally
	jmp	L000
	// x allocated with size 9
	// y allocated with size 64
	// c allocated with size 1
	// i allocated with size 1
	// q allocated with size 1
	// j allocated with size 1
	// a allocated with size 1
	// b allocated with size 1
	// function "main"
L000:
	// allocate space
	push	sp
	push	79
	add
	pop	sp

	// constant
	push	97
	// global identifier c
	push	sb
	pop	ac
	push	ac
	push	73
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// BEGIN FOR
	// constant
	push	0
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	74
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
	push	74
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	3
	// arithmetic
	compLT
	j0	L002
	// FOR BODY
	// BEGIN FOR
	// global identifier x
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
	push	74
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	push	3
	mul
	add
	// array-to-pointer
	// global identifier q
	push	sb
	pop	ac
	push	ac
	push	75
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L004:
	// global identifier q
	push	sb
	pop	ac
	push	ac
	push	75
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// global identifier x
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
	push	74
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	push	3
	mul
	add
	// array-to-pointer
	// constant
	push	3
	// arithmetic
	add
	// arithmetic
	compLT
	j0	L005
	// FOR BODY
	// global identifier q
	push	sb
	pop	ac
	push	ac
	push	75
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// OUTPUT
	puti
	// global identifier c
	push	sb
	pop	ac
	push	ac
	push	73
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// global identifier q
	push	sb
	pop	ac
	push	ac
	push	75
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// PTR
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// global identifier c
	push	sb
	pop	ac
	push	ac
	push	73
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// global identifier c
	push	sb
	pop	ac
	push	ac
	push	73
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

L006:
	// FOR INCREMENT
	// global identifier q
	push	sb
	pop	ac
	push	ac
	push	75
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// global identifier q
	push	sb
	pop	ac
	push	ac
	push	75
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
	push	74
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
	push	74
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L001
L002:
	// END FOR
	// BEGIN FOR
	// constant
	push	0
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	74
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
	push	74
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	3
	// arithmetic
	compLT
	j0	L008
	// FOR BODY
	// BEGIN FOR
	// constant
	push	0
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	76
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L010:
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	76
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	3
	// arithmetic
	compLT
	j0	L011
	// FOR BODY
	// global identifier x
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
	push	74
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	push	3
	mul
	add
	// array-to-pointer
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	76
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
	putc_
L012:
	// FOR INCREMENT
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	76
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
	push	76
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L010
L011:
	// END FOR
	// constant
	push	10
	// OUTPUT
	putc_
L009:
	// FOR INCREMENT
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	74
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
	push	74
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L007
L008:
	// END FOR
	// global identifier x
	push	sb
	pop	ac
	push	ac
	push	0
	add
	// array-to-pointer
	// constant
	push	0
	// [
	push	3
	mul
	add
	// REF
	// constant
	push	1
	// [
	push	3
	mul
	add
	// array-to-pointer
	// OUTPUT
	puti
	// global identifier x
	push	sb
	pop	ac
	push	ac
	push	0
	add
	// array-to-pointer
	// constant
	push	0
	// [
	push	3
	mul
	add
	// REF
	// constant
	push	1
	// [
	push	3
	mul
	add
	// array-to-pointer
	// constant
	push	0
	// [
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// OUTPUT
	putc
	// BEGIN FOR
	// constant
	push	0
	// global identifier a
	push	sb
	pop	ac
	push	ac
	push	77
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L013:
	// global identifier a
	push	sb
	pop	ac
	push	ac
	push	77
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	4
	// arithmetic
	compLT
	j0	L014
	// FOR BODY
	// BEGIN FOR
	// constant
	push	0
	// global identifier b
	push	sb
	pop	ac
	push	ac
	push	78
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L016:
	// global identifier b
	push	sb
	pop	ac
	push	ac
	push	78
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	4
	// arithmetic
	compLT
	j0	L017
	// FOR BODY
	// BEGIN FOR
	// constant
	push	0
	// global identifier c
	push	sb
	pop	ac
	push	ac
	push	73
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L019:
	// global identifier c
	push	sb
	pop	ac
	push	ac
	push	73
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	4
	// arithmetic
	compLT
	j0	L020
	// FOR BODY
	// global identifier y
	push	sb
	pop	ac
	push	ac
	push	9
	add
	// array-to-pointer
	// global identifier a
	push	sb
	pop	ac
	push	ac
	push	77
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	push	16
	mul
	add
	// array-to-pointer
	// global identifier b
	push	sb
	pop	ac
	push	ac
	push	78
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	push	4
	mul
	add
	// array-to-pointer
	// global identifier c
	push	sb
	pop	ac
	push	ac
	push	73
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	add
	// REF
	// OUTPUT
	puti
L021:
	// FOR INCREMENT
	// global identifier c
	push	sb
	pop	ac
	push	ac
	push	73
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// global identifier c
	push	sb
	pop	ac
	push	ac
	push	73
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
	// global identifier b
	push	sb
	pop	ac
	push	ac
	push	78
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// global identifier b
	push	sb
	pop	ac
	push	ac
	push	78
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L016
L017:
	// END FOR
L015:
	// FOR INCREMENT
	// global identifier a
	push	sb
	pop	ac
	push	ac
	push	77
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// global identifier a
	push	sb
	pop	ac
	push	ac
	push	77
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L013
L014:
	// END FOR
	end