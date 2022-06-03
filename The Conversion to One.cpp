#include <iostream>
using namespace std;
int count(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n % 2 == 0)
    {
        return 1 + count(n / 2);
    }
    else
    {
        return 1 + min(count(n + 1), count(n - 1));
    }
}
int main()
{
    // code
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << count(n) << endl;
    }
    return 0;
}