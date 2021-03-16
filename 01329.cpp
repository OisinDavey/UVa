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

ll len[20001];
int par[20001];

int find_set(int at){
    if(at == par[at]){
        return at;
    }else{
        int x = find_set(par[at]);
        len[at] += len[par[at]];
        return par[at] = x;
    }
}

void union_set(int I, int J){
    find_set(J);
    par[I] = J;
    len[I] = abs(I - J)%1000;
    find_set(I);
    return;
}

int main(){
    FastIO;
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i=0;i<=n;++i){
            par[i] = i;
            len[i] = 0;
        }
        char c;
        while(cin >> c){
            if(c == 'O'){
                break;
            }else if(c == 'E'){
                int I;
                cin >> I;
                find_set(I);
                cout << len[I] << endl;
            }else{
                int I, J;
                cin >> I >> J;
                union_set(I, J);
            }
        }
    }
}
