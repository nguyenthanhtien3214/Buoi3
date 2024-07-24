#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Hàm tạo và xuất ma trận chứa các phần tử ngẫu nhiên từ 0 đến k
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

// Hàm xuất các cột chỉ chứa số lẻ
void print_odd_columns(int a[MAX_ROWS][MAX_COLS], int m, int n) {
    printf("Cac cot chi chua so le:\n");
    for (int j = 0; j < n; j++) {
        int all_odd = 1;
        for (int i = 0; i < m; i++) {
            if (a[i][j] % 2 == 0) {
                all_odd = 0;
                break;
            }
        }
        if (all_odd) {
            for (int i = 0; i < m; i++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
}

// Hàm tìm phần tử lớn nhất trên biên của ma trận
int max_border_element(int a[MAX_ROWS][MAX_COLS], int m, int n) {
    int max = a[0][0];
    for (int j = 0; j < n; j++) {
        if (a[0][j] > max) max = a[0][j]; 
        if (a[m - 1][j] > max) max = a[m - 1][j]; 
    }
    for (int i = 1; i < m - 1; i++) {
        if (a[i][0] > max) max = a[i][0]; 
        if (a[i][n - 1] > max) max = a[i][n - 1]; 
    }
    return max;
}

// Hàm kiểm tra xem một số có chứa chữ số 2 hay không
int contains_digit_2(int num) {
    while (num > 0) {
        if (num % 10 == 2) return 1;
        num /= 10;
    }
    return 0;
}

// Hàm đếm số phần tử có chữ số 2
int count_elements_with_digit_2(int a[MAX_ROWS][MAX_COLS], int m, int n) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (contains_digit_2(a[i][j])) {
                count++;
            }
        }
    }
    return count;
}

// Hàm xuất các phần tử cực tiểu
void local_minima(int a[MAX_ROWS][MAX_COLS], int m, int n) {
    printf("Cac phan tu cuc tieu:\n");
    for (int i = 1; i < m - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (a[i][j] < a[i - 1][j] && a[i][j] < a[i + 1][j] && a[i][j] < a[i][j - 1] && a[i][j] < a[i][j + 1]) {
                printf("%d ", a[i][j]);
            }
        }
    }
    printf("\n");
}

// Hàm sắp xếp ma trận theo yêu cầu bài 3.5
void sort_matrix_rows(int a[MAX_ROWS][MAX_COLS], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((i % 2 == 0 && a[i][j] > a[i][k]) || (i % 2 != 0 && a[i][j] < a[i][k])) {
                    int temp = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = temp;
                }
            }
        }
    }
    printf("Ma tran sau khi sap xep cac dong co chi so le tang dan, dong co chi so chan giam dan:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// Hàm sắp xếp ma trận theo yêu cầu bài 3.6
void sort_matrix_columns(int a[MAX_ROWS][MAX_COLS], int m, int n) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m - 1; i++) {
            for (int k = i + 1; k < m; k++) {
                if ((j % 2 == 0 && a[i][j] > a[k][j]) || (j % 2 != 0 && a[i][j] < a[k][j])) {
                    int temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
    }
    printf("Ma tran sau khi sap xep cac cot co chi so chan tang dan, cot co chi so le giam dan:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// Hàm kiểm tra ma trận có giảm dần theo cột và dòng
int is_decreasing_zigzag(int a[MAX_ROWS][MAX_COLS], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0 && a[i][j] >= a[i - 1][j]) return 0;
            if (j > 0 && a[i][j] >= a[i][j - 1]) return 0;
        }
    }
    return 1;
}

// Hàm liệt kê chỉ số các dòng chứa toàn giá trị chẵn
void even_rows_indices(int a[MAX_ROWS][MAX_COLS], int m, int n) {
    printf("Chi so cac dong chua toan gia tri chan:\n");
    for (int i = 0; i < m; i++) {
        int all_even = 1;
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                all_even = 0;
                break;
            }
        }
        if (all_even) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Hàm liệt kê các dòng chứa giá trị giảm dần
void decreasing_rows_indices(int a[MAX_ROWS][MAX_COLS], int m, int n) {
    printf("Chi so cac dong chua gia tri giam dan:\n");
    for (int i = 0; i < m; i++) {
        int decreasing = 1;
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] <= a[i][j + 1]) {
                decreasing = 0;
                break;
            }
        }
        if (decreasing) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Hàm tìm giá trị xuất hiện nhiều nhất trong ma trận
int most_frequent_value(int a[MAX_ROWS][MAX_COLS], int m, int n) {
    int freq[MAX_ROWS * MAX_COLS] = { 0 };
    int max_count = 0;
    int most_frequent = a[0][0];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            freq[a[i][j]]++;
            if (freq[a[i][j]] > max_count) {
                max_count = freq[a[i][j]];
                most_frequent = a[i][j];
            }
        }
    }

    return most_frequent;
}

// Hàm tìm chữ số xuất hiện nhiều nhất trong ma trận
int most_frequent_digit(int a[MAX_ROWS][MAX_COLS], int m, int n) {
    int digit_count[10] = { 0 };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int num = a[i][j];
            while (num > 0) {
                digit_count[num % 10]++;
                num /= 10;
            }
        }
    }

    int max_count = 0;
    int most_frequent_digit = 0;
    for (int i = 0; i < 10; i++) {
        if (digit_count[i] > max_count) {
            max_count = digit_count[i];
            most_frequent_digit = i;
        }
    }

    return most_frequent_digit;
}

// Hàm liệt kê các cột có tổng nhỏ nhất trong ma trận
void columns_with_min_sum(int a[MAX_ROWS][MAX_COLS], int m, int n) {
    int min_sum = 0;
    for (int i = 0; i < m; i++) {
        min_sum += a[i][0];
    }

    for (int j = 1; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += a[i][j];
        }
        if (sum < min_sum) {
            min_sum = sum;
        }
    }

    printf("Chi so cac cot co tong nho nhat: ");
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += a[i][j];
        }
        if (sum == min_sum) {
            printf("%d ", j);
        }
    }
    printf("\n");
}

// Hàm hoán vị hai cột i và j trong ma trận
void swap_columns(int a[MAX_ROWS][MAX_COLS], int m, int i, int j) {
    for (int row = 0; row < m; row++) {
        int temp = a[row][i];
        a[row][i] = a[row][j];
        a[row][j] = temp;
    }
}

// Hàm hoán vị hai dòng k và l trong ma trận
void swap_rows(int a[MAX_ROWS][MAX_COLS], int n, int k, int l) {
    for (int col = 0; col < n; col++) {
        int temp = a[k][col];
        a[k][col] = a[l][col];
        a[l][col] = temp;
    }
}

int main() {
    int a[MAX_ROWS][MAX_COLS];
    int m, n, k, i, j, x, y;

    printf("Nhap so dong m: ");
    scanf_s("%d", &m);
    printf("Nhap so cot n: ");
    scanf_s("%d", &n);
    printf("Nhap gia tri ngau nhien toi da k: ");
    scanf_s("%d", &k);

    generate_and_print_matrix(a, m, n, k);
    print_odd_columns(a, m, n);
    printf("Phan tu lon nhat tren bien cua ma tran: %d\n", max_border_element(a, m, n));
    printf("So phan tu co chu so 2: %d\n", count_elements_with_digit_2(a, m, n));
    local_minima(a, m, n);
    sort_matrix_rows(a, m, n);
    sort_matrix_columns(a, m, n);
    if (is_decreasing_zigzag(a, m, n)) {
        printf("Ma tran giam dan theo cot va dong (ziczac)\n");
    }
    else {
        printf("Ma tran khong giam dan theo cot va dong (ziczac)\n");
    }
    even_rows_indices(a, m, n);
    decreasing_rows_indices(a, m, n);
    printf("Gia tri xuat hien nhieu nhat trong ma tran: %d\n", most_frequent_value(a, m, n));
    printf("Chu so xuat hien nhieu nhat trong ma tran: %d\n", most_frequent_digit(a, m, n));
    columns_with_min_sum(a, m, n);

    printf("Nhap chi so hai cot can hoan vi i va j: ");
    scanf_s("%d %d", &i, &j);
    swap_columns(a, m, i, j);
    printf("Ma tran sau khi hoan vi hai cot %d va %d:\n", i, j);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("Nhap chi so hai dong can hoan vi k va l: ");
    scanf_s("%d %d", &x, &y);
    swap_rows(a, n, x, y);
    printf("Ma tran sau khi hoan vi hai dong %d va %d:\n", x, y);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
