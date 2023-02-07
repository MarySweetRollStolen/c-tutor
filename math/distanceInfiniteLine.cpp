

#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>

using namespace std;

struct dot {
    double X;
    double Y;
    double Z;
    dot(double x, double y, double z);
};

dot::dot(double x, double y, double z) {
    X = x; Y = y; Z = z;
}

double product(dot a, dot b)  //calculates dot product of a and b
{
    //cout << a.X * b.X + a.Y * b.Y + a.Z * b.Z << "   prod" << endl;
    return a.X * b.X + a.Y * b.Y + a.Z * b.Z;

}


double mag(dot a)  //calculates magnitude of a
{
    //cout << sqrt(a.X * a.X + a.Y * a.Y + a.Z * a.Z) << "   mag" << endl;
    return sqrt(a.X * a.X + a.Y * a.Y + a.Z * a.Z);
}


double projection(dot a, dot b) {
    return product(a, b) / mag(a);
}


double pythagoreanTheorem(double len1, double len2) {
    return sqrt((float)(pow(len1, 2) + pow(len2, 2)));
}


int main()
{
    dot given_point(1.0, 1.0, 1.0), line_point(2.0, 1.0, 1.0), direction_vector(0.0, 0.0, 1.0);
    cin >> given_point.X >> given_point.Y >> given_point.Z;
    cin >> line_point.X >> line_point.Y >> line_point.Z;
    cin >> direction_vector.X >> direction_vector.Y >> direction_vector.Z;
    //dot line_point(0, 0, 0), direction_vector(6, 0, 0), given_point(-6, -3, 0);
    dot A(line_point.X - direction_vector.X, line_point.Y - direction_vector.Y, line_point.Z - direction_vector.Z);
    dot B(line_point.X - given_point.X, line_point.Y - given_point.Y, line_point.Z - given_point.Z);

    double distance = pythagoreanTheorem(projection(direction_vector, B), mag(B));
    cout << std::fixed << std::setprecision(8) << sqrt(distance);

}

