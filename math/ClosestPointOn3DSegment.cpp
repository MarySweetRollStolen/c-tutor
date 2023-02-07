
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

int main()
{
	//Input
	coordinates given_point, A, B;
	cin >> given_point.X >> given_point.Y >> given_point.Z;
	cin >> A.X >> A.Y >> A.Z;
	cin >> B.X >> B.Y >> B.Z;



}
