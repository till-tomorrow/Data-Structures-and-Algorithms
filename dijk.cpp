#include "dijk.h"
#include <limits.h>
#include <vector>
#include <stack>
using namespace std;
Dijk::Dijk(WtGraph& g){
	graph = g;
	SPT = WtGraph(g.getSize());
	from = vector<int> (g.getSize()+1, -1);
	dist = vector<int> (g.getSize()+1, INT_MAX);
}

void Dijk::findSPT(int source){
	vector<int> tmpV;
	vector<int> tmpWt;
	from[source]=-1;
	dist[source] = 0;
	for(int i=1;i<=graph.getSize();i++){
		tmpV.push_back(i);
		tmpWt.push_back(dist[i]);
	}

	heap.buildHeap(tmpV,tmpWt);
	
	while(!heap.empty()){
		int u = heap.retTop();
		heap.deleteMin();
		for(int v=1;v<=graph.getSize();v++){
			int weight = graph.getWt(u,v);
			//cout<<u<<" "<<v<<" "<<weight<<endl;
			if(weight!=0 && dist[u]!=INT_MAX && dist[v]>dist[u]+weight && heap.inHeap(v)){
				dist[v] = dist[u]+weight;
				heap.decreaseKey(v,dist[v]);
				from[v]=u;
			}
		}
	}
}

WtGraph Dijk::retSPT(){
	for(int i=1;i<from.size();i++){
		if(dist[i]!=INT_MAX){
			cout<<i<<" "<<dist[i]<<endl;
			SPT.addDirEdge(i,from[i],dist[i]);	
		}
		else{
			cout<<i<<" "<<"INF"<<endl;
		}
		
	}
	return SPT;
}

void Dijk::tracePath(int dest){
	int i = dest;
	int total = 0;
	if(dist[i]==INT_MAX){
		cout<<"No Path Exists\n";
		return;
	}
	stack<int> tmp;
	while(from[i]!=-1){
		tmp.push(i);
		total+=dist[i];
		i = from[i];
	}
	tmp.push(i);
	
	while(!tmp.empty()){
		cout<<tmp.top()<<' ';
		tmp.pop();
	}
	cout<<endl;
	cout<<"Total Distance: "<<total<<endl;
}