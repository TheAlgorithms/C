/**
 * @file
 * @brief
 * [Non-Preemptive Priority
 * Scheduling](https://en.wikipedia.org/wiki/Scheduling_(computing))
 * is a scheduling algorithm that selects the tasks to execute based on
 * priority.
 *
 * @details
 * In this algorithm, processes are executed according to their
 * priority. The process with the highest priority is to be executed first and
 * so on. In this algorithm, a variable is maintained known as the time quantum.
 * The length of the time quantum is decided by the user. The process which is
 * being executed is interrupted after the expiration of the time quantum and
 * the next process with the highest priority is executed. This cycle of
 * interrupting the process after every time quantum and resuming the next
 * process with the highest priority continues until all the processes have
 * been executed.
 * @author [Aryan Raj](https://github.com/aryaraj132)
 */
#include <assert.h>   /// for assert
#include <stdbool.h>  /// for boolean data type
#include <stdio.h>    /// for IO operations (`printf`)
#include <stdlib.h>  /// for memory allocation eg: `malloc`, `realloc`, `free`, `exit`
/**
 * @brief Structure to represent a process
 */
 typedef struct node {
     int ID;             ///< ID of the process node
     int AT;             ///< Arrival Time of the process node
     int BT;             ///< Burst Time of the process node
     int priority;       ///< Priority of the process node
     int CT;             ///< Completion Time of the process node
     int WT;             ///< Waiting Time of the process node
     int TAT;            ///< Turn Around Time of the process node
     struct node *next;  ///< pointer to the node
 } node;

/**
 * @brief To insert a new process in the queue
 * @param root pointer to the head of the queue
 * @param id process ID
 * @param at arrival time
 * @param bt burst time
 * @param prior priority of the process
 * @returns void
 */
void insert(node **root, int id, int at, int bt, int prior)
{
    // create a new node and initialize it
    node *new = (node *)malloc(sizeof(node));
    node *ptr = *root;
    new->ID = id;
    new->AT = at;
    new->BT = bt;
    new->priority = prior;
    new->next = NULL;
    new->CT = 0;
    new->WT = 0;
    new->TAT = 0;
    // if the root is null, make the new node the root
    if (*root == NULL)
    {
        *root = new;
        return;
    }
    // else traverse to the end of the queue and insert the new node there
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new;
    return;
}
/*
 * @brief To delete a process from the queue
 * @param root pointer to the head of the queue
 * @param id process ID
 * @returns void
 */
void delete(node **root, int id)
{
    node *ptr = *root, *prev;
    // if the root is null, return
    if (ptr == NULL)
    {
        return;
    }
    // if the root is the process to be deleted, make the next node the root
    if (ptr->ID == id)
    {
        *root = ptr->next;
        free(ptr);
        return;
    }
    // else traverse the queue and delete the process
    while (ptr != NULL && ptr->ID != id)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        return;
    }
    prev->next = ptr->next;
    free(ptr);
}
/**
 * @brief To show the process queue
 * @param head pointer to the head of the queue
 * @returns void
 */
void show_list(node *head)
{
    printf("Process Priority AT BT CT TAT WT \n");
    while (head != NULL)
    {
        printf("P%d. %d %d %d %d %d %d \n", head->ID, head->priority, head->AT,
               head->BT, head->CT, head->TAT, head->WT);
        head = head->next;
    }
}
/**
 * @brief To length process queue
 * @param root pointer to the head of the queue
 * @returns int total length of the queue
 */
int l_length(node **root)
{
    int count = 0;
    node *ptr = *root;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}
/**
 * @brief To update the completion time, turn around time and waiting time of
 * the processes
 * @param root pointer to the head of the queue
 * @param id process ID
 * @param ct current time
 * @param wt waiting time
 * @param tat turn around time
 * @returns void
 */
void update(node **root, int id, int ct, int wt, int tat)
{
    node *ptr = *root;
    // If process to be updated is head node
    if (ptr != NULL && ptr->ID == id)
    {
        if (ct != 0)
        {
            ptr->CT = ct;
        }
        if (wt != 0)
        {
            ptr->WT = wt;
        }
        if (tat != 0)
        {
            ptr->TAT = tat;
        }
        return;
    }
    // else traverse the queue and update the values
    while (ptr != NULL && ptr->ID != id)
    {
        ptr = ptr->next;
    }
    if (ct != 0)
    {
        ptr->CT = ct;
    }
    if (wt != 0)
    {
        ptr->WT = wt;
    }
    if (tat != 0)
    {
        ptr->TAT = tat;
    }
    return;
}
/**
 * @brief To compare the priority of two processes based on their arrival time
 * and priority
 * @param a pointer to the first process
 * @param b pointer to the second process
 * @returns true if the priority of the first process is greater than the
 * the second process
 * @returns false if the priority of the first process is NOT greater than the
 * second process
 */
bool compare(node *a, node *b)
{
    if (a->AT == b->AT)
    {
        return a->priority < b->priority;
    }
    else
    {
        return a->AT < b->AT;
    }
}
/**
 * @brief To calculate the average completion time of all the processes
 * @param root pointer to the head of the queue
 * @returns float average completion time
 */
float calculate_ct(node **root)
{
    // calculate the total completion time of all the processes
    node *ptr = *root, *prior, *rpt;
    int ct = 0, i, time = 0;
    int n = l_length(root);
    float avg, sum = 0;
    node *duproot = NULL;
    // create a duplicate queue
    while (ptr != NULL)
    {
        insert(&duproot, ptr->ID, ptr->AT, ptr->BT, ptr->priority);
        ptr = ptr->next;
    }
    ptr = duproot;
    rpt = ptr->next;
    // sort the queue based on the arrival time and priority
    while (rpt != NULL)
    {
        if (!compare(ptr, rpt))
        {
            ptr = rpt;
        }
        rpt = rpt->next;
    }
    // ptr is the process to be executed first.
    ct = ptr->AT + ptr->BT;
    time = ct;
    sum += ct;
    // update the completion time, turn around time and waiting time of the
    // process
    update(root, ptr->ID, ct, 0, 0);
    delete (&duproot, ptr->ID);
    // repeat the process until all the processes are executed
    for (i = 0; i < n - 1; i++)
    {
        ptr = duproot;
        while (ptr != NULL && ptr->AT > time)
        {
            ptr = ptr->next;
        }
        rpt = ptr->next;
        while (rpt != NULL)
        {
            if (rpt->AT <= time)
            {
                if (rpt->priority < ptr->priority)
                {
                    ptr = rpt;
                }
            }
            rpt = rpt->next;
        }
        ct += ptr->BT;
        time += ptr->BT;
        sum += ct;
        update(root, ptr->ID, ct, 0, 0);
        delete (&duproot, ptr->ID);
    }
    avg = sum / n;
    return avg;
}
/**
 * @brief To calculate the average turn around time of all the processes
 * @param root pointer to the head of the queue
 * @returns float average turn around time
 */
float calculate_tat(node **root)
{
    float avg, sum = 0;
    int n = l_length(root);
    node *ptr = *root;
    // calculate the completion time if not already calculated
    if (ptr->CT == 0)
    {
        calculate_ct(root);
    }
    // calculate the total turn around time of all the processes
    while (ptr != NULL)
    {
        ptr->TAT = ptr->CT - ptr->AT;
        sum += ptr->TAT;
        ptr = ptr->next;
    }
    avg = sum / n;
    return avg;
}
/**
 * @brief To calculate the average waiting time of all the processes
 * @param root pointer to the head of the queue
 * @returns float average waiting time
 */
float calculate_wt(node **root)
{
    float avg, sum = 0;
    int n = l_length(root);
    node *ptr = *root;
    // calculate the completion if not already calculated
    if (ptr->CT == 0)
    {
        calculate_ct(root);
    }
    // calculate the total waiting time of all the processes
    while (ptr != NULL)
    {
        ptr->WT = (ptr->TAT - ptr->BT);
        sum += ptr->WT;
        ptr = ptr->next;
    }
    avg = sum / n;
    return avg;
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test()
{
    // Entered processes
    // printf("ID Priority Arrival Time Burst Time \n");
    // printf("1 0 5 1 \n");
    // printf("2 1 4 2 \n");
    // printf("3 2 3 3 \n");
    // printf("4 3 2 4 \n");
    // printf("5 4 1 5 \n");

    node *root = NULL;
    insert(&root, 1, 0, 5, 1);
    insert(&root, 2, 1, 4, 2);
    insert(&root, 3, 2, 3, 3);
    insert(&root, 4, 3, 2, 4);
    insert(&root, 5, 4, 1, 5);
    float avgCT = calculate_ct(&root);
    float avgTAT = calculate_tat(&root);
    float avgWT = calculate_wt(&root);
    assert(avgCT == 11);
    assert(avgTAT == 9);
    assert(avgWT == 6);
    printf("[+] All tests have successfully passed!\n");
    // printf("Average Completion Time is : %f \n", calculate_ct(&root));
    // printf("Average Turn Around Time is : %f \n", calculate_tat(&root));
    // printf("Average Waiting Time is : %f \n", calculate_wt(&root));
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
    test();  // run self-test implementations

    return 0;
}
