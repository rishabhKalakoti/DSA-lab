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
  printf("Enter the no to search:\t");
  int num=0, count=0;
  scanf("%d", &num);
  for(i=0; i<n; i++)
  {
    if(arr[i]==num)
    {
      count++;
    }
  }
  printf("occurences: %d\n", count);
}
