
#include <iostream>
#include <list>

using namespace std;

class Ship {
public:
    int id;
    int type;

    Ship() {
        id = -1;
        type = 0;
    }

    virtual void show() {
        cout << "bladj" << endl;
    }

};

class Cargo : public Ship {
public:
    int weight;
    int remainings;


    Cargo(int id_, int type_, int volume) {
        id = id_;
        type = type_;
        weight = volume;
        remainings = 0;
    }

    void setRemaining(int remain) {
        remainings = remain;
    }

    int Fee() {
        show();
        return (weight - remainings) * 5 + remainings * 2;
        
    }

    void show() override {
        cout << "Cargo " << id << " " << weight << " " << remainings << endl;
    }
};

class Passenger : public Ship {
public:
    int people;

    Passenger() {
        people = 0;
    }

    Passenger(int id_, int type_, int volume) {
        id = id_;
        type = type_;
        people = volume;
    }

    int Fee() {
        show();
        return people * 3;
    }

    void show() override {
        cout << "Passenger " << id << " " << people << endl;
    }
};


class Yacht : public Passenger {
public:
    bool left;

    Yacht(int id_, int type_, int volume) {
        id = id_;
        type = type_;
        people = volume;
        left = false;
    }

    void setLeft() {
        left = true;
    }

    int Fee() {
        show();
        if (left == true)
        {
            return 0;
        }
        else { return people * 5; }
    }

    void show() override {
        cout << "Yacht " << id << " " << people << " " << left << endl;
    }
};


int main()
{
    list<Ship> ships;
    int temp = 0,  type, volume;
    Ship iHateCpp;
    Ship* obj = &iHateCpp;
    while (temp != -1)
    {
        cin >> temp >> type >> volume;
        if(temp != -1)
        switch (type)
        {
        case 1:
            obj = new Passenger(temp, type, volume);
            break;
        case 2:
            obj = new Cargo(temp, type, volume);
            break;

        case 3:
            obj = new Yacht(temp, type, volume);
            break;
        }
        ships.push_back(*obj);
        cout << "loop" << endl;
    }
    
    for (auto i = ships.begin(); i != ships.end(); i++) {
        i->show();
    }


    /*
    Passenger s1(1, 1, 250);
    Passenger s2(2, 1, 150);
    Cargo s3(3, 2, 50);
    s3.setRemaining(20);
    Cargo s4(4, 2, 75);
    Passenger s5(5, 1, 175);
    Yacht s6(6, 3, 5);
    s6.setLeft();
    Yacht s7(7, 3, 4);
    */

    //int profit = s1.Fee() + s2.Fee() + s3.Fee() + s4.Fee() + s6.Fee() + s7.Fee() + s5.Fee();
    //cout << profit;


    return 0;
}


/*
list<Ship> ships;
int id = -2, type, volume;
Ship* temp;
while (id != -1) {
    cin >> id >> type >> volume;
    switch (type)
    {
    case 1:
        temp = new Passenger(id, type, volume);
        break;
    case 2:
        temp = new Cargo(id, type, volume);
        break;

    case 3:
        Ship * temp = new Yacht(id, type, volume);
        break;

    }

    //ships.push_back();
}
*/