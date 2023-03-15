//Author: Huỳnh Phúc Toàn
#include <stdio.h>

#define MAX_VILLAGES 1125
#define INF 999999

int ary[MAX_VILLAGES][MAX_VILLAGES];
int completed[MAX_VILLAGES] = {0};
int n, num_villages;
int start_villages[MAX_VILLAGES];
int min_costs[MAX_VILLAGES];

void docfile(FILE *f, int ary[MAX_VILLAGES][MAX_VILLAGES], int &n, int start_villages[], int &num_villages);
int least(int c) {
    int i, nc = INF;
    int min = INF, kmin, min_index = INF;

    for (i = 0; i < n; i++) {
        if ((ary[c][i] != 0) && (completed[i] == 0)) {
            if (ary[c][i] < min || (ary[c][i] == min && i < min_index)) {
                min = ary[c][i];
                kmin = ary[c][i];
                nc = i;
                min_index = i;
            }
        }
    }

    if (min != INF) {
        return nc;
    }

    return INF;
}

void mincost(int city, int start_village_index) {
    int i, ncity;

    completed[city] = 1;

    ncity = least(city);

    if (ncity == INF) {
        ncity = start_villages[start_village_index];
        min_costs[start_village_index] += ary[city][ncity];
        completed[city] = 0;
        return;
    }

    min_costs[start_village_index] += ary[city][ncity];
    mincost(ncity, start_village_index);
}

int main() {

    FILE *f;
   
    docfile(f, ary, n, start_villages, num_villages);
//
    int i, j;

    for (i = 0; i < num_villages; i++) {
        for (j = 0; j < n; j++) {
            completed[j] = 0;
        }
        mincost(start_villages[i], i);
    }

    for (i = 0; i < num_villages; i++) {
        printf("Chi phi nho nhat tai dinh %d la %d\n", start_villages[i]+1, min_costs[i]);
    }
    int min = min_costs[0];
	//Tim phan tu nho nhat trong mang min_costs
	for (i = 1; i < num_villages; i++) {
    	if (min_costs[i] < min) {
        	min = min_costs[i];
    	}
	}

	printf("\nHanh trinh tot nhat co chi phi la: %d\n", min);


    //Ham xuat ra danh sach cac dinh can duyet
//	for (int i = 0; i < num_villages; i++) {		
//    	printf("\t%d", start_villages[i]);
//	}
	
//	for (i = 0; i < n; i++) {
//        printf("\n");
//
//        for (j = 0; j < n; j++) {
//            printf("\t%d", ary[i][j]);
//        }
//    }
    return 0;
}

void docfile(FILE *f, int ary[][MAX_VILLAGES], int &n, int start_villages[], int &num_villages)
{
    f = fopen("GTS2c.txt", "rt");
    fscanf(f, "%d", &n);
    fscanf(f, "%d", &num_villages);
    for (int i = 0; i < num_villages; i++)
    {
        fscanf(f, "%d", &start_villages[i]);
        start_villages[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(f, "%d", &ary[i][j]);
        }
    }
    fclose(f);
}
//Author: Huỳnh Phúc Toàn