/*
Judge: PKU
PROG: 3173
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int mat[21][21],N,S;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("PKU_20120319_3173.in","r",stdin);
	freopen("PKU_20120319_3173.out","w",stdout);
	#endif
	
	while(~scanf("%d%d",&N,&S))
	{
		memset(mat,0,sizeof(mat));
		mat[0][0] = S;
		for(int i=1;i<N;i++)
		{
			mat[i][0] = mat[i-1][i-1]%9 + 1;
			for(int j=1;j<=i;j++)
			{
				mat[i][j] = mat[i][j-1]%9 + 1;
			}
		}
		for(int j=0;j<N;j++)
		{
			if(mat[0][j])
				printf("%d",mat[0][j]);
			else printf(" ");
			for(int i=1;i<N;i++)
			{
				if(mat[i][j])
					printf(" %d",mat[i][j]);
				else printf("  ");
			}
			puts("");
		}
			
	}
	
	return 0;
}
