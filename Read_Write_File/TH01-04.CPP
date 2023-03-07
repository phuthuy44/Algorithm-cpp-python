#include<iostream>
#include<math.h>
#define maxm 800
#define maxn 600
FILE *f;
void ReadFile(int a[maxm][maxn], int &n);
void CountPrime(int a[maxm][maxn], int &n);
using namespace std;
int main(){
	FILE *f; 
	int a[maxm][maxn],n;
	ReadFile(a,n);
	printf("%d",n);
	printf("\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=10;j++)
			printf("%6d",a[i][j]) ;
		printf("\n"); 
	}
	CountPrime(a,n);
	fclose(f);
	return 0;	
}
int CheckPrime(int n){
	if (n<2) return 0;
	int k = sqrt(n);
	for(int i = 2 ; i <= k ;i++){
		if (n % i == 0){
			return 0;
		}
	}
	return 1;	
}
void ReadFile(int a[maxm][maxn], int &n){
	f = fopen("array1.txt","rt");
	fscanf(f,"%d",&n);
	for (int i = 1; i<=n ;i++){
		for(int j=1 ;j<=10;j++){
			fscanf(f,"%6d",&a[i][j]);
		}
		fprintf(f,"\n");
	}
	fclose(f);
}
void CountPrime(int a[maxm][maxn], int &n){
	int count = 0;
	FILE *f = fopen("array1.out","wt");
	fprintf(f,"Count Prime : ");
	for (int i = 1 ; i<=n;i++){
		for(int j=1 ;j<=10;j++){
			if(CheckPrime(a[i][j])){
				count++;
			}
		}
	}
	fprintf(f,"%d",count);
	fclose(f);
}

