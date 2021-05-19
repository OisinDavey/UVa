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

void solve(){
    string x, z;
    cin >> x >> z;
    int n = x.size(), m = z.size();
    ll dp[n][m];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = (x[0] == z[0]);
    for(int i=1;i<n;++i){
        dp[i][0] = (x[i] == z[0]) + dp[i-1][0];
    }
    for(int i=1;i<n;++i){
        for(int j=1;j<m;++j){
            dp[i][j] = dp[i-1][j] + (x[i] == z[j])*(dp[i-1][j-1]);
        }
    }
    cout << dp[n-1][m-1] << endl;
    return;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}
