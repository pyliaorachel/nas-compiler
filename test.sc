c = 100;

hello () {
	c = 30;
	return @c;
}

d = hello();

oh() {
	@d = 100;
}

puti(d);