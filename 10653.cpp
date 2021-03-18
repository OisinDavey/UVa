//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            5001
#define mp              make_pair
#define mod7            1000000007
#define modpi           314159
#define PI              3.141592653589793238
#define pb              push_back
#define FastIO          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define All(a)          a.begin(),a.end()
#define fi              first
#define se              second
#define ll              long long int
#define ull             unsigned long long int

int kx[8]  =            {+2, +2, -2, -2, +1, +1, -1, -1};
int ky[8]  =            {+1, -1, +1, -1, +2, -2, +2, -2};
int d9x[9] =            {+1, +1, +1, +0, +0, +0, -1, -1, -1};
int d9y[9] =            {+1, +0, -1, +1, +0, -1, +1, +0, -1};
int dx4[4] =            {+0, +0, +1, -1};
int dy4[4] =            {+1, -1, +0, +0};

ll gcd(ull a, ull b){
    return (a==0)?b:gcd(b%a,a);
}

ll lcm(ull a, ull b){
    return a*(b/gcd(a,b));
}

const long long INF = 1e18;

using namespace std;

int main(){
    FastIO;
    int R, C;
    while(cin >> R >> C && (R or C)){
        bool board[R][C], vis[R][C];
        memset(board, 0, sizeof(board));
        memset(vis, 0, sizeof(vis));
        int r_count;
        cin >> r_count;
        while(r_count--){
            int r, in_row;
            cin >> r >> in_row;
            while(in_row--){
                int c;
                cin >> c;
                board[r][c] = true;
            }
        }
        int sr, sc, dr, dc;
        cin >> sr >> sc >> dr >> dc;
        queue<tuple<int, int, int> > q;
        q.push({sr, sc, 0});
        vis[sr][sc] = true;
        while(!q.empty()){
            auto [x, y, cnt] = q.front();
            q.pop();
            if(x == dr && y == dc){
                cout << cnt << endl;
                break;
            }
            for(int i=0;i<4;++i){
                int x_ = x + dx4[i];
                int y_ = y + dy4[i];
                if(x_ < 0 || y_ < 0 || x_ >= R || y_ >= C){
                    continue;
                }
                if(vis[x_][y_] || board[x_][y_]){
                    continue;
                }
                vis[x_][y_] = true;
                q.push({x_, y_, cnt+1});
            }
        }
    }
}
