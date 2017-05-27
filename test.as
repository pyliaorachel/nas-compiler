	push	sp
	push	10
	add
	pop	sp

	// array declaration & assignment a

	// push constant
	push	5

	// array size 10
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
	push	ac[3]
	pop	ac[4]
	push	ac[4]
	pop	ac[5]
	push	ac[5]
	pop	ac[6]
	push	ac[6]
	pop	ac[7]
	push	ac[7]
	pop	ac[8]
	push	ac[8]
	pop	ac[9]

	// dereference assignment

	// push constant
	push	100

	// push pointer a
	push	sb
	push	0
	add

	// push constant
	push	3
	add

	pop	ac
	pop	ac[0]

	// Output

	// variable/array element dereference

	// push pointer a
	push	sb
	push	0
	add

	// push constant
	push	4
	add

	pop	ac
	push	ac[0]
	puti

	// Output

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
	puti
	end
