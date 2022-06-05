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
        unsigned int d = (int)log2(n) + 1;
        int l, r;
        if (d % 2 == 0)
        {
            l = (d / 2);
            r = (d / 2) + 1;
        }
        else
        {
            l = r = (d / 2) + 1;
        }
        for (int i = l; i <= r; i++)
        {
            n = n ^ (1 << (i - 1));
        }
        cout << n << endl;
    }
    return 0;
}