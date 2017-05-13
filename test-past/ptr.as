	// jump to main function unconditionally
	jmp	L000
	// a allocated with size 1
	// b allocated with size 1
	// c allocated with size 1
	// function "main"
L000:
	// allocate space
	push	sp
	push	3
	add
	pop	sp

	// constant
	push	10
	// global identifier a
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
	push	20
	// global identifier b
	push	sb
	pop	ac
	push	ac
	push	1
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	30
	// global identifier c
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

	// global identifier a
	push	sb
	pop	ac
	push	ac
	push	0
	add
	// REF
	// OUTPUT
	puti
	// global identifier b
	push	sb
	pop	ac
	push	ac
	push	1
	add
	// REF
	// OUTPUT
	puti
	// global identifier c
	push	sb
	pop	ac
	push	ac
	push	2
	add
	// REF
	// OUTPUT
	puti
	// global identifier a
	push	sb
	pop	ac
	push	ac
	push	0
	add
	// REF
	// PTR
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// OUTPUT
	puti
	// global identifier b
	push	sb
	pop	ac
	push	ac
	push	1
	add
	// REF
	// PTR
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// OUTPUT
	puti
	// global identifier c
	push	sb
	pop	ac
	push	ac
	push	2
	add
	// REF
	// PTR
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// OUTPUT
	puti
	end
