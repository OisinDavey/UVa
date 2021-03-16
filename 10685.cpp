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

int par[5001];
int set_size[5001];
int biggest;

int find_set(int at){
    if(at == par[at]){
        return at;
    }else{
        return par[at] = find_set(par[at]);
    }
}

void union_set(int a, int b){
    int tmp_a = find_set(a);
    int tmp_b = find_set(b);
    if(tmp_a == tmp_b){
        return;
    }
    par[tmp_a] = tmp_b;
    set_size[tmp_b] += set_size[tmp_a];
    biggest = max(biggest, set_size[tmp_b]);
    return;
}

int main(){
    int c, r;
    while(cin >> c >> r){
        if(c == 0 && r == 0){
            return 0;
        }
        biggest = 1;
        map<string, int> m;
        for(int i=0;i<c;++i){
            string s;
            cin >> s;
            m[s] = i;
            par[i] = i;
            set_size[i] = 1;
        }
        for(int i=0;i<r;++i){
            string A, B;
            cin >> A >> B;
            int a = m[A], b = m[B];
            union_set(a, b);
        }
        cout << biggest << endl;
    }
}
