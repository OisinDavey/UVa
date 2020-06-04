//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            1000002
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

//Global Variables
ll L, R;
int N, M, K;
int freq[MX_N];
int a[MX_N];
int uni;

void solve(int Case){
    cin >> N >> M >> K;
    memset(freq, 0, sizeof(freq));
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    for(int i=3;i<1000001;++i)
        a[i] = (a[i-3] + a[i-2] + a[i-1])%M + 1;
    uni = 1;
    L = 0;
    R = 0;
    freq[1] = 1;
    ll best = INF;
    while(L <= R){
        if(uni < K){
            ++R;
            if(R == N)
                break;
            if(a[R] > K)
                continue;
            if(freq[a[R]]==0)
                ++uni;
            ++freq[a[R]];
        }else{
            best = min(best, R-L+1LL);
            if(a[L] <= K){
                if(freq[a[L]]==1)
                    --uni;
                --freq[a[L]];
            }
            ++L;
            if(L == N)
                break;
        }
    }
    if(best == INF){
        cout << "Case " << Case << ": sequence nai\n";
    }else{
        cout << "Case " << Case << ": " << best << endl;
    }
}

int main(){
    FastIO;
    int T;
    cin >> T;
    for(int i=0;i<T;++i){
        solve(i+1);
    }
}
