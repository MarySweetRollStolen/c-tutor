
#include <iostream>
#include <list>
using namespace std;

class Purse {
public:
    list<int> accounts;
    int wallet = 0;

    Purse(int data) {
        wallet = data;
    }

    void setAccounts(list<int> data) {
        accounts = data;
    }

    void showAccount() {
        for (auto i = accounts.begin(); i != accounts.end(); i++) {
            cout << " " << *i;
        }
    }

    void spend(int amount) {
        //cout << wallet << endl;
        if (wallet - amount >= 0) {
            wallet -= amount;
        }
        else {
            wallet += withdrawn(amount+amount);
            wallet -= amount;
        }
    }

    int withdrawn(int amount) {
        int a = amount;
        while (a > 0)
        {
            for (auto i = accounts.begin(); i != accounts.end(); i++) {
                if (*i != 0) {
                    if (*i - a >= 0) {
                        *i = *i - a;
                        //cout << " acc-" << *i << endl;
                        return a;
                        //a = 0;
                    }
                    else {
                        a = int ((*i - a) * (-1));
                        //cout << *i << endl;
                        *i = 0;
                    }
                }
            }
            //cout << "looop";
        }
        
    }
};



int main()
{
    //Input
    int r;
    cin >> r;
    Purse purse(r);

    cin >> r;
    list<int> accounts;
    while (r != -1) {
        accounts.push_back(r);
        cin >> r;
    }
    purse.setAccounts(accounts);

    cin >> r;
    list<int> purchase;
    while (r != -1) {
        purchase.push_back(r);
        cin >> r; 
    }

    //Output
    //cout << "3 500 200 1000 -1 100 200 1000 -1 0 0 100 -1";
   
    cout << purchase.size();
    for (auto j = purchase.begin(); j != purchase.end(); ++j) {
        purse.spend(*j);
        //cout << purse.wallet << endl;
        purse.showAccount();
        cout << " -1";
    }
    

    //100 500 200 1000 -1 50 200 600 -1
    return 0;
}

