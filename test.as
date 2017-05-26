	push	sp
	push	4
	add
	pop	sp

	// array declaration & assignment a

	// push constant
	push	'a'

	// array size 4
	push	sb
	push	0
	add
	pop	ac
	pop	ac[0]
	push	ac[0]
	pop	ac[1]
	push	ac[1]
	pop	ac[2]
	push	ac[2]
	pop	ac[3]

	// array assignment a

	// push constant
	push	0
	push	sb
	push	0
	push	0

	// push constant
	push	3
	add
	add
	add
	pop	ac
	pop	ac[0]

	// I/O

	// push char array
	push	sb
	push	0
	add
	pop	ac
L004:
	push	ac[0]
	push	0
	compLE
	j1	L005
	push	ac[0]
	putc_
	push	ac
	push	1
	add
	pop	ac
	jmp	L004
L005:

	// array assignment a

	// push constant
	push	87
	push	sb
	push	0
	push	0

	// push constant
	push	1
	add
	add
	add
	pop	ac
	pop	ac[0]

	// I/O

	// push char array
	push	sb
	push	0
	add
	pop	ac
L006:
	push	ac[0]
	push	0
	compLE
	j1	L007
	push	ac[0]
	putc_
	push	ac
	push	1
	add
	pop	ac
	jmp	L006
L007:
	push	0
	putc
	end
