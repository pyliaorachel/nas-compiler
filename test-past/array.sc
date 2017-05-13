main()
{
	array test1[10][10]=90, test2[10]=100; // array declaration and initialization
	puts_("test1:\n");
	for (i=0; i<10; i=i+1;)
		for (j=0; j<10; j=j+1;)
			puti(test1[i][j]);
			
	puts_("test2:\n");
	for (i=0; i<10; i=i+1;)
		puti(test2[i]);

	for (i=0; i<10; i=i+1;)
		for (j=0; j<10; j=j+1;)
			test1[i][j]=i+j;
			
	puts("========");
	for (i=0; i<10; i=i+1;)
		for (j=0; j<10; j=j+1;){
			puti(i);
			puti(j);
			puti(test1[i][j]);
			puts("========");
		}
}