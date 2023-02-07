
#include <iostream>
#include <iomanip>


using namespace std;

struct dot {
    double X;
    double Y;
    double Z;
}givenDot, A, B, lamS, S;  // A is the start od the segment, B is the end

double lam(double a, double b, double g) {
    if (b - a == 0)
        return 0;
    else
        return (g - a) / (b - a);
}

int main()
{
    // for(int i = 0; i<10; i++) {
    //     cout << endl;

    //cout << "Input:\n";
    cin >> givenDot.X >> givenDot.Y >> givenDot.Z >> A.X >> A.Y >> A.Z >> B.X >> B.Y >> B.Z;

    //testing output, remove later
    //cout <<"    "  << givenDot.X << "    " << givenDot.Y << "    " << givenDot.Z << "    " << A.X << "    " << A.Y << "    " << A.Z << "    " << B.X << "    " << B.Y << "    " << B.Z;
    //cout << endl;

    lamS.X = lam(A.X, B.X, givenDot.X);
    lamS.Y = lam(A.Y, B.Y, givenDot.Y);
    lamS.Z = lam(A.Z, B.Z, givenDot.Z);

    //testing output, remove later
   // cout << lamS.X  <<"     " << lamS.Y << "   " << lamS.Z;

   //cout << "Output:\n";
    if (lamS.X <= 0 & lamS.Y <= 0 & lamS.Z <= 0) {
        cout << std::fixed << std::setprecision(8) << A.X << " " << A.Y << " " << A.Z;
    }
    else {
        if (lamS.X >= 1 & lamS.Y >= 1 & lamS.Z >= 1) {
            cout << std::fixed << std::setprecision(8) << B.X << " " << B.Y << " " << B.Z;
        }
        else {
            S.X = A.X + lamS.X * (B.X - A.X);
            S.Y = A.Y + lamS.Y * (B.Y - A.Y);
            S.Z = A.Z + lamS.Z * (B.Z - A.Z);
            cout << std::fixed << std::setprecision(8) << S.X << " " << S.Y << " " << S.Z;
        }
    }
    // cout << endl;

    // }

}

