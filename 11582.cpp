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

void modulo(ull& val, int m){
    if(val < 0){
        val = (m + (val%m)) % m;
    }else if(val >= m){
        val %= m;
    }
    return;
}

ull mod_binpow(ull base, ull expo, int m){
    modulo(base, m);
    if(expo == 0LL){
        return 1LL;
    }else if(expo == 1LL){
        return base;
    }else{
        ull tmp = mod_binpow(base, expo/2LL, m);
        tmp *= tmp;
        modulo(tmp, m);
        if(expo % 2LL == 1LL){
            tmp *= base;
            modulo(tmp, m);
        }
        return tmp;
    }
}

int main(){
    ull fib[1000000];
    int T;
    cin >> T;
    while(T--){
        fib[0] = 0LL;
        fib[1] = 1LL;
        ull a, b;
        int n;
        cin >> a >> b >> n;
        modulo(fib[0], n);
        modulo(fib[1], n);
        int l;//The length of the cycle
        for(int i=2;i<1000000;++i){
            fib[i] = fib[i-1] + fib[i-2];
            modulo(fib[i], n);
            if(fib[i-1] == fib[0] && fib[i] == fib[1]){
                ll ind = mod_binpow(a, b, i-1);
                cout << fib[ind] << endl;
                break;
            }
        }
    }
}
