#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class Point;
//double distance(Point A, Point B);
double distance(const Point& A, const Point& B);

class Point
{
	double x;
	double y;
public:
	double getx()const
	{
		return x;
	}
	double gety()const
	{
		return y;
	}

	void setx(int x)
	{
		this->x = x;
	}
	void sety(int y)
	{
		this->y = y;
	}

	//                  Constructors
	Point()
	{
		x = 0;
		y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignmetn:\t\t" << this << endl;
		return *this;
	}


	//Increment/Decrement//
	Point& operator++() //Prefix increment
	{
		this->x++;
		this->y++;
		cout << "PrefixIncrement:\t" << this << endl;
		return *this;
	}

	Point operator++(int) //Suffix increment
	{
		Point old = *this;  //Сохраняем текущее знаечние нашего объекта
		this->x++;
		this->y++;
		cout << "SuffixIncrement:\t" << this << endl;
		return old;
	}

	//					methods
	double distance(const Point& other)
	{
		/*double x_distance = other.x - this->x;
		double y_distance = other.y - this->y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance); ВАРИАНТ РЕШЕНИЯ ЗАДАЧИ №1
		return distance;*/


		return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));		//ВАРИАНТ РЕШЕНИЯ ЗАДАЧИ №2

	}
	void print()const
	{
		cout << "X = " << x << '\t' << "Y = " << y << endl;
	}

};

Point& operator+(const Point& left, const Point& right)
{
	Point buffer;
	buffer.setx(left.getx() + right.getx());
	buffer.sety(left.gety() + right.gety());
	return buffer;
}

ostream& operator << (ostream& os, const Point& obj)
{
	os << "X = " << obj.getx() << '\t' << "Y = " << obj.gety() << endl;
	return os;
}

istream& operator >> (istream& is,  Point& obj)
{
	double x, y;
	is >> x >> y;
	obj.setx(x);
	obj.sety(y);
	return is;
}

#define delimiter "\n------------------------------------------\n"
//#define STRUCT_POINT
//#define DISTANCE
//#define CLASS_POINT
//#define ASSIGNMENT_CHECK
//#define ARITHMETICAL_METHODS



void main()
{
	setlocale(LC_ALL, "ru");
#ifdef STRUCT_POINT
	int a;				//объявление переменной 'a' типа 'int'
	Point A;			//Объявление переменной 'A' типа 'Point'
						//Объявлнеие экземпляра 'A' структуры 'Point'
						//Объявление объекта 'A' структуры 'Point'
						//Создание объекта 'A' структуры 'Point'
	A.getx = 2;
	A.y = 3;
	cout << A.x << '\t' << A.y << endl;

	Point* pA = &A;
	cout << pA->x << '\t' << pA->y << endl;
#endif // STRUCT_POINT


#ifdef DISTANCE
	Point A;
	A.setx(2);
	A.sety(3);
	cout << A.getx() << '\t' << A.gety() << endl;

	Point B;
	B.setx(3);
	B.sety(4);
	cout << B.getx() << '\t' << B.gety() << endl;

	cout << "Расстояние от точки A до точки B: " << A.distance(B) << endl << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки A до точки B: " << A.distance(B) << endl << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками A и B: " << distance(A, B) << endl << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками B и A: " << distance(B, A) << endl << endl;
	cout << delimiter << endl;
#endif // DISTANCE
#ifdef CLASS_POINT

	Point A;  //Default constructor
	A.print();
	Point B(2, 3);
	B.print();

	Point C = B;//CopyConstructor
	C.print();

	Point D;
	D = B; //CopyAssignment - оператор присваивания
	D.print();
#endif // CLASS_POINT

#ifdef ASSIGNMENT_CHECK

	int a, b, c;
	a = b = c = 0;
	cout << a << '\t' << b << '\t' << c << '\t' << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3); //Point(2,3) - явный вызов конструктора.
	//Таким образом создается временный безымянный объект,
	//который существует только в пределах выражения,
	//и удаляется после завершения выражения.
	cout << delimiter << endl;
	A.print();
	cout << delimiter << endl;
	B.print();
	cout << delimiter << endl;
	C.print();
#endif
#ifdef ARITHMETICAL_METHODS

	Point A(2, 3);
	Point B(4, 5);
	Point C = A + B; //Чтобы научить оператор "+" складывать точки
					//его нужно перегрузить для класса ТОЧКА!!
	C.print();
#endif // ARITHMETICAL_METHODS

	/*for (Point i(2, 3); i.getx() < 10; i++)
	{
		i.print();
	}*/

	Point A(2, 3);
	A.print();
	Point B = A++;
	B.print();

	cout << A << endl;
	cout << B << endl;

	cout << "Введите координаты точки А: ";
	cin >> A;
	cout << A << endl;
}

double distance(const Point& A, const Point& B)
{
	double x_distance = A.getx() - B.getx();
	double y_distance = A.gety() - B.gety();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;

	/*return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));*/
}

