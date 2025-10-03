/**
 * @file
 * @brief [Gale-Shapley
 * Algorithm](https://en.wikipedia.org/wiki/Gale%E2%80%93Shapley_algorithm):
 * Stable matching between two sets.
 * @details
 * This implementation uses the Gale-Shapley algorithm to find stable matches
 * between two equally sized sets, given their preferences.
 *
 * **Gale Shapley Algorithm** aims to find a stable matching between two equally
 * sized sets of elements given an ordinal preference for each element. The
 * algorithm was introduced by David Gale and Lloyd Shapley in 1962.
 *
 * Reference:
 *   - [Wikipedia](https://en.wikipedia.org/wiki/Gale%E2%80%93Shapley_algorithm)
 *   - [Stable matching
 * problem](https://en.wikipedia.org/wiki/Stable_matching_problem)
 *   - [Original
 * Paper](https://sites.math.washington.edu/~billey/classes/562.winter.2018/articles/Gale.Shapley.pdf)
 *
 * Math: Stable matching means no pair prefers each other over their current
 * match.
 *
 * @author [Mastermind-sap](https://github.com/Mastermind-sap)
 */

#include <assert.h>  /// for assert
#include <stdio.h>   /// for IO operations

#define N 4  // number of proposers and acceptors

/**
 * @brief Find the index of value in an array
 * @param arr array to search
 * @param size length of array
 * @param val value to find
 * @return index of value if found, -1 otherwise
 */
int index_of(int arr[], int size, int val)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == val)
            return i;
    }
    return -1;
}

/**
 * @brief Initialize matches and free status
 * @param matches array to store final matches
 * @param is_free_proposer array to check which proposer free
 * @param proposal_index array to keep track of next index to propose for each
 * proposer
 * @returns void
 */
void initialize(int matches[], int is_free_proposer[], int proposal_index[])
{
    for (int i = 0; i < N; i++)
    {
        matches[i] = -1;          // all acceptors unmatched
        is_free_proposer[i] = 1;  // all proposers are free
        proposal_index[i] = 0;    // start from first preference
    }
}

/**
 * @brief Find the next free proposer
 * @param is_free_proposer array to check which proposer is free
 * @returns index of free proposer or -1 if none free
 */
int get_free_proposer(int is_free_proposer[])
{
    for (int i = 0; i < N; i++)
    {
        if (is_free_proposer[i])
            return i;
    }
    return -1;
}

/**
 * @brief Gale–Shapley stable matching algorithm
 * @param proposer_pref preferences of proposers
 * @param acceptor_pref preferences of acceptors
 * @param matches output: matches[j] = i means acceptor j is matched with
 * proposer i
 * @returns void
 */
void gale_shapley(int proposer_pref[N][N], int acceptor_pref[N][N],
                  int matches[])
{
    int is_free_proposer[N];
    int proposal_index[N];
    initialize(matches, is_free_proposer, proposal_index);

    while (1)
    {
        int p = get_free_proposer(is_free_proposer);  // free proposer
        if (p == -1)
            break;  // no free proposer left

        int s = proposer_pref[p][proposal_index[p]];  // acceptor to propose
        proposal_index[p]++;

        int current_match = matches[s];

        if (current_match == -1)
        {
            // acceptor is free
            matches[s] = p;
            is_free_proposer[p] = 0;
        }
        else
        {
            // acceptor already matched, check preference
            int rank_new = index_of(acceptor_pref[s], N, p);
            int rank_current = index_of(acceptor_pref[s], N, current_match);

            if (rank_new < rank_current)
            {
                // acceptor prefers new proposer
                matches[s] = p;
                is_free_proposer[p] = 0;
                is_free_proposer[current_match] = 1;  // old match becomes free
            }
        }
    }
}

/**
 * @brief Print final matches
 * @param matches output: matches[j] = i means acceptor j is matched with
 * proposer i
 */
void print_matches(int matches[])
{
    printf("Stable Matching Results:\n");
    for (int s = 0; s < N; s++)
    {
        printf("acceptor %d is matched with proposer %d\n", s, matches[s]);
    }
}

/**
 * @brief Self-test for Gale-Shapley implementation
 * @returns void
 */
static void test()
{
    // Test case 1:
    int proposer_pref1[N][N] = {
        {1, 0, 2, 3}, {2, 1, 3, 0}, {2, 1, 0, 3}, {3, 0, 1, 2}};
    int acceptor_pref1[N][N] = {
        {1, 0, 2, 3}, {3, 0, 1, 2}, {0, 2, 1, 3}, {1, 2, 0, 3}};
    int matches1[N];
    gale_shapley(proposer_pref1, acceptor_pref1, matches1);
    int expected1[N] = {3, 0, 2, 1};
    for (int i = 0; i < N; i++)
    {
        assert(matches1[i] == expected1[i]);
    }

    // Test case 2:
    int proposer_pref2[N][N] = {
        {0, 1, 2, 3}, {0, 1, 2, 3}, {0, 1, 2, 3}, {0, 1, 2, 3}};
    int acceptor_pref2[N][N] = {
        {0, 1, 2, 3}, {1, 0, 2, 3}, {2, 1, 0, 3}, {3, 2, 1, 0}};
    int matches2[N];
    gale_shapley(proposer_pref2, acceptor_pref2, matches2);
    int expected2[N] = {0, 1, 2, 3};
    for (int i = 0; i < N; i++)
    {
        assert(matches2[i] == expected2[i]);
    }

    // Test case 3:
    int proposer_pref3[N][N] = {
        {3, 2, 1, 0}, {3, 2, 1, 0}, {3, 2, 1, 0}, {3, 2, 1, 0}};
    int acceptor_pref3[N][N] = {
        {3, 2, 1, 0}, {2, 3, 1, 0}, {1, 2, 3, 0}, {0, 1, 2, 3}};
    int matches3[N];
    gale_shapley(proposer_pref3, acceptor_pref3, matches3);
    int expected3[N] = {3, 2, 1, 0};
    for (int i = 0; i < N; i++)
    {
        assert(matches3[i] == expected3[i]);
    }

    printf("All Gale-Shapley tests have successfully passed!\n");
}

/**
 * @brief Main function with test case
 * @returns 0 on exit
 */
int main()
{
    test();  // Run Gale-Shapley self-test
    return 0;
}