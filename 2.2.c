#include<stdio.h>
void main()
{
  int n;
  printf("Enter the no of elements:\t");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the values of the array.\n");
  int i=0;
  for(i=0; i<n; i++)
  {
    scanf("%d", &arr[i]);
  }
  int temp;
  for(i=0; i<n/2; i++)
  {
    temp=arr[i];
    arr[i]=arr[n-i-1];
    arr[n-i-1]= temp;
  }
  
  for(i=0; i<n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
