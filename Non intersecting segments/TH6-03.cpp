#include<stdio.h>
#include<stdlib.h>
typedef struct{
     int a;
     int b;
     int index;
}LineSegment;
int compare(const void *a, const void *b){
     LineSegment *l1 = (LineSegment *)a;
     LineSegment *l2 = (LineSegment *)b;
     /* Sorting the segments by their end points. */
     if(l1->b == l2->b){
          return l1->index - l2->index;
     }
     return l1->b - l2->b;
}
int main(){
     FILE *fp;
     int n;
     fp = fopen("line2.txt", "r");
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
          segments[i].index = i;
     }
     qsort(segments, n, sizeof(LineSegment), compare);
     /*for(int i = 0;i<5;i++){
          printf("%d %d\n", segments[i].a, segments[i].b);
     }*/
     printf("===========\n");
     int count = 1;
    /* The end of the first segment. */
     int end = segments[0].b;
     printf("%d %d\n", segments[0].a, segments[0].b);
     /* Checking if the next segment's start is greater than the end of the last segment. If it is,
     then it is a non-intersecting segment. */
     for(int i = 1; i < n; i++){
          if(segments[i].a >= end){
               count++;
               printf("%d %d\n", segments[i].a, segments[i].b);
              /* Updating the end of the last segment. */
               end = segments[i].b;
          }
     }
     printf("Have %d non-intersecting segments\n", count);
     fclose(fp);
     free(segments);
     return 0;
}/* Setting the end of the current segment to the end of the previous segment. */
