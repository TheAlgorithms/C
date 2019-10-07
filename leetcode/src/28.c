int strStr(char* haystack, char* needle) {
    int i = 0;
    int j = 0;
    int k = 0;
    int hlen = 0;
    int nlen = 0;
    
    if(needle == NULL || *needle == 0)
        return 0;
    
    if(haystack == NULL || *haystack == 0)
        return -1;
    
    hlen = strlen(haystack);
    nlen = strlen(needle);
    
    if(hlen < nlen)
        return -1;
    
    for(i = 0; i <= hlen - nlen; i++) {  
        j = 0;
        if(haystack[i] != needle[j++])
            continue;
        
        k = i + 1;
        for(; j < nlen; j++) {
            if(haystack[k] != needle[j]) {
                break;
            } else
                k++;
        }
        if(j == nlen)
            return i;
    }
    return -1;
}

