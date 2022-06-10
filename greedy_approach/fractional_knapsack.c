/**
 * @file
 * @author [Rajdeep Ghosh](https://github.com/sl1mb0)
 * @brief [Knapsack problem](https://en.wikipedia.org/wiki/Knapsack_problem)
 * implementation in C to find the Greedy solution to the Fractional Knapsack problem.
 * @details Fractional Knapsack is a problem in which the goal is to maximize the profit by filling a knapsack with items, which can be fully or fractionally taken.
 *
*/

#include <stdio.h>                                  /// for IO operations
#include <stdlib.h>                                 /// for memory allocations          

/**
 * @brief profit is the associated profit to the item
        unit is the profit per unit weight (profit/weight)
        proportion is the fraction of the item to be taken
 */
typedef struct item
{
	float profit, weight, unit, proportion;
} item;

/**
 * @brief Sorting the items (High to low) based on the profit per unit weight
 * @param items pointer to array of items to be sorted
 * @param len length of the array to be sorted
 * @returns void
 */
void sort(item **items, int len)
{
	for(int i = 0; i<len; i++)
	{
		for(int j = 0; j<len-i-1; j++)
		{
			if(items[j]->unit<items[j+1]->unit)
			{
				item *temp = items[j+1];
				items[j+1] = items[j];
				items[j] = temp;
			}
		}
	}
}

/**
 * @brief Prints the proportion of the items to be taken for max profit
 * @param items pointer to array of items
 * @param len length of the array of items
 * @param capacity maximum capacity of the knapsack
 * @returns void
 */
void fractionalKnapsack(item **items, int len, int capacity)
{
	int remaining = capacity;
	float profit = 0;
	int i;	
	for(i = 0; i<len; i++)                                                  //taking items which can be fully taken
	{
		if(items[i]->weight<=remaining)
		{
			profit += items[i]->profit;
			items[i]->proportion = 1.0;
			remaining -= items[i]->weight;
		}
		else break;		
	}
	if(remaining)                                                           //if space for a fraction of item
	{
		items[i]->proportion = remaining/(items[i]->weight);
		profit += items[i]->profit*items[i]->proportion;
	}
	for(int i = 0; i<len; i++)                                              //printing the object proportions
	{
		printf("\n");
		printf("%f ", items[i]->proportion);
	}
	printf("\nTotal profit = %f", profit);
}

/**
 * @brief Main function
 * @param argc commandline argument count (ignored)
 * @param argv commandline array of arguments (ignored)
 * @returns 0 on exit
 */
int main()
{
    /**
     * @test
     * input:
     * * size of items: 5
     * * max knapsack capacity: 60
     * * item 1: Profit: 30 Weight: 5
     * * item 2: Profit: 40 Weight: 10
     * * item 3: Profit: 45 Weight: 15
     * * item 4: Profit: 77 Weight: 22
     * * item 5: Profit: 90 Weight: 25
     * output:
     * 1.000000 
        1.000000 
        1.000000 
        0.909091 
        0.000000 
        Total profit = 230.000000
     * 
     */
    
	int n, m;
	printf("Enter The total nmber of items: ");
	scanf("%d", &n);
	printf("Enter Maximum Knapsack Capacity: ");
	scanf("%d", &m);	
	item *items[n];
	for(int i = 0; i<n; i++)
	{
		item *newItem = (item*)malloc(sizeof(item));                        //Allocating memory for array of items
		int profit, weight;
		printf("Enter profit ");
		scanf("%f", &newItem->profit);
		printf("Enter weight ");
		scanf("%f", &newItem->weight);
		newItem->unit = newItem->profit/newItem->weight;                    //calculating unit weight
		newItem->proportion = 0.0;                                          //initializing the proportion to 0
		items[i] = newItem;
	}
	sort(items, n);
	fractionalKnapsack(items, n, m);
	return 0;
}