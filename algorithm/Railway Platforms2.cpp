// Program to find minimum number of platforms
// required on a railway station
#include <algorithm>
#include <iostream>

using namespace std;

// Returns minimum number of platforms reqquired
int findPlatform(int arr[], int dep[], int n)
{
    // Sort arrival and departure arrays
    sort(arr, arr + n);
    sort(dep, dep + n);

    // plat_needed indicates number of platforms
    // needed at a time
    int plat_needed = 1, result = 1;
    int i = 1, j = 0;

    // Similar to merge in merge sort to process
    // all events in sorted order
    while (i < n && j < n) {
        // If next event in sorted order is arrival,
        // increment count of platforms needed
        if (arr[i] < dep[j]) {
            plat_needed++;
            i++;
        }

        // Else decrement count of platforms needed
        else if (arr[i] >= dep[j]) {
            plat_needed--;
            j++;
        }

        // Update result if needed
        if (plat_needed > result)
            result = plat_needed;
    }

    return result;
}

// Driver code
int main()
{
    int len;
    cin >> len;

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

    cout << findPlatform(arr, dep, len);

    return 0;
}