/*
Judge: PKU
PROG: 1007
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define test
using namespace std;

int n,m;
char dna[101][101];
int sor[101],order[101];

bool compare(int U,int V){ if(sor[U]==sor[V])return U<V; return sor[U]<sor[V];} 

int main()
{
	#ifdef test
	freopen("PKU_20120103_1007.in","r",stdin);
	freopen("PKU_20120103_1007.out","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int chk['T'+1] = {};sor[i] = 0;order[i] = i;
		getchar();
		for(int j=0;j<n;j++)
		{
			scanf("%c",&dna[i][j]);
			chk[dna[i][j]]++;
			switch(dna[i][j])
			{
				case 'A': sor[i]+= chk['C']+chk['G']+chk['T'];break;
				case 'C': sor[i]+= chk['G']+chk['T'];break;
				case 'G': sor[i]+= chk['T'];break;
			}
		}
	//	printf("sor %d\n",sor[i]);
	}
	sort(order,order+m,compare);
	for(int i=0;i<m;i++)
	{
	//	printf("%d ",order[i]+1);
		puts(dna[order[i]]);
	}
	return 0;
}
