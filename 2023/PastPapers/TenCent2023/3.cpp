#define _CRT_SECURE_NO_WARNINGS 1

/*
* ��n�������i�������ս����Ϊai����ʼʱ��ţţ��ս����Ϊ0��ţţҪ����n������ս������ţţ���i������ս��ʱţţ��ս����Ϊ,����:
* 1.��c <a����ţţ������������"�¸�ţţ��������"ʹ���Լ���ս����������a;��սʤ�����������ţţ������ֵ����a;һ��
* 2.��a ��a;����ţţ��ֱ��սʤ���������ұ���ս��������ţţ��ս�����ή����ai��
* ţţ����������������ս����˳��ţţ��֪����������е�nֻ����֮��ţţ�ۼ�����������ֵ�������Ƕ��١�
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