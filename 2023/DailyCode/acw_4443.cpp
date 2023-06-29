#include <iostream>
#include <cstring>

using namespace std;

int T;

double getArea(long long r)
{
    return r * r * 3.1415926;
}

int main()
{
    cin >> T;
    for(int t = 1; t <= T; ++ t)
    {
        long long R, A, B;
        cin >> R >> A >> B;
        double res = getArea(R);
        
        while(R)
        {
            R *= A;
            res += getArea(R);
            R /= B;
            res += getArea(R);
        }
        
        printf("Case #%d: %lf\n", t, res);
    }
    
    return 0;
}