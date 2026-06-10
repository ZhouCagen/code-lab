//#include <iostream>
//using namespace std;
//
//void preOrder(string middleOrder, string postOrder)
//{
//	if (middleOrder.size() > 0)
//	{
//		char ch = postOrder[postOrder.size() - 1];
//		cout << ch;
//
//		int position = middleOrder.find(ch);
//
//		preOrder(middleOrder.substr(0, position), postOrder.substr(0, position));
//		preOrder(middleOrder.substr(position + 1), postOrder.substr(position, middleOrder.size() - position - 1));
//
//	}
//}
//
//int main()
//{
//	string middleOrder, postOrder;
//	cin >> middleOrder >> postOrder;
//	preOrder(middleOrder, postOrder);
//}