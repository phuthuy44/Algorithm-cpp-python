#include<stdio.h>
#include<stdlib.h>
typedef struct{
     int a;
     int b;
}LineSegment;
int compare(const void *a, const void *b){
     LineSegment *l1 = (LineSegment*)a;
     LineSegment *l2 = (LineSegment*)b;
     if( l1->a != l2->a ){
          return l1->a - l2->a;
     }
     return l1->b - l2->b;
}
void merge(LineSegment* arr, int left, int mid, int right, int(*compar)(const void *, const void *)){
     int i, j, k;
     int n1 = mid - left + 1;
     int n2 = right - mid;

     //create two temporary arrays
     LineSegment *L = (LineSegment*)malloc(n1 * sizeof(LineSegment));
     LineSegment *R = (LineSegment*)malloc(n2 * sizeof(LineSegment));

     //copy data to temp arrays
     for(i = 0; i < n1; i++){
          L[i] = arr[left + i];
     }
     for(j = 0; j < n2; j++){
          R[j]= arr[mid + j];
     }
     //merge temp arrays back into arr[left..right]
     i = 0;
     j = 0;
     k = left;
     while(i<n1 && j<n2){
          if(compare(&L[i], &R[j]) <= 0){
               arr[k] = L[i];
               i++;
          }else{
               arr[k] = R[j];
               j++;
          }
          k++;

     }
     //copy the remaining elements of L[]
     while(i<n1){
          arr[k] = L[i];
          i++;
          k++;
     }
     //copy the remaining elements of R[]
     while(j<n2){
          arr[k] = R[j];
          j++;
          k++;
     }
     free(L);
     free(R);

}
void msort(LineSegment*arr , int left, int right, int(*compare)(const void *, const void *)){
     if(left<right){
          //same as (left+right)/2, but avoids overflow for large left and right
          int mid = left + (right - left)/2;
          //sort first and second halves
          msort(arr, left, mid, compare);
          msort(arr, mid + 1, right, compare);
          merge(arr, left, mid, right, compare);
     }
}
int main(){
     FILE *fp;
     //Read the number of line segments from a file and allocate memory accordingly.
     fp = fopen("line1.txt","r");
     int n ;
     fscanf(fp,"%d",&n);
     LineSegment* segments = (LineSegment *) malloc(n*sizeof(LineSegment));
     if(segments == NULL){
          printf("Memory allocation failed\n");
          return 1;
     }
     //Read the starting and ending points of line segments from a file 
     for(int i=0;i<n;i++){
          int a,b;
          fscanf(fp,"%d %d",&a,&b);
          segments[i].a = a;
          segments[i].b = b;
     }
     //Using Quicksort to swap
     qsort(segments,n,sizeof(LineSegment),compare);
     //Using merge sort
    // msort(segments,n,sizeof(LineSegment),compare);
    // LineSegment* s =(LineSegment *)malloc(n*sizeof(LineSegment));
     //int size_s = 0;
     int count = 1;
     //Start with the first line segment and set its ending point as the"end"
     int end = segments[0].b;
     printf("%d %d\n",segments[0].a,segments[0].b);
     //Tìm các đoạn không giao nhau bằng cách lặp qua các đoạn đã sắp xếp và kiểm tra xem điểm kết thúc của đoạn trước nhỏ hơn hoặc bằng điểm bắt đầu của đoạn hiện tại

     for(int i=1;i<n;i++){
          if(segments[i].a >= end){
                
               //s[size_s++] = segments[i];
               count ++;
               printf("%d %d\n",segments[i].a,segments[i].b);
               end = segments[i].b;//set the ending point of the current line segment

          }
     }
     printf("Have %d non-intersecting segments.\n",count);
     //printf("Set of non-intersecting segments is : \n");
    /* for(int i=0;i<size_s;i++){
          printf("%d %d\n",s[i].a,s[i].b);
     }*/
     fclose(fp);
     free(segments);
     //free(s);
 return 0;
}
