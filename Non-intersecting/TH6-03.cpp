#include<stdio.h>
#include<stdlib.h>
typedef struct{
     int a;
     int b;
}LineSegment;
int compare(const void *a, const void *b){
     LineSegment *l1 = (LineSegment *)a;
     LineSegment *l2 = (LineSegment *)b;
     if(l1->b != l2->b){
          return l1->b - l2->b;
     }
     return l1->a - l2->a;
}
int main(){
     FILE *fp;
     int n;
     fp = fopen("line1.txt", "r");
     fscanf(fp, "%d", &n);
     LineSegment *segments = (LineSegment *)malloc(n * sizeof(LineSegment));
     if(segments == NULL){
          printf("Memory allocated failed!\n");
          return 1;
     }
     for(int i = 0; i < n; i++){
          int a, b;
          fscanf(fp, "%d %d", &a, &b);
          segments[i].a = a;
          segments[i].b = b;
     }
     qsort(segments, n, sizeof(LineSegment), compare);
     int count = 1;
     int end = segments[0].b;
     printf("%d %d\n", segments[0].a, segments[0].b);
     for(int i = 1; i < n; i++){
          if(segments[i].a >= end){
               count++;
               printf("%d %d\n", segments[i].a, segments[i].b);
               end = segments[i].b;
          }
     }
     printf("Have %d non-intersecting segments\n", count);
     fclose(fp);
     free(segments);
     return 0;
}