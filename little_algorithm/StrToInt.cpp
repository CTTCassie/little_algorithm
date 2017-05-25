#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

enum state
{
	Valid,
	Invalid,
};
bool stat=Valid;  //ȫ�ֱ�������ʶ�ǿմ�����"0"
class Solution {
public:
	int StrToInt(const char *str) 
	{
		stat=Invalid;
		int num=0;
		const char *digit=str;
		if(str != NULL && *str != '\0')
		{
			int flag=1;  //����λ���Ƿ����+,-��
			if(*digit == '+') 
				digit++;
			else if(*digit == '-')
			{
				flag=-1;
				digit++;
			}
			while(*digit != '\0')
			{
				//�Ƿ���ڷǷ��ַ�
				if(*digit >= '0' && *digit <= '9')
				{
					num=10*num+flag*(*digit-'0');
					//��������
					if((flag == 1) && (num > 0x7FFFFFFF) \
						|| (flag == -1) && (num < (size_t)0x80000000))
					{
						num=0;
						break;
					}
					digit++;
				}
				else
				{//�Ƿ��ַ�,��������ĸ���ո�
					digit++;
				}
			}
			if(*digit == '\0')
			{
				stat=Valid;
			}
		}
		return num;
	}
};

int main()
{
	Solution so;
	//char * str="+abc12  34qwz5?6@7xyz";
	//char *str="0";  //�մ�stat=1������"0"stat=0
	char *str="-123";
	long long num=so.StrToInt(str);
	cout<<stat<<" "<<num<<endl;
	system("pause");
	return 0;
}