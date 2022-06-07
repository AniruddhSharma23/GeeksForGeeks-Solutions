// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to delete middle element of a stack.
    void del(stack<int> &st, int n, int k)
    {

        if (k == n / 2)
        {
            st.pop();
            return;
        }
        int x = st.top();
        st.pop();
        k++;
        del(st, n, k);
        st.push(x);
    }
    void deleteMid(stack<int> &s, int sizeOfStack)
    {
        // code here..
        del(s, sizeOfStack, 0);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int sizeOfStack;
        cin >> sizeOfStack;

        stack<int> myStack;

        for (int i = 0; i < sizeOfStack; i++)
        {
            int x;
            cin >> x;
            myStack.push(x);
        }

        Solution ob;
        ob.deleteMid(myStack, myStack.size());
        while (!myStack.empty())
        {
            cout << myStack.top() << " ";
            myStack.pop();
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends