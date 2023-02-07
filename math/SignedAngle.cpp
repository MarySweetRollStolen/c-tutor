
#include <iostream>

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


double angle(dot A, dot B) {
    return safe_acos(product(A, B) / (mag(A) * mag(B)));
}


double mathSign(double num) {
    if (num >= 0) return 1;
    else  return -1;
}

// The smaller of the two possible angles between the two vectors is returned, therefore the result will never be greater than 180 degrees or smaller than -180 degrees.
// If you imagine the from and to vectors as lines on a piece of paper, both originating from the same point, then the /axis/ vector would point up out of the paper.
// The measured angle between the two vectors would be positive in a clockwise direction and negative in an anti-clockwise direction.

double SignedAngle(dot from, dot to, dot axis)
{
    double unsignedAngle = angle(from, to);

    double cross_x = from.Y * to.Z - from.Z * to.Z;
    double cross_y = from.Z * to.X - from.X * to.Z;
    double cross_z = from.X * to.Y - from.Y * to.X;
    double sign = mathSign(axis.X * cross_x + axis.Y * cross_y + axis.Z * cross_z);
    return unsignedAngle * sign;
}


dot CrossProduct(dot A, dot B) {
    double cross_x = A.Y * B.Z - A.Z * B.Z;
    double cross_y = A.Z * B.X - A.X * B.Z;
    double cross_z = A.X * B.Y - A.Y * B.X;
    dot C(cross_x, cross_y, cross_z);
    return C;
}


int main()
{
    dot A(2, 0, 0), B(0, 3, 0);
    dot normal = CrossProduct(A, B);
    cout << mag(normal) << endl;
    cout << SignedAngle(A, B, normal) << endl;
    cout << SignedAngle(B, A, normal) << endl;

    //expected and right result
    /*
    6
    1.5708
    -1.5708
    */
    // 90 degrees id 1.5708 radians


}
