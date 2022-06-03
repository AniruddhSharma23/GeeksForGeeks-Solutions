#include <iostream>
#include <vector>
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
        int i;
        for (i = 0; i < n; i++)
        {
            if (v[abs(v[i]) - 1] > 0)
                v[abs(v[i]) - 1] = -v[abs(v[i]) - 1];
            else
                cout << abs(v[i]) << " ";
        }

        for (i = 0; i < n; i++)
        {
            if (v[i] > 0)
                cout << (i + 1);
        }
        cout << endl;
    }
    return 0;
}