	push	sp
	push	27
	add
	pop	sp

	// I/O

	// push pointer a
	push	sb
	push	0
	push	0

	// push constant
	push	2
	add
	push	3
	mul

	// push constant
	push	2
	add
	push	3
	mul
	add
	push	8
	mul
	add
	puti

	// function call hello

	// push pointer a
	push	sb
	push	0
	push	0

	// push constant
	push	2
	add
	push	3
	mul

	// push constant
	push	2
	add
	push	3
	mul
	add
	push	8
	mul
	add
	call	L000, 1

	// I/O

	// push array a
	push	sb
	push	0
	push	0

	// push constant
	push	2
	add
	push	3
	mul

	// push constant
	push	2
	add
	push	3
	mul

	// push constant
	push	0
	add
	add
	push	8
	mul
	add
	pop	ac
	push	ac[0]
	puti

	// I/O

	// push array a
	push	sb
	push	0
	push	0

	// push constant
	push	2
	add
	push	3
	mul

	// push constant
	push	2
	add
	push	3
	mul

	// push constant
	push	1
	add
	add
	push	8
	mul
	add
	pop	ac
	push	ac[0]
	putc

	// I/O

	// push array a
	push	sb
	push	0
	push	0

	// push constant
	push	2
	add
	push	3
	mul

	// push constant
	push	2
	add
	push	3
	mul

	// push constant
	push	2
	add
	add
	push	8
	mul
	add
	pop	ac
	push	ac[0]
	puts
	end
L000:

	// declare function

	// I/O
	geti

	// get to array b
	push	fp[-4]
	push	0

	// push constant
	push	0
	add
	push	8
	mul
	add
	pop	ac
	pop	ac[0]

	// I/O
	getc

	// get to array b
	push	fp[-4]
	push	0

	// push constant
	push	1
	add
	push	8
	mul
	add
	pop	ac
	pop	ac[0]

	// I/O
	gets

	// get to array b
	push	fp[-4]
	push	0

	// push constant
	push	2
	add
	push	8
	mul
	add
	pop	ac
	pop	ac[0]
	ret
