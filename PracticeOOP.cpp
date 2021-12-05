#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;



class Point
{
private: // All variables must to be into private section
	double x;
	double y;
public:

	// Get -, set - methods:
	void set_x()
	{
		this->x = x;
	}
	void set_y()
	{
		this->y = y;
	}
	double get_x(double x)const // Get - methods must to be only constant, cause they are immutable
	{
		return x;
	}
	double get_y(double y)const
	{
		return y;
	}

	// Constructors:
	/*Point() // If we don't initialize default constructors where variables equal zeros, we get garbage values
	{
		x = 0;
		y = 0;
		cout << "Default constructor: " << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x; // 'this' is special operatior that works like pointer.
		this->y = y;
		cout << "Custom constructor: " << this << endl;
	}
	~Point()
	{
		cout << "Destructor: " << this << endl;
	}

	Point(const Point& other) // Copy - constructor creates an exact copy of an exiciting object. 
		//If we don't do this, the compiler uses another strategy: it creates the pointer that points at the same object.
	{
		this->x = other.x; // Pointer to x equal x with method 'other'
		this->y = other.y;
		cout << "Copy constructor: " << this << endl;
	}

	void operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
	}

	// Methods:
	double distance(Point other) // 'other' here like another random Point 
	{
		double x_distance = this->x - other.x; // we initialize x_distance like pointer to x minus x of another point
		double y_distance = this->y - other.y; // same
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance); // according to Pythagorean theorem we find out the distance using square root
		return distance;
	}
	void print()
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

//double distance(Point A, Point B)
//{
//	double x_distance = A.get_x() - B.get_y();
//	double y_distance = A.get_y() - B.get_y();
//	return sqrt(x_distance * x_distance + y_distance * y_distance);
//}

int main()
{
	Point A(2, 3);
	Point B(5, 6);

	cout << "Distance from A to B is " << A.distance(B) << endl;
	

	return 0;
}

