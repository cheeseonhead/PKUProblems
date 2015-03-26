/*
Judge: PKU
PROG: 2377
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,i,fa[1001],ans,j;
int get(int N){ return (N==fa[N])?N:(fa[N]=get(fa[N])); }
void uni(int N,int M){ fa[get(N)]=get(M); }

struct DIS
{
	int s,e,c;	
}dis[20001];

bool cmp(DIS a,DIS b)
{
	if(a.c==b.c)
		return a.s>b.s;
	return a.c>b.c;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("PKU_20120114_2377.in","r",stdin);
	freopen("PKU_20120114_2377.out","w",stdout);
	#endif
	while(~scanf("%d%d",&n,&m))
	{
		ans=j=0;
		for(i=0;i<n;i++)fa[i]=i;
		for(i=0;i<m;i++)scanf("%d%d%d",&dis[i].s,&dis[i].e,&dis[i].c);
		sort(dis,dis+m,cmp);
		for(i=0;i<m;i++)
		{
			if(get(dis[i].s)!=get(dis[i].e))
			{
				uni(dis[i].s,dis[i].e);
				ans+=dis[i].c;
				j++;
//				printf("%d\n",dis[i].c);
			}
		}
		
		printf("%d\n",(j==n-1)?ans:-1);
	}
	return 0;
}
