	push	sp
	push	451
	add
	pop	sp

	// variable assignment c

	// push constant
	push	1
	pop	sb[0]

	// I/O

	// push pointer a
	push	sb
	push	1
	push	0

	// push constant
	push	4
	add
	push	10
	mul

	// push constant
	push	1
	add
	push	9
	mul
	add
	push	8
	mul
	add
	puti

	// function call hello

	// push pointer a
	push	sb
	push	1
	push	0

	// push constant
	push	4
	add
	push	10
	mul

	// push constant
	push	1
	add
	push	9
	mul
	add
	push	8
	mul
	add
	call	L000, 1

	// I/O

	// push array a
	push	sb
	push	1
	push	0

	// push constant
	push	4
	add
	push	10
	mul

	// push constant
	push	1
	add
	push	9
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
	push	1
	push	0

	// push constant
	push	4
	add
	push	10
	mul

	// push constant
	push	1
	add
	push	9
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
	puti

	// I/O

	// push variable c
	push	sb[0]
	puti
	end
L000:

	// declare function

	// array assignment b

	// push constant
	push	0
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

	// array assignment b

	// push constant
	push	1
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
	ret
