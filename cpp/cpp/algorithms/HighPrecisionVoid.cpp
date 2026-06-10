/*

#include<iostream>
#include <vector>
 
using namespace std;

#define MAXSIZE 0xffff // 0xffff = 65535

// 高精度加法函数，用于计算两个大整数字符串的和  
void HighPrecisionAddition(string a, string b)
{
	// 获取两个字符串的长度  
	size_t lena = a.length(), lenb = b.length();

	// 初始化两个vector来存储两个大整数的每一位数字，初始化为0  
	// MAXSIZE应该足够大以存储两个大整数的和的最大位数							
	vector<int>num1(MAXSIZE, 0), num2(MAXSIZE, 0);

	// 计数器，用于填充num1和num2  
	int count = 0;

	// 将字符串a的每一位数字逆序存储到num1中  
	for (int i = int(lena) - 1; i >= 0; i--)
	{
		num1[count++] = a[i] - '0'; // 减去'0'的ASCII码值得到实际的数字  
	}

	// 重置计数器  
	count = 0;

	// 将字符串b的每一位数字逆序存储到num2中  
	for (int i = int(lenb) - 1; i >= 0; i--)
	{
		num2[count++] = b[i] - '0'; // 同样减去'0'的ASCII码值  
	}

	// 初始化结果vector，大小与MAXSIZE相同  
	vector<int>num3(MAXSIZE, 0);

	// 确定需要遍历的最大长度，即两个数中较长的那个  
	size_t lenmax = max(lena, lenb);

	// 进位变量，初始化为0  
	int temp = 0;

	// 执行加法操作  
	for (int i = 0; i < int(lenmax); i++)
	{
		// 当前位的和等于两个数的对应位之和加上之前的进位  
		num3[i] = num1[i] + num2[i] + temp;
		// 更新进位  
		temp = num3[i] / 10;
		// 取个位数作为当前位的最终结果  
		num3[i] %= 10;
	}

	// 如果最高位还有进位，则需要在结果中额外添加一位  
	if (temp != 0)
	{
		num3[lenmax] = temp; // 将进位添加到结果的最高位  
		lenmax++; // 更新结果的最大长度  
	}

	// 打印结果，从最高位开始  
	for (int i = int(lenmax) - 1; i >= 0; i--)
	{
		cout << num3[i];
	}
	cout << endl; 
}


// 高精度减法函数，用于计算两个大整数字符串的差  
void HighPrecisionSubtraction(string a, string b)
{
	// 获取两个字符串的长度  
	size_t lena = a.length(), lenb = b.length();

	// 用于存储两个大整数的每一位数字的向量，初始化为0  
	vector<int>num1(MAXSIZE, 0), num2(MAXSIZE, 0);

	// 如果a小于b，则输出负号并交换a和b的值，同时交换它们的长度  
	if (lena < lenb || (lena == lenb && a < b))
	{
		cout << "-"; // 输出负号表示结果为负数  
		string temp = a; // 交换a和b  
		a = b;
		b = temp;

		size_t lentemp = lena; // 交换长度  
		lena = lenb;
		lenb = lentemp;
	}i

	// 将字符串a的每一位数字逆序存储到num1中  
	for (int i = 0; i < lena; ++i)
	{
		num1[i] = a[lena - 1 - i] - '0'; // 减去'0'的ASCII码值得到实际的数字  
	}

	// 将字符串b的每一位数字逆序存储到num2中  
	for (int i = 0; i < lenb; ++i)
	{
		num2[i] = b[lenb - 1 - i] - '0'; // 同样减去'0'的ASCII码值  
	}

	// 用于存储结果的向量，长度与a相同（因为a被假定为较大的数或两者相等）  
	vector<int>num3(lena, 0);

	// 执行减法操作  
	for (int i = 0; i < lena; i++)
	{
		// 如果当前位num1小于num2，则需要从高位借位  
		if (num1[i] < num2[i])
		{
			num1[i] += 10; // 加上10表示从高位借1  
			num3[i] = num1[i] - num2[i]; // 执行减法  

			// 如果需要借位，则高位减1  
			if (i + 1 < lena) // 确保不会越界  
			{
				num1[i + 1]--;
			}
			// 注意：这里假设了lena足够大，能够处理所有可能的借位情况  
			// 在实际应用中，可能需要更复杂的逻辑来处理借位到最高位后的情况  
		}
		else
		{
			num3[i] = num1[i] - num2[i]; // 直接执行减法  
		}
	}

	// 去除结果中的前导0  
	for (int i = int(lena) - 1; i >= 0; i--)
	{
		if (num3[i] == 0 && lena > 1) // 如果当前位是0且不是最后一位  
		{
			lena--; // 缩短结果长度  
		}	
		else
		{
			break; // 找到第一个非0位后停止  
		}
	}

	// 打印结果  
	for (int i = int(lena) - 1; i >= 0; i--)
	{
		cout << num3[i];
	}
	cout << endl; 
}


// 高精度乘法函数，用于计算两个大整数字符串的乘积  
void HighPrecisionMultiplication(string& a, string& b)
{
	// 使用vector存储两个大整数的每一位数字，初始化为0  
	vector<int>num1(MAXSIZE, 0), num2(MAXSIZE, 0);

	// 获取两个字符串的长度  
	size_t lena = a.length(), lenb = b.length();

	// 用于记录当前已经填充num1或num2的位数  
	int count = 0;

	// 将字符串a转换为数字并存储到num1中  
	for (int i = int(lena) - 1; i >= 0; i--)
	{
		num1[count++] = a[i] - '0'; // 减去'0'的ASCII码值得到实际的数字  
	}

	// 重置计数器  
	count = 0;

	// 将字符串b转换为数字并存储到num2中  
	for (int i = int(lenb) - 1; i >= 0; i--)
	{
		num2[count++] = b[i] - '0'; // 同样减去'0'的ASCII码值  
	}

	// 初始化结果数组num，长度为两个乘数长度之和，因为最大位数不会超过这个值  
	size_t len = lena + lenb;
	vector<int>num(len, 0);

	// 执行乘法操作  
	for (int i = 0; i < int(lena); i++)
	{
		int temp = 0; // 用于存储进位  

		// 遍历num2的每一位，与num1的当前位相乘，并加上之前的进位  
		for (int j = 0; j < int(lenb); j++)
		{
			num[i + j] += num1[i] * num2[j] + temp; // 加上进位  
			temp = num[i + j] / 10; // 更新进位  
			num[i + j] %= 10; // 取个位数  
		}

		// 处理最高位的进位  
		num[i + lenb] = temp;
	}

	// 去除结果前导0  
	for (int i = int(len) - 1; i >= 0; i--)
	{
		if (num[i] == 0 && len > 1) // 如果当前位是0且不是最后一位  
		{
			len--; // 缩短结果长度  
		}
		else
		{
			break; // 找到第一个非0位后停止  
		}
	}

	// 打印结果  
	for (int i = int(len) - 1; i >= 0; i--)
	{
		cout << num[i];
	}
	cout << endl;
}


// 定义了一个名为Division的类，用于处理高精度除法相关的操作  
class Division
{
public:
	// 比较两个大整数num1和num2的大小  
	// lena是num1的长度，用于从后向前遍历比较  
	// 返回1表示num1大于num2，-1表示num1小于num2，0表示相等  
	int MAX(int lena, vector<int>& num1, vector<int>& num2)
	{
		// 从最低位开始比较  
		for (int i = lena - 1; i >= 0; i--)
		{
			if (num1[i] > num2[i])
			{
				return 1;
			}
			else if (num1[i] < num2[i])
			{
				return -1;
			}
		}
		return 0;
	}

	// 将num2向左移动shiftlen位，结果存储在newnum2中  
	// 如果shiftlen小于等于0，则直接复制num2到newnum2  
	void ShiftLeft(int lena, vector<int>& num2, vector<int>& newnum2, int shiftlen)
	{
		if (shiftlen <= 0)
		{
			newnum2 = num2;
			return;
		}
		// 执行左移操作  
		for (int i = lena - 1; i >= 0; i--)
		{
			if (i - shiftlen >= 0)
			{
				newnum2[i] = num2[i - shiftlen];
			}
			else
			{
				newnum2[i] = 0;
			}
		}
	}

	// 从num1中减去newnum2，处理借位  
	void Substract(int lena, vector<int>& num1, vector<int>& newnum2)
	{
		// 从最低位开始减法操作  
		for (int i = 0; i < lena; i++)
		{
			num1[i] -= newnum2[i];
			if (num1[i] < 0)
			{
				// 如果当前位小于0，则向上一位借1  
				num1[i] += 10;
				num1[i + 1]--;
			}
		}
	}
};


// 高精度除法的实现函数  
void HighPrecisionDevision(string a, string b)
{
	// 除数不能为0  
	if (b == "0")
	{
		cout << "输入错误 0不能作为除数" << endl;
		return;
	}

	// 使用vector存储大整数，初始化为0  
	vector<int>num1(MAXSIZE, 0), num2(MAXSIZE, 0), num(MAXSIZE, 0);

	size_t lena = a.length(), lenb = b.length();

	if (lena < lenb || (lena == lenb && a <= b))
	{
		cout << "0" << endl;
		return;
	}


	size_t Shiftlen = lena - lenb; // 初始移位长度  

	// 将字符串转换为数字存储到vector中  
	for (int i = 0; i < int(lena); i++)
	{
		num1[i] = a[lena - i - 1] - '0';
	}

	for (int i = 0; i < int(lenb); i++)
	{
		num2[i] = b[lenb - i - 1] - '0';
	}

	Division division; // 创建Division对象  
	vector<int>movednum2(MAXSIZE, 0); // 用于存储左移后的除数  

	int first_nonZero = 0; // 记录商的第一个非零位的位置  

	// 进行除法操作  
	while (division.MAX(int(lena), num1, num2) >= 0)
	{
		division.ShiftLeft(int(lena), num2, movednum2, int(Shiftlen)); // 将除数左移  

		// 尝试从被除数中减去左移后的除数，直到不能减为止  
		while (division.MAX(int(lena), num1, movednum2) >= 0)
		{
			division.Substract(int(lena), num1, movednum2);
			num[Shiftlen]++; // 对应位上的商加1  
		}

		// 记录商的第一个非零位  
		if (first_nonZero == 0 && num[Shiftlen] != 0)
		{
			first_nonZero = int(Shiftlen);
		}

		Shiftlen--; // 继续减小移位长度  
	}

	// 从第一个非零位开始打印商  
	for (int i = first_nonZero; i >= 0; i--)
	{
		cout << num[i];
	}

	cout << endl;

	return;
}

// 定义了一个名为Mode的类，用于处理高精度取模相关的操作 
class Mode
{
public:
	// 比较两个大整数num1和num2的大小  
	// lena是num1的长度，用于从后向前遍历比较  
	// 返回1表示num1大于num2，-1表示num1小于num2，0表示相等  
	int MAX(int lena, vector<int>& num1, vector<int>& num2)
	{
		// 从最低位开始比较  
		for (int i = lena - 1; i >= 0; i--)
		{
			if (num1[i] > num2[i])
			{
				return 1;
			}
			else if (num1[i] < num2[i])
			{
				return -1;
			}
		}
		return 0;
	}

	// 将num2向左移动shiftlen位，结果存储在newnum2中  
	// 如果shiftlen小于等于0，则直接复制num2到newnum2  
	void ShiftLeft(int lena, vector<int>& num2, vector<int>& newnum2, int shiftlen)
	{
		if (shiftlen <= 0)
		{
			newnum2 = num2;
			return;
		}
		// 执行左移操作  
		for (int i = lena - 1; i >= 0; i--)
		{
			if (i - shiftlen >= 0)
			{
				newnum2[i] = num2[i - shiftlen];
			}
			else
			{
				newnum2[i] = 0;
			}
		}
	}

	// 从num1中减去newnum2，处理借位  
	void Substract(int lena, vector<int>& num1, vector<int>& newnum2)
	{
		// 从最低位开始减法操作  
		for (int i = 0; i < lena; i++)
		{
			num1[i] -= newnum2[i];
			if (num1[i] < 0)
			{
				// 如果当前位小于0，则向上一位借1  
				num1[i] += 10;
				num1[i + 1]--;
			}
		}
	}
};


void HighPrecisionMode(string a, string b)
{
	// 除数不能为0  
	if (b == "0")
	{
		cout << "输入错误 0不能作为除数" << endl;
		return;
	}

	// 使用vector存储大整数，初始化为0  
	vector<int>num1(MAXSIZE, 0), num2(MAXSIZE, 0), num(MAXSIZE, 0);

	size_t lena = a.length(), lenb = b.length();

	if (lena < lenb || (lena == lenb && a <= b))
	{
		cout << a << endl;
		return;
	}
	size_t Shiftlen = lena - lenb; // 初始移位长度  

	// 将字符串转换为数字存储到vector中  
	for (int i = 0; i < int(lena); i++)
	{
		num1[i] = a[lena - i - 1] - '0';
	}

	for (int i = 0; i < int(lenb); i++)
	{
		num2[i] = b[lenb - i - 1] - '0';
	}

	Mode mode; // 创建Division对象  
	vector<int>movednum2(MAXSIZE, 0); // 用于存储左移后的除数  

	// 进行除法操作  
	while (mode.MAX(int(lena), num1, num2) >= 0)
	{
		mode.ShiftLeft(int(lena), num2, movednum2, int(Shiftlen)); // 将除数左移  

		// 尝试从被除数中减去左移后的除数，直到不能减为止  
		while (mode.MAX(int(lena), num1, movednum2) >= 0)
		{
			mode.Substract(int(lena), num1, movednum2);
		}
		Shiftlen--; // 继续减小移位长度  
	}

	bool NonZero = false;

	for (int i = int(lena) - 1; i >= 0; i--)
	{
		if (num1[i] != 0)
		{
			NonZero = true;
		}

		if (NonZero == true)
		{
			cout << num1[i];
		}
	}
	if (NonZero == false)
	{
		cout << "0";
	}

	cout << endl;

	return;
}



int main()
{
	string a, b;
	cin >> a >> b;
	HighPrecisionAddition(a, b);
	HighPrecisionSubtraction(a, b);
	HighPrecisionMultiplication(a, b);
	HighPrecisionDevision(a, b);
	HighPrecisionMode(a, b);
	return 0;
}

*/