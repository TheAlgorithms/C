/**
 * @file
 * @brief [Patience Sort](https://en.wikipedia.org/wiki/Patience_sorting)
 * @details From Wikipedia:
 * In computer science, patience sorting is a sorting algorithm inspired by, and named after, the card game patience.
 * Given an array of n elements from some totally ordered domain, consider this array as a collection of cards and simulate the patience sorting game.
 * When the game is over, recover the sorted sequence by repeatedly picking off the minimum visible card;
 * in other words, perform a k-way merge of the p piles, each of which is internally sorted.
 * @author [CascadingCascade](https://github.com/CascadingCascade)
 */

#include <assert.h> /// for assertions
#include <stdio.h> /// for IO operations
#include <stdlib.h> /// for memory management

/**
 * @brief Sorts the target array by dividing it into a variable number of internally sorted piles then merge the piles
 * @param array pointer to the array to be sorted
 * @param length length of the target array
 * @returns void
 */
void patienceSort(int *array, int length) {
    // An array of pointers used to store each pile
    int* *piles = (int* *) malloc(sizeof(int*) * length);
    for (int i = 0; i < length; ++i) {
        piles[i] = malloc(sizeof(int) * length);
    }

    // pileSizes keep track of the indices of each pile's topmost element, hence 0 means only one element
    // Note how calloc() is used to initialize the sizes of all piles to zero
    int *pileSizes = (int*) calloc(length,sizeof(int));

    // This initializes the first pile, note how using an array of pointers allowed us to access elements through two subscripts
    // The first subscript indicates which pile we are accessing, the second subscript indicates the location being accessed in that pile
    piles[0][0] = array[0];
    int pileCount = 1;

    for (int i = 1; i < length; ++i) {
        // This will be used to keep track whether an element has been added to an existing pile
        int flag = 1;

        for (int j = 0; j < pileCount; ++j) {
            if(piles[j][pileSizes[j]] > array[i]) {
                // We have found a pile this element can be added to
                piles[j][pileSizes[j] + 1] = array[i];
                pileSizes[j]++;
                flag--;
                break;
            }
        }

        if(flag) {
            // The element in question can not be added to any existing piles, creating a new pile
            piles[pileCount][0] = array[i];
            pileCount++;
        }
    }

    // This will keep track of the minimum value of all 'exposed' elements and which pile that value is from
    int min, minLocation;

    for (int i = 0; i < length; ++i) {
        // Since there's no guarantee the first pile will be depleted slower than other piles,
        // Example: when all elements are equal, in that case the first pile will be depleted immediately
        // We can't simply initialize min to the top most element of the first pile,
        // this loop finds a value to initialize min to.
        for (int j = 0; j < pileCount; ++j) {
            if(pileSizes[j] < 0) {
                continue;
            }
            min = piles[j][pileSizes[j]];
            minLocation = j;
            break;
        }

        for (int j = 0; j < pileCount; ++j) {
            if(pileSizes[j] < 0) {
                continue;
            }
            if(piles[j][pileSizes[j]] < min) {
                min = piles[j][pileSizes[j]];
                minLocation = j;
            }
        }

        array[i] = min;
        pileSizes[minLocation]--;
    }

    // Deallocate memory
    free(pileSizes);
    for (int i = 0; i < length; ++i) {
        free(piles[i]);
    }
    free(piles);
}

/**
 * @brief Helper function to print an array
 * @param array pointer to the array
 * @param length length of the target array
 * @returns void
 */
void printArray(int *array,int length) {
    printf("Array:");
    for (int i = 0; i < length; ++i) {
        printf("%d",array[i]);
        if (i != length - 1) putchar(',');
    }
    putchar('\n');
}

/**
 * @brief Testing Helper function
 * @param array pointer to the array to be used for testing
 * @param length length of the target array
 * @returns void
 */

void testArray(int *array,int length) {
    printf("Before sorting:\n");
    printArray(array,length);

    patienceSort(array,length);

    printf("After sorting:\n");
    printArray(array,length);

    for (int i = 0; i < length - 1; ++i) {
        assert(array[i] <= array[i + 1]);
    }
    printf("All assertions have passed!\n\n");
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
    int testArray1[] = {2,8,7,1,3,5,6,4};
    int testArray2[] = {2,2,5,1,3,5,6,4};
    int testArray3[] = {1,2,3,4,5,6,7,8};
    int testArray4[] = {8,7,6,5,4,3,2,1};

    testArray(testArray1,8);
    testArray(testArray2,8);
    testArray(testArray3,8);
    testArray(testArray4,8);

    printf("Testing successfully completed!\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test();  // run self-test implementations
    return 0;
}
