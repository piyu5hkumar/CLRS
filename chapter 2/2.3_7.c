#include<stdio.h>
#include<stdlib.h>

typedef enum boolvalues{true=1,false=0} bool;

/*

Im doing the book way of merge
but you can use my old method also they both are kinda same
and have same complexity

*/
void merge(int *arr,int beg,int mid,int end)
{
	int i;
	int n1=mid-beg+1;
	//since mid-beg will be difference only and for total we have to add 1
	int n2 =end-(mid+1) +1;
	
	int L[n1+1];
	L[n1]=INT_MAX;
	
	int R[n2+1];
	R[n2]=INT_MAX;
	
	for(i=0;i<mid-beg+1;i++)
		L[i]=arr[beg+i];
		
	for(i=0;i<(end-(mid+1)+1);i++)
		R[i]=arr[mid+1+i];
	
	int k,j;
	k=beg;
	i=0;
	j=0;
	
	while(k<=end)
	{
		if(L[i]<R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
}


void merge_sort(int *arr,int beg,int end)
{
	if(beg<end)
	{
		int mid=(beg+end)/2;
		merge_sort(arr,beg,mid);
		merge_sort(arr,mid+1,end);
		merge(arr,beg,mid,end);
	}
}


int main()
{
	int n,i,j;
	int *a;
	
	printf("Enter the size of the array\t");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	
	printf("Enter your array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	merge_sort(a,0,n-1);
	
	int x;
	printf("Enter value of x whose sum pair you want to search\t");
	scanf("%d",&x);
	
	i=0;
	j=n-1;
	bool found=false;
	while(i!=j)
	{
		if(a[i]+a[j]==x)
		{
			printf("Elements found = (%d,%d)\n",a[i],a[j]);
			found=true;
			break;
		}
		else if(a[i]+a[j] < x)
		{
			i=i+1;
		}
		else
		{
			j=j-1;
		}
	}
	if(found==false)
	{
		printf("\nsum does not exist\n");
	}
	return 0;
}
