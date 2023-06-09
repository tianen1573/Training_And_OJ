// #include <iostream>
// #include <algorithm>
// #include <cmath>

// using namespace std;

// int main()
// {
//     int t; cin >> t;

//     while(t --)
//     {
//         int n; cin >> n;
//         int odd = 0, even = 0;

//         int tmp;
//         for(int i = 0; i < n; ++ i)
//         {
//             cin >> tmp;
//             if(tmp % 2) ++ odd;
//             else ++ even;
//         }

//         if(odd % 2 == 1) cout << 0 << endl;
//         else
//         {
//             if(odd == 0) odd = 1;
//             cout << ( ((long long)pow(2, even) % 1000000007) * ((long long)pow(2, odd - 1) % 1000000007) ) % 1000000007 << endl;
//         }
        
//     }

//     return 0;
// }

// #include <iostream>
// #include <cstring>
// #include <queue>

// using namespace std;

// const int N = 100010;

// int h[N], e[N], w[N], ne[N], idx;
// int dist[N];
// bool st[N];

// int n, m;

// void add(int a, int b, int c)
// {
//     e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
// }

// int spfa()
// {
//     memset(dist, 0x3f, sizeof dist);
//     dist[1] = 0, st[1] = true;
//     queue<int> que;
//     que.push(1);

//     while(que.size())
//     {
//         auto cur = que.front(); que.pop();
//         st[cur] = false;

//         for(int i = h[cur]; ~i; i = ne[i])
//         {
//             int son = e[i], d = w[i];

//             if(dist[son] > dist[cur] + d)
//             {
//                 dist[son] = dist[cur] + d;

//                 if(st[son] == false)
//                 {
//                     st[son] = true;
//                     que.push(son);
//                 }
//             }
//         }
//     }
// }

// int main()
// {
//     memset(h, -1, sizeof h);

//     cin >> n >> m;
//     while(m --)
//     {
//         int a, b, c; cin >> a >> b >> c;
//         add(a, b, c);
//     }

//     spfa();
//     if(dist[n] > 0x3f3f3f3f / 2) cout << "impossible";
//     else cout << dist[n];

//     return 0;
// }


// #include <cstdio>
// #include <iostream>
// #include <queue>
// #include <cstring>

// using namespace std;

// const int N = 10010;

// int h[N], e[N], w[N], ne[N], idx;
// int dist[N], cnt[N];
// bool st[N];

// int n, m;

// void add(int a, int b, int c)
// {
//     e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
// }

// bool spfa()
// {
//     memset(dist, 0x3f, sizeof dist);
//     dist[1] = 0;
//     queue<int> que;
//     for(int i = 1; i <= n; ++ i)
//     {
//         st[i] = true;
//         que.push(i);
//     }

//     while(que.size())
//     {
//         auto cur = que.front(); que.pop();
//         st[cur] = false;

//         for(int i = h[cur]; ~i; i = ne[i])
//         {
//             int son = e[i], d = w[i];

//             if(dist[son] > dist[cur] + d)
//             {
//                 dist[son] = dist[cur] + d;
//                 cnt[son] = cnt[cur] + 1;

//                 if(cnt[son] >= n) return true;

//                 if(st[son] == false)
//                 {
//                     st[son] = true;
//                     que.push(son);
//                 }
//             }
//         }
//     }

//     return false;
// }

// int main()
// {
//     memset(h, -1, sizeof h);

//     cin >> n >> m;
//     while(m --)
//     {
//         int a, b, c; cin >> a >> b >> c;
//         add(a, b, c);
//     }

//     if(spfa()) cout << "Yes";
//     else cout << "No";

//     return 0;

// }

// #include <iostream>
// #include <cstring>

// using namespace std;

// const int N = 211;

// int g[N][N];

// int n, m, k;

// void floyd()
// {
//     for(int k = 1; k <= n; ++ k)
//         for(int i = 1; i <= n; ++ i)
//             for(int j = 1; j <= n; ++ j)
//                 g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
// }

// int main()
// {
//     cin >> n >> m >> k;

//     for(int i = 1; i <= n; ++ i)
//         for(int j = 1; j <= n; ++ j)
//             if(i == j) g[i][j] = 0;
//             else g[i][j] = 0x3f3f3f3f;

//     while(m --)
//     {
//         int a, b , c; cin >> a >> b >> c;
//         g[a][b] = min(g[a][b], c);
//     }

//     floyd();

//     while(k --)
//     {
//         int a, b; cin >> a >> b;
//         if(g[a][b] > 0x3f3f3f3f / 2) cout << "impossible" << endl;
//         else cout << g[a][b] << endl;
//     }

//     return 0;
// }


// #include <cstdio>
// #include <iostream>
// #include <cstring>

// using namespace std;

// const int N = 511, INF = 0x3f3f3f3f;

// int g[N][N], dist[N];
// bool st[N];

// int n, m;

// int prim()
// {
//     memset(dist, 0x3f, sizeof dist);
//     dist[1] = 0;

//     int res = 0;

//     for(int i = 0; i < n; ++ i)
//     {
//         int t = -1;
//         for(int j = 1; j <= n; ++ j)
//             if(!st[j] && (t == -1 || dist[t] > dist[j]))
//                 t = j;
//         if(i && dist[t] == INF) return INF;

//         res += dist[t];
//         st[t] = true;

//         for(int j = 1; j <= n; ++ j)
//             dist[j] = min(dist[j], g[t][j]);
//     }
    
//     return res;
// }

// int main()
// {
//     memset(g, 0x3f, sizeof g);

//     cin >> n >> m;

//     while(m --)
//     {
//         int a, b, c; cin >> a >> b >> c;
//         g[a][b] = g[b][a] = min(g[a][b], c);
//     }

//     int ret = prim();

//     if(ret == INF) cout << "impossible";
//     else cout << ret;

//     return 0;
// }


// #include <iostream>
// #include <cstring>
// #include <algorithm>

// using namespace std;

// const int N = 100010, INF = 0x3f3f3f3f;

// int p[N];
// struct Edge
// {
//     int a, b, w;
//     bool operator< (const Edge& e) const
//     {
//         return w < e.w;
//     }
// }edges[N*2];

// int n, m;

// int find(int x)
// {
//     if(p[x] != x) p[x] = find(p[x]);

//     return p[x];
// }

// int kruskal()
// {
//     for(int i = 1; i <= n; ++ i) p[i] = i;
//     sort(edges, edges + m);

//     int res = 0, cnt = 0;

//     for(int i = 0; i < m; ++ i)
//     {
//         int a = edges[i].a, b = edges[i].b, w = edges[i].w;

//         a = find(a), b = find(b);

//         if(a != b)
//         {
//             res += w;
//             p[a] = b;
//             cnt ++;
//         }
//     }

//     if(cnt < n - 1) return INF;
//     else return res;
// }

// int main()
// {
//     cin >> n >> m;
//     for(int i = 0; i < m; ++ i)
//     {
//         int a, b, c; cin >> a >> b >> c;
//         edges[i].a = a, edges[i].b = b, edges[i].w = c;
//     }

//     int ret = kruskal();

//     if(ret == INF) cout << "impossible";
//     else cout << ret;

//     return 0;
// }

// #include <iostream>
// #include <cstring>
// #include <algorithm>

// using namespace std;

// const int N = 511, M = 100011;

// int h[N], e[M], ne[M], idx;
// int match[N];
// bool st[N];

// int n1, n2, m;

// void add(int a, int b)
// {
//     e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
// }

// bool find(int x)
// {
//     for(int i = h[x]; ~i; i = ne[i])
//     {
//         int j = e[i];

//         if(!st[j])
//         {
//             st[j] = true;
//             if(match[j] == 0 || find(match[j]))
//             {
//                 match[j] = x;
//                 return true;
//             }
//         }
//     }

//     return false;
// }

// int main()
// {
//     memset(h, -1, sizeof h);

//     cin >> n1 >> n2 >> m;
//     while(m --)
//     {
//         int a, b; cin >> a >> b;
//         add(a, b);
//     }

//     int res = 0;
//     for(int i = 1; i <= n1; ++ i)
//     {
//         memset(st, 0, sizeof st);
//         if(find(i)) ++ res;
//     }

//     cout << res;

//     return 0;
// }

// #include <cstdio>
// #include <iostream>
// #include <cstring>
// #include <algorithm>

// using namespace std;

// const int N = 100010, M = N * 2;

// int h[N], e[M], ne[M], idx;
// int color[N];

// int n, m;

// void add(int a, int b)
// {
//     e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
// }

// bool dfs(int u, int c)
// {
//     color[u] = c;

//     for(int i = h[u]; ~i; i = ne[i])
//     {
//         int j = e[i];
//         if(color[j] == 0)
//         {
//             if(!dfs(j, 3 - c)) return false;
//         }
//         else if(color[j] == c) return false;
//     }

//     return true;
// }

// int main()
// {
//     memset(h, -1, sizeof h);

//     cin >> n >> m;
//     while(m --)
//     {
//         int a, b; cin >> a >> b;
//         add(a, b), add(b, a);
//     }

//     bool flag = true;

//     for(int i = 1; i <= n; ++ i)
//     {
//         if(color[i] == 0)
//         {
//             if(!dfs(i, 1))
//             {
//                 flag = false;
//                 break;
//             }
//         }
//     }

//     if(flag) cout << "Yes";
//     else cout << "No";

//     return 0;
// }


// #include <cstdio>
// #include <cstring>
// #include <iostream>

// using namespace std;

// const int N = 1000009;

// char s[N], p[N];
// int ne[N];

// int n, m;

// int main()
// {
//     cin >> n >> p + 1 >> m >> s + 1;

//     for(int i = 2, j = 0; i <= n; ++ i)
//     {
//         while(j && p[i] != p[j + 1]) j = ne[j];

//         if(p[i] == p[j + 1]) ++ j;

//         ne[i] = j;
//     }

//     for(int i = 1, j = 0; i <= m; ++ i)
//     {
//         while(j && s[i] != p[j + 1]) j = ne[j];

//         if(s[i] == p[j + 1]) ++ j;

//         if(j == n)
//         {
//             cout << i - n << ' ';
//             j = ne[j];
//         }
//     }

//     return 0;
// }

// #include <cstdio>
// #include <iostream>

// using namespace std;

// const int N = 100011;

// int p[N];
// int n, m;

// int find(int x)
// {
//     if(p[x] != x) p[x] = find(p[x]);

//     return p[x];
// }

// int main()
// {
//     cin >> n >> m;
//     for(int i = 1; i <= n; ++ i) p[i] = i;

//     while(m -- )
//     {
//         char op[2];
//         int a, b;

//         cin >> op >> a >> b;

//         if(*op == 'M')
//             p[find(a)] = find(b);
//         else
//         {
//             if(find(a) == find(b)) cout << "Yes" << endl;
//             else cout << "No" << endl;
//         }

//     }

//     return 0;
// }


// #include <cstdio>
// #include <iostream>
// #include <cstring>

// using namespace std;

// const int N = 100010;

// int p[N], cnt[N];
// int n, m;

// int find(int x)
// {
//     if(p[x] != x) p[x] = find(p[x]);

//     return p[x];
// }

// int main()
// {
//     cin >> n >> m;
//     for(int i = 1; i <= n; ++ i) p[i] = i, cnt[i] = 1;

//     while(m -- )
//     {
//         string op;
//         int a, b;
//         cin >> op;

//         if(op == "C")
//         {
//             cin >> a >> b;
//             a = find(a), b = find(b);
//             if(a == b) continue;

//             cnt[b] += cnt[a];
//             p[a] = b;
//         }
//         else if(op == "Q1")
//         {
//             cin >> a >> b;
//             if(find(a) == find(b)) cout << "Yes" << endl;
//             else cout << "No" << endl;
//         }
//         else
//         {
//             cin >> a;
//             cout << cnt[find(a)] << endl;
//         }
//     }

//     return 0;
// }