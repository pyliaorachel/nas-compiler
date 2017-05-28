	push	sp
	push	49
	add
	pop	sp

	// Output

	// push normal string

	// push constant
	push	"enter an int: "
	puts_

	// Input
	geti

	// get to array a
	push	sb
	push	0
	push	0

	// push constant
	push	3
	add
	push	4
	mul

	// push constant
	push	3
	add
	push	1
	mul
	add
	add

	pop	ac
	pop	ac[0]

	// Output

	// push normal string

	// push constant
	push	"you entered: "
	puts_

	// Output

	// push array a
	push	sb
	push	0
	push	0

	// push constant
	push	3
	add
	push	4
	mul

	// push constant
	push	3
	add
	push	1
	mul
	add
	add

	pop	ac
	push	ac[0]
	puti

	// Output

	// push normal string

	// push constant
	push	"enter a char: "
	puts_

	// Input
	getc

	// get to array b
	push	sb
	push	16
	push	0

	// push constant
	push	3
	add
	push	4
	mul

	// push constant
	push	3
	add
	push	1
	mul
	add
	add

	pop	ac
	pop	ac[0]

	// Output

	// push normal string

	// push constant
	push	"you entered: "
	puts_

	// Output

	// push array b
	push	sb
	push	16
	push	0

	// push constant
	push	3
	add
	push	4
	mul

	// push constant
	push	3
	add
	push	1
	mul
	add
	add

	pop	ac
	push	ac[0]
	putc

	// Output

	// push normal string

	// push constant
	push	"enter a string: "
	puts_

	// Input
	getc

	// get to variable dummy
	pop	sb[48]

	// Input
	gets

	// get to array c
	push	sb
	push	32
	push	0

	// push constant
	push	3
	add
	push	4
	mul

	// push constant
	push	3
	add
	push	1
	mul
	add
	add

	pop	ac
	pop	ac[0]

	// Output

	// push normal string

	// push constant
	push	"you entered: "
	puts_

	// Output

	// push normal string

	// push array c
	push	sb
	push	32
	push	0

	// push constant
	push	3
	add
	push	4
	mul

	// push constant
	push	3
	add
	push	1
	mul
	add
	add

	pop	ac
	push	ac[0]
	puts
	end
