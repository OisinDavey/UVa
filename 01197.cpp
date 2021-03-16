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

struct node{
    node* par;
    int set_size;
};

node* find_set(node* at){
    return (at == at->par)?(at):(at->par = find_set(at->par));
}

void union_set(node* A, node* B){
    node* tmp_a = find_set(A);
    node* tmp_b = find_set(B);
    if(tmp_a == tmp_b){
        return;
    }
    tmp_a->set_size += tmp_b->set_size;
    tmp_b->par = tmp_a;
    return;
}

node* A[30001];
node* B[501];

int main(){
    for(int i=0;i<30001;++i){
        A[i] = new node;
    }
    for(int i=0;i<501;++i){
        B[i] = new node;
    }
    int n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0){
            return 0;
        }
        for(int i=0;i<n;++i){
            A[i]->par = A[i];
            A[i]->set_size = 1;
        }
        for(int i=0;i<m;++i){
            B[i]->par = B[i];
            B[i]->set_size = 0;
        }
        for(int i=0;i<m;++i){
            int k;
            cin >> k;
            for(int j=0;j<k;++j){
                int x;
                cin >> x;
                union_set(A[x], B[i]);
            }
        }
        cout << find_set(A[0])->set_size << endl;
    }
}
