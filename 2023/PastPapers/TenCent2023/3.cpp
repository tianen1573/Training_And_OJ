#define _CRT_SECURE_NO_WARNINGS 1

/*
* 有n个怪物，第i个怪物的战斗力为ai，初始时，牛牛的战斗力为0。牛牛要与这n个怪物战斗，设牛牛与第i个怪物战斗时牛牛的战斗力为,，则:
* 1.若c <a，则牛牛触发被动技能"勇敢牛牛不怕困难"使得自己的战斗力提升至a;并战胜这个怪物，这会让牛牛的勇气值提升a;一。
* 2.若a ≥a;，则牛牛会直接战胜这个怪物，并且本次战斗结束后，牛牛的战斗力会降低至ai。
* 牛牛可以任意决定与怪物战斗的顺序，牛牛想知道打败完所有的n只怪物之后，牛牛累计提升的勇气值最大可能是多少。
*/

#include <iostream>
#include <vector>

using namespace std;


//int main()
//{
//	int n; cin >> n;
//	vector<int> arr(n + 1);
//	arr[0] = 0;
//	for (int i = 1; i <= n; ++i)
//		cin >> arr[i];
//	
//	unsigned long long sum = 0;
//	for (int low = 0, up = n; low < up; ++low, --up)
//		sum += (arr[up] - arr[low]);
//
//	cout << sum;
//
//	return 0;
//}