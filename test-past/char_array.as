	// jump to main function unconditionally
	jmp	L000
	// s allocated with size 25
	// function "main"
L000:
	// allocate space
	push	sp
	push	25
	add
	pop	sp

	// constant
	push	97
	// initialise s
	push	sp[-1]
	pop	fp[0]
	push	sp[-1]
	pop	fp[1]
	push	sp[-1]
	pop	fp[2]
	push	sp[-1]
	pop	fp[3]
	push	sp[-1]
	pop	fp[4]
	push	sp[-1]
	pop	fp[5]
	push	sp[-1]
	pop	fp[6]
	push	sp[-1]
	pop	fp[7]
	push	sp[-1]
	pop	fp[8]
	push	sp[-1]
	pop	fp[9]
	push	sp[-1]
	pop	fp[10]
	push	sp[-1]
	pop	fp[11]
	push	sp[-1]
	pop	fp[12]
	push	sp[-1]
	pop	fp[13]
	push	sp[-1]
	pop	fp[14]
	push	sp[-1]
	pop	fp[15]
	push	sp[-1]
	pop	fp[16]
	push	sp[-1]
	pop	fp[17]
	push	sp[-1]
	pop	fp[18]
	push	sp[-1]
	pop	fp[19]
	push	sp[-1]
	pop	fp[20]
	push	sp[-1]
	pop	fp[21]
	push	sp[-1]
	pop	fp[22]
	push	sp[-1]
	pop	fp[23]
	push	sp[-1]
	pop	fp[24]
	pop	ac
	// global identifier s
	push	sb
	pop	ac
	push	ac
	push	0
	add
	// array-to-pointer
	// constant
	push	0
	// [
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// OUTPUT
	putc
	end
