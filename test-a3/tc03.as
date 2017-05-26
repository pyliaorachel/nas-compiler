	push	sp
	push	3
	add
	pop	sp

	// Input
	gets

	// get to variable a
	pop	sb[0]

	// variable assignment b

	// push variable a
	push	sb[0]
	pop	sb[1]

	// variable assignment c

	// push constant
	push	"test!"
	pop	sb[2]

	// Output

	// push normal string

	// push variable b
	push	sb[1]
	puts_

	// Output

	// push normal string

	// push variable c
	push	sb[2]
	puts
	end
