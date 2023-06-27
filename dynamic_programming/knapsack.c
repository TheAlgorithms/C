/**
 * @file
 * @brief
 * [0-1_Knapsack](https://en.wikipedia.org/wiki/Knapsack_problem#0-1_knapsack_problem) implementation
 * @details
 * From Wikipedia : The knapsack problem is
 * Given a set of items, each with a weight and a value, determine
 * which items to include in the collection
 * so that the total weight is less than or equal to a given limit 
 * and the total value is as large as possible.
 * @author [aa001R](https://github.com/aa001R)
 */

#include <assert.h>  /// for assert
#include <stdio.h>

/**
 * @brief max() macro function
 */
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

/**
 * @brief Maximum capacity of the knapsack
 */
#define MAXCAPACITY 10

/**
 * @brief Item structure
 */
struct Item
{
    int weight;  // weight
    int value;   // value
};

/**
 * @brief Print input items function
 * @param items an array of Item structure
 * @param itemCount the number of items(Item structure)
 * @returns void
 */
void print_input_struct_Items(struct Item items[], int itemCount);
/**
 * @brief Print the combination of items in the knapsack
 * @param maxWeight the capacity of the knapsack
 * @param items an array of Item structure
 * @param itemCount the number of items(Item structure)
 * @param K the 2D array storing the optimal solution
 * @returns void
 */
void print_knapsack_item(int maxWeight, struct Item items[], int itemCount,
                         int K[][MAXCAPACITY + 1]);

/**
 * @brief 0-1 Knapsack algorithm
 * @param maxWeight the capacity of the knapsack
 * @param items an array of Item structure
 * @param itemCount the number of items(Item structure)
 * @returns the maximum value that can be obtained
 */
int knapsack(int maxWeight, struct Item items[], int itemCount)
{
    // Print input items
    print_input_struct_Items(items, itemCount);

    // 2D array to store the optimal solution of subproblems
    int K[itemCount + 1][maxWeight + 1];

    // Initialize the first row and column to 0
    for (int i = 0; i <= itemCount; i++) K[i][0] = 0;
    for (int j = 0; j <= maxWeight; j++) K[0][j] = 0;

    // Calculate the optimal solution by selecting items one by one
    for (int i = 1; i <= itemCount; i++)
    {
        for (int w = 1; w <= maxWeight; w++)
        {
            if (items[i - 1].weight <= w)
            {  // If the i-th item can be included in the knapsack
                int valueWithPick =
                    items[i - 1].value +
                    K[i - 1][w - items[i - 1].weight];  // Value if the i-th
                                                        // item is selected
                int valueWithoutPick =
                    K[i - 1][w];  // Value if the i-th item is not selected
                K[i][w] = MAX(valueWithPick,
                              valueWithoutPick);  // Select the maximum value
            }
            else
            {  // If the i-th item cannot be included in the knapsack
                K[i][w] = K[i - 1][w];
            }
        }
    }

    // Print the result of the Knapsack algorithm
    printf("Knapsack execution result:\n");
    for (int i = 0; i < itemCount + 1; i++)
    {
        for (int j = 0; j < maxWeight + 1; j++)
        {
            printf("%2d ", K[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Print the maximum value of the knapsack
    printf("Maximum Value: %d\n", K[itemCount][maxWeight]);
    // Print the combination of items in the knapsack
    print_knapsack_item(maxWeight, items, itemCount, K);
    return K[itemCount][maxWeight];
}

/**
 * @brief Print input items
 * @param items an array of Item structure
 * @param itemCount the number of items(Item structure)
 * @returns void
 */
void print_input_struct_Items(struct Item items[], int itemCount)
{
    printf("Input Item Structures:\n");
    for (int i = 0; i < itemCount; i++)
    {
        printf("Item %d (Weight: %d, Value: %d)\n", i + 1, items[i].weight,
               items[i].value);
    }
    printf("\n");
}
/**

 * @brief Print the combination of items in the knapsack
 * @param maxWeight the capacity of the knapsack
 * @param items an array of Item structure
 * @param itemCount the number of items(Item structure)
 * @param K the 2D array storing the optimal solution
 * @returns void
 */
void print_knapsack_item(int maxWeight, struct Item items[], int itemCount,
                         int K[][MAXCAPACITY + 1])
{
    // Backtracking from the final maximum value to track the value changes
    int i = itemCount;  // Number of items (maximum to 0)
    int w = maxWeight;  // Temporary capacity of the knapsack (maximum to 0)
    printf("Items in the knapsack:\n");
    while (i > 0 && w > 0)
    {
        // Check if the i-th item is selected
        if (K[i][w] != K[i - 1][w])
        {
            /* If K[i][j] != K[i-1][j], it means the i-th item is included at
             * the previous (w-items[i-1].weight) weight. */
            printf("Item %d (Weight: %d, Value: %d)\n", i, items[i - 1].weight,
                   items[i - 1].value);
            w = w - items[i - 1].weight;  // Move to the weight excluding the
                                          // i-th item from now on
        }
        /* If K[i][w] == K[i-1][maxWeight], it means the i-th item is not
         * included in the knapsack: w remains the same. */
        i--;
    }
}

static void test()
{
    // Initialize the given items
    struct Item items[4] = {{5, 10}, {4, 40}, {6, 30}, {3, 50}};

    // Calculate the maximum value that can be obtained in a 10kg knapsack
    int v = knapsack(MAXCAPACITY, items, 4);
    assert(v == 90);
    printf("All tests have passed successfully!\n");
}

/**
 * @brief Main function
 * @returns 0 on success
 */
int main()
{
    test();
    return 0;
}
