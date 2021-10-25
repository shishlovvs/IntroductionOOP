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
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance); ������� ������� ������ �1
		return distance;*/


		return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));		//������� ������� ������ �2
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
	int a;				//���������� ���������� 'a' ���� 'int'
	Point A;			//���������� ���������� 'A' ���� 'Point'
						//���������� ���������� 'A' ��������� 'Point'
						//���������� ������� 'A' ��������� 'Point'
						//�������� ������� 'A' ��������� 'Point'
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

	cout << "���������� �� ����� A �� ����� B: " << A.distance(B) << endl;
	cout << "���������� �� ����� B �� ����� A: " << B.distance(A) << endl;

	cout << "���������� �� ����� A �� ����� B: " << A.distance(B) << endl;
	cout << "���������� �� ����� B �� ����� A: " << B.distance(A) << endl;
	cout << "���������� ����� ������� A � B: " << distance(A, B);
	cout << "���������� ����� ������� B � A: " << distance(B, A);
#endif // DISTANCE

	Point A;  //Default constructor
	A.print(); 
	Point B(2,3);
	B.print();

	Point C = B;//CopyConstructor
	C.print();

	Point D;
	D = B; //CopyAssignment - �������� ������������
	D.print();
}
