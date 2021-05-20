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
    int n, k;
    cin >> k >> n;
    k+=8;
    int L[n];
    for(int i=0;i<n;++i){
        cin >> L[i];
    }
    sort(L, L+n, greater<int>());
    ll B[n];
    for(int i=1;i<n;++i){
        B[i] = (L[i] - L[i-1])*(L[i] - L[i-1]);
    }
    ll dp[k+1][n];
    for(int u=0;u<=k;++u){
        for(int i=0;i<n;++i){
            if(u == 0){
                dp[u][i] = 0;
            }else if(i+1 > 3*u){
                ll A = (i>1 && u>0)?dp[u-1][i-2]+B[i]:INF;
                ll B = (i>0)?dp[u][i-1]:INF;
                dp[u][i] = min(A, B);
            }else if(i+1 == 3*u){
                dp[u][i] = (i>1 && u>0)?dp[u-1][i-2]+B[i]:INF;
            }else{
                dp[u][i] = INF;
            }
        }
    }
    cout << dp[k][n-1] << endl;
    return;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}
