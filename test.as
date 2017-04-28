	push	sp
	push	1
	add
	pop	sp
	push	"hello"
	pop	sb[0]
	call	L000, 0
	push	sb[0]
	putc
	end
L000:
	push	'c'
	pop	sb[0]
	ret
