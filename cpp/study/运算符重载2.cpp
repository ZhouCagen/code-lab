//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	Person(int age)
//	{
//		m_Age = new int(age);
//	}
//	int* m_Age;
//	//~Person()  //本串代码会导致堆区重复释放m_Age,程序崩溃。
//	//{
//	//	if (m_Age != NULL)
//	//	{
//	//		delete m_Age;
//	//		m_Age = NULL;
//	//	}
//	//}  
//};
//void test01()
//{
//	Person p1(18);
//	cout << "p1的年龄为：" << *p1.m_Age << endl;
//	Person p2(20);
//	cout << "p2的年龄为：" << *p2.m_Age << endl;
//	p2 = p1;
//}
//
//int main()
//{
//	test01();
//	return 0;
//}