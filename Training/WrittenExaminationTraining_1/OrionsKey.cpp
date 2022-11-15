// https://www.nowcoder.com/questionTerminal/34f17d5f2a8240bea661a23ec095a062
// –«º √‹¬Î

#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main() {
    int n;
    int index = 0;
    vector<int> code(10000, 0);
    code[0] = 1;
    code[1] = 2;
    for (int i = 2; i < 10000; i++) 
    {
        code[i] = (code[i - 1] + code[i - 2])%10000;
    }
    while (cin >> n) 
    {
        for (int i = 0; i < n; i++) 
        {
            cin >> index;
            cout << setw(4) << setfill('0') << code[index - 1];
        }
        cout << endl;
    }
}