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
	int j,key;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0&&key<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	
}
