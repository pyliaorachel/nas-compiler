main()
{
array x[3][3], y[4][4][4];
c = 'a';
for (i = 0; i < 3; i = i + 1;) {
    for (q = x[i]; q < x[i] + 3; q = q + 1;) {
        puti(q);
        *q = c;
        c = c + 1;
    }
}
for (i = 0; i < 3; i = i + 1;) {
    for (j = 0; j < 3; j = j + 1;) {
        putc_(x[i][j]);
    }
    putc_('\n');
}
puti((&x[0])[1]);
putc((&x[0])[1][0]);
for (a = 0; a < 4; a = a + 1;) {
    for (b = 0; b < 4; b = b + 1;) {
        for (c = 0; c < 4; c = c + 1;) {
            puti(&y[a][b][c]);
        }
    }
}
}
