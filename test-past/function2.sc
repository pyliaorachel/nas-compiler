double();

main(){ 
	garbage=-1;
	array test[5][5]=2;
	for(i=0; i<5; i=i+1;)
		for(j=0; j<5; j=j+1;)
			puti("%d ", test[i][j]);
	puts_("\n");
	garbage=double();  //since the system is typeless, it requires a garbage to collect any unwanted return value
	puts("after function double():");
	for(i=0; i<5; i=i+1;)
		for(j=0; j<5; j=j+1;)
			puti("%d ", test[i][j]);
	puts_("\n");
}

double(){
	for(i=0; i<5; i=i+1;)
		for(j=0; j<5; j=j+1;)
			@test[i][j]=@test[i][j]*2;
	return -1;
}

// main() is treated as global scope, all variables defined here are treated as global variables which can be accessed in other scopes (i.e. function) by keyword '@'
// P.S. statement out of any function scope is not allowed