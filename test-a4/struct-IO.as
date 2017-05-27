	push	sp
	push	5
	add
	pop	sp

	// variable assignment max

	// push constant
	push	255

	pop	sb[3]

	// variable assignment min

	// push constant
	push	0

	pop	sb[4]

	// Output

	// push normal string

	// push constant
	push	"Enter a color:"
	puts

	// Output

	// push normal string

	// push constant
	push	"r="
	puts_

	// Input
	geti

	// get to struct
	push	sb
	push	0
	add
	push	0
	add

	pop	ac
	pop	ac[0]

	// Output

	// push normal string

	// push constant
	push	"g="
	puts_

	// Input
	geti

	// get to struct
	push	sb
	push	0
	add
	push	1
	add

	pop	ac
	pop	ac[0]

	// Output

	// push normal string

	// push constant
	push	"b="
	puts_

	// Input
	geti

	// get to struct
	push	sb
	push	0
	add
	push	2
	add

	pop	ac
	pop	ac[0]

	// while loop
L004:

	// function call isvalid

	// access struct member .r
	push	sb
	push	0
	add
	push	0
	add

	pop	ac
	push	ac[0]

	// access struct member .g
	push	sb
	push	0
	add
	push	1
	add

	pop	ac
	push	ac[0]

	// access struct member .b
	push	sb
	push	0
	add
	push	2
	add

	pop	ac
	push	ac[0]
	call	L002, 3

	// push constant
	push	0
	compEQ
	j0	L005

	// Output

	// push normal string

	// push constant
	push	"Color not valid! Enter again:"
	puts

	// Output

	// push normal string

	// push constant
	push	"r="
	puts_

	// Input
	geti

	// get to struct
	push	sb
	push	0
	add
	push	0
	add

	pop	ac
	pop	ac[0]

	// Output

	// push normal string

	// push constant
	push	"g="
	puts_

	// Input
	geti

	// get to struct
	push	sb
	push	0
	add
	push	1
	add

	pop	ac
	pop	ac[0]

	// Output

	// push normal string

	// push constant
	push	"b="
	puts_

	// Input
	geti

	// get to struct
	push	sb
	push	0
	add
	push	2
	add

	pop	ac
	pop	ac[0]
	jmp	L004
L005:

	// Output

	// push normal string

	// push constant
	push	"Color: r="
	puts_

	// Output

	// access struct member .r
	push	sb
	push	0
	add
	push	0
	add

	pop	ac
	push	ac[0]
	puti_

	// Output

	// push normal string

	// push constant
	push	", g="
	puts_

	// Output

	// access struct member .g
	push	sb
	push	0
	add
	push	1
	add

	pop	ac
	push	ac[0]
	puti_

	// Output

	// push normal string

	// push constant
	push	", b="
	puts_

	// Output

	// access struct member .b
	push	sb
	push	0
	add
	push	2
	add

	pop	ac
	push	ac[0]
	puti
	end
L002:

	// declare function

	// if statement

	// push variable r
	push	fp[-6]

	// push variable @max
	push	sb[3]
	compGT

	// push variable r
	push	fp[-6]

	// push variable @min
	push	sb[4]
	compLT
	or

	// push variable g
	push	fp[-5]

	// push variable @max
	push	sb[3]
	compGT

	// push variable g
	push	fp[-5]

	// push variable @min
	push	sb[4]
	compLT
	or
	or

	// push variable b
	push	fp[-4]

	// push variable @max
	push	sb[3]
	compGT

	// push variable b
	push	fp[-4]

	// push variable @min
	push	sb[4]
	compLT
	or
	or
	j0	L006

	// push constant
	push	0
	ret
L006:

	// push constant
	push	1
	ret
	ret
