#include<iostream>
#include<string>
using namespace std;

////4.2.1构造函数和析构函数
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Person 构造函数的调用" << endl;
//	}
//
//	~Person()
//	{
//		cout << "Person 析构函数的调用" << endl;
//	}
//};
////void test01()
////{
////	Person p;  //栈区使用完直接释放，即直接调用析构函数
////}  
//int main()
//{
//	//Person p;
//	//cout << "l" << endl;
//	//return 0;
////先调用构造函数 再输出l，在 return 0（销毁前）调用析构函数。
//}

////4.2.2 构造函数的分类和调用
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Person 无参（默认）构造函数的调用" << endl;
//	}
//	Person(int a)
//	{
//		age = a;
//		cout << "Person 有参构造函数的调用" << endl;
//	}
//	Person(const Person & p)
//	{
//		age = p.age;
//		cout << "Person 拷贝构造函数的调用" << endl;
//	}
//	~Person()
//	{
//		cout << "Person 析构函数的调用" << endl;
//	}
//	int age = 0;
//};
//
//void test01()
//{
//	//括号式调用：无参 有参 拷贝。
//	Person p1;   
//	//注意：调用默认构造函数的时候，不要加（），会默认为函数的声明，不会认为在创建对象。（函数体内部可以声明另一种函数）
//	Person p2(10);
//	Person p3(p2);
//	cout << "p2的年龄为：" << p2.age << endl;
//	cout << "p2的年龄为：" << p3.age << endl;
//
//	//显示法调用：无参 有参 拷贝。
//	Person p1;
//	Person p2 = Person(10);
//	Person p3 = Person(p2);
//	Person(10);	//匿名对象：当前行执行结束后，系统会立刻回收掉匿名对象。
//	cout << "a" << endl;
//	//注意：不要利用拷贝函数来初始化匿名函数。
//	//Person(p3); error Person p3 为重定义 编译器会认为Person(p3) = Person p3 对象声明。
//	
//	//隐式转换法：无参 有参 拷贝。
//	Person p4 = 10; //相当于写了 Person p4 = Person(10)。有参构造。
//	Person p5 = p4;	//拷贝构造。
//}
//
//int main()
//{
//	test01();
//	return 0;
//}

////4.2.3 拷贝构造函数调用时机 
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Person的默认构造函数" << endl;
//	}
//	Person(int age)
//	{
//		m_age = age;
//		cout << "Person的有参构造函数" << endl;
//	}
//	Person(const Person& p)
//	{
//		m_age = p.m_age;
//		cout << "Person的拷贝构造函数" << endl;
//	}
//	~Person()
//	{
//		cout << "Person的析构函数" << endl;
//	}
//	int m_age;
//}; 
////1.使用一个已经创建完毕的对象来初始化一个新对象。
//void test01()
//{
//	Person p1(20);
//	Person p2(p1);
//	cout << "P2的年龄为：" << p2.m_age << endl;
//
//}
////2.值传递的方式给函数参数传值。
//void doWork1(Person p)
//{
//	//实参传给形参时会调用Person拷贝构造函数，值传递的本质时临时创建一个副本将值拷贝。
//	//隐式转换法：Person p1=p 即为拷贝构造函数。
//}
//void test02()
//{
//	Person p;
//	doWork1(p);
//}
//////3.值方式返回局部对象。
//Person doWork2()
//{
//	Person p1;
//	cout << (int*)&p1 << endl;
//	//return p1;
//  //这里person p = doWork2()不会调用拷贝方法，因为编译器优化，会直接用对象p存放dowork2()的返回值。
//  //这个问题在维基百科上叫做copy ellision。中文叫复制省略。
//	return Person(p1);
//}
//void test03()
//{
//	Person p = doWork2(); 
//	cout << (int*)&p << endl;
//}
//
//
//int main()
//{
//	//test01();
//	//test02();
//	//test03();
//	return 0;
//}

////4.2.4构造函数的调用规则：
//class Person
//{		
////1.创建一个类，C++编译器会给每个类都添加至少三个函数。
////	默认构造（空实现）	析构构造（空实现）	拷贝构造（值拷贝）。
////2.如果写了有参构造函数，编译器就不会提供默认构造，依然会提供拷贝构造。
////	如果写了拷贝构造函数，编译器就不再提供普通构造函数。
//public:
//	Person()
//	{
//		cout << "Person的默认构造函数" << endl;
//	}
//	Person(int age)
//	{
//		m_age = age;
//		cout << "Person的有参构造函数" << endl;
//	}
//	Person(const Person& p)
//	{
//		m_age = p.m_age;
//		cout << "Person的拷贝构造函数" << endl;
//	}
//	~Person()
//	{
//		cout << "Person的析构函数" << endl;
//	}
//	int m_age;
//};
//
////void test01()
////{
////	Person p;
////	p.m_age = 18;
////	Person p2(p);
////	//此时注释类内拷贝构造函数	当调用拷贝构造函数时，编译器会默认写拷贝构造函数。
////	cout << "p2的年龄为：" << p2.m_age << endl;
////}
//
////void test02()
////{
////	//此时将默认构造注释
////	//Person p;  //此时报错没有合适的默认构造函数。
////	Person p(20);
////	Person p2(p);
////	cout << "p2的年龄为：" << p2.m_age << endl;
////	//但此时有编译器默认写的拷贝构造函数。
////}
//
////void test03()
////{
////	//此时将所有普通构造函数进行注释
////	//Person p;	 //此时没有合适的普通构造函数
////}
//
//int main()
//{
//	//test01();
//	//test02();
//	//test03();
//	return 0;
//}

////4.2.5 深拷贝和浅拷贝
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Person的默认构造函数" << endl;
//	}
//	Person(int age,int height) //析构代码，为堆区开辟数据做释放操作。
//	{
//		m_age = age; 
//		m_Height = new int(height);
//		cout << "Person的有参构造函数" << endl;
//	}
//	Person(const Person& p)
//	{
//		cout << "Person的拷贝函数" << endl;
//		m_age = p.m_age;
//		m_Height = new int(*p.m_Height);
//	}
//	~Person()		//浅拷贝操作时，导致堆区的内存重复释放，需利用深拷贝解决(自己写拷贝函数解决)
//	{
//		if (m_Height != NULL)
//		{
//			delete m_Height;
//			m_Height = NULL;
//		}
//		cout << "Person的析构函数" << endl;
//	}
//	int m_age;
//	int* m_Height;
//}; 
//
//void test01()
//{
//	Person p1(18,160);
//	cout << "p1的年龄为：" << p1.m_age << "身高为：" << *p1.m_Height << endl;
//	Person p2(p1);
//	cout << "p2的年龄为：" << p2.m_age << "身高为：" << *p2.m_Height << endl;
//}
//int main()
//{
//	test01();
//	return 0;
//}	

////4.2.6 初始化列表
//class Person
//{
//	//Person(int a, int b, int c)  //传统方法构造
//	//{
//	//	m_A = a;
//	//	m_B = b;
//	//	m_C = c;
//	//}
//	//int m_A, m_B, m_C;
//
//	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c){}
//	int m_A, m_B, m_C;
//};

////4.2.7 类对象作为类成员
//class Phone
//{
//public:
//	Phone(string pName)
//	{
//		cout << "手机的构造函数" << endl;
//		p_name = pName;
//	}
//	~Phone()
//	{
//		cout << "手机的析构函数" << endl;
//	}
//	string p_name;
//};
//
//class Person
//{
//public:
//	Person(string name, string pName) :m_Name(name), m_phone(pName) 
//	{
//		cout << "人的构造函数" << endl;
//	}
//	~Person()
//	{
//		cout << "人的析构函数" << endl;
//	}
//	string m_Name;
//	Phone m_phone;
//};
//
//void test01()
//{
//	Person p("张三", "苹果15ProMax");
//	cout << p.m_Name << "拿着：" << p.m_phone.p_name << endl;
//
//}
//int main()
//{
//	test01();
//	//当其他类对象作为本类成员，构造时先构造类对象，再构造本身，析构时先析构本身，再析构类对象。
//	return 0;
//}

////4.2.8 静态成员
//class Person
//{
//public:
//	static int m_A;
//	static void func1()
//	{
//		cout << "static void func1调用" << endl;
//	}
//private:
//	static int m_B;
//	static void func2()
//	{
//		cout << "static void func2调用" << endl;
//	}
//};
//
//int Person::m_A = 10;
//int Person::m_B = 200;
//void test01()
//{
//	//静态成员变量 不属于某个对象上 所有对象都共享一份数据
//	//因此静态成员变量有两种访问方式
//	Person p;
//	//1、通过对象进行访问
//	cout << p.m_A << endl;
//	Person p2;
//	p2.m_A = 200;
//	//2、通过类名进行访问
//	cout << Person::m_A << endl;
//	//cout << Person::m_B << endl; //静态成员变量也是有访问权限的 类外访问不到私有静态成员变量
//
//	//静态成员函数有两种访问方式
//	//1.通过对象进行访问
//	p.func1();
//	//2.通过类名访问
//	Person::func1();
//	//Person::func2(); //静态成员函数也是有访问权限的 类外访问不到私有静态成员函数
//}
//
//int main()
//{
//	test01();
//}