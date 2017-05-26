	push	sp
	push	1000
	add
	pop	sp

	// Input
	gets

	// get to array a
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

	// Output

	// push normal string

	// push array a
	push	sb
	push	0
	push	0

	// push constant
	push	3
	add
	add
	add
	pop	ac
	push	ac[0]
	puts

	// Input

	// get to char array
	push	sb
	push	0
	add
	pop	ac
L004:
	getc
	pop	ac[0]
	push	ac[0]
	push	10
	compEQ
	j1	L005
	push	ac
	push	1
	add
	pop	ac
	jmp	L004
L005:
	push	0
	pop	ac[0]

	// Output

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
