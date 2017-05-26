	push	sp
	push	5
	add
	pop	sp

	// variable assignment a

	// push constant
	push	9876543
	pop	sb[0]

	// variable assignment ab

	// push variable a
	push	sb[0]

	// push constant
	push	1
	add
	pop	sb[1]

	// variable assignment abcd

	// push variable ab
	push	sb[1]

	// push constant
	push	2
	add
	pop	sb[2]

	// variable assignment a1b2c3

	// push variable abcd
	push	sb[2]

	// push constant
	push	4
	add
	pop	sb[3]

	// variable assignment xyztuvwopqrs

	// push variable a1b2c3
	push	sb[3]

	// push constant
	push	8
	add
	pop	sb[4]

	// Output

	// push variable xyztuvwopqrs
	push	sb[4]
	puti
	end
