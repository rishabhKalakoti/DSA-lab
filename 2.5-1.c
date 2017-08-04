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
  
  printf("largest %d nos are:\t", l);
  // find max, print, pop
  int index, k;
  for(i=0; i<l; i++)
  {
    int max=arr[0];
    index=0;
    for(k=0; k<n; k++)
    {
      if(arr[k]>max)
      {
        max=arr[k];
        index=k;
      }
    }
    printf("%d ", max);
    int j;
    for(j=index; j<n-1; j++)
    {
      arr[j]=arr[j+1];
    }
    n--;
  }
  printf("\n");
}
