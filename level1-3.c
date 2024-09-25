#include<stdio.h>
#include<string.h>
int main()
{
	int position,price,num,buy_position,buy_num,total,input,output,sum,i=0;
	char name[10],buy_name[10];
	scanf("%s%d%d%d",&name,&position,&price,&num);//存放货物 
	while(num>0)
	{
		sum = 0;
		printf("需要购买什么？\n"); 
		scanf("%s%d%d",&buy_name,&buy_position,&buy_num);
		if(strcmp(name,buy_name) == 0)
		{
			if(buy_position != position)
			{
				printf("这个通道没有您想要的货物！\n");
				continue;
			}
			else if(buy_num > num)
			{
				printf("货物数量不足！\n");
				continue;
			}
			else
			{
				total = price * buy_num;
				printf("总共%d元，请投币。\n",total);
				scanf("%d",&input);
				sum += input;
				while(sum<total)
				{
					scanf("%d",&input);
					sum+=input;
				}
				output=sum-total;
				printf("购买成功！找零%d元。\n",output);
			}
		}
		else
		{
			printf("没有这个商品！\n");
			continue;
		}
		num -= buy_num;
	}
	printf("货物已卖光！");
	return 0;
}
