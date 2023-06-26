#include <functional>
#include <queue>
class Solution {
public:
    void Insert(int num) {
        if(lMax.size() == rMin.size())
        {
            rMin.push(num);
            lMax.push(rMin.top());
            rMin.pop();
        }
        else {
            lMax.push(num);
            rMin.push(lMax.top());
            lMax.pop();
        }
        
    }

    double GetMedian() { 

        if(lMax.size() == rMin.size())
            return (lMax.top() + rMin.top()) * 1.0 / 2;
        else
            return lMax.top() * 1.0;
    
    }

    priority_queue<int, vector<int>, less<int>> lMax;
    priority_queue<int, vector<int>, greater<int>> rMin;
};