#include <iostream>
using namespace std;
#include <climits>
void minmax(int arr[], int low, int high, int &min, int &max)
{
    if (low == high)
    {
        min = max = arr[low];
    }
    else if (low == high - 1)
    {
        if (arr[low] < arr[high])
        {
            min = arr[low];
            max = arr[high];
        }
        else
        {
            min = arr[high];
            max = arr[low];
        }
    }
    else
    {
        int mid = (low + high) / 2;
        minmax(arr, low, mid, min, max);
        int min1 = min, max1 = max;
        minmax(arr, mid + 1, high, min, max);
        if (min1 < min)
        {
            min = min1;
        }
        if (max1 > max)
        {
            max = max1;
        }
    }
}
int main()
{
    int min = INT_MAX, max = INT_MIN;
    int n;
    cout << "enter the no of elements" << endl;
    cin >> n;
    int arr[n];
    cout << "enter the array elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    minmax(arr, 0, n - 1, min, max);
    cout << "minimum :" << min << endl;
    cout << "maximum :" << max << endl;
    return 0;
}