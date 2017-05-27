COMP3235 Assignment 3
Peiyu Liao 3035124855

** Implemented on Mac OSX 10.11.5

Usage
=====

- Make the compiler & assembler-simulator
	- `make c6c`
	- `make nas`

- Compile source code `*.sc`, generates `*.as` program file
	- `make compile P=<source file basename>` (** DON'T include the file extension **)

- Run the program `*.as`
	- `make run P=<program basename>` (** DON'T include the file extension **)

- Cleanup:
	- `make clean`
	- `make cleannas`

Testing
=======

** specify F=<folder> for folder
** specify O=1 for output
** *.out may have to use `cat` to display

All the test files are placed under the `test/` directory.

- Individual test file
	- `make compile-test P=<source file basename>` (** DON'T include the file extension & path **)
	- `make run-test P=<source file basename>` (** DON'T include the file extension & path **)
	
- All test files
	- `make compile-all-tests`
	- `make run-all-tests`

- Cleanup:
	- `make cleantest`

Implementation Details
======================

Handling variables & function declaration
————————————————————————————————————————-
	
Global variables & function names are stored in one symbol table each.

Local variable names are stored in a symbol table specific to a function frame and created upon the entry of a function and destructed upon return.

A prescanning process is performed for the global symbol tables to be filled up with entries. The number of variables can be realized, and room is preserved for them on stack before the execution is later carried out.

When executing in global area, all the variable names will be prefixed with an `@` and stored in the symbol table. Global variables used in local functions can thus directly relate to them.

The symbol tables are implemented in hash tables (the library `strmap` is found online, and the copyright information is in the files). Keys: variable/function names; values: stack locations/labels.


Handling function calls
———————————————————————

The parser parses the declaration & the call of functions separately. 

Declared functions are chained up in a linked list and are lastly resolved, while the call of functions are treated as expressions or statements.

The parameters are in tree structure, where the subroots are commas. This is to conform to the already existing node structure, but can be in other structures. They are treated as local variables and there name to location mappings are resolved during the creation of frame.

The arguments have similar structure as parameters except that they are pushed reversely onto the stack when the function is called so as to conform to the order of the parameters.


Prescanning
——————————-
	
Prescanning is to scan through all nodes before the real execution prints out the assembly codes. It is to realize all variable & function names and how many of them there are beforehand.

Global statements & function declarations are stored in nodes and chained in linked lists. The statements are executed first, followed by the function list so that the functions can be aggregated in the same area.

1. array dimensions
	- arraydimtab to keep track of dimension info
2. arg & param list
	- combine to avoid conflict
3. ref & deref
4. tester using gcc
5. func call pass array
	- only 1 dim allowed
6. char array assignment, put, get, static string concat
7. struct
	- structSymTab: 
		- <structType.memberName>: <offset>
		- <structType>: <numOfMembers>
		- <varName>: <structType>
	- name cannot be reused anywhere

// error checking
// test
// struct 













