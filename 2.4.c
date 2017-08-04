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
  printf("Enter the rotation key:\t");
  int key;
  scanf("%d", &key);
  
  int j;
  for(j=0; j<key; j++)
  {
    // rotate once
    int temp;
    temp=arr[0];
    for(i=0; i<n-1; i++)
    {
      arr[i]=arr[i+1];
    }
    arr[n-1]=temp;
  }
  // print
  printf("new:\n");
  for(i=0; i<n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
