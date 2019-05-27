#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	printf("Enter total number of elements\t");
	scanf("%d",&n);
	int *a=(int *)malloc(n*sizeof(int));
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int j,min,pos,temp;
	
	for(i=0;i<n-1;i++)
	{
		min=a[i];
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<min)
			{
				min=a[j];
				pos=j;
			}
		}
		temp=a[i];
		a[i]=a[pos];
		a[pos]=temp;
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
