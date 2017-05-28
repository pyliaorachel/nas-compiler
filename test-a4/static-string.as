	push	sp
	push	114
	add
	pop	sp

	// array assignment a

	// push constant
	push	"Hello world!"

	push	sb
	push	0
	push	0

	// push constant
	push	0
	add
	push	1
	mul
	add
	add

	pop	ac
	pop	ac[0]

	// array assignment a

	// push constant
	push	"Bye world!"

	push	sb
	push	0
	push	0

	// push constant
	push	1
	add
	push	1
	mul
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
	push	0
	add
	push	1
	mul
	add
	add

	pop	ac
	push	ac[0]
	puts

	// Output

	// push normal string

	// push array a
	push	sb
	push	0
	push	0

	// push constant
	push	1
	add
	push	1
	mul
	add
	add

	pop	ac
	push	ac[0]
	puts

	// char array assignment
	push	sb
	push	2
	push	0

	// push constant
	push	0
	add
	push	6
	mul
	push	1
	mul
	add
	add
	pop	ac
	push	'H'
	pop	ac[0]
	push	'e'
	pop	ac[1]
	push	'l'
	pop	ac[2]
	push	'l'
	pop	ac[3]
	push	'o'
	pop	ac[4]
	push	' '
	pop	ac[5]
	push	'w'
	pop	ac[6]
	push	'o'
	pop	ac[7]
	push	'r'
	pop	ac[8]
	push	'l'
	pop	ac[9]
	push	'd'
	pop	ac[10]
	push	0
	pop	ac[11]

	// Output

	// push char array
	push	sb
	push	2
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

	// char array assignment
	push	sb
	push	2
	push	0

	// push constant
	push	1
	add
	push	6
	mul
	push	1
	mul
	add
	add
	pop	ac
	push	'K'
	pop	ac[0]
	push	'i'
	pop	ac[1]
	push	't'
	pop	ac[2]
	push	't'
	pop	ac[3]
	push	'y'
	pop	ac[4]
	push	0
	pop	ac[5]

	// Output

	// push char array
	push	sb
	push	2
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

	// Output

	// push normal string

	// push constant
	push	"Hotel? Trivago."
	puts

	// char array assignment
	push	sb
	push	14
	add
	pop	ac
	push	'H'
	pop	ac[0]
	push	'o'
	pop	ac[1]
	push	't'
	pop	ac[2]
	push	'e'
	pop	ac[3]
	push	'l'
	pop	ac[4]
	push	'?'
	pop	ac[5]
	push	' '
	pop	ac[6]
	push	'T'
	pop	ac[7]
	push	'r'
	pop	ac[8]
	push	'i'
	pop	ac[9]
	push	'v'
	pop	ac[10]
	push	'a'
	pop	ac[11]
	push	'g'
	pop	ac[12]
	push	'o'
	pop	ac[13]
	push	'.'
	pop	ac[14]
	push	0
	pop	ac[15]

	// Output

	// push char array
	push	sb
	push	14
	add
	pop	ac
L010:
	push	ac[0]
	push	0
	compLE
	j1	L011
	push	ac[0]
	putc_
	push	ac
	push	1
	add
	pop	ac
	jmp	L010
L011:
	push	0
	putc
	end
