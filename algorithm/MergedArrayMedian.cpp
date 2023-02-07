
#include <iostream>

using namespace std;

int compare(const void* a, const void* b)
{
    const int* x = (int*)a;
    const int* y = (int*)b;

    if (*x > *y)
        return 1;
    else if (*x < *y)
        return -1;

    return 0;
}

void showArray(int* array, int numbers) {
    for (int i = 0; i < numbers; i++) {
        cout << array[i] << " ";
    }
}

int* makeOne(int* arr1, int* arr2, int n1, int n2) {
    int* array = new int[n1 + n2];
    for (int i = 0; i < n1; i++) {
        array[i] = arr1[i];
    }
    for (int i = 0; i < n2; i++) {
        array[i + n1] = arr2[i];
    }
    qsort(array, n1 + n2, sizeof(int), compare);
    return array;
}

int main()
{
    //generate the first array
    int n_1;
    cin >> n_1;
    int* X_1 = new int[n_1];
    int S_1, A_1, B_1, M_1;
    cin >> S_1 >> A_1 >> B_1 >> M_1;
    X_1[0] = S_1;
    for (int i = 1; i <= n_1 - 1; i++) {
        S_1 = (A_1 * S_1 + B_1) % M_1;
        X_1[i] = X_1[i - 1] + S_1;
    }

    //generate the first array
    int n_2;
    cin >> n_2;
    int S_2, A_2, B_2, M_2;
    cin >> S_2 >> A_2 >> B_2 >> M_2;
    int* X_2 = new int[n_2];
    X_2[0] = S_2;
    for (int i = 1; i <= n_2 - 1; i++) {
        S_2 = (A_2 * S_2 + B_2) % M_2;
        X_2[i] = X_2[i - 1] + S_2;
    }

    //checking if generate right
    showArray(X_1, n_1);
    cout << endl;
    showArray(X_2, n_2);

    int* array = new int[n_1 + n_2];
    array = makeOne(X_1, X_2, n_1, n_2);
    cout << endl;
    showArray(array, n_1 + n_2);

    cout << endl;
    //mediana
    cout << array[(int(((n_1)+(n_2)) / 2))];
    //cout << array[(int(((n_1-1) + (n_2-1)) / 2) + 1)]; //6/10

    //tests 6/10
}
