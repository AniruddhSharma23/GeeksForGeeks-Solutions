// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int transfigure(string A, string B)
    {
        // Your code goes here
        int na = A.length();
        int nb = B.length();
        if (na != nb)
            return -1;
        if (A == B)
            return 0;
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for (char c : A)
            mp1[c]++;
        for (char c : B)
            mp2[c]++;
        if (mp1 != mp2)
            return -1;
        int i = na - 1;
        int j = nb - 1;
        int count = 0;
        while (i >= 0 && j >= 0)
        {
            if (A[i] == B[j])
            {
                i--;
                j--;
            }
            else
            {
                count++;
                i--;
            }
        }
        return count;
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
        Solution obj;
        cout << obj.transfigure(A, B) << endl;
    }
} // } Driver Code Ends