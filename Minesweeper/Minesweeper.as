	push	sp
	push	194
	add
	pop	sp

	// variable assignment nummax

	// push constant
	push	99

	pop	sb[0]

	// variable assignment nummin

	// push constant
	push	1

	pop	sb[1]

	// function call main
	call	L000, 0
	end
L003:

	// declare function

	// push variable num
	push	fp[-4]

	// push variable @nummax
	push	sb[0]
	compLE

	// push variable num
	push	fp[-4]

	// push variable @nummin
	push	sb[1]
	compGE
	and

	// push variable num
	push	fp[-4]

	// push constant
	push	2
	mod

	// push constant
	push	1
	compEQ
	and
	ret
	ret
L031:

	// declare function
	push	sp
	push	1
	add
	pop	sp

	// Output

	// push normal string

	// push constant
	push	"Enter an ODD number between "
	puts_

	// Output

	// push variable @nummin
	push	sb[1]
	puti_

	// Output

	// push normal string

	// push constant
	push	" to "
	puts_

	// Output

	// push variable @nummax
	push	sb[0]
	puti_

	// Output

	// push normal string

	// push constant
	push	" to generate the board: "
	puts

	// Input
	geti

	// get to variable num
	pop	fp[0]

	// while loop
L033:

	// function call seedisvalid

	// push variable num
	push	fp[0]
	call	L003, 1

	// push constant
	push	0
	compEQ
	j0	L034

	// Output

	// push normal string

	// push constant
	push	"Number invalid!"
	puts

	// Output

	// push normal string

	// push constant
	push	"Enter an ODD number between "
	puts_

	// Output

	// push variable @nummin
	push	sb[1]
	puti_

	// Output

	// push normal string

	// push constant
	push	" to "
	puts_

	// Output

	// push variable @nummax
	push	sb[0]
	puti_

	// Output

	// push normal string

	// push constant
	push	" to generate the board: "
	puts

	// Input
	geti

	// get to variable num
	pop	fp[0]
	jmp	L033
L034:

	// push variable num
	push	fp[0]
	ret
	ret
L007:

	// declare function

	// dereference assignment

	// variable/array element dereference

	// push variable seed
	push	fp[-4]

	pop	ac
	push	ac[0]

	// variable/array element dereference

	// push variable seed
	push	fp[-4]

	pop	ac
	push	ac[0]

	// push constant
	push	21
	sla
	bitxor


	// push variable seed
	push	fp[-4]

	pop	ac
	pop	ac[0]

	// dereference assignment

	// variable/array element dereference

	// push variable seed
	push	fp[-4]

	pop	ac
	push	ac[0]

	// variable/array element dereference

	// push variable seed
	push	fp[-4]

	pop	ac
	push	ac[0]

	// push constant
	push	35
	sra
	bitxor


	// push variable seed
	push	fp[-4]

	pop	ac
	pop	ac[0]

	// dereference assignment

	// variable/array element dereference

	// push variable seed
	push	fp[-4]

	pop	ac
	push	ac[0]

	// variable/array element dereference

	// push variable seed
	push	fp[-4]

	pop	ac
	push	ac[0]

	// push constant
	push	4
	sla
	bitxor


	// push variable seed
	push	fp[-4]

	pop	ac
	pop	ac[0]

	// variable/array element dereference

	// push variable seed
	push	fp[-4]

	pop	ac
	push	ac[0]

	// push variable max
	push	fp[-5]

	// push variable min
	push	fp[-6]
	sub
	bitand

	// push variable min
	push	fp[-6]
	add
	ret
	ret
L032:

	// declare function
	push	sp
	push	8
	add
	pop	sp

	// variable assignment max

	// push variable size
	push	fp[-5]

	// push variable size
	push	fp[-5]
	mul

	// push constant
	push	1
	sub

	pop	fp[0]

	// for loop

	// variable assignment i

	// push constant
	push	0

	pop	fp[1]
L037:

	// push variable i
	push	fp[1]

	// push variable size
	push	fp[-5]
	compLT
	j0	L036

	// variable assignment num

	// function call getnextrandom

	// push constant
	push	0

	// push variable max
	push	fp[0]

	// variable/array element reference
	push	fp
	push	-4
	add
	call	L007, 3

	pop	fp[2]

	// variable assignment x

	// push variable num
	push	fp[2]

	// push variable size
	push	fp[-5]
	mod

	pop	fp[3]

	// variable assignment y

	// push variable num
	push	fp[2]

	// push variable size
	push	fp[-5]
	div

	pop	fp[4]

	// if statement

	// access struct member .isbomb
	push	sb
	push	2
	push	0

	// push variable y
	push	fp[4]
	add
	push	8
	mul

	// push variable x
	push	fp[3]
	add
	push	3
	mul
	add
	add
	push	0
	add

	pop	ac
	push	ac[0]

	// push constant
	push	1
	compEQ
	j0	L038

	// variable assignment i

	// push variable i
	push	fp[1]

	// push constant
	push	1
	sub

	pop	fp[1]

	// variable assignment num

	// push variable num
	push	fp[2]

	// push constant
	push	71
	mul

	pop	fp[2]
	jmp	L039
L038:

	// struct member assignment

	// push constant
	push	1

	push	sb
	push	2
	push	0

	// push variable y
	push	fp[4]
	add
	push	8
	mul

	// push variable x
	push	fp[3]
	add
	push	3
	mul
	add
	add
	push	0
	add

	pop	ac
	pop	ac[0]
L039:
L035:

	// variable assignment i

	// push variable i
	push	fp[1]

	// push constant
	push	1
	add

	pop	fp[1]
	jmp	L037
L036:

	// for loop

	// variable assignment i

	// push constant
	push	0

	pop	fp[1]
L042:

	// push variable i
	push	fp[1]

	// push variable size
	push	fp[-5]
	compLT
	j0	L041

	// for loop

	// variable assignment j

	// push constant
	push	0

	pop	fp[5]
L045:

	// push variable j
	push	fp[5]

	// push variable size
	push	fp[-5]
	compLT
	j0	L044

	// if statement

	// access struct member .isbomb
	push	sb
	push	2
	push	0

	// push variable i
	push	fp[1]
	add
	push	8
	mul

	// push variable j
	push	fp[5]
	add
	push	3
	mul
	add
	add
	push	0
	add

	pop	ac
	push	ac[0]

	// push constant
	push	1
	compEQ
	j0	L046

	// for loop

	// variable assignment k

	// push constant
	push	1
	neg

	pop	fp[6]
L049:

	// push variable k
	push	fp[6]

	// push constant
	push	1
	compLE
	j0	L048

	// for loop

	// variable assignment l

	// push constant
	push	1
	neg

	pop	fp[7]
L052:

	// push variable l
	push	fp[7]

	// push constant
	push	1
	compLE
	j0	L051

	// if statement

	// push variable i
	push	fp[1]

	// push variable k
	push	fp[6]
	add

	// push constant
	push	0
	compGE

	// push variable i
	push	fp[1]

	// push variable k
	push	fp[6]
	add

	// push variable size
	push	fp[-5]
	compLT
	and

	// push variable j
	push	fp[5]

	// push variable l
	push	fp[7]
	add

	// push constant
	push	0
	compGE
	and

	// push variable j
	push	fp[5]

	// push variable l
	push	fp[7]
	add

	// push variable size
	push	fp[-5]
	compLT
	and
	j0	L053

	// struct member assignment

	// access struct member .neighborbombs
	push	sb
	push	2
	push	0

	// push variable i
	push	fp[1]

	// push variable k
	push	fp[6]
	add
	add
	push	8
	mul

	// push variable j
	push	fp[5]

	// push variable l
	push	fp[7]
	add
	add
	push	3
	mul
	add
	add
	push	1
	add

	pop	ac
	push	ac[0]

	// push constant
	push	1
	add

	push	sb
	push	2
	push	0

	// push variable i
	push	fp[1]

	// push variable k
	push	fp[6]
	add
	add
	push	8
	mul

	// push variable j
	push	fp[5]

	// push variable l
	push	fp[7]
	add
	add
	push	3
	mul
	add
	add
	push	1
	add

	pop	ac
	pop	ac[0]
L053:
L050:

	// variable assignment l

	// push variable l
	push	fp[7]

	// push constant
	push	1
	add

	pop	fp[7]
	jmp	L052
L051:
L047:

	// variable assignment k

	// push variable k
	push	fp[6]

	// push constant
	push	1
	add

	pop	fp[6]
	jmp	L049
L048:

	// struct member assignment

	// access struct member .neighborbombs
	push	sb
	push	2
	push	0

	// push variable i
	push	fp[1]
	add
	push	8
	mul

	// push variable j
	push	fp[5]
	add
	push	3
	mul
	add
	add
	push	1
	add

	pop	ac
	push	ac[0]

	// push constant
	push	1
	sub

	push	sb
	push	2
	push	0

	// push variable i
	push	fp[1]
	add
	push	8
	mul

	// push variable j
	push	fp[5]
	add
	push	3
	mul
	add
	add
	push	1
	add

	pop	ac
	pop	ac[0]
L046:
L043:

	// variable assignment j

	// push variable j
	push	fp[5]

	// push constant
	push	1
	add

	pop	fp[5]
	jmp	L045
L044:
L040:

	// variable assignment i

	// push variable i
	push	fp[1]

	// push constant
	push	1
	add

	pop	fp[1]
	jmp	L042
L041:
	ret
L030:

	// declare function
	push	sp
	push	2
	add
	pop	sp

	// for loop

	// variable assignment i

	// push constant
	push	0

	pop	fp[0]
L056:

	// push variable i
	push	fp[0]

	// push constant
	push	8
	compLT
	j0	L055

	// for loop

	// variable assignment j

	// push constant
	push	0

	pop	fp[1]
L059:

	// push variable j
	push	fp[1]

	// push constant
	push	8
	compLT
	j0	L058

	// struct member assignment

	// push constant
	push	0

	push	sb
	push	2
	push	0

	// push variable i
	push	fp[0]
	add
	push	8
	mul

	// push variable j
	push	fp[1]
	add
	push	3
	mul
	add
	add
	push	0
	add

	pop	ac
	pop	ac[0]

	// struct member assignment

	// push constant
	push	0

	push	sb
	push	2
	push	0

	// push variable i
	push	fp[0]
	add
	push	8
	mul

	// push variable j
	push	fp[1]
	add
	push	3
	mul
	add
	add
	push	1
	add

	pop	ac
	pop	ac[0]

	// struct member assignment

	// push constant
	push	0

	push	sb
	push	2
	push	0

	// push variable i
	push	fp[0]
	add
	push	8
	mul

	// push variable j
	push	fp[1]
	add
	push	3
	mul
	add
	add
	push	2
	add

	pop	ac
	pop	ac[0]
L057:

	// variable assignment j

	// push variable j
	push	fp[1]

	// push constant
	push	1
	add

	pop	fp[1]
	jmp	L059
L058:
L054:

	// variable assignment i

	// push variable i
	push	fp[0]

	// push constant
	push	1
	add

	pop	fp[0]
	jmp	L056
L055:
	ret
L000:

	// declare function

	// function call initboard
	call	L030, 0

	// function call genrandomboard

	// push constant
	push	8

	// function call getseed
	call	L031, 0
	call	L032, 2
	ret
