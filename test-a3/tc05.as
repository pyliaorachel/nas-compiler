	push	sp
	push	3
	add
	pop	sp

	// variable assignment a

	// push constant
	push	100
	pop	sb[0]

	// variable assignment b

	// push constant
	push	100
	pop	sb[1]

	// variable assignment c

	// push constant
	push	200
	pop	sb[2]

	// if statement

	// push variable a
	push	sb[0]

	// push variable b
	push	sb[1]
	compGE
	j0	L005

	// Output

	// push normal string

	// push constant
	push	"a>b"
	puts

	// if statement

	// push variable a
	push	sb[0]

	// push variable b
	push	sb[1]
	compEQ
	j0	L007

	// Output

	// push normal string

	// push constant
	push	"a==b"
	puts
L007:
	jmp	L006
L005:

	// Output

	// push normal string

	// push constant
	push	"a<b"
	puts
L006:

	// if statement

	// push variable c
	push	sb[2]

	// push variable a
	push	sb[0]
	compLT
	j0	L008

	// Output

	// push normal string

	// push constant
	push	"c<a"
	puts
	jmp	L009
L008:

	// Output

	// push normal string

	// push constant
	push	"c>=a"
	puts
L009:
	end
