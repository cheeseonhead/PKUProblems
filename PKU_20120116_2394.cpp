/*
Judge: PKU
PROG: 2394
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 21474836
using namespace std;

int v[101],u[101],M,F,P,C,c[101],on[101],dist[101],ans[101],x,cnt;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("PKU_20120116_2394.in","r",stdin);
	freopen("PKU_20120116_2394.out","w",stdout);
	#endif
	while(~scanf("%d%d%d%d",&F,&P,&C,&M))
	{
		for(int i=1;i<=P;i++)scanf("%d%d%d",v+i,u+i,c+i);

		for(int i=1;i<=F;i++)
			dist[i] = INF;
		dist[1]=0;

		//bellman ford
		for(int j=0;j<F;j++){
			for(int i=1;i<=P;i++)
			{
				if(dist[v[i]]>dist[u[i]]+c[i])
					dist[v[i]]=dist[u[i]]+c[i];
				if(dist[u[i]]>dist[v[i]]+c[i])
					dist[u[i]]=dist[v[i]]+c[i];
			}
		}
		//for (int i=1;i<=F;i++)printf("%d %d\n",i,dist[i]);
		for(int i=cnt=0;i<C;i++)
		{
			scanf("%d",&x);
			if(dist[x]<=M)ans[cnt++]=i+1;
		}
		printf("%d\n",cnt);
		for(int i=0;i<cnt;i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}
