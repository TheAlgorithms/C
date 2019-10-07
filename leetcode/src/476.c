int findComplement(int num) {
    int TotalBits = 0;
    int temp = num;
    while(temp) {               //To find position of MSB in given num. Since num is represented as a standard size in memory, we cannot rely on size
                                //for that information.
        TotalBits++;            //increment TotalBits till temp becomes 0
        temp >>= 1;             //shift temp right by 1 bit every iteration; temp loses 1 bit to underflow every iteration till it becomes 0
    }
    int i, flipNumber = 1;      //Eg: 1's complement of 101(binary) can be found as 101^111 (XOR with 111 flips all bits that are 1 to 0 and flips 0 to 1)
    for(i = 1; i < TotalBits; i++) {
        flipNumber += UINT32_C(1) << i; //Note the use of unsigned int to facilitate left shift more than 31 times, if needed
    }
    num = num^flipNumber;
    return num;
}