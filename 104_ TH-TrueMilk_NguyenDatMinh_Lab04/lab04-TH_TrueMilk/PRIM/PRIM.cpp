#include<bits/stdc++.h>

using namespace std;

#define MAX 100
#define inputfile ""

struct GRAPH{
	int sodinh;
	int a[MAX][MAX];
};
struct EDGE{
	int u;
	int v;
	int value;
};
EDGE T[MAX];
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
void Prim(GRAPH g){
	if(XetLienThong(g) != 1){
		cout << "do thi khong lien thong do do ko thuc hien duoc bai toan prim tim cay nho nhat\n";
		return;
	}
	// Buoc 1:
	int nT=0;
	for(int i=0; i<g.sodinh; i++){
		ChuaXet[i]=0;
	}
	ChuaXet[0]=1;
	while(nT<g.sodinh-1){ // Cau 3: tai sao lai co dieu kien nay? . Boi vi, nT la so canh it nhat co the noi duoc cac dinh => nT = so dinh - 1 
		EDGE edgeMin;
		int GTNN = 1000;//Cau 4: thay doi GTNN = -1000
		//Buoc 2:
		for(int i=0; i<g.sodinh; i++){
			if(ChuaXet[i]==1){
				for(int j=0;j<g.sodinh; j++){
					if(ChuaXet[j]==0 && g.a[i][j]!=0 && GTNN > g.a[i][j]){// Cau 4: thay doi GTNN > g.a[i][j] --> GTNN < g.a[i][j] de tim cay khung lon nhat
						//Buoc 3:
						edgeMin.u=i;
						edgeMin.v=j;
						edgeMin.value=g.a[i][j];
						GTNN = g.a[i][j];
					}
				}
			}
		}
		T[nT]=edgeMin;
		nT++;
		ChuaXet[edgeMin.v] = 1; // Cau 3: De danh dau dinh cac duong di ma ta duyet qua va duoc chon
	}
	int sum = 0;
	cout<<"Cay khung nho nhat cua do thi la: "<<endl;
	for(int i = 0; i < nT; i++)
	{
		cout<<"("<<T[i].u+1<<", "<<T[i].v+1<<") ";
		sum += T[i].value;
	}
	cout<<endl;
	cout<<"Tong gia tri cua cay la: "<<sum<<endl;
}
int main(){
	GRAPH g;
	string file;
	readGRAPH(file, g);
	printGRAPH(g);
	Prim(g);
}
// Cau 6
// do thi co trong so am thi thuat toan van dung
// demo bang testAm.txt
