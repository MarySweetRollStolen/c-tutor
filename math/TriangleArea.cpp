
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct coordinates {
	double X;
	double Y;
	double Z;
}A, B;


double product(coordinates a, coordinates b)  //calculates dot product of a and b
{
    //cout << a.X * b.X + a.Y * b.Y + a.Z * b.Z << "   prod" << endl;
    return a.X * b.X + a.Y * b.Y + a.Z * b.Z;

}

double magnitude(coordinates a)  //calculates magnitude of a
{
    //cout << sqrt(a.X * a.X + a.Y * a.Y + a.Z * a.Z) << "   mag" << endl;
    return sqrt(a.X * a.X + a.Y * a.Y + a.Z * a.Z);
}

double safe_acos(double value) {
    if (value <= -1.0) {
        //cout << "3.14159265 safe_acos" << endl;
        return 3.14159265;
    }
    else if (value >= 1.0) {
        //cout << "0 safe_acos" << endl;
        return 0;
    }
    else {
        //cout << acos(value)  << " safe_acos" << endl;
        return acos(value);
    }
}


double area_SAS(double a, double b, double angle) {
    //cout << 0.5 * a * b * sin(angle) << " area" << endl;
    return 0.5 * a * b * sin(angle);
}


int main()
{
	cin >> A.X >> A.Y >> A.Z >> B.X >> B.Y >> B.Z;
    //cout << product(A, B) / (magnitude(A) * magnitude(B)) << " check" << endl;
    if (magnitude(A) * magnitude(B) == 0) {
        cout << std::fixed << std::setprecision(8) << 0;
        //cout << " if non";
    }
    else {
        double area = area_SAS(magnitude(A), magnitude(B), safe_acos(product(A, B) / (magnitude(A) * magnitude(B))));
        cout << std::fixed << std::setprecision(8) << area;
    }
    return 0;
    // 9/10 tests 
}

