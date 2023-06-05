#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 5e5 + 11;
typedef long long LL;
typedef pair<LL, int> PLI;

long long v[N];
int r[N], l[N];

int n, k;

void del(int pos)
{
    r[l[pos]] = r[pos], l[r[pos]] = l[pos];
    v[r[pos]] += v[pos], v[l[pos]] += v[pos];
}

int main()
{
    priority_queue<PLI, vector<PLI>, greater<PLI>> hp;//PLI, 左边是第i个元素被插入时的值

    cin >> n >> k;
    r[0] = 1, l[n + 1] = n;//两个端点
    for(int i = 1; i <= n; ++ i)
    {
        cin >> v[i];
        l[i] = i - 1, r[i] = i + 1;
        hp.push({v[i], i});
    }

    while(k -- )
    {
        auto t = hp.top(); hp.pop();
        if(t.first != v[t.second])//说明t.second是被更新过的，需要重新入队
        {
            ++ k;
            hp.push({v[t.second], t.second});
        }
        else
            del(t.second);
    }

    int head = r[0];
    while(head != n + 1)
        cout << v[head] << ' ', head = r[head];

    return 0;
}