// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// Function to erase the element from specified position X in deque.
void eraseAt(deque<int> &dq, int X)
{
    // your code here
    auto it = dq.begin();
    it = it + X;
    dq.erase(it);
}

// Function to erase the elements in range start (inclusive), end (exclusive).
void eraseInRange(deque<int> &dq, int start, int end)
{
    // your code here
    auto it = dq.begin();
    auto s = it + start;
    auto e = it + end;
    dq.erase(s, e);
}

// Function to erase all the elements in the deque.
void eraseAll(deque<int> &dq)
{
    // your code here
    dq.clear();
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        deque<int> deq;
        for (int i = 1; i <= n; i++)
        {
            int val;
            cin >> val;
            deq.push_back(val);
        }

        int eraseQuery;
        cin >> eraseQuery;

        if (eraseQuery == 1)
        {
            int pos;
            cin >> pos;
            eraseAt(deq, pos);
        }
        else if (eraseQuery == 2)
        {
            int start, end;
            cin >> start >> end;
            eraseInRange(deq, start, end);
        }
        else
        {
            eraseAll(deq);
        }

        if (deq.empty())
            cout << "Empty";
        else
        {
            for (auto itr = deq.begin(); itr != deq.end(); itr++)
                cout << *itr << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends