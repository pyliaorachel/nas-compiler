	push	sp
	push	1001
	add
	pop	sp

	// for loop

	// variable assignment i

	// push constant
	push	0
	pop	sb[1000]
L007:

	// push variable i
	push	sb[1000]

	// push constant
	push	26
	compLT
	j0	L006

	// array assignment a

	// push variable i
	push	sb[1000]

	// push constant
	push	'a'
	add
	push	sb
	push	0
	push	0

	// push variable i
	push	sb[1000]
	add
	add
	add
	pop	ac
	pop	ac[0]
L005:

	// variable assignment i

	// push variable i
	push	sb[1000]

	// push constant
	push	1
	add
	pop	sb[1000]
	jmp	L007
L006:

	// array assignment a

	// push constant
	push	0
	push	sb
	push	0
	push	0

	// push constant
	push	26
	add
	add
	add
	pop	ac
	pop	ac[0]

	// Output

	// push char array
	push	sb
	push	0
	add
	pop	ac
L008:
	push	ac[0]
	push	0
	compLE
	j1	L009
	push	ac[0]
	putc_
	push	ac
	push	1
	add
	pop	ac
	jmp	L008
L009:
	push	0
	putc
	end
