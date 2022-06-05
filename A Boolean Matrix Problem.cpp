#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <list>
#include <iterator>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>
#include <complex>
#include <math.h>
#include <cstring>
#include <string>
using namespace std;
int main()
{
    // code
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> v;
        unordered_map<int, int> mp;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int x;
                cin >> x;
                if (x == 1)
                {
                    mp[i]++;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (mp[i] > 0)
            {
                vector<int> p(n, 1);
                v.push_back(p);
            }
            else
            {
                vector<int> p(n, 0);
                v.push_back(p);
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}