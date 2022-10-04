/**
 * @file
 * @author [serturx](https://github.com/serturx)
 * @brief This is a C implementation of the [greedy coin change
 * algorithm](https://en.wikipedia.org/wiki/Change-making_problem)
 * @details This algorithm computes the needed coins from a given set of coins
 * that make up a given amount. It works greedy, so it chooses the biggest
 * possible coin that fits in the remaining amount until the remaining sum is
 * <=0.
 */

#include <stdlib.h>  /// for qsort
#include <stdbool.h> /// for bool type
#include <string.h> /// for memcmp
#include <assert.h> /// for assert
#include <stdio.h> /// for printf

/**
 * @brief A struct containing the result of the coin change algorithm.
 * It consists of the length of the result and the result itself (as an integer array)
 * 
 */
typedef struct {
    size_t result_length;
    int *result;
} coin_change;

/**
 * @brief Compare function for qsort to for qsort to sort in decreasing order
 *
 * @param a Element A
 * @param b Element B
 * @return Difference of a and b
 */
int compare_reverse(const void *a, const void *b) {
    int *x = (int *)a;
    int *y = (int *)b;
    return *y - *x;
}

bool is_set(int *array, size_t size) {
    bool duplicate = false;

    for (int i = 0; i < size - 1; ++i) {
        if(array[i] == array[i + 1]) {
            duplicate = true;
            break;
        }
    }

    return !duplicate;
}

/**
 * @brief Implementation of the greedy coin change algorithm
 *
 * @param amount Amount to compute the coin change for
 * @param coin_set An array consisting of distinct integer values denoting
 * a set of coins to compute the amount with
 * @return coin_change* A pointer to acoin_change struct consisting of
 * the results length and an array of integers making
 * up the given amount in coin change or null if not
 * possible (with greedy approach)
 */
coin_change *compute_coins(int amount, int coin_set[], size_t coin_set_length) {
    qsort(coin_set, coin_set_length, sizeof(*coin_set),
          compare_reverse);
    if(!is_set(coin_set, coin_set_length))
        return NULL;

    size_t current_size = 1;
    size_t size_used = 0;

    int *coins = malloc(current_size * sizeof(int));

    bool coin_fit = false;

    while(amount > 0) {
        coin_fit = false;
        for (int i = 0; i < coin_set_length; ++i) {
            int current_coin = coin_set[i];
            if(current_coin <= amount) {
                if(current_size >= size_used) {
                    current_size += 10;
                    if(!(coins = realloc(coins, current_size))) {
                        free(coins);
                        exit(1);
                    }
                }

                coins[size_used] = current_coin;
                ++size_used;

                amount -= current_coin;
                coin_fit = true;
                break;
            }
        }

        if(!coin_fit) {
            free(coins);
            return NULL;
        }
    }

    coin_change *result = malloc(sizeof(coin_change));
    result->result_length = size_used;
    result->result = coins;

    return result;
}

void test() {
    int *result;

    int test_set_1[] = {1, 2, 5, 10, 20, 50};
    int expected_result_1[] = {20, 10, 2, 2};
    coin_change* result_1 = compute_coins(34, test_set_1, 6);
    assert(result_1->result_length == 4);
    assert(!memcmp(expected_result_1, result_1->result, sizeof(int) * 4));
    free(result_1->result);
    free(result_1);

    int test_set_2[] = {2, 4, 6};
    coin_change *result_2 = compute_coins(23, test_set_2, 3);
    assert(result_2 == NULL);

    int test_set_3[] = {2, 6, 5};
    int expected_result_3[] = {6, 2, 2};
    coin_change *result_3 = compute_coins(10, test_set_3, 3);
    assert(result_3->result_length == 3);
    assert(!memcmp(expected_result_3, result_3->result, sizeof(int) * 3));
    free(result_3->result);
    free(result_3);

    int test_set_4[] = {200, 100, 150, 1, 50};
    int expected_result_4[] = {100, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1,   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    coin_change *result_4 = compute_coins(130, test_set_4, 5);
    assert(result_4->result_length == 31);
    assert(!memcmp(expected_result_4, result_4->result, sizeof(int) * 31));
    free(result_4->result);
    free(result_4);

    printf("All tests have passed!");
}

int main() {
    test();
}
