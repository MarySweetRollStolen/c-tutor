

#include <iostream>
#include <iomanip>

using namespace std;

struct coordinates2d {
	double X;
	double Y;
};

// overide << for struct coordinates2d
ostream& operator<<(ostream& os, const coordinates2d& cor)
{
	os << std::fixed << std::setprecision(8) << cor.X << " " << cor.Y;
	return os;
}

double mag(coordinates2d a)  //calculates magnitude of a
{
	//cout << sqrt(a.X * a.X + a.Y * a.Y + a.Z * a.Z) << "   mag" << endl;
	return sqrt(a.X * a.X + a.Y * a.Y );
}

coordinates2d find_closest_point(coordinates2d circle_center, coordinates2d given_point, double radius)  //calculates magnitude of a
{
	coordinates2d  closest_point;
	coordinates2d vector;
	vector.X = given_point.X - circle_center.X;
	vector.Y = given_point.Y - circle_center.Y;
	closest_point.X = circle_center.X + radius * (vector.X / mag(vector));
	closest_point.Y = circle_center.Y + radius * (vector.Y / mag(vector));
	return closest_point;
}


int main()
{
	//INPUT
	coordinates2d point, circle_center;
	double r;
	cin >> point.X >> point.Y;
	cin >> circle_center.X >> circle_center.Y;
	cin >> r;

	//OUTPUT
	coordinates2d found_point = find_closest_point(circle_center, point, r);
	cout << found_point;
	//10/10 tests

}

