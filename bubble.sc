for (k = 0; k < 10; k = k + 1;) {
    read a[k];
}
for (k = 0; k < 10; k = k + 1;) {
    y = 0;

    for (l = 0; l < (10 - k - 1); l = l + 1;) {
        if (a[l] > a[l+1]) {
            y = 1;

            z = a[l];
            a[l] = a[l+1];
            a[l+1] = z;
        }
    }
    if (y == 0) break;
}
for (k = 0; k < 10; k = k + 1;) {
    print a[k];
}