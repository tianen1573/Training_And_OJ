#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

deque<int> deqMax, deqMin;
vector<int> vec, vecMax, vecMin;

int main()
{
    int n, k; scanf("%d%d", &n, &k);
    int val; 
    for(int i = 0; i < n; ++ i)
    {
        scanf("%d", &val);
        vec.push_back(val);
    }
    
    
    for(int i = 0; i < n; ++ i)
    {
        
        
        while(!deqMin.empty() && vec[deqMin.back()] > vec[i]) deqMin.pop_back();
        while(!deqMax.empty() && vec[deqMax.back()] < vec[i]) deqMax.pop_back();
        
        deqMax.push_back(i), deqMin.push_back(i);
        
        if(i < k - 1)
        {
            continue;
        }
        
        while(deqMin.front() < i - k + 1) deqMin.pop_front();
        while(deqMax.front() < i - k + 1) deqMax.pop_front();
        
        vecMax.push_back(vec[deqMax.front()]);
        vecMin.push_back(vec[deqMin.front()]);
    }
    
    for(auto& v : vecMin)
        printf("%d ", v);
    printf("\n");
    for(auto& v : vecMax)
        printf("%d ", v);
    
    
    return 0;
}