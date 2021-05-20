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
    ll c[27][27];
    ll s[27][27];
    memset(c, 0, sizeof(c));
    memset(s, 0, sizeof(s));
    c[0][0] = 1ll;
    s[0][0] = 1ll;
    for(int i=0;i<27;++i){
        for(int j=0;j<=i;++j){
            if(i > 0){
                c[i][j] += c[i-1][j];
            }
            if(j > 0){
                c[i][j] += c[i][j-1];
            }
        }
    }
    for(int i=0;i<27;++i){
        for(int j=0;j<=i;++j){
            if(i != j && j > 0 && i > 0){
                s[i][j] += s[i-1][j-1];
            }
            if(i > 0){
                s[i][j] += s[i-1][j];
            }
            if(j > 0){
                s[i][j] += s[i][j-1];
            }
        }
    }
    int n;
    while(cin >> n){
        cout << s[n-1][n-1] - c[n-1][n-1] << endl;
    }
}
