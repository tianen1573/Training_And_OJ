#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unsigned long long ans = 0;

void dfs(unordered_map<int, vector<int>>& hash, unsigned long long sum, int k)
{

	if (k == 0)
	{
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i <= k; ++i)
	{
		auto& arr = hash[i];
		if (arr.empty())
			continue;

		int val = arr.back();
		sum += val;
		arr.pop_back();
		dfs(hash, sum, k - i);
		sum -= val;
		arr.emplace_back(val);
	}
}

int main()
{
	int n, k;
	unsigned long long ssum = 0;
	vector<vector<int>> arr;
	unordered_map<int, vector<int>> hash;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		int v; cin >> v;
		ssum += v;

		int cnt = 1;
		int sum = 0;
		for (int i = 0; i < 31; ++i)
			if (v & (1 << i))
			{
				sum += (1 << i);
				hash[cnt].push_back(sum);
				++cnt;
			}
	}
	for (auto& it : hash)
	{
		auto& tmp = it.second;
		sort(tmp.begin(), tmp.end());
	}

	dfs(hash, 0, k);

	cout << ssum - ans;
	

	return 0;
}