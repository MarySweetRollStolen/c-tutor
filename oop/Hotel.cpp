
#include <iostream>
using namespace std;

class Room {      
public:             
    int num;        
    int maintence;
    int rent_amount;
    bool daily;

    Room() {
        num = -1;
        maintence = 0;
        rent_amount = 0;
        daily = false;
    }

    Room(int n, bool d) {
        num = n;
        maintence = 0;
        rent_amount = 0;
        daily = d;
    }

    void calculete_rent_amount(int hours) {
        if (daily == true) {
            int days = 0, hour = hours;
            while (hour >= 24) {
                days++;
                hour -= 24;
            }
            rent_amount += 400 * days + hour * 20;
        }
        else {
            rent_amount += hours * 20;
        }
    }

    int profit() {
        return rent_amount - maintence;
    }


};


int main()
{
    Room one = Room(1, false);
    Room two = Room(2, false);
    Room three = Room(3, false);
    Room four = Room(4, true);
    Room five = Room(5, true);

    int r, h;
    cin >> r;
    while (r != -1) {
        cin >> h;
        switch (r)
        {
        case 1:
            one.calculete_rent_amount(h);
            break;
        case 2:
            two.calculete_rent_amount(h);
            break;
        case 3:
            three.calculete_rent_amount(h);
            break;
        case 4:
            four.calculete_rent_amount(h);
            break;
        case 5:
            five.calculete_rent_amount(h);
            break;
        default:
            break;
        }
        cin >> r;
    }

    int m;
    cin >> r;
    while (r != -1) {
        cin >> m;
        switch (r)
        {
        case 1:
            one.maintence = m;
            break;
        case 2:
            two.maintence = m;
            break;
        case 3:
            three.maintence = m;
            break;
        case 4:
            four.maintence = m;
            break;
        case 5:
            five.maintence = m;
            break;
        default:
            break;
        }
        cin >> r;
    }



    cout << one.profit() << " " << two.profit() << " " << three.profit() << " " << four.profit() << " " << five.profit() << " -1";
    //cout << "625 290 0 520 0 -1";

    return 0;
}

