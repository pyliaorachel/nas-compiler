COMP3235 Assignment 4
Peiyu Liao 3035124855

** Implemented on Mac OSX 10.11.5 **

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
|                          Compiler                              |
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Quick Start
-----------

`make c6c`  
`make compile-all-tests F=a4`  
`make run-all-tests F=a4 O=1`

Usage
-----

** DON'T include the file extension for P **

- Make the compiler & assembler-simulator
	- `make c6c`
	- `make nas`

- Compile source code `*.sc`, generates `*.as` program file
	- `make compile P=<source file basename>`

- Run the program `*.as`
	- `make run P=<program basename>`

- Cleanup
	- `make clean`
	- `make cleannas`

Testing
-------

Test files are placed under the `test-<F>/` directory.

** DON'T include the leading ‘test-’ for F **
** DON'T include the file extension & path for P **

- Individual test file
	- `make compile-test F=<test folder subname> P=<source file basename>`
	- `make run-test F=<test folder subname> P=<source file basename>`
	
- All test files
	- `make compile-all-tests F=<test folder subname>`
	- `make run-all-tests F=<test folder subname> O=<1 if output to *.out>` 

- Cleanup
	- `make cleantest F=<test folder subname>`


++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
|                     Project - Minesweeper                      |
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

An 8x8 implementation of the popular Minesweeper PC game. (Wiki: https://en.wikipedia.org/wiki/Minesweeper_(video_game))  

All the files are under `/Minesweeper`.  

`Minesweeper.sc` is the source code for the underlying game engine.  
`MinesweeperWin.c` is the source code for the game GUI engine using the ** ncurses ** library; please make sure it is installed under your environment.  
A demo video is available in the folder.  

Usage
-----

`cd Minesweeper`  

- Run the game under GUI mode
	- `make` (game engine)
	- `make MinesweeperWin` (GUI engine)
	- `make run`

- Run the game under stdin mode
	- Open `Minesweeper.sc` source file, search for definition of global variable `isStdGUI`, set it to 1
	- `make` (game engine)
	- `make run-std`

Instructions
------------

- Upon start of the game, enter a valid number for generating a psuedo-random board
- The instruction sets will be shown on the window; make sure you press ** Enter ** to actually send the input command to the game engine, including commands for moving the cursor
- Enter `q` to quit at any time ** EXCEPT when the game engine is still asking for a random number **; enter a valid number and then enter `q` to quit
- Of course you can use `Ctrl-C` to exit at any time (or when there is bug...)


++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
|                           New Features                         |
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

New Features
------------

+ Array implementation
	+ Multidimentional array
	+ I/O
	+ Pass to function
	+ Char array as string, read until '\0'
	- No VLA (variable length array) support
	- No function passing support for pointers pointing to array > 1 dimension
	- Variable names should be unique throughout the program
+ Reference & Dereference Symbols
	+ `b = &a; *b = 5;` same as `a = 5;`
	+ `array a[10]; *(a + 5) = 5;` same as `a[5] = 5;`
+ Static string concatenation
	+ "Hello" + "world" => "Helloworld"
+ Operators <<, >>, ^, & | support
+ Struct implementation
	+ Array
	- No function passing
	- Variable names should be unique throughout the program


++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
|                    Implementation Details                      |
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Array implementation
--------------------

An array dimension table is used to bookkeep the dimension information of each array. A hash table same as the one used for symbol tables is used, where the <key, value> mapping is string to string:

	"array_base_name" -> "unit_size|dim_count|dim1,dim2,...,dimn"

The unit size is normally 1 for arrays except for structs, which is useful for calculating the address for array elements. Dimension count is, of course, how many dimensions there are. The respective array width of each dimension follow.

For I/O and array assignments, the helper functions `isArrayPtr` and `pushPtr` are helpful. 

`isArrayPtr` checks if a variable/array name is actually an array pointer or an array element by refering to the array dimension table mentioned above; if they are recorded as an array but the dimension count is less than that in the table, then they are probably array pointers.

`pushPtr` pushes the address to stack, with all the offset issues handled. It refers to the array dimension table and push the mul/add instructions accordingly.

Passing array pointers to functions is restricted to dimension size of at most 1, i.e. for `a[5][5][5]`, only `a[0][0]` or `a[0][0][0]` can be pushed as arguments but not `a[0]` or `a`. This is because for higher dimensions, we need to know exactly the width of each dimensions to do the offset calculation; but since we didn't support typing in funciton parameters, we have no idea which array is passed into the function. The feature can be made possible if the parameter consists of array size information, e.g. `func(a[][10])`.

Character arrays are implemented with a loop to push the characters one by one until a value of <= 0 is encountered. Note that strings are stored as character arrays only if they are assigned to array pointers; if a string is assigned to a specific array slot, it is stored as a reference to that string, and won't be combined with its preceding/succeeding character arrays.

Reference & Dereference Symbols
-------------------------------

Simply choose between pushing/poping values/pointers onto the stack.

Static string concatenation
---------------------------

Concatenation is done in the lexical parser when ** str + str ** is reduced to ** expression **.

New operators support
-----------------

<< (arithmetic shift left), >> (arithmetic shift right), ^ (logical xor), & (logical and), and | (logical or) are supported. Simply modify the nas engine, and also add them to our compiler for recognition.

Struct implementation
---------------------

Struct syntax is as follows:
	struct struct_type { member1, member2, membern }; // define before use
	<struct_type> s1, s2[10]; // either declare as variable or array

All the struct definitions will be executed first and information kept in a struct symbol table. The entries include:
	
	"struct_type.member_name": "offset" // the nth member of the struct
	"struct_type": "number_of_members"
	"variable_name": 'struct_type'

When using struct arrays, the unit size will equal to the number of members in the struct. Then structs can be treated the same as primitive types when pushing their pointers.

A struct is easily recognized with the '.' operator. The two sides will be sent to evaluate their associations by refering to the struct symbol table, and their addresses can be deduced as if they were simply some small fix-sized arrays.

Function passing is difficult if not impossible if the types of the parameters are not specified - you don't know which struct type the variable is referring to.

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
|                          Project Details                       |
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Minesweeper is a game for finding where the mines/bombs might be according to the information shown by the neighbors. In our simple version of Minesweeper, board size is fixed to 8x8 with 8 bombs. Players either reveal a slot or mark a slot as bomb; each revealed slot displays how many neighboring bombs it has. If a bomb is accidentally revealed, the player loses; if all bombs are correctly identified, the player wins.

- What code features are mainly included?

Since the game is a board, and each cell contains some information, e.g. is it a bomb, how many neighboring bombs, is it opened, etc., using a struct array is a perfect fit. Also, the cursor information is stored in another struct.

An interesting feature is the pseudo-random board generator. The algorithm is found online; since most random algorithms need the shift and logical operators, they are added to nas. Before the game begins, the users need to choose an odd number between 1 - 99 to serve as the seed number, and 8 random numbers within the range 0-63 will be generated and divided into x and y. Hence currently around 50 different boards are available, but the range of the seed number can be increased to allow more board configurations if needed.

- How is the game implemented with GUI?

The GUI engine is written in C, and the `ncurses` library is used to control the terminal. The output of the game engine will be of some commands to be piped to the GUI engine for reading, and the GUI engine will handle the display upon instruction.

A nasty thing is that when the terminal is under window mode, both the stdin input from the game engine and the cursor input from the terminal window will be read by `getch()`. Since we can't send commands back from the GUI to the game engine, we want to discard the input from the terminal window. To differentiate between them, the commands send by the game engine is prepended with a '*' so that the GUI engine will be ready to receive useful commands.

Another thing is that the output of the game engine must be flushed from the buffer in runtime, or else the GUI engine will not receive anything until the game engine ends and print things out.










