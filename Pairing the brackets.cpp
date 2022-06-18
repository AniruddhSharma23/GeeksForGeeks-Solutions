#include <iostream>
using namespace std;
#include <bits/stdc++.h>
using ll = long long;
int main()
{
    // code
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<int> st;
        int n = s.length();
        int k = 0;
        vector<int> a;
        vector<int> b;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' && st.empty())
            {
                st.push(i);
            }
            if (s[i] == ')' && !st.empty())
            {
                a.push_back(st.top());
                b.push_back(i);
                st.pop();
                k++;
            }
        }
        cout << k << endl;
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << " " << b[i] << endl;
        }
    }
    return 0;
}