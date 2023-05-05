
class Solution {
public:
     int countDigitOne(int n) {
        uint64_t digit = 1, res = 0;
        uint64_t high = n / 10, cur = n % 10, low = 0;
        while(high != 0 || cur != 0) {
            if(cur == 0) res += high * digit;
            else if(cur == 1) res += high * digit + low + 1;
            else res += (high + 1) * digit;
            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }
        return res;
    }
};

// class Solution {
//     /**
//      * 假设当前要讨论的数是 abcdefg，我们当前对 d 这一位的取值进行讨论，看在 d 的不同取值下，这一位（d位）是1的数有多少个。
//      * <p>
//      *   -若 d=0，则前三位的取值范围为 000∼abc−1，后三位的取值范围为 000∼999，这样合法的数就有 abc⋅1000 个
//      *   -若 d=1
//      *     -前三位取 000∼abc−1，后三位取 000∼999，这样合法的数就有 abc⋅1000 个
//      *     -前三位取 abc，后三位取 000∼efg，这样合法的数就有 efg+1 个
//      *   -若 d>1，则前三位取 000∼abc，后三位取 000∼999，这样合法的数有 (abc+1)⋅1000
//      * 每一位都像这样讨论，就可以算出来所有合法的数的个数。
//      * <p>
//      */
//     public int countDigitOne(int n) {
//         List<Integer> nums = new ArrayList<>();
//         while (n > 0) {
//             nums.add(n % 10);
//             n /= 10;
//         }
//         int ret = 0;
//         for (int i = nums.size() - 1; i >= 0; i--) {
//             int cur = nums.get(i);
//             int left = 0, right = 0, power = 1;
//             for (int j = nums.size() - 1; j > i; j--) left = left * 10 + nums.get(j);
//             for (int j = i - 1; j >= 0; j--) {
//                 right = right * 10 + nums.get(j);
//                 power *= 10;
//             }
//             if (cur == 0) ret += left * power;
//             else if (cur == 1) ret += left * power + right + 1;
//             else ret += (left + 1) * power; // cur > 1
//         }
//         return ret;
//     }
// }