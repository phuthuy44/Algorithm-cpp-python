//TH1-02.CPP

#include<iostream>
#include<stdio.h>
using namespace std;
#include<math.h>
#define maxm 300
#define maxn 500
FILE *f ;
void readfile(int a[maxm][maxn],int &m, int &n);
void cau1(int a[maxm][maxn],int m, int n);
void cau2(int a[maxm][maxn],int m, int n);
void cau3(int a[maxm][maxn],int m, int n);
int main(){
	FILE *f; int m,n;
	int a[maxm][maxn];
	readfile(a,m,n);

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
			printf("%4d",a[i][j]) ;
		printf("\n"); 
	}
	//FILE *f= fopen("array2.out",wt)
	cau1(a,m,n);
	cau2(a,m,n);
	cau3(a,m,n); 
	fclose(f);
	return 0;
}
void readfile(int a[maxm][maxn],int &m, int &n){
	FILE *f;
	f =fopen("array2.txt","r");
	fscanf(f,"%d%d",&m,&n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
			fscanf(f,"%d",&a[i][j]);
		printf("\n"); 
	}	
	fclose(f);
}

int prime_number(int n){
	if(n<2) return 0 ;
	int k = sqrt(n);
	for(int i =2 ;i<= k;i++){
		if (n%i == 0) return 0;
	}
	return 1;
}
void cau1(int a[maxm][maxn],int m, int n){
	int count = 0;
	f =fopen("array2.out","wt");
	fprintf(f,"Cau 1 : ");
	for (int i =0; i<m;i++){
		for(int j=0;j<n;j++){
			if(prime_number(a[i][j])){
				count++;
			}
		}
	}
	fprintf(f,"%d",count);
	fprintf(f,"\n");
	//fclose(f); 
	
}
void cau2(int a[maxm][maxn],int m, int n){
	
	//f =fopen("array2.out","wt");
	fprintf(f,"Cau 2 : ");
	for (int i =0; i<m;i++){
		int s=0;
		for(int j=0;j<n;j++){
			s += a[i][j];
		}
		fprintf(f,"%3d",s);
	}
	fprintf(f,"\n");
	
	//fclose(f); 
} 
void cau3(int a[maxm][maxn], int m, int n){
	//f =fopen("array2.out","wt");
	fprintf(f,"Cau 3 : ");
	for (int i =0; i<n;i++){
		int s = 0;
		for(int j=0;j<m;j++){
			s += a[j][i];
		}
		fprintf(f,"%3d",s);
	}
	fprintf(f,"\n");
	fclose(f); 
}
