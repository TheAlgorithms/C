/**
 * @file
 * @brief 
 * [First-Come, First-Served (FCFS) Scheduling Algorithm]
 * (https://en.wikipedia.org/wiki/Scheduling_(computing))
 *
 * @details
 * This is a non-preemptive scheduling algorithm where the process that arrives
 * first gets executed first. It is one of the simplest CPU scheduling algorithms.
 * @author [Nivedh TJ](https://github.com/NivedhTJ)
 */

#include <stdio.h>  /// /// for IO operations (`printf`)
#include <stdlib.h> /// for malloc, free
#include <assert.h> /// for assert

/**
 * @brief Struct representing a process in the scheduling algorithm
 */
typedef struct
{
    int id;               ///< Process ID
    int arrival_time;     ///< Time at which the process arrives
    int burst_time;       ///< Time required by the process to complete
    int completion_time;  ///< Time at which process completes execution
    int turnaround_time;  ///< Turnaround time = completion - arrival
    int waiting_time;     ///< Waiting time = turnaround - burst
} process;

/**
 * @brief Comparator function for sorting processes by arrival time
 * @param a Pointer to first process
 * @param b Pointer to second process
 * @return Negative if a comes before b, positive if b comes before a
 */
int compare_by_arrival(const void *a, const void *b)
{
    return ((process *)a)->arrival_time - ((process *)b)->arrival_time;
}

/**
 * @brief Performs FIFO scheduling and calculates completion, turnaround, and waiting times
 * @param processes Array of processes
 * @param n Number of processes
 */
void calculate_fcfs_timings(process *processes, int n)
{
    qsort(processes, n, sizeof(process), compare_by_arrival);

    int current_time = 0;
    for (int i = 0; i < n; i++)
    {
        // Makes sure CPU waits if the next process hasn't arrived yet
        if (current_time < processes[i].arrival_time)
        {
            current_time = processes[i].arrival_time;
        }
        processes[i].completion_time = current_time + processes[i].burst_time;
        current_time = processes[i].completion_time;

        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}

/**
 * @brief Test function to verify FIFO scheduling logic
 */
static void test_fifo()
{
    process test_processes[3] = {
        {1, 0, 4, 0, 0, 0},
        {2, 1, 3, 0, 0, 0},
        {3, 2, 1, 0, 0, 0}};

    calculate_fcfs_timings(test_processes, 3);

    // Expected waiting times: P1 = 0, P2 = 3, P3 = 5
    assert(test_processes[0].waiting_time == 0);
    assert(test_processes[1].waiting_time == 3);
    assert(test_processes[2].waiting_time == 5);

    // Expected turnaround times: P1 = 4, P2 = 6, P3 = 6
    assert(test_processes[0].turnaround_time == 4);
    assert(test_processes[1].turnaround_time == 6);
    assert(test_processes[2].turnaround_time == 6);

    printf("All test cases passed!\n");
}


/**
 * @brief Main function
 * @return 0 upon successful execution
 */
int main()
{
    test_fifo();
    return 0;
}
