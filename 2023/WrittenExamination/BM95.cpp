class Solution {
public:

    // 把数据转换成折线，每个谷底都赋值为1
    // 爬坡代表糖果+1，峰顶的大小和左右峰坡长度有关
    // 如果存在平直线，则直线两端受峰坡影响，中间节点都赋值为1
    int candy(vector<int>& arr) {
        
        vector<int> cnt(arr.size(), 1);

        //正序
        for(int i = 1; i < arr.size(); ++ i)
        {
            if(arr[i] > arr[i - 1])
                cnt[i] = cnt[i - 1] + 1;
        }
        //反序
        for(int i = arr.size() - 2; i >= 0; -- i)
        {
            if(arr[i] > arr[ i + 1])
                cnt[i] = max(cnt[i], cnt[i + 1] + 1);
        }
        int sum = 0;
        for(int i = 0; i < arr.size(); ++ i)
        {
            sum += cnt[i];
        }

        return sum;
    }
};