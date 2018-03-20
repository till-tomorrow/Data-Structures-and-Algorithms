#include <iostream>
#include <vector>
#include <queue>
#include "wtgraph.h"
using namespace std;

WtGraph::WtGraph(){
	size=0;
}

WtGraph::WtGraph(int n){
	size = n;
	visited= vector<bool> (n+1,0);
	adjMat = vector<vector<int> >(n+1, vector<int> (n+1,0));
}

WtGraph::WtGraph(const WtGraph& from){
	size = from.size;
	visited= vector<bool> (from.size+1,0);
	adjMat = from.adjMat;
}

void WtGraph::operator= (const WtGraph& from){
	size = from.size;
	visited= vector<bool> (from.size+1,0);
	adjMat = from.adjMat;
}

void WtGraph::addEdge(int u, int v, int wt){
	adjMat[u][v]= wt;
	adjMat[v][u]= wt;
}
void WtGraph::addDirEdge(int u, int v, int wt){
	adjMat[u][v]= wt;
}
void WtGraph::bfs(int source){
	queue<int> que;
	que.push(source);
	visited[source] = true;
	visit(source);
	while(!que.empty()){
		int u = que.front();
		que.pop();
		for(int v=1;v<=size;v++){
			if(adjMat[u][v]!=0 && !visited[v]){
				visit(v);
				visited[v] = true;
				que.push(v);
			}
		}
	}

}

void  WtGraph::bfs(){
	for(int i=1;i<=size;i++){
		if(!visited[i]){
			bfs(i);
		}
	}
	clear();
}

void WtGraph::clear(){
	visited = vector<bool> (size+1,0);
}

void  WtGraph::visit(int src){
	cout<<src<<endl;
}