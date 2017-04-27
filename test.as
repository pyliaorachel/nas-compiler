start stmt 3
execute 3
	push	100
execute 3
	call	L000, 0
execute 3
	push	sb[1]
	puti
end stmt
start func 2
execute func 4
	jmp	L001
L000:
	push	30
	push	sb[0]
	ret
L001:
execute func 4
	jmp	L002
L003:
	push	100
	pop	sb[1]
L002:
end func
wrapup