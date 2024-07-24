#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

/// Hàm tạo và xuất ma trận vuông a chứa các phần tử ngẫu nhiên có cấp n >= 5
void generate_and_print_square_matrix(int a[MAX_SIZE][MAX_SIZE], int n, int k) {
    srand(time(0)); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % (k + 1);
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }//
}

/// Hàm xuất các phần tử trên đường chéo chính
void print_main_diagonal(int a[MAX_SIZE][MAX_SIZE], int n) {
    printf("Cac phan tu tren duong cheo chinh:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i][i]);
    }
    printf("\n");
}//

/// Hàm xuất các phần tử thuộc đường chéo song song với đường chéo chính
void print_parallel_diagonals(int a[MAX_SIZE][MAX_SIZE], int n) {
    printf("Cac phan tu thuoc duong cheo song song voi duong cheo chinh:\n");

    for (int d = 1; d < n; d++) {
        for (int i = 0; i < n - d; i++) {
            printf("%d ", a[i][i + d]);
        }
        printf("\n");
    }

    for (int d = 1; d < n; d++) {
        for (int i = 0; i < n - d; i++) {
            printf("%d ", a[i + d][i]);
        }
        printf("\n");
    }//
}

/// Hàm tìm phần tử max thuộc tam giác trên của đường chéo chính
int max_upper_triangle(int a[MAX_SIZE][MAX_SIZE], int n) {
    int max = a[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
    }
    return max;
}//

// Hàm sắp xếp ma trận tăng dần theo kiểu zic-zac
void sort_matrix_zigzag(int a[MAX_SIZE][MAX_SIZE], int n) {
    int temp[MAX_SIZE * MAX_SIZE];
    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[index++] = a[i][j];
        }
    }

    for (int i = 0; i < index - 1; i++) {
        for (int j = i + 1; j < index; j++) {
            if (temp[i] > temp[j]) {
                int tmp = temp[i];
                temp[i] = temp[j];
                temp[j] = tmp;
            }
        }
    }

    // Gán lại các phần tử đã sắp xếp vào ma trận theo kiểu zic-zac
    index = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                a[i][j] = temp[index++];
            }
        }
        else {
            for (int j = n - 1; j >= 0; j--) {
                a[i][j] = temp[index++];
            }
        }
    }

    printf("Ma tran sau khi sap xep tang dan theo kieu zic-zac:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// Hàm sắp xếp đường chéo chính tăng dần từ trên xuống dưới
void sort_main_diagonal(int a[MAX_SIZE][MAX_SIZE], int n) {
    int temp[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        temp[i] = a[i][i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (temp[i] > temp[j]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        a[i][i] = temp[i];
    }

    printf("Ma tran sau khi sap xep duong cheo chinh tang dan tu tren xuong duoi:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
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
    print_main_diagonal(a, n);
    print_parallel_diagonals(a, n);
    printf("Phan tu lon nhat trong tam giac tren cua duong cheo chinh: %d\n", max_upper_triangle(a, n));
    sort_matrix_zigzag(a, n);
    sort_main_diagonal(a, n);

    return 0;
}
