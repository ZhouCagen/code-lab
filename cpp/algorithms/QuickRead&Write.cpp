#include <iostream>
using namespace std;


/*
	读入优化：
	scanf 和 printf 依然有优化的空间，这就是本章所介绍的内容——读入和输出优化。
	注意，本页面中介绍的读入和输出优化均针对整型数据，若要支持其他类型的数据（如浮点数），可自行按照本页面介绍的优化原理来编写代码。
*/

/*
	原理：
	众所周知，getchar 是用来读入 1 byte 的数据并将其转换为 char 类型的函数，且速度很快，故可以用「读入字符——转换为整型」来代替缓慢的读入。
	每个整数由两部分组成——符号和数字。整数的 '+' 通常是省略的，且不会对后面数字所代表的值产生影响，而 '-' 不可省略，因此要进行判定。
	10 进制整数中是不含空格或除 0~9 和正负号外的其他字符的，因此在读入不应存在于整数中的字符（通常为空格）时，就可以判定已经读入结束。
*/

/*
int read()
{
	int x = 0, w = 1;
	char ch = 0;
	while (ch < '0' || ch>'9')
	{
		if (ch == '-') w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + (ch - '0');
		ch = getchar();
	}

	return x * w;

}
*/


/*
	输出优化：
	原理：同样是众所周知，putchar 是用来输出单个字符的函数。因此将数字的每一位转化为字符输出以加速。
	要注意的是，负号要单独判断输出，并且每次 %（mod）取出的是数字末位，因此要倒序输出。
*/

/*
void write(int x)
{
	if (x < 0)
	{
		x = -x;
		putchar('-');
	}
	if (x > 9)
	{
		write(x / 10);
	}
	putchar(x % 10 + '0');
}
*/

/* 但是递归实现常数是较大的，我们可以写一个栈来实现这个过程。*/

/*
void write(int x)
{
	static int sta[35];
	int top = -1;
	while (x != 0)
	{
		sta[++top] = x % 10;
		x /= 10;
	}
	while (top != -1)
	{
		putchar(sta[top--] + '0');

	}
}
*/

/* 完整代码实现如下*/

/*
int read()
{
	int x = 0, w = 1;
	char ch = 0;
	while (ch < '0' || ch>'9')
	{
		if (ch == '-') w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + (ch - '0');
		ch = getchar();
	}

	return x * w;

}

void write(int x)
{
	if (x < 0)
	{
		x = -x;
		putchar('-');
	}
	if (x > 9)
	{
		write(x / 10);
	}
	putchar(x % 10 + '0');
}

int main()
{
	cout << "请输入一个整数：";
	int number = read();	
	cout << "您输入的整数是：";
	write(number);
	cout << endl;

	return 0;
}
*/


/*
int read()
{
	int x = 0, w = 1;
	char ch = 0;
	while (ch < '0' || ch>'9')
	{
		if (ch == '-') w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + (ch - '0');
		ch = getchar();
	}

	return x * w;

}

void write(int x)
{
	static int sta[35];
	int top = -1;
	while (x != 0)
	{
		sta[++top] = x % 10;
		x /= 10;
	}
	while (top != -1)
	{
		putchar(sta[top--] + '0');

	}
}

int main()
{
	cout << "请输入一个整数：";
	int number = read();
	cout << "您输入的整数是：";
	write(number);
	cout << endl;

	return 0;
}
*/

/*
	更快的读入/输出优化：
	通过 fread 或者 mmap 可以实现更快的读入。
	fread 能将需要的文件部分读入内存缓冲区。mmap 则会调度内核级函数，将文件一次性地映射到内存中，类似于可以指针引用的内存区域。
	所以在日常程序读写时，只需要重复读取部分文件可以使用 fread，因为如果用 mmap 反复读取一小块文件，做一次性内存映射并且内核处理 page fault 的花费会远比使用 fread 的内核级函数调度大。
	同时 fread 和 mmap 由于是整段整段读取、写入，所以比 getchar()/putchar() 要快的多。并且 mmap 确保了进程间自动共享，存储区如果可以也会与内核缓存分享信息，确保了更少的拷贝操作。
	fread 类似于参数为 "%s" 的 scanf，不过它更为快速，而且可以一次性读入若干个字符（包括空格换行等制表符），如果缓存区足够大，甚至可以一次性读入整个文件。
	对于输出，我们还有对应的 fwrite 函数。
	std::size_t fread(void* buffer, std::size_t size, std::size_t count, std::FILE* stream);
	std::size_t fwrite(const void* buffer, std::size_t size, std::size_t count, std::FILE* stream);

	使用示例：fread(Buf, 1, SIZE, stdin)，表示从 stdin 文件流中读入 SIZE 个大小为 1 byte 的数据块到 Buf 中。
	读入之后的使用就跟普通的读入优化相似了，只需要重定义一下 getchar。它原来是从文件中读入一个 char，现在变成从 Buf 中读入一个 char，也就是头指针向后移动一位。
	fwrite 也是类似的，先放入一个 OutBuf[MAXSIZE] 中，最后通过 fwrite 一次性将 OutBuf 输出。

	mmap 是 linux 系统调用，可以将文件一次性地映射到内存中。在一些场景下有更优的速度。
	注意 mmap 不能在 Windows 环境下使用（例如 CodeForces 的 tester），同时也不建议在正式赛场上使用，可以在卡常时使用。在使用前要引入 fcntl.h，unistd.h，sys/stat.h 与 sys/mman.h。
	读入示例：首先要获取文件描述符 fd，然后通过 fstat 获取文件信息以得到文件大小，此后通过 char *pc = (char *) mmap(NULL, state.st_size, PROT_READ, MAP_PRIVATE, fd, 0); 将指针 *pc 指向我们的文件。可以直接用 *pc ++ 替代 getchar()。
	当我们要提交不使用文件操作的题目时，可以将 fd 设为 0，表示从 stdin 读入。但是，对 stdin 使用 mmap 是极其危险的行为，同时不能在终端输入，我们不建议您这么做。
*/
