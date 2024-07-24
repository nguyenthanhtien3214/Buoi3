#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Hàm tạo và xuất ma trận vuông a chứa các phần tử ngẫu nhiên có cấp n >= 5
void generate_and_print_square_matrix(int a[MAX_SIZE][MAX_SIZE], int n, int k) {
    srand(time(0)); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % (k + 1);
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

/// Hàm sắp xếp đường chéo phụ tăng /giảm 
void sort_secondary_diagonal(int a[MAX_SIZE][MAX_SIZE], int n, int ascending) {
    int temp[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        temp[i] = a[i][n - i - 1];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ascending && temp[i] > temp[j]) || (!ascending && temp[i] < temp[j])) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        a[i][n - i - 1] = temp[i];
    }

    printf("Ma tran sau khi sap xep duong cheo phu %s dan:\n", ascending ? "tang" : "giam");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}//

/// Hàm sắp xếp ma trận các dòng có chỉ số lẻ thì tăng , còn các dòng có chỉ số chẵn thì giảm 
void sort_matrix_rows(int a[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((i % 2 == 0 && a[i][j] < a[i][k]) || (i % 2 != 0 && a[i][j] > a[i][k])) {
                    int temp = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = temp;
                }
            }
        }
    }

    printf("Ma tran sau khi sap xep cac dong le tang dan, dong chan giam dan:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}//

// Hàm sắp xếp ma trận các cột có chỉ số lẻ thì giảm, còn các cột có chỉ số chẵn thì tăng 
void sort_matrix_columns(int a[MAX_SIZE][MAX_SIZE], int n) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - 1; i++) {
            for (int k = i + 1; k < n; k++) {
                if ((j % 2 == 0 && a[i][j] > a[k][j]) || (j % 2 != 0 && a[i][j] < a[k][j])) {
                    int temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
    }

    printf("Ma tran sau khi sap xep cac cot chan tang dan, cot le giam dan:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// Hàm sắp xếp các đường chéo chính và các đường chéo song song với đường chéo chính tăng 
void sort_all_diagonals(int a[MAX_SIZE][MAX_SIZE], int n) {
    for (int d = 0; d < n; d++) {
        int temp[MAX_SIZE];
        int index = 0;
        for (int i = 0; i < n - d; i++) {
            temp[index++] = a[i][i + d];
        }
        for (int i = 0; i < index - 1; i++) {
            for (int j = i + 1; j < index; j++) {
                if (temp[i] > temp[j]) {
                    int t = temp[i];
                    temp[i] = temp[j];
                    temp[j] = t;
                }
            }
        }
        index = 0;
        for (int i = 0; i < n - d; i++) {
            a[i][i + d] = temp[index++];
        }
    }

    for (int d = 1; d < n; d++) {
        int temp[MAX_SIZE];
        int index = 0;
        for (int i = 0; i < n - d; i++) {
            temp[index++] = a[i + d][i];
        }
        for (int i = 0; i < index - 1; i++) {
            for (int j = i + 1; j < index; j++) {
                if (temp[i] > temp[j]) {
                    int t = temp[i];
                    temp[i] = temp[j];
                    temp[j] = t;
                }
            }
        }
        index = 0;
        for (int i = 0; i < n - d; i++) {
            a[i + d][i] = temp[index++];
        }
    }

    printf("Ma tran sau khi sap xep cac duong cheo chinh va song song tang dan:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// Hàm di chuyển các phần tử trong ma trận sao cho các phần tử chẵn nằm ở các dòng đầu mảng,các phần tử lẻ nằm ở các dòng cuối mảng
void rearrange_matrix_even_odd(int a[MAX_SIZE][MAX_SIZE], int n) {
    int even[MAX_SIZE * MAX_SIZE], odd[MAX_SIZE * MAX_SIZE];
    int even_count = 0, odd_count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 0) {
                even[even_count++] = a[i][j];
            }
            else {
                odd[odd_count++] = a[i][j];
            }
        }
    }

    int index = 0;
    for (int i = 0; i < even_count; i++) {
        a[index / n][index % n] = even[i];
        index++;
    }
    for (int i = 0; i < odd_count; i++) {
        a[index / n][index % n] = odd[i];
        index++;
    }

    printf("Ma tran sau khi di chuyen cac phan tu chan len dau va le xuong cuoi:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// Hàm kiểm tra ma trận có đối xứng nhau qua đường chéo chính hay không
int is_symmetric_across_main_diagonal(int a[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i][j] != a[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int a[MAX_SIZE][MAX_SIZE];
    int n, k;

    printf("Nhap cap cua ma tran vuong n (n >= 5): ");
    scanf_s("%d", &n);
    if (n < 5) {
        printf("Cap cua ma tran phai >= 5\n");
        return 1;
    }

    printf("Nhap gia tri ngau nhien toi da k: ");
    scanf_s("%d", &k);

    generate_and_print_square_matrix(a, n, k);

    sort_secondary_diagonal(a, n, 1); 
    sort_secondary_diagonal(a, n, 0); 

    sort_matrix_rows(a, n); 

    sort_matrix_columns(a, n); 

    sort_all_diagonals(a, n); 

    rearrange_matrix_even_odd(a, n); 

    if (is_symmetric_across_main_diagonal(a, n)) {
        printf("Ma tran doi xung qua duong cheo chinh\n");
    }
    else {
        printf("Ma tran khong doi xung qua duong cheo chinh\n");
    }

    return 0;
}
