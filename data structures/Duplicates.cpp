

#include <iostream>
#include<queue>
#include<list>

using namespace std;

bool find(int key, list<int> sequence) {
	for (auto i = sequence.begin(); i != sequence.end(); i++) {
		//cout << " *i " << *i;
		if (*i == key) {
			//cout << *i << " " << key << "funif" << endl;
			return true;
		}
	}
	return false;
}

int main()
{
	int temp;
	cin >> temp;
	queue<int> seq1;  
	while (temp != -1) {
		seq1.push(temp);
		cin >> temp;
	}

	list<int> seq2;
	cin >> temp;
	while (temp != -1) {
		seq2.push_back(temp);
		cin >> temp;
		
	}


	int temp2 = seq1.front();
	cout << temp2;
	int n = seq1.size();
	for (int i = 0; i < n; i++) {
		
		if (find(temp2, seq2) == true) {
			cout << " " << temp2;
			//cout << " " << temp2 << "temp2" << endl;
			seq1.pop();
		}
		else {
			seq1.pop();
		}
		if (!seq1.empty()){
			temp2 = seq1.front();
			cout << " " << temp2;
		}
		else {
			return 0;
		}
	}

}

