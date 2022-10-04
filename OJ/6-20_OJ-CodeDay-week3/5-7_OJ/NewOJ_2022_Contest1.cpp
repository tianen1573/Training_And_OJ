#define _CRT_SECURE_NO_WARNINGS 1

/*NewOJ_2022_Contest1*/
/* http://oj.ecustacm.cn/contest.php?cid=1023 */

/*A. 质数*/
//#include<stdlib.h>
//#include<iostream>
//#include<math.h>
//using namespace std;
//
//bool Prime(long num)
//{
//	for (int i = 2;i <= sqrt(num); i++)
//	{
//		if (num % i == 0)
//			return true;
//	}
//	return false;
//}
//
//int main()
//{
//	long num = 20222022;
//	for (; Prime(num); num++);
//
//	cout << num << endl;
//
//	return 0;
//}

/*B. 01卡片*/
//#include<stdlib.h>
//#include<iostream>
//#include<math.h>
//using namespace std;
//
//short nums[28];
//long long count1 = 0;
//long long count0 = 0;
//int count11 = 0;
//int count00 = 0;
//
//
//void Carry()
//{
//	count11 += 1;
//	count00 = count00 - 1 > 0 ? count00 - 1 : 0;
//
//	short carry = 1;
//	short carryCount = 0;
//
//	for (int i = 27; i >= 0 && carry; i--)
//	{
//		short sum = carry + nums[i];
//		carry = sum / 2;
//		if (carry == 1)
//			carryCount++;
//		nums[i] = sum % 2;
//	}
//
//	count11 -= carryCount;
//	count00 += carryCount;
//
//	count1 += count11;
//	count0 += count00;
//
//}
//
//int main()
//{
//	
//
//	for (int i = 0; i < 20222022; i++)
//	{
//		Carry();
//	}
//
//	cout << count0 << " " << count1 << endl;
//
//	return 0;
//}

/*C. 数位和*/
//#include<stdlib.h>
//#include<iostream>
//#include<math.h>
//using namespace std;
//
//int Count;
//
//int FunX(int num)
//{
//	int count = 1;
//
//	if (num < 10)
//		return count;
//
//	while (num > 9)
//	{
//		count++;
//		num = num / 1000 + (num % 1000) / 100 + (num % 100) / 10 + (num % 10) / 1;
//	}
//	
//	return count;
//}
//
//int main()
//{
//	int x, y, z;
//
//	for(z = 1; z <= 2020; z++)
//		for (y = z + 1; y <= 2021; y++)
//		{
//			if (FunX(z) >= FunX(y))
//				continue;
//			for (x = y + 1; x <= 2022; x++)
//			{
//				if (FunX(y) < FunX(x))
//					Count++;
//			}
//		}
//
//	cout << Count << endl;
//	return 0;
//}

/*D. 地图*/
//#include<stdlib.h>
//#include<iostream>
//using namespace std;
//char map[51][51];
//int rc = 50;
//
//int lag = 3;
//int Count = 0;
//
////pos
//int posRow = 0;
//int posCol = 1;
//
////direction
//int dirRow = 0;
//int dirCol = 1;
//
//void move()
//{
//	//end
//	if (posCol == posRow && posCol == rc - 1)
//	{
//		Count++;
//		return;
//	}
//
//	//one-move
//	if (posRow + dirRow < rc && posCol + dirCol < rc &&
//		map[posRow + dirRow][posCol + dirCol] != '*')
//	{
//		posRow += dirRow;
//		posCol += dirCol;
//
//		move();
//		
//		posRow -= dirRow;
//		posCol -= dirCol;
//
//	}
//	//two-change direction
//	if (lag > 0)
//	{
//		int tmpR = dirRow;
//		int tmpC = dirCol;
//
//		lag--;		
//		dirRow = (dirRow + 1) % 2;
//		dirCol = (dirCol + 1) % 2;
//
//		move();
//
//
//		lag++;
//		dirRow = tmpR;
//		dirCol = tmpC;
//
//	}
//
//
//}
//
//int main()
//{
//	for (int i = 0; i < rc; i++)
//		cin >> map[i];
//	
//	//first right
//	dirRow = 0;
//	dirCol = 1;
//	move();
//	
//	//first down
//	dirCol = 0;
//	dirRow = 1;
//
//	posRow = 1;
//	posCol = 0;
//	lag = 3;
//	move();
//	
//
//	cout << Count;
//
//	return 0;
//}

//官解-dp
//#include<stdlib.h>
//#include<iostream>
//using namespace std;
//int n, k;
//char Map[55][55];
//int dir[][2] = { 0, 1, 1, 0 };
//int dp[55][55][2][4];
//int dfs(int x, int y, int d, int step)
//{
//    if (x > n || y > n)return 0;     //越界
//    if (Map[x][y] == '*')return 0;   //障碍物
//    if (step > k)return 0;           //转弯次数超过k
//    if (x == n && y == n)return 1;   //终点
//    if (dp[x][y][d][step])return dp[x][y][d][step];  //记忆化搜索
//    int ans = 0;
//    for (int i = 0; i <= 1; i++)     //两种方向
//        ans += dfs(x + dir[i][0], y + dir[i][1], i, step + (i != d));
//    return dp[x][y][d][step] = ans;
//}
//
//int main()
//{
//    n = 50;
//    k = 3;
//    for (int i = 1; i <= n; i++)cin >> (Map[i] + 1);
//    memset(dp, 0, sizeof(dp));
//    int ans = 0;
//    if (Map[1][2] != '*')ans += dfs(1, 2, 0, 0);
//    if (Map[2][1] != '*')ans += dfs(2, 1, 1, 0);
//    cout << ans << endl;
//    return 0;
//}

/*E. 消消乐*/
//#include<stdlib.h>
//#include<iostream>
//using namespace std;
//
//int X[10005];
//int Y[10005];
//int Sx[105];
//int Sy[105];
//
//int main()
//{
//	int n = 0;
//	int tmp = 0;
//
//	cin >> n;
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			cin >> tmp;
//			X[tmp] = i;
//			Y[tmp] = j;
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		Sx[i] = n;
//		Sy[i] = n;
//	}
//
//	for (int i = 1; i <= n * n; i++)
//	{
//		cin >> tmp;
//		Sx[X[tmp]]--, Sy[Y[tmp]]--;
//		if (!Sx[X[tmp]] || !Sy[Y[tmp]])
//		{
//			cout << tmp << endl;
//			break;
//		}
//	}
//
//	return 0;
//}

