
#include <iostream>

using namespace std;

class WorkshopMaterals {
public: 
	int board;
	int sawdust;
	int trimming;

	WorkshopMaterals(int b) {
		board = b;
		sawdust = 0;
		trimming = 0;
	}

	void showResources() {
		cout << board << " " << sawdust << " " << trimming;
	}

	void makeTable() {
		if (sawdust >= 10){
			sawdust -= 10;
		}
		else if (board >= 5){
			board -= 5;
			sawdust += 2;
			trimming += 1;
		}
	}

	void makeChair(){
		if (sawdust >= 5) {
			sawdust -= 5;
		}
		else if (board >= 3) {
			board -= 3;
			trimming += 2;
		}
	}
	void makeDoor(){
		if (trimming >= 10) {
			trimming -= 10;
		}
		else if (board >= 4){
			board -= 4;
			sawdust += 1;
		}
	
	}
};

class Good {
public:
	int mainMarerial;
	int alternativeMaterial_sawdust;
	int alternativeMaterial_trimming;
	int waste_sawdust;
	int waste_trimming;

	Good(int m, int aS, int aT, int wS, int wT) {
		mainMarerial = m;
		alternativeMaterial_sawdust = aS;
		alternativeMaterial_trimming = aT;
		waste_sawdust = wS;
		waste_trimming = wT;
	}
};

int main()
{
	Good Table = Good(5, 10, 0, 2, 1);
	Good Chair = Good(3, 5, 0, 0, 2);
	Good Door = Good(4, 0, 10, 1, 0);

	int temp;
	cin >> temp;
	WorkshopMaterals Given(temp);
	int wood = temp;
	while (temp != -1) {
		cin >> temp;
		switch (temp) {
		case 1:
			//cout << "1" << endl;
			Given.makeTable();
			//Given.showResources();
			//cout << endl;
			break;
		case 2:
			//cout << "2" << endl;
			Given.makeChair();
			//Given.showResources();
			//cout << endl;
			break;
		case 3 :
			//cout << "3" << endl;
			Given.makeDoor();
			//Given.showResources();
			//cout << endl;
			break;
		default:
			break;
		}
	}
	Given.showResources();
}

