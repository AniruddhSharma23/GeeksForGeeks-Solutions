// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        // code here.
        set<int> s1(A, A + n1);
        set<int> s2(B, B + n2);
        set<int> s3(C, C + n3);
        vector<int> v;
        for (auto x : s3)
            if (s1.find(x) != s1.end() && s2.find(x) != s2.end())
                v.push_back(x);
        return v;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];

        for (int i = 0; i < n1; i++)
            cin >> A[i];
        for (int i = 0; i < n2; i++)
            cin >> B[i];
        for (int i = 0; i < n3; i++)
            cin >> C[i];

        Solution ob;

        vector<int> res = ob.commonElements(A, B, C, n1, n2, n3);
        if (res.size() == 0)
            cout << -1;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
} // } Driver Code Ends