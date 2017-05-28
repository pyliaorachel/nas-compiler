	push	sp
	push	10
	add
	pop	sp

	// for loop

	// variable assignment i

	// push constant
	push	0

	pop	sb[8]
L014:

	// push variable i
	push	sb[8]

	// push constant
	push	2
	compLT
	j0	L013

	// for loop

	// variable assignment j

	// push constant
	push	0

	pop	sb[9]
L017:

	// push variable j
	push	sb[9]

	// push constant
	push	2
	compLT
	j0	L016

	// Output

	// push normal string

	// push constant
	push	"Class "
	puts_

	// Output

	// push variable i
	push	sb[8]

	// push constant
	push	1
	add
	puti_

	// Output

	// push normal string

	// push constant
	push	" Student "
	puts_

	// Output

	// push variable j
	push	sb[9]

	// push constant
	push	1
	add
	puti_

	// Output

	// push normal string

	// push constant
	push	": "
	puts

	// Output

	// push normal string

	// push constant
	push	"First name: "
	puts_

	// Input
	gets

	// get to struct
	push	sb
	push	0
	push	0

	// push variable i
	push	sb[8]
	add
	push	2
	mul

	// push variable j
	push	sb[9]
	add
	push	2
	mul
	add
	add
	push	0
	add

	pop	ac
	pop	ac[0]

	// Output

	// push normal string

	// push constant
	push	"Last name: "
	puts_

	// Input
	gets

	// get to struct
	push	sb
	push	0
	push	0

	// push variable i
	push	sb[8]
	add
	push	2
	mul

	// push variable j
	push	sb[9]
	add
	push	2
	mul
	add
	add
	push	1
	add

	pop	ac
	pop	ac[0]
L015:

	// variable assignment j

	// push variable j
	push	sb[9]

	// push constant
	push	1
	add

	pop	sb[9]
	jmp	L017
L016:
L012:

	// variable assignment i

	// push variable i
	push	sb[8]

	// push constant
	push	1
	add

	pop	sb[8]
	jmp	L014
L013:

	// for loop

	// variable assignment i

	// push constant
	push	0

	pop	sb[8]
L020:

	// push variable i
	push	sb[8]

	// push constant
	push	2
	compLT
	j0	L019

	// for loop

	// variable assignment j

	// push constant
	push	0

	pop	sb[9]
L023:

	// push variable j
	push	sb[9]

	// push constant
	push	2
	compLT
	j0	L022

	// Output

	// push normal string

	// push constant
	push	"Class "
	puts_

	// Output

	// push variable i
	push	sb[8]

	// push constant
	push	1
	add
	puti_

	// Output

	// push normal string

	// push constant
	push	" Student "
	puts_

	// Output

	// push variable j
	push	sb[9]

	// push constant
	push	1
	add
	puti_

	// Output

	// push normal string

	// push constant
	push	": "
	puts

	// Output

	// push normal string

	// access struct member .firstname
	push	sb
	push	0
	push	0

	// push variable i
	push	sb[8]
	add
	push	2
	mul

	// push variable j
	push	sb[9]
	add
	push	2
	mul
	add
	add
	push	0
	add

	pop	ac
	push	ac[0]
	puts_

	// Output

	// push normal string

	// push constant
	push	" "
	puts_

	// Output

	// push normal string

	// access struct member .lastname
	push	sb
	push	0
	push	0

	// push variable i
	push	sb[8]
	add
	push	2
	mul

	// push variable j
	push	sb[9]
	add
	push	2
	mul
	add
	add
	push	1
	add

	pop	ac
	push	ac[0]
	puts
L021:

	// variable assignment j

	// push variable j
	push	sb[9]

	// push constant
	push	1
	add

	pop	sb[9]
	jmp	L023
L022:
L018:

	// variable assignment i

	// push variable i
	push	sb[8]

	// push constant
	push	1
	add

	pop	sb[8]
	jmp	L020
L019:
	end
