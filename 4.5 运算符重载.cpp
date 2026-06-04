#include<iostream>
#include<string>
using namespace std;

////4.5.1 加号运算符重载
//class Person
//{
//public:
//	////成员函数实现 + 号运算符重载
//	//Person operator +(Person& p)
//	//{
//	//	Person temp;
//	//	temp.m_A = this->m_A + p.m_A;
//	//	temp.m_B = this->m_B + p.m_B;
//	//	return temp;
//	//}
//	int m_A, m_B;
//};
//////全局函数重载+号
////Person operator+ (const Person& p1, const Person& p2)
////{
////	Person temp;
////	temp.m_A = p1.m_A + p2.m_A;
////	temp.m_B = p1.m_B + p2.m_B;
////	return temp;
////}
//
//int main()
//{
//	Person p1, p2;
//	p1.m_A = 10;
//	p1.m_B = 10;
//	p2.m_A = 20;
//	p2.m_B = 20;
//	//Person p3 = p1.operator+(p2);
//	//Person p3 = p1 + p2;
//	cout << "m_A= " << p3.m_A << endl << "m_B= " << p3.m_B << endl;
//	return 0;
//}

////4.5.2 左移运算符重载	
//class Person
//{
//public:
//	friend ostream& operator<<(ostream& cout, Person& p);
// //利用成员函数重载左移运算符 p.operator<<(cout) 简化版本p<<cout 不会利用成员函数重载<<运算符，因为无法实现cout在左侧
//	int m_A, m_B;
//};
////只能用全局函数重载左移运算符 本质：operator<<(cout,p) 简化 cout<<p
//ostream & operator<<(ostream &cout, Person& p)
//{
//	cout << "m_A= " << p.m_A << "   " << "m_B =" << p.m_B << endl;
//	return cout;
//}
//int main()
//{
//	Person p;
//	p.m_A = 10;
//	p.m_B = 10;
//	cout << p;
//	return 0;
//}

////4.5.3 递增运算符重载
//class MyInteger
//{
//public:
//	friend ostream& operator<<(ostream& cout, MyInteger myint);
//	MyInteger()
//	{
//		n_Num = 0;
//	}
//	//重载前置++运算符，返回引用是为了一直对一个数据进行递增
//	MyInteger& operator++()
//	{
//		n_Num++;
//		return *this;
//	}
//	//重载后置++运算符，若返回引用—temp为局部对象的引用执行被释放，后置必须返回值
//	MyInteger operator++(int) //int代表占位，区分前置和后置。
//	{
//		MyInteger temp = *this;
//		n_Num++;
//		return temp;
//	}
//private:
//	int n_Num;
//};
//ostream& operator<<(ostream& cout, MyInteger myint)
//{
//	cout << myint.n_Num;
//	return cout;
//}
//
//void test01()
//{
//	MyInteger myint;
//	//cout << ++(++myint) << endl;
//	cout << myint++ << endl;
//	cout << myint << endl;
//}
//int main()
//{
//	test01();
//}

////4.5.4赋值运算符重载
//class Person
//{
//public:
//	Person(int age)
//	{
//		m_Age = new int(age);
//	}
//	~Person()//堆区内存重复释放，需要深拷贝解决
//	{
//		if (m_Age != NULL)
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//	}
//	Person & operator=(Person& p)
//	{
//		//编译器提供的为浅拷贝
//		// m_Age=p.m_Age;
//		//应该先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
//		if (m_Age != NULL)
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//		m_Age = new int(*p.m_Age);
//		return *this;
//	}
//	int* m_Age;
//};
//
//void test01()
//{
//	Person p1(18);
//	Person p2(20);
//	Person p3(21);
//	 p3 = p2 = p1; //赋值操作暂时不能连等，将返回值改为this指针即可
//	cout << "p1的年龄为：" << *p1.m_Age << endl;
//	cout << "p2的年龄为：" << *p2.m_Age << endl;
//	cout << "p3的年龄为：" << *p3.m_Age << endl;
//}
//int main()
//{
//	//内置可以连等
//	//int a = 10;
//	//int b = 20;
//	//int c = 30;
//	//c = b = a;
//	//cout << "a=" << a << endl << "b=" << b << endl << "c=" << c << endl;
//
//	test01();
//	return 0;
//}

////4.5.5 关系运算符重载
//class Person
//{
//public:
//	Person(string name, int age):m_name(name),m_age(age){}
//	string m_name;
//	int m_age;
//	bool operator==(Person& p) 
//	{
//		if (this->m_name == p.m_name && this->m_age == p.m_age)
//		{
//			return true;
//		}
//		return false;
//	}
//	//bool operator!=(Person& p)
//	//{
//	//	if (this->m_name == p.m_name && this->m_age == p.m_age)
//	//	{
//	//		return false;
//	//	}
//	//	return true;
//	//}
//};
//
//void test01()
//{
//	Person p1("Tom", 18);
//	Person p2("Jenny", 18);
//	if (p1 == p2)
//	{
//		cout << "p1和p2是相等的" << endl;
//	}
//	else
//	{
//		cout << "p1和p2是不相等的" << endl;
//	}
//	//if (p1 != p2)
//	//{
//	//	cout << "p1和p2是不相等的" << endl;
//	//}
//	//else
//	//{
//	//	cout << "p1和p2是相等的" << endl;
//	//}
//}
//int main()
//{
//	test01();
//}

////4.5.6函数调用运算符重载
//class MyPrint
//{
//public:
//	void operator()(string test)
//	{
//		cout << test << endl;
//	}
//};
//
//class MyAdd
//{
//public:
//	int operator()(int a, int b)
//	{
//		return a + b;
//	}
//};
//void test01()
//{
//	MyPrint myprint;
//	myprint("Hello World");
//}
//void test02()
//{
//	MyAdd myadd;
//	int ret = myadd(100, 100);
//	cout << ret << endl;
//	//匿名函数对象
//	cout << MyAdd()(100, 100) << endl;
//}
//int main()
//{
//	test01();
//	test02();
//	return 0;
//}