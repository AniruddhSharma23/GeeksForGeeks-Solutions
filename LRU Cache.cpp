//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
private:
public:
    // Constructor for initializing the cache capacity with the given value.
    int cap;
    list<pair<int, int>> li;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    LRUCache(int cap) : cap{cap}
    {
    }
    // Function to return value corresponding to the key.
    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;
        li.splice(li.begin(), li, mp[key]);
        return mp[key]->second;
    }

    // Function for storing key-value pair.
    void set(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            li.splice(li.begin(), li, mp[key]);
            mp[key]->second = value;
            return;
        }
        if (mp.size() == cap)
        {
            int del_key = li.back().first;
            mp.erase(del_key);
            li.pop_back();
        }
        li.emplace_front(key, value);
        mp[key] = li.begin();
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends