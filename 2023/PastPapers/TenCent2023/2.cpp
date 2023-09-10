#define _CRT_SECURE_NO_WARNINGS 1

/*
* 牛牛有一个长度为n的序列a，以及一个长度为n ―1的序列b，序列b中的元素不重复。
* 对于这个序列a牛牛会先求出他的中位数，然后再根据序列b的顺序依次删除原序列a中对应下标的元素，即删除a[b[刚]],0<i<n 一 1。
* 每次删除完一个数后，牛牛会统计序列a中剩下的数的中位数是什么，若剩下的数为奇数牛牛会取中间数(排序后)，若为偶数牛牛会取中间两个数的平均值(排序后)。
* 牛牛把每次的结果都记录下来了，但是他怕出错，给你初始的序列a和b，希望你能帮他验证一下。
*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

struct DBL
{
	int val;
	DBL* pre;
	DBL* next;

	DBL(int v) : val(v){};
};