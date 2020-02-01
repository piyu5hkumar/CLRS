#include<stdio.h>

void main()
{
    int n;
    printf("Enter the degree of the polynomial\t");
    scanf("%d",&n);
    int coeff[n+1];
    printf("Enter your coefficients\n");
    int i;
    for(i = 0; i < n+1 ;i++)
    {
        printf("Coefficient of x^%d\t",n-i);
        scanf("%d",&coeff[i]);
    }
    for(i = 0;i<n+1;i++)
    {
        printf("%d\t",coeff[i]);
    }
    
    int x;
    printf("\nEnter the value of x\t");
    scanf("%d",&x);

    int y = coeff[0];
    for(i = 1;i<n+1;i++)
    {
        y = coeff[i] + (x * y); 
    }

    printf("Result is %d\n",y);
}