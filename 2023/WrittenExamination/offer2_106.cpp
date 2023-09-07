class Solution {
private:
    bool colorDfs(vector<int>& color, vector<vector<int>>& graph, int u, int c)
    {
        // 第一步：上色
        color[u] = c;

        // 第二步：给连接点上色
        for(int i = 0; i < graph[u].size(); ++ i)
        {
            int j = graph[u][i];
            // 如果没上色
            if(color[j] == 0)
            {
                // 上和c相反的色
                if(colorDfs(color, graph, j, 3 - c) == false)
                    return false; // 上色失败
            }
            // 如果上过色，则需要和c相反
            else if(color[j] == c)
                return false;
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {

        vector<int> color(graph.size(), 0);

        bool flag = true;
        for(int i = 0; i < graph.size(); ++ i)
        {
            if(color[i] == 0)
            {
                if(colorDfs(color, graph, i, 1) == false)
                {
                    flag = false;
                    break;
                }
            }
        }

        return flag;
    }
};