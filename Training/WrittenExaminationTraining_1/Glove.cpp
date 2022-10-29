// 在地下室里放着n种颜色的手套，手套分左右手，但是每种颜色的左右手手套个数不一定相同。
// A先生现在要出门，所以他要去地下室选手套。但是昏暗的灯光让他无法分辨手套的颜色，只能分辨出左右手。
// 所以他会多拿一些手套，然后选出一双颜色相同的左右手手套。
// 现在的问题是，他至少要拿多少只手套(左手加右手)，才能保证一定能选出一双颜色相同的手套。
// 给定颜色种数n(1≤n≤13),同时给定两个长度为n的数组left,right,分别代表每种颜色左右手手套的数量。
// 数据保证左右的手套总数均不超过26，且一定存在至少—种合法方案。

class Gloves {
public:
    
    // https://www.nowcoder.com/questionTerminal/365d5722fff640a0b6684391153e58d8
    // 将左手 或 右手  全取到， 则另一个手，只需取一种即可， 则除了最小的全取， 最小的去一个
    // 因为存在只有左手或右手的情况， 这类手套必须全取
    // 判断 全取 左手小 还是 全取 右手 小， 即可
    int findMinimum(int n, vector<int> left, vector<int> right) {
        
        int onlyOne = 0;
        int lAll = 0, rAll = 0;
        int lMin = 31, rMin = 31;
        for(int i = 0; i < n; ++ i)
        {
            //单手套不参与最小值比较
            if(left[i] == 0 || right[i] == 0)
            {
                onlyOne += (left[i] + right[i]);
            }
            else//
            {
                lAll += left[i];
                rAll += right[i];
                lMin = min(lMin, left[i]);
                rMin = min(rMin, right[i]);
            }
        }
        
        //min选出最小全拿的手，onlyOne是单手套， 1是另一只手取一个
        int res = min(lAll + 1 - lMin, rAll + 1 - rMin) + onlyOne + 1;
        
        return res;
    }
};