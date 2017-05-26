array a[100][2] = 4;
a[3][1] = 5;
b = 5;

puti(&b);
puti(&a[3][1]);
puti(*(a[1] + b));