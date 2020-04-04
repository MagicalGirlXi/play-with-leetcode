/*
 * @Author: magicgirlxi
 *
 *
 * 314 / 315 个通过测试用例
 * 状态：超出时间限制
 */
#include <stdio.h>

int trap(int *height, int heightSize)
{
	int sum = 0;
	int stage = 0;
	int maxheight = -1;
	for (int i = 0; i < heightSize; i++)
	{
		if (height[i] > maxheight)
			maxheight = height[i];
	}
	for (stage = 0; stage < maxheight; stage++)
	{
		int flag = 0;
		int loc = -1;
		for (int i = 0; i < heightSize; i++)
		{
			if (height[i] > stage)
			{
				if (flag == 0) //第一根柱子出现
				{
					flag = 1;
					loc = i;
				}
				else
				{
					//printf("[i=%d, loc=%d] ", i, loc);
					sum += i - loc - 1; //计算与前一根柱子的间距
					loc = i;
				}
			}
		}
		//printf("%d\n", sum);
	}
	return sum;
}

int main()
{
	int height[12] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int heightSize = 12;
	printf("%d\n", trap(height, heightSize));
	return 0;
}
