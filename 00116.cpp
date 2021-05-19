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

void solve(int n, int m){
    int dp[n][m];
    int a[n][m];
    pair<int, int> p[n][m];
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin >> a[i][j];
        }
        dp[i][m-1] = a[i][m-1];
    }
    for(int j=m-2;~j;--j){
        for(int i=0;i<n;++i){
            int A, B, C;
            A = dp[i][j+1];
            if(i > 0){
                B = dp[i-1][j+1];
            }else{
                B = dp[n-1][j+1];
            }
            if(i < n-1){
                C = dp[i+1][j+1];
            }else{
                C = dp[0][j+1];
            }
            int res = min(A, min(B, C));
            if(res == C && i == n-1){
                p[i][j] = {0, j+1};
            }else if(res == B && i > 0){
                p[i][j] = {i-1, j+1};
            }else if(res == A){
                p[i][j] = {i, j+1};
            }else if(res == C && i < n-1){
                p[i][j] = {i+1, j+1};
            }else if(res == B && i == 0){
                p[i][j] = {n-1, j+1};
            }
            dp[i][j] = res + a[i][j];
        }
    }
    int ans = dp[0][0];
    for(int i=0;i<n;++i){
        ans = min(ans, dp[i][0]);
    }
    for(int i=0;i<n;++i){
        if(dp[i][0] == ans){
            int x = i, y = 0;
            while(y < m-1){
                cout << x+1 << ' ';
                x = p[x][y].fi;
                ++y;
            }
            cout << x+1 << endl;
            break;
        }
    }
    cout << ans << endl;
    return;
}

int main(){
    int n, m;
    while(cin >> n >> m){
        solve(n, m);
    }
}
