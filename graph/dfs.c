/* 
Dfs is depth first search algorithm. 
Working: Visit every node starting from the source node. The current node remains unexplored and we keep on visiting the next node until there is no new adjacent node. 
As we rraverse, we store the element in a stack and after there's no adjacent node we simply backtrack to the previous node and see if there's an unvisited adjacne node.
*/
```
#include<stdio.h>
int a[20][20],reach[20],n;
void dfs(int v)
{
int i;
reach[v]=1;
for (i=1;i<=n;i++)
if(a[v][i] && !reach[i])
{
printf("\n %d->%d",v,i);
dfs(i);
}
}
void main()
{
int i,j,v,count=0;
printf("\n Enter number of vertices:");
scanf("%d",&n);
for (i=1;i<=n;i++)
{
reach[i]=0;
for (j=1;j<=n;j++)
a[i][j]=0;
}
printf("\n Enter the adjacency matrix:\n");
for (i=1;i<=n;i++)
for (j=1;j<=n;j++)
scanf("%d",&a[i][j]);
printf("Enter the source vertex:\n");
scanf("%d",&v);
dfs(v);
printf("\n");
for (i=1;i<=n;i++)
if(reach[i])
count++;
if(count==n)
printf("\n Graph is connected");
else
printf("\n Graph is not connected");
}
```
