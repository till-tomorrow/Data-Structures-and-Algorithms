/*
simple implementation of merge sort
Author:sspsk
Email:kdstsdk@gmail.com
*/

#include<iostream>
using namespace std;



/*
inputs:
a = given array
start = position of the first element
med = position of middle element
last = position of last element

function=joins the two subarrays
*/

void merge(int a[],int start,int med,int last){

  int b[last-start+1];
  int i=start;
  int j=med+1;
  int k=0;

  while(i<=med && j<=last){
    if(a[i]<a[j]){b[k]=a[i];i++;}
    else{b[k] = a[j];j++;}
    k++;
  }
  if(i>med){
    while(j<=last){b[k]=a[j];j++;k++;}
  }
  else{
    while(i<=med){b[k]=a[i];i++;k++;}
  }
  for(i=0;i<k;i++){
    a[start+i]=b[i];
  }


}

/*
inputs:
a = given array
start = position of first element
last = position of last element

function:
creates two subarrays and makes recursice call of mergesort

*/
void mergesort(int a[],int start,int last){
  int med = (last+start)/2;


  if(start==last)return;
  mergesort(a,start,med);
  mergesort(a,med+1,last);
  merge(a,start,med,last);
};

/*
exmaple on a array

*/
int main(){
  int a[]={0,9,2,7,4,5,3,6,8,1};
  for(int i=0;i<10;i++){
    cout<< a[i];
  }
  cout <<endl;
  mergesort(a,0,9);

  for(int i=0;i<10;i++){
    cout<< a[i];
  }


}
