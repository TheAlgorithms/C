#include<stdio.h>
int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1,k=0,count;
void graph2();
void graph1();//using adjacency matrix
void DFS(int);
int G[20][20];
int node1,node2;
void graph1()
 {count=0;
	int v;
printf("\nEnter the last node:");
	scanf("%d",&n);
	printf("\nEnter the nodes:");
	while(count!=n)
   {scanf("%d",&node1);
    count=node1;}
	for (i=1;i<=n;i++)
    visited[i]=0;    //visited set as 0
    printf("\nEnter adjacency matrix of graph:\n");
	for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    scanf("%d",&a[i][j]);
	printf("\nEnter the starting vertex:");
	scanf("%d",&v);
    printf("\nBFS Traversal is : ");
     q[++r]=v;
    while(!(f==-1 || f>r))
   {
      v = q[f++];
      if(visited[v]==1)  //if vertex is visted,dont print it.Continue with next element
	    continue;

      printf("%d  ",v);
      visited[v] = 1;

      for(int i=1; i<=n; i++)
      if(a[v][i]==1 && !visited[i])
        q[++r]=i;
   }
}
void main()
{int ch;
    do
    {
        printf("\nEnter choice 1.bfs or 2.dfs?");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:graph1();
            break;
            case 2:graph2();
            break;
        }

    }while(ch!=3);
}
void graph2()
{count=0;
    int i,j,k;
    printf("Enter the last node:");
	scanf("%d",&n);
	printf("\nEnter the nodes:");
	while(count!=n)
   {scanf("%d",&node2);
    count=node2;}
	for (i=1;i<=n;i++)
	visited[i]=0;       //visited set as 0
	printf("\nEnter adjecency matrix of the graph:");
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
			scanf("%d",&G[i][j]);
printf("\nEnter starting vertex");
scanf("%d",&k);
printf("DFS traversal is: ");
    DFS(k);
}
void DFS(int i)
{
    int j;
	printf("%d ",i);
    visited[i]=1;

	for(j=1;j<=n;j++)
       if(!visited[j] && G[i][j]==1)
            DFS(j);
}
