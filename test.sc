c = 0;

hello (a, b) {
	@c = 2;
	b = 1;
	puti(a + b + @c);
}

d = hello(1, 2);