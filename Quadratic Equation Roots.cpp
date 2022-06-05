// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> quadraticRoots(int a, int b, int c)
    {
        // code here
        vector<int> j;
        double p = sqrt((b * b) - 4 * a * c);
        if (b * b >= 4 * a * c)
        {
            double x = (floor((-b + p) / (2.0 * a)));
            double y = (floor((-b - p) / (2.0 * a)));
            if (x >= y)
            {
                j.push_back(x);
                j.push_back(y);
            }
            else
            {
                j.push_back(y);
                j.push_back(x);
            }
        }
        else
            j.push_back(-1);
        return j;
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Solution ob;
        vector<int> roots = ob.quadraticRoots(a, b, c);
        if (roots.size() == 1 && roots[0] == -1)
            cout << "Imaginary";
        else
            for (int i = 0; i < roots.size(); i++)
                cout << roots[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends