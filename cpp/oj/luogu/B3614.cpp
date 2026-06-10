//#include<iostream>
//#define MAXSIZE 0xffff
//
//using namespace std;
//
//class Stack
//{
//private:
//	unsigned long long  top;
//	unsigned long long maxsize;
//	unsigned long long * my_s;
//public:
//	Stack() :top(-1), maxsize(MAXSIZE)
//	{
//		my_s = new unsigned long long[maxsize];
//		if (my_s == nullptr)
//		{
//			cout << "¶¯Ì¬´æ´¢·ÖÅäÊ§°Ü£¡" << endl;
//			exit(1);
//		}
//	}
//	~Stack()
//	{
//		delete[] my_s;
//	}
//	bool Empty();
//	void Pop();
//	unsigned long long Query();
//	unsigned long long Size();
//	void Push(unsigned long long x);
//};
//
//bool Stack::Empty()
//{
//	if (top < 0)
//	{
//		top - 1;
//	}
//
//	return top == -1 ? true : false;
//}
//
//void Stack::Push(unsigned long long x)
//{
//	if (top + 1 < MAXSIZE)
//	{
//		my_s[++top] = x;
//	}
//	else
//	{
//		cout << "ÂúÕ»" << endl;
//		exit(1);
//	}
//}
//
//void Stack::Pop()
//{
//	if (!Empty())
//	{
//		top--;
//	}
//	else
//	{
//		cout << "Empty" << endl;
//	}
//}
//
//unsigned long long Stack::Query()
//{
//	if (!Empty())
//	{
//		return my_s[top];
//	}
//	else
//	{
//		return -1;
//	}
//}
//
//unsigned long long Stack::Size()
//{
//	return top + 1;
//}
//
//int main()
//{
//	unsigned long long T;
//	cin >> T;
//	for (unsigned long long i = 1; i <= T; i++)
//	{
//		Stack stack;
//		unsigned long long n;
//		cin >> n;
//		for (unsigned long long j = 0; j < n; j++)
//		{
//			string choice;
//			cin >> choice;
//
//			if (choice == "push")
//			{
//				unsigned long long num;
//				cin >> num;
//				stack.Push(num);
//			}
//			else if (choice == "query")
//			{
//				if (stack.Query() == -1)
//				{
//					cout << "Anguei!" << endl;
//				}
//				else
//				{
//					cout << stack.Query() << endl;
//				}
//			}
//			else if (choice == "pop")
//			{
//				stack.Pop();
//			}
//			else if (choice == "size")
//			{
//				cout << stack.Size() << endl;
//			}
//		}
//	}
//	return 0;
//}