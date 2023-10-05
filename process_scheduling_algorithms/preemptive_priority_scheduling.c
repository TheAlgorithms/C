/**
 * @file
 * @brief
 * [Pre-emptive Priority Scheduling](https://en.wikipedia.org/wiki/Fixed-priority_pre-emptive_scheduling)
 * is a scheduling algorithm that selects the tasks to execute based on
 * priority.
 *
 * @details
 * The preemptive priority CPU scheduling algorithm uses a rank-based system 
 * to define a rank for each process, where lower rank processes have higher 
 * priority and higher rank processes have lower priority. 
 * The preemptive priority CPU scheduling algorithm decides the priority of 
 * a process based on its rank. The scheduler selects the first process whose 
 * arrival time is 0 because that process is only executing at time t=0. 
 * Then it checks the priority of the next available process. If the current 
 * process has a higher priority than the previous one, then it executes the 
 * current process. If the current process has a lower priority than the 
 * previous one, then it executes the previous one. 
 * If both processes have equal priorities, then it executes the one that arrived first.
 * @author [Dilip Jain](https://github.com/dilipkjain)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[10];
    int arrivalTime;
    int burstTime;
    int priority;
    int startTime;
    int finishTime;
    int waitingTime;
    int turnaroundTime;
} Process;

/**
 * @brief Inserts a process into the array of processes
 * @param processes array of processes
 * @param n pointer to the number of processes
 */
void insert(Process *processes, int *n) {
    printf("Enter process name, arrival time, burst time, and priority: ");
    scanf("%s%d%d%d", processes[*n].name, &processes[*n].arrivalTime, &processes[*n].burstTime, &processes[*n].priority);
    (*n)++;
}

/**
 * @brief Deletes a process from the array of processes
 * @param processes array of processes
 * @param n pointer to the number of processes
 * @param index index of the process to delete
 */
void delete(Process *processes, int *n, int index) {
    for (int i = index; i < (*n) - 1; i++) {
        processes[i] = processes[i + 1];
    }
    (*n)--;
}

/**
 * @brief Updates the arrival time, burst time, and priority of a process
 * @param processes array of processes
 * @param n number of processes
 * @param index index of the process to update
 */
void update(Process *processes, int n, int index) {
    printf("Enter new arrival time, burst time, and priority for process %s: ", processes[index].name);
    scanf("%d%d%d", &processes[index].arrivalTime, &processes[index].burstTime, &processes[index].priority);
}

/**
 * @brief Comparison function for sorting the processes based on arrival time and priority
 * @param a pointer to the first process
 * @param b pointer to the second process
 * @returns negative value if a < b, positive value if a > b, 0 if a == b
 */
int compare(const void *a, const void *b) {
    Process *processA = (Process *)a;
    Process *processB = (Process *)b;

    if (processA->arrivalTime < processB->arrivalTime) {
        return -1;
    } else if (processA->arrivalTime > processB->arrivalTime) {
        return 1;
    } else {
        if (processA->priority < processB->priority) {
            return -1;
        } else if (processA->priority > processB->priority) {
            return 1;
        } else {
            return 0;
        }
    }
}

/**
 * @brief Calculates the completion time of each process
 * @param processes array of processes
 * @param n number of processes
 */
void calculate_ct(Process *processes, int n) {
    for (int i = 0; i < n; i++) {
        processes[i].finishTime = processes[i].startTime + processes[i].burstTime;
    }
}

/**
 * @brief Calculates the turnaround time of each process
 * @param processes array of processes
 * @param n number of processes
 */
void calculate_tat(Process *processes, int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].finishTime - processes[i].arrivalTime;
    }
}

/**
 * @brief Calculates the waiting time of each process
 * @param processes array of processes
 * @param n number of processes
 */
void calculate_wt(Process *processes, int n) {
    for (int i = 0; i < n; i++) {
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
    }
}

/**
 * @brief Calculates the average completion time of all the processes
 * @param processes array of processes
 * @param n number of processes
 * @returns float average completion time
 */
float calculate_avg_ct(Process *processes, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += processes[i].finishTime;
    }
    return sum / n;
}

/**
 * @brief Calculates the average turnaround time of all the processes
 * @param processes array of processes
 * @param n number of processes
 * @returns float average turnaround time
 */
float calculate_avg_tat(Process *processes, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += processes[i].turnaroundTime;
    }
    return sum / n;
}

/**
 * @brief Calculates the average waiting time of all the processes
 * @param processes array of processes
 * @param n number of processes
 * @returns float average waiting time
 */
float calculate_avg_wt(Process *processes, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += processes[i].waitingTime;
    }
    return sum / n;
}

/**
 * @brief Performs preemptive priority scheduling on the processes
 * @param processes array of processes
 * @param n number of processes
 * @returns void
 */
void preemptivePriorityScheduling(Process *processes, int n) {
    qsort(processes, n, sizeof(Process), compare);

    int currentTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < n) {
        int highestPriorityIndex = -1;
        int highestPriority = 9999;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && processes[i].burstTime > 0 && processes[i].priority < highestPriority) {
                highestPriorityIndex = i;
                highestPriority = processes[i].priority;
            }
        }

        if (highestPriorityIndex != -1) {
            processes[highestPriorityIndex].burstTime--;
            currentTime++;

            if (processes[highestPriorityIndex].startTime == -1) {
                processes[highestPriorityIndex].startTime = currentTime - 1;
            }

            if (processes[highestPriorityIndex].burstTime == 0) {
                completedProcesses++;
                processes[highestPriorityIndex].finishTime = currentTime;
            }
        } else {
            currentTime++;
        }
    }

    calculate_ct(processes, n);
    calculate_tat(processes, n);
    calculate_wt(processes, n);
}

/**
 * @brief Prints a table of the processes
 * @param processes array of processes
 * @param n number of processes
 * @returns void
 */
void printProcessTable(Process *processes, int n) {
    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%12d\t%10d\t%8d\t%12d\t%15d\n", processes[i].name, processes[i].arrivalTime, processes[i].burstTime, processes[i].priority, processes[i].waitingTime, processes[i].turnaroundTime);
    }
}

/**
 * @brief Self-test implementations
 * @returns void
 */
void test() {
    int n = 4;
    Process processes[4] = {
        {"P1", 0, 4, 2},
        {"P2", 1, 3, 1},
        {"P3", 2, 2, 3},
        {"P4", 3, 1, 4}
    };

    preemptivePriorityScheduling(processes, n);
    printProcessTable(processes, n);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process *processes = (Process *)malloc(n * sizeof(Process));

    for (int i = 0; i < n; i++) {
        insert(processes, &n);
    }

    preemptivePriorityScheduling(processes, n);

    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tFinish Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].name, processes[i].arrivalTime, processes[i].burstTime, processes[i].priority, processes[i].finishTime, processes[i].turnaroundTime, processes[i].waitingTime);
    }

    float avgCT = calculate_avg_ct(processes, n);
    float avgTAT = calculate_avg_tat(processes, n);
    float avgWT = calculate_avg_wt(processes, n);

    printf("\nAverage Completion Time: %.2f\n", avgCT);
    printf("Average Turnaround Time: %.2f\n", avgTAT);
    printf("Average Waiting Time: %.2f\n", avgWT);

    free(processes);

    return 0;
}
