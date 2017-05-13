	// jump to main function unconditionally
	jmp	L000
	// x allocated with size 10000
	// y allocated with size 100
	// n allocated with size 1
	// m allocated with size 1
	// i allocated with size 1
	// j allocated with size 1
	// function "main"
L000:
	// allocate space
	push	sp
	push	10104
	add
	pop	sp

	// global identifier n
	push	sb
	pop	ac
	push	ac
	push	10100
	add
	// INPUT
	pop	ac
	geti
	pop	ac[0]
	// global identifier m
	push	sb
	pop	ac
	push	ac
	push	10101
	add
	// INPUT
	pop	ac
	geti
	pop	ac[0]
	// BEGIN FOR
	// constant
	push	0
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	10102
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
	push	10102
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// global identifier n
	push	sb
	pop	ac
	push	ac
	push	10100
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
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
	push	10103
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
	push	10103
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// global identifier m
	push	sb
	pop	ac
	push	ac
	push	10101
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// arithmetic
	compLT
	j0	L005
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
	push	10102
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	push	100
	mul
	add
	// array-to-pointer
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	10103
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	add
	// INPUT
	pop	ac
	geti
	pop	ac[0]
L006:
	// FOR INCREMENT
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	10103
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
	push	10103
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
	push	10102
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
	push	10102
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
	push	10102
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
	push	10102
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// global identifier n
	push	sb
	pop	ac
	push	ac
	push	10100
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
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
	push	10103
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
	push	10103
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// global identifier m
	push	sb
	pop	ac
	push	ac
	push	10101
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
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
	push	10102
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	push	100
	mul
	add
	// array-to-pointer
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	10103
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
	puti_
	// constant
	push	32
	// OUTPUT
	putc_
L012:
	// FOR INCREMENT
	// global identifier j
	push	sb
	pop	ac
	push	ac
	push	10103
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
	push	10103
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
	push	10102
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
	push	10102
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L007
L008:
	// END FOR
	end
