#include<stdio.h>
#include<math.h>
void main()
{
	//inut the nos.
	int a, b;
	printf("Enter the numbers:\t");
	scanf("%d", &a);
	scanf("%d", &b);
	
	int i;
	int c=0;
	for(i=0; i<abs(b); i++)
	{
		c=c+abs(a);
	}
	int flag=0;
	if((a<0 && !(b<0)) || (!(a<0) && b<0))
		flag=1;
		
	if(flag==1)
	{
		c=~c;
		c+=1;
	}
	
	printf("result:\t%d\n", c);
}
