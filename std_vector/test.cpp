#include <iostream>
#include "my_vector.h"

using namespace std;

struct Vector3
{
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;

	Vector3()
	{
		// cout << "Default\n";
	}

	Vector3(float scalar ) 
		: x(scalar),y(scalar),z(scalar)
	{

	}

	Vector3(float _x,float _y,float _z) 
		: x(_x),y(_y),z(_z)
	{

	}

	Vector3(const Vector3& rhs) 
	: x(rhs.x),y(rhs.y),z(rhs.z)
	{
		cout << "Copied \n";
	}

	Vector3& operator=(const Vector3& rhs) 
	{
		cout << "Copied \n";
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;

		return *this;
	}

	Vector3& operator=(Vector3&& rhs) 
	{
		cout << "Moved \n";
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;

		return *this;
	}


	~Vector3()
	{
		cout << "Destroyed \n";
	}
	

};

void PrintVector(const Vector<Vector3>& vector)
{
	for (int i = 0; i < vector.size(); ++i)
	{
		cout << vector[i].x << " " << vector[i].y << " " << vector[i].z << endl;
 	}
}



int main(int argc, char const *argv[])
{
	Vector<Vector3> vector;

	// vector.push_back(Vector3(1.0f));
	// vector.push_back(Vector3(1,2,3));
	// vector.push_back(Vector3());

	vector.emplace_back(1.0f);
	vector.emplace_back(1,2,3);
	vector.emplace_back();

	PrintVector(vector);
	vector.Clear();


	return 0;
}