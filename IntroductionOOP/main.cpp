#include<iostream>
using namespace std;

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


#define delimiter "\n------------------------------------------\n"
//#define STRUCT_POINT
//#define DISTANCE
//#define CLASS_POINT
//#define ASSIGNMENT_CHECK



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

	Point A(2, 3);
	Point B(4,5);
	//Point C = A + B;
}

double distance(const Point& A, const Point& B)
{
	double x_distance = A.getx() - B.getx();
	double y_distance = A.gety() - B.gety();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;

	/*return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));*/
}
