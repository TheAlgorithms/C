/**
 * @file
 * @brief [01 Knapsack](https://en.wikipedia.org/wiki/Knapsack_problem#0-1_knapsack_problem)
 * @details
 * From Wikipedia : The knapsack problem is
 * Given a set of items, each with a weight and a value, determine
 * which items to include in the collection
 * so that the total weight is less than or equal to a given limit and the total value is as large as possible.
 * @author [aa001R](https://github.com/aa001R)
 */

#include <assert.h> /// for assert
#include <stdio.h>

/**
 * @brief max() macro function
 */
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

/**
 * @brief Maximum capacity of the knapsack
 */ 
#define MAXCAPACITY 10

/**
 * @brief Item structure
 */
struct Item {
	int weight; // weight
	int value; // value
};

/**
 * @brief Print input items function
 * @param items an array of Item structure
 * @param cnt the number of items(Item structure)
 * @returns void
 */
void print_input_struct_Items(struct Item items[], int cnt);
/**
 * @brief Print the combination of items in the knapsack
 * @param W the capacity of the knapsack
 * @param items an array of Item structure
 * @param cnt the number of items(Item structure)
 * @param K the 2D array storing the optimal solution
 * @returns void
 */
void print_knapsack_item(int W, struct Item items[], int cnt, int K[][MAXCAPACITY+1]);

/**
 * @brief 0-1 Knapsack algorithm
 * @param W the capacity of the knapsack
 * @param items an array of Item structure
 * @param cnt the number of items(Item structure)
 * @returns the maximum value that can be obtained
 */
int knapsack(int W, struct Item items[], int cnt) {
	// Print input items
	print_input_struct_Items(items, cnt);

	// 2D array to store the optimal solution of subproblems
	int K[cnt + 1][W + 1];

	// Initialize the first row and column to 0
	for (int i = 0; i <= cnt; i++)
		K[i][0] = 0;
	for (int j = 0; j <= W; j++)
		K[0][j] = 0;

	// Calculate the optimal solution by selecting items one by one
	for (int i = 1; i <= cnt; i++) {
		for (int w = 1; w <= W; w++) {
			if (items[i - 1].weight <= w) { // If the i-th item can be included in the knapsack
				int val1 = items[i - 1].value + K[i - 1][w - items[i - 1].weight]; // Value if the i-th item is selected
				int val2 = K[i - 1][w]; // Value if the i-th item is not selected
				K[i][w] = MAX(val1, val2); // Select the maximum value
			} else { // If the i-th item cannot be included in the knapsack
				K[i][w] = K[i - 1][w];
			}
		}
	}

	// Print the result of the Knapsack algorithm
	printf("Knapsack execution result:\n");
	for (int i = 0; i < cnt + 1; i++) {
		for (int j = 0; j < W + 1; j++) {
			printf("%2d ", K[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	// Print the maximum value of the knapsack
	printf("Maximum Value: %d\n", K[cnt][W]);
	// Print the combination of items in the knapsack
	print_knapsack_item(W, items, cnt, K);
	return K[cnt][W];
}

/**
 * @brief Print input items
 * @param items an array of Item structure
 * @param cnt the number of items(Item structure)
 * @returns void
 */
void print_input_struct_Items(struct Item items[], int cnt) {
	printf("Input Item Structures:\n");
	for (int i = 0; i < cnt; i++) {
		printf("Item %d (Weight: %d, Value: %d)\n", i + 1, items[i].weight, items[i].value);
	}
	printf("\n");
}
/**

 * @brief Print the combination of items in the knapsack
 * @param W the capacity of the knapsack
 * @param items an array of Item structure
 * @param cnt the number of items(Item structure)
 * @param K the 2D array storing the optimal solution
 * @returns void
 */
void print_knapsack_item(int W, struct Item items[], int cnt, int K[][MAXCAPACITY+1]) {
	// Backtracking from the final maximum value to track the value changes
	int i = cnt; // Number of items (maximum to 0)
	int w = W; // Temporary capacity of the knapsack (maximum to 0)
	printf("Items in the knapsack:\n");
	while (i > 0 && w > 0) {
		// Check if the i-th item is selected
		if (K[i][w] != K[i - 1][w]) {
			/* If K[i][j] != K[i-1][j], it means the i-th item is included at the previous (w-items[i-1].weight) weight. */
			printf("Item %d (Weight: %d, Value: %d)\n", i, items[i - 1].weight, items[i - 1].value);
			w = w - items[i - 1].weight; // Move to the weight excluding the i-th item from now on
		}
		/* If K[i][w] == K[i-1][W], it means the i-th item is not included in the knapsack: w remains the same. */
		i--;
	}
}

static void test() {
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
int main() {
	test();
	return 0;
}
