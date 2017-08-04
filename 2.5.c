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
  printf("Enter the no of largest to find:\t");
  int l;
  scanf("%d", &l);
  
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
  printf("%d largest numbers in order are:\n", l);
  for(i=0; i<l; i++)
  {
    printf("%d ", arr[n-1-i]);
  }
  printf("\n");
}
