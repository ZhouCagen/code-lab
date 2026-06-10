	/*
	前缀和:	
	前缀和可以简单理解为「数列的前 n 项的和」，是一种重要的预处理方式，能大大降低查询的时间复杂度。1
	C++ 标准库中实现了前缀和函数 std::partial_sum，定义于头文件 <numeric> 中。
*/

/*例题：有 N 个的正整数放到数组 A 里，现在要求一个新的数组 B，新数组的第 i 个数 B[i] 是原数组 A 第 0 到第 i 个数的和。*/

/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<int>A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];          
	}

	vector<int>B(N);
	B[0] = A[0];
	for (int i = 1; i < N; i++)
	{
		B[i] = B[i - 1] + A[i];
	}

	for (int num : B)	
	{
		cout << num << " ";
	}

	return 0;
}
*/

/* 
	二维/多维前缀和:
	类比一维的情形，S_{i,j} 应该可以基于 S_{i-1,j} 或 S_{i,j-1} 计算，从而避免重复计算前面若干项的和。
	但是，如果直接将 S_{i-1,j} 和 S_{i,j-1} 相加，再加上 A_{i,j}，会导致重复计算 S_{i-1,j-1} 这一重叠部分的前缀和，所以还需要再将这部分减掉。这就是 容斥原理。
	由此得到如下递推关系：S_{i,j} = A_{i,j} + S_{i-1,j} + S_{i,j-1} - S_{i-1,j-1}.  实现时，直接遍历 (i,j) 求和即可。
*/

/*洛谷 P1387 最大正方形 在一个 n*m 的只包含 0 和 1 的矩阵里找出一个不包含 0 的最大正方形，输出边长。*/

/*
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	int row, column;	
	cin >> row >> column;

	vector<vector<int>> matrix(row + 1, vector<int>(column + 1, 0));
	vector<vector<int>> prefixesand_MNatrix(row + 1, vector<int>(column + 1, 0));
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= column; j++)
		{
			cin >> matrix[i][j];
			prefixesand_MNatrix[i][j] = prefixesand_MNatrix[i - 1][j] + prefixesand_MNatrix[i][j - 1] - prefixesand_MNatrix[i - 1][j - 1] + matrix[i][j];
		}
	}

	int length = 1;
	int maxlength = 1;
	while (length <= min(row, column))
	{
		for (int i = length; i <= row; i++)
		{
			for (int j = length; j <= column; j++)
			{
				if (prefixesand_MNatrix[i][j] - prefixesand_MNatrix[i - length][j] - prefixesand_MNatrix[i][j - length] + prefixesand_MNatrix[i - length][j - length] == pow(length, 2))
				{
					maxlength = max(maxlength, length);
				}
			}
		}
		length++;
	}
	cout << maxlength;

	return 0;
}
*/

/* 三维前缀和的参考实现 */

/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int length, width, height;
	cin >> length >> width >> height;

	vector<vector<vector<int>>> array(length + 1, vector<vector<int>>(width + 1, vector<int>(height + 1, 0)));
	vector<vector<vector<int>>> prefixesand_array(length + 1, vector<vector<int>>(width + 1, vector<int>(height + 1, 0)));

	for (int i = 1; i <= length; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			for (int k = 1; k <= height; k++)
			{
				cin >> array[i][j][k];
				prefixesand_array[i][j][k] = array[i][j][k] + prefixesand_array[i - 1][j][k] + prefixesand_array[i][j - 1][k] + prefixesand_array[i][j][k - 1]
					- prefixesand_array[i - 1][j - 1][k] - prefixesand_array[i - 1][j][k - 1] - prefixesand_array[i][j - 1][k - 1] + prefixesand_array[i - 1][j - 1][k - 1];
			}
		}
	}

	return 0;
}

*/

/*
	子集和（SOS）问题	特例：子集和 DP
	维度比较大的情形，经常出现在一类叫做 子集和 (SOS, Sum Over Subsets) 的问题中。这是高维前缀和的特例。
*/

/*
	//这段代码处理了一个基于位的状态空间，并对每个状态执行了一个基于其相邻状态（通过翻转单个位得到）的累加操作。
#include <iostream>
#include <vector>
#include <cstdint> // 为了使用 std::uint64_t
using namespace std;

int main() {
	int n;
	cin >> n;

	if (n < 0 || n >= 64)
	{
		std::cerr << "n 的值太大，可能导致溢出。" << std::endl;
		return 1;
	}

	// 使用 unsigned long long 类型进行左移操作
	std::uint64_t size = static_cast<std::uint64_t>(1) << n;

	// 创建一个长度为2^n的整数向量a，用于存储用户输入的数据
	vector<int> a(size);
	for (int& x : a)
	{
		cin >> x; // 通过引用遍历向量a，从标准输入读取每个元素的值
	}

	// 创建向量a的副本ps，以避免直接修改原始数据
	auto ps = a;

	// 遍历所有维度（从0到n-1）
	for (int i = 0; i < n; ++i)
	{
		// 遍历当前维度下的所有状态（从0到2^n-1）
		for (int st = 0; st < (1 << n); ++st)
		{
			// 检查当前状态st在第i维上是否为1
			if ((st >> i) & 1)
			{
				// 如果是，则将当前状态st的值增加其相邻状态（第i维为0）的值
				// 这里使用位运算^来翻转第i位，实现状态之间的转换
				ps[st] += ps[st ^ (1 << i)];
			}
		}
	}

	for (int x : ps) {
		cout << x << ' ';
	}

	cout << std::endl;

	return 0;
}
*/

/*
	树上前缀和
	设 \textit{sum}_i 表示结点 i 到根节点的权值总和。     //\textit{sum}_i 代表sum右下角i
	然后：
	若是点权，x,y 路径上的和为 \textit{sum}_x + \textit{sum}_y - \textit{sum}_\textit{lca} - \textit{sum}_{\textit{fa}_\textit{lca}}。
	若是边权，x,y 路径上的和为 \textit{sum}_x + \textit{sum}_y - 2\cdot\textit{sum}_{lca}。

	LCA 的求法参见 最近公共祖先。
*/

/*
	差分:
	差分是一种和前缀和相对的策略，可以当做是求和的逆运算。
	这种策略的定义是令b[i] =a[i]        i=1
						   =a[i]-a[i-1] i>=2&&i<=n
*/

