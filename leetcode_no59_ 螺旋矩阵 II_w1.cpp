/*------------------------------------------------------------------|
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	旋转
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：6.6 MB, 在所有 C++ 提交中击败了46.60%的用户				
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

vector<vector<int>> generateMatrix(int n) 
{
	vector<vector<int> > res(n,vector<int>(n));
	int left = 0;
	int right = n - 1;
	int top = 0;
	int bottom = n - 1;
	int cnt = 1;

	while (cnt <= n*n)
	{
		for (int i = left; i < right; i++)
		{
			res[top][i] = cnt;
			cnt++;
		}

		for (int j = top; j < bottom; j++)
		{
			res[j][right] = cnt;
			cnt++;
		}

		if (cnt <= n * n)
		{
			for (int p = right; p > left; p--)
			{
				res[bottom][p] = cnt;
				cnt++;
			}

			for (int q = bottom; q > top; q--)
			{
				res[q][left] = cnt;
				cnt++;
			}
		}
	}
	return res;
}

int main()
{
	int n = 3;

	//
	vector<vector<int> > res(n, vector<int>(n));
	int left = 0;
	int right = n - 1;
	int top = 0;
	int bottom = n - 1;
	int cnt = 1;

	while (left <= right && top <= bottom)
	{
		for (int i = left; i < right; i++)
		{
			res[top][i] = cnt;
			cnt++;
		}

		for (int j = top; j <= bottom; j++)
		{
			res[j][right] = cnt;
			cnt++;
		}

		top++;
		right--;

		if (left <= right && top <= bottom)
		{
			for (int p = right; p > left; p--)
			{
				res[bottom][p] = cnt;
				cnt++;
			}

			for (int q = bottom; q >= top; q--)
			{
				res[q][left] = cnt;
				cnt++;
			}
		}
		left++;
		bottom--;
	}
	//
}