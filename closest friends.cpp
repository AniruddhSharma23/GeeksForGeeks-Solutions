
#include <iostream>
using namespace std;
#include <bits/stdc++.h>
using ll = long long;
int main()
{
    // code
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        stack<ll> st;
        vector<ll> v;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            v.push_back(x);
        }
        stack<int> st;
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && v[i] <= v[st.top()])
            {
                st.pop();
            }
            if (st.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top());
            }

            st.push(i);
        }
        for (int i = 0; i < n - 1; i++)
        {
            cout << ans[i] << " ";
        }
        cout << ans[n - 1] << endl;
    }

    return 0;
}