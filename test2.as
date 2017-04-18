	push	100
	jmp	L000
L001:
	push	30
	push	sb[0]
	ret
L000:
	call	L001, 0
	push	sb[1]
	puti
