#include<bits/stdc++.h>
using namespace std;
vector<int> vect[1000];
vector<bool> visited;
void dfs(int k)
{
	visited[k]=ture;
	for(auto x:vect[k]){
	    if(!visited[x])
		   dfs(x);
	}
}
int main(){
	int vertex,edge;
	cout<<"Enter number of the vertex and egde";
	cin>>vertex>>edge;
	for(int i=0;i<edge;i++){
		int x,y;//Two adjacent elements
		cin>>x>>Y;
		vect[x].push_back(y);
		vect[y].push_back(x);
	}
	visited.assign(vertex,false);
	for(int i=0;i<vertex;i++)
		 if(!visited[i])
			 dfs(i);
	
	
}
