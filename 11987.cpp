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
    int num;
    int sum;
};

node* A[100001];

node* find_set(node* at){
    if(at == at->par){
        return at;
    }else{
        return at->par = find_set(at->par);
    }
}

void union_set(node* a, node* b){
    node* a_tmp = find_set(a);
    node* b_tmp = find_set(b);
    if(b_tmp == a_tmp){
        return;
    }
    b_tmp->par = a_tmp;
    a_tmp->num += b_tmp->num;
    a_tmp->sum += b_tmp->sum;
    return;
}

void move(int p, int q){
    node* P = A[p];
    node* Q = A[q];
    node* P_tmp = find_set(P);
    node* Q_tmp = find_set(Q);
    if(P_tmp == Q_tmp){
        return;
    }
    //Replacement
    A[p] = new node;
    A[p]->par = Q_tmp;
    A[p]->sum = p;
    A[p]->num = 1;
    Q_tmp->num++;
    Q_tmp->sum += p;
    //Hollow node
    P_tmp->sum -= p;
    P_tmp->num--;
    return;
}

int main(){
    for(int i=1;i<100001;++i){
        A[i] = new node;
    }
    int n, m;
    while(cin >> n >> m){
        for(int i=1;i<=n;++i){
            A[i]->sum = i;
            A[i]->num = 1;
            A[i]->par = A[i];
        }
        for(int i=0;i<m;++i){
            char c;
            int p, q;
            cin >> c;
            switch(c){
                case '1':
                    cin >> p >> q;
                    union_set(A[p], A[q]);
                    break;
                case '2':
                    cin >> p >> q;
                    move(p, q);
                    break;
                case '3':
                    cin >> p;
                    node* tmp = find_set(A[p]);
                    cout << tmp->num << ' ' << tmp->sum << endl;
                    break;
            }
        }
    }
}
