void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    nums1Size = m + n;
    int Len = m-- + n-- - 1;
    while(m >= 0 && n >= 0)
    {
        if(nums1[m] > nums2[n])
        {
            nums1[Len] = nums1[m];
            m--;
            Len--;
        }
        else
        {
            nums1[Len] = nums2[n];
            n--;
            Len--;
        }
    }
    while(m >= 0)
    {
        nums1[Len--] = nums1[m--];
    }
    while(n >= 0)
    {
        nums1[Len--] = nums2[n--];
    }

}