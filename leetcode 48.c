#include <stdio.h>

#define MAX 100

void rotate(int matrix[MAX][MAX], int n) {
	int i,j;
    
    for ( i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Step 2: Reverse each row
    for (i = 0; i < n; i++) {
        for ( j = 0; j < n / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = temp;
        }
    }
}

int main() {
    int n;
    int j,i;
    int matrix[MAX][MAX];

    printf("Enter size of matrix (n): ");
    scanf("%d", &n);

    printf("Enter elements of %d x %d matrix:\n", n, n);
    for ( i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    rotate(matrix, n);

    printf("Matrix after 90 degree rotation:\n");
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

