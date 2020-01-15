#include <stdio.h>

void main()
{
    int a[] = {5, 6, 7, 8, 65, 99, 155, 666, 700, 845, 957, 1000};
    int beg = 0;
    int end = sizeof(a) / sizeof(int);
    int mid;
    int search;
    printf("Element to be searched\t");
    scanf("%d", &search);
    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (a[mid] == search)
        {
            printf("Element found HURRAY!!!\n");
            return;
        }
        if (a[mid] < search)
            beg = mid + 1;
        else
            end = mid - 1;
    }
    printf("Not found\n");
}