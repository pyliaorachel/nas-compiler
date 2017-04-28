	push	sp
	push	0
	add
	pop	sp
	call	L000, 0
	call	L001, 0
	call	L002, 0
	end
L000:
	push	sp
	push	0
	add
	pop	sp
	push	1
	puti
	ret
L001:
	push	sp
	push	0
	add
	pop	sp
	push	5
	puti
	ret
L002:
	push	sp
	push	0
	add
	pop	sp
	push	12
	puti
	ret
