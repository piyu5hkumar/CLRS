#include<stdio.h>
#include<stdlib.h>
int *b;
void merge(int *arr,int start,int mid,int end)
{
	int i=start;
	int k=0;
	int j=mid+1;
	int l;
	while(i<=mid&&j<=end)
	{
		if(arr[i]<arr[j])
		{
			b[k]=arr[i];
			i++;
		}
		else
		{
			b[k]=arr[j];
			j++;
		}
		k++;
	}
	while(i<=mid)
	{
		b[k]=arr[i];
		i++;
		k++;
	}
	while(j<=end)
	{
		b[k]=arr[j];
		j++;
		k++;
	}
	for(i=start,k=0;i<=end;i++,k++)
	{
		arr[i]=b[k];
	}
}

void merge_sort(int *arr,int start,int end)
{
	if(start<end)
	{
		int mid=(start+end)/2;
		merge_sort(arr,start,mid);
		merge_sort(arr,mid+1,end);
		merge(arr,start,mid,end);
	}
}


int main()
{
	int n;
	printf("Enter total number of elements\t");
	scanf("%d",&n);
	int *arr=(int *)malloc(n*sizeof(int));
	b=(int *)malloc(n*sizeof(int));
	
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	merge_sort(arr,0,n-1);
	
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
