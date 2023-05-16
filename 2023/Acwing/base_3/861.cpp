// 作者：Hasity
// 链接：https://www.acwing.com/solution/content/179030/

#include<iostream>
#include <cstring>
#include<algorithm>
using namespace std;
// 邻接表存储图
int n1, n2, m;
int h[500], e[100010],ne[100010], idx = 0;
//st 标记是否递归找过， match[x]：和 x 编号 牵手 的男生的编号
int st[510], match[510];
//存图函数
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a]; h[a] = idx++;
}
//递归找可以匹配的点
bool find(int x){
    // 和各个点尝试能否匹配
    for(int i = h[x]; i != -1; i = ne[i]){
        int b = e[i];
        if(!st[b]){//打标记
            st[b] = 1;
            // 当前尝试点没有被匹配或者和当前尝试点匹配的那个点可以换另一个匹配
            if(match[b] == 0 || find(match[b])){
                // 和当前尝试点匹配在一起
                match[b] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    memset(h, -1, sizeof h);
    cin >> n1 >> n2 >> m;
    // 保存图，因为只从一遍找另一边，所以该无向图只需要存储一个方向
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    int res = 0;
    //为各个点找匹配
    for(int i = 1; i <= n1; i++){
        memset(st, 0, sizeof st);
        //找到匹配
        if(find(i)) res++;
    }
    cout << res;
    return 0;
}