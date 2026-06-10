//#include<iostream>
//using namespace std;
//
//#define MAXSIZE 0xffff
//
//class Queue
//{
//private:
//	int front;
//	int rear;
//	unsigned long long* que;
//	int maxsize;
//public:
//	Queue() :rear(-1), front(0), maxsize(MAXSIZE)
//	{
//		que = new unsigned long long[maxsize];
//		if (que == nullptr)
//		{
//			cout << "¶¯Ì¬´æ´¢·ÖÅäÊ§°Ü" << endl;
//			exit(1);
//		}
//	}
//	~Queue()
//	{
//		delete[] que;
//	}
//	bool empty();
//	bool full();
//	void push(int x);
//	void pop();
//	unsigned long long query();
//	int size();
//};
//
//bool Queue::empty()
//{
//	return rear + 1 == front ? true : false;
//}
//
//bool Queue::full()
//{
//	return rear + 1 == maxsize ? true : false;
//}
//
//void Queue::push(int x)
//{
//	if (full())
//	{
//		cout << "¶ÓÁÐÒÑÂú" << endl;
//		exit(1);
//	}
//	else
//	{
//		que[++rear] = x;
//	}
//}
//
//void Queue::pop()
//{
//	if (empty())
//	{
//		cout << "ERR_CANNOT_POP" << endl;
//	}
//	else
//	{
//		front++;
//	}
//}
//
//unsigned long long Queue::query()
//{
//	if (!empty())
//	{
//		return que[front];
//	}
//	else
//	{
//		return -1;
//	}
//}
//
//int Queue::size()
//{
//	return rear - front + 1;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	Queue queue;
//	for (int i = 0; i < n; i++)
//	{
//		string choice;
//		cin >> choice;
//		if (choice == "1")
//		{
//			unsigned long long x;
//			cin >> x;
//			queue.push(x);
//		}
//		else if (choice == "2")
//		{
//			queue.pop();
//		}
//		else if (choice == "3")
//		{
//			if (queue.query() == -1)
//			{
//				cout << "ERR_CANNOT_QUERY" << endl;
//			}
//			else
//			{
//				cout << queue.query() << endl;
//			}
//		}
//		else if (choice == "4")
//		{
//			cout << queue.size() << endl;
//		}
//		else
//		{
//			cout << "ÊäÈë´íÎó" << endl;
//		}
//	}
//	return 0;
//}
