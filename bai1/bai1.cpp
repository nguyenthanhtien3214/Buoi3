#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 100
#define MAX_COLS 100

/// Hàm tạo và xuất ma trận a chứa các phần tử ngẫu nhiên từ 0 đến k
void generate_and_print_matrix(int a[MAX_ROWS][MAX_COLS], int m, int n, int k) {
    srand(time(0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % (k + 1);
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

/// Hàm tính và xuất tổng giá trị từng dòng
void sum_of_rows(int a[MAX_ROWS][MAX_COLS], int m, int n) {
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += a[i][j];
        }
        printf("Tong gia tri dong %d: %d\n", i, sum);
    }
}

/// Hàm xuất phần tử lớn nhất trên từng cột
void max_in_columns(int a[MAX_ROWS][MAX_COLS], int m, int n) {
    for (int j = 0; j < n; j++) {
        int max = a[0][j];
        for (int i = 1; i < m; i++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }//
        printf("Phan tu lon nhat cot %d: %d\n", j, max);
    }
}

// Hàm xuất các phần tử thuộc các đường biên
void border_elements(int a[MAX_ROWS][MAX_COLS], int m, int n) {
    printf("Cac phan tu thuoc cac duong bien:\n");
    for (int j = 0; j < n; j++) {
        printf("%d ", a[0][j]); 
    }
    for (int i = 1; i < m; i++) {
        printf("%d ", a[i][n - 1]); 
    }
    for (int j = n - 2; j >= 0; j--) {
        printf("%d ", a[m - 1][j]); 
    }
    for (int i = m - 2; i > 0; i--) {
        printf("%d ", a[i][0]); 
    }
    printf("\n");
}

// Hàm xuất các phần tử cực đại
void local_maxima(int a[MAX_ROWS][MAX_COLS], int m, int n) {
    printf("Cac phan tu cuc dai:\n");
    for (int i = 1; i < m - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (a[i][j] > a[i - 1][j] && a[i][j] > a[i + 1][j] && a[i][j] > a[i][j - 1] && a[i][j] > a[i][j + 1]) {
                printf("%d ", a[i][j]);
            }
        }
    }
    printf("\n");
}

// Hàm xuất các phần tử hoàng hậu
void queen_elements(int a[MAX_ROWS][MAX_COLS], int m, int n) {
    printf("Cac phan tu hoang hau:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int is_queen = 1;
            for (int x = 0; x < m; x++) {
                if (a[x][j] > a[i][j]) {
                    is_queen = 0;
                    break;
                }
            }
            for (int y = 0; y < n; y++) {
                if (a[i][y] > a[i][j]) {
                    is_queen = 0;
                    break;
                }
            }
            if (is_queen) {
                printf("%d ", a[i][j]);
            }
        }
    }
    printf("\n");
}

// Hàm xuất các phần tử là điểm yên ngựa
void saddle_points(int a[MAX_ROWS][MAX_COLS], int m, int n) {
    printf("Cac phan tu la diem yen ngua:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int is_saddle = 1;
            for (int k = 0; k < n; k++) {
                if (a[i][k] < a[i][j]) {
                    is_saddle = 0;
                    break;
                }
            }
            for (int k = 0; k < m; k++) {
                if (a[k][j] > a[i][j]) {
                    is_saddle = 0;
                    break;
                }
            }
            if (is_saddle) {
                printf("%d ", a[i][j]);
            }
        }
    }
    printf("\n");
}

// Hàm xuất dòng chỉ chứa số chẵn
void even_rows(int a[MAX_ROWS][MAX_COLS], int m, int n) {
    printf("Cac dong chi chua so chan:\n");
    for (int i = 0; i < m; i++) {
        int all_even = 1;
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                all_even = 0;
                break;
            }
        }
        if (all_even) {
            for (int j = 0; j < n; j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
}

// Hàm sắp xếp mảng a tăng theo từng dòng
void sort_rows(int a[MAX_ROWS][MAX_COLS], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i][j] > a[i][k]) {
                    int temp = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = temp;
                }
            }
        }
    }
    printf("Ma tran sau khi sap xep tang theo tung dong:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[MAX_ROWS][MAX_COLS];
    int m, n, k;

    printf("Nhap so dong m: ");
    scanf_s("%d", &m);
    printf("Nhap so cot n: ");
    scanf_s("%d", &n);
    printf("Nhap gia tri ngau nhien toi da k: ");
    scanf_s("%d", &k);

    generate_and_print_matrix(a, m, n, k);
    sum_of_rows(a, m, n);
    max_in_columns(a, m, n);
    border_elements(a, m, n);
    local_maxima(a, m, n);
    queen_elements(a, m, n);
    saddle_points(a, m, n);
    even_rows(a, m, n);
    sort_rows(a, m, n);

    return 0;
}
