//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	friend Person operator+ (const Person& p1,const Person& p2);
//	friend ostream& operator<<(ostream& cout, Person& p);
//	Person(){}
//	Person(int x, int y) :m_x(x), m_y(y) {}
//private:
//	int m_x;
//	int m_y;
//};
//
//ostream & operator<<(ostream &cout, Person& p)
//{
//	cout << "m_x= " << p.m_x << "  " << "m_y =" << p.m_y << endl;
//	return cout;
//}
//
//
//Person operator+ (const Person& p1,const Person& p2)
//{
//	Person temp;
//	temp.m_x = p1.m_x + p2.m_x;
//	temp.m_y = p1.m_y + p2.m_y;
//	return temp;
//}
//
//int main()
//{
//	Person p1(10, 20);
//	Person p2(20, 30);
//	Person p3 = p1 + p2;
//	cout << p3 << endl;
//	return 0;
//}