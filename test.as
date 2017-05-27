

	push	sp
	push	302
	add
	pop	sp

	// for loop

	// variable assignment i

	// push constant
	push	0

	pop	sb[300]
L014:

	// push variable i
	push	sb[300]

	// push constant
	push	10
	compLT
	j0	L013

	// for loop

	// variable assignment j

	// push constant
	push	0

	pop	sb[301]
L017:

	// push variable j
	push	sb[301]

	// push constant
	push	10
	compLT
	j0	L016

	// struct member assignment

	// push variable i
	push	sb[300]

	// push constant
	push	10
	mul

	// push variable j
	push	sb[301]
	add

	push	sb
	push	0
	push	0

	// push variable i
	push	sb[300]
	add
	push	10
	mul

	// push variable j
	push	sb[301]
	add
	add
	add
	push	0
	add

	pop	ac
	pop	ac[0]

	// struct member assignment

	// push variable i
	push	sb[300]

	// push variable j
	push	sb[301]
	add

	push	sb
	push	0
	push	0

	// push variable i
	push	sb[300]
	add
	push	10
	mul

	// push variable j
	push	sb[301]
	add
	add
	add
	push	1
	add

	pop	ac
	pop	ac[0]
L015:

	// variable assignment j

	// push variable j
	push	sb[301]

	// push constant
	push	1
	add

	pop	sb[301]
	jmp	L017
L016:
L012:

	// variable assignment i

	// push variable i
	push	sb[300]

	// push constant
	push	1
	add

	pop	sb[300]
	jmp	L014
L013:

	// for loop

	// variable assignment i

	// push constant
	push	0

	pop	sb[300]
L020:

	// push variable i
	push	sb[300]

	// push constant
	push	10
	compLT
	j0	L019

	// for loop

	// variable assignment j

	// push constant
	push	0

	pop	sb[301]
L023:

	// push variable j
	push	sb[301]

	// push constant
	push	10
	compLT
	j0	L022

	// Output

	// access struct member .id
	push	sb
	push	0
	push	0

	// push variable i
	push	sb[300]
	add
	push	10
	mul

	// push variable j
	push	sb[301]
	add
	add
	add
	push	0
	add

	pop	ac
	push	ac[0]
	puti

	// Output

	// access struct member .num
	push	sb
	push	0
	push	0

	// push variable i
	push	sb[300]
	add
	push	10
	mul

	// push variable j
	push	sb[301]
	add
	add
	add
	push	1
	add

	pop	ac
	push	ac[0]
	puti
L021:

	// variable assignment j

	// push variable j
	push	sb[301]

	// push constant
	push	1
	add

	pop	sb[301]
	jmp	L023
L022:
L018:

	// variable assignment i

	// push variable i
	push	sb[300]

	// push constant
	push	1
	add

	pop	sb[300]
	jmp	L020
L019:
	end
