array a[4][4][4] = 4;

a[1][0][0] = 500;

hello(a[1]);

hello(b) {
	puti(b[0][0]);
	b[0][0] = b[0][0] - 1;
}

hello(a[1]);
hello(a[1]);