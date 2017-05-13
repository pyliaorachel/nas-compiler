main(){
	array x[100][100], y[100];
	geti(n, m);
	for (i = 0; i < n; i = i + 1;) {
	    for (j = 0; j < m; j = j + 1;) {
	        geti(x[i][j]);
	    }
	}
	for (i = 0; i < n; i = i + 1;) {
	    for (j = 0; j < m; j = j + 1;) {
	        puti_(x[i][j]);
	        putc_(' ');
	    }
	    putc_('\n');
	}
}