// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

int sumExists(int arr[], int sizeOfArray, int sum);

// } Driver Code Ends
// User function Template for C++

// Complete this function
// Function to check if two numbers in the array have sum equal to the given
// sum.
int sumExists(int arr[], int n, int sum)
{

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        if (mp.find(sum - arr[i]) != mp.end())
        {
            if (arr[i] == sum - arr[i])
            {
                if (mp[arr[i]] > 1)
                {
                    return 1;
                }
            }
            else
            {
                return 1;
            }
        }
    }
    return 0;
}

// { Driver Code Starts.

int main()
{

    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int N;
        cin >> N;

        int arr[N];

        for (int i = 0; i < N; i++)
            cin >> arr[i];
        int sum;
        cin >> sum;

        cout << sumExists(arr, N, sum) << endl;
    }

    return 0;
} // } Driver Code Ends