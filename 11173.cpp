#include<bits/stdc++.h>
#define rep(j,n) for(int i=j;i<n;i++)
#define pb push_back
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long int ll;
int main(){
	int n,k;
	scanf("%d",&n);
	while(n--){
		scanf("%d %d",&k,&k);
		printf("%d\n",k^(k>>1));
	}
	return 0;
}