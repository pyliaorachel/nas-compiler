	push	sp
	push	1
	add
	pop	sp

	// variable assignment b

	// push constant
	push	999
	pop	sb[0]

	// function call f

	// push variable b
	push	sb[0]
	call	L000, 1
	end
L000:

	// declare function

	// Output

	// push variable a
	push	fp[-4]
	puti
	ret
