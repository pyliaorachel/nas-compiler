	push	sp
	push	9
	add
	pop	sp

	// array declaration & assignment a

	// push constant
	push	78

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

	// array declaration & assignment b

	// push constant
	push	87

	// array size 4
	push	sb
	push	4
	add
	pop	ac
	pop	ac[0]
	push	ac[0]
	pop	ac[1]
	push	ac[1]
	pop	ac[2]
	push	ac[2]
	pop	ac[3]

	// for loop

	// variable assignment i

	// push constant
	push	0
	pop	sb[8]
L008:

	// push variable i
	push	sb[8]

	// push constant
	push	4
	compLT
	j0	L007

	// Output

	// push array a
	push	sb
	push	0
	push	0

	// push variable i
	push	sb[8]
	add
	add
	add
	pop	ac
	push	ac[0]
	puti

	// Output

	// push array a
	push	sb
	push	0
	push	0

	// push variable i
	push	sb[8]
	add
	add
	add
	pop	ac
	push	ac[0]

	// push array b
	push	sb
	push	4
	push	0

	// push variable i
	push	sb[8]
	add
	add
	add
	pop	ac
	push	ac[0]
	add
	puti

	// array assignment a

	// push array b
	push	sb
	push	4
	push	0

	// push variable i
	push	sb[8]
	add
	add
	add
	pop	ac
	push	ac[0]

	// push constant
	push	100
	add
	push	sb
	push	0
	push	0

	// push variable i
	push	sb[8]
	add
	add
	add
	pop	ac
	pop	ac[0]
L006:

	// variable assignment i

	// push variable i
	push	sb[8]

	// push constant
	push	1
	add
	pop	sb[8]
	jmp	L008
L007:

	// for loop

	// variable assignment i

	// push constant
	push	1
	pop	sb[8]
L011:

	// push variable i
	push	sb[8]

	// push constant
	push	5
	compLT
	j0	L010

	// Output

	// push array a
	push	sb
	push	0
	push	0

	// push variable i
	push	sb[8]

	// push constant
	push	1
	sub
	add
	add
	add
	pop	ac
	push	ac[0]
	puti
L009:

	// variable assignment i

	// push variable i
	push	sb[8]

	// push constant
	push	1
	add
	pop	sb[8]
	jmp	L011
L010:
	end
