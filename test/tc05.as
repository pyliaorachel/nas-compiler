	push	100
	push	100
	push	200
	push	sb[0]
	push	sb[1]
	compGE
	j0	L000
	push	"a>b"
	puts
	push	sb[0]
	push	sb[1]
	compEQ
	j0	L002
	push	"a==b"
	puts
L002:
	jmp	L001
L000:
	push	"a<b"
	puts
L001:
	push	sb[2]
	push	sb[0]
	compLT
	j0	L003
	push	"c<a"
	puts
	jmp	L004
L003:
	push	"c>=a"
	puts
L004:
