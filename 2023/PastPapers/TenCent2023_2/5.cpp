// 有n个点，第i个点的坐标为x，第i个点的颜色为cj。如果c=0，则第i个点为红点。
// 如果C=1，则第i个点为蓝点。
// 每次你可以做以下两种操作之—:
// 1.选择一个红点，设这个红点的坐标为×，把这个点移动到x-1或×＋1。2.选择一个蓝点，将它变为红点。
// 你可以最多做k次操作2, 求最少要进行多少次操作1可以使得任意两个红点之间不存在蓝点。
// 即设两个红点分别在坐标x,y(x <= y)，则不存在任何一个蓝点的坐标在区间[x.y]内。

// 思路：优先改变中间的颜色?