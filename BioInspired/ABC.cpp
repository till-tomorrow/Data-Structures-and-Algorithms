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
	double fEval;
	double fit;
	int cont;
	double prob;
}Sol;

bool compare(Sol a, Sol b)
{
	if(a.fit<b.fit) return false; return true;
}

typedef pair<int,int> tupla;
typedef vector<vector<double> > mat;
typedef vector<Sol> Soluciones;

double genRandom(double li, double ls)
{
	return li + static_cast <double> (rand()) /( static_cast <double> (RAND_MAX/(ls-li)));
}
void printSol(string s,Sol a)
{
	cout<<s;
	cout<<a.val[0]<<"  "<<a.val[1]<<"  "<<a.fEval<<"  "<<a.fit<<" "<<a.cont<<endl;
}

void printSolProb(string s,Sol a)
{
	cout<<s;
	cout<<a.val[0]<<"  "<<a.val[1]<<"  "<<a.fEval<<"  "<<a.fit<<"  Prob: "<< a.prob<<" cont: "<<a.cont<<endl;
}

void printSolucionesProb(string s,Soluciones E)
{
	cout<<s;
	for(int i=0;i<E.size();i++)
	{
		printSolProb(to_string(i)+")   ",E[i]);
	}
}
void printSoluciones(string s,Soluciones E)
{
	cout<<s;
	for(int i=0;i<E.size();i++)
	{
		printSol(to_string(i)+")   ",E[i]);
	}
}
void calcfEvalSol(Sol &a)
{
	 a.fEval=pow(a.val[0],2)+pow(a.val[1],2);
}
void calcFit(Sol &a)
{
	if(a.fEval>=0)
		a.fit=1/(1+a.fEval);
	else
		a.fit=1+abs(a.fEval);
}
void calcfEvalSoluciones(Soluciones &E)
{
	for(auto &e:E)
		calcfEvalSol(e);
}
void calcFitSoluciones(Soluciones &E)
{
	for(auto &e:E)
		calcFit(e);	
}
void startPop(Soluciones &A, int CS)
{
	for(int i=0;i<CS;i++)
	{
		Sol n_a;
		n_a.val[0]= genRandom(-5,5);
		n_a.val[1]= genRandom(-5,5);
		n_a.fEval=0;
		n_a.fit=0;
		n_a.cont=0;
		A.push_back(n_a);
	} 
}
void genCandidatas(Soluciones & A,Soluciones & cand,int CS, int D, int SN)
{
	for(int i=0;i<CS;i++)
	{
		double fi=genRandom(-1,1);
		int j = round((genRandom(0,D-1)));
		int k = round(genRandom(0,SN-1));
		while(k==i)
			 k = round(genRandom(0,SN-1));
		if(k!=i)
		{
			Sol n;
			n.val[(j+1)%2]=A[i].val[(j+1)%2];
			n.val[j]=A[i].val[j]+ fi * (A[i].val[j]-A[k].val[j]);
			n.fEval=0;
			n.fit=0;
			n.cont=0;
			cand.push_back(n);
		}
	}
}

void genNuevaObs(Soluciones & A, int pos,int D, int SN)
{
	// vi,j = xi,j + ɸ · (xi,j − xk,j),
	cout<<" \n ---->  pos elegida ------> "<<pos<<endl;
	double fi=genRandom(-1,1);
	int j = round(genRandom(0,D-1));
	int k = round(genRandom(0,SN-1));
	while(k==pos)
		k = round(genRandom(0,SN-1));
	if(k!=pos)
	{
		Sol n;
		n.val[(j+1)%2]=A[pos].val[(j+1)%2];
		n.val[j]=A[pos].val[j]+ fi * (A[pos].val[j]-A[k].val[j]);
		n.fEval=0;
		n.fit=0;
		n.cont=0;
		calcfEvalSol(n);calcFit(n);
		
		if(A[pos].fit> n.fit)
		{
			n.cont++; 
			A[pos].cont++;	
		}
		else
		{
			n.cont=0; A[pos].cont=0;	
			A[pos]=n;
		}
		printSol("\nimprimiendo primera opcion \n\n",n);
		printSoluciones("\nNuevos Mejores \n\n", A);
	}
}

void compSoluciones(Soluciones & A, Soluciones & cand)
{
	for(int i=0;i<A.size();i++)
	{
		if(A[i].fit>=cand[i].fit)
		{
			cand[i].cont++;
		}
	}
}
Soluciones bestSols(Soluciones &A , Soluciones &cand)
{
	Soluciones B;
	for(int i=0;i<A.size();i++)
	{
		if(cand[i].fit < A[i].fit)
		{
			//cand[i].cont++;
			A[i].cont++;
			//cand[i].cont;
			B.push_back(A[i]);
		}
		else
			B.push_back(cand[i]);	
		//if(cand[i].cont==0)
		//	B.push_back(cand[i]);
	}
	return B;
}

int probSeleccion(Soluciones & B)
{
	double ruleta=0; 
	for(int i=0;i<B.size();i++)
	{
		ruleta += B[i].fit;
	}
	for(int i=0;i<B.size();i++)
	{
		B[i].prob=B[i].fit/ruleta;
	}
	double acu=0;
	double r=genRandom(0,1);
	for(int i=0;i<B.size();i++)
	{
		acu+=B[i].prob;
		if(r<acu)
			return i;
	}
	return B.size()-1;
}
Sol CalcBest(Soluciones & A)
{
	sort(A.begin(), A.end(),compare);
	return A[0];
}

void excedLimt(Soluciones & A, int L )
{
	for(auto &y: A)
	{
		if(y.cont > L)
		{
			for(int j=0;j<2;j++)
			{
				y.val[j]= min(y.val[0],y.val[1])+ genRandom(0,1)*(max(y.val[0],y.val[1])-min(y.val[0],y.val[1]));
			}
			y.fEval=0;
			y.fit=0;
			y.cont=0;
			calcfEvalSol(y);calcFit(y);
		}

	}
}
int main()
{
	srand (time(NULL));
	int CS=6; //tamaño de colmena
	int D=2 ; //Numero de variables
	int L=6; //num de iteracciones antes de abandonar la fuente
	int MCN=5; //Maximo numero de ciclos que itera el algorimo
	int SN=3; //numero de soluciones
	Soluciones A;
	Soluciones cand, best;
	startPop(A,CS);
	//cout<<"size"<<A.size()<<endl;
	//printSoluciones("\n Soluciones inicial \n\n", A);
	calcfEvalSoluciones(A);
	calcFitSoluciones(A);
	printSoluciones("\n Calculando Iniciales fEval y fitness \n\n", A);
	int ite=0;
	Sol nn;
	while(ite<100)
	{
		cout<<"############# Iteracion"<<ite<<"################"<<endl;
		cand.clear();
		//best.clear();
		//cand=best;
		printSoluciones("\n Calculando Iniciales fEval y fitness \n\n", A);
		genCandidatas(A,cand,CS,D,SN);
		//printSoluciones("\n Soluciones Candidatas \n\n", cand);
		calcfEvalSoluciones(cand);
		calcFitSoluciones(cand);
		compSoluciones(A,cand);
		printSoluciones("\n Calculando Candidatas fEval y fitness \n\n", cand);
		A=bestSols(A,cand);
		printSoluciones("\n Mejores Soluciones \n\n", A);	
		int obs=0;
		while(obs<SN)
		{
			cout<<"\n * * * * * * * * *  Observadora "<<obs<<"* * * * * * * * *"<<endl;
			probSeleccion(A);
			printSolucionesProb("\n Mejores Soluciones con Probabilidad \n\n", A);
			double solEle= probSeleccion(A);
			genNuevaObs(A,solEle,D,SN);
			obs++;
		}
		
		excedLimt(A,L);
		printSolucionesProb("\n Ciclo Terminado , Comprobando si se acabo recursos \n \n ", A);
		sort(A.begin(),A.end(),compare);
		if(nn.fit< A[0].fit)
			nn= A[0];
		printSol("\nEl mejor acumulado\n", nn);
		ite++;		
	}
	return 0;
}