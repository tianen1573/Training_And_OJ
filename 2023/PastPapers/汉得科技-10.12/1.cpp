#include <iostream>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    
    while(t --)
    {
        int n;
        cin >> n;
        if(n < 9)
            cout << "0\n";
        else
        {
            n /= 3;
            if(n % 2)
            {
                n = (n - 1) / 2 * (n - 2);
            }
            else 
            {
                n = (n - 2) / 2 * (n - 1);
            }

            cout << n << endl;
        }
    }

    return 0;    
}
// 64 位输出请用 printf("%lld")