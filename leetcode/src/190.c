uint32_t reverseBits(uint32_t n)
{
    uint TotalBits = 32;
    uint32_t reverse_int = 0;  // stored in memory as 32 bits, each bit valued 0
    uint i;
    for (i = 0; i < TotalBits; i++)
    {
        if ((n & (UINT32_C(1)
                  << i)))  // if the bit on the ith position of 32 bit input is
                           // 1, then proceed Further note the use of UINT32_C
                           // to convert 1 to unsigned 32 bit int, since just 1
                           // is treated as int which cannot be shifted left
                           // more than 30 times
            reverse_int =
                reverse_int |
                (UINT32_C(1)
                 << (TotalBits - 1 -
                     i));  // Convert the ith bit from the end in reverse_int
                           // from 0 to 1, if ith bit from beginning in n is 1
                           // This is achieved by using bitwise OR on
                           // reverse_int (where ith bit from end is currently
                           // 0) and 1 shifted left 31 - i bits (to ith bit from
                           // the end)
    }
    return reverse_int;
}