#include <bits/stdc++.h>
using namespace std;
const int MAX= 20 ;

struct GRAPH {
int n; 
int a[MAX][MAX]; 
int visited[MAX];
};

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
bool tangdan(CANH a, CANH b){
	return a.u < b.u;
	if (a.u == b.u){
		return a.v < b.v;
	}
}
void SapXepCanh(CANH E[],int tongsocanh){
	CANH canhtam;
	for(int i = 0 ; i < tongsocanh   ; i++){
		for(int j = i + 1 ; j < tongsocanh ; j++)
			if(E[i].value > E[j].value){ // Cau 4: doi thanh E[i].value > E[j].value -> E[i].value < E[j].value 	de tim cay khung lon nhat
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
			if(g.a[i][j] > 0){//  Cau 5: sua dieu kien > 0 thanh != 0 de nhan trong so am. 
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
	if(nT != g.n -1) 
		printf("Do thi khong lien thong \n");
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

void Outfile(GRAPH& g){
	ofstream os;
	os.open("out.txt");
	if (os.is_open()){	
		int nT = 0;
	int tongsocanh = 0;
	
	int Nhan[100];
	CANH DSCanh[100];
	for (int i=0;i<g.n;i++){
		for( int j = i+1 ; j< g.n ; j++){
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
	if(nT != g.n -1) 
	os<<"Do thi khong lien thong \n";
	else {
		int TongTrongSoCuaCayKhung = 0;
		os<<"Do thi lien thong \n";
		os<<"Cay khung nho nhat cua do thi la \n";
		for (int i = 0; i < nT; i++){
			os<<"("<<T[i].u<<","<<T[i].v<<")";
			TongTrongSoCuaCayKhung += T[i].value;
		}
		os<<"\nTong gia tri cua cay khung la %d\n"<<TongTrongSoCuaCayKhung;
	}
}
	
	os.close();	
}

int main(){
	GRAPH l;
	
	readGRAPH(l);
	Kruskal(l);
	Outfile(l);
	return 0;
}

