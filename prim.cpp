#include <stdio.h>
struct DOTHI{
	int soDinh;
	int a[100][100];
};
struct CANH{
	int v1, v2, ts;
};
void docFile(DOTHI &g){
	char tenFile[18];
	printf("Nhap ten File: "); scanf("%s",&tenFile);
	FILE *f=fopen(tenFile,"rt");
	if(f==NULL){
		printf("\n Khong mo duoc File! ");
		return;
	}
	//da mo file roi
	fscanf(f,"%d",&g.soDinh);
	for(int i=0;i<g.soDinh;i++)
		for(int j=0;j<g.soDinh;j++)
			fscanf(f,"%d",&g.a[i][j]);
	fclose(f); //dong File
}
void Prim (DOTHI g){
	int VT[100] ={0}, nET=0; //khai bao va khoi tao tap hop VT chua cac dinh thuoc Cay khung
	CANH ET[100]; //khai bao tap hop ET chua cac CANH thuoc cay khung, nET:la so canh cua cay khung
	VT[0]=1;
	int min;
	CANH canhMin;
	while(nET < g.soDinh-1){
		min=1000;
		for(int i=0; i<g.soDinh;i++)
			if(VT[i]==1)
				for(int j=0; j<g.soDinh; j++)
					if(VT[j]==0 && g.a[i][j] !=0 && g.a[i][j] <min)
						{
							canhMin.v1=i;
							canhMin.v2=j;
							canhMin.ts=g.a[i][j];
							min= g.a[i][j];
						}
				ET[nET++]=canhMin;
				VT[canhMin.v2]=1;
	}
	//xuat cay khung nho nhat
	printf("\nPRIM - CAY KHUNG NHO NHAT GOM CAC CANH:");
	int tongTS=0;
	for(int i=0;i<nET;i++){
		tongTS +=ET[i].ts;
		printf("\n\t(%d,%d)= %d",ET[i].v1, ET[i].v2, ET[i].ts);
	}
	printf("\n CAY KHUNG CO TONG TRONG SO = %d", tongTS);
}
int main(){
	DOTHI g;
	docFile(g);
	Prim(g);
}
