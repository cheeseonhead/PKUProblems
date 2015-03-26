/*
Judge: PKU
PROG: 3051
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int r,c,i,j,size,mxsize;
char id[2000][2000],fa;
bool vis[2000][2000];

void print_all()
{
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			//if(vis[i][j])putchar('@');
			// putchar(id[i][j]);
		puts("");
	}
	return;
}

void dfs(int x,int y)
{
	if(x<0||x>=r||y<0||y>=c||vis[x][y]||id[x][y]!=fa)return;
	size++;vis[x][y]=true;
	print_all();
	puts("");
				dfs(x-1,y);
	dfs(x,y-1);				dfs(x,y+1);
				dfs(x+1,y);
	return;
}

void prepare(int x,int y)
{
	size=0;
	fa=id[x][y];
	dfs(x,y);
	if(size>mxsize)
		mxsize=size;
	return;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("PKU_20120123_3051.in","r",stdin);
	freopen("PKU_20120123_3051.out","w",stdout);
	#endif
	while(~scanf("%d%d",&c,&r))
	{
		getchar();
		memset(vis,0,sizeof(vis));mxsize=0;
		for(i=0;i<r;i++)
			for(j=0;j<=c;j++)
				scanf("%c",&id[i][j]);
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)if(!vis[i][j])
					prepare(i,j);
		printf("%d\n",mxsize);
	}
	return 0;
}
