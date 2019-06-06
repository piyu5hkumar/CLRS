#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int*,int,int);
void merge(int*,int,int,int);
int k;

void merge_sort_insertion(int *arr,int beg,int end)
{
	if(end-beg +1 > k)
	{
		
		int div = beg+k-1;
		//printf("\nbeg = %d , div = %d , end = %d",beg,div,end);
		insertion_sort(arr,beg,div);
		merge_sort_insertion(arr,div+1,end);
		merge(arr,beg,div,end);
		int i;
		printf("\nsorted array between %d to %d\n",beg,div);
		for(i=beg;i<=div;i++)
		{
			printf("%d\t",arr[i]);
		}
		printf("\nsorted array between %d to %d\n",div+1,end);
		for(i=div+1;i<=end;i++)
		{
			printf("%d\t",arr[i]);
		}
		printf("\nafter mergeing array from %d to %d\n",beg,end);
		for(i=beg;i<=end;i++)
		{
			printf("%d\t",arr[i]);
		}
		printf("\n");
	}
	else if(beg<=end)
	{
		int i;
		insertion_sort(arr,beg,end);
		printf("\nlast sorted array is from %d to %d\n",beg,end);
		for(i=beg;i<=end;i++)
		{
			printf("%d\t ",arr[i]);
		}
	printf("\n");
		
	}
	else
	{
		return;
	}	
}

void insertion_sort(int *arr,int beg,int end)
{
	int i,j,key;
	for(i=beg+1;i<=end;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=beg&&key<arr[j])
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

void merge(int *arr,int beg,int div,int end)
{
	int i=beg;
	int j=div+1;
	int k=0;
	int b[end-beg+1];
	while(i<=div&&j<=end)
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
	while(i<=div)
	{
		b[k]=arr[i];
		i++;
		k++;
	}
	while(j<=end)
	{
		b[k]==arr[j];
		j++;
		k++;
	}
	
	for(i=beg,k=0;i<=end;i++,k++)
	{
		arr[i]=b[k];
	}
}

int main()
{
	int n;
//	printf("Enter total number of elements\t");
n=9;
//	scanf("%d",&n);
	int a[]={9,88,17,62,5,14,-53,211,981};//(int *)malloc(n*sizeof(int));
	int i;
//	for(i=0;i<n;i++)
//	{
//		scanf("%d",&a[i]);
//	}
//	printf("Enter division value of k\t");
//	scanf("%d",&k);
	k=4;
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");	merge_sort_insertion(a,0,n-1);

	printf("\nyour array after sorting is \n");
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
