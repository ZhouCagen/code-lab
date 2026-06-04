#include<iostream>
#include<cstring>
using namespace std;

////4.7.1 多态的基础概念
//class Animal
//{
//public:
//	//void speak()
//	//{
//	//	cout << "动物在说话" << endl;
//	//}
//	//虚函数 就能实现地址晚绑定
//	virtual void speak()
//	{
//		cout << "动物在说话" << endl;
//	}
//};
//class Cat :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "小猫在说话" << endl;
//	}
//};
////此时为地址早绑定 在编译阶段就确定函数地址（Animal&） 动物在说话
////如果想执行猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段绑定，地址晚绑定
//void dospeak(Animal& animal) // Animal& animal = cat; C++中允许父子之间的类型转换 不需要做强制类型转换
//{
//	animal.speak();
//}
////动态多态的满足条件：1.有继承关系	2.子类重写父类的虚函数（重写:函数返回值类型、函数名、参数列表完全相同）
////动态多态的使用：父类的指针或引用 指向子类对象
//class Dog :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "小狗在说话" << endl;
//	}
//};
//void test01()
//{
//	Cat cat;
//	dospeak(cat);
//	Dog dog;
//	dospeak(dog);
//}
//int main()
//{
//	test01();
//	return 0;
//}

////4.7.2 多态案例一 计算器实现
////普通写法实现计算器
//class Calculator
//{
//public:
//	int getResult(string oper)
//	{
//		if (oper == "+")
//		{
//			return m_Num1 + m_Num2;
//		}
//		else if (oper == "-")
//		{
//			return m_Num1 - m_Num2;
//		}
//		else if (oper == "*")
//		{
//			return m_Num1 * m_Num2;
//		}
//		//如果想扩展新的功能 需要修改源码
//		//在真实开发中提倡 开闭原则：对扩展进行开发 对修改进行关闭。
//	}
//	int m_Num1, m_Num2;
//
//};
//
//void test01()
//{
//	Calculator c;
//	c.m_Num1 = 10;
//	c.m_Num2 = 20;
//	cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
//	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
//	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
//}
//
//int main()
//{
//	test01();
//}
////利用多态实现计算器
////多态好处：1.组织结构清晰 2.可读性强
//class AbstractCalculator
//{
//public:
//	virtual int getResult()
//	{
//		return 0;
//	}
//	int m_Num1;
//	int m_Num2;
//};
//
//class AddCalculator :public AbstractCalculator
//{
//public:
//	virtual int getResult()
//	{
//		return m_Num1 + m_Num2;
//	}
//};
//
//class SubCalculator :public AbstractCalculator
//{
//public:
//	virtual int getResult()
//	{
//		return m_Num1 - m_Num2;
//	}
//};
//
//class MulCalculator :public AbstractCalculator
//{
//public:
//	virtual int getResult()
//	{
//		return m_Num1 * m_Num2;
//	}
//};
//void test02()
//{
//	//多态使用条件 父类指针或者引用指向子类对象
//
//	AbstractCalculator* abc = new AddCalculator;
//	abc->m_Num1 = 10;
//	abc->m_Num2 = 10;
//	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
//	delete abc;
//
//	abc = new SubCalculator;
//	abc->m_Num1 = 10;
//	abc->m_Num2 = 10;
//	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
//}
//int main()
//{
//	test02();
//}

////4.7.3 纯虚函数和抽象类
//class Base
//{
//public:
//	//纯虚函数 只要有一个纯虚函数，这个类称为抽象类 
//	//抽象类特点：1.无法实例化对象 2.抽象类的子类 必须要重写父类中的纯虚函数，否则也属于抽象类
//	virtual void func() = 0;
//};
//class Son :public Base
//{
//	virtual void func()
//	{
//		cout << "func函数调用" << endl;
//	}
//};
//void test01()
//{
//	//Base b;  //代码错误 无法实例化抽象类
//	//new Base;  //代码错误 无法实例化抽象类
//	Son s; //若不重写纯虚函数 则不能实例化对象
//	Base* base = new Son;
//	base->func();
//}
//int main()
//{
//	test01();
//	return 0;
//}

////4.7.4 多态实例二 制作饮品
//class AbstractDrinking
//{
//public:
//	//煮水
//	virtual void Boil() = 0;
//	//冲泡
//	virtual void Brew() = 0;
//	//倒入杯中
//	virtual void PourInCup() = 0;
//	//添加小料
//	virtual void PutSomethings() = 0;
//	//制作饮品/
//	void MakeDrinking()
//	{
//		Boil();
//		Brew();
//		PourInCup();
//		PutSomethings();
//	}
//};
//
//class MakeTea :public AbstractDrinking
//{
//public:
//	virtual void Boil()
//	{
//		cout << "煮水" << endl;
//	}
//	virtual void Brew()
//	{
//		cout << "冲泡茶叶" << endl;
//	}
//	virtual void PourInCup()
//	{
//		cout << "倒入杯中" << endl;
//	}
//	virtual void PutSomethings()
//	{
//		cout << "加柠檬" << endl;
//	}
//};
//
//class MakeCoffee :public AbstractDrinking
//{
//public:
//	virtual void Boil()
//	{
//		cout << "煮水" << endl;
//	}
//	virtual void Brew()
//	{
//		cout << "冲泡咖啡" << endl;
//	}
//	virtual void PourInCup()
//	{
//		cout << "倒入杯中" << endl;
//	}
//	virtual void PutSomethings()
//	{
//		cout << "加糖和牛奶" << endl;
//	}
//};
//
//void doWork(AbstractDrinking *abstractdrinking)
//{
//	abstractdrinking->MakeDrinking();
//	delete abstractdrinking;
//}
//
//void test01()
//{
//	doWork(new MakeCoffee);
//	cout << "--------------------------------------" << endl;
//	doWork(new MakeTea);
//}
//
////void test01()
////{
////	AbstractDrinking* abstractdrinking = new MakeTea;
////	abstractdrinking->MakeDrinking(); 
////	delete abstractdrinking;
////	AbstractDrinking* abstractdrinking = new MakeCoffee;
////	abstractdrinking->MakeDrinking();
////	delete abstractdrinking;
////}
//
//int main()
//{
//	test01();
//	return 0;
//}

////4.7.5 虚析构和纯虚析构
////子类没有堆区数据 可以不写虚析构和纯虚析构
//class Animal
//{
//public:
//	Animal()
//	{
//		cout << "Animal的构造函数" << endl;
//	}
//	//~Animal()
//	//{
//	//	cout << "Animal的析构函数" << endl;
//	// }
//	//虚析构
//	//virtual	~Animal()
//	//{
//	//	cout << "Animal的析构函数" << endl;
//	//}
//	//利用虚析构可以解决 父类指针释放子类对象时不干净的问题
//	//virtual ~Animal() = 0; // 纯虚析构 报错：无法解析的外部命令（链接阶段出现错误） 解决方式：声明和具体实现
//	virtual ~Animal() = 0;
//	//有纯虚析构之后 这个类也属于抽象类，无法实体化对象
//	virtual void speak() = 0;
//};
//Animal::~Animal()
//{
//	cout << "Animal纯虚析构函数的调用" << endl;
//}
//
//class Cat :public Animal
//{
//public:
//	Cat(string name)
//	{
//		cout << "Cat的构造函数" << endl;
//		m_Name = new string(name);
//	}
//	virtual void speak( ) 
//	{
//		cout << *m_Name << " 小猫在说话" << endl;
//	};  
//	string* m_Name;
//	~Cat()
//	{
//		cout << "Cat的析构函数" << endl;
//		if (m_Name != NULL)
//		{
//			delete m_Name;
//			m_Name = NULL;
//		}
//	}
//};
//
//void test01()
//{
//	Animal* animal = new Cat("Tom");
//	//由于父类指针在析构时不会调用子类中析构函数 导致子类如果有堆区属性 出现内存泄漏
//	animal->speak();
//	delete animal; 
//}
//int main()
//{
//	test01();
//	return 0;
//}

////4.7.6 多态实例三 电脑组装
//class Cpu
//{
//public:
//	virtual void calculate() = 0;
//};
//
//class Gpu
//{
//public:
//	virtual void display() = 0;
//};
//
//class MemorySticks
//{
//public:
//	virtual void storage() = 0;
//};
//
//class Computer
//{
//public:
//	Computer(Cpu* cpu, Gpu* gpu, MemorySticks* memorysticks)
//	{
//		m_cpu = cpu;
//		m_gpu = gpu;
//		m_memorysticks = memorysticks;
//	}
//	void Work()
//	{
//		//让零件工作起来 调用接口
//		m_cpu->calculate();
//		m_gpu->display();
//		m_memorysticks->storage();
//	}
//	~Computer()
//	{
//		if (m_cpu != NULL)
//		{
//			m_cpu = NULL;
//		}
//		if (m_gpu != NULL)
//		{
//			m_gpu = NULL;
//		}
//		if (m_memorysticks != NULL)
//		{
//			m_memorysticks = NULL;
//		}
//	}
//private:
//	Cpu* m_cpu;
//	Gpu* m_gpu;
//	MemorySticks* m_memorysticks;
//};
//
//class InterCpu :public Cpu
//{
//public:
//	virtual void calculate()
//	{
//		cout << "Inter的Cpu开始	计算了！" << endl;
//	}
//};
//class InterGpu :public Gpu
//{
//public:
//	virtual void display()
//	{
//		cout << "Inter的Gpu开始显示了！" << endl;
//	}
//};
//class InterMemorySticks :public MemorySticks
//{
//public:
//	virtual void storage()
//	{
//		cout << "Inter的MemorySticks开始存储了！" << endl;
//	}
//};
//
//class LenovoCpu :public Cpu
//{
//public:
//	virtual void calculate()
//	{
//		cout << "Lenovo的Cpu开始计算了！" << endl;
//	}
//};
//class LenovoGpu :public Gpu
//{
//public:
//	virtual void display()
//	{
//		cout << "Lenovo的Gpu开始显示了！" << endl;
//	}
//};
//class LenovoMemorySticks :public MemorySticks
//{
//public:
//	virtual void storage()
//	{
//		cout << "Lenovo的MemorySticks开始存储了！" << endl;
//	}
//};
//
//void test01()
//{
//	//第一台电脑零件
//	Cpu* intercpu = new InterCpu;
//	Gpu* intergpu = new InterGpu;
//	MemorySticks* intermemorysticks = new InterMemorySticks;
//	//创建第一台电脑
//	Computer* computer1 = new Computer(intercpu, intergpu, intermemorysticks);
//	computer1->Work();
//	delete computer1; //方法一：释放指针 //方法二：提供一个析构函数，释放零件。
//	cout << "------------------------------------------" << endl;
//	//第二台电脑零件
//	Cpu* lenovocpu = new LenovoCpu;
//	Gpu* lenovogpu = new LenovoGpu;
//	MemorySticks* lenovomemorysticks = new InterMemorySticks;
//	//创建第二台电脑
//	Computer* computer2 = new Computer(lenovocpu, lenovogpu, lenovomemorysticks);
//	computer2->Work();
//	delete computer2;
//	cout << "------------------------------------------" << endl;
//	//第三台电脑零件
//	//创建第三台电脑
//	Computer* computer3 = new Computer(lenovocpu, intergpu, intermemorysticks);
//	computer3->Work();
//	delete computer3;
//}
//int main()
//{
//	test01();
//}z