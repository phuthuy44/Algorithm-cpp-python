//Assignment problem 
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 300 // maximum number of workers/jobs
int assigned[MAX_SIZE];
int matrix[MAX_SIZE][MAX_SIZE];
int worker[MAX_SIZE];
int job[MAX_SIZE];
void AP(int n){
	int i ,j;
	//Initialze worker and job arrays
	for(i = 0;i < n;i++){
		worker[i] = -1 ;
		job[i] = -1;
	}
	for( i = 0;i<n;i++){
		//int max_cost = -1;
		//int best_job =0;
		for( j = 0;j<n;j++){
			if(job[j]== -1 && (worker[i]== -1||matrix[i][j]> matrix[i][worker[j]])){
				matrix[i][worker[j]] = matrix[i][j];
				//matrix[i][j]= matrix[worker[i]][j];
				worker[i]=j;
			}
			/*
			if(!job[j]&&matrix[i][j]>max_cost){
				max_cost = matrix[i][j];
				best_job = j;
			}*/
		}
		job[worker[i]]=i;
		//job[best_job] = 1;
		//worker[i] = best_job;
		
	}
	int total_cost = 0;
	for(i = 0;i<n;i++){
		total_cost += matrix[i][worker[i]];
		printf("Worker %d assigned to job %d with cost %d\n",i+1,worker[i]+1,matrix[i][worker[i]]);
	}
	printf("Total cost : %d", total_cost);
}
int main(){
	FILE *f;
	int n;
	f = fopen("Assignmentc.txt","rt");
	fscanf(f,"%d",&n);
	for(int i = 0;i<n;i++){
		for(int j=0;j<n;j++){
			fscanf(f,"%3d",&matrix[i][j]);
		}
	}
	AP(n);
	fclose(f);
	return 0;	
}
