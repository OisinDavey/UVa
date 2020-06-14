//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            300001 
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

struct node{
    int L;
    int R;
    node* l;
    node* r;
    ll val;
};

//Global Variables
node* root;
int N, Q;
ll u;
ll A[MX_N];

node* build(int L, int R){
    node* at = new node;
    at->L = L;
    at->R = R;
    if(L == R){
        at->val=A[L];
        at->l == NULL;
        at->r == NULL;
    }else{
        int M = L + (R-L)/2;
        at->l = build(L, M);
        at->r = build(M+1, R);
        at->val = min(at->l->val, at->r->val);
    }
    return at;
}

ll segfind(node* at, int L, int R, ll v){
    if(at->val >= v){
        return 0LL;
    }
    if(at->L > R || at->R < L){
        return 0LL;
    }
    if(at->L == at->R){
        //cout << "SegFound: " << at->L << ' ' << at->R << ' ' << at->val << endl;
        return 1LL;
    }
    return segfind(at->l, L, R, v) + segfind(at->r, L, R, v);
}

int main(){
    FastIO;
    //cout << "Inputting\n";
    cin >> N >> Q >> u;
    for(int i=0;i<N;++i){
        cin >> A[i];
    }
    root = build(0, N-1);
    int L, R;
    ll v;
    int p;
    for(int i=0;i<Q;++i){
        cin >> L >> R >> v >> p;
        --L;
        --R;
        --p;
        A[p] = u * segfind(root, L, R, v) / (R - L + 1);
    }
    //cout << "Outputting\n";
    for(int i=0;i<N;++i){
        cout << A[i] << endl;
    }
}
