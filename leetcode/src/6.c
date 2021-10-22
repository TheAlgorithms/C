/**
 * @file 6.c
 * @brief ZigZag Conversion leetcode problem solution.
 * @details
 * A decent solution to the ZigZag conversion problem.
 * Take advantage of the fact that the maximum gap between the chars is 2 times
 * the depth(the number of rows).
 * The actual gap between the two first chars of a rows depends on the depth of
 * the row. The gaps between successives chars on the same row is the complement
 * of the first gap to the maximum gap.
 * @author [straight_into_the_wall](https://github.com/straight-into-the-wall)
 * @see https://leetcode.com/problems/zigzag-conversion/
 */

#include <assert.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Convert a string to the it's zigzag equivalent on a given number of
 * rows.
 * @param in the string in input.
 * @param numRows the desired number of rows.
 * @returns the converted new (malloced) string.
 */
char* convert(char* in, int numRows)
{
    int len = strlen(in);

    if (len < numRows)
    {
        numRows = len;
    }
    char* out = calloc(len + 1, sizeof(char));

    if (numRows < 2)
    {
        memcpy(out, in, len + 1);
        return out;
    }

    int max = numRows - 1;
    int rr = 2 * max;
    int i = 0;
    int o = 0;
    int delta = 0;

    // first row
    while (i < len)
    {
        out[o++] = in[i];
        i += rr;
    }

    // middle rows
    for (int l = 1; l < max; l++)
    {
        i = l;
        delta = 2 * l;
        while (i < len)
        {
            out[o++] = in[i];
            delta = rr - delta;
            i += delta;
        }
    }

    // last row
    i = max;
    while (i < len)
    {
        out[o++] = in[i];
        i += rr;
    }

    return out;
}

/**
 * @brief Self-test implementations
 * @returns void
 */
void testZigZag(char* s, int numRows, char* expected)
{
    char* ret = convert(s, numRows);
    int len = strlen(s);
    int cmp = strncmp(ret, expected, len);
    assert(!cmp);

    free(ret);
}

void test(void)
{
    char* s01 = "PAYPALISHIRING";

    char* r01 = "PINALSIGYAHRPI";
    testZigZag(s01, 4, r01);

    char* r02 = "PAHNAPLSIIGYIR";
    testZigZag(s01, 3, r02);

    char* s03 = "A";
    testZigZag(s03, 1, s03);
    testZigZag(s03, 3, s03);

    char* s04 =
        "cbxdwjccgtdoqiscyspqzvuqivzptlpvooynyapgvswoaosaghrffnxnjyeeltzaiznicc"
        "ozwknwyhzgpqlwfkjqipuu"
        "jvwtxlbznryjdohbvghmyuiggtyqjtmuqinntqmihntkddnalwnmsxsatqqeldacnnpjfe"
        "rmrnyuqnwbjjpdjhdeavkn"
        "ykpoxhxclqqedqavdwzoiorrwwxyrhlsrdgqkduvtmzzczufvtvfioygkvedervvudnegh"
        "bctcbxdxezrzgbpfhzanff"
        "eccbgqfmzjqtlrsppxqiywjobspefujlxnmddurddiyobqfspvcoulcvdrzkmkwlyiqdch"
        "ghrgytzdnobqcvdeqjystm"
        "epxcaniewqmoxkjwpymqorluxedvywhcoghotpusfgiestckrpaigocfufbubiyrrffmwa"
        "eeimidfnnzcphkflpbqsvt"
        "dwludsgaungfzoihbxifoprwcjzsdxngtacw";

    char* r04 =
        "cbxdwjccgtdoqiscyspqzvuqivzptlpvooynyapgvswoaosaghrffnxnjyeeltzaiznicc"
        "ozwknwyhzgpqlwfkjqipuu"
        "jvwtxlbznryjdohbvghmyuiggtyqjtmuqinntqmihntkddnalwnmsxsatqqeldacnnpjfe"
        "rmrnyuqnwbjjpdjhdeavkn"
        "ykpoxhxclqqedqavdwzoiorrwwxyrhlsrdgqkduvtmzzczufvtvfioygkvedervvudnegh"
        "bctcbxdxezrzgbpfhzanff"
        "eccbgqfmzjqtlrsppxqiywjobspefujlxnmddurddiyobqfspvcoulcvdrzkmkwlyiqdch"
        "ghrgytzdnobqcvdeqjystm"
        "epxcaniewqmoxkjwpymqorluxedvywhcoghotpusfgiestckrpaigocfufbubiyrrffmwa"
        "eeimidfnnzwccpahtkgfnl"
        "xpdbsqzsjvctwdrwploufdisxgbahuinogzf";

    testZigZag(s04, 472, r04);
}
