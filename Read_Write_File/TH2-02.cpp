#include<iostream>
#include<math.h>
using namespace std;
int prime(int n){
	if(n<2)
	return 0;
	for(int i=2; i<=sqrt(n);i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
int demprime(int m,int n,int a[50][50]){
	int count=0;
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
		if (prime(a[i][j]))
		count++;
	}
	return count;
}
int main(){
	FILE *f;int m,n;
	int a[50][50];
	f=fopen("array2.txt","rt");
	fscanf(f,"%d",&m);
	fscanf(f,"%d",&n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
			fscanf(f,"%d",&a[i][j]);
	}
	int b[m];
	int c[n];
	for(int i=0;i<m;i++){
				b[i]=0;
		for(int j=0;j<n;j++){
	c[j]=0;
				cout<<a[i][j]<<"  ";
				b[i]+=a[i][j];
		}
		
			cout<<endl;
	}
	
//	for(int i = 1; i<=4;i++){
//		for(int j= 1; j<=6;j++){
			
//		}
//	}
cout<<demprime(m,n,a)<<endl;
for (int i=0;i<m;i++){
	cout<<b[i]<<" ";
}
	fclose(f);
	return 0;
}
