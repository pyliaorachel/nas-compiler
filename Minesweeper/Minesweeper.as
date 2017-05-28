	push	sp
	push	201
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

	// variable assignment isstdgui

	// push constant
	push	0

	pop	sb[6]

	// function call main
	call	L000, 0
	end
L004:

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
L055:

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
L112:

	// declare function
	push	sp
	push	1
	add
	pop	sp

	// if statement

	// push variable @isstdgui
	push	sb[6]

	// push constant
	push	1
	compEQ
	j0	L131

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
L131:

	// Input
	geti

	// get to variable num
	pop	fp[0]

	// while loop
L132:

	// function call seedisvalid

	// push variable num
	push	fp[0]
	call	L004, 1

	// push constant
	push	0
	compEQ
	j0	L133

	// if statement

	// push variable @isstdgui
	push	sb[6]

	// push constant
	push	1
	compEQ
	j0	L134

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
	jmp	L135
L134:

	// Output

	// push constant
	push	'*'
	putc_

	// Output

	// push constant
	push	'x'
	putc_
L135:

	// Input
	geti

	// get to variable num
	pop	fp[0]
	jmp	L132
L133:

	// push variable num
	push	fp[0]
	ret
	ret
L076:

	// declare function
	push	sp
	push	2
	add
	pop	sp

	// if statement

	// push variable @isstdgui
	push	sb[6]

	// push constant
	push	0
	compEQ
	j0	L136

	// Output

	// push constant
	push	'*'
	putc_

	// Output

	// push constant
	push	'b'
	putc_
L136:

	// for loop

	// variable assignment i

	// push constant
	push	0

	pop	fp[0]
L139:

	// push variable i
	push	fp[0]

	// push variable @boardsize
	push	sb[2]
	compLT
	j0	L138

	// for loop

	// variable assignment j

	// push constant
	push	0

	pop	fp[1]
L142:

	// push variable j
	push	fp[1]

	// push variable @boardsize
	push	sb[2]
	compLT
	j0	L141

	// if statement

	// push variable @isstdgui
	push	sb[6]

	// push constant
	push	1
	compEQ
	j0	L143

	// if statement

	// access struct member .x
	push	sb
	push	199
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
	push	199
	add
	push	1
	add

	pop	ac
	push	ac[0]

	// push variable i
	push	fp[0]
	compEQ
	and
	j0	L145

	// Output

	// push constant
	push	'*'
	putc_
	jmp	L146
L145:

	// if statement

	// access struct member .status
	push	sb
	push	7
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
	j0	L147

	// Output

	// push constant
	push	'B'
	putc_
	jmp	L148
L147:

	// if statement

	// access struct member .status
	push	sb
	push	7
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
	j0	L149

	// Output

	// access struct member .neighborbombs
	push	sb
	push	7
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
	jmp	L150
L149:

	// Output

	// push constant
	push	'.'
	putc_
L150:
L148:
L146:
	jmp	L144
L143:

	// Output

	// access struct member .isbomb
	push	sb
	push	7
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
	push	ac[0]
	puti_

	// Output

	// access struct member .neighborbombs
	push	sb
	push	7
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

	// Output

	// access struct member .status
	push	sb
	push	7
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
	puti_
L144:
L140:

	// variable assignment j

	// push variable j
	push	fp[1]

	// push constant
	push	1
	add

	pop	fp[1]
	jmp	L142
L141:
L137:

	// variable assignment i

	// push variable i
	push	fp[0]

	// push constant
	push	1
	add

	pop	fp[0]
	jmp	L139
L138:
	ret
L077:

	// declare function

	// if statement

	// push variable @isstdgui
	push	sb[6]

	// push constant
	push	1
	compEQ
	j0	L151

	// Output

	// push normal string

	// push constant
	push	"	<i,j,k,l> to move up, left, down, right
	<r> to reveal
	<b> to mark bomb
	<u> to unmark bomb
	<q> to quit"
	puts
L151:
	ret
L078:

	// declare function

	// if statement

	// push variable @isstdgui
	push	sb[6]

	// push constant
	push	1
	compEQ
	j0	L152

	// Output

	// push constant
	push	'('
	putc_

	// Output

	// access struct member .x
	push	sb
	push	199
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
	push	199
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
L152:
	ret
L085:

	// declare function

	// if statement

	// push variable command
	push	fp[-4]

	// push constant
	push	'i'
	compEQ
	j0	L153

	// struct member assignment

	// access struct member .y
	push	sb
	push	199
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
	push	199
	add
	push	1
	add

	pop	ac
	pop	ac[0]
	jmp	L154
L153:

	// if statement

	// push variable command
	push	fp[-4]

	// push constant
	push	'j'
	compEQ
	j0	L155

	// struct member assignment

	// access struct member .x
	push	sb
	push	199
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
	push	199
	add
	push	0
	add

	pop	ac
	pop	ac[0]
	jmp	L156
L155:

	// if statement

	// push variable command
	push	fp[-4]

	// push constant
	push	'k'
	compEQ
	j0	L157

	// struct member assignment

	// access struct member .y
	push	sb
	push	199
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
	push	199
	add
	push	1
	add

	pop	ac
	pop	ac[0]
	jmp	L158
L157:

	// struct member assignment

	// access struct member .x
	push	sb
	push	199
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
	push	199
	add
	push	0
	add

	pop	ac
	pop	ac[0]
L158:
L156:
L154:
	ret
L038:

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
L161:

	// push variable k
	push	fp[0]

	// push constant
	push	1
	compLE
	j0	L160

	// for loop

	// variable assignment l

	// push constant
	push	1
	neg

	pop	fp[1]
L164:

	// push variable l
	push	fp[1]

	// push constant
	push	1
	compLE
	j0	L163

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
	push	7
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
	j0	L165

	// struct member assignment

	// push constant
	push	1

	push	sb
	push	7
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
	push	7
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
	j0	L166

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
	call	L038, 2
L166:

	// variable assignment @numofrevealed

	// push variable @numofrevealed
	push	sb[4]

	// push constant
	push	1
	add

	pop	sb[4]
L165:
L162:

	// variable assignment l

	// push variable l
	push	fp[1]

	// push constant
	push	1
	add

	pop	fp[1]
	jmp	L164
L163:
L159:

	// variable assignment k

	// push variable k
	push	fp[0]

	// push constant
	push	1
	add

	pop	fp[0]
	jmp	L161
L160:
	ret
L089:

	// declare function

	// struct member assignment

	// push constant
	push	1

	push	sb
	push	7
	push	0

	// access struct member .y
	push	sb
	push	199
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
	push	199
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
	push	7
	push	0

	// access struct member .y
	push	sb
	push	199
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
	push	199
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
	j0	L167

	// variable assignment @isend

	// push constant
	push	1

	pop	sb[3]
	jmp	L168
L167:

	// if statement

	// access struct member .neighborbombs
	push	sb
	push	7
	push	0

	// access struct member .y
	push	sb
	push	199
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
	push	199
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
	j0	L169

	// function call revealneighbors

	// access struct member .y
	push	sb
	push	199
	add
	push	1
	add

	pop	ac
	push	ac[0]

	// access struct member .x
	push	sb
	push	199
	add
	push	0
	add

	pop	ac
	push	ac[0]
	call	L038, 2
L169:

	// variable assignment @numofrevealed

	// push variable @numofrevealed
	push	sb[4]

	// push constant
	push	1
	add

	pop	sb[4]
L168:
	ret
L092:

	// declare function

	// if statement

	// access struct member .status
	push	sb
	push	7
	push	0

	// access struct member .y
	push	sb
	push	199
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
	push	199
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
	j0	L170

	// struct member assignment

	// push constant
	push	2

	push	sb
	push	7
	push	0

	// access struct member .y
	push	sb
	push	199
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
	push	199
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
	push	7
	push	0

	// access struct member .y
	push	sb
	push	199
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
	push	199
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
	j0	L171

	// variable assignment @numofmatched

	// push variable @numofmatched
	push	sb[5]

	// push constant
	push	1
	add

	pop	sb[5]
L171:
L170:
	ret
L095:

	// declare function

	// if statement

	// access struct member .status
	push	sb
	push	7
	push	0

	// access struct member .y
	push	sb
	push	199
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
	push	199
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
	j0	L172

	// struct member assignment

	// push constant
	push	0

	push	sb
	push	7
	push	0

	// access struct member .y
	push	sb
	push	199
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
	push	199
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
	push	7
	push	0

	// access struct member .y
	push	sb
	push	199
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
	push	199
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
	j0	L173

	// variable assignment @numofmatched

	// push variable @numofmatched
	push	sb[5]

	// push constant
	push	1
	sub

	pop	sb[5]
L173:
L172:
	ret
L109:

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
L176:

	// push variable i
	push	fp[0]

	// push variable @boardsize
	push	sb[2]
	compLT
	j0	L175

	// for loop

	// variable assignment j

	// push constant
	push	0

	pop	fp[1]
L179:

	// push variable j
	push	fp[1]

	// push variable @boardsize
	push	sb[2]
	compLT
	j0	L178

	// struct member assignment

	// push constant
	push	0

	push	sb
	push	7
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
	push	7
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
	push	7
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
L177:

	// variable assignment j

	// push variable j
	push	fp[1]

	// push constant
	push	1
	add

	pop	fp[1]
	jmp	L179
L178:
L174:

	// variable assignment i

	// push variable i
	push	fp[0]

	// push constant
	push	1
	add

	pop	fp[0]
	jmp	L176
L175:

	// struct member assignment

	// push variable @boardsize
	push	sb[2]

	// push constant
	push	1
	sub

	// push constant
	push	2
	div

	push	sb
	push	199
	add
	push	0
	add

	pop	ac
	pop	ac[0]

	// struct member assignment

	// access struct member .x
	push	sb
	push	199
	add
	push	0
	add

	pop	ac
	push	ac[0]

	push	sb
	push	199
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
L113:

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
L182:

	// push variable i
	push	fp[1]

	// push variable @boardsize
	push	sb[2]
	compLT
	j0	L181

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
	call	L055, 3

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
	push	7
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
	j0	L183

	// variable assignment i

	// push variable i
	push	fp[1]

	// push constant
	push	1
	sub

	pop	fp[1]
	jmp	L184
L183:

	// struct member assignment

	// push constant
	push	1

	push	sb
	push	7
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
L184:
L180:

	// variable assignment i

	// push variable i
	push	fp[1]

	// push constant
	push	1
	add

	pop	fp[1]
	jmp	L182
L181:

	// for loop

	// variable assignment i

	// push constant
	push	0

	pop	fp[1]
L187:

	// push variable i
	push	fp[1]

	// push variable @boardsize
	push	sb[2]
	compLT
	j0	L186

	// for loop

	// variable assignment j

	// push constant
	push	0

	pop	fp[5]
L190:

	// push variable j
	push	fp[5]

	// push variable @boardsize
	push	sb[2]
	compLT
	j0	L189

	// if statement

	// access struct member .isbomb
	push	sb
	push	7
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
	j0	L191

	// for loop

	// variable assignment k

	// push constant
	push	1
	neg

	pop	fp[6]
L194:

	// push variable k
	push	fp[6]

	// push constant
	push	1
	compLE
	j0	L193

	// for loop

	// variable assignment l

	// push constant
	push	1
	neg

	pop	fp[7]
L197:

	// push variable l
	push	fp[7]

	// push constant
	push	1
	compLE
	j0	L196

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
	j0	L198

	// struct member assignment

	// access struct member .neighborbombs
	push	sb
	push	7
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
	push	7
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
L198:
L195:

	// variable assignment l

	// push variable l
	push	fp[7]

	// push constant
	push	1
	add

	pop	fp[7]
	jmp	L197
L196:
L192:

	// variable assignment k

	// push variable k
	push	fp[6]

	// push constant
	push	1
	add

	pop	fp[6]
	jmp	L194
L193:

	// struct member assignment

	// access struct member .neighborbombs
	push	sb
	push	7
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
	push	7
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
L191:
L188:

	// variable assignment j

	// push variable j
	push	fp[5]

	// push constant
	push	1
	add

	pop	fp[5]
	jmp	L190
L189:
L185:

	// variable assignment i

	// push variable i
	push	fp[1]

	// push constant
	push	1
	add

	pop	fp[1]
	jmp	L187
L186:
	ret
L101:

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
L108:

	// declare function

	// if statement

	// push variable @isstdgui
	push	sb[6]

	// push constant
	push	1
	compEQ
	j0	L199

	// Output

	// push normal string

	// push constant
	push	"Bomb! You lose.
"
	puts
	jmp	L200
L199:

	// Output

	// push constant
	push	'*'
	putc_

	// Output

	// push constant
	push	'L'
	putc
L200:
	ret
L107:

	// declare function

	// if statement

	// push variable @isstdgui
	push	sb[6]

	// push constant
	push	1
	compEQ
	j0	L201

	// Output

	// push normal string

	// push constant
	push	"Congratulations! You have sweeped all the mines. You are a hero!
"
	puts
	jmp	L202
L201:

	// Output

	// push constant
	push	'*'
	putc_

	// Output

	// push constant
	push	'W'
	putc_
L202:
	ret
L114:

	// declare function
	push	sp
	push	2
	add
	pop	sp

	// function call putboard
	call	L076, 0

	// function call putcmdinst
	call	L077, 0

	// function call putcursor
	call	L078, 0

	// while loop
L203:

	// push constant
	push	1
	j0	L204

	// Input
	getc

	// get to variable command
	pop	fp[0]

	// while loop
L205:

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
	j0	L206

	// Input
	getc

	// get to variable command
	pop	fp[0]
	jmp	L205
L206:

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
	j0	L207

	// function call movecursor

	// push variable command
	push	fp[0]
	call	L085, 1

	// if statement

	// push variable @isstdgui
	push	sb[6]

	// push constant
	push	0
	compEQ
	j0	L209

	// Output

	// push constant
	push	'*'
	putc_

	// Output

	// push variable command
	push	fp[0]
	putc_
L209:
	jmp	L208
L207:

	// if statement

	// push variable command
	push	fp[0]

	// push constant
	push	'r'
	compEQ
	j0	L210

	// function call reveal
	call	L089, 0
	jmp	L211
L210:

	// if statement

	// push variable command
	push	fp[0]

	// push constant
	push	'b'
	compEQ
	j0	L212

	// function call markbomb
	call	L092, 0
	jmp	L213
L212:

	// if statement

	// push variable command
	push	fp[0]

	// push constant
	push	'u'
	compEQ
	j0	L214

	// function call unmarkbomb
	call	L095, 0
	jmp	L215
L214:

	// if statement

	// push variable command
	push	fp[0]

	// push constant
	push	'q'
	compEQ
	j0	L216

	// if statement

	// push variable @isstdgui
	push	sb[6]

	// push constant
	push	0
	compEQ
	j0	L218

	// Output

	// push constant
	push	'*'
	putc_

	// Output

	// push constant
	push	'q'
	putc_
L218:

	// push constant
	push	1
	neg
	ret
	jmp	L217
L216:
	jmp	L203
L217:
L215:
L213:
L211:
L208:

	// if statement

	// push variable @isend
	push	sb[3]

	// push constant
	push	0
	compEQ
	j0	L219

	// variable assignment @isend

	// function call checkendgame
	call	L101, 0

	pop	sb[3]

	// if statement

	// push variable @isend
	push	sb[3]

	// push constant
	push	0
	compEQ
	j0	L221

	// if statement

	// push variable @isstdgui
	push	sb[6]

	// push constant
	push	1
	compEQ
	j0	L223

	// function call putboard
	call	L076, 0

	// function call putcursor
	call	L078, 0
	jmp	L224
L223:

	// if statement

	// push variable command
	push	fp[0]

	// push constant
	push	'i'
	compNE

	// push variable command
	push	fp[0]

	// push constant
	push	'j'
	compNE
	and

	// push variable command
	push	fp[0]

	// push constant
	push	'k'
	compNE
	and

	// push variable command
	push	fp[0]

	// push constant
	push	'l'
	compNE
	and
	j0	L225

	// function call putboard
	call	L076, 0
L225:
L224:
	jmp	L222
L221:

	// function call playerwin
	call	L107, 0

	// function call putboard
	call	L076, 0
	jmp	L204
L222:
	jmp	L220
L219:

	// function call playerlose
	call	L108, 0

	// function call putboard
	call	L076, 0
	jmp	L204
L220:
	jmp	L203
L204:

	// push constant
	push	0
	ret
	ret
L000:

	// declare function
	push	sp
	push	3
	add
	pop	sp

	// function call init
	call	L109, 0

	// if statement

	// push variable @isstdgui
	push	sb[6]

	// push constant
	push	1
	compEQ
	j0	L226

	// Output

	// push normal string

	// push constant
	push	"Start game!"
	puts
	jmp	L227
L226:

	// Output

	// push constant
	push	's'
	putc_
L227:

	// function call genrandomboard

	// function call getseed
	call	L112, 0
	call	L113, 1

	// variable assignment status

	// function call start
	call	L114, 0

	pop	fp[0]

	// if statement

	// push variable status
	push	fp[0]

	// push constant
	push	1
	neg
	compEQ
	j0	L228

	// if statement

	// push variable @isstdgui
	push	sb[6]

	// push constant
	push	1
	compEQ
	j0	L229

	// Output

	// push normal string

	// push constant
	push	"Have a nice day!"
	puts
	jmp	L230
L229:

	// Output

	// push constant
	push	'q'
	putc_
L230:

	// push constant
	push	0
	ret
L228:

	// if statement

	// push variable @isstdgui
	push	sb[6]

	// push constant
	push	1
	compEQ
	j0	L231

	// Output

	// push normal string

	// push constant
	push	"New game? <y/n>"
	puts
L231:

	// Input
	getc

	// get to variable newgame
	pop	fp[1]

	// while loop
L232:

	// push variable newgame
	push	fp[1]

	// push constant
	push	'
'
	compEQ

	// push variable newgame
	push	fp[1]

	// push constant
	push	'y'
	compNE

	// push variable newgame
	push	fp[1]

	// push constant
	push	'n'
	compNE
	and
	or
	j0	L233

	// Input
	getc

	// get to variable newgame
	pop	fp[1]
	jmp	L232
L233:

	// Input
	getc

	// get to variable nl
	pop	fp[2]

	// if statement

	// push variable @isstdgui
	push	sb[6]

	// push constant
	push	0
	compEQ
	j0	L234

	// Output

	// push constant
	push	'*'
	putc_

	// Output

	// push variable newgame
	push	fp[1]
	putc_
L234:

	// while loop
L235:

	// push variable newgame
	push	fp[1]

	// push constant
	push	'y'
	compEQ
	j0	L236

	// function call init
	call	L109, 0

	// function call genrandomboard

	// function call getseed
	call	L112, 0
	call	L113, 1

	// variable assignment status

	// function call start
	call	L114, 0

	pop	fp[0]

	// if statement

	// push variable status
	push	fp[0]

	// push constant
	push	1
	neg
	compEQ
	j0	L237
	jmp	L236
L237:

	// if statement

	// push variable @isstdgui
	push	sb[6]

	// push constant
	push	1
	compEQ
	j0	L238

	// Output

	// push normal string

	// push constant
	push	"New game? <y/n>"
	puts
L238:

	// Input
	getc

	// get to variable newgame
	pop	fp[1]

	// while loop
L239:

	// push variable newgame
	push	fp[1]

	// push constant
	push	'
'
	compEQ

	// push variable newgame
	push	fp[1]

	// push constant
	push	'y'
	compNE

	// push variable newgame
	push	fp[1]

	// push constant
	push	'n'
	compNE
	and
	or
	j0	L240

	// Input
	getc

	// get to variable newgame
	pop	fp[1]
	jmp	L239
L240:

	// Input
	getc

	// get to variable nl
	pop	fp[2]

	// if statement

	// push variable @isstdgui
	push	sb[6]

	// push constant
	push	0
	compEQ
	j0	L241

	// Output

	// push constant
	push	'*'
	putc_

	// Output

	// push variable newgame
	push	fp[1]
	putc_
L241:
	jmp	L235
L236:

	// if statement

	// push variable @isstdgui
	push	sb[6]

	// push constant
	push	1
	compEQ
	j0	L242

	// Output

	// push normal string

	// push constant
	push	"Have a nice day!"
	puts
	jmp	L243
L242:

	// Output

	// push constant
	push	'q'
	putc_
L243:
	ret
