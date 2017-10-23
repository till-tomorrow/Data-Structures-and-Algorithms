// Find the median of the integers at any time while input 
// e.g. n=4
// arr[0] = 1 --> median = 1
// arr[1] = 15 --> median = (15+1)/2 = 8
// arr[2] = 23 --> median = 15
// arr[3] = 3 --> median = (15+3)/2 = 9



#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <list>
#include <queue>
#include <functional>
#include <unordered_map>
#include <limits.h>
using namespace std;

#define ll long long int
#define pb push_back
#define mp make_pair




int main(){
	priority_queue<int> maxpq;
	priority_queue<int, vector<int>, greater<int> > minpq;
	int n;
	cin>>n;
	int i=0;
    int arr[n];
	while(i<n){
	    cin>>arr[i];
		if(i==0){
			cout<<arr[0]<<endl;
			i++;
			continue;
		}
		if(i==1){
			maxpq.push(min(arr[0], arr[1]));
			minpq.push(max(arr[0], arr[1]));
			cout<<(maxpq.top() + minpq.top())/2<<endl;
			i++;
			continue;
		}




		if(arr[i] < maxpq.top()){

			maxpq.push(arr[i]);
		}
		else{

			minpq.push(arr[i]);
		}
		int maxpq_size = maxpq.size();
		int minpq_size = minpq.size();

		// for balancing the heaps
		if(abs(maxpq_size - minpq_size) > 1){
			if(maxpq_size - minpq_size > 1){

				minpq.push(maxpq.top());
				
				maxpq.pop();
				
			}
			if(minpq_size - maxpq_size > 1){
				
				maxpq.push(minpq.top());
				
				minpq.pop();
				
			}

		}		
		

		// now output
		if(maxpq.size() == minpq.size()){
			
			int ans  = (maxpq.top() + minpq.top())/2;
			cout<<ans<< endl;
			i++;
			continue;
		}
		else{
			if(maxpq.size() > minpq.size()){
				
				
				cout<<maxpq.top()<<endl; 
			}
			else{
				
				
				cout<<minpq.top()<< endl;
			}
		}

		i++;
	}

	return 0;

}