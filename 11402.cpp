//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            1024001
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

bool pirates[4*MX_N];//1 for bucc, 0 for barb
int value[4*MX_N];
char instruct[4*MX_N];

void build(int at, int L, int R){
    instruct[at] = 'o';
    if(L == R){
        value[at] = pirates[L];
    }else{
        int M = L + ((R - L) >> 1);
        build((at << 1), L, M);
        build((at << 1)+1, M+1, R);
        value[at] = value[(at << 1)] + value[(at << 1) + 1];
    }
    return;
}

void flip_sub_tree(int at){
    switch(instruct[at]){
        case 'o':
            instruct[at] = 'i';
            break;
        case 'i':
            instruct[at] = 'o';
            break;
        case 'u':
            instruct[at] = 'a';
            break;
        case 'a':
            instruct[at] = 'u';
            break;
    }
    return;
}

void prop(int at, int L, int R){
    switch(instruct[at]){
        case 'i':
            value[at] = R - L + 1 - value[at];
            break;
        case 'a':
            value[at] = 0;
            break;
        case 'u':
            value[at] = R - L + 1;
            break;
    }
    if(L != R){
        if(instruct[at] == 'i'){
            flip_sub_tree((at << 1));
            flip_sub_tree((at << 1) + 1);
        }else{
            instruct[(at << 1)] = instruct[at];
            instruct[(at << 1) + 1] = instruct[at];
        }
    }
    instruct[at] = 'o';
    return;
}

int query(int at, int L, int R, int at_L, int at_R){
    if(instruct[at] != 'o'){
        prop(at, at_L, at_R);
    }
    if(at_R < L || R < at_L){
        return 0;
    }else if(L <= at_L && at_R <= R){
        return value[at];
    }else{
        int at_M = at_L + ((at_R - at_L) >> 1);
        return query((at << 1), L, R, at_L, at_M) + query((at << 1)+1, L, R, at_M+1, at_R);
    }
}

void update(int at, int L, int R, int at_L, int at_R, char task){
    if(instruct[at] != 'o'){
        prop(at, at_L, at_R);
    }
    if(at_R < L || R < at_L){
        return;
    }else if(L <= at_L && at_R <= R){
        switch(task){
            case 'i':
                value[at] = at_R - at_L + 1 - value[at];
                break;
            case 'a':
                value[at] = 0;
                break;
            case 'u':
                value[at] = at_R - at_L + 1;
                break;
        }
        if(at_L != at_R){
            if(task == 'i'){
                flip_sub_tree((at << 1));
                flip_sub_tree((at << 1) + 1);
            }else{
                instruct[(at << 1)] = task; 
                instruct[(at << 1) + 1] = task;
            }
        }
        return;
    }
    int at_M = at_L + ((at_R - at_L) >> 1);
    update((at << 1), L, R, at_L, at_M, task);
    update((at << 1)+1, L, R, at_M+1, at_R, task);
    value[at] = value[(at << 1)] + value[(at << 1)+1];
    return;
}

int main(){
    int T;
    cin >> T;
    for(int t=1;t<=T;++t){
        //Inputting
        int M;
        cin >> M;
        int ind = 1;
        for(int i=0;i<M;++i){
            int t;
            cin >> t;
            string s;
            cin >> s;
            int tmp_n = s.size();
            bool tmp_b[tmp_n];
            for(int j=0;j<tmp_n;++j){
                tmp_b[j] = (s[j] == '1');
            }
            for(int j=0;j<t;++j){
                for(int k=0;k<tmp_n;++k){
                    pirates[ind] = tmp_b[k];
                    ++ind;
                }
            }
        }
        cout << "Case " << t << ":\n";

        build(1, 1, ind-1);
        int Q;
        cin >> Q;
        int count = 0;
        for(int i=0;i<Q;++i){
            char c;
            int a, b;
            cin >> c >> a >> b;
            ++a, ++b;
            switch(c){
                case 'F':
                    update(1, a, b, 1, ind-1, 'u');
                    break;
                case 'E':
                    update(1, a, b, 1, ind-1, 'a');
                    break;
                case 'I':
                    update(1, a, b, 1, ind-1, 'i');
                    break;
                case 'S':
                    cout << "Q" << ++count << ": " << query(1, a, b, 1, ind-1) << endl;
                    break;
            }
        }
    }
}
