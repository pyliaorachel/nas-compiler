	// jump to main function unconditionally
	jmp	L000
	// count allocated with size 1
	// count2 allocated with size 1
	// player1 allocated with size 5
	// player2 allocated with size 5
	// size1 allocated with size 1
	// size2 allocated with size 1
	// broad allocated with size 9
	// garbage allocated with size 1
	// mark1 allocated with size 1
	// mark2 allocated with size 1
	// draw allocated with size 1
	// s allocated with size 9
	// bound allocated with size 1
	// x allocated with size 1
	// y allocated with size 1
	// function "main"
L000:
	// allocate space
	push	sp
	push	39
	add
	pop	sp

	// constant
	push	0
	// global identifier count
	push	sb
	pop	ac
	push	ac
	push	0
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	0
	// global identifier count2
	push	sb
	pop	ac
	push	ac
	push	1
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	0
	// initialise player1
	push	sp[-1]
	pop	fp[2]
	push	sp[-1]
	pop	fp[3]
	push	sp[-1]
	pop	fp[4]
	push	sp[-1]
	pop	fp[5]
	push	sp[-1]
	pop	fp[6]
	pop	ac
	// constant
	push	0
	// initialise player2
	push	sp[-1]
	pop	fp[7]
	push	sp[-1]
	pop	fp[8]
	push	sp[-1]
	pop	fp[9]
	push	sp[-1]
	pop	fp[10]
	push	sp[-1]
	pop	fp[11]
	pop	ac
	// constant
	push	0
	// global identifier size1
	push	sb
	pop	ac
	push	ac
	push	12
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	0
	// global identifier size2
	push	sb
	pop	ac
	push	ac
	push	13
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	0
	// initialise broad
	push	sp[-1]
	pop	fp[14]
	push	sp[-1]
	pop	fp[15]
	push	sp[-1]
	pop	fp[16]
	push	sp[-1]
	pop	fp[17]
	push	sp[-1]
	pop	fp[18]
	push	sp[-1]
	pop	fp[19]
	push	sp[-1]
	pop	fp[20]
	push	sp[-1]
	pop	fp[21]
	push	sp[-1]
	pop	fp[22]
	pop	ac
	// constant
	push	1
	// UMINUS
	neg
	// global identifier garbage
	push	sb
	pop	ac
	push	ac
	push	23
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	0
	// global identifier mark1
	push	sb
	pop	ac
	push	ac
	push	24
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	0
	// global identifier mark2
	push	sb
	pop	ac
	push	ac
	push	25
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	1
	// global identifier draw
	push	sb
	pop	ac
	push	ac
	push	26
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	0
	// initialise s
	push	sp[-1]
	pop	fp[27]
	push	sp[-1]
	pop	fp[28]
	push	sp[-1]
	pop	fp[29]
	push	sp[-1]
	pop	fp[30]
	push	sp[-1]
	pop	fp[31]
	push	sp[-1]
	pop	fp[32]
	push	sp[-1]
	pop	fp[33]
	push	sp[-1]
	pop	fp[34]
	push	sp[-1]
	pop	fp[35]
	pop	ac
	// constant
	push	8
	// global identifier s
	push	sb
	pop	ac
	push	ac
	push	27
	add
	// array-to-pointer
	// constant
	push	0
	// [
	push	3
	mul
	add
	// array-to-pointer
	// constant
	push	0
	// [
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	1
	// global identifier s
	push	sb
	pop	ac
	push	ac
	push	27
	add
	// array-to-pointer
	// constant
	push	0
	// [
	push	3
	mul
	add
	// array-to-pointer
	// constant
	push	1
	// [
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	6
	// global identifier s
	push	sb
	pop	ac
	push	ac
	push	27
	add
	// array-to-pointer
	// constant
	push	0
	// [
	push	3
	mul
	add
	// array-to-pointer
	// constant
	push	2
	// [
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	3
	// global identifier s
	push	sb
	pop	ac
	push	ac
	push	27
	add
	// array-to-pointer
	// constant
	push	1
	// [
	push	3
	mul
	add
	// array-to-pointer
	// constant
	push	0
	// [
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	5
	// global identifier s
	push	sb
	pop	ac
	push	ac
	push	27
	add
	// array-to-pointer
	// constant
	push	1
	// [
	push	3
	mul
	add
	// array-to-pointer
	// constant
	push	1
	// [
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	7
	// global identifier s
	push	sb
	pop	ac
	push	ac
	push	27
	add
	// array-to-pointer
	// constant
	push	1
	// [
	push	3
	mul
	add
	// array-to-pointer
	// constant
	push	2
	// [
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	4
	// global identifier s
	push	sb
	pop	ac
	push	ac
	push	27
	add
	// array-to-pointer
	// constant
	push	2
	// [
	push	3
	mul
	add
	// array-to-pointer
	// constant
	push	0
	// [
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	9
	// global identifier s
	push	sb
	pop	ac
	push	ac
	push	27
	add
	// array-to-pointer
	// constant
	push	2
	// [
	push	3
	mul
	add
	// array-to-pointer
	// constant
	push	1
	// [
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	2
	// global identifier s
	push	sb
	pop	ac
	push	ac
	push	27
	add
	// array-to-pointer
	// constant
	push	2
	// [
	push	3
	mul
	add
	// array-to-pointer
	// constant
	push	2
	// [
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// literal
	push	"=============="
	// global identifier bound
	push	sb
	pop	ac
	push	ac
	push	36
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// BEGIN DO
L004:
	// function call "createBroad"
	call	L002, 0
	// global identifier garbage
	push	sb
	pop	ac
	push	ac
	push	23
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// BEGIN WHILE
L007:
	// global identifier count2
	push	sb
	pop	ac
	push	ac
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	9
	// arithmetic
	compLT
	// WHILE BODY
	j0	L008
	// literal
	push	"Player1 - O"
	// OUTPUT
	puts
	// BEGIN DO
L009:
	// global identifier x
	push	sb
	pop	ac
	push	ac
	push	37
	add
	// INPUT
	pop	ac
	geti
	pop	ac[0]
L010:
	// DO TEST
	// global identifier broad
	push	sb
	pop	ac
	push	ac
	push	14
	add
	// array-to-pointer
	// global identifier x
	push	sb
	pop	ac
	push	ac
	push	37
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// arithmetic
	add
	// constant
	push	1
	// arithmetic
	sub
	// PTR
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	0
	// arithmetic
	compNE
	j1	L009
L011:
	// DO END
	// global identifier s
	push	sb
	pop	ac
	push	ac
	push	27
	add
	// array-to-pointer
	// global identifier x
	push	sb
	pop	ac
	push	ac
	push	37
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// arithmetic
	add
	// constant
	push	1
	// arithmetic
	sub
	// PTR
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// global identifier player1
	push	sb
	pop	ac
	push	ac
	push	2
	add
	// array-to-pointer
	// global identifier count
	push	sb
	pop	ac
	push	ac
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	1
	// global identifier broad
	push	sb
	pop	ac
	push	ac
	push	14
	add
	// array-to-pointer
	// global identifier x
	push	sb
	pop	ac
	push	ac
	push	37
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// arithmetic
	add
	// constant
	push	1
	// arithmetic
	sub
	// PTR
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// function call "createBroad"
	call	L002, 0
	// global identifier garbage
	push	sb
	pop	ac
	push	ac
	push	23
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// global identifier count2
	push	sb
	pop	ac
	push	ac
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// global identifier count2
	push	sb
	pop	ac
	push	ac
	push	1
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// BEGIN IF
	// constant
	push	1
	// function call "subsetSum"
	call	L001, 1
	// constant
	push	15
	// arithmetic
	compEQ
	j0	L012
	// THEN
	// literal
	push	"Player 1 wins!"
	// OUTPUT
	puts
	// global identifier mark1
	push	sb
	pop	ac
	push	ac
	push	24
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// global identifier mark1
	push	sb
	pop	ac
	push	ac
	push	24
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	0
	// global identifier draw
	push	sb
	pop	ac
	push	ac
	push	26
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// BREAK
	jmp	L008
L012:
	// END IF
	// global identifier size1
	push	sb
	pop	ac
	push	ac
	push	12
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// global identifier size1
	push	sb
	pop	ac
	push	ac
	push	12
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// BEGIN IF
	// global identifier count2
	push	sb
	pop	ac
	push	ac
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	9
	// arithmetic
	compGE
	j0	L013
	// THEN
	// BREAK
	jmp	L008
L013:
	// END IF
	// literal
	push	"Player2 - X"
	// OUTPUT
	puts
	// BEGIN DO
L014:
	// global identifier x
	push	sb
	pop	ac
	push	ac
	push	37
	add
	// INPUT
	pop	ac
	geti
	pop	ac[0]
L015:
	// DO TEST
	// global identifier broad
	push	sb
	pop	ac
	push	ac
	push	14
	add
	// array-to-pointer
	// global identifier x
	push	sb
	pop	ac
	push	ac
	push	37
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// arithmetic
	add
	// constant
	push	1
	// arithmetic
	sub
	// PTR
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	0
	// arithmetic
	compNE
	j1	L014
L016:
	// DO END
	// global identifier s
	push	sb
	pop	ac
	push	ac
	push	27
	add
	// array-to-pointer
	// global identifier x
	push	sb
	pop	ac
	push	ac
	push	37
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// arithmetic
	add
	// constant
	push	1
	// arithmetic
	sub
	// PTR
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// global identifier player2
	push	sb
	pop	ac
	push	ac
	push	7
	add
	// array-to-pointer
	// global identifier count
	push	sb
	pop	ac
	push	ac
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	2
	// global identifier broad
	push	sb
	pop	ac
	push	ac
	push	14
	add
	// array-to-pointer
	// global identifier x
	push	sb
	pop	ac
	push	ac
	push	37
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// arithmetic
	add
	// constant
	push	1
	// arithmetic
	sub
	// PTR
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// function call "createBroad"
	call	L002, 0
	// global identifier garbage
	push	sb
	pop	ac
	push	ac
	push	23
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// global identifier count2
	push	sb
	pop	ac
	push	ac
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// global identifier count2
	push	sb
	pop	ac
	push	ac
	push	1
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// BEGIN IF
	// constant
	push	2
	// function call "subsetSum"
	call	L001, 1
	// constant
	push	15
	// arithmetic
	compEQ
	j0	L017
	// THEN
	// literal
	push	"Player 2 wins!"
	// OUTPUT
	puts
	// global identifier mark2
	push	sb
	pop	ac
	push	ac
	push	25
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// global identifier mark2
	push	sb
	pop	ac
	push	ac
	push	25
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	0
	// global identifier draw
	push	sb
	pop	ac
	push	ac
	push	26
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// BREAK
	jmp	L008
L017:
	// END IF
	// global identifier size2
	push	sb
	pop	ac
	push	ac
	push	13
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// global identifier size2
	push	sb
	pop	ac
	push	ac
	push	13
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// global identifier count
	push	sb
	pop	ac
	push	ac
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// global identifier count
	push	sb
	pop	ac
	push	ac
	push	0
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L007
L008:
	// WHILE END
	// BEGIN IF
	// global identifier draw
	push	sb
	pop	ac
	push	ac
	push	26
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	compEQ
	j0	L018
	// THEN
	// literal
	push	"Draw!"
	// OUTPUT
	puts
L018:
	// END IF
	// global identifier mark1
	push	sb
	pop	ac
	push	ac
	push	24
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// OUTPUT
	puti	"Player1: %d"
	// global identifier mark2
	push	sb
	pop	ac
	push	ac
	push	25
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// OUTPUT
	puti	"  vs  Player2: %d\n"
	// literal
	push	"One more round?(1=yes)"
	// OUTPUT
	puts
	// global identifier y
	push	sb
	pop	ac
	push	ac
	push	38
	add
	// INPUT
	pop	ac
	geti
	pop	ac[0]
	// function call "init"
	call	L003, 0
	// global identifier garbage
	push	sb
	pop	ac
	push	ac
	push	23
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

L005:
	// DO TEST
	// global identifier y
	push	sb
	pop	ac
	push	ac
	push	38
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	compEQ
	j1	L004
L006:
	// DO END
	end
	// c allocated with size 1
	// i allocated with size 1
	// j allocated with size 1
	// function "createBroad"
L002:
	// allocate space
	push	sp
	push	3
	add
	pop	sp

	// constant
	push	1
	// identifier c
	push	fp
	push	0
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// BEGIN FOR
	// constant
	push	0
	// identifier i
	push	fp
	push	1
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L019:
	// identifier i
	push	fp
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	3
	// arithmetic
	compLT
	j0	L020
	// FOR BODY
	// global identifier bound
	push	sb
	pop	ac
	push	ac
	push	36
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// OUTPUT
	puts
	// literal
	push	"|"
	// OUTPUT
	puts_
	// BEGIN FOR
	// constant
	push	0
	// identifier j
	push	fp
	push	2
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L022:
	// identifier j
	push	fp
	push	2
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	3
	// arithmetic
	compLT
	j0	L023
	// FOR BODY
	// BEGIN IF
	// global identifier broad
	push	sb
	pop	ac
	push	ac
	push	14
	add
	// array-to-pointer
	// identifier i
	push	fp
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	push	3
	mul
	add
	// array-to-pointer
	// identifier j
	push	fp
	push	2
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	0
	// arithmetic
	compEQ
	j0	L025
	// THEN
	// identifier c
	push	fp
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// OUTPUT
	puti	" %d "
L025:
	// END IF
	// BEGIN IF
	// global identifier broad
	push	sb
	pop	ac
	push	ac
	push	14
	add
	// array-to-pointer
	// identifier i
	push	fp
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	push	3
	mul
	add
	// array-to-pointer
	// identifier j
	push	fp
	push	2
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	compEQ
	j0	L026
	// THEN
	// literal
	push	" O "
	// OUTPUT
	puts_
L026:
	// END IF
	// BEGIN IF
	// global identifier broad
	push	sb
	pop	ac
	push	ac
	push	14
	add
	// array-to-pointer
	// identifier i
	push	fp
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	push	3
	mul
	add
	// array-to-pointer
	// identifier j
	push	fp
	push	2
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	2
	// arithmetic
	compEQ
	j0	L027
	// THEN
	// literal
	push	" X "
	// OUTPUT
	puts_
L027:
	// END IF
	// literal
	push	"|"
	// OUTPUT
	puts_
	// identifier c
	push	fp
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// identifier c
	push	fp
	push	0
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

L024:
	// FOR INCREMENT
	// identifier j
	push	fp
	push	2
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// identifier j
	push	fp
	push	2
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L022
L023:
	// END FOR
	// literal
	push	"\n"
	// OUTPUT
	puts_
L021:
	// FOR INCREMENT
	// identifier i
	push	fp
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// identifier i
	push	fp
	push	1
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L019
L020:
	// END FOR
	// global identifier bound
	push	sb
	pop	ac
	push	ac
	push	36
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// OUTPUT
	puts
	// constant
	push	1
	// UMINUS
	neg
	ret
	// i allocated with size 1
	// j allocated with size 1
	// function "subsetSum"
L001:
	// allocate space
	push	sp
	push	2
	add
	pop	sp

	// BEGIN IF
	// identifier player
	push	fp
	push	-4
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	compEQ
	j0	L028
	// THEN
	// BEGIN IF
	// global identifier size1
	push	sb
	pop	ac
	push	ac
	push	12
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	2
	// arithmetic
	compGE
	j0	L029
	// THEN
	// BEGIN FOR
	// global identifier size1
	push	sb
	pop	ac
	push	ac
	push	12
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	sub
	// identifier i
	push	fp
	push	0
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L030:
	// identifier i
	push	fp
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	0
	// arithmetic
	compGE
	j0	L031
	// FOR BODY
	// BEGIN FOR
	// identifier i
	push	fp
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	sub
	// identifier j
	push	fp
	push	1
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L033:
	// identifier j
	push	fp
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	0
	// arithmetic
	compGE
	j0	L034
	// FOR BODY
	// BEGIN IF
	// global identifier player1
	push	sb
	pop	ac
	push	ac
	push	2
	add
	// array-to-pointer
	// identifier i
	push	fp
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// global identifier player1
	push	sb
	pop	ac
	push	ac
	push	2
	add
	// array-to-pointer
	// identifier j
	push	fp
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// arithmetic
	add
	// global identifier player1
	push	sb
	pop	ac
	push	ac
	push	2
	add
	// array-to-pointer
	// global identifier size1
	push	sb
	pop	ac
	push	ac
	push	12
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// arithmetic
	add
	// constant
	push	15
	// arithmetic
	compEQ
	j0	L036
	// THEN
	// constant
	push	15
	ret
L036:
	// END IF
L035:
	// FOR INCREMENT
	// identifier j
	push	fp
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	sub
	// identifier j
	push	fp
	push	1
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L033
L034:
	// END FOR
L032:
	// FOR INCREMENT
	// identifier i
	push	fp
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	sub
	// identifier i
	push	fp
	push	0
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L030
L031:
	// END FOR
L029:
	// END IF
L028:
	// END IF
	// BEGIN IF
	// identifier player
	push	fp
	push	-4
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	2
	// arithmetic
	compEQ
	j0	L037
	// THEN
	// BEGIN IF
	// global identifier size2
	push	sb
	pop	ac
	push	ac
	push	13
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	2
	// arithmetic
	compGE
	j0	L038
	// THEN
	// BEGIN FOR
	// global identifier size2
	push	sb
	pop	ac
	push	ac
	push	13
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	sub
	// identifier i
	push	fp
	push	0
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L039:
	// identifier i
	push	fp
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	0
	// arithmetic
	compGE
	j0	L040
	// FOR BODY
	// BEGIN FOR
	// identifier i
	push	fp
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	sub
	// identifier j
	push	fp
	push	1
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L042:
	// identifier j
	push	fp
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	0
	// arithmetic
	compGE
	j0	L043
	// FOR BODY
	// BEGIN IF
	// global identifier player2
	push	sb
	pop	ac
	push	ac
	push	7
	add
	// array-to-pointer
	// identifier i
	push	fp
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// global identifier player2
	push	sb
	pop	ac
	push	ac
	push	7
	add
	// array-to-pointer
	// identifier j
	push	fp
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// arithmetic
	add
	// global identifier player2
	push	sb
	pop	ac
	push	ac
	push	7
	add
	// array-to-pointer
	// global identifier size2
	push	sb
	pop	ac
	push	ac
	push	13
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// arithmetic
	add
	// constant
	push	15
	// arithmetic
	compEQ
	j0	L045
	// THEN
	// constant
	push	15
	ret
L045:
	// END IF
L044:
	// FOR INCREMENT
	// identifier j
	push	fp
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	sub
	// identifier j
	push	fp
	push	1
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L042
L043:
	// END FOR
L041:
	// FOR INCREMENT
	// identifier i
	push	fp
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	sub
	// identifier i
	push	fp
	push	0
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L039
L040:
	// END FOR
L038:
	// END IF
L037:
	// END IF
	// constant
	push	1
	// UMINUS
	neg
	ret
	// i allocated with size 1
	// j allocated with size 1
	// function "init"
L003:
	// allocate space
	push	sp
	push	2
	add
	pop	sp

	// constant
	push	0
	// global identifier count
	push	sb
	pop	ac
	push	ac
	push	0
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	0
	// global identifier count2
	push	sb
	pop	ac
	push	ac
	push	1
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// BEGIN FOR
	// constant
	push	0
	// identifier i
	push	fp
	push	0
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L046:
	// identifier i
	push	fp
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	5
	// arithmetic
	compLT
	j0	L047
	// FOR BODY
	// constant
	push	0
	// global identifier player1
	push	sb
	pop	ac
	push	ac
	push	2
	add
	// array-to-pointer
	// identifier i
	push	fp
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	0
	// global identifier player2
	push	sb
	pop	ac
	push	ac
	push	7
	add
	// array-to-pointer
	// identifier i
	push	fp
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

L048:
	// FOR INCREMENT
	// identifier i
	push	fp
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// identifier i
	push	fp
	push	0
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L046
L047:
	// END FOR
	// constant
	push	0
	// global identifier size1
	push	sb
	pop	ac
	push	ac
	push	12
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	0
	// global identifier size2
	push	sb
	pop	ac
	push	ac
	push	13
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// BEGIN FOR
	// constant
	push	0
	// identifier i
	push	fp
	push	0
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L049:
	// identifier i
	push	fp
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	3
	// arithmetic
	compLT
	j0	L050
	// FOR BODY
	// BEGIN FOR
	// constant
	push	0
	// identifier j
	push	fp
	push	1
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// FOR TEST
L052:
	// identifier j
	push	fp
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	3
	// arithmetic
	compLT
	j0	L053
	// FOR BODY
	// constant
	push	0
	// global identifier broad
	push	sb
	pop	ac
	push	ac
	push	14
	add
	// array-to-pointer
	// identifier i
	push	fp
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	push	3
	mul
	add
	// array-to-pointer
	// identifier j
	push	fp
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// [
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

L054:
	// FOR INCREMENT
	// identifier j
	push	fp
	push	1
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// identifier j
	push	fp
	push	1
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L052
L053:
	// END FOR
L051:
	// FOR INCREMENT
	// identifier i
	push	fp
	push	0
	add
	// lvalue-to-rvalue
	pop	ac
	push	ac[0]
	// constant
	push	1
	// arithmetic
	add
	// identifier i
	push	fp
	push	0
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	jmp	L049
L050:
	// END FOR
	// constant
	push	1
	// global identifier draw
	push	sb
	pop	ac
	push	ac
	push	26
	add
	// =
	pop	ac
	pop	ac[0]
	push	ac
	pop	ac

	// constant
	push	1
	// UMINUS
	neg
	ret
