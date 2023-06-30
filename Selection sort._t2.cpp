
#include <bits/stdc++.h>
using namespace std;
void printArray(int array[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << array[i] << endl;
}

void selectionSort(int array[], int n)
{
    int min;
    for (int i = 0; i < n; ++i)
    {
        min = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (array[j] < array[min])
                swap(array[j],array[min]);
        }

    }
}

int main()
{
    int array[] = {95, 45, 48, 98, 485, 65, 54, 478, 1, 2325};
    int n = sizeof(array)/sizeof(array[0]);
    cout << "Before Selection Sort :" << endl;
    printArray(array, n);
    selectionSort(array, n);
    cout << "After Selection Sort :" << endl;
    printArray(array, n);
    return (0);
}
