/*
Judge: PKU
PROG: 2533
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1001] = {-1},n,i,LIS,t,L,R,M,p;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("PKU_20120113_2533.in","r",stdin);
	freopen("PKU_20120113_2533.out","w",stdout);
	#endif
	while(~scanf("%d",&n))
	{
		for(i=LIS=0;i<n;i++)
		{
			scanf("%d",&t);
			L=0;R=LIS;
			while(L<=R)
			{
				M=(L+R)/2;
				if(dp[M]<t)
				{
					L=M+1;
					p=M;
				} 
				else R=p=M-1;
			}
			dp[p+1]=t;
			if(p==LIS)LIS++;
		}
		printf("%d\n",n?LIS:1);
	}
	return 0;
}
