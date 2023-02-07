

#include <iostream>
#include <iomanip>

using namespace std;


struct coordinates {
	double X;
	double Y;
	double Z;
};


coordinates operator-(coordinates a, const coordinates& b) {
	coordinates d;
	d.X = a.X - b.X;
	d.Y = a.Y - b.Y;
	d.Z = a.Z - b.Z;
	return d;
}

coordinates operator+(coordinates a, const coordinates& b) {
	coordinates d;
	d.X = a.X + b.X;
	d.Y = a.Y + b.Y;
	d.Z = a.Z + b.Z;
	return d;
}

coordinates operator*(coordinates a, const double& b) {
	coordinates d;
	d.X = a.X * b;
	d.Y = a.Y * b;
	d.Z = a.Z * b;
	return d;
}

ostream& operator<<(ostream& os, const coordinates& cor) {
	os << std::fixed << std::setprecision(8) << cor.X << " " << cor.Y << " " << cor.Z;
	return os;
}


double magnitude(coordinates a)  //calculates magnitude of a
{
	//cout << sqrt(a.X * a.X + a.Y * a.Y + a.Z * a.Z) << "   mag" << endl;
	return sqrt(a.X * a.X + a.Y * a.Y + a.Z * a.Z);
}


double product(coordinates a, coordinates b)  //calculates dot product of a and b
{
	//cout << a.X * b.X + a.Y * b.Y + a.Z * b.Z << "   prod" << endl;
	return a.X * b.X + a.Y * b.Y + a.Z * b.Z;

}

coordinates FindNearestPointOnLine(coordinates line_dot, coordinates direction_v, coordinates g_point) {
	return g_point+(direction_v * (product(line_dot, direction_v) - product(direction_v, g_point)));

}

int main()
{
	//Input
	coordinates given_point, point_on_line, vector;
	cin >> given_point.X >> given_point.Y >> given_point.Z;
	cin >> point_on_line.X >> point_on_line.Y >> point_on_line.Z;
	cin >> vector.X >> vector.Y >> vector.Z;

	//Output
	coordinates found_point = FindNearestPointOnLine(point_on_line, vector, given_point);
	cout << found_point;

	// 2/11 tests 

}
