
#include <iostream>
#include <iomanip>

using namespace std;


struct coordinates {
	double X;
	double Y;
	double Z;
};



ostream& operator<<(ostream& os, const coordinates& cor)
{
	os << std::fixed << std::setprecision(8) << cor.X << " " << cor.Y << " " << cor.Z;
	return os;
}
// overide << for struct coordinates


class AABB {
public:
	coordinates min;
	coordinates max;
	void empty();
	void add(const coordinates& p);
};

void AABB::empty() {
	const double BigNumber = 1e37f;
	min.X = min.Y = min.Z = BigNumber;
	max.X = max.Y = max.Z = -(BigNumber);
}


void AABB::add(const coordinates &p) {
	if (p.X < min.X) min.X = p.X;
	if (p.X > max.X) max.X = p.X;
	if (p.Y < min.Y) min.Y = p.Y;
	if (p.Y > max.Y) max.Y = p.Y;
	if (p.Z < min.Z) min.Z = p.Z;
	if (p.Z > max.Z) max.Z = p.Z;
}

int main()
{
    int num;
    cin >> num;
	coordinates* array = new coordinates[num];
	for (int i = 0; i < num; i++) {
		cin >> array[i].X >> array[i].Y >> array[i].Z;
	}

	AABB box;
	box.empty();

	for (int i = 0; i < num; ++i) {
		box.add(array[i]);
	}

	cout << box.min << " " << box.max;

	// 11/11 tests 
}

