/**
 * Problem 4
 * ~~~~~~~~~
 *
 * Write a program that finds the largest and smallest
 * integers in an array of integers.
 *
 * In this solution, I implemented the quick sort algorithm
 * to sort the array, then select the first and last elements
 * as smallest and largest, respectively.
 */

#include <stdio.h>

void swap(int *a, int *b)
{
    int t;

    t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int i, pivot;

    pivot = arr[high];
    i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}

void qSort(int arr[], int lo, int hi)
{
    if (lo < hi)
    {
        int pIndex = partition(arr, lo, hi);

        qSort(arr, lo, pIndex - 1);
        qSort(arr, pIndex + 1, hi);
    }
}

int main()
{
    int arr[] = {5, 33, 24, 7, 16};
    int n = sizeof arr / sizeof arr[0];

    qSort(arr, 0, n - 1);

    int smallest = arr[0];
    int largest = arr[sizeof arr / sizeof *arr - 1];

    printf("Smallest: %d\nLargest: %d\n", smallest, largest);
}