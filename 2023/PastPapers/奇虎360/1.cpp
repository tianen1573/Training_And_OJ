#include<vector>
#include<unordered_set>
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_set<int> hash;
    int ans = 0;
    for(int i = 0; i < n; ++ i)
    {
        int val;
        cin >> val;
        if(hash.count(val))
        {
            ++ ans;
            continue;
        }
        hash.insert(val);
    }
    
    cout << ans;
    return 0;
}