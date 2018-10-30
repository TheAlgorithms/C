#include<stdio.h>
#include<stdlib.h>

int a[20][20],q[20],visited[20],reach[10],n,i,j,f=0,r=-1,count=0;

void bfs(int v){
for(i=1;i<=n;i++)
if(a[v][i]&&!visited[i])
 q[++r]=i;

if(f<=r)
 {
 visited[q[f]]=1;
 bfs(q[f++]);
 }
}
void dfs(int v)
{
int i;

reach[v]=1;
for(i=1;i<=n;i++)
 { if(a[v][i]&&!reach[i])
   {
    printf("\n%d->%d",v,i);
     count++;
      dfs(i);
  }
 }
}

void main()
{
int v,choice;
 
 printf("\nENter No. Of VerticeS:");
  scanf("%d",&n);

 for(i=1;i<=n;i++)
  {
   q[i]=0;
   visited[i]=0;
  }

for(i=0;i<=n;i++)
 reach[i]=0;

printf("\nENter THe Graph data in Matrix FOrm:");

 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   scanf("%d",&a[i][j]);
for(;;){
printf("\n1.BFS\n2.DFS\n3.Exit\n");
 printf("ENter Ur CHoice");scanf("%d",&choice);

 switch(choice)
{
case 1: printf("\nENter THe Starting Vertex/Node:");
	scanf("%d",&v);
         for(i=1;i<=n;i++){
			 q[i]=0;
			 visited[i]=0;
			 
		 }	 
		 
		 
		 bfs(v);
        
         if((v<1)||(v>n))
          printf("\nDFS not possible!!\n");
	 else{
	  printf("\nThe NOdes which are reachable from %d:\n",v);
           for(i=1;i<=n;i++)
             if(visited[i])
               printf("%d\t",i);
             }
 	break;
case 2:dfs(1);
	if(count==n-1)
          printf("Graph Is COnnected\n");
        else
          printf("Graph Is NOt COnnected\n");
 	 break;
case 3:exit(0);
}}
}

