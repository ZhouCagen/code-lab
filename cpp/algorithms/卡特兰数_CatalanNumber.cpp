/*
	Catalan 数列：
	Catalan 数列 H_n 可以应用于以下问题：
		1: 有 2n 个人排成一行进入剧场。入场费 5 元。其中只有 n 个人有一张 5 元钞票，另外 n 人只有 10 元钞票，剧院无其它钞票。问有多少种方法使得只要有 10 元的人买票，售票处就有 5 元的钞票找零？ H(n)
				思路：5元钞票的人总是要大于或等于10元钞票的人 即 C_2n(n)-C_2n(n-1)

		   同理 还书借书问题：在图书馆一共2n个人在排队，n个还《面试宝典》一书，n个在借《面试宝典》一书，图书馆此时没有了面试宝典了，求他们排队的总数？ H(n)
		2：由 n 个 +1 和 n 个 -1 组成的 2n 个数 a_1,a_2,……,a_{2n}，其部分和满足 a_1+a_2+……+a_k≥0（k=1,2,3,……,2n），有多少个满足条件的数列？  H(n)
		   同理 括号匹配：由1对括号，可以组成一种合法括号序列：()。 由2对括号，可以组成两种合法括号序列：()()、(())。由n对括号组成的合法括号序列一共有多少种？ H(n) 
				单调路径：有一个大小为 n*n 的方格图左下角为 (0, 0) 右上角为 (n, n)，从左下角开始每次都只能向右或者向上走一单位，不走到对角线 y=x 上方（但可以触碰）的情况下到达右上角有多少可能的路径？ H(n)
				  01序列：给出一个n，要求一个长度为2n的01序列，使得序列的任意前缀中1的个数不少于0的个数，有多少个不同的01序列?

		3：在圆上选择 2n 个点，将这些点成对连接起来使得所得到的 n 条线段不相交的方法数？ H(n)
		      思路：（递归分治思想）
					1.以其中一个点为基点，编号为 ‘0’ ，然后按顺时针方向将其他点依次编号。
					2.那么与编号为 ‘0’ 相连的点的编号一定是奇数（否则，这两个编号间含有奇数个点，势必会有个点被孤立）。即把编号为 ‘0’ 的点与任意一个编号为奇数的点相连形成一条线段。
					3.设选中的 ‘0’ 点为基点A，与它连接的点为B，那么A和B将所有点分成两个部分，一部分位于A、B的左边，另一部分位于A、B的右边。然后分别对这两部分求解即可。
					4.设问题的解f(n)，那么f(n) = f(0)*f(n-1) + f(1)*f(n-2) + f(2)*f(n-3) + …+f(n-2)*f(1) + f(n-1)*f(0)。
					其中，f(0)*f(n-1)表示编号0的点与编号1的点相连，此时位于它们右边的点的个数为0(可以连成0条线段)，而位于它们左边的点为2n-2（可以连成n-1条线段）。依次类推。

		4：高矮排队问题：2n个高矮不同的人,排成两排,每排必须是从矮到高排列,而且第二排比对应的第一排的人高,问排列方式有多少种?  H(n)
			
		5：一个栈（无穷大）的进栈序列为 1,2,3,……,n 有多少个不同的出栈序列？ H(n)
		   同理 摞碗问题：一共有n个不同的碗，洗前也是摞成一摞的，也许因为小妹贪玩而使碗拿进碗橱不及时，姐姐则把洗过的碗摞在旁边，问：小妹摞起的碗有多少种可能的方式？ H(n)
		   同理 汽车胡同加油问题：一个汽车队在狭窄的路面上行驶，不得超车，但可以进入一个死胡同去加油，然后再插队行驶，共有n辆汽车，问共有多少种不同的方式使得车队开出城去？ H(n)

		6：n 个结点可构造多少个不同的二叉树？ H(n)
		
		7：满二叉树个数：n+1个叶子的满二叉树个数为多少？ H(n)
			  思路：（递归分治思想）
					1. 可以这样考虑，根肯定会占用一个结点，那么剩余的n-1个结点可以有如下的分配方式，T(0,n−1) ,T(1,n−2) ,…… ,T(n−1,0)设T(i,j)表示根的左子树含i个结点，右子树含j个结点。
					2.然后对于根结点情况为T(i,j)的左子树再有如下分配方式：T(i-1, 0)T(0,i−1),T(1,i−2),...,T(i−1,0)，其右子树分配方式：T(0,j−1),T(1,j−2),...,T(j−1,0)
					3.设问题的解为f(n)，那么f(n) = f(0)*f(n-1) + f(1)*f(n-2) + …+ f(n-2)*f(1) + f(n-1)*f(0)。假设f(0) = 1，那么f(1) = 1, f(2) = 2, f(3) = 5。结合递推式，不难发现f(n)等于H(n)。

		8：凸多边形划分：在一个n边形中，通过不相交于n边形内部的对角线，把n边形拆分为若干个三角形，问有多少种拆分方案？  H(n-2)
			  思路：（递归分治思想）
					1.以凸多边形的一边为基，设这条边的2个顶点为A和B。从剩余顶点中选1个，可以将凸多边形分成三个部分，中间是一个三角形，左右两边分别是两个凸多边形，然后求解左右两个凸多边形。
					2.设问题的解f(n)，其中n表示顶点数，那么f(n)=f(2)*f(n-1)+f(3)*f(n-2)+……+f(n-2)*f(3)+f(n-1)*f(2)。
					其中，f(2)*f(n-1)表示：三个相邻的顶点构成一个三角形，另外两个部分的顶点数分别为2（一条直线两个点）和n-1。
					其中，f(3)*f(n-2)表示：将凸多边形分为三个部分，左右两边分别是一个有3个顶点的三角形和一个有n-2个顶点的多边形。
					3.设f(2) = 1，那么f(3) = 1, f(4) = 2, f(5) = 5。结合递推式，不难发现f(n) 等于H(n-2)。

		9: 矩阵链乘： P=a1×a2×a3×……×an，依据乘法结合律，不改变其顺序，只用括号表示成对的乘积，试问有几种括号化的方案？H(n-1)
	  
	   10: 填充阶梯图形：用n个长方形填充一个高度为n的阶梯状图形的方法个数？
			  思路：（递归分治思想）
					1.把高度为n-1的阶梯状图形，塞进高度为n的阶梯状图形，把高度为n的阶梯状图形分为几个部分。设问题的解f(n)，其中n表示高度为n的阶梯状图形或n个长方形。
					2.先来看n=1，易得f(1)=1；同理f(2)=2。其中f(1)不仅表示高度为1的阶梯状图，而且表示长或宽有一条为1且另一条不等于n的长方形。
					3.那n=3呢？其实，n=3即在n=2的阶梯图形上再添加一个高度为1宽度为3（或高度为3宽度为1）的长方形，而且只有两种添加方法，即要么在左边添加，要么在上边添加，这样才能构成一个高度为n=3的阶梯状图形。
					4.我们设f(0)=1。f(0)代表：一边为n，一边为1的长方形。
					5.那么f(3)=f(0)*f(2)+f(1)*f(1)+f(2)*f(0)=5。
					其中，f(0)*f(2)表示：高度为3的阶梯状图形含有这两个部分，一个部分是高度为2的阶梯状图形，另外一个部分是一边为3一边为1的长方形。
					其中，f(1)*f(1)表示：高度为3的阶梯状图形含有这两个部分，都是高度为1的阶梯状图形。
					6.那么f(4)=f(0)*f(3)+f(1)*f(2)+f(2)*f(1)+f(3)*f(0)=14。
					其中，f(0)*f(3)表示：高度为4的阶梯状图形含有这两个部分，一个部分是高度为3的阶梯状图形，另外一个部分是一边为4一边为1的长方形。
					其中，f(1)*f(2)表示：高度为4的阶梯状图形含有这两个部分，一个部分是高度为1的阶梯状图形或者长或宽有一条为1且另一条不等于n的长方形，另外一个部分是高度为2的阶梯状图形。


	通项公式1：H_n=1/(n+1) *(2n__n) =1/(n+1)​ *C_2n(n)=(2n)!/[(n+1)!*n!]
	通项公式2：H_n=1/(n+1) *Σ(i=0～n)(n__i)²=1/n+1 *Σ(i=0～n)[C_n(i)]
	递推公式1：H_n=[2*(2n-1)/n+1]*H_(n-1)   
	递推公式2：H_n+1=Σ(i=0～n)[H_i*H_(n-i)]      即：H(n)= H(0)*H(n-1)+H(1)*H(n-2) + … + H(n-1)H(0) (n>=2)
	性质：H_n=(2n__n)-(2n__n-1)=C_2n(n)-C_2n(n-1)
	逐渐增长：H_n ～ 4^n/[n^(3/2) * √π]

	Catalan数常用公式： H_n={	 Σ(i=1～n) H_(i-1)*H_(n-i)  n≥2,n∈N*
							{	             1				 n=0,1
						H_n=(4n-2)/n+1 *H_(n-1)
						H_n=(2n__n)-(2n__n-1)
 
*/

//Catalan代码实现 

/*
#include <iostream>
#include <vector>
using namespace std;


long long catalan_Recursion_First(int n)
{
	if (n <= 1)return 1;

	vector<long long>total(n + 1, 0);
	total[0] = total[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			total[i] += (total[j] * total[i - j - 1]);
		}
	}

	long long result = total[n];

	return result;
}

long long catalan_Recursion_Second(int n)
{
	if (n <= 1)return 1;

	vector<long long>total(n + 1, 0);
	total[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		total[i] = total[i - 1] * (4 * i - 2) / (i + 1);
	}

	long long result = total[n];

	return result;
}

unsigned long long combination(int n, int k)
{
	vector<vector<unsigned long long>> C(n + 1, vector<unsigned long long>(k + 1, 0));

	for (int i = 0; i <= n; i++)
	{
		C[i][0] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= min(i, k); j++)
		{
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
	}

	return C[n][k];
}

 //H_n = 1/(n+1)​ *C_2n(n) 
unsigned long long catalan_Formula_First(int n)
{
	unsigned long long result = combination(2 * n, n) / (n + 1);

	return result;
}


unsigned long long Factorial(int n)
{
	if (n < 0) return 0;

	else if (n == 0 || n == 1) return 1;

	else return n * Factorial(n - 1);
}


 //H_n = (2n)!/[(n+1)!*n!] 
unsigned long long catalan_Formula_Second(int n)
{
	unsigned long long result = Factorial(2 * n) / (Factorial(n + 1) * Factorial(n));

	return result;
}

 //H_n = 1/n+1 *Σ(i=0～n)[C_n(i)] 
unsigned long long catalan_Formula_Third(int n)
{
	unsigned long long sum = 0;
	for (int i = 0; i <= n; i++)
	{
		sum += static_cast<unsigned long long>(pow(combination(n, i), 2));
	}

	unsigned long long result = sum / (n + 1);

	return result;
}

int main()
{
	int n;
	cin >> n;

	cout << "Catalan_Recursion_First： " << catalan_Recursion_First(n) << endl;

	cout << "Catalan_Recursion_Second：" << catalan_Recursion_Second(n) << endl;

	cout << "Catalan_Formula_First：" << catalan_Formula_First(n) << endl;

	cout << "Catalan_Formula_Second：" << catalan_Formula_Second(n) << endl;

	cout << "Catalan_Formula_Third：" << catalan_Formula_Third(n) << endl;
	return 0;
}
*/

