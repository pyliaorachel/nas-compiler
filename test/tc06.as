	push	1
sb[0] isDeclared? 0
	push	1
sb[1] isDeclared? 0
L002:
	push	sb[1]
	push	100
	compLT
	j0	L001
	push	sb[1]
sb[2] isDeclared? 0
L003:
	push	sb[2]
	push	0
	compGT
	j0	L004
	push	sb[2]
	push	2
	div
sb[2] isDeclared? 1
	pop	sb[2]
	push	sb[2]
	push	1
	compEQ
	j0	L005
	jmp	L004
L005:
	jmp	L003
L004:
	push	sb[1]
	push	10
	compLT
	j0	L006
	jmp	L000
L006:
	push	sb[0]
	push	1
	add
sb[0] isDeclared? 1
	pop	sb[0]
L000:
	push	sb[1]
	push	sb[0]
	add
sb[1] isDeclared? 1
	pop	sb[1]
	jmp	L002
L001:
	push	sb[1]
	puti_
	push	", "
	puts_
	push	sb[2]
	puti_
	push	", "
	puts_
	push	sb[0]
	puti
