#include<bits/stdc++.h>
#define rep(j,n) for(int i=j;i<n;i++)
#define pb push_back
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long int ll;
int main(){
	int t;
	cin >> t;
	for(int gg=0;gg<t;gg++){
		int n,b,k;
		cin >> n >> b >> k;
		map<int,int> m;
		int a[n];
		a[0]=1,a[1]=2,a[2]=3;
		rep(3,n)
			a[i]=(a[i-1]+a[i-2]+a[i-3])%b +1;
		int d=0;
		int f=0xfffffff;
		for(int i= 0,j= -1;;){
			if(d<k){
				if(j==n-1){
					if(d==k)
						f=min(f,(j-i));
					break;
				}
				j++;
				if((m[a[j]]==0)&&((1<=a[j])&&(a[j]<=k)))
					d++;
				m[a[j]]++;
			}else{
				if((m[a[i]]==1)&&((1<=a[i])&&(a[i]<=k)))
					d--;
				m[a[i]]--;
				i++;
			}
			if(d==k)
				f=min(f,(j-i));
		}
		(f==0xfffffff)?printf("Case %d: sequence nai\n",gg+1):printf("Case %d: %d\n",gg+1,f+1);
	}
}