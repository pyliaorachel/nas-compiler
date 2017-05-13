	push	sp
	push	450
	add
	pop	sp

	// I/O

	// push pointer a
	push	sb
	push	0
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
	add
	puti

	// function call hello

	// push pointer a
	push	sb
	push	0
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
	add
	call	L000, 1
	end
L000:

	// declare function

	// I/O

	// push variable b
	push	fp[-4]
	puti
	ret
