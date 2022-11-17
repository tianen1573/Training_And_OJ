//https://www.nowcoder.com/questionTerminal/cf24906056f4488c9ddb132f317e03bc?answerType=1&f=discussion
#include<deque>
#include<vector>
#include<iostream>
using namespace std;

int N, M;
deque<pair<int, int>> res;
vector<vector<int>> mapp;

bool DFS(int x, int y)
{
    if(x == N - 1 && y == M - 1)
    {
        res.push_back(make_pair(x, y));
        return true;
    }
    if(x >= N || y >= M || x < 0|| y < 0 || mapp[x][y] == 1)
    {
        return false;
    }
    
    res.push_back(make_pair(x, y));
    mapp[x][y] = true;
    
    //向右走
    if(DFS(x, y + 1))
    {
        return true;
    }
    //向下走
    if(DFS(x + 1, y))
    {
        return true;
    }
    //向左走
    if(DFS(x, y - 1))
    {
        return true;
    }
    //向上走
    if(DFS(x - 1, y))
    {
        return true;
    }
    else
    {
        res.pop_back();
        return false;
    }
    
}

int main()
{
    cin >> N >> M;
    mapp = vector<vector<int>>(N, vector<int>(M, 0));
    for(int i = 0; i < N; ++ i)
        for(int j = 0; j < M; ++ j)
        {
            cin >> mapp[i][j];
        }
    
    DFS(0, 0);
    
    while(!res.empty())
    {
        auto [x, y] = res.front();
        res.pop_front();
        
        cout << '(' << x << ',' << y << ')' << endl;
    }
}