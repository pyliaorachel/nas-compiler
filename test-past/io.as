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
	push	1
	// OUTPUT
	puti	"%03ld\n"
	// constant
	push	2
	// OUTPUT
	puti	"%03ld\n"
	// constant
	push	3
	// OUTPUT
	puti	"%03ld\n"
	// global identifier a
	push	sb
	pop	ac
	push	ac
	push	0
	add
	// INPUT
	pop	ac
	gets
	pop	ac[0]
	// global identifier b
	push	sb
	pop	ac
	push	ac
	push	1
	add
	// INPUT
	pop	ac
	gets
	pop	ac[0]
	// global identifier c
	push	sb
	pop	ac
	push	ac
	push	2
	add
	// INPUT
	pop	ac
	gets
	pop	ac[0]
	// global identifier a
	push	sb
	pop	ac
	push	ac
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// OUTPUT
	puts
	// global identifier b
	push	sb
	pop	ac
	push	ac
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// OUTPUT
	puts
	// global identifier c
	push	sb
	pop	ac
	push	ac
	push	2
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// OUTPUT
	puts
	end
