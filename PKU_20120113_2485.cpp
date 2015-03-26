/*
Judge: PKU
PROG: 2485
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T,data,i,j,k,dis[501][501],vis[501],minid,mindis,ans;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("PKU_20120113_2485.in","r",stdin);
	freopen("PKU_20120113_2485.out","w",stdout);
	#endif
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&data);
		memset(vis,0,sizeof(vis));
		for(i=0;i<data;i++)
			for(j=0;j<data;j++)
				scanf("%d",&dis[i][j]);
		vis[0]=1;ans = 0;
		for(i=1;i<data;i++)
		{
			mindis = 2147483647;
			for(j=0;j<data;j++)if(vis[j])
				for(k=0;k<data;k++)if(!vis[k])
					if(mindis>dis[j][k])
					{
						minid=k;
						mindis=dis[j][k];
					}
			if(ans<mindis)ans=mindis;
			vis[minid]=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
