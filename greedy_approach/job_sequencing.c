#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a job
typedef struct Job {
	char id; // Job Id
	int dead; // Deadline of job
	int profit; // Profit if job is over before or on deadline
} Job;

// This function is used for sorting all jobs according to
// profit
int compare(const void* a, const void* b)
{
	Job* temp1 = (Job*)a;
	Job* temp2 = (Job*)b;
	return (temp2->profit - temp1->profit);
}

// Find minimum between two numbers.
int min(int num1, int num2)
{
	return (num1 > num2) ? num2 : num1;
}

// Returns minimum number of platforms required
void printJobScheduling(Job arr[], int n)
{
	// Sort all jobs according to decreasing order of profit
	qsort(arr, n, sizeof(Job), compare);
	//	 sort(arr, arr+n, comparison);

	int result[n]; // To store result (Sequence of jobs)
	bool slot[n]; // To keep track of free time slots

	// Initialize all slots to be free
	for (int i = 0; i < n; i++)
		slot[i] = false;

	// Iterate through all given jobs
	for (int i = 0; i < n; i++) {
		// Find a free slot for this job (Note that we start
		// from the last possible slot)
		for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
			// Free slot found
			if (slot[j] == false) {
				result[j] = i; // Add this job to result
				slot[j] = true; // Make this slot occupied
				break;
			}
		}
	}

	// Print the result
	for (int i = 0; i < n; i++)
		if (slot[i])
			printf("%c ", arr[result[i]].id);
}

// Driver code
int main()
{
	Job arr[] = { { 'a', 2, 100 },
				{ 'b', 1, 19 },
				{ 'c', 2, 27 },
				{ 'd', 1, 25 },
				{ 'e', 3, 15 } };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf(
		"Following is maximum profit sequence of jobs \n");

	// Function call
	printJobScheduling(arr, n);
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
