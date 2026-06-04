#include<iostream>
#include<string>
using namespace std;

////4.3.1 成员变量和成员函数分开存储
//class Person
//{
//	int m_A; //非静态成员变量	属于类的对象上
//	static int m_b;//静态成员变量	不属于类的对象上
//	void func() {}	//非静态成员函数	不属于类的对象上
//	static void func() {}
//};
////void test01()
////{
////	Person p;
//	//cout << "size of p=" << sizeof(p) << endl; //空对象占用的内存空间为：1
//	//C++编译器会给每个空对象也分配一个内存空间，是为了区分空对象占内存的位置
//	//每个空对象也应该有一个独一无二的内存地址
////}

////4.3.2 this指针概念
//class Person
//{
//public:
//	Person(int age)
//	{
//		this->age = age; //this指针解决名称冲突 指向被调用的成员函数所属的对象
//	}
//	Person& PersonAddage(Person& p) //用引用返回不会创建新对象，只会返回本身
//	{
//		this->age += p.age;
//		//this指向p2的指针，而*this指向的就是p2这个对象本体
//		return *this;
//	}
//	int age;
//};
//
////1.解决名称冲突
//void test01()
//{
//	Person p1(18);
//	cout << "p1的年龄为：" << p1.age << endl;
//}
//
////2.返回对象本身用*this
//void test02()
//{
//	Person p1(18);
//	Person p2(20);
//	p2.PersonAddage(p1).PersonAddage(p1).PersonAddage(p1); //链式编程思想 
//	cout << "p2的年龄为：" << p2.age << endl;
//}
//int main()
//{
//	test01();
//	test02();
//}

////4.3.3 空指针访问成员函数
//class Person
//{
//public:
//	void showClassName()
//	{
//		cout << "this is Person class" << endl;
//	}
//	void showPersonAge()
//	{
//		if (this == NULL)
//		{
//			return;
//		}
//		//传入的指针为空指针，没有值输出
//		//cout << "age=" << /*this->*/m_Age << endl;
//	}
//	int m_Age;
//};
//
//void test01()
//{
//	Person* p = NULL;
//	p->showClassName();
//	p->showPersonAge();
//}
//int main()
//{
//	test01();
//	return 0;
//}

////4.3.4 const修饰成员函数
//class Person
//{
//public:
//	Person(){}
//	//this指针的本质是指针常量，指针的指向是不可以修改的
//	void showPerson() const //成员函数+const为常函数 const Person *const this const修饰的this指针 让指针指向的值也不可以修改  
//	{
//		this->m_B = 100;
//		//this->m_A = 100;
//		//this = NULL; //this指针不可以修改指针指向 但指针指向的值可以修改
//	}
//	void func()
//	{
//		m_A = 100;
//	}
//	int m_A;
//	mutable int m_B;//特殊变量 即使在常函数中 也可以修改这个值 关键字mutable
//
//};
//
//void test01()
//{
//	Person p;
//	p.showPerson();
//}
//
//void test02()
//{
//	const Person p1; //在对象前加const，变为常对象
//	//p.m_A = 100;
//	p1.m_B = 100; //m_B是特殊值，在常对象下也可以修改
//	//常对象只能调用常函数
//	p1.showPerson();
//	//p.func(); //常对象不可以调用普通成员函数，因为普通成员函数可以修改属性
//}
//
//int main()
//{
//	test01();
//	test02();
//	return 0;
//}