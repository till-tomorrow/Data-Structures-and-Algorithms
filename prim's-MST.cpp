#include <stdio.h>
#include <queue>
#define max 99999
using namespace std;

int t[1000][1000];
int dist[1000];

void createEdge(int a,int b)
{
    t[a][b] = 1;
    t[b][a] = 1;
}
void initTree(int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(t[i][j] == 0) t[i][j] = max;
}

void solution(int n,int start,int end)
{
    initTree(n);
    for(int i=0;i<n;i++)
    {
        dist[i] = max;
    }
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i=0;i<n;i++)
        {
            if(dist[i] > dist[now] + 1)
            {
                q.push(i);
                dist[i] = dist[now]+1;
            }
        }
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        createEdge(a,b);
    }
    int st,end;
    scanf("%d %d",&st,&end);
    solution(n,st,end);
    for(int i=0;i<n;i++)
        printf("%d ",dist[i]);
    puts("");
    return 0;
}