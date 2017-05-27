// basic array: declaration, initialization, offset arithmetics, assignment

array a[4] = 78, b[4] = 87;

for (i = 0; i < 4; i = i + 1;) {
	puti_(a[i]); puts_(" should be equal to "); puti(78);
	puti_(a[i] + b[i]); puts_(" should be equal to "); puti(78 + 87);
	a[i] = b[i] + 100;
}

for (i = 1; i < 5; i = i + 1;) {
	puti_(a[i-1]); puts_(" should be equal to "); puti(87 + 100);
}