	push	sp
	push	201
	add
	pop	sp

	// for loop

	// variable assignment i

	// push constant
	push	'a'

	pop	sb[200]
L017:

	// push variable i
	push	sb[200]

	// push constant
	push	'z'
	compLE
	j0	L016

	// array assignment a

	// push variable i
	push	sb[200]

	push	sb
	push	0
	push	0

	// push constant
	push	0
	add
	push	100
	mul

	// push variable i
	push	sb[200]

	// push constant
	push	'a'
	sub
	add
	add
	push	1
	mul
	add

	pop	ac
	pop	ac[0]

	// array assignment a

	// push variable i
	push	sb[200]

	// push constant
	push	'a'
	sub

	// push constant
	push	'A'
	add

	push	sb
	push	0
	push	0

	// push constant
	push	1
	add
	push	100
	mul

	// push variable i
	push	sb[200]

	// push constant
	push	'a'
	sub
	add
	add
	push	1
	mul
	add

	pop	ac
	pop	ac[0]
L015:

	// variable assignment i

	// push variable i
	push	sb[200]

	// push constant
	push	1
	add

	pop	sb[200]
	jmp	L017
L016:

	// array assignment a

	// push constant
	push	0

	push	sb
	push	0
	push	0

	// push constant
	push	0
	add
	push	100
	mul

	// push constant
	push	'z'

	// push constant
	push	'a'
	sub

	// push constant
	push	1
	add
	add
	add
	push	1
	mul
	add

	pop	ac
	pop	ac[0]

	// array assignment a

	// push constant
	push	0

	push	sb
	push	0
	push	0

	// push constant
	push	1
	add
	push	100
	mul

	// push constant
	push	'z'

	// push constant
	push	'a'
	sub

	// push constant
	push	1
	add
	add
	add
	push	1
	mul
	add

	pop	ac
	pop	ac[0]

	// Output

	// push normal string

	// push constant
	push	"lower case alphabet: "
	puts_

	// Output

	// push char array
	push	sb
	push	0
	push	0

	// push constant
	push	0
	add
	push	100
	mul
	add
	push	1
	mul
	add
	pop	ac
L018:
	push	ac[0]
	push	0
	compLE
	j1	L019
	push	ac[0]
	putc_
	push	ac
	push	1
	add
	pop	ac
	jmp	L018
L019:
	push	0
	putc

	// Output

	// push normal string

	// push constant
	push	"UPPER CASE ALPHABET: "
	puts_

	// Output

	// push char array
	push	sb
	push	0
	push	0

	// push constant
	push	1
	add
	push	100
	mul
	add
	push	1
	mul
	add
	pop	ac
L020:
	push	ac[0]
	push	0
	compLE
	j1	L021
	push	ac[0]
	putc_
	push	ac
	push	1
	add
	pop	ac
	jmp	L020
L021:
	push	0
	putc

	// Output

	// push normal string

	// push constant
	push	"enter a string: "
	puts_

	// Input

	// get to char array
	push	sb
	push	0
	push	0

	// push constant
	push	0
	add
	push	100
	mul
	add
	push	1
	mul
	add
	pop	ac
L022:
	getc
	pop	ac[0]
	push	ac[0]
	push	10
	compEQ
	j1	L023
	push	ac
	push	1
	add
	pop	ac
	jmp	L022
L023:
	push	0
	pop	ac[0]

	// Output

	// push normal string

	// push constant
	push	"you entered: "
	puts_

	// Output

	// push char array
	push	sb
	push	0
	push	0

	// push constant
	push	0
	add
	push	100
	mul
	add
	push	1
	mul
	add
	pop	ac
L024:
	push	ac[0]
	push	0
	compLE
	j1	L025
	push	ac[0]
	putc_
	push	ac
	push	1
	add
	pop	ac
	jmp	L024
L025:
	push	0
	putc

	// Output

	// push normal string

	// push constant
	push	"enter another string: "
	puts_

	// Input

	// get to char array
	push	sb
	push	0
	push	0

	// push constant
	push	1
	add
	push	100
	mul
	add
	push	1
	mul
	add
	pop	ac
L026:
	getc
	pop	ac[0]
	push	ac[0]
	push	10
	compEQ
	j1	L027
	push	ac
	push	1
	add
	pop	ac
	jmp	L026
L027:
	push	0
	pop	ac[0]

	// Output

	// push normal string

	// push constant
	push	"you entered: "
	puts_

	// Output

	// push char array
	push	sb
	push	0
	push	0

	// push constant
	push	1
	add
	push	100
	mul
	add
	push	1
	mul
	add
	pop	ac
L028:
	push	ac[0]
	push	0
	compLE
	j1	L029
	push	ac[0]
	putc_
	push	ac
	push	1
	add
	pop	ac
	jmp	L028
L029:
	push	0
	putc
	end
