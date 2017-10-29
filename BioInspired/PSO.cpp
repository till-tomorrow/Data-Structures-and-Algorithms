#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <list>
#include <iterator>
#include <fstream>
#include <cstdio>
#include <sstream>

using namespace std;


static int Dim=2;
typedef struct 
{
	double val[2];
	double speed[2];
	double former[2];
	double fit;
}Ave;

typedef vector<Ave> bandada;

double genRandom(double li, double ls)
{
	return li + static_cast <double> (rand()) /( static_cast <double> (RAND_MAX/(ls-li)));
}
void printAve(string a, Ave v)
{
	cout<<a<<"<"<<v.val[0]<<","<<v.val[1]<<">  -  <"<<v.speed[0]<<","<<v.speed[1]<<">  "<<v.fit<<"\n";
}
void printBandada(string a, bandada & A)
{
	cout<<a;
	for (int i = 0; i < A.size(); ++i)
	{
		printAve("",A[i]);
	}
}
void evaluateAve(Ave &a)
{
	a.fit=a.val[0]*a.val[0]+a.val[1]*a.val[1];
}
void evaluateBandada(bandada &B)
{
	for (int i = 0; i < B.size(); i++)
	{
		evaluateAve(B[i]);
	}
}

void StartPopulation(bandada &B, int PT, double li, double ls)
{
	B.resize(PT);
	for(int i=0; i<PT;i++)
	{
		B[i].val[0]= genRandom(li,ls);B[i].val[1]=genRandom(li,ls);
		B[i].speed[0] = genRandom(li,ls);B[i].speed[1]=genRandom(li,ls);
		evaluateAve(B[i]);
		printAve("",B[i]);
	}
}
bool compare(Ave a, Ave B)
{
	if(a.fit< B.fit) return true; return false;
}

Ave findAlfa(bandada & B)
{
	sort(B.begin(), B.end(),compare);
	printAve("\n El mejor : \n\n", B[0]);
	return B[0];
}
void findBestVersion(Ave & B)
{
	double ant= B.former[0]*B.former[0]+B.former[1]*B.former[1];
	double nue= B.val[0]*B.val[1]+B.val[0]*B.val[1];
	if(ant>nue)
	{
		B.former[0]=B.val[0];
		B.former[1]=B.val[1];
	}
}

void Run(bandada &B,int f1, int f2)
{
	double W=genRandom(0,1);
	double rand1= genRandom(0,1);
	double rand2= genRandom(0,1);
	Ave G=findAlfa(B);
	for (int i = 0; i < B.size(); ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			B[i].speed[j]=W*B[i].speed[j]+f1*rand1*(B[i].former[j]-B[i].val[j])+ f2*rand2*(G.val[j]-B[i].val[j]);	
			B[i].val[j]+=B[i].speed[j];
			evaluateAve(B[i]);
		}

		findBestVersion(B[i]);
	}
}
int main()
{
	srand (time(NULL));
	double li,ls;
	li=-5;
	ls=5;
	int PT=6;
	bandada B;
	int ite=100;
	int f1,f2; 
	f1=2;f2=2;
	int v=0;
	cout<<"Imprimiendo Poblacion Inicial"<<endl;
	StartPopulation(B,PT,li,ls);
	while(v<ite)
	{
		cout<<"\n**********"<<v <<"**********"<<endl;
		Run(B,f1,f2);
		printBandada("\nCúmulo de las particulas siguientes\n\n",B);
		v++;
	}
	return 0;
}