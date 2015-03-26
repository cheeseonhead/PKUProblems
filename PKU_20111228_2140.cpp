/*
Judge: PKU
PROG: 2140
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
//#define test
using namespace std;

int n,pnt,temp,ans;

int main()
{
	#ifdef test
	freopen("PKU_20111228_2140.in","r",stdin);
	freopen("PKU_20111228_2140.out","w",stdout);
	#endif
	scanf("%d",&n);pnt = 1;temp = 0;ans = 0;
	for(int data = 1;data<=n;data++)
	{
		temp += data;
		while(temp>n){temp-=pnt;pnt++;}
		if(temp==n)ans++;
	}
	printf("%d\n",ans);
	return 0;
}
