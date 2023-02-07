
#include <iostream>
#include <list>

using namespace std;


//function for printing the elements in a list
void showlist(list <int> g)
{
	list <int> ::iterator it;
	for (it = g.begin(); it != g.end(); ++it)
		cout<< *it << " ";
}


void deleteItem(list<int> &a, list<int> b)
{
	list <int> ::iterator it_a = a.begin();
	list <int> ::iterator it_b;
	int size_a;
	int index;

	for (it_b = b.begin(); it_b != b.end(); ++it_b)
	{
		//cout << "b start" << endl;
		index = 0;
		size_a = a.size();
		it_a = a.begin();
		while (index < size_a && it_a != a.end())
		{
			if (index % *it_b)
			{
				index++;
				it_a++;
			} else {
				a.erase(it_a++);
				index++;
			}
			
		}
	}
 
}


int main()
{
	list<int> seq1, seq2;

	int temp;
	cin >> temp;
	while (temp != -1) {
		seq1.push_back(temp);
		cin >> temp;
	}

	cin >> temp;
	while (temp != -1) {
		seq2.push_back(temp);
		cin >> temp;
	}

	deleteItem(seq1, seq2);
	showlist(seq1);
	cout << "-1";
	//tests 11/11
}



