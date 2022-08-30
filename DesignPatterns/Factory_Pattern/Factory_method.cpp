#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>


class Point
{
private :
	friend class PointFactory;
	float x,y;

	Point(float _x,float _y) : x(_x),y(_y)
	{
	}

	//inner factory 
	class PointFactory
	{
		PointFactory() {}
	public : 

		static Point getCartesion(float _x,float _y)
		{
			return {_x,_y};
		}

		static Point getPolar(float r,float theta)
		{
			return {r * cos(theta),r * sin(theta)};
		}
	};
	
public : 
	static PointFactory Factory;

	~Point()
	{

	}
	friend std::ostream& operator<<(std::ostream &stream,const Point &rhs)
	{

		stream << "x: " << rhs.x << " y: " << rhs.y << std::endl;
 		return stream;
	}
};


int main(int argc, char const *argv[])
{
	Point P1 = Point::Factory.getCartesion(9.0,10.0);
	Point P2 = Point::Factory.getPolar(9.0, M_PI_4);

	std::cout << P1 << std::endl;
	std::cout << P2 << std::endl;
	return 0;
}