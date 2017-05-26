	push	sp
	push	94
	add
	pop	sp

	// variable assignment b

	// push constant
	push	3
	pop	sb[0]

	// variable assignment c

	// push constant
	push	4
	pop	sb[1]

	// variable assignment d

	// push constant
	push	3
	pop	sb[2]

	// I/O

	// push variable b
	push	sb[0]
	puti

	// I/O

	// push variable c
	push	sb[1]
	puti

	// I/O

	// push variable d
	push	sb[2]
	puti

	// array assignment a

	// push constant
	push	2
	push	sb
	push	3
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
	pop	ac[0]

	// array assignment x

	// push constant
	push	3
	push	sb
	push	30
	push	0

	// push constant
	push	2
	add
	push	4
	mul

	// push constant
	push	2
	add
	push	4
	mul

	// push constant
	push	2
	add
	add
	push	8
	mul
	add
	pop	ac
	pop	ac[0]

	// I/O

	// push array a
	push	sb
	push	3
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
	puti

	// I/O

	// push array x
	push	sb
	push	30
	push	0

	// push constant
	push	2
	add
	push	4
	mul

	// push constant
	push	2
	add
	push	4
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
	puti
	end
