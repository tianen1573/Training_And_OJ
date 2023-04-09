class Solution {

  private :
    const int MOD = 1000000007;
  public:

    int InversePairs(vector<int> data) {

        int ret = 0;

        vector<int> arr(data.size());

        //归并排序 -- 可以在排序的时候 -- 统计 逆序对
        mergeSort(data, arr, 0, data.size() - 1, ret);

        return ret;

    }

    void mergeSort(vector<int> &arr, vector<int> &tmp, int l, int r, int &ret)
    {
        if(l >= r) return ;

        //分治
        int mid = l + ((r - l) >> 1);
        mergeSort(arr, tmp, l, mid, ret);
        mergeSort(arr, tmp, mid+1, r, ret);
        merge(arr, tmp, l, mid, r, ret);
        //合并 -- 并求逆序对
    }
    void merge(vector<int> &arr, vector<int> &tmp, int l, int mid, int r, int &ret)//输出型参数
    {
        int i = l, j = mid + 1, k = 0;//左区间开头，右区间开头，周转链表开头

        while(i <= mid && j <= r)
        {
            if(arr[i] > arr[j])//左大于右
            {
                tmp[k ++ ] = arr[j ++ ];
                ret += (mid - i + 1);//则左边的[i, mid)的元素 都大于右边的[j]
                ret %= MOD;
            }
            else {
                tmp[k ++ ] = arr[i ++ ];
            }
        }
        while (i <= mid) {
            tmp[k++] = arr[i++];
        }
        while (j <= r) {
            tmp[k++] = arr[j++];
        }

        //拷贝到原链表
        for (k = 0, i = l; i <= r; ++i, ++k) {
            arr[i] = tmp[k];
        }
    }
};