

#include <iostream>
#include <algorithm>


using namespace std;

int main()
{
    int len;
    cin >> len;

    if (len != 0) {

        int* arr = new int[len];
        int* dep = new int[len];



        int k = 0, j = 0;
        for (int i = 0; i < len * 2; i++) {
            if (i % 2 == 0 || i == 0) {
                cin >> arr[k];
                k++;
            }
            else {
                cin >> dep[j];
                j++;
            }
        }


        sort(arr, arr + len);
        sort(dep, dep + len);


        int plat_needed = 1;
        k = 1, j = 0;

        while (k < len && j < len) {
            if (arr[k] < dep[j]) {
                plat_needed++;
                k++;
            }
            else if (arr[k] >= dep[j]) {
                plat_needed--;
                j++;
            }
        }

        cout << plat_needed;

    }
    else cout << 0;

    return 0;
}

