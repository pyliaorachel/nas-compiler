// struct array: declaration, assignment, evaluation, I/O

struct student {
	firstName, lastName
};

<student> s[2][2];

for (i = 0; i < 2; i = i + 1;) {
	for (j = 0; j < 2; j = j + 1;) {
		puts_("Class "); puti_(i + 1); puts_(" Student "); puti_(j + 1); puts(": ");
		puts_("First name: "); gets(s[i][j].firstName);
		puts_("Last name: "); gets(s[i][j].lastName);
	}
}

for (i = 0; i < 2; i = i + 1;) {
	for (j = 0; j < 2; j = j + 1;) {
		puts_("Class "); puti_(i + 1); puts_(" Student "); puti_(j + 1); puts(": ");
		puts_(s[i][j].firstName); puts_(" "); puts(s[i][j].lastName);
	}
}