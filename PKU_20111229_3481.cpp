/*
Judge: PKU
PROG: 3481
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define test
using namespace std;

typedef map <int,int> Waitline;
map<int,int>::iterator it;
Waitline line;
int n,pri,k;

int main()
{
	#ifdef test
	freopen("PKU_20111229_3481.in","r",stdin);
	freopen("PKU_20111229_3481.out","w",stdout);
	#endif
	while(~scanf("%d",&n) && n)
	{
		switch(n)
		{
			case 1:
				scanf("%d%d",&k,&pri);
				line[pri] = k;
				break;
			case 2:
				
				if(line.empty())puts("0");
				else
				{
					it = line.end();
					--it;
					printf("%d\n",it->second);
					line.erase(it);
				}
				break;
			case 3:
				if(line.empty())puts("0");
				else
				{
					printf("%d\n",line.begin()->second);
					line.erase(line.begin());
				}
				break;
		}
	}
	return 0;
}
