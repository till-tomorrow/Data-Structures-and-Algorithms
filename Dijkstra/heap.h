#include <iostream>
#include <vector>
using namespace std;

#ifndef HEAP_H
#define HEAP_H


class Heap{
	public:
		Heap();
		bool insert(int wt, int node);
		int retTop();
		inline bool empty(){
			return size==0;
		}
		inline bool inHeap(int node){
			return position[node]!=-1;
		}
		bool deleteMin();
		void decreaseKey(int key, int ne);
		void buildHeap(vector<int>& vt, vector<int>& wt);
	private:
		void percolateUp(int i);
		void percolateDown(int i);
		vector<int> heap;
		vector<int> vertices;
		vector<int> position;
		int size;
};
#endif
