
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    //6 -2 -3 3 2 -1 1
    //1 ( 
    //2 {
    //3 [
    stack<int> stack;
    int num, i=0, bracket;
    cin >> num;
   /* cin >> bracket;
    stack.push(bracket);
    cout << stack.top() << endl; // $$$$
    */
    while (i != num) {
        cin >> bracket;
        //cout << stack.top() << " i=" << i << endl;
        if (stack.empty() == 1) {
            stack.push(bracket);
        }
        else if (stack.top() == -1 && bracket == 1) {
            //cout << stack.top() << " i=" << i << " 1.1 " << endl;
            stack.pop();
           // cout << stack.top() << " i=" << i << " 1.2 " << endl;
            
        }   
        else if (stack.top() == -2 && bracket == 2) {
            //cout << stack.top() << " i=" << i << " 2.1 " << endl;
            stack.pop();
            //cout << stack.top() << " i=" << i << " 2.2 " << endl;
        } 
        else if (stack.top() == -3 && bracket == 3) {
           // cout << stack.top() << " i=" << i << " 3.1 " << endl;
            stack.pop();
            //cout << stack.top() << " i=" << i << " 3.2 " << endl;
        }
        else stack.push(bracket);
        i++;
    }
    
    cout << stack.empty();
}