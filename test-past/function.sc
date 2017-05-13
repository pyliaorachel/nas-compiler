fibonacci(n); // any function appears in main() must be declared or defined before main()

max(a,b){
	if(a>b)
		return a;
	else
		return b;
}

main(){
	geti(x);
	geti(y);
	a=fibonacci(x);
	b=fibonacci(y);
	puti(a);
	puti(b);
	puti("%d is larger.\n", max(a,b));
}

fibonacci(n){ // the parameter must match that declared
	x=1;
	y=1;
	for (i=2; i<=n; i=i+1;)
	{
		z=x;
		x=y;
		y=x+z;
	}
	return y;
}