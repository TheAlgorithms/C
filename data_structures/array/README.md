# Array

Simple array of integers. With I/O functions, Sort Functions and Search Functions.

## Sort Function

The Sort function sorts the elements in the range in a particular order. The different types of sorting methods are Bubble Sort, Selection Sort, Merge Sort and Quick Sort. Bubble Sort repeatedly sorts the adjacent elements if they are in wrong order.

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
