#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int main()
{
	int position[5],price[5],num[5],buy_position[5],buy_num[5],total = 0,input,output,sum = 0,i,j,k = 1,ans;
	char name[6][10],buy_name[6][10],end[3]={'E','N','D'};
	bool sit;
	int left[6];
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
		printf("�����밴��1�����鿴����밴��2��\n");
		scanf("%d",&ans);
		if(ans == 1)
		{
			printf("��Ҫ����ʲô��\n");
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
				if(j == 6)//δ�ҵ���Ӧͨ��
				{
					printf("����ͨ������\n");
					break;
				}
				if(strcmp(buy_name[i],name[j]) != 0)//ͨ������ﲻ��Ӧ
				{
					printf("������ͨ����ƥ�䣡\n");
					sit = false;
					break;
				}
				if(buy_num[i] > num[j])
				{
					printf("��ͨ��û���㹻�Ļ��\n");
					sit = false;
					break;
				}
				left[buy_position[i]] = 0;
				left[buy_position[i]] += buy_num[i];
				if(left[buy_position[i]] > num[j])
				{
					printf("��ͨ��û���㹻�Ļ��\n");
					sit = false;
					break;
				}
				total += price[j]*buy_num[i];
				num[j] -= buy_num[i];
				if(sit == false)break;
			}
			if(sit == true)
			{
				printf("�ܹ�%dԪ����Ͷ�ҡ�\n",total);
				scanf("%d",&input);
				sum = 0;
				sum += input;
				if(!(input == 1 || input == 2 || input == 5))
				{
					printf("��������ȷ����\n�˻�%dԪ\n",input);
					sum -= input;
				}
				while(sum<total)
				{
					scanf("%d",&input);
					sum+=input;
					if(!(input == 1 || input == 2 || input == 5))
					{
						printf("��������ȷ����\n�˻�%dԪ\n",input);
						sum -= input;
					}
				}
				output=sum-total;
				printf("����ɹ�������%dԪ��\n",output);
			}
			k = 0;
			for(i=1;i<=5;i++)k += num[i];
		}
		else if(ans == 2)
		{
			for(i=1;i<=5;i++)
			{
				if(num[i] != 0)
				{
					printf("%d��ͨ������Ʒ%s��%d��\n",position[i],name[i],num[i]);
				}
			}
		}
		else printf("û�����ѡ�\n");
	}
	return 0;
}
