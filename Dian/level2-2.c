#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int main()
{
	int position[5],price[5],num[5],buy_position[5],buy_num[5],total = 0,input,output,sum = 0,i,j,k = 1,top = 0,back,l;
	char name[6][10],buy_name[6][10],end[3]={'E','N','D'},ans[10],a[10] = {'1'},b[10] = {'2'},c[10] = {'b','a','c','k'};
	bool sit = true;
	int save[3],save1[3],n,left[6];
	for(i=0;i<=5;i++)position[i]=0;
	for(i=0;i<=2;i++)save[i] = 0;
	for(i=0;i<=2;i++)save1[i] = 0;
	for(i=1;i<=5;i++)num[i] = 0;
	for(i=1;i<=6;i++)
	{
		scanf("%s",&name[i]);
		if(strcmp(name[i],end) == 0)break;
		scanf("%d%d%d",&position[i],&num[i],&price[i]);
	}
	while(k>0)
	{
		sit = true;
		printf("购物请按“1”，查看库存请按“2”，退货请按“back”\n");
		scanf("%s",&ans);
		if(strcmp(ans,a) == 0)
		{
			printf("需要购买什么？\n");
			for(i=1;i<=6;i++)
			{
				scanf("%s",&buy_name[i]);
				if(strcmp(buy_name[i],end) == 0)break;
				scanf("%d%d",&buy_position[i],&buy_num[i]);
				for(j=1;j<=6;j++)
				{
					if(buy_position[i] == position[j])
					{
						break;
					}
				}
				if(j == 6)//未找到对应通道
				{
					printf("购买通道有误！\n");
					break;
				}
				if(strcmp(buy_name[i],name[j]) != 0)//通道与货物不对应
				{
					printf("货物与通道不匹配！\n");
					sit = false;
					break;
				}
				if(buy_num[i] > num[j])
				{
					printf("该通道没有足够的货物。\n");
					sit = false;
					break;
				}
				left[buy_position[i]] = 0;
				left[buy_position[i]] += buy_num[i];
				if(left[buy_position[i]] > num[j])
				{
					printf("该通道没有足够的货物。\n");
					sit = false;
					break;
				}
				if(top < 2)
				{
					save[top] = buy_num[i];
					save1[top] = position[j];
					top++;
				}
				else
				{
					save[0] = save[1];
					save[1] = save[2];
					save[2] = buy_num[i];
					save1[0] = save1[1];
					save1[1] = save1[2];
					save1[2] = position[j];
				}
				total += price[j]*buy_num[i];
				num[j] -= buy_num[i];
				if(sit == false)break;
			}
			if(sit == true)
			{
				printf("总共%d元，请投币。\n",total);
				scanf("%d",&input);
				sum = 0;
				sum += input;
				if(!(input == 1 || input == 2 || input == 5))
				{
					printf("请输入正确的面额！\n退回%d元\n",input);
					sum -= input;
				}
				while(sum<total)
				{
					scanf("%d",&input);
					sum+=input;
					if(!(input == 1 || input == 2 || input == 5))
					{
						printf("请输入正确的面额！\n退回%d元\n",input);
						sum -= input;
					}
				}
				output=sum-total;
				printf("购买成功！找零%d元。\n",output);
			}
			k = 0;
			for(i=1;i<=5;i++)k += num[i];
		}
		else if(strcmp(ans,b) == 0)
		{
			for(i=1;i<=5;i++)
			{
				if(num[i] != 0)
				{
					printf("%d号通道有商品%s共%d个\n",position[i],name[i],num[i]);
				}
			}
		}
		else if(strcmp(ans,c) == 0)
		{
			if(save[0] == 0)printf("无购买记录！\n");
			else
			{
				for(j=2;j>=0;j--)if(save[j] != 0)break;
				i = save[j];
				l = save1[j];
				save[j] = 0;
				save1[j] = 0;
				for(j=1;j<=5;j++)
				{
					if(l == position[j])
					{
						back = price[j] * i;
						num[j] += i;
						top --;
						break;
					}
				}
				printf("撤销%d通道购买的%s货物%d个，退款%d元。\n",l,name[j],i,back);
			}
		}
		else printf("没有这个选项！\n");
	}
	return 0;
}