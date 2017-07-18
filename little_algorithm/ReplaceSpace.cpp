char *ReplaceSpace(char str[],int len,int size)
{
	assert(str);
	int count = 0;
	char *ptr = str;
	//统计空格出现的次数
	while (*ptr != '\0')
	{
		if (isspace(*ptr))
		{
			count++;
		}
		ptr++;
	}
	//计算替换之后的字符串的长度
	int newSize = len + (size-1)* count;
	char *tmp = (char *)malloc(sizeof(char)*newSize);
	memset(tmp,0,newSize);
	ptr = str;
	char *ptmp = tmp;
	while (*ptr != '\0')
	{
		if (!isspace(*ptr))   //不是空格则直接复制过去
		{
			*ptmp++ = *ptr++;
		}
		else   //是空格
		{
			int k = size;
			while (k--)  //size表明是替换几个$
			{
				*ptmp++ = '$';
			}
			ptr++;
		}
	}
	tmp[newSize] = '\0';
	return tmp;
}
void TestSpace()
{
	char str[] = "talk is cheap show me the code";
	size_t len = strlen(str);
	int size = 4;
	printf("%s\n",str);
	char *res=ReplaceSpace(str,len,size);
	printf("%s\n",res);
}