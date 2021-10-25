#include<iostream>
using namespace std; 

//double distance(Point A, Point B);

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
	void operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignmetn:\t\t" << this << endl;
	}


	//					methods
	double distance(Point other)
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


double distance(Point A, Point B)
{
	double x_distance = A.getx() - B.getx();
	double y_distance = A.gety() - B.gety();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;

	/*return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));*/
}

//#define STRUCT_POINT
//#define DISTANCE

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

	cout << "Расстояние от точки A до точки B: " << A.distance(B) << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;

	cout << "Расстояние от точки A до точки B: " << A.distance(B) << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << "Расстояние между точками A и B: " << distance(A, B);
	cout << "Расстояние между точками B и A: " << distance(B, A);
#endif // DISTANCE

	Point A;  //Default constructor
	A.print(); 
	Point B(2,3);
	B.print();

	Point C = B;//CopyConstructor
	C.print();

	Point D;
	D = B; //CopyAssignment - оператор присваивания
	D.print();
}
