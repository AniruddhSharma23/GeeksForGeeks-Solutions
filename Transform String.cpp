// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int transform(string A, string B)
    {
        // code here.
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for (char c : A)
            mp1[c]++;
        for (char c : B)
            mp2[c]++;
        if (mp1 != mp2)
            return -1;
        int k = 0;
        int i = A.length() - 1;
        int j = B.length() - 1;
        while (i >= 0 && j >= 0)
        {
            if (A[i] == B[j])
                j--;
            else
                k++;
            i--;
        }
        return k;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.transform(A, B) << endl;
    }
} // } Driver Code Ends