#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    // code
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long sq = sqrt(n);
        long long a = sq * sq;
        long long b = (sq + 1) * (sq + 1);
        long long c = (sq - 1) * (sq - 1);
        if (a == n)
        {
            if (abs(b - a) > abs(c - a))
            {
                cout << c << endl;
            }
            else if (abs(b - a) < abs(c - a))
            {
                cout << b << endl;
            }
            else
            {
                cout << max(b, c) << endl;
            }
        }
        else
        {
            if (abs(b - n) > abs(n - a))
            {
                cout << a << endl;
            }
            else if (abs(b - n) < abs(n - a))
            {
                cout << b << endl;
            }
            else
            {
                cout << max(b, a) << endl;
            }
        }
    }
    return 0;
}