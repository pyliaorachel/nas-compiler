	push	sp
	push	2000
	add
	pop	sp

	// array assignment a

	// push constant
	push	100
	push	sb
	push	0

	// push constant
	push	9
	push	10
	mul

	// push constant
	push	19
	add
	push	20
	mul

	// push constant
	push	4
	add
	add
	add
	pop	ac
	pop	ac[0]

	// I/O

	// push array a
	push	sb
	push	0

	// push constant
	push	9
	push	10
	mul

	// push constant
	push	19
	add
	push	20
	mul

	// push constant
	push	4
	add
	add
	add
	pop	ac
	push	ac[0]
	puti
	end
