#include <bits/stdc++.h>
#include <fstream>
using namespace std;

const int MAX = 10 ;

struct GRAPH {
	int n;
	int a[MAX][MAX];
	int LuuVet[MAX];
	int ChuaXet[MAX];
	
	
};


	int Stack[MAX];
	int Last=0;
	int First=0;

void  readGRAPH (string fn, GRAPH &g){
	ifstream is;
	is.open("test1.txt");
	if (is.is_open()){	
		is>>g.n;
		for(int i=0;i<g.n;i++){
		for(int j=0 ;j<g.n;j++ ){
			is>>g.a[i][j];
		}
	}
	is.close();
	
		
	}
	else cout<<"Khong mo duoc file!";	
}
void xuatGRAPH(GRAPH g){
	cout<<"So dinh do thi: "<<g.n<<endl;
	for(int i=0;i<g.n;i++){
		for(int j=0 ;j<g.n;j++ ){
			
			cout<<setw(4)<<g.a[i][j];
		}
		cout<<endl;
	}
	
}
int visited[101];
int nSLT;
void visit(GRAPH g, int i, int  nSLT)
{

	visited[i] = nSLT	;

	for (int j=0; j < g.n; j++)
		if ((visited[j] == 0) && (g.a[i][j] != 0)){
	
			visit(g, j,nSLT);}

}

int XetLienThong(GRAPH& g){

	for(int i=0; i < g.n; i++)	{
	visited[i] = 0;}

 	nSLT = 0;

	for ( int i=0; i<g.n; i++){

		if (visited[i] == 0){
		nSLT ++;
		visit(g, i, nSLT);
		}
	}
	if(nSLT <= 1){
		return 1;
	}
	else{
		return 0;
	}
}



void Push(int V){
	Last++;
	Stack[Last]=V;
	
}

int Pop(){
	int x = Stack[Last];
	Last--;
	return x;
}

void DFS(int s,GRAPH& g){
	int u;
	g.ChuaXet[s]=1;
	Push(s);
	do {
		u = Pop();
		int gtnn = 100;
		for (int v=0;v<g.n;v++){
			
			if (g.ChuaXet[v]==0 && g.a[u][v]>0 ){
				g.ChuaXet[v]= 1;
				g.LuuVet[v]=u;
				Push(u); 	
				Push(v);
				cout<<"("<<u<<","<<v<<") ";
				break;
				
			}
		}
	}
	while (Last !=0);
	
	
	
}



void duyetDFS(int s, int f, GRAPH &g){	
	if (XetLienThong(g) != 1){
		cout<<"Do thi khong lien thong\n";
		return;
	}
	
	
	for(int i = 0; i < g.n; i++){
		g.ChuaXet[i] = 0;
		g.LuuVet[i] = -1;
	}
	
	DFS(s,g);
		
	
	
}


int main (){
	GRAPH l;
	int c[MAX];
	string fn;
	readGRAPH(fn,l);
	xuatGRAPH(l);
	int s=0;
	int f=l.n-1;
	
	duyetDFS(s,f,l);
	DFS(s,l); 
	return 0;
}
