// basic array: declaration, initialization, offset arithmetics, assignment

array a[4] = 78, b[4] = 87;

for (i = 0; i < 4; i = i + 1;) {
	puti(a[i]);
	puti(a[i] + b[i]);
	a[i] = b[i] + 100;
}

for (i = 1; i < 5; i = i + 1;) {
	puti(a[i-1]);
}