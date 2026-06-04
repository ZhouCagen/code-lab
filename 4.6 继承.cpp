#include<iostream>
using namespace std;

//4.6.1继承的基本语法
//// 菜鸟写法：
//class Java
//{
//public:
//	void header()
//	{
//		cout << "首页，公开课，登录，注册......（公共头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心，交流合作，站内地图.......（公共底部）" << endl;
//	}
//	void left()
//	{
//		cout << "Java、Python、C++.......（公共分类列表）" << endl;
//	}
//	void content()
//	{
//		cout << "Java学科视频" << endl;
//	}
//};
//
//class Python
//{
//public:
//	void header()
//	{
//		cout << "首页，公开课，登录，注册......（公共头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心，交流合作，站内地图.......（公共底部）" << endl;
//	}
//	void left()
//	{
//		cout << "Java、Python、C++.......（公共分类列表）" << endl;
//	}
//	void content()
//	{
//		cout << "Python学科视频" << endl;
//	}
//};
//class C
//{
//public:
//	void header()
//	{
//		cout << "首页，公开课，登录，注册......（公共头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心，交流合作，站内地图.......（公共底部）" << endl;
//	}
//	void left()
//	{
//		cout << "Java、Python、C++.......（公共分类列表）" << endl;
//	}
//	void content()
//	{
//		cout << "C++学科视频" << endl;
//	}
//};
//void test01()
//{
//	cout << "Java的下载视频页面如下" << endl;
//	Java ja;
//	ja.header();
//	ja.footer();
//	ja.left();
//	ja.content();
//	cout << "-----------------------------------------------------" << endl;
//	cout << "Python的下载视频页面如下" << endl;
//	Python python;
//	python.header();
//	python.footer();
//	python.left();
//	python.content();
//	cout << "-----------------------------------------------------" << endl;
//	cout << "C++的下载视频页面如下" << endl;
//	C c;
//	c.header();
//	c.footer();
//	c.left();
//	c.content();
//	return;
//}
//
//int main()
//{
//	test01();
//	return 0;
//}
////继承写法：
//class BasePage
//{
//public:
//	void header()
//	{
//		cout << "首页，公开课，登录，注册......（公共头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心，交流合作，站内地图.......（公共底部）" << endl;
//	}
//	void left()
//	{
//		cout << "Java、Python、C++.......（公共分类列表）" << endl;
//	}
//};
////继承语法：class 子类：继承方式 父类
////子类（派生类） 父类（基类）
//class Java :public BasePage
//{
//public:
//	void content()
//	{
//		cout << "Java学科视频" << endl;
//	}
//};
//
//class Python :public BasePage
//{
//public:
//	void content()
//	{
//		cout << "Python学科视频" << endl;
//	}
//};
//
//class Cpp :public BasePage
//{
//public:
//	void content()
//	{
//		cout << "C++学科视频" << endl;
//	}
//};
//void test01()
//{
//	cout << "Java的下载视频页面如下" << endl;
//	Java ja;
//	ja.header();
//	ja.footer();
//	ja.left();
//	ja.content();
//	cout << "-----------------------------------------------------" << endl;
//	cout << "Python的下载视频页面如下" << endl;
//	Python python;
//	python.header();
//	python.footer();
//	python.left();
//	python.content();
//	cout << "-----------------------------------------------------" << endl;
//	cout << "C++的下载视频页面如下" << endl;
//	Cpp cpp;
//	cpp.header();
//	cpp.footer();
//	cpp.left();
//	cpp.content();
//	return;
//}
//
//int main()
//{
//	test01();
//	return 0;
//}

////4.6.2 继承方式
//class Base1
//{
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C;
//};
//class Son1 :public Base1
//{
//public: 
//	void func()
//	{
//		m_A = 10;//父类中的公共权限成员 到子类中依然是公共权限
//		m_B = 20;//父类中的保护权限成员 到子类中依然是保护权限
//		//m_C = 10;//父类中的私有权限成员 子类访问不到  
//	}
//};
//void test01()
//{
//	Son1 s1;
//	s1.m_A = 100;
//	//s1.m_B = 200;  //到Son1中 m_B是保护权限 类外访问不到
//	//s1.m_C = 300;
//}
//class Base2
//{
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C;
//};
//
//class Son2 :protected Base2
//{
//public:
//	void func()
//	{
//		m_A = 100;	 //父类中公共成员，保护继承后到子类变为保护权限
//		m_B = 100;
//		//m_C = 100; //父类中私有成员 子类访问不到
//	}
//};
//
//void test02()
//{
//	Son2 s1;
//	//s1.m_A = 1000; //在Son2中 m_A变为保护权限，因此类外访问不到
//	//s2.m_B = 1000; //在Son2中 m_B保护权限 不可以访问
//}
//class Base3
//{
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C;
//};
//class Son3 :private Base3
//{
//public:
//	void func()
//	{
//		m_A = 100;   //父类中的公共成员和保护成员到子类变为私有成员
//		m_B = 100;
//		//m_C = 100; //父类中私有成员 子类访问不到
//	}
//};
//
//void test03()
//{
//	Son3 s1;
//	//s1.m_A = 100;  //到Son3中变为私有成员 类外访问不到
//	//s1.m_B = 100;
//}
//
//class Grandson3 :public Son3
//{
//public:
//	void func()
//	{
//		//m_A = 1000; // Son3中变为私有 即使是子类也访问不到
//	}
//};
//int main()
//{
//	test01();
//	test02();
//	test03();
//	return 0;
//}

////4.6.3 继承中的对象模型
//class Base
//{
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C;
//};
//
//class Son :public Base
//{
//public:
//	int m_D;//私有属性只是被隐藏了，但还是会继承下去。
//};
//
////利用开发人员命令提示工具查看对象模型
////跳转盘符：C： 跳转文件路径 C:\Users\Asus\Desktop\VisualStudio\C++学习内容\C++学习内容
////查看命名 cl/dl reportSingleClassLayout类名 文件名(Tab)
//
//void test01()
//{
//	//父类中所有非静态成员属性都会被子类继承下去
//	//父类中私有属性 是被编译器给隐藏了 因此是访问不到 但是确实被继承下去
//	cout << "size of Son=" << sizeof(Son) << endl;
//}
//int main()
//{
//	test01();
//	return 0;
//}

////4.6.4 继承中的构造和析构顺序
//class Base
//{
//public:
//	Base()
//	{
//		cout << "Base的构造函数" << endl;
//	}
//	~Base()
//	{
//		cout << "Base的析构函数" << endl;
//	}
//};
//class Son :public Base
//{
//public:
//	Son()
//	{
//		cout << "Son的构造函数" << endl;
//	}
//	~Son()
//	{
//		cout << "Son的析构函数" << endl;
//	}
//};
//void test01()
//{
//	Son son1;
//	//继承中的构造和析构顺序如下
//	//先构造父类 再构造子类 再析构子类 最后析构父类 
//}
//int main()
//{
//	test01();
//	return 0;
//}

////4.6.5 继承同名成员处理方式
//class Base
//{
//public:
//	Base()
//	{
//		m_A = 100;
//	}
//	void func()
//	{
//		cout << "Base - func()调用" << endl;
//	}	
//	void func(int a)
//	{
//		cout << "Base - func(int a)调用" << endl;
//	}
//	int m_A;
//};
//class Son :public Base
//{
//public:
//	Son()
//	{
//		m_A = 200;
//	}
//	void func()
//	{
//		cout << "Son - func()调用" << endl;
//	}
//	int m_A;
//};
////同名成员属性
//void test01()
//{
//	Son s;
//	cout << "Son中m_A=" << s.m_A << endl;
//	cout << "Base中m_A=" << s.Base::m_A << endl;
//}
////同名成员函数
//void test02()
//{
//	Son s1;
//	s1.func();
//	下面一行的函数报错 原因：如果子类中出现和父类同名的成员函数，子类的同名函数会隐藏掉父类中所有同名函数
//	//s1.func(100); //如果想访问请加作用域
//	s1.Base::func(100);
//	s1.Base::func();
//}
//int main()
//{
//	test01();
//	test02();
//	return 0;
//}

////4.6.6 继承同名静态成员处理
//
//class Base
//{
//public:
//	static void func()
//	{
//		cout << "Base - static void func()的调用" << endl;
//	}
//	static void func(int a)
//	{
//		cout << "Base - static void func(int a)的调用" << endl;
//	}
//	static int m_A;
//};
//
//int Base::m_A = 100;
//class Son :public Base
//{
//public:
//	static void func()
//	{
//		cout << "Son - static void func()的调用" << endl;
//	}
//	static int m_A;
//};
//int Son::m_A = 200;
//
//void test01()
//{
//	//通过对象访问静态成员变量
//	Son s;
//	cout << "通过对象访问:	" << endl;
//	cout <<"Son - m_A = " << s.m_A << endl;
//	cout << "Base - m_A = " << s.Base::m_A << endl;
//	//通过类名访问静态成员变量
//	cout << "通过类名访问：	" << endl;
//	cout << "Son - m_A = " << Son::m_A << endl;
//	cout << "Base - m_A = " << Base::m_A << endl;
//	cout << "Base - m_A = " << Son::Base::m_A << endl; //Son::通过类名访问数据 Base::父类作用域下的m_A  
//}
//
//void test02()
//{
//	//通过对象访问
//	Son s1;
//	cout << "通过对象访问:	" << endl;
//	s1.func();
//	s1.Base::func();
//  //下面一行的函数报错 原因：如果子类中出现和父类同名的成员函数，子类的同名函数会隐藏掉父类中所有同名函数
//	//s1.func(100); //如果想访问请加作用域
//	s1.Base::func(100);
//	//通过类名访问
//	cout << "通过类名访问：	" << endl;
//	Son::func();
//	Base::func();
//	Base::func(100);
//	Son::Base::func();
//	Son::Base::func(100);
//}
//
//int main()
//{
//	test01();
//	test02();
//	return 0;
//}

////4.6.7 多继承语法
//class Base1
//{
//public:
//	Base1()
//	{
//		m_A = 100;
//	}
//	int m_A;
//};
//class Base2
//{
//public:
//	Base2()
//	{
//		m_A = 500;
//		m_B = 200;
//	}
//	int m_A, m_B; 
//};
//class Son :public Base1, public Base2
//{
//public:
//	Son()
//	{
//		m_C = 300;
//		m_D = 400;
//	}
//	int m_C, m_D;
//};
//
//void test01()
//{
//	Son s;
//	cout << "sizeof Son = " << sizeof(s) << endl;
//	//cout << "m_A = " << s.m_A << endl; //当父类中出现同名成员，需要加作用域区分
//	cout << "Base1 m_A = " << s.Base1::m_A << endl;
//	cout << "Base2 m_A = " << s.Base2::m_A << endl;
//}
//
//int main()
//{
//	test01();
//}

////4.6.8 菱形继承
//class Animal
//{
//public:
//	int m_Age;
//};
////这份数据我们知道 只要有一份就可以 菱形继承导致数据有两份 资源浪费
////利用虚继承可以解决菱形继承问题 在继承前加上关键字virtual 变为虚继承 Animal类称为虚基类
////  class SheepAlpaca   size(12) :
////			+-- -
////	0		| +-- - (base class Sheep)
////	0		| | {vbptr}
////			| +-- -
////  4		| +-- - (base class Alpaca)
////  4		| | {vbptr}
////			| +-- -
////			+-- -
////			+-- - (virtual base Animal)
////  8		| m_Age
////			+ -- -
////SheepAlpaca::$vbtable@Sheep@:
////	0       | 0
////  1	    | 8 (SheepAlpacad(Sheep + 0)Animal)
//// 
////SheepAlpaca::$vbtable@Alpaca@:
////  0		| 0
////  1	    | 4 (SheepAlpacad(Alpaca + 0)Animal)
//// vbi:			class  offset o.vbptr  o.vbte fVtorDisp
////			   Animal       8       0       4 0
//// 
////vbptr为虚基类指针（virtual base pointer） 指向 vbtable（虚基类表格）指针到表格进行偏移量处理直接找到m_Age
//class Sheep :virtual public Animal{};
//class Alpaca :virtual public Animal {};
//class  SheepAlpaca :public Sheep, public Alpaca{};
//
//void test01()
//{
//	SheepAlpaca sheepalpaca;
//	sheepalpaca.Sheep::m_Age = 18;
//	sheepalpaca.Alpaca::m_Age = 20; 
//	//当菱形继承时，有两个父类拥有相同的数据，需要加以作用域区分。
//	cout << "sheepalpaca.Sheep::m_Age = " << sheepalpaca.Sheep::m_Age << endl;
//	cout << "sheepalpaca.Alpaca::m_Age = " << sheepalpaca.Alpaca::m_Age << endl;
//	cout << "m_Age = " << sheepalpaca.m_Age << endl;
//}
//
//int main()
//{
//	test01();
//	return 0;
//}