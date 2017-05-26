	push	sp
	push	1
	add
	pop	sp

	// function call finit
	call	L000, 0

	// function call fout
	call	L001, 0
	end
L000:

	// declare function

	// variable assignment @a

	// push constant
	push	10
	pop	sb[0]
	ret
L001:

	// declare function

	// Output

	// push variable @a
	push	sb[0]
	puti
	ret
