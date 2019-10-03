int hammingWeight(uint32_t n) {
    int TotalBits = 32;
    int i, weight = 0;
    for(i = 0; i < TotalBits; i++) {
        if((n & (UINT32_C(1) << i)) >> i)
            weight += 1;
    }
    return weight;
}