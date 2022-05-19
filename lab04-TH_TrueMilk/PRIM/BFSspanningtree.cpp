#include<bits/stdc++.h>

using namespace std;

#define MAX 100
#define inputfile ""

struct GRAPH{
	int sodinh;
	int a[MAX][MAX];
};
int Queue[MAX];
int Last, First;
int ChuaXet[MAX];
int visited[MAX];
int nSoMienLienThong;
void readGRAPH(string file ,GRAPH& g){
	ifstream f;
	f.open("test1.txt");
	if(f.is_open()){
		f>>g.sodinh;
		for(int i=0; i<g.sodinh; i++){
			for(int j=0; j<g.sodinh; j++){
				f>>g.a[i][j];
			}
		}
		f.close();
	}
	else cout << "khong mo duoc file";
}
void printGRAPH (GRAPH g){
	cout << "So dinh cua do thi: " << g.sodinh << "\n";
	for(int i=0; i<g.sodinh;i++){
		for(int j=0; j<g.sodinh;j++){
			cout << setw(4) << g.a[i][j];
			
		}
		cout << "\n";
	}
}

void visit(GRAPH g, int i, int nLabel){
	visited[i]=nLabel;
	for(int j=0; j<g.sodinh; j++){
		if(visited[j]==0 && (g.a[i][j] !=0)){
			visit(g, j, nLabel);
		}
	}
}
int XetLienThong(GRAPH& g){
	for(int i=0; i<g.sodinh;i++){
		visited[i]=0;
	}
	nSoMienLienThong = 0;
	for(int i=0; i<g.sodinh; i++){
		if(visited[i]==0){
			nSoMienLienThong++;
			visit(g,i,nSoMienLienThong);
		}
	}
	if(nSoMienLienThong <= 1){
		return 1;
	}
	else{
		return 0;
	}
}
void Push(int v){
	Last++;
	Queue[Last]=v;
}
int Pop(){
	int x = Queue[First];
	First++;
	return x;
}
void Prim(GRAPH g){
	if(XetLienThong(g) != 1){
		cout << "do thi khong lien thong do do ko thuc hien duoc bai toan prim tim cay nho nhat\n";
		return;
	}
	int nT=0;
	for(int i=0; i<g.sodinh; i++){
		ChuaXet[i]=0;
	}
	ChuaXet[0]=1;
		int GTNN = 1000;
		int u;
		Queue[0]=0;
		Last = 0;
		First = 0;
		do{
		u=Pop();
			for(int i=0; i<g.sodinh; i++){
				if(ChuaXet[i]==0 && g.a[u][i]!=0){
					Push(i);
					ChuaXet[i]=1;
					cout << "(" << u<< "," << i << ")" ;
				}
			}
		}while(First <= Last && nT<g.sodinh-1);
		
}
int main(){
	GRAPH g;
	string file;
	readGRAPH(file, g);
	printGRAPH(g);
	Prim(g);
}
