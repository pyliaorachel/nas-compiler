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
	push	'4'
	pop	ac[5]
	push	'5'
	pop	ac[6]
	push	'5'
	pop	ac[7]
	push	'6'
	pop	ac[8]
	push	'6'
	pop	ac[9]
	push	'y'
	pop	ac[10]
	push	0
	pop	ac[11]

	// Output

	// push normal string

	// push constant
	push	"123321111"
	puts

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
