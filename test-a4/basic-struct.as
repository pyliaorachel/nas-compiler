	push	sp
	push	3
	add
	pop	sp

	// struct member assignment

	// push constant
	push	255

	push	sb
	push	0
	add
	push	0
	add

	pop	ac
	pop	ac[0]

	// struct member assignment

	// push constant
	push	255

	push	sb
	push	0
	add
	push	1
	add

	pop	ac
	pop	ac[0]

	// struct member assignment

	// push constant
	push	255

	push	sb
	push	0
	add
	push	2
	add

	pop	ac
	pop	ac[0]

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
