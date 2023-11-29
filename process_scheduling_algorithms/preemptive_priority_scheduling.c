/**
 * @file
 * @brief
 * [Preemptive Priority
 * Scheduling]
 *  Preemptive Priority Scheduling is a   CPU scheduling algorithm
 *  that assigns priorities to processes and selects the process
 *  with the highest priority to execute. If a higher-priority
 *  process becomes available, it preempts the currently executing.
 *  This algorithm ensures that higher-priority processes
 *  are given preference, but it may lead to starvation of lower-priority
 *   if not handled properly.*
 *
 * @details
 *  Algorithm Overview:
 *    1. Initialize a set of processes with such as ID, arrival time,
 *       burst time, priority, executed time, and completion time.
 *      2. Start with an empty queue of ready processes and initialize variables
 *         to keep track of the current time, executed processes, and the currently
 *         executing process.
 *      3. Repeat the following steps until all processes are executed:
 *         a. Find the process with the highest priority that has arrived and
 *           not completed yet.
 *       b. Execute the selected process for one time unit, updating its executed time and the current time.
 *       c. If the selected process completes, calculate its completion time, print a completion message, and update turnaround and waiting times.
 *       d. If no suitable process is found to execute, increment the current time.
 *     4. Calculate and print the average turnaround time and average waiting time.
 * @author [Archana Saroj](https://github.com/SarojArchana)
 */
#include <stdio.h>    /// for IO operations (`printf`)
/**
 * @brief Structure to represent a process
 */
struct Process {
    int id;             ///< Process ID
    int arrival_time;   ///< Arrival time of the process 
    int burst_time;     ///< Burst time of the process
    int priority;       ///< Priority of the process
    int executed_time;  ///< Time the process has been executed
    int completion_time;///< Completion time of the process 
};
/**
 * @brief Performs preemptive priority scheduling for a set of processes.
 * @param processes An array of Process structures representing the processes to be scheduled.
 * @param n The number of processes in the array.
 * @return void
 */
void preemptivePriority(struct Process processes[], int n) {
    unsigned int currentTime = 0;
    unsigned int executedProcesses = 0;
    int currentProcess = -1;
    float totalTurnaroundTime = 0;
    float totalWaitingTime = 0;

    while (executedProcesses < n) {
        int highestPriority = 9999; // A large number as initial priority
        int nextProcess = -1;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= currentTime && processes[i].executed_time < processes[i].burst_time) {
                if (processes[i].priority < highestPriority) {
                    highestPriority = processes[i].priority;
                    nextProcess = i;
                }
            }
        }

        if (nextProcess != -1) {
            if (currentProcess != -1 && currentProcess != nextProcess) {
                printf("Time %d: Process %d -> Process %d\n", currentTime, currentProcess + 1, nextProcess + 1);
            }
            currentProcess = nextProcess;
            processes[currentProcess].executed_time++;
            currentTime++;

            if (processes[currentProcess].executed_time == processes[currentProcess].burst_time) {
                executedProcesses++;
                processes[currentProcess].completion_time = currentTime;
                printf("Time %d: Process %d completed\n", currentTime, currentProcess + 1);
                totalTurnaroundTime += (float)processes[currentProcess].completion_time - processes[currentProcess].arrival_time;
                totalWaitingTime += (float)processes[currentProcess].completion_time - processes[currentProcess].arrival_time - processes[currentProcess].burst_time;
                currentProcess = -1;
            }
        } else {
            currentTime++;
        }
    }

    float avgTurnaroundTime = totalTurnaroundTime / n;
    float avgWaitingTime = totalWaitingTime / n;

    printf("\nAverage Turnaround Time: %.2f\n", avgTurnaroundTime);
    printf("Average Waiting Time: %.2f\n", avgWaitingTime);
}
/**
 * @brief Runs test cases for preemptive priority scheduling.
 * @return void
 */
static void test() {
    struct Process testCase1[] = {
        {1, 0, 3, 2, 0},
        {2, 1, 5, 1, 0},
        {3, 2, 2, 3, 0},
        {4, 3, 4, 4, 0},
        {5, 4, 6, 2, 0}
    };

    struct Process testCase2[] = {
        {1, 0, 8, 2, 0},
        {2, 1, 6, 1, 0},
        {3, 2, 4, 3, 0},
        {4, 3, 2, 4, 0},
        {5, 4, 5, 2, 0}
    };

    struct Process testCase3[] = {
        {1, 0, 4, 3, 0},
        {2, 1, 3, 2, 0},
        {3, 2, 7, 1, 0},
        {4, 3, 5, 4, 0},
        {5, 4, 2, 5, 0}
    };

    struct Process testCase4[] = {
        {1, 0, 5, 4, 0},
        {2, 1, 4, 3, 0},
        {3, 2, 6, 2, 0},
        {4, 3, 3, 1, 0},
        {5, 4, 7, 5, 0}
    };

    int n1 = sizeof(testCase1) / sizeof(testCase1[0]);
    int n2 = sizeof(testCase2) / sizeof(testCase2[0]);
    int n3 = sizeof(testCase3) / sizeof(testCase3[0]);
    int n4 = sizeof(testCase4) / sizeof(testCase4[0]);

    printf("Test Case 1:\n");
    preemptivePriority(testCase1, n1);

    printf("\nTest Case 2:\n");
    preemptivePriority(testCase2, n2);

    printf("\nTest Case 3:\n");
    preemptivePriority(testCase3, n3);

    printf("\nTest Case 4:\n");
    preemptivePriority(testCase4, n4);
}
/**
 * @brief Main function to run the scheduling algorithm with test cases.
 * @return Returns 0 to indicate successful execution.
 */
int main() {
    test();
    return 0;
}
