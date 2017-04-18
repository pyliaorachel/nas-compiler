	push	0
	jmp	L000
L001:
	push	2
	pop	sb[0]
	push	1
	pop	fp[-4]
	push	fp[-5]
	push	fp[-4]
	add
	push	sb[0]
	add
	ret
L000:
	push	1
	push	2
	call	L001, 2
	push	5
	call	L001, 2
	push	sb[1]
	puti
