int hammingDistance(int x, int y){
    int difference = x ^ y;         //The XOR operator generates the bitwise difference in the binary representation of two numbers
                                    //If bit in ith position of both numbers is same, bit in difference is 0, otherwise 1
    int TotalBits = sizeof(difference)*8;   //total number of bits
    int i, distance = 0;
    for(i = 0; i < TotalBits; i++) {
        if(difference & (UINT32_C(1) << i)) //if the bit on the ith position of 32 bit input is 1, then proceed
                                            //Further note the use of UINT32_C to convert 1 to unsigned 32 bit int, as just 1 is treated as int which cannot be shifted left more than 30 times
            distance += 1;
    }   
    return distance;
}