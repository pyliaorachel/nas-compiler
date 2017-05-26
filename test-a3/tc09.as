	push	sp
	push	3
	add
	pop	sp

	// variable assignment x

	// push constant
	push	10
	pop	sb[0]

	// variable assignment y

	// push constant
	push	15
	pop	sb[1]

	// variable assignment z

	// push constant
	push	40
	pop	sb[2]

	// variable assignment z

	// function call f

	// push variable x
	push	sb[0]

	// push variable z
	push	sb[2]

	// push variable z
	push	sb[2]

	// push variable y
	push	sb[1]
	call	L000, 4
	pop	sb[2]

	// Output

	// push variable z
	push	sb[2]
	puti
	end
L000:

	// declare function

	// push variable a
	push	fp[-7]

	// push variable b
	push	fp[-6]
	add

	// push variable c
	push	fp[-5]

	// push variable d
	push	fp[-4]
	add
	mul
	ret
	ret
