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
#define matrix          vector<vector<int> > 
#define matrix_ll          vector<vector<long long int> > 

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

matrix_ll mat_make(int H, int W){
    matrix_ll res;
    for(int i=0;i<H;++i){
        vector<ll> tmp;
        for(int j=0;j<W;++j){
            tmp.pb(0LL);
        }
        res.pb(tmp);
    }
    return res;
}

void modulo(ll& val, ll M){
    if(val < 0){
        val = (M + (val%M))%M;
    }else if(val >= M){
        val -= M;
        if(val >= M){
            val %= M;
        }
    }
    return;
}

matrix_ll mat_mult(matrix_ll& A, matrix_ll& B, ll M){
    int H = A.size();
    int W = B[0].size();
    matrix_ll res = mat_make(H, W);
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            for(int k=0;k<A[0].size();++k){
                ll a = A[i][k];
                modulo(a, M);
                ll b = B[k][j];
                modulo(b, M);
                res[i][j] += a*b;
                modulo(res[i][j], M);
            }
        }
    }
    return res;
}

matrix_ll mat_identity(int N){
    matrix_ll res = mat_make(N, N);
    for(int i=0;i<N;++i){
        res[i][i] = 1ll;
    }
    return res;
}

matrix_ll mat_binpow(matrix_ll base, ll expo, ll M){
    if(expo == 0){
        return mat_identity(base.size());
    }else if(expo == 1){
        return base;
    }else{
        matrix_ll tmp = mat_binpow(base, expo/2ll, M);
        tmp = mat_mult(tmp, tmp, M);
        if(expo % 2LL == 1LL){
            tmp = mat_mult(base, tmp, M);
        }
        return tmp;
    }
}

int main(){
    ll N, L;
    while(cin >> N >> L){
        matrix_ll adj = mat_make(N, N);
        ll S, T;
        cin >> S >> T;
        --T, --S;
        for(int i=0;i<N;++i){
            for(int j=0;j<4;++j){
                ll dest;
                cin >> dest;
                ++adj[i][dest-1];
            }
        }
        adj = mat_binpow(adj, L, 10000LL);
        cout << adj[S][T] << endl;
    }
}
