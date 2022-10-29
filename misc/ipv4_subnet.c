#include <assert.h>
#include <stdio.h>
/**
 * @file
 * @brief
 * [Explanation](https://www.softwaretestinghelp.com/subnet-mask-and-network-classes/)
 * @author [XenoxJeager] (https://github.com/XenoxJeager)
 * @details
 * Getting subnetmasks of ipv4(32 bit long) addresses based on the length(0-32)
 * of the network bits.
 *
 */

/**
 * @brief Definition of union ipv4_address composed of an unsigned int ipv4 and
 * a four byte long char[] subnetmask.
 */
typedef union
{
    unsigned int ipv4;
    unsigned char subnetmask[4];
} ipv4_address;

/**
 * @brief Calculates the subnetmask with networkbits via bit-shifting and
 * |-operator
 * @param networkbit_len lenght of the network_bits, ranging from 0 (no
 * networkbits set) to 32 (all networkbits set)
 * @return ipv4_address union with the subnetmask in the ipv4_address.subnetmask
 */
ipv4_address calculate_subnet(unsigned int networkbit_len)
{
    ipv4_address ipv4_add;
    ipv4_add.ipv4 = 0;

    for (int i = 0; i < networkbit_len; i++)
    {
        ipv4_add.ipv4 |= 1 << 31 - i;
    }

    return ipv4_add;
}
/**
 * @brief test method
 *
 */
static void test()
{
    ipv4_address ipv4;
    ipv4 = calculate_subnet(8);
    printf("subnetmask: %u.%u.%u.%u \n", ipv4.subnetmask[3], ipv4.subnetmask[2],
           ipv4.subnetmask[1], ipv4.subnetmask[0]);
    assert(ipv4.ipv4 == 4278190080);
}

int main()
{
    test();
    return 1;
}
