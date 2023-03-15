#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
     int a;
     int b;
     int length;
}LineSegment;
int compare(const void *a, const void *b){
     LineSegment *l1=(LineSegment *)a;
     LineSegment *l2=(LineSegment *)b;
     //return l1->length - l2->length;
    int len1= abs(l1->b - l1->a);
     int len2= abs(l2->b - l2->a);
     if(len1 == len2){
          return 0;
     }
    return (len1 < len2) ? -1 : 1;
}
int main(){
     FILE *fp;
     fp = fopen("line1.txt","r");
     int n;
     fscanf(fp,"%d\n",&n);
     LineSegment *segments = (LineSegment *)malloc(n*sizeof(LineSegment));
     if(segments == NULL){
          printf("Memory allocation failed\n");
          return 1;
     }
     for(int i=0;i<n;i++){
          int a,b;
          fscanf(fp,"%d %d",&a,&b);
          segments[i].a = a;
          segments[i].b = b;
          segments[i].length = abs(b-a);
     }
     qsort(segments,n,sizeof(LineSegment),compare);
     int count=1;
     int end = segments[0].b;
     printf("%d %d\n",segments[0].a,segments[0].b);
     for(int i=1;i<n;i++){
          if(segments[i].a >= end){
               count++;
               printf("%d %d\n",segments[i].a,segments[i].b);
               end = segments[i].b;
          }
     }
     printf("Have %d non-intersecting segments\n",count);
     fclose(fp);
     free(segments);
     return 0;
}