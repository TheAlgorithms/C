#include <stdio.h>

// To find the largest number in the array
int findLargestNum(int data[], int length) {
    int largest = data[0];
    for (int i = 1; i < length; i++)
        if (data[i] > largest)
            largest = data[i];
    return largest;
}

// To perform counting sort on the array based on the specified digit
void performCountSort(int data[], int length, int place) {
    int output[length]; 
    int i, freq[10] = {0};
    for (i = 0; i < length; i++)
        freq[(data[i] / place) % 10]++;
    for (i = 1; i < 10; i++)
        freq[i] += freq[i - 1];
    for (i = length - 1; i >= 0; i--) {
        output[freq[(data[i] / place) % 10] - 1] = data[i];
        freq[(data[i] / place) % 10]--;
    }
    for (i = 0; i < length; i++)
        data[i] = output[i];
}

// Main function for Radix Sort
void performRadixSort(int data[], int length) {
    int largestNum = findLargestNum(data, length);
    for (int place = 1; largestNum / place > 0; place *= 10)
        performCountSort(data, length, place);
}
void displayArray(int data[], int length) {
    for (int i = 0; i < length; i++)
        printf("%d ", data[i]);
    printf("\n");
}
int main() {
    int array1[] = {121, 432, 564, 23, 1, 45, 788};
    int length1 = sizeof(array1) / sizeof(array1[0]);
    int array2[] = {95, 90, 85, 80, 75, 70};
    int length2 = sizeof(array2) / sizeof(array2[0]);
    int array3[] = {333, 287, 911, 462, 786};
    int length3 = sizeof(array3) / sizeof(array3[0]);
    int array4[] = {5, 3, 8, 1, 2, 9, 4, 7, 6};
    int length4 = sizeof(array4) / sizeof(array4[0]);
    int array5[] = {12, 34, 12, 45, 67, 45, 34};
    int length5 = sizeof(array5) / sizeof(array5[0]);

    // Sorting and displaying each array
    performRadixSort(array1, length1);
    printf("Sorted Array 1: ");
    displayArray(array1, length1);
    performRadixSort(array2, length2);
    printf("Sorted Array 2: ");
    displayArray(array2, length2);
    performRadixSort(array3, length3);
    printf("Sorted Array 3: ");
    displayArray(array3, length3);
    performRadixSort(array4, length4);
    printf("Sorted Array 4: ");
    displayArray(array4, length4);
    performRadixSort(array5, length5);
    printf("Sorted Array 5: ");
    displayArray(array5, length5);

    return 0;
}