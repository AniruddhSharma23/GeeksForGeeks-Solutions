// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void leftSmaller(int arr[], int n, int SE[])
    {
        // Create an empty stack
        stack<int> S;

        // Traverse all array elements
        // compute nearest smaller elements of every element
        for (int i = 0; i < n; i++)
        {
            // Keep removing top element from S while the top
            // element is greater than or equal to arr[i]
            while (!S.empty() && S.top() >= arr[i])
                S.pop();

            // Store the smaller element of current element
            if (!S.empty())
                SE[i] = S.top();

            // If all elements in S were greater than arr[i]
            else
                SE[i] = 0;

            // Push this element
            S.push(arr[i]);
        }
    }
    int findMaxDiff(int A[], int n)
    {
        int LS[n]; // To store left smaller elements

        // find left smaller element of every element
        leftSmaller(A, n, LS);

        // find right smaller element of every element
        // first reverse the array and do the same process
        int RRS[n]; // To store right smaller elements in
                    // reverse array
        reverse(A, A + n);
        leftSmaller(A, n, RRS);

        // find maximum absolute difference b/w LS & RRS
        // In the reversed array right smaller for arr[i] is
        // stored at RRS[n-i-1]
        int result = -1;
        for (int i = 0; i < n; i++)
            result = max(result, abs(LS[i] - RRS[n - 1 - i]));

        // return maximum difference b/w LS & RRS
        return result;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.findMaxDiff(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends