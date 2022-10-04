#define _CRT_SECURE_NO_WARNINGS 1


/*最长连续不重复子序列*/
/* https://www.acwing.com/problem/content/801/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 1e5 + 11;
//
//int n;
//short c[N] = { 0 };
//int arr[N];
//int maxL = 1;
//
//int main()
//{
//    cin >> n;
//    for (int i = 0; i < n; i++) cin >> arr[i];
//
//    for (int i = 0, j = 0; i < n; i++)
//    {
//        c[arr[i]]++;
//        if (c[arr[i]] > 1)//值为2，即有重复元素
//        {
//            while (j < i && c[arr[j]] != 2)//找重复元素位置
//            {
//                c[arr[j]]--;
//                j++;
//            }
//            c[arr[j++]]--;
//        }
//        maxL = max(maxL, i - j + 1);//更新最大值
//    }
//
//    cout << maxL;
//    return 0;
//}

/*数组元素的目标和*/
/* https://www.acwing.com/problem/content/802/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 1e5 + 11;
//
//int n, m;
//int a[N], b[N];
//int res;
//long long x;
//
//int main()
//{
//    cin >> n >> m >> x;
//    for (int i = 0; i < n; i++) cin >> a[i];
//    for (int i = 0; i < m; i++) cin >> b[i];
//
//    int i = 0, j = m - 1;
//
//    while (i < n && j >= 0)
//    {
//        if ((long long)a[i] + b[j] == x)
//        {
//            cout << i << ' ' << j;
//            break;
//        }
//        else if ((long long)a[i] + b[j] > x) j--;
//        else i++;
//    }
//
//    return 0;
//}


/*判断子序列*/
/* https://www.acwing.com/problem/content/description/2818/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 1e5 + 11;
//
//int n, m;
//int arr[N], brr[N];
//
//int main()
//{
//    cin >> n >> m;
//    for (int i = 0; i < n; i++) cin >> arr[i];
//    for (int i = 0; i < m; i++) cin >> brr[i];
//
//    int i = 0, j = 0;
//    for (; i < m; i++)
//    {
//        if (brr[i] == arr[j]) j++;
//
//        if (j == n) break;
//    }
//
//    if (j == n) cout << "Yes";
//    else cout << "No";
//
//    return 0;
//}

/*二进制中1的个数*/
/* https://www.acwing.com/problem/content/803/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int n, val;
//
//int main()
//{
//    cin >> n;
//
//    while (n--)
//    {
//        int ans = 0;
//        cin >> val;
//
//        while (val) val -= val & (-val), ans++;//val & -val 可以得到最后一个1至尾的数值
//
//        cout << ans << " ";
//    }
//
//    return 0;
//}

/*离散化---区间和*/
/* https://www.acwing.com/activity/content/problem/content/836/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//typedef pair<int, int> PII;
//const int N = 3e5 + 7;//n个插入，2m个查询
//
//int nums[N], sum[N];//元素数组，前缀和数组
//
//vector<int> alls;//离散化插入下标和查询下标
//vector<PII> add, query;//插入信息，查询信息
//
//int n, m;
//
//int find(int x)
//{
//    int l = 0, r = alls.size() - 1;
//    while (l < r)
//    {
//        int mid = l + r >> 1;
//        if (alls[mid] >= x) r = mid;
//        else l = mid + 1;
//    }
//    return r + 1;
//}
//
//int main()
//{
//    cin >> n >> m;
//    //保存插入操作
//    for (int i = 0; i < n; i++)
//    {
//        int x, c; cin >> x >> c;
//
//        add.push_back({ x, c });//保存插入信息
//        alls.push_back(x);//保存操作下标
//    }
//    //保存查找操作
//    for (int i = 0; i < m; i++)
//    {
//        int l, r; cin >> l >> r;
//        query.push_back({ l, r });//保存查询信息
//        alls.push_back(l); alls.push_back(r);//保存查询下标
//    }
//    //去重，离散化操作下标
//    sort(alls.begin(), alls.end());
//    alls.erase(unique(alls.begin(), alls.end()), alls.end());
//    //此时，操作下标唯一，并在alls数组中有着自己的唯一映射 --》下标
//
//    //插入数据
//    for (auto ait : add)
//    {
//        int x = find(ait.first);
//        nums[x] += ait.second;
//    }
//    //前缀和
//    for (int i = 1; i <= alls.size(); i++) sum[i] = sum[i - 1] + nums[i];
//
//    //查询前缀和
//    for (auto qit : query)//qit是query的一个元素
//    {
//        int l = find(qit.first), r = find(qit.second);
//        cout << sum[r] - sum[l - 1] << endl;
//    }
//    //for (vector<PII>::iterator qite = query.begin(); qite != query.end(); qite++)//qite是query的迭代器
//    //{
//    //    int l = find(qite->first), r = find(qite->second);
//    //    cout << sum[r] - sum[l - 1] << endl;
//    //}
//    //for (int i = 0; i < m; i++)//从0开始
//    //{
//    //    int l = find(query[i].first), r = find(query[i].second);
//    //    cout << sum[r] - sum[l - 1] << endl;
//    //}
//    return 0;
//}


/*区间和并*/
/* https://www.acwing.com/problem/content/805/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//typedef pair<int, int> PII;
//
//vector <PII> vec;
//
//int n, l, r, ans;
//
//void merge(vector<PII>& segs)//保存新区间
//{
//    vector<PII> res;
//
//    sort(segs.begin(), segs.end());
//
//    int st = -2e9, ed = -2e9;
//    for (auto seg : segs)
//        if (ed < seg.first)
//        {
//            if (st != -2e9) res.push_back({ st, ed });//比较区间不保存
//            st = seg.first, ed = seg.second;
//        }
//        else ed = max(ed, seg.second);//更新右端点
//
//    if (st != -2e9) res.push_back({ st, ed });
//
//    segs = res;
//}
//
//
//int main()
//{
//    cin >> n;
//
//    while (n--)
//    {
//        cin >> l >> r;
//        vec.push_back({ l, r });
//    }
//    sort(vec.begin(), vec.end());
//
//    int l = -1e9 - 7, r = -1e9 - 7;
//    for (int i = 0; i < vec.size(); i++)
//    {
//        if (vec[i].first <= r) //相交
//            if (vec[i].second > r) r = vec[i].second;//若新区间右端点更大，更新右端点
//            else
//            {
//                l = vec[i].first; r = vec[i].second;//不相交，更新左右端点
//                ans++;//不相交，则存在新区间，ans++
//            }
//    }
//    cout << ans;
//    return 0;
//}

