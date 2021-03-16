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

int n, q;
int A[1000001];

struct node{
    int L;
    int R;
    node* l;
    node* r;
    int val;
};

node* build(int L, int R){
    node* at = new node;
    at->L = L;
    at->R = R;
    if(L == R){
        at->val = A[L];
        at->l = nullptr;
        at->r = nullptr;
    }else{
        int M = L + ((R-L) >> 1);
        at->l = build(L, M);
        at->r = build(M+1, R);
        at->val = min(at->l->val, at->r->val);
    }
    return at;
}

int query(node* at, int L, int R){
    if(at->R < L || R < at->L){
        return 1000002;
    }else if(at->L >= L && R >= at->R){
        return at->val;
    }else{
        return min(query(at->l, L, R), query(at->r, L, R));
    }
}

void update_point(node* at, int pos, int val){
    if(at->R < pos || pos < at->L){
        return;
    }else if(at->L == pos && at->R == pos){
        at->val = val;
    }else{
        update_point(at->l, pos, val);
        update_point(at->r, pos, val);
        at->val = min(at->l->val, at->r->val);
    }
    return;
}

int main(){
    cin >> n >> q;
    for(int i=0;i<n;++i){
        cin >> A[i];
    }
    node* root = build(0, n-1);
    while(q--){
        char c;
        cin >> c;
        if(c == 'q'){
            for(int i=0;i<5;++i){
                cin >> c;
            }
            int L, R;
            cin >> L >> c >> R >> c;
            --L, --R;
            cout << query(root, L, R) << endl;
        }else{
            for(int i=0;i<5;++i){
                cin >> c;
            }
            vector<int> v;
            while(true){
                int x;
                cin >> x >> c;
                --x;
                v.pb(x);
                if(c == ')'){
                    break;
                }
            }
            int m = v.size();
            int S[m];
            for(int i=0;i<m;++i){
                if(i==m-1){
                    S[i] = A[v[0]];
                }else{
                    S[i] = A[v[i+1]];
                }
            }
            for(int i=0;i<m;++i){
                update_point(root, v[i], S[i]);
                A[v[i]] = S[i];
            }
        }
    }
}
