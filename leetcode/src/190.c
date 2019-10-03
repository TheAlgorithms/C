uint32_t reverseBits(uint32_t n) {
    uint TotalBits = 32;
    uint32_t reverse_int = 0;
    uint i;
    for(i = 0; i < TotalBits; i++) {
        if((n & (UINT32_C(1) << i)))
           reverse_int = reverse_int | (UINT32_C(1) << (TotalBits - 1 - i));
    }
    return reverse_int;
}