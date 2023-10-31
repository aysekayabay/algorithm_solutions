#include <stdio.h>
void quicksort(int arr[], int l, int r);
int partition(int arr[], int l, int r);
int main(int argc, char const *argv[])
{
    int arr[] = {5, 3, 1, 9, 8, 2, 4, 7};
    quicksort(arr, 0, 6);
    printf("Sorted array: ");
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void quicksort(int arr[], int l, int r)
{
    if (l < r)
    {
        int adr = partition(arr, l, r);
        quicksort(arr, l, adr - 1);
        quicksort(arr, adr + 1, r);
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int l, int r)
{
    int pivot = arr[l];
    int pivot_p = l;
    l++;
    while (l < r)
    {
        while (arr[l] < pivot)
        {
            l++;
        }
        while (arr[r] > pivot)
        {
            r--;
        }

        if (l < r)
        {
            swap(&arr[l], &arr[r]);
            l++;
            r--;
        }
    }
    swap(&arr[l - 1], &arr[pivot_p]);
    return l - 1; // new pivot index
}