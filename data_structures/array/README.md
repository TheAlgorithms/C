# Array

Simple array of integers. With I/O functions, Sort Functions and Search Functions.

## Sort Function

The Sort function sorts the elements and arrange in a particular order. The different types of sorting methods are Bubble Sort, Selection Sort,insertion sort, Merge Sort and Quick Sort.
1. Bubble Sort repeatedly sorts the adjacent elements if they are in wrong order.
2. Selection sort repeatedly finds minimum elements from unsorted array and place at the beginning, this algorithm maintains two sub array one is sorted and one  is  unsorted.
3. Insertion sort makes virtualy two subarrays one is sorted and one is unsorted . Takes values from unsorted array and put at proper position in sorted array.
4. Merge sort is based on divide and conquer method. This sortig algorithm continiously divide array in two equal halves and combined in sorted order.
5. Quick sort is a divide and conquer algorithm , it takes an element as an pivot and partitions the array around the pivot element.


## Structure

```C
typedef struct CArray {
		int *array;
		int size;
	} CArray;
```

## Files

* CArray.c - Array Implementations
* CArray.h - Import for Usage
* CArrayTests.c - Usage Examples and tests
