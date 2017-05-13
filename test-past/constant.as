	// jump to main function unconditionally
	jmp	L000
	// x allocated with size 1
	// i allocated with size 1
	// a allocated with size 1
	// function "main"
L000:
	// allocate space
	push	sp
	push	3
	add
	pop	sp

	// constant
	push	99
	// global identifier x
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
	push	27
	// global identifier i
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

	// literal
	push	"Hello World!"
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

	// global identifier x
	push	sb
	pop	ac
	push	ac
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// OUTPUT
	putc
	// global identifier i
	push	sb
	pop	ac
	push	ac
	push	1
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
	// OUTPUT
	puts_
	// literal
	push	" Merry Christmas!\n"
	// OUTPUT
	puts_
	end
