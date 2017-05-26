	push	sp
	push	3
	add
	pop	sp

	// Input
	getc

	// get to variable a
	pop	sb[0]

	// variable assignment b

	// push variable a
	push	sb[0]
	pop	sb[1]

	// variable assignment c

	// push constant
	push	'X'
	pop	sb[2]

	// Output

	// push variable b
	push	sb[1]
	putc_

	// Output

	// push variable c
	push	sb[2]
	putc
	end
