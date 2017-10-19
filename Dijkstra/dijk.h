#include "heap.h"
#include "wtgraph.h"
#include <vector>
using namespace std;

#ifndef DIJK_H
#define DIJK_H

class Dijk{
	public:
		Dijk(WtGraph& g);
		void findSPT(int source);
		void tracePath(int dest);
		WtGraph retSPT();
	private:

		Heap heap;
		WtGraph graph;
		WtGraph SPT;
		vector<int> from;
		vector<int> dist;
};
#endif