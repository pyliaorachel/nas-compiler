	push	sp
	push	1
	add
	pop	sp

	// Output

	// push normal string

	// push constant
	push	"Please enter a +ve int <= 12: "
	puts_

	// Input
	geti

	// get to variable n
	pop	sb[0]

	// if statement

	// push variable n
	push	sb[0]

	// push constant
	push	12
	compLE
	j0	L004

	// Output

	// function call fact

	// push variable n
	push	sb[0]
	call	L002, 1
	puti
	jmp	L005
L004:

	// Output

	// push variable n
	push	sb[0]
	puti_

	// Output

	// push normal string

	// push constant
	push	" > 12!!"
	puts
L005:
	end
L002:

	// declare function

	// if statement

	// push variable n
	push	fp[-4]

	// push constant
	push	1
	compLT
	j0	L006

	// push constant
	push	1
	ret
L006:

	// push variable n
	push	fp[-4]

	// function call fact

	// push variable n
	push	fp[-4]

	// push constant
	push	1
	sub
	call	L002, 1
	mul
	ret
	ret
