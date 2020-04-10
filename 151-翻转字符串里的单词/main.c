//AC, time58%, mem100%
#include <stdio.h>
void myOutput(char *s, int len, char *result, int loc)
{
	for (int i = 0; i < len; i++)
	{
		result[loc + i] = s[i];
	}
	result[loc + len] = '\0';
	//printf("Add word : %s \n", result);
}
char *reverseWords(char *s)
{
	int len = 0;
	for (len = 0; s[len] != '\0'; len++)
		;
	char result[len + 1];
	int wordLen = 0;
	int inWord = 0;
	int loc = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		//printf("\'%c\' : %d : %d\n", s[i], i, inWord);
		if (s[i] == ' ')
		{
			inWord = 0;
		}
		else
		{
			inWord = 1;
		}

		if (inWord == 0) //如果没有在处理一个单词
		{
			if (s[i + 1] != ' ' && s[i + 1] != '\0')
			{
				myOutput(&s[i + 1], wordLen, result, loc);
				//printf("Current location is : %d \nCurrent char is \'%c\' \n", i, s[i + 1]);
				loc += wordLen;
				//printf("len : %d\n", wordLen);
				result[loc++] = ' ';
			}
			wordLen = 0;
		}
		else
		{
			wordLen++;
			if (i == 0)
			{
				myOutput(&s[i], wordLen, result, loc);
				//printf("Current location is : %d \nCurrent char is \'%c\' \n", i, s[i + 1]);
				loc += wordLen;
				//printf("len : %d\n", wordLen);
				result[loc++] = ' ';
				inWord = 0;
				wordLen = 0;
			}
		}
	}
	result[loc > 0 ? --loc : 0] = '\0';
	memcpy(s, result, strlen(result) + 1);
	return s;
}
int main()
{
	char in[100] = "a good   example";
	printf("%s\n", in);
	printf("%s", reverseWords(in));
	return 0;
}