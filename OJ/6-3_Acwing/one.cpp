#define _CRT_SECURE_NO_WARNINGS 1

/*快排模板*/
/* https://www.acwing.com/problem/content/787/ */
//#include<iostream>
//using namespace std;
//
//const int N = 1e5 + 7;
//int nums[N];
//
//void quickSort(int nums[], int l, int r)
//{
//    if (l >= r) return;
//
//    int i = l - 1, j = r + 1, val = nums[l + r >> 1];//取中间值更有效
//    while (i < j)
//    {
//        do i++; while (nums[i] < val && i < r);
//        do j--; while (nums[j] > val && j > l);
//        if (i < j) swap(nums[i], nums[j]);
//        else break;
//    }
//
//    quickSort(nums, l, j);
//    quickSort(nums, j + 1, r);
//    /*
//    左半区间为空时，[l, j],[j+1, r]可避免死循环，如（1，2）
//    右半区间为空时，[l, i - 1],[i, r],如（2，1）
//    */
//    return;
//}
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//
//    for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);
//
//    quickSort(nums, 1, n);
//
//    for (int i = 1; i <= n; i++) printf("%d ", nums[i]);
//
//    return 0;
//}

/*第k个数*/
/* https://www.acwing.com/problem/content/788/ */
//#include <iostream>
//#include <algorithm>
//#include <stdlib.h>
//using namespace std;
//
//const int N = 1e5 + 7;
//int nums[N];
//
//void qiuckSort(int nums[], int l, int r)
//{
//    if (l >= r) return;
//    int i = l - 1, j = r + 1, val = nums[l + r >> 1];
//    while (i < j)
//    {
//        do i++; while (nums[i] < val && i < r);
//        do j--; while (nums[j] > val && j > l);
//        if (i < j) swap(nums[i], nums[j]);
//        else break;
//    }
//
//    qiuckSort(nums, l, j), qiuckSort(nums, j + 1, r);
//
//    return;
//}
//
//int main()
//{
//    int n = 0, k = 0;
//    cin >> n >> k;
//    for (int i = 1; i <= n; i++) cin >> nums[i];
//
//    qiuckSort(nums, 1, n);
//    //sort(nums + 1, nums + 1 + n);
//
//    cout << nums[k];
//
//    return 0;
//}

/*归并模板*/
/* https://www.acwing.com/problem/content/789/ */
//#include <stdlib.h>
//#include <iostream>
//
//using namespace std;
//
//const int N = 1e5 + 7;
//int nums[N], tmp[N];
// /*
// 先分割，再合并排序，最后复制到原数组对应位置
// */
//void mergeSort(int nums[], int l, int r)
//{
//    if (l >= r) return;
//
//    int mid = (l + r) >> 1;
//
//    mergeSort(nums, l, mid), mergeSort(nums, mid + 1, r);//先分割
//
//    int k = 0, i = l, j = mid + 1;
//
//    //再合并至辅助数组
//    while (i <= mid && j <= r)
//    {
//        if (nums[i] <= nums[j]) tmp[k++] = nums[i++];
//        else tmp[k++] = nums[j++];
//    }
//    while (i <= mid) tmp[k++] = nums[i++];
//    while (j <= r) tmp[k++] = nums[j++];
//
//    //复制到原数组对应位置
//    for (i = l, j = 0; i <= r; i++, j++) nums[i] = tmp[j];
//
//}
//
//int main()
//{
//    int n = 0;
//    cin >> n;
//
//    for (int i = 1; i <= n; i++) cin >> nums[i];
//
//    mergeSort(nums, 1, n);
//
//    for (int i = 1; i <= n; i++) cout << nums[i] << " ";
//
//    return 0;
//}

/*逆序对的数量*/
/* https://www.acwing.com/problem/content/790/ */
//#include <stdlib.h>
//#include <iostream>
//
//using namespace std;
//
//const int N = 1e5 + 7;
//int nums[N], tmp[N];
//long long count = 0;
// /*
// 先分割，再合并排序，最后复制到原数组对应位置
// */
//void mergeSort(int nums[], int l, int r)
//{
//    if (l >= r) return;
//
//    int mid = (l + r) >> 1;
//
//    mergeSort(nums, l, mid), mergeSort(nums, mid + 1, r);//先分割
//
//    int k = 0, i = l, j = mid + 1;
//
//    //再合并至辅助数组
//
//    while (i <= mid && j <= r)
//    {
//        if (nums[i] <= nums[j]) tmp[k++] = nums[i++];
//        /*
//        首先，i对应部分，一定在j对应的数组区间之前，即 i < j 恒成立
//        其次，若nums[i] > nums[j], 则 i 至 mid 都大于nums[j]，因为i和j对应的数组是有序的
//        则，大于nums[j] 的有 mid - i + 1 个
//        */
//        else count += mid - i + 1, tmp[k++] = nums[j++];
//    }
//    while (i <= mid) tmp[k++] = nums[i++];
//    while (j <= r) tmp[k++] = nums[j++];
//
//    //复制到原数组对应位置
//    for (i = l, j = 0; i <= r; i++, j++) nums[i] = tmp[j];
//
//}
//
//int main()
//{
//    int n = 0;
//    cin >> n;
//
//    for (int i = 1; i <= n; i++) cin >> nums[i];
//    mergeSort(nums, 1, n);
//
//    cout << count << endl;
//
//    return 0;
//}
