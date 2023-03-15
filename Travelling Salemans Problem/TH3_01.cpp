//Author: Huỳnh Phúc Toàn
#include <stdio.h>

#define MAX_VILLAGES 1125
#define INF 999999
int ary[MAX_VILLAGES][MAX_VILLAGES];
int completed[MAX_VILLAGES] = {0};
int n, cost = 0;
int start_village = 0;
void docfile(FILE *f, int ary[MAX_VILLAGES][MAX_VILLAGES], int &n, int &start_village);
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
        cost += kmin;
    }

    return nc;
}
//Ở đây, chúng ta đã thêm biến min_index để lưu trữ chỉ số của đỉnh có trọng số nhỏ nhất trong dòng đó. 
//Nếu tìm thấy một trọng số nhỏ hơn hoặc nếu trọng số bằng nhau nhưng chỉ số của đỉnh đang xét nhỏ hơn min_index, 
//thì ta cập nhật min, kmin, nc và min_index. Cuối cùng, trả về chỉ số của đỉnh nhỏ nhất.

void mincost(int city) {
    int i, ncity;

    completed[city] = 1;

   
    ncity = least(city);

    if (ncity == INF) {
        ncity = start_village;
//       
        cost += ary[city][ncity];

        return;
    }

    mincost(ncity);
}

int main() {

	FILE *f;
	docfile(f,ary,n,start_village);
	
	int i, j;
    
    
    mincost(start_village);

    printf("\n\nMinimum cost is %d\n", cost);

    return 0;
}
void docfile(FILE *f, int ary[][MAX_VILLAGES], int &n, int &start_village)
{
	
    f = fopen("GTS1a.txt", "rt");
    fscanf(f, "%d", &n);
	fscanf(f, "%d", &start_village);
	start_village--;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(f, "%d", &ary[i][j]);
        }
    }
    fclose(f);
}

// Dòng 1: Khai báo thư viện tiêu chuẩn của C.
// Dòng 3-5: Định nghĩa hằng số MAX_VILLAGES bằng 10 và INF bằng 999.
// Dòng 7-9: Khai báo mảng hai chiều ary với kích thước MAX_VILLAGES x MAX_VILLAGES, mảng completed với kích thước MAX_VILLAGES, biến n và cost.
// Dòng 11-33: Định nghĩa hàm takeInput để nhập vào số lượng làng và ma trận chi phí. Hàm sử dụng hai vòng lặp for để nhập vào từng phần tử của ma trận chi phí và gán giá trị 0 cho mảng completed tại mỗi chỉ số.
// Dòng 35-46: Định nghĩa hàm least để tìm kiếm một điểm kề tiếp theo có chi phí nhỏ nhất từ một điểm hiện tại. Hàm này sử dụng vòng lặp for để tìm kiếm tất cả các điểm kề của điểm hiện tại, và lưu trữ điểm có chi phí nhỏ nhất trong biến nc.
// Dòng 48-58: Định nghĩa hàm mincost để tính toán đường đi ngắn nhất từ một điểm đến điểm cuối. Hàm sử dụng đệ quy để duyệt toàn bộ đồ thị, tìm kiếm điểm kề tiếp theo có chi phí nhỏ nhất và tính toán chi phí trung bình cho đường đi.
// Dòng 60-69: Hàm main để điều khiển chương trình. Hàm gọi hàm takeInput để lấy dữ liệu đầu vào, sau đó gọi hàm mincost để tính toán đường đi ngắn nhất. Cuối cùng, hàm in ra đường đi và chi phí trung bình.
//Author: Huỳnh Phúc Toàn