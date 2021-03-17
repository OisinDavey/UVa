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

int n, m;
int x, y;

char board[10][10];

int step[10][10];

int cnt;

int main(){
    while(cin >> n >> m >> y){
        x = 0;
        if(n == m && m == y && y == 0){
            return 0;
        }
        --y;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin >> board[i][j];
            }
        }
        memset(step, -1, sizeof(step));
        cnt = 0;
        bool left = false;
        while(true){
            ++cnt;
            if(y < 0 || x < 0 || x >= n || y >= m){
                left = true;
                break;
            }
            if(step[x][y] != -1){
                break;
            }
            step[x][y] = cnt;
            switch(board[x][y]){
                case 'N':
                    --x;
                    break;
                case 'S':
                    ++x;
                    break;
                case 'W':
                    --y;
                    break;
                case 'E':
                    ++y;
                    break;
            }
        }
        if(left){
            cout << cnt-1 << " step(s) to exit\n";
        }else{
            cout << step[x][y]-1 << " step(s) before a loop of " << cnt-step[x][y] << " step(s)\n";
        }
    }
}
