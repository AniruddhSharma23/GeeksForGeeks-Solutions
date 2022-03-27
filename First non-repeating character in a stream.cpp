Approach :
// we store the non-repeating character in the queue
// now if the element is not in the map then we add it to the queue as it is a non-repeating character
// no matter whether we encounter a repeating character or a non-repeating character we increase its frequency in the map
// so if we encounter a repeating character we pop the first element from the queue
// if the queue is empty then add # as there is no non-repeating character available at the moment
// else add the front element of queue to s
// example: A = aabc
// i=0 A[i] = a
//     add a to q
//     mp[a] increases to 1
//     q is not empty nor it contains repeating chracter hence add a to s
//     s=a
// i =1 A[i]=a
//     as mp[a]!=0
//     so a is not pushed in q this time
//     now mp[a] increases to 2
//     now as q is not empty and its front element is repeating therefore we pop it
//     now as q is empty thus no non-repeating character so we add #
//     s=a#
// i=2 A[i]=b
//     add b to q
//     mp[b] increases to 1
//     q is not empty nor it contains repeating chracter hence add b to s
//     s=a#b
// i=3 A[i]=c
//     add c to q
//     mp[c] increases to 1
//     q is not empty nor it contains repeating chracter hence add b(because b is the front element i.e. the first non-repeating character) to s
//     s=a#bb
// return s

// { Driver Code Starts
#include <bits/stdc++.h>
    using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        // Code here
        unordered_map<char, int> mp;
        queue<char> q;
        string s = "";
        for (int i = 0; i < A.length(); i++)
        {
            if (mp[A[i]] == 0)
            {
                q.push(A[i]);
            }
            mp[A[i]]++;
            while (!q.empty() && mp[q.front()] > 1)
            {
                q.pop();
            }
            if (q.empty())
            {
                s += "#";
            }
            else
            {
                s += q.front();
            }
        }
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends