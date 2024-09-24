#include<stdio.h>
int main()
{
	int price,input,sum=0,output;
	scanf("%d",&price);
	while(sum<price)
	{
		scanf("%d",&input);
		sum+=input;
	}
	output=sum-price;
	printf("%d",output);
	return 0;
}