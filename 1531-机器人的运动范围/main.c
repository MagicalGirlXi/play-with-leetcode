/*
 * 执行用时 :
0 ms
, 在所有 C 提交中击败了
100.00%
的用户
内存消耗 :
5.1 MB
, 在所有 C 提交中击败了
100.00%
的用户
 */
/*
 * 
 */
#include <stdio.h>
int calc(int x)
{
	if (x >= 10)
	{
		return x % 10 + calc(x / 10);
	}
	else
	{
		return x;
	}
}
int move(int x, int y, int k, int m, int n, char (*visited)[105])
{
	if (x < 0 || y < 0 || x >= m || y >= n) //越界，return 0
	{
		//printf("end at %d %d \n", x, y);
		return 0;
	}
	else if (visited[x][y] == 1) // 如果已经统计过该格子，返回0
	{
		return 0;
	}
	else if (calc(x) + calc(y) > k) // 越界，return 0
	{
		printf("end at %d %d \n", x, y);
		visited[x][y] = 1;
		return 0;
	}
	else // return四个方向的move+自己
	{
		visited[x][y] = 1;
		return move(x + 1, y, k, m, n, visited) + move(x, y + 1, k, m, n, visited) + 1;
	}
}
int movingCount(int m, int n, int k)
{
	char visited[105][105] = {0};
	int count = move(0, 0, k, m, n, visited);
	return count;
}
int main()
{
	printf("%d\n", calc(10));
	printf("%d", movingCount(11, 8, 16));
	return 0;
}
