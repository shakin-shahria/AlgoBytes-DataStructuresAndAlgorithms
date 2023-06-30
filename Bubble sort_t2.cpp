#include <bits/stdc++.h>
using namespace std;
void printArray(int *array, int n)
{
    for (int i = 0; i < n; ++i)
    cout << array[i] << ", ";
    cout << endl;
}

void bubbleSort(int *array, int n)
{
    bool swapped = true;
    int j = 0;
    while (swapped==true)
    {
        swapped = false;
        j++;
        cout << "Value of j = " << j << endl;
        for (int i = 0; i < n - j; ++i)
        {
            if (array[i] > array[i + 1])
            {
                swap(array[j],array[j+1]);
                swapped = true;
            }
            printArray(array, n);
        }
    }
}

int main()
{
    int array[] = {5, 3, 2, 4, 1};
    int n = sizeof(array)/sizeof(array[0]);
    cout << "Before Bubble Sort :" << endl;
    printArray(array, n);
    bubbleSort(array, n);
    cout << "After bubble Sort :" << endl;
    printArray(array, n);
    return (0);
}
