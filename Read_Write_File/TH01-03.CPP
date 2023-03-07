#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
#define maxm 300;
#define maxn 500;
int main(){
	FILE *f; int n;
	srand(time(NULL));
	f = fopen("array1.txt","wt");
	cout<<"Nhap n : "; cin>>n;
	fprintf(f,"%d",n);
	fprintf(f,"\n");
	for (int i = 1 ; i <=n;i++){
		for(int j = 1; j <=10;j++){
			fprintf(f,"%6d",rand());
		}
		fprintf(f,"\n");
	}
	fclose(f);
	return 0;
}

