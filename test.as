	push	sp
	push	64
	add
	pop	sp

	// array declaration & assignment a

	// push constant
	push	4

	// array size 64
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
	push	ac[23]
	pop	ac[24]
	push	ac[24]
	pop	ac[25]
	push	ac[25]
	pop	ac[26]
	push	ac[26]
	pop	ac[27]
	push	ac[27]
	pop	ac[28]
	push	ac[28]
	pop	ac[29]
	push	ac[29]
	pop	ac[30]
	push	ac[30]
	pop	ac[31]
	push	ac[31]
	pop	ac[32]
	push	ac[32]
	pop	ac[33]
	push	ac[33]
	pop	ac[34]
	push	ac[34]
	pop	ac[35]
	push	ac[35]
	pop	ac[36]
	push	ac[36]
	pop	ac[37]
	push	ac[37]
	pop	ac[38]
	push	ac[38]
	pop	ac[39]
	push	ac[39]
	pop	ac[40]
	push	ac[40]
	pop	ac[41]
	push	ac[41]
	pop	ac[42]
	push	ac[42]
	pop	ac[43]
	push	ac[43]
	pop	ac[44]
	push	ac[44]
	pop	ac[45]
	push	ac[45]
	pop	ac[46]
	push	ac[46]
	pop	ac[47]
	push	ac[47]
	pop	ac[48]
	push	ac[48]
	pop	ac[49]
	push	ac[49]
	pop	ac[50]
	push	ac[50]
	pop	ac[51]
	push	ac[51]
	pop	ac[52]
	push	ac[52]
	pop	ac[53]
	push	ac[53]
	pop	ac[54]
	push	ac[54]
	pop	ac[55]
	push	ac[55]
	pop	ac[56]
	push	ac[56]
	pop	ac[57]
	push	ac[57]
	pop	ac[58]
	push	ac[58]
	pop	ac[59]
	push	ac[59]
	pop	ac[60]
	push	ac[60]
	pop	ac[61]
	push	ac[61]
	pop	ac[62]
	push	ac[62]
	pop	ac[63]

	// array assignment a

	// push constant
	push	500
	push	sb
	push	0
	push	0

	// push constant
	push	1
	add
	push	4
	mul

	// push constant
	push	0
	add
	push	4
	mul

	// push constant
	push	0
	add
	add
	add
	pop	ac
	pop	ac[0]

	// function call hello

	// push pointer a
	push	sb
	push	0
	push	0

	// push constant
	push	1
	add
	push	4
	mul
	push	4
	mul
	add
	add
	call	L000, 1

	// function call hello

	// push pointer a
	push	sb
	push	0
	push	0

	// push constant
	push	1
	add
	push	4
	mul
	push	4
	mul
	add
	add
	call	L000, 1

	// function call hello

	// push pointer a
	push	sb
	push	0
	push	0

	// push constant
	push	1
	add
	push	4
	mul
	push	4
	mul
	add
	add
	call	L000, 1
	end
L000:

	// declare function

	// Output

	// push array b
	push	fp[-4]
	push	0

	// push constant
	push	0
	add
	add
	pop	ac
	push	ac[0]
	puti

	// array assignment b

	// push array b
	push	fp[-4]
	push	0

	// push constant
	push	0
	add
	add
	pop	ac
	push	ac[0]

	// push constant
	push	1
	sub
	push	fp[-4]
	push	0

	// push constant
	push	0
	add
	add
	pop	ac
	pop	ac[0]
	ret
