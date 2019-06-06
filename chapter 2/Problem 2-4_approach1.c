#include<stdio.h>

int total_inversion(int *a,int n)
{
    int i,j,inverisons=0;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                inverisons++;
            }
        } 
    }
    return inverisons;
}

int main()
{
    int n,i;
    printf("Enter total elements of the array\t");
    scanf("%d",&n);

    int a[n];
    printf("Enter your array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("total inversions are %d\n",total_inversion(a,n));
    return 0;
}