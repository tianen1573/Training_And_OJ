#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

const int N = 10010;

int arr[N];

int n;

//哈夫曼树
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    priority_queue<int, vector<int>, greater<int> > heap;
    
    cin >> n;
    while(n --)
    {
        int val; cin >> val;
        heap.push(val);
    }
    
    int res = 0;
    while(heap.size() > 1)
    {
        auto l = heap.top();
        heap.pop();
        auto r = heap.top();
        heap.pop();
        
        auto sum = l + r;
        res += sum;
        
        heap.push(sum);
    }
    
    cout << res;
    
    return 0;
}