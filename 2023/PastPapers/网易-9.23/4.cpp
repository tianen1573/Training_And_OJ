#include <iostream>
using namespace std;

int main() {
    
}
// 64 位输出请用 printf("%lld")

// f(i)能够分解成f(1)^F1[i] * f(2)^F2[i] * (c^d)^F3[i]
// F1[i] = F1[i - 1] + F1[i - 2]
// F2[i] = F2[i - 1] + F2[i - 2]
// F3[i] = F3[i - 1] + F3[i - 2] + 1;
// 进而转换成了DP矩阵快速幂的形式
// 首先需要因式分解f(1),f(2),c^d, 保存其因子个数 记为x
// 再对F1,F2,F3进行矩阵快速幂 记为y
// 再对x^y进行快速幂求解
// 最后三者相乘得到的是f(i) 记为z
// ans = (z - 1) * 2