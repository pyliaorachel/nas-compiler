c = 0;

hello (a, b) {
	@c = 2;
	b = 1;
	return a + b + @c;
}

d = hello(hello(1, 2), 5);
puti(d);