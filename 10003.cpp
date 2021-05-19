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

void solve(int l){
    int n;
    cin >> n;
    n += 2;
    int a[n];
    a[0] = 0;
    a[n-1] = l;
    for(int i=1;i<n-1;++i){
        cin >> a[i];
    }
    int cost[n][n];
    for(int k=0;k<n;++k){
        for(int i=0;i<n-k;++i){
            int j = i + k;
            if(i == j){
                cost[i][j] = 0;
            }else if(i+1 == j){
                cost[i][j] = 0;
            }else{
                int tmp = 10000001;
                for(int x = i+1;x<j;++x){
                    tmp = min(tmp, cost[i][x] + cost[x][j]);
                }
                cost[i][j] = a[j] - a[i] + tmp;
            }
        }
    }
    cout << "The minimum cutting is " << cost[0][n-1] << ".\n";
    return;
}

int main(){
    int l;
    while(cin >> l){
        if(l == 0){
            return 0;
        }
        solve(l);
    }
}
