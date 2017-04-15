	push	0
	pop	k
L002:
	push	k
	push	10
	compLT
	j0	L001
	read
	push	k
	popi	a
L000:
	push	k
	push	1
	add
	pop	k
	jmp	L002
L001:
	push	0
	pop	k
L005:
	push	k
	push	10
	compLT
	j0	L004
	push	0
	pop	y
	push	0
	pop	l
L008:
	push	l
	push	10
	push	k
	sub
	push	1
	sub
	compLT
	j0	L007
	push	l
	pushi	a
	push	l
	push	1
	add
	pushi	a
	compGT
	j0	L009
	push	1
	pop	y
	push	l
	pushi	a
	pop	z
	push	l
	push	1
	add
	pushi	a
	push	l
	popi	a
	push	z
	push	l
	push	1
	add
	popi	a
L009:
L006:
	push	l
	push	1
	add
	pop	l
	jmp	L008
L007:
	push	y
	push	0
	compEQ
	j0	L010
	jmp	L004
L010:
L003:
	push	k
	push	1
	add
	pop	k
	jmp	L005
L004:
	push	0
	pop	k
L013:
	push	k
	push	10
	compLT
	j0	L012
	push	k
	pushi	a
	puti
L011:
	push	k
	push	1
	add
	pop	k
	jmp	L013
L012:
