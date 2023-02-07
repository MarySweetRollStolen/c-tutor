
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct dot {
    double X;
    double Y;
    double Z;
}A, B;

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

double safe_acos(double value) {
    if (value <= -1.0) {
        return 3.14159265;
    }
    else if (value >= 1.0) {
        return 0;
    }
    else {
        return acos(value);
    }
}



int main()
{
    cin >>  A.X >> A.Y >> A.Z >> B.X >> B.Y >> B.Z;
    //cout << endl;
    //cout << A.X << A.Y << A.Z << B.X << B.Y << B.Z <<endl;
    //cout << (mag(A) * mag(B)) << "  *   "  << endl;
    //cout << product(A, B) / (mag(A) * mag(B)) << "    /    "   << endl;
   // cout << safe_acos(product(A, B) / (mag(A) * mag(B))) << "    arcos   " << endl;
    double angle = safe_acos( product(A,B) / (mag(A) * mag(B)) );
    cout << std::fixed << std::setprecision(8) << angle;
    return 0;
}

