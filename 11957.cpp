//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            5001
#define mp              make_pair
#define mod7            1000007
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

int n;
bool board[101][101];

bool valid(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= n){
        return false;
    }
    return !board[x][y];
}

int main(){
    int T;
    cin >> T;
    for(int t=1;t<=T;++t){
        cin >> n;
        ll ways[n][n];
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                ways[i][j] = 0ll;
                char c;
                cin >> c;
                board[i][j] = (c == 'B');
                if(c == 'W'){
                    ways[i][j] = 1ll;
                }
            }
        }
        for(int x=n-1;x>=0;--x){
            for(int y=0;y<n;++y){
                ways[x][y] %= mod7;
                int _x, _y;
                if(valid(x-1, y+1)){
                    _x = x-1;_y = y+1;
                    ways[_x][_y] += ways[x][y];
                }else if(valid(x-2, y+2)){
                    _x = x-2;_y = y+2;
                    ways[_x][_y] += ways[x][y];
                }
                if(valid(x-1, y-1)){
                    _x = x-1;_y = y-1;
                    ways[_x][_y] += ways[x][y];
                }else if(valid(x-2, y-2)){
                    _x = x-2;_y = y-2;
                    ways[_x][_y] += ways[x][y];
                }
            }
        }
        ll cnt = 0ll;
        for(int i=0;i<n;++i){
            cnt += ways[0][i];
            cnt %= mod7;
        }
        cout << "Case " << t << ": " << cnt << endl;
    }
}
