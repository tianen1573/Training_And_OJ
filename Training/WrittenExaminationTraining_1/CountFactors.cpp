//https://www.nowcoder.com/questionTerminal/e8fb8f89f5d147ec92fd8ecfefe89b0d
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

bool prime(int p)
{
    if(p == 1) return false;
	if (p == 2 || p == 3) return true; 
	if (p % 6 != 1 && p % 6 != 5) return false; 
	
	for (int i = 5; i <= floor(sqrt(p)); i += 6)
	{
		if (p % i == 0 || p % (i + 2) == 0)
			return false;
	}
	
	return true;
}

int CountF(int num)
{
    if(prime(num))//剪纸
        return 1;
    
    int res = 0;
    
    for(int i = 2; i <= sqrt(num); ++ i)//不开方，会超时
    {
        if(num % i == 0)
        {
            res ++;
        }
        
        while(num % i == 0)
        {
            num /= i;
        }
        
        if(prime(num))//剪枝
        {
            return res + 1;
        }

    }
    
    return res;
    
}


int main()
{
    int num;
    
    while(cin >> num)
    {
        cout << CountF(num) << endl;
    }
    
    return 0;
}
