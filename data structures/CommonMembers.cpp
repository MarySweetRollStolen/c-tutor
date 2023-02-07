

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then it can only
        // be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present in right
        // subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not present in array
    return -1;
}

list<int> find_common(int* asmoll,int ns, int* abig, int nb) {
    list<int> intersection;
    for (int i = 0; i < nb; i++)
        if (binarySearch(asmoll, 0, nb - 1, abig[i]) != -1)
            intersection.push_back(abig[i]);
    //push front passed only 7/10 tests
    return intersection;
}


int main()
{
    //INPUT 
    //first sequence
    int num1, i = 0, n;
    cin >> num1;
    int* array1 = new int[num1];
    while (i != num1)
    {
        cin >> n;
        array1[i] = n;
        i++;
    }
    i = 0;

    //second sequence
    int num2;
    cin >> num2;
    int* array2 = new int[num2];
    while (i != num2)
    {
        cin >> n;
        array2[i] = n;
        i++;
    }

    
    list<int> intersection;

    if (num1 < num2) {
        sort(array1, array1 + num1);
        intersection = find_common(array1, num1, array2, num2);
    }
    else {
        sort(array2, array2 + num2);
        intersection = find_common(array2, num2, array1, num1);
    }

    //OUTPUT
    int quantity = intersection.size();
    cout << quantity;

    for (auto i = intersection.begin(); i != intersection.end(); i++) {
        cout << " " << *i;
    }
    
    //tests 8/10 not passed 8, 10
}

