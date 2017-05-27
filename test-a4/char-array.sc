// char array: consecutive characters within an array treated as string, I/O support

array a[2][100];

for (i = 'a'; i <= 'z'; i = i + 1;) {
	a[0][i - 'a'] = i;
	a[1][i - 'a'] = i - 'a' + 'A';
}

a[0]['z' - 'a' + 1] = '\0';
a[1]['z' - 'a' + 1] = '\0';

puts_("lower case alphabet: "); puts(a[0]);
puts_("UPPER CASE ALPHABET: "); puts(a[1]);

puts_("enter a string: "); gets(a[0]);
puts_("you entered: "); puts(a[0]);

puts_("enter another string: "); gets(a[1]);
puts_("you entered: "); puts(a[1]);