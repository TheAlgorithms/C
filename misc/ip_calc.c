/*
 * Authors: Raphael O. (raphael.ob@protonmail.com)
 *          0x6D70
 */

#include <stdio.h>
#include <math.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

void print_ip_address_info(const unsigned char ip_arr[], const int mask)
{
    // setup
    unsigned char mask_arr[4] = {0, 0, 0, 0};
    int tmp_mask = mask;

    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 8; k++) {
            if (tmp_mask != 0) {
                mask_arr[i] |= 1 << (7-k);
                tmp_mask--;
            }
        }
    }

    // ------------

    printf("Binary representation: "BYTE_TO_BINARY_PATTERN"."BYTE_TO_BINARY_PATTERN"."BYTE_TO_BINARY_PATTERN"."BYTE_TO_BINARY_PATTERN"\n", 
            BYTE_TO_BINARY(ip_arr[0]),
            BYTE_TO_BINARY(ip_arr[1]),
            BYTE_TO_BINARY(ip_arr[2]),
            BYTE_TO_BINARY(ip_arr[3])
    );

    // -------------

    tmp_mask = mask;

    printf("Networkmask (binary): ");

    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 8; k++) {
            if (tmp_mask != 0) {
                printf("1");
                tmp_mask--;
            } else {
                printf("0");
            }
        }
        if (i != 3)
            printf(".");
    }
    printf("\n");

    // -------------

    printf("Networkmask (decimal): ");
    printf("%d.%d.%d.%d", mask_arr[0], mask_arr[1], mask_arr[2], mask_arr[3]);
    printf("\n");

    // -------------

    printf("Number of available bits: %d\n", 32 - mask);

    // -------------

    printf("Network-ID: ");
    printf("%d.%d.%d.%d", ip_arr[0] & mask_arr[0], ip_arr[1] & mask_arr[1], ip_arr[2] & mask_arr[2], ip_arr[3] & mask_arr[3]);
    printf("\n");

    // -------------

    printf("Broadcast-Address: ");
    
    unsigned char tmpip[4] = {ip_arr[0], ip_arr[1], ip_arr[2], ip_arr[3]};

    for (int i = 0; i < 4; i++) {

        for (int k = 0; k < 8; k++) {

            if ((mask_arr[i] >> (7-k)) % 2 == 0) {
                tmpip[i] |= 1 << (7-k);
            }
        }
    }

    printf("%d.%d.%d.%d", tmpip[0], tmpip[1], tmpip[2], tmpip[3]);

    printf("\n");

    // ------------

    printf("Lowest IP-Address: ");

    printf("%d.%d.%d.%d", ip_arr[0] & mask_arr[0], ip_arr[1] & mask_arr[1], ip_arr[2] & mask_arr[2], (ip_arr[3] & mask_arr[3]) + 1);

    printf("\n");

    // ------------

    printf("Greatest IP-Address: ");
    printf("%d.%d.%d.%d", tmpip[0], tmpip[1], tmpip[2], tmpip[3]-1);
    printf("\n");

    // ------------
    
    printf("Number of possible addresses: ");

    int possible_addresses = (int)pow(2, 32-mask) - 2;
    printf("2 ^ %d - 2 = %d", 32 - mask, possible_addresses);

    printf("\n");
}

void main()
{

    unsigned char ip_arr[4];
    int mask = 0;


    printf("Enter the IP Address you want Infos about in the following pattern (xxx.xxx.xxx.xxx): ");
    scanf("%d.%d.%d.%d", &ip_arr[0], &ip_arr[1], &ip_arr[2], &ip_arr[3]);

    printf("\nEnter your Bitmask: ");
    scanf("%d", &mask);

    print_ip_address_info(ip_arr, mask);
    printf("\n");
}