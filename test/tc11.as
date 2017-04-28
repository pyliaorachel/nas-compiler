	push	sp
	push	1
	add
	pop	sp
	call	L000, 0
	call	L001, 0
	end
L002:
	push	sp
	push	0
	add
	pop	sp
	push	10
	pop	sb[0]
	ret
L001:
	push	sp
	push	0
	add
	pop	sp
	push	sb[0]
	puti
	ret
