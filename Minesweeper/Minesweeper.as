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
L023:

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
L025:

	// function call seedisvalid

	// push variable num
	push	fp[0]
	call	L003, 1

	// push constant
	push	0
	compEQ
	j0	L026

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
	jmp	L025
L026:

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
L024:

	// declare function
	push	sp
	push	6
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
L029:

	// push variable i
	push	fp[1]

	// push variable size
	push	fp[-5]
	compLT
	j0	L028

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

	// Output

	// push variable num
	push	fp[2]
	puti

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
	j0	L030

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
	jmp	L031
L030:

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
L031:
L027:

	// variable assignment i

	// push variable i
	push	fp[1]

	// push constant
	push	1
	add

	pop	fp[1]
	jmp	L029
L028:

	// for loop

	// variable assignment i

	// push constant
	push	0

	pop	fp[1]
L034:

	// push variable i
	push	fp[1]

	// push variable size
	push	fp[-5]
	compLT
	j0	L033

	// for loop

	// variable assignment j

	// push constant
	push	0

	pop	fp[5]
L037:

	// push variable j
	push	fp[5]

	// push variable size
	push	fp[-5]
	compLT
	j0	L036

	// Output

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
	puti_
L035:

	// variable assignment j

	// push variable j
	push	fp[5]

	// push constant
	push	1
	add

	pop	fp[5]
	jmp	L037
L036:

	// Output

	// push constant
	push	' '
	putc
L032:

	// variable assignment i

	// push variable i
	push	fp[1]

	// push constant
	push	1
	add

	pop	fp[1]
	jmp	L034
L033:
	ret
L022:

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
L040:

	// push variable i
	push	fp[0]

	// push constant
	push	8
	compLT
	j0	L039

	// for loop

	// variable assignment j

	// push constant
	push	0

	pop	fp[1]
L043:

	// push variable j
	push	fp[1]

	// push constant
	push	8
	compLT
	j0	L042

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
L041:

	// variable assignment j

	// push variable j
	push	fp[1]

	// push constant
	push	1
	add

	pop	fp[1]
	jmp	L043
L042:
L038:

	// variable assignment i

	// push variable i
	push	fp[0]

	// push constant
	push	1
	add

	pop	fp[0]
	jmp	L040
L039:
	ret
L000:

	// declare function

	// function call initboard
	call	L022, 0

	// function call genrandomboard

	// push constant
	push	8

	// function call getseed
	call	L023, 0
	call	L024, 2
	ret
