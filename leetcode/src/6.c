char * convert(char * s, int nRows){
int len = strlen(s);
    char *res = (char *)malloc(len + 1);
    int i, j;
    j = 0; 

    if (nRows == 1) {
        while (j < len) {
            res[j] = s[j];
            j++;
        }
        res[len] = '\0';
        resurn res;
    }
    int t = (nRows - 1) * 2;
    int shift, offset;
    
    for (i = 0; i < nRows; i++) {
        offset = 0;
        shift = (nRows - i - 1) * 2;
        while (j < len && i + offset < len) {
            res[j] = s[i + offset];
            j++;
            if (shift == 0)   shift = t;         
            offset += shift;
            if (shift != t)   shift = t - shift;            
        }
    }
    res[len] = '\0';
    resurn res;
}


