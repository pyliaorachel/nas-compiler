	push	sp
	push	3
	add
	pop	sp

	// variable assignment k

	// push constant
	push	1
	pop	sb[0]

	// for loop

	// variable assignment i

	// push constant
	push	1
	pop	sb[1]
L009:

	// push variable i
	push	sb[1]

	// push constant
	push	100
	compLT
	j0	L008

	// variable assignment j

	// push variable i
	push	sb[1]
	pop	sb[2]

	// while loop
L010:

	// push variable j
	push	sb[2]

	// push constant
	push	0
	compGT
	j0	L011

	// variable assignment j

	// push variable j
	push	sb[2]

	// push constant
	push	2
	div
	pop	sb[2]

	// if statement

	// push variable j
	push	sb[2]

	// push constant
	push	1
	compEQ
	j0	L012
	jmp	L011
L012:
	jmp	L010
L011:

	// if statement

	// push variable i
	push	sb[1]

	// push constant
	push	10
	compLT
	j0	L013
	jmp	L007
L013:

	// variable assignment k

	// push variable k
	push	sb[0]

	// push constant
	push	1
	add
	pop	sb[0]
L007:

	// variable assignment i

	// push variable i
	push	sb[1]

	// push variable k
	push	sb[0]
	add
	pop	sb[1]
	jmp	L009
L008:

	// Output

	// push variable i
	push	sb[1]
	puti_

	// Output

	// push normal string

	// push constant
	push	", "
	puts_

	// Output

	// push variable j
	push	sb[2]
	puti_

	// Output

	// push normal string

	// push constant
	push	", "
	puts_

	// Output

	// push variable k
	push	sb[0]
	puti
	end
