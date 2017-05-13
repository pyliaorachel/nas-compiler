	// jump to main function unconditionally
	jmp	L000
	// function "max"
L002:
	// allocate space
	push	sp
	push	0
	add
	pop	sp

	// BEGIN IF
	// identifier a
	push	fp
	push	-5
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// identifier b
	push	fp
	push	-4
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// arithmetic
	compGT
	j0	L003
	// THEN
	// identifier a
	push	fp
	push	-5
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	ret
	jmp	L004
	// ELSE
L003:
	// identifier b
	push	fp
	push	-4
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	ret
L004:
	// END IF
	// x allocated with size 1
	// y allocated with size 1
	// a allocated with size 1
	// b allocated with size 1
	// function "main"
L000:
	// allocate space
	push	sp
	push	4
	add
	pop	sp

	// global identifier x
	push	sb
	pop	ac
	push	ac
	push	0
	add
	// INPUT
	pop	ac
	geti
	pop	ac[0]
	// global identifier y
	push	sb
	pop	ac
	push	ac
	push	1
	add
	// INPUT
	pop	ac
	geti
	pop	ac[0]
	// global identifier x
	push	sb
	pop	ac
	push	ac
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// function call "fibonacci"
	call	L001, 1
	// global identifier a
	push	sb
	pop	ac
	push	ac
	push	2
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// global identifier y
	push	sb
	pop	ac
	push	ac
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// function call "fibonacci"
	call	L001, 1
	// global identifier b
	push	sb
	pop	ac
	push	ac
	push	3
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// global identifier a
	push	sb
	pop	ac
	push	ac
	push	2
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// OUTPUT
	puti
	// global identifier b
	push	sb
	pop	ac
	push	ac
	push	3
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// OUTPUT
	puti
	// global identifier a
	push	sb
	pop	ac
	push	ac
	push	2
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// global identifier b
	push	sb
	pop	ac
	push	ac
	push	3
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// function call "max"
	call	L002, 2
	// OUTPUT
	puti	"%d is larger.\n"
	end
	// x allocated with size 1
	// y allocated with size 1
	// i allocated with size 1
	// z allocated with size 1
	// function "fibonacci"
L001:
	// allocate space
	push	sp
	push	4
	add
	pop	sp

	// constant
	push	1
	// identifier x
	push	fp
	push	0
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	1
	// identifier y
	push	fp
	push	1
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// BEGIN FOR
	// constant
	push	2
	// identifier i
	push	fp
	push	2
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L005:
	// identifier i
	push	fp
	push	2
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// identifier n
	push	fp
	push	-4
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// arithmetic
	compLE
	j0	L006
	// FOR BODY
	// identifier x
	push	fp
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// identifier z
	push	fp
	push	3
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// identifier y
	push	fp
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// identifier x
	push	fp
	push	0
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// identifier x
	push	fp
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// identifier z
	push	fp
	push	3
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// arithmetic
	add
	// identifier y
	push	fp
	push	1
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

L007:
	// FOR INCREMENT
	// identifier i
	push	fp
	push	2
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
	push	2
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L005
L006:
	// END FOR
	// identifier y
	push	fp
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	ret
