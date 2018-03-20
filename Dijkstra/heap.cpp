#include "heap.h"
#include <iostream>
using namespace std;

Heap::Heap(){
	heap.push_back(-1);
	vertices.push_back(-1);
	position = vector<int> (1000,-1);
	size = 0;
}

void display(vector<int>& a){
	for(int i=0;i<a.size();i++){
		cout<<i<<" : "<<a[i]<<endl;
	}
	cout<<endl;
}

int Heap::retTop(){
	return vertices[1];
	
}

void Heap::percolateUp(int i){
	while(i>1){
		if(heap[i]<heap[i/2]){
			int tmp = heap[i];
			int tmp2 = vertices[i];
			position[tmp2] = i/2;
			position[vertices[i/2]] = i;
			heap[i] = heap[i/2];
			vertices[i] = vertices[i/2];
			heap[i/2] = tmp;
			vertices[i/2] = tmp2;
			i/=2;

		}
		else{
			break;
		}
	}
}

void Heap::percolateDown(int i){
	while(2*i<heap.size()){
		int minChild = 2*i;
		if(2*i+1 < heap.size() && heap[2*i]>heap[2*i+1]){
			minChild = 2*i+1;
		}
		if(heap[i]>heap[minChild]){
			int tmp = heap[i];
			int tmp2 = vertices[i];

			position[tmp2] = minChild;
			position[vertices[minChild]] = i;

			heap[i] = heap[minChild];
			vertices[i] = vertices[minChild];
			heap[minChild] = tmp;
			vertices[minChild] = tmp2;
		}
		i=minChild;
	}
}
bool Heap::insert(int wt,int node){
	heap.push_back(wt);
	vertices.push_back(node);
	size++;
	int i = heap.size()-1;
	position[node]=i;
	percolateUp(i);
}

void Heap::decreaseKey(int node, int ne){
	int i = position[node];
	heap[i] = ne;
	percolateUp(i);
}

bool Heap::deleteMin(){
	int last = heap.size()-1;
	
	int tmp = heap[1];
	heap[1] = heap[last];
	heap[last] = tmp;
	
	position[vertices[last]]=1;
	int tmp2 = vertices[1];
	vertices[1] = vertices[last];
	vertices[last] = tmp2;


	heap.pop_back();
	vertices.pop_back();

	percolateDown(1);
	position[tmp2] = -1;
	size--;
}



void Heap::buildHeap(vector<int>& vt, vector<int>& wt){
	heap.clear();
	vertices.clear();
	heap.push_back(-1);
	vertices.push_back(-1);
	for(int i=0;i<vt.size();i++){
		heap.push_back(wt[i]);
		vertices.push_back(vt[i]);
		position[vt[i]] = i+1;
	}
	size = vt.size();
	

	for(int i = heap.size()/2; i>0;i--){
		percolateDown(i);
	}
}