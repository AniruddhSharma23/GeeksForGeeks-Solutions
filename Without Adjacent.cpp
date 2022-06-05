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
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        vector<int> dp(n + 1, -1);
        dp[1] = v[0];
        dp[0] = 0;

        for (int i = 2; i <= n; i++)
        {

            int pick = arr[i - 1] + dp[i - 2];

            int nonPick = dp[i - 1];

            dp[i] = max(pick, nonPick);
        }

        cout << dp[n] <, endl;
    }
    return 0;
}