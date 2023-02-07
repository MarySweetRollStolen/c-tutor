
#include <iostream>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int lcs(int* X, int* Y, const  int m, const  int n)
{
    int** L = new int* [m + 1];
    for (int i = 0; i < m + 1; ++i)
        L[i] = new int[n + 1];
    int i, j;


    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }


    return L[m][n];
}

int main()
{
    int num1, num2, i = 0, n;
    cin >> num1;
    cin >> num2;

    int* array1 = new int[num1];
    int* array2 = new int[num2];

    while (i != num1)
    {
        cin >> n;
        array1[i] = n;
        i++;
    }
    i = 0;
    while (i != num2)
    {
        cin >> n;
        array2[i] = n;
        i++;
    }

    /*
    for (int j = 0; j < num1; j++) {
        cout << array1[j] << "   ";
    }
    cout << endl;
    for (int j = 0; j < num2; j++) {
        cout << array2[j] << "   ";
    }
    */

    cout << lcs(array1, array2, num1, num2);

    return 0;
}

