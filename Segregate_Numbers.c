/*
	Sort +ve and -ve numbers without changing order of +ve and -ve numbers in array
	(like if 12 comes before 7 then after sort order is 12 then 7)
*/

#include<stdio.h>
void main()
{
	int a[8]={-10,12,7,-3,-15,43,22,-8};
	int i,j,k;
	int start=0,end,temp;
	for(i=0;i<8;i++)
	{
		if(a[i]>=0)
		{
			start=i;
			for(j=start+1;j<8;j++)
			{
				if(a[j]<0)
				{
					end=j;
					break;
				}
			}
			if(j!=8)
			{
				temp=a[j];
				for(k=end;k>start;k--)
				{
					a[k]=a[k-1];
				}
				a[start]=temp;
			}
		}
	}
	for(i=0;i<8;i++)
	{
		printf("%d\n",a[i]);
	}
}