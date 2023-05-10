#include <iostream>
using namespace std;
const int Max = 100;
int arr[Max];
int n;
void print(int subset[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << subset[i] << " ";
    }
    cout << endl;
}

void sumofsubset(int subset[], int size, int indx, int sum)
{
    if (indx == n)
    {
        print(subset, size);
        cout << "sum :" << sum << endl;
        return;
    }
    // include the subset
    subset[size] = arr[indx];
    sumofsubset(subset, size + 1, indx + 1, sum + arr[indx]);
    // exclude the subset
    sumofsubset(subset, size, indx+1, sum);
}
int main()
{
    cout << "enter the no of elements" << endl;
    cin>>n;
    cout << "enter the elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int subset[Max];
    sumofsubset(subset, 0, 0, 0);

    return 0;
}