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

string cards[53];
bool s[53];

void solve(int n){
    memset(s, 0, sizeof(s));
    int pos = 0;
    for(int i=0;i<n;++i){
        string put, siz;
        cin >> put >> siz;
        int todo = siz.size();
        while(todo > 0){
            if(!s[pos]){
                --todo;
                if(todo == 0){
                    cards[pos] = put;
                    s[pos] = true;
                }
            }
            ++pos;
            if(pos == n)
                pos = 0;
        }
    }
    return;
}

int main(){
    int n;
    while(1){
        cin >> n;
        if(n == 0)
            break;
        solve(n);
        cout << cards[0];
        for(int i=1;i<n;++i)
            cout << ' ' << cards[i];
        cout << endl;
    }
    return 0;
}
