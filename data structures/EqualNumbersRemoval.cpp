

#include <iostream>
#include <stack>
#include <list>
using namespace std;


int main()
{
	//Input
	int n, temp;
	cin >> n;
	list<int> seq;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		seq.push_back(temp);
	}

	//Output
	int quantity = 0;
	stack<int> stck;
	while (seq.empty() != true){
		//temp = *i;
		temp = seq.front();
		seq.pop_front();
		if (stck.empty() != true) {
			cout << "if1" << endl;
			if (stck.top() == temp) {
				cout << "if2" << endl;
				stck.push(temp);
			}
			else {
				if (stck.size() >= 3) {
					quantity += stck.size();
					while (!stck.empty()) {
						stck.pop();
					}
					cout << quantity;
				}
				else {
					while (stck.empty() != true)
					{
						seq.push_front(stck.top());
						stck.pop();
					}
					stck.push(temp);
				}
			}
		}
		else {
			cout << "else1" << endl;
			stck.push(temp);
		}

	}

	cout << quantity;



}

/*
cout << *i;
if (!stck.empty())
{
	if (*i == stck.top()) {
		stck.push(*i);
	}
	else {
		//if(stck.size())
	}
}
//stck.push(*it);
*/