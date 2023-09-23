#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() 
{
    int n, k;
    string str;
    cin >> n >> k >> str;
    vector<int> left, right;
    for(int i = 2; i < n; ++ i)
    {
        if(str[i] == str[i - 1] && str[i - 1] == str[i - 2])
        {
            left.push_back(i - 2);
            right.push_back(i);
        }
    }
    int len = left.size();

    while(k --)
    {
        int l, r; cin >> l >> r;
        -- l, -- r;
        if(len == 0 || r - l < 2 || l > left[len - 1] || r < right[0])
        {
            printf("0\n");
            continue;
        }

        unsigned int star = 0, end = len - 1;
        while(star < end)
        {
            unsigned int mid = (star + end) >> 1;
            if(left[mid] >= l)
                end = mid;
            else
                star = mid + 1;
        }
        int ll = star;
        // cout << ll << " ";
        star = 0, end = len - 1;
        while(star < end)
        {
            unsigned int mid = (star + end + 1) >> 1;
            if(right[mid] <= r)
                star = mid;
            else
                end = mid - 1;
        }
        int rr = star;
        // cout << rr << endl;
        printf("%d\n", rr - ll + 1);
    }

    return 0;
}
// 64 位输出请用 printf("%lld")
// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// int main() 
// {
//     int n, k;
//     string str;
//     cin >> n >> k >> str;
//     vector<int> pre(n + 1, 0);
//     for(int i = 3; i <= n; ++ i)
//     {
//         pre[i] = pre[i - 1];
//         if(str[i - 1] == str[i - 2] && str[i - 2] == str[i - 3])
//             ++ pre[i];
//     }
    
//     while(k --)
//     {
//         int l, r; cin >> l >> r;
//         if(pre[n] == 0 || r - l < 2)
//         {
//             printf("0\n");
//             continue;
//         }

//         printf("%d\n", pre[r] - pre[l + 1]);
//     }

//     return 0;
// }
// // 64 位输出请用 printf("%lld")