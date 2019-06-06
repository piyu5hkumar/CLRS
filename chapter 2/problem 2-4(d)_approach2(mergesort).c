#include<stdio.h>

int merge(int *a,int beg,int mid,int end)
{
    int i=beg;
    int j=mid+1;
    int k=0;
    int b[end-beg+1];
    int inversions=0;

    while(i<=mid&&j<=end)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
        }
        else if(a[i]>a[j])
        {
            inversions+=mid-i+1;
            b[k]=a[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        b[k]=a[i];
        i++;
        k++;
    }
    while(j<=end)
    {
        b[k]=a[j];
        j++;
        k++;
    }
    for(i=beg,k=0;i<=end;i++,k++)
    {
        a[i]=b[k];
    }

    return inversions;
}


int modified_merge(int *arr,int beg,int end)
{
    if(beg<end)
    {
        int i;
        int mid = (beg+end)/2;
        int l_inversion=modified_merge(arr,beg,mid);
        int r_inversion=modified_merge(arr,mid+1,end);
        int c_inversion=merge(arr,beg,mid,end);
        return (l_inversion+r_inversion+c_inversion);
    }
    /* inversion in one element array is zero*/
    return 0;
}
int main()
{
    int n,i;
    printf("Enter the size of your array\t");
    scanf("%d",&n);

    int arr[n];
    printf("Enter array\n");
    
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("\ninversions are = %d\n",modified_merge(arr,0,n-1));

    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
    
    printf("\n");
    return 0;
}