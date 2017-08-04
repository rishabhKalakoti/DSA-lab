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
  // sort
  int temp, j, index;
  int hPtr=0;
  for(i=0; i<n; i++)
  {
    temp=arr[hPtr];
    index=hPtr;
    for(j=hPtr; j<n; j++)
    {
      if(arr[j]<temp)
      {
        temp=arr[j];
        index=j;
      }
    }
    arr[index]=arr[i];
    arr[i]=temp;
    hPtr++;
  }
  /**
  for(i=0; i<n; i++)
  {
    printf("%d ", arr[i]);
  }
  **/
  printf("smallest: %d\nsecond smallest:%d\n", arr[0], arr[1]);
  printf("largest: %d\nsecond largest:%d\n", arr[n-1], arr[n-2]);
}
