#include <stdio.h>
typedef enum
{
    true = 1,
    false = 0
} bool;

bool binary_search(int a[], int beg, int end, int search)
{
    if (beg <= end)
    {
        int mid = (beg + end) / 2;
        if (a[mid] == search)
            return true;
        else if (a[mid] < search)
            return binary_search(a, mid + 1, end, search);
        else
            return binary_search(a, beg, mid - 1, search);
    }
    return false;
}
void main()
{
    int a[] = {5, 6, 7, 8, 65, 99, 155, 666, 700, 845, 957, 1000};
    int search;
    printf("Element to be searched\t");
    scanf("%d", &search);
    if (binary_search(a, 0, sizeof(a) / sizeof(int), search))
        printf("Element found HURRAY!!!\n");
    else
        printf("Not found\n");
}