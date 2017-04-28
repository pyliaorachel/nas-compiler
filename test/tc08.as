	push	sp
	push	1
	add
	pop	sp
	push	999
	pop	sb[0]
	push	sb[0]
	call	L000, 1
	end
L000:
	push	fp[-4]
	puti
	ret
