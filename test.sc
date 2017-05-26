array a[1000];

for (i = 0; i < 26; i = i + 1;) {
	a[i] = i + 'a';
}

a[26] = '\0';
puts(a);