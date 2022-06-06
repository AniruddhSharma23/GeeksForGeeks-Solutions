// { Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;
map<int, int> mp; // mp hold 1 to those number which consists of only 1, 2, 3 as digits only

// } Driver Code Ends
// User function template for C++

bool isValid(int n)
{

    while (n > 0)
    {
        int d = n % 10;
        if (d != 1 && d != 2 && d != 3)
        {
            return false;
        }
        n /= 10;
    }
    return true;
}

void findAll()
{
    // code here

    int n = 1000001;
    for (int i = 0; i < n; i++)
    {
        if (isValid(i))
        {
            mp[i] = 1;
        }
    }
}

// { Driver Code Starts.

int main()
{
    findAll(); // find all such numbers whose digits are from set {1,2,3} from 1 to 1000000
    int t;
    cin >> t;

    while (t--)
    {
        int n, flag = 0;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) // insert n elements
            cin >> arr[i];

        sort(arr, arr + n); // sort them

        for (int i = 0; i < n; ++i)
        {
            if (mp[arr[i]])
            { // if arr[i] is already there in the map then it satisfied else not
                cout << arr[i] << " ";
                flag = 1;
            }
        }

        if (!flag)
            cout << "-1";

        cout << endl;
    }
    return 0;
} // } Driver Code Ends