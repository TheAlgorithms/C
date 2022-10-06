#define max(i, j) (((i) > (j)) ? (i) : (j))

int candy(int* ratings, int ratingsSize){
    int res[ratingsSize];
    for (int i=0; i<ratingsSize; i++) res[i]=1;
    int *r = ratings;
    
    for (int i=1; i<ratingsSize; i++) {
        if (r[i] > r[i-1])
            res[i] = max(res[i-1]+1,res[i]);
    }
    
    for (int i=ratingsSize-2; i>=0; i--) {
        if (r[i] > r[i+1])
            res[i] = max(res[i+1]+1,res[i]);
    }
    
    int acc = 0;
    for (int i=0; i<ratingsSize; i++) {
        acc += res[i];
    }
    return acc;
}
