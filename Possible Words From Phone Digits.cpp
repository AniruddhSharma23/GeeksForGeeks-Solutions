// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void solve(int a[], int i, int n, vector<string> &value, vector<string> &ans, string s)
    {
        if (i == n)
        {
            ans.push_back(s);
            return;
        }
        int digit = a[i];
        int m = value[digit].length();
        for (int j = 0; j < m; j++)
        {
            solve(a, i + 1, n, value, ans, s + value[digit][j]);
        }
    }
    vector<string> possibleWords(int a[], int n)
    {
        // Your code here
        vector<string> value = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        solve(a, 0, n, value, ans, "");
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main()
{

    int T;

    cin >> T; // testcases

    while (T--)
    { // while testcases exist
        int N;

        cin >> N; // input size of array

        int a[N]; // declare the array

        for (int i = 0; i < N; i++)
        {
            cin >> a[i]; // input the elements of array that are keys to be pressed
        }

        Solution obj;

        vector<string> res = obj.possibleWords(a, N);
        for (string i : res)
            cout << i << " ";
        cout << endl;
    }

    return 0;
} // } Driver Code Ends