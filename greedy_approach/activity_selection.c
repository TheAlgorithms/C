/**
 * @file
 * @author [Risanlang Hynniewta](https://github.com/risanlang)
 * @brief [Activity selection problem](https://en.wikipedia.org/wiki/Activity_selection_problem)
 * implementation in C to find the Maximum number of activity from the list of given activities.
 * @details The activity selection problem is a problem concerning the selection of non-conflicting activities to perform within a given time frame,
 * given a set of activities each marked by a start time (si) and finish time (fi). 
 * The problem is to select the maximum number of activities that can be performed by a single person or machine using Greedy Tecnique, 
 * assuming that a person can only work on a single activity at a time.
 *
 * To test - run './activity_selection'
 *Sample Input
 *Enter the number of activities you have
 *6
 *Enter the Start Time of Activity 1 :8
 *Enter the End Time of Activity 1 :9

 *Enter the Start Time of Activity 2 :5
 *Enter the End Time of Activity 2 :9

 *Enter the Start Time of Activity 3 :5
 *Enter the End Time of Activity 3 :7

 *Enter the Start Time of Activity 4 :3
 *Enter the End Time of Activity 4 :4

 *Enter the Start Time of Activity 5 :0
 *Enter the End Time of Activity 5 :6

 *Enter the Start Time of Activity 6 :1
 *Enter the End Time of Activity 6 :2

 *Before Sorting
 *The start time of activity 1 is : 8
 *The end time of activity 1 is : 9

 *The start time of activity 2 is : 5
 *The end time of activity 2 is : 9

 *The start time of activity 3 is : 5
 *The end time of activity 3 is : 7

 *The start time of activity 4 is : 3
 *The end time of activity 4 is : 4

 *The start time of activity 5 is : 0
 *The end time of activity 5 is : 6

 *The start time of activity 6 is : 1
 *The end time of activity 6 is : 2

 *After Sorting
 *The start time of activity 1 is : 1
 *The end time of activity 1 is : 2

 *The start time of activity 2 is : 3
 *The end time of activity 2 is : 4

 *The start time of activity 3 is : 0
 *The end time of activity 3 is : 6

 *The start time of activity 4 is : 5
 *The end time of activity 4 is : 7

 *The start time of activity 5 is : 8
 *The end time of activity 5 is : 9

 *The start time of activity 6 is : 5
 *The end time of activity 6 is : 9

 *Following activities are selected
 *activity with start_time : 1
 *activity with end_time : 2
 
 *activity with start_time : 3
 *activity with end_time : 4
 
 *activity with start_time : 5
 *activity with end_time : 7
 
 *activity with start_time : 8
 *activity with end_time : 9

 *
 */
#include<stdio.h> /// for IO operations
#include<stdlib.h> /// for Dynamic Memory allocation i.e calloc()
/// Activity structure with two data members i.e start_time and end_time
struct activity{
    int start_time;
    int end_time;
};

/**
 * @brief Printing all the Activity i.e the start_time and end_time of each Activity
 * @param struct activity *ptr, the pointer to the n activity blocks located in the heap memory
 * @param n number of activities
 */
void printing(struct activity *ptr,int n){
    for(int i=0;i<n;i++){
        printf("The start time of activity %d is : %d\n",i+1,(ptr+i)->start_time);
        printf("The end time of activity %d is : %d\n",i+1,(ptr+i)->end_time);
        printf("\n");
    }
    
}


/**
 * @brief Sorting the activity structure in ascending order of end_time
 * @param struct activity *ptr, the pointer to the n activity blocks located in the heap 
 * @param n number of activities
 */
void sort_the_structure(struct activity *ptr,int n){
    struct activity temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if((ptr+j)->end_time > (ptr+(j+1))->end_time){
               
               temp.start_time=(ptr+j)->start_time;
               temp.end_time=(ptr+j)->end_time;
               
               (ptr+j)->start_time=(ptr+(j+1))->start_time;
               (ptr+j)->end_time=(ptr+(j+1))->end_time;
               
               
                (ptr+(j+1))->start_time=temp.start_time;
                (ptr+(j+1))->end_time=temp.end_time;
            }
        }
    }
    
}



/**
 * @brief Finding the maximum number of non-conflicting activities to be selected and printing them
 * @param struct activity *ptr, the pointer to the n activity blocks located in the heap 
 * @param n number of activities
 */
void print_Max_Activities(struct activity *ptr,int n)
{
    
    printf("Following activities are selected\n");
 
    // The first activity always gets selected
    int i = 0;
    printf("activity with start_time : %d\n",(ptr+i)->start_time);
    printf("activity with end_time : %d\n",(ptr+i)->end_time);

 
    // Consider rest of the activities
    for (int j = 1; j < n; j++) {
        // If this activity has start time greater than or
        // equal to the finish time of previously selected
        // activity, then select it
        if ((ptr+j)->start_time>= (ptr+i)->end_time) {
            printf("activity with start_time : %d\n",(ptr+j)->start_time);
            printf("activity with end_time : %d\n",(ptr+j)->end_time);
            printf("\n");
            i = j;
        }
    }
}

 
/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(){
    int n;
    struct activity *ptr;
    printf("Enter the number of activities you have\n");
    scanf("%d",&n);
    ptr=(struct activity*)calloc(n,sizeof(struct activity));
    for(int i=0;i<n;i++){
        printf("Enter the Start Time of Activity %d :",i+1);
        scanf("%d",&((ptr+i)->start_time));
        printf("Enter the End Time of Activity %d :",i+1);
        scanf("%d",&((ptr+i)->end_time));
        printf("\n");
    }
    printf("Before Sorting\n");
    printing(ptr,n);
    sort_the_structure(ptr,n);
    printf("After Sorting\n");
    printing(ptr,n);
    print_Max_Activities(ptr,n);
    return 0;
}
