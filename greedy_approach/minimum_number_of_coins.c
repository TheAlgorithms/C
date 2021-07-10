// C program to find minimum 
// number of denominations 
#include <stdio.h> 
#define COINS 9 
#define MAX 20 

// All denominations of Indian Currency 
int coins[COINS] = { 1, 2, 5, 10, 20, 
					50, 100, 200, 2000 }; 

void findMin(int cost) 
{ 
	int coinList[MAX] = { 0 }; 
	int i, k = 0; 

	for (i = COINS - 1; i >= 0; i--) { 
		while (cost >= coins[i]) { 
			cost -= coins[i]; 
			// Add coin in the list 
			coinList[k++] = coins[i]; 
		} 
	} 

	for (i = 0; i < k; i++) { 
		// Print 
		printf("%d ", coinList[i]); 
	} 
	return; 
} 

int main(void) 
{ 
	// input value 
	int n = 93; 

	printf("Following is minimal number"
		"of change for %d: ", 
		n); 
	findMin(n); 
	return 0; 
} 
