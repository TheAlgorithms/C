int hammingDistance(int x, int y){
    int difference = x ^ y;
    int TotalBits = sizeof(difference)*8;
    int i, distance = 0;
    for(i = 0; i < TotalBits; i++) {
        if(difference & (UINT32_C(1) << i))
            distance += 1;
    }   
    return distance;
}
