class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> toRig;
        vector<int> ret;

        for(int i = 0; i < asteroids.size(); ++ i)
        {
            if(asteroids[i] > 0)
                toRig.push(asteroids[i]);
            else
            {
                while(toRig.size() && -asteroids[i] > toRig.top())
                    toRig.pop();
                
                if(toRig.empty()) // 向左飞走了
                    ret.push_back(asteroids[i]);
                else // 被陨石挡住了
                {
                    // 双方都爆炸
                    if(toRig.top() == -asteroids[i])
                        toRig.pop();
                    // 仅自己爆炸
                }
            }
        }

        int len = ret.size();
        while(toRig.size())
        {
            ret.push_back(toRig.top());
            toRig.pop();
        }
        reverse(ret.begin() + len, ret.end());
        
        return ret;
    }
};