#include<stdio.h>
#include<string.h>
int main()
{
	int position,price,num,buy_position,buy_num,total,input,output,sum,i=0;
	char name[10],buy_name[10];
	scanf("%s%d%d%d",&name,&position,&price,&num);//��Ż��� 
	while(num>0)
	{
		sum = 0;
		printf("��Ҫ����ʲô��\n"); 
		scanf("%s%d%d",&buy_name,&buy_position,&buy_num);
		if(strcmp(name,buy_name) == 0)
		{
			if(buy_position != position)
			{
				printf("���ͨ��û������Ҫ�Ļ��\n");
				continue;
			}
			else if(buy_num > num)
			{
				printf("�����������㣡\n");
				continue;
			}
			else
			{
				total = price * buy_num;
				printf("�ܹ�%dԪ����Ͷ�ҡ�\n",total);
				scanf("%d",&input);
				sum += input;
				while(sum<total)
				{
					scanf("%d",&input);
					sum+=input;
				}
				output=sum-total;
				printf("����ɹ�������%dԪ��\n",output);
			}
		}
		else
		{
			printf("û�������Ʒ��\n");
			continue;
		}
		num -= buy_num;
	}
	printf("���������⣡");
	return 0;
}
