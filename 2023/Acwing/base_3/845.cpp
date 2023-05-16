//重难点：如何标记剪枝，已经遍历过的状态
//可以发现，在移动过程中，x是可以重复在某个位置的，所以我们没法用矩阵的方式来避免重复遍历
//使用的是，序列化反序列化，解码编码思想， 即将矩阵转换成字符串，存储[字符串，移动次数]
//这样第一次存储的字符串tmp，对应的操作次数，也是初始状态到达该状态最小的次数
//存储字符串可以记忆化搜索，去重
//编码解码思想

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <unordered_map>

using namespace std;

int bfs(string start)
{
    
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    
    unordered_map<string, int> umap;//字符串状态，次数
    queue<string> que;//第一次出现的状态
    
    string end = "12345678x";
    
    que.push(start);
    umap[start] = 0;
    
    while(que.size())
    {
        auto cur = que.front();
        que.pop();
        
        if(cur == end) return umap[end];
        
        int distance = umap[cur];//保存
        int k = cur.find('x');
        int x = k / 3, y = k % 3;//字符串位置 转 在矩阵中的位置
        
        //宽搜
        for(int i = 0; i < 4; ++ i)
        {
            int a = x + dx[i], b = y + dy[i];
            
            if(a >= 0 && a < 3 && b >= 0 && b < 3)//不越界
            {
                swap(cur[k], cur[a * 3 + b]);//矩阵位置 转 字符串位置
                
                if(!umap.count(cur))//第一次出现的状态
                {
                    umap[cur] = distance + 1;
                    que.push(cur);//新状态入队
                }
                
                swap(cur[a * 3 + b], cur[k]);//恢复现场
            }
        }
        
    }
    
    return -1;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    char s[2];
    string start;
    
    for(int i = 0; i < 9; ++ i)
    {
        cin >> s;//可以避免空格符的干扰
        start += *s;
    }
    
    
    cout << bfs(start) ;
    
    return 0;
}