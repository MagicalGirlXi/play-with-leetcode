/*
 * @Author: magicgirlxi
 *
 *
 * 315 / 315 个通过测试用例
 * 状态：AC
 */
#include <stdio.h>

int trap(int *height, int heightSize)
{
	int ans = 0;
	int maxHeight = 0;
	for (int i = 0; i < heightSize; i++)
	{
		if (height[i] >= height[maxHeight])
		{
			maxHeight = i;
		}
	}
	int maxLeft = 0;
	for (int i = 0; i < maxHeight; i++)
	{
		if (height[i] < height[maxLeft])
		{
			ans += height[maxLeft] - height[i];
		}
		else
		{
			maxLeft = i;
		}
	}
	int maxRight = heightSize - 1;
	for (int i = maxRight; i > maxHeight; i--)
	{
		if (height[i] < height[maxRight])
		{
			ans += height[maxRight] - height[i];
		}
		else
		{
			maxRight = i;
		}
	}
	return ans;
}

int main()
{
	int height[12] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int heightSize = 12;
	printf("%d\n", trap(height, heightSize));
	return 0;
}
