

#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main()
{
    list <int> sequence;
    int temp;
    cin >> temp;
    while (temp != -1) {
        sequence.push_front(temp);
        cin >> temp;
    }

    for (list<int>::iterator i = sequence.begin(); i != sequence.end(); i++) {
        cout << *i << " ";
    }

    cout << "-1";

}
