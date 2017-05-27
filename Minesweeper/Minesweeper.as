	push	sp
	push	200
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

	// variable assignment boardsize

	// push constant
	push	8

	pop	sb[2]

	// variable assignment isend

	// push constant
	push	0

	pop	sb[3]

	// variable assignment numofrevealed

	// push constant
	push	0

	pop	sb[4]

	// variable assignment numofmatched

	// push constant
	push	0

	pop	sb[5]

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
L092:

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
L101:

	// function call seedisvalid

	// push variable num
	push	fp[0]
	call	L003, 1

	// push constant
	push	0
	compEQ
	j0	L102

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
	jmp	L101
L102:

	// push variable num
	push	fp[0]
	ret
	ret
L093:

	// declare function
	push	sp
	push	8
	add
	pop	sp

	// variable assignment max

	// push variable @boardsize
	push	sb[2]

	// push variable @boardsize
	push	sb[2]
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
L105:

	// push variable i
	push	fp[1]

	// push variable @boardsize
	push	sb[2]
	compLT
	j0	L104

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

	// push variable @boardsize
	push	sb[2]
	mod

	pop	fp[3]

	// variable assignment y

	// push variable num
	push	fp[2]

	// push variable @boardsize
	push	sb[2]
	div

	pop	fp[4]

	// if statement

	// access struct member .isbomb
	push	sb
	push	6
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
	j0	L106

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
	jmp	L107
L106:

	// struct member assignment

	// push constant
	push	1

	push	sb
	push	6
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
L107:
L103:

	// variable assignment i

	// push variable i
	push	fp[1]

	// push constant
	push	1
	add

	pop	fp[1]
	jmp	L105
L104:

	// for loop

	// variable assignment i

	// push constant
	push	0

	pop	fp[1]
L110:

	// push variable i
	push	fp[1]

	// push variable @boardsize
	push	sb[2]
	compLT
	j0	L109

	// for loop

	// variable assignment j

	// push constant
	push	0

	pop	fp[5]
L113:

	// push variable j
	push	fp[5]

	// push variable @boardsize
	push	sb[2]
	compLT
	j0	L112

	// if statement

	// access struct member .isbomb
	push	sb
	push	6
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
	j0	L114

	// for loop

	// variable assignment k

	// push constant
	push	1
	neg

	pop	fp[6]
L117:

	// push variable k
	push	fp[6]

	// push constant
	push	1
	compLE
	j0	L116

	// for loop

	// variable assignment l

	// push constant
	push	1
	neg

	pop	fp[7]
L120:

	// push variable l
	push	fp[7]

	// push constant
	push	1
	compLE
	j0	L119

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

	// push variable @boardsize
	push	sb[2]
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

	// push variable @boardsize
	push	sb[2]
	compLT
	and
	j0	L121

	// struct member assignment

	// access struct member .neighborbombs
	push	sb
	push	6
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
	push	6
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
L121:
L118:

	// variable assignment l

	// push variable l
	push	fp[7]

	// push constant
	push	1
	add

	pop	fp[7]
	jmp	L120
L119:
L115:

	// variable assignment k

	// push variable k
	push	fp[6]

	// push constant
	push	1
	add

	pop	fp[6]
	jmp	L117
L116:

	// struct member assignment

	// access struct member .neighborbombs
	push	sb
	push	6
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
	push	6
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
L114:
L111:

	// variable assignment j

	// push variable j
	push	fp[5]

	// push constant
	push	1
	add

	pop	fp[5]
	jmp	L113
L112:
L108:

	// variable assignment i

	// push variable i
	push	fp[1]

	// push constant
	push	1
	add

	pop	fp[1]
	jmp	L110
L109:
	ret
L091:

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
L124:

	// push variable i
	push	fp[0]

	// push variable @boardsize
	push	sb[2]
	compLT
	j0	L123

	// for loop

	// variable assignment j

	// push constant
	push	0

	pop	fp[1]
L127:

	// push variable j
	push	fp[1]

	// push variable @boardsize
	push	sb[2]
	compLT
	j0	L126

	// struct member assignment

	// push constant
	push	0

	push	sb
	push	6
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
	push	6
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
	push	6
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
L125:

	// variable assignment j

	// push variable j
	push	fp[1]

	// push constant
	push	1
	add

	pop	fp[1]
	jmp	L127
L126:
L122:

	// variable assignment i

	// push variable i
	push	fp[0]

	// push constant
	push	1
	add

	pop	fp[0]
	jmp	L124
L123:

	// struct member assignment

	// push constant
	push	3

	push	sb
	push	198
	add
	push	0
	add

	pop	ac
	pop	ac[0]

	// struct member assignment

	// push constant
	push	3

	push	sb
	push	198
	add
	push	1
	add

	pop	ac
	pop	ac[0]

	// variable assignment @isend

	// push constant
	push	0

	pop	sb[3]

	// variable assignment @numofrevealed

	// push constant
	push	0

	pop	sb[4]

	// variable assignment @numofmatched

	// push constant
	push	0

	pop	sb[5]
	ret
L064:

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
L130:

	// push variable i
	push	fp[0]

	// push variable @boardsize
	push	sb[2]
	compLT
	j0	L129

	// for loop

	// variable assignment j

	// push constant
	push	0

	pop	fp[1]
L133:

	// push variable j
	push	fp[1]

	// push variable @boardsize
	push	sb[2]
	compLT
	j0	L132

	// if statement

	// access struct member .x
	push	sb
	push	198
	add
	push	0
	add

	pop	ac
	push	ac[0]

	// push variable j
	push	fp[1]
	compEQ

	// access struct member .y
	push	sb
	push	198
	add
	push	1
	add

	pop	ac
	push	ac[0]

	// push variable i
	push	fp[0]
	compEQ
	and
	j0	L134

	// Output

	// push constant
	push	'*'
	putc_
	jmp	L135
L134:

	// if statement

	// access struct member .status
	push	sb
	push	6
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
	push	ac[0]

	// push constant
	push	2
	compEQ
	j0	L136

	// Output

	// push constant
	push	'B'
	putc_
	jmp	L137
L136:

	// if statement

	// access struct member .status
	push	sb
	push	6
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
	push	ac[0]

	// push constant
	push	1
	compEQ
	j0	L138

	// Output

	// access struct member .neighborbombs
	push	sb
	push	6
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
	push	ac[0]
	puti_
	jmp	L139
L138:

	// Output

	// push constant
	push	'.'
	putc_
L139:
L137:
L135:
L131:

	// variable assignment j

	// push variable j
	push	fp[1]

	// push constant
	push	1
	add

	pop	fp[1]
	jmp	L133
L132:

	// Output

	// push constant
	push	' '
	putc
L128:

	// variable assignment i

	// push variable i
	push	fp[0]

	// push constant
	push	1
	add

	pop	fp[0]
	jmp	L130
L129:
	ret
L065:

	// declare function

	// Output

	// push normal string

	// push constant
	push	"	<i,j,k,l> to move up, left, down, right
	<r> to reveal
	<b> to mark bomb
	<u> to unmark bomb
	<q> to quit"
	puts
	ret
L066:

	// declare function

	// Output

	// push constant
	push	'('
	putc_

	// Output

	// access struct member .x
	push	sb
	push	198
	add
	push	0
	add

	pop	ac
	push	ac[0]
	puti_

	// Output

	// push constant
	push	','
	putc_

	// Output

	// access struct member .y
	push	sb
	push	198
	add
	push	1
	add

	pop	ac
	push	ac[0]
	puti_

	// Output

	// push constant
	push	')'
	putc
	ret
L086:

	// declare function

	// push variable @numofrevealed
	push	sb[4]

	// push variable @numofmatched
	push	sb[5]
	add

	// push variable @boardsize
	push	sb[2]

	// push variable @boardsize
	push	sb[2]
	mul
	compEQ
	ret
	ret
L090:

	// declare function

	// Output

	// push normal string

	// push constant
	push	"Bomb! You lose.
"
	puts
	ret
L089:

	// declare function

	// Output

	// push normal string

	// push constant
	push	"Congratulations! You have sweeped all the mines. You are a hero!
"
	puts
	ret
L073:

	// declare function

	// if statement

	// push variable command
	push	fp[-4]

	// push constant
	push	'i'
	compEQ
	j0	L140

	// struct member assignment

	// access struct member .y
	push	sb
	push	198
	add
	push	1
	add

	pop	ac
	push	ac[0]

	// push constant
	push	1
	sub

	// push variable @boardsize
	push	sb[2]
	add

	// push variable @boardsize
	push	sb[2]
	mod

	push	sb
	push	198
	add
	push	1
	add

	pop	ac
	pop	ac[0]
	jmp	L141
L140:

	// if statement

	// push variable command
	push	fp[-4]

	// push constant
	push	'j'
	compEQ
	j0	L142

	// struct member assignment

	// access struct member .x
	push	sb
	push	198
	add
	push	0
	add

	pop	ac
	push	ac[0]

	// push constant
	push	1
	sub

	// push variable @boardsize
	push	sb[2]
	add

	// push variable @boardsize
	push	sb[2]
	mod

	push	sb
	push	198
	add
	push	0
	add

	pop	ac
	pop	ac[0]
	jmp	L143
L142:

	// if statement

	// push variable command
	push	fp[-4]

	// push constant
	push	'k'
	compEQ
	j0	L144

	// struct member assignment

	// access struct member .y
	push	sb
	push	198
	add
	push	1
	add

	pop	ac
	push	ac[0]

	// push constant
	push	1
	add

	// push variable @boardsize
	push	sb[2]
	mod

	push	sb
	push	198
	add
	push	1
	add

	pop	ac
	pop	ac[0]
	jmp	L145
L144:

	// struct member assignment

	// access struct member .x
	push	sb
	push	198
	add
	push	0
	add

	pop	ac
	push	ac[0]

	// push constant
	push	1
	add

	// push variable @boardsize
	push	sb[2]
	mod

	push	sb
	push	198
	add
	push	0
	add

	pop	ac
	pop	ac[0]
L145:
L143:
L141:
	ret
L056:

	// declare function
	push	sp
	push	2
	add
	pop	sp

	// for loop

	// variable assignment k

	// push constant
	push	1
	neg

	pop	fp[0]
L148:

	// push variable k
	push	fp[0]

	// push constant
	push	1
	compLE
	j0	L147

	// for loop

	// variable assignment l

	// push constant
	push	1
	neg

	pop	fp[1]
L151:

	// push variable l
	push	fp[1]

	// push constant
	push	1
	compLE
	j0	L150

	// if statement

	// push variable i
	push	fp[-5]

	// push variable k
	push	fp[0]
	add

	// push constant
	push	0
	compGE

	// push variable i
	push	fp[-5]

	// push variable k
	push	fp[0]
	add

	// push variable @boardsize
	push	sb[2]
	compLT
	and

	// push variable j
	push	fp[-4]

	// push variable l
	push	fp[1]
	add

	// push constant
	push	0
	compGE
	and

	// push variable j
	push	fp[-4]

	// push variable l
	push	fp[1]
	add

	// push variable @boardsize
	push	sb[2]
	compLT
	and

	// access struct member .status
	push	sb
	push	6
	push	0

	// push variable i
	push	fp[-5]

	// push variable k
	push	fp[0]
	add
	add
	push	8
	mul

	// push variable j
	push	fp[-4]

	// push variable l
	push	fp[1]
	add
	add
	push	3
	mul
	add
	add
	push	2
	add

	pop	ac
	push	ac[0]

	// push constant
	push	1
	compNE
	and
	j0	L152

	// struct member assignment

	// push constant
	push	1

	push	sb
	push	6
	push	0

	// push variable i
	push	fp[-5]

	// push variable k
	push	fp[0]
	add
	add
	push	8
	mul

	// push variable j
	push	fp[-4]

	// push variable l
	push	fp[1]
	add
	add
	push	3
	mul
	add
	add
	push	2
	add

	pop	ac
	pop	ac[0]

	// if statement

	// access struct member .neighborbombs
	push	sb
	push	6
	push	0

	// push variable i
	push	fp[-5]

	// push variable k
	push	fp[0]
	add
	add
	push	8
	mul

	// push variable j
	push	fp[-4]

	// push variable l
	push	fp[1]
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
	push	0
	compEQ
	j0	L153

	// function call revealneighbors

	// push variable i
	push	fp[-5]

	// push variable k
	push	fp[0]
	add

	// push variable j
	push	fp[-4]

	// push variable l
	push	fp[1]
	add
	call	L056, 2
L153:

	// variable assignment @numofrevealed

	// push variable @numofrevealed
	push	sb[4]

	// push constant
	push	1
	add

	pop	sb[4]
L152:
L149:

	// variable assignment l

	// push variable l
	push	fp[1]

	// push constant
	push	1
	add

	pop	fp[1]
	jmp	L151
L150:
L146:

	// variable assignment k

	// push variable k
	push	fp[0]

	// push constant
	push	1
	add

	pop	fp[0]
	jmp	L148
L147:
	ret
L076:

	// declare function

	// if statement

	// access struct member .isbomb
	push	sb
	push	6
	push	0

	// access struct member .y
	push	sb
	push	198
	add
	push	1
	add

	pop	ac
	push	ac[0]
	add
	push	8
	mul

	// access struct member .x
	push	sb
	push	198
	add
	push	0
	add

	pop	ac
	push	ac[0]
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
	j0	L154

	// variable assignment @isend

	// push constant
	push	1

	pop	sb[3]
	jmp	L155
L154:

	// struct member assignment

	// push constant
	push	1

	push	sb
	push	6
	push	0

	// access struct member .y
	push	sb
	push	198
	add
	push	1
	add

	pop	ac
	push	ac[0]
	add
	push	8
	mul

	// access struct member .x
	push	sb
	push	198
	add
	push	0
	add

	pop	ac
	push	ac[0]
	add
	push	3
	mul
	add
	add
	push	2
	add

	pop	ac
	pop	ac[0]

	// if statement

	// access struct member .neighborbombs
	push	sb
	push	6
	push	0

	// access struct member .y
	push	sb
	push	198
	add
	push	1
	add

	pop	ac
	push	ac[0]
	add
	push	8
	mul

	// access struct member .x
	push	sb
	push	198
	add
	push	0
	add

	pop	ac
	push	ac[0]
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
	push	0
	compEQ
	j0	L156

	// function call revealneighbors

	// access struct member .y
	push	sb
	push	198
	add
	push	1
	add

	pop	ac
	push	ac[0]

	// access struct member .x
	push	sb
	push	198
	add
	push	0
	add

	pop	ac
	push	ac[0]
	call	L056, 2
L156:

	// variable assignment @numofrevealed

	// push variable @numofrevealed
	push	sb[4]

	// push constant
	push	1
	add

	pop	sb[4]
L155:
	ret
L079:

	// declare function

	// if statement

	// access struct member .status
	push	sb
	push	6
	push	0

	// access struct member .y
	push	sb
	push	198
	add
	push	1
	add

	pop	ac
	push	ac[0]
	add
	push	8
	mul

	// access struct member .x
	push	sb
	push	198
	add
	push	0
	add

	pop	ac
	push	ac[0]
	add
	push	3
	mul
	add
	add
	push	2
	add

	pop	ac
	push	ac[0]

	// push constant
	push	0
	compEQ
	j0	L157

	// struct member assignment

	// push constant
	push	2

	push	sb
	push	6
	push	0

	// access struct member .y
	push	sb
	push	198
	add
	push	1
	add

	pop	ac
	push	ac[0]
	add
	push	8
	mul

	// access struct member .x
	push	sb
	push	198
	add
	push	0
	add

	pop	ac
	push	ac[0]
	add
	push	3
	mul
	add
	add
	push	2
	add

	pop	ac
	pop	ac[0]

	// if statement

	// access struct member .isbomb
	push	sb
	push	6
	push	0

	// access struct member .y
	push	sb
	push	198
	add
	push	1
	add

	pop	ac
	push	ac[0]
	add
	push	8
	mul

	// access struct member .x
	push	sb
	push	198
	add
	push	0
	add

	pop	ac
	push	ac[0]
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
	j0	L158

	// variable assignment @numofmatched

	// push variable @numofmatched
	push	sb[5]

	// push constant
	push	1
	add

	pop	sb[5]
L158:
L157:
	ret
L082:

	// declare function

	// if statement

	// access struct member .status
	push	sb
	push	6
	push	0

	// access struct member .y
	push	sb
	push	198
	add
	push	1
	add

	pop	ac
	push	ac[0]
	add
	push	8
	mul

	// access struct member .x
	push	sb
	push	198
	add
	push	0
	add

	pop	ac
	push	ac[0]
	add
	push	3
	mul
	add
	add
	push	2
	add

	pop	ac
	push	ac[0]

	// push constant
	push	2
	compEQ
	j0	L159

	// struct member assignment

	// push constant
	push	0

	push	sb
	push	6
	push	0

	// access struct member .y
	push	sb
	push	198
	add
	push	1
	add

	pop	ac
	push	ac[0]
	add
	push	8
	mul

	// access struct member .x
	push	sb
	push	198
	add
	push	0
	add

	pop	ac
	push	ac[0]
	add
	push	3
	mul
	add
	add
	push	2
	add

	pop	ac
	pop	ac[0]

	// if statement

	// access struct member .isbomb
	push	sb
	push	6
	push	0

	// access struct member .y
	push	sb
	push	198
	add
	push	1
	add

	pop	ac
	push	ac[0]
	add
	push	8
	mul

	// access struct member .x
	push	sb
	push	198
	add
	push	0
	add

	pop	ac
	push	ac[0]
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
	j0	L160

	// variable assignment @numofmatched

	// push variable @numofmatched
	push	sb[5]

	// push constant
	push	1
	sub

	pop	sb[5]
L160:
L159:
	ret
L094:

	// declare function
	push	sp
	push	2
	add
	pop	sp

	// Output

	// push normal string

	// push constant
	push	"Start game!"
	puts

	// function call putboard
	call	L064, 0

	// function call putcmdinst
	call	L065, 0

	// function call putcursor
	call	L066, 0

	// while loop
L161:

	// push constant
	push	1
	j0	L162

	// Input
	getc

	// get to variable command
	pop	fp[0]

	// while loop
L163:

	// push variable command
	push	fp[0]

	// push constant
	push	'
'
	compEQ

	// push variable command
	push	fp[0]

	// push constant
	push	' '
	compEQ
	or

	// push variable command
	push	fp[0]

	// push constant
	push	'	'
	compEQ
	or
	j0	L164

	// Input
	getc

	// get to variable command
	pop	fp[0]
	jmp	L163
L164:

	// Input
	getc

	// get to variable nl
	pop	fp[1]

	// if statement

	// push variable command
	push	fp[0]

	// push constant
	push	'i'
	compEQ

	// push variable command
	push	fp[0]

	// push constant
	push	'j'
	compEQ
	or

	// push variable command
	push	fp[0]

	// push constant
	push	'k'
	compEQ
	or

	// push variable command
	push	fp[0]

	// push constant
	push	'l'
	compEQ
	or
	j0	L165

	// function call movecursor

	// push variable command
	push	fp[0]
	call	L073, 1
	jmp	L166
L165:

	// if statement

	// push variable command
	push	fp[0]

	// push constant
	push	'r'
	compEQ
	j0	L167

	// function call reveal
	call	L076, 0
	jmp	L168
L167:

	// if statement

	// push variable command
	push	fp[0]

	// push constant
	push	'b'
	compEQ
	j0	L169

	// function call markbomb
	call	L079, 0
	jmp	L170
L169:

	// if statement

	// push variable command
	push	fp[0]

	// push constant
	push	'u'
	compEQ
	j0	L171

	// function call unmarkbomb
	call	L082, 0
	jmp	L172
L171:

	// if statement

	// push variable command
	push	fp[0]

	// push constant
	push	'q'
	compEQ
	j0	L173
	jmp	L162
L173:
L172:
L170:
L168:
L166:

	// if statement

	// push variable @isend
	push	sb[3]

	// push constant
	push	0
	compEQ
	j0	L174

	// variable assignment @isend

	// function call checkendgame
	call	L086, 0

	pop	sb[3]

	// if statement

	// push variable @isend
	push	sb[3]

	// push constant
	push	0
	compEQ
	j0	L176

	// function call putboard
	call	L064, 0

	// function call putcursor
	call	L066, 0

	// Output

	// push normal string

	// push constant
	push	"Revealed: "
	puts_

	// Output

	// push variable @numofrevealed
	push	sb[4]
	puti

	// Output

	// push normal string

	// push constant
	push	"Matched: "
	puts_

	// Output

	// push variable @numofmatched
	push	sb[5]
	puti
	jmp	L177
L176:

	// function call playerwin
	call	L089, 0
	jmp	L162
L177:
	jmp	L175
L174:

	// function call playerlose
	call	L090, 0
	jmp	L162
L175:
	jmp	L161
L162:
	ret
L000:

	// declare function
	push	sp
	push	2
	add
	pop	sp

	// function call init
	call	L091, 0

	// function call genrandomboard

	// function call getseed
	call	L092, 0
	call	L093, 1

	// function call start
	call	L094, 0

	// Output

	// push normal string

	// push constant
	push	"New game? <y/n>"
	puts

	// Input
	getc

	// get to variable newgame
	pop	fp[0]

	// while loop
L178:

	// push variable newgame
	push	fp[0]

	// push constant
	push	'
'
	compEQ
	j0	L179

	// Input
	getc

	// get to variable newgame
	pop	fp[0]
	jmp	L178
L179:

	// while loop
L180:

	// push variable newgame
	push	fp[0]

	// push constant
	push	'y'
	compEQ
	j0	L181

	// function call init
	call	L091, 0

	// function call genrandomboard

	// function call getseed
	call	L092, 0
	call	L093, 1

	// function call start
	call	L094, 0

	// Output

	// push normal string

	// push constant
	push	"New game? <y/n>"
	puts

	// Input
	getc

	// get to variable newgame
	pop	fp[0]

	// while loop
L182:

	// push variable newgame
	push	fp[0]

	// push constant
	push	'y'
	compNE

	// push variable newgame
	push	fp[0]

	// push constant
	push	'n'
	compNE
	or
	j0	L183

	// Input
	getc

	// get to variable newgame
	pop	fp[0]
	jmp	L182
L183:

	// Input
	getc

	// get to variable nl
	pop	fp[1]
	jmp	L180
L181:

	// Output

	// push normal string

	// push constant
	push	"Have a nice day!"
	puts
	ret
