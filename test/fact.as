	jmp	L000
L001:
	push	fp[-4]
	push	1
	compLT
	j0	L002
	push	1
	ret
L002:
	push	fp[-4]
	push	fp[-4]
	push	1
	sub
	call	L001, 1
	mul
	ret
L000:
	push	"Please enter a +ve int <= 12: "
	puts_
	geti
	push	sb[0]
	push	12
	compLE
	j0	L003
	push	sb[0]
	call	L001, 1
	puti
	jmp	L004
L003:
	push	sb[0]
	puti_
	push	" > 12!!"
	puts
L004:
