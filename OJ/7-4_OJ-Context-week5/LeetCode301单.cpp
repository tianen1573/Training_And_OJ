#define _CRT_SECURE_NO_WARNINGS 1

/* https://leetcode.cn/contest/weekly-contest-301/ */

/*装满杯子需要的最短时间*/
//class Solution {
//public:
//
//    int fillCups(vector<int>& amount) {
//
//        int cnt = 0;
//        while (true)
//        {
//            sort(amount.begin(), amount.end(), [&](int& a, int& b)//降序
//                {
//                    return a > b;
//                });
//            if (amount[0] > 0)
//            {
//                amount[0]--;
//                amount[1]--;
//                cnt++;
//            }
//            else break;
//        }
//        return cnt;
//
//    }
//};

/*无限集中的最小数字*/
// /*set*/
//class SmallestInfiniteSet {
//    set<int> sma;
//public:
//    SmallestInfiniteSet() {
//        sma.clear();
//        for (int i = 1; i <= 1000; i++) sma.insert(i);
//
//    }
//
//    int popSmallest() {
//
//        int a = *(sma.begin());
//        sma.erase(sma.begin());
//
//        return a;
//
//    }
//
//    void addBack(int num) {
//        sma.insert(num);
//    }
//};
// /*模拟
//class SmallestInfiniteSet {
//    int _min = 1;
//    bool arr[1007] = {0};
//    int size = 0;
//public:
//    SmallestInfiniteSet() {
//
//        _min = 1;//初始化连续最小数
//        memset(arr, 0, sizeof(arr));//初始化插入数
//
//    }
//
//    int popSmallest() {
//        int pos = -1;
//        for(int i = 1; i < _min; i++)//先求插入最小
//            if(arr[i])
//            {
//                pos = i;
//                break;
//            }
//        if(pos != -1)//若存在
//        {
//            arr[pos] = false;
//            return pos;
//        }
//        else//不存在
//        {
//            _min++;
//            return _min - 1;
//        }
//
//    }
//
//    void addBack(int num) {
//        if(num >= _min) return ;
//
//        arr[num] = true;
//
//    }
//};*/
// /**
// * Your SmallestInfiniteSet object will be instantiated and called as such:
// * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
// * int param_1 = obj->popSmallest();
// * obj->addBack(num);
// */

/*移动片段得到字符串*/
////首先字母序必须对应
////其次， 对应的，s的L必须在t的右边，s的R必须在t的左边
//class Solution {
//public:
//    bool canChange(string start, string target) {
//
//        int j = 0;
//        for (int i = 0; i < start.size(); i++)//左至右依次判断
//        {
//            if (start[i] == '_') continue;
//            while (j < start.size() && target[j] == '_') j++;
//
//            if (j == start.size()) return false;//越界
//            if (start[i] != target[j]) return false;//字母不同
//            if (start[i] == 'L' && i < j) return false;//s的L ，在 t的L 的左边，则s的L无法向右移动
//            if (start[i] == 'R' && i > j) return false;//同理
//            j++;//后移
//        }
//
//        //判断 s无字符 而 t有字符
//        for (j; j < start.size(); j++)
//            if (target[j] != '_') return false;
//
//        return true;
//
//    }
//};

/*统计理想数组的数目--数论*/
////DP
//class Solution {
//public:
//    int idealArrays(int n, int maxValue) {
//        const int MOD = 1e9 + 7;
//        vector< vector<int> > f(maxValue + 1, vector<int>(15));
//        for (int i = 1; i <= maxValue; i++) f[i][1] = 1;//以i结尾，只有一个元素
//
//        for (int j = 1; j < 14; j++)//j最多为14 -- 1*2^14 ,此时的j为统计过的，则最多为13
//            for (int i = 1; i <= maxValue; i++)
//                for (int k = 2; k * i <= maxValue; k++)//模拟倍数
//                    f[k * i][j + 1] = (f[k * i][j + 1] + f[i][j]) % MOD;
//
//        //求组合数
//        vector< vector<int> > C(n, vector<int>(15));
//        for (int i = 0; i < n; i++)
//            for (int j = 0; j <= i && j <= 14; j++)
//                if (j == 0) C[i][j] = 1;
//                else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
//
//        int res = 0;
//        for (int i = 1; i <= maxValue; i++)
//            for (int j = 1; j <= 14 && j <= n; j++)//j从1开始， 最大值为 min(14, n)
//                res = (res + (long long)f[i][j] * C[n - 1][j - 1]) % MOD;
//
//        return res;
//    }
//};
////作者--yxc
////f[i][j] -- 以i结尾，存在j中不同元素
////i = (1, maxV), j = (1, 14) --> 最小倍数2，最多乘13次，算上初始1，14种元素
////则每一种状态可以代表 f[i][j] * C[n - 1][j - 1]理想数组 --> 隔板法，把n个位置，隔成j个，有n - 1个位置可以放隔板，需要j-1个隔板。
//////暴搜
////class Solution {
////public:
////    int n, m;
////    int ans = 0;
////    const int MOD = 1e9 + 7;
////    vector<vector<int>> f;
////
////    void dfs(int u, int cnt) {
////        ans = (ans + f[n - 1][cnt - 1]) % MOD;//隔板法
////        if (cnt < n) {
////            for (int i = 2; i * u <= m; i++)
////                dfs(i * u, cnt + 1);
////        }
////    }
////
////    int idealArrays(int n, int m) {
////        this->n = n, this->m = m;
////        f = vector<vector<int>>(n, vector<int>(20));
////        for (int i = 0; i < n; i++)
////            for (int j = 0; j < 20 && j <= i; j++)
////                if (!j) f[i][j] = 1;
////                else f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % MOD;
////
////        for (int i = 1; i <= m; i++)
////            dfs(i, 1);
////
////        return ans;
////    }
////};
//////作者：yxc
