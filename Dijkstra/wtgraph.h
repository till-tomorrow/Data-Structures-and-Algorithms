#include <vector>
using namespace std;
#ifndef WTGRAPH_H
#define WTGRAPH_H

class WtGraph{
	public:
		WtGraph();
		WtGraph(int n);
		WtGraph(const WtGraph &from);
		void operator = (const WtGraph & from);
		void addEdge(int u, int v, int wt);
		void addDirEdge(int u, int v, int wt);
		inline int getSize(){
			return size;
		}
		inline int getWt(int u, int v){
			return adjMat[u][v];
		}
		void bfs(int source);
		void bfs();
		void visit(int src);
		void clear();
	private:
		vector<vector<int> > adjMat;
		vector<bool> visited;
		int size;

};
#endif