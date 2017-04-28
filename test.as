	push	sp
	push	2
	add
	pop	sp
	push	100
	pop	sb[0]
	call	L000, 0
	pop	sb[1]
	push	sb[1]
	puti
	push	sb[1]
	puti
	call	L001, 0
	push	sb[1]
	puti
	end
L000:
	push	sp
	push	1
	add
	pop	sp
	push	30
	pop	sb[0]
	push	5
	pop	fp[0]
	push	sb[0]
	push	fp[0]
	add
	ret
	ret
L001:
	push	sp
	push	1
	add
	pop	sp
	push	50
	pop	sb[1]
	push	1
	pop	fp[0]
	ret
