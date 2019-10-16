/* 
 * brute force approach
 * time complexity: O(mn)
 */
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

/* ---------------------------------------------------------------------------------------- */

/*
 * KMP algorithm
 * time complexity: O(m + n)
 */

/* fills overlap with longest proper prefix which is also suffix for each index in needle */
void fill_overlap(char *needle, int len_needle, int *overlap)
{
    int len = 0;
    int i = 0;

    overlap[0] = 0;

    for (i = 1; i < len_needle;) {
        if (needle[i] == needle[len]) {
            len++;
            overlap[i++] = len;
        } else {
            if (len)
                len = overlap[len - 1];
            else
                overlap[i++] = 0;
        }
    }
}

int strStr(char *haystack, char *needle)
{
    int i = 0; /* index for haystack */
    int j = 0; /* index for needle */

    int len_needle = strlen(needle);
    int len_haystack = strlen(haystack);

    if (!len_needle)
        return 0;

    int overlap[len_needle];

    fill_overlap(needle, len_needle, overlap);

    while (i < len_haystack) {
        if (needle[j] == haystack[i]) {
            i++;
            j++;
        }

        if (j == len_needle) {
            return (i - j);
        } else if (i < len_haystack && needle[j] != haystack[i]) {
            if (j != 0)
                j = overlap[j - 1];
            else
                i = i + 1;
        }
    }
    return -1;
}

/* ---------------------------------------------------------------------------------------- */

