#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<vector<int>> hash;

    for (int i = 0; i < n; ++ i) {
        string tmp;
        vector<int> arr(26, 0);
        cin >> tmp;
        for (int i = 0; i < tmp.size(); ++ i)
            arr[tmp[i] - 'a']++;

        hash.emplace(arr);
    }

    cout << hash.size();

    return 0;
}
// 64 位输出请用 printf("%lld")