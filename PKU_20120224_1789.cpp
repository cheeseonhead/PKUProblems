/*
Judge: PKU
PROG: 1789
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 2147483647
using namespace std;

int N,ans,minid,least[2001]={0},mind;
char s[2001][8];

int dis(int x, int y)
{
	int dif=0;
	for(int i=0;i<6;i++)
		if(s[x][i]!=s[y][i])dif++;
	return dif;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("PKU_20120224_1789.in","r",stdin);
	freopen("PKU_20120224_1789.out","w",stdout);
	#endif
	
	while(~scanf("%d\n",&N))
	{
		if(!N)return 0;
		ans=0;
		
		for(int i=0;i<N;i++)
			gets(s[i]);
		
		for(int i=1;i<N;i++)
			least[i]=dis(0,i);
		
		for(int n=0;n<N-1;n++)
		{
			mind = MAXN;
			for(int i=0;i<N;i++)
				if(least[i]<mind && least[i]>0)
				{
					mind = least[i];
					minid = i;
				}
			ans+=mind;
			least[minid] = -1;
			
			for(int i=0;i<N;i++) if(least[i]>0)
				if(dis(i,minid)<least[i])
					least[i]=dis(i,minid);
		}
		
		printf("The highest possible quality is 1/%d.\n",ans);
	}
	return 0;
}
