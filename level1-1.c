#include<stdio.h>
int main()
{
	int position,price,num,i;
	char name;
	scanf("%s%d%d%d",&name,&position,&price,&num);
	printf("%d:",position);
	for(i=0;i<num;i++)
	{
		printf("%s",&name);
	}
	printf(" %d",price);
	return 0;
}
