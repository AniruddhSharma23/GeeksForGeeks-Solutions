// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> removeDuplicate(vector<int> &arr, int n)
    {
        // code here
        vector<int> v;
        unordered_map<int, int> mp;
        for (auto x : arr)
        {
            if (mp.find(x) == mp.end())
            {
                mp[x]++;
                v.push_back(x);
            }
        }
        return v;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        vector<int> result = obj.removeDuplicate(A, N);
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
        cout << endl;
    }
}
// } Driver Code Ends