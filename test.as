	push	sp
	push	1000
	add
	pop	sp

	// char array assignment
	push	sb
	push	0
	add
	pop	ac
	push	'1'
	pop	ac[0]
	push	'2'
	pop	ac[1]
	push	'3'
	pop	ac[2]
	push	'4'
	pop	ac[3]
	push	'5'
	pop	ac[4]
	push	0
	pop	ac[5]

	// array assignment a

	// push constant
	push	'4'
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

	// Output

	// push char array
	push	sb
	push	0
	add
	pop	ac
L002:
	push	ac[0]
	push	0
	compLE
	j1	L003
	push	ac[0]
	putc_
	push	ac
	push	1
	add
	pop	ac
	jmp	L002
L003:
	push	0
	putc
	end
