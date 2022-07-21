//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string s, vector<string> &wordDict)
    {
        // code here
        unordered_set<string> st(wordDict.begin(), wordDict.end()); // store the wordDict in a set
        int n = s.length();
        vector<bool> dp(n + 1, false); // dp[i] = whether a valid word ends at index i-1 or not
        dp[0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 1; j >= 0; j--) // move back from i
            {
                if (dp[j] == true) // a valid word ends at j-1
                {
                    string k = s.substr(j, i - j); // substring from index=j to index=i-1
                    // k = new invalid word sequence (s[j..i-1]), if we find it in st we declare it as a valid word
                    if (st.find(k) != st.end())
                    {
                        dp[i] = true;
                        break; // move to the next i
                    }
                }
            }
        }
        return dp[n]; // whether a valid word ends at n-1 or not
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> dict;
        for (int i = 0; i < n; i++)
        {
            string S;
            cin >> S;
            dict.push_back(S);
        }
        string line;
        cin >> line;
        Solution ob;
        cout << ob.wordBreak(line, dict) << "\n";
    }
}

// } Driver Code Ends