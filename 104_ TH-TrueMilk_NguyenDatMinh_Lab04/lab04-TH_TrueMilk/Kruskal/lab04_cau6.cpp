#include <bits/stdc++.h>
using namespace std;
const int MAX= 20 ;

struct GRAPH {
	int n; 
	int a[MAX][MAX]; 
};
int visited[101];
int nSLT;
void visit(GRAPH g, int i, int  nSLT)
{
visited[i] = nSLT	;

for (int j=0; j < g.n; j++)
	if ((visited[j] == 0) && (g.a[i][j] != 0)){
	
			visit(g, j,nSLT);}

}
void XetLienThong(GRAPH& g){
	for(int i=0; i < g.n; i++)	{
		visited[i] = 0;
	}
	nSLT = 0;
	for ( int i=0; i<g.n; i++){

		if (visited[i] == 0){
		nSLT ++;
		visit(g, i, nSLT);	
		}
	}
}
struct CANH
{
	int u;
	int v;
	int value;
};
CANH T[MAX];
int tongsocanh = 0;
void  readGRAPH ( GRAPH &g){
	ifstream is;
	is.open("test2.TXT");
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
bool tangdan(CANH a, CANH b){
	
	if (a.u == b.u){
		return a.v < b.v;
	}
	else {
		return a.u < b.u;
	}
}
void SapXepCanh(CANH E[],int tongsocanh){
	CANH canhtam;
	for(int i = 0 ; i < tongsocanh   ; i++){
		for(int j = i + 1 ; j < tongsocanh ; j++)
			if(E[i].value > E[j].value){
				canhtam = E[i];
				E[i] = E[j];
				E[j] = canhtam;
			}
	}
}
void Kruskal(GRAPH g){
	int nT = 0;
	int Nhan[100];
	CANH DSCanh[100];
	for (int i=0;i<g.n;i++){
		for( int j = 0 ; j<g.n ; j++){
			if(g.a[i][j] > 0){
				DSCanh[tongsocanh].u = i;
				DSCanh[tongsocanh].v = j;
				DSCanh[tongsocanh].value = g.a[i][j];
				tongsocanh++;
			}
		}
	}
	SapXepCanh(DSCanh,tongsocanh);
	for(int i=0; i< g.n; i++){
		Nhan[i] = i;	
	}
	int iMin = 0;
	while(nT < g.n - 1){
		if(iMin < tongsocanh){
			if((Nhan[DSCanh[iMin].u] != Nhan[DSCanh[iMin].v])){
			T[nT] = DSCanh[iMin];
			nT++;
			int giatri = Nhan[DSCanh[iMin].v];
				for (int j = 0; j < g.n; j++){
					if (Nhan[j] == giatri)
					Nhan[j] = Nhan[DSCanh[iMin].u];
				}
			}
			iMin++;
		}
		else{
			break;
		}
	}
	if(nSLT != 1) {
		int dinh[MAX] ;
		for (int i=1;i<=MAX ; i++){
			dinh[i]=0;
		}
		cout<<"Do thi khong lien thong \n";
		for (int i=1; i<= nSLT ; i++){
			for (int j=0; j<g.n; j++)
				if (visited[j] == i){
				dinh[i]++;
				}		
		}
	int Tong[MAX];
	for (int i=1;i<=nSLT ; i++){
			Tong[i]=0;
		}
	int tmp=0;
	sort (T+0,T+nT,tangdan);
	for (int j = 1; j <= nSLT; j++  ){
		cout<<"Cay khung nho nhat cua mien lien thong thu "<<j<< " la "<<endl;
			
			for (int i = tmp; i < dinh[j]-1 + tmp; i++){
				
				printf ("(%d,%d), ", T[i].u, T[i].v);
				Tong[j] += T[i].value;
			}
			tmp = dinh[j]-1;
			printf ("\nTong gia tri cua cay khung la %d\n",Tong[j]);
		}
	}
	else {
		int TongTrongSoCuaCayKhung = 0;
		
		printf("Do thi lien thong \n");
		printf ("Cay khung nho nhat cua do thi la \n");
		sort (T+0,T+nT,tangdan);
		for (int i = 0; i < nT; i++){
			
			printf ("(%d,%d), ", T[i].u, T[i].v);
			TongTrongSoCuaCayKhung += T[i].value;
		}
		printf ("\nTong gia tri cua cay khung la %d\n",TongTrongSoCuaCayKhung);
	}
}
int main(){
	GRAPH l;
	readGRAPH(l);
	XetLienThong(l);
	Kruskal(l);
	return 0;
}


