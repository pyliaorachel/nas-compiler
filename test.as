	push	sp
	push	97
	add
	pop	sp

	// array declaration & assignment a

	// push constant
	push	1

	// array size 9
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

	// array declaration & assignment c

	// push constant
	push	99

	// array size 24
	push	sb
	push	73
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
	push	ac[9]
	pop	ac[10]
	push	ac[10]
	pop	ac[11]
	push	ac[11]
	pop	ac[12]
	push	ac[12]
	pop	ac[13]
	push	ac[13]
	pop	ac[14]
	push	ac[14]
	pop	ac[15]
	push	ac[15]
	pop	ac[16]
	push	ac[16]
	pop	ac[17]
	push	ac[17]
	pop	ac[18]
	push	ac[18]
	pop	ac[19]
	push	ac[19]
	pop	ac[20]
	push	ac[20]
	pop	ac[21]
	push	ac[21]
	pop	ac[22]
	push	ac[22]
	pop	ac[23]

	// I/O

	// push array c
	push	sb
	push	73
	push	0

	// push constant
	push	1
	add
	push	3
	mul

	// push constant
	push	2
	add
	push	4
	mul

	// push constant
	push	0
	add
	add
	add
	pop	ac
	push	ac[0]
	puti

	// array assignment b

	// push constant
	push	1
	push	sb
	push	9
	push	0

	// push constant
	push	2
	add
	push	4
	mul

	// push constant
	push	3
	add
	push	4
	mul

	// push constant
	push	1
	add
	add
	add
	pop	ac
	pop	ac[0]

	// I/O

	// push array b
	push	sb
	push	9
	push	0

	// push constant
	push	2
	add
	push	4
	mul

	// push constant
	push	3
	add
	push	4
	mul

	// push constant
	push	1
	add
	add
	add
	pop	ac
	push	ac[0]
	puti
	end
