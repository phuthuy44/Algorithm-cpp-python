#include<stdio.h>
#include<stdlib.h> 
#include<limits.h>
#define Max_cities 150 
#define Max_distance INT_MAX
int n; // number of cities 
int matrix[Max_cities][Max_cities];
int visited[Max_cities];
int path[Max_cities];
int min_path[Max_cities];
int min_distance = Max_distance;
void tsp_backtracking(int distance, int visited_count){
	int i,j;
	if(visited_count == n){
		distance += matrix[path[n-1]][path[0]];
		if(distance < min_distance){
			for(i = 0;i <n;i++){
				min_path[i]=path[i+1];
			}
			min_path[n]=path[0];
			min_distance = distance;
		}
		return;
	}
	//Try all unvisited cities
	for(i =0; i<n;i++){
		if(!visited[i]){
			visited[i] = 1;
			path[visited_count] = i;
			//Calculate the distance to the next unvisited city
			int d = distance + matrix[path[visited_count-1]][i];
			//Pure the brach if the minimum distance so far is greater than the current minimum distance
			if(d < min_distance){
				tsp_backtracking(d,visited_count +1);
			}
			visited[i]=0;		
		}
	}
}
int main(){
	FILE *f;
	f = fopen("tsp_20vertex.txt","rt");
	if (f==NULL){
		printf("Error opening file");
		return 0;
	}
	fscanf(f,"%d",&n);
	for(int i =	0;i<n;i++){
		for(int j =0;j<n;j++){
			fscanf(f,"%4d",&matrix[i][j]);
		}
	}
	//start with the first city
	visited[0] = 1;
	path[0]= 0;
	tsp_backtracking(0,1);
	printf("Minimum Distance:%d\n",min_distance);
	printf("The minimum cost tour :");
	for(int i=0;i<n;i++){
		printf("%d->",min_path[i]+1);
	}
	printf("%d",min_path[0]+1);
	fclose(f);
	
	return 0;
}
