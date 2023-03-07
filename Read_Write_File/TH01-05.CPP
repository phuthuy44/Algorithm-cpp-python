#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
int main(){
	FILE *f;
	int n;
	f = fopen("taci.txt","wt");
	cout<<"Nhap n : "; cin>>n;
	fprintf(f,"%d",n);
	fprintf(f,"\n");
	int num = 1;
	for(int i = 0;i<=n;i++){
		for(int j = 0; j <=n;j++){
			fprintf(f,"%3d",num);
			num ++ ;
			if (num > n*n){
				num = 0;
			}
		}
		fprintf(f,"\n");
	}
	fclose(f);
	return 0;
}
