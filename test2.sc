struct s1 {
	id, num, hello
};

struct s2 {
	id, num, hello, nihao, lalala
};

<s1> a[10][10];

for (i = 0; i < 10; i = i + 1;) {
	for (j = 0; j < 10; j = j + 1;) {
		a[i][j].id = i * 10 + j;
		a[i][j].num = i + j;
		puts_("id: "); puti(a[i][j].id);
		puts_("num: "); puti(a[i][j].num);
	}
}

for (i = 0; i < 10; i = i + 1;) {
	for (j = 0; j < 10; j = j + 1;) {
		puts_("id: "); puti(a[i][j].id);
		puts_("num: "); puti(a[i][j].num);
	}
}

pr(a[0][0].id);

pr(b) {
	puti(b);
}

struct s1 {
	id, num, hello
};

struct s2 {
	id, num, hello, nihao, lalala
};

<s1> a[3][3];

for (i = 0; i < 3; i = i + 1;) {
	for (j = 0; j < 3; j = j + 1;) {
		a[i][j].id = i * 10 + j;
		a[i][j].num = i + j;
		puts_("id: "); puti(a[i][j].id);
		puts_("num: "); puti(a[i][j].num);
	}
}

for (i = 0; i < 3; i = i + 1;) {
	for (j = 0; j < 3; j = j + 1;) {
		puts_("id: "); puti(a[i][j].id);
		puts_("num: "); puti(a[i][j].num);
	}
}
