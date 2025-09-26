#include <stdio.h>
#include <stdlib.h>

struct sparse {
    int row;
    int col;
    int value;
};

struct sparsematrix {
    int nvalues;
    struct sparse unit[100];
};

void ReadSparse(struct sparsematrix *sp, int *matrix, int rows, int cols) {
    sp->nvalues = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int val = *(matrix + i * cols + j);
            if (val != 0) {
                sp->unit[sp->nvalues].row = i;
                sp->unit[sp->nvalues].col = j;
                sp->unit[sp->nvalues].value = val;
                sp->nvalues++;
            }
        }
    }
}

void DisplaySparse(struct sparsematrix *sp) {
    for (int i = 0; i < sp->nvalues; i++) {
        printf("%d %d %d\n", sp->unit[i].row, sp->unit[i].col, sp->unit[i].value);
    }
    printf("\n");
}

void AddSparse(struct sparsematrix *sp1, struct sparsematrix *sp2) {
    struct sparsematrix result;
    result.nvalues = 0;
    int i = 0, j = 0;
    while (i < sp1->nvalues && j < sp2->nvalues) {
        if (sp1->unit[i].row < sp2->unit[j].row ||
           (sp1->unit[i].row == sp2->unit[j].row && sp1->unit[i].col < sp2->unit[j].col)) {
            result.unit[result.nvalues++] = sp1->unit[i++];
        } else if (sp1->unit[i].row > sp2->unit[j].row ||
                 (sp1->unit[i].row == sp2->unit[j].row && sp1->unit[i].col > sp2->unit[j].col)) {
            result.unit[result.nvalues++] = sp2->unit[j++];
        } else {
            int sum = sp1->unit[i].value + sp2->unit[j].value;
            if (sum != 0) {
                result.unit[result.nvalues].row = sp1->unit[i].row;
                result.unit[result.nvalues].col = sp1->unit[i].col;
                result.unit[result.nvalues].value = sum;
                result.nvalues++;
            }
            i++;
            j++;
        }
    }
    while (i < sp1->nvalues) {
        result.unit[result.nvalues++] = sp1->unit[i++];
    }
    while (j < sp2->nvalues) {
        result.unit[result.nvalues++] = sp2->unit[j++];
    }
    DisplaySparse(&result);
}

void TransposeSparse(struct sparsematrix *sp) {
    struct sparsematrix result;
    result.nvalues = sp->nvalues;
    for (int i = 0; i < sp->nvalues; i++) {
        result.unit[i].row = sp->unit[i].col;
        result.unit[i].col = sp->unit[i].row;
        result.unit[i].value = sp->unit[i].value;
    }
    for (int i = 0; i < result.nvalues - 1; i++) {
        for (int j = i + 1; j < result.nvalues; j++) {
            if (result.unit[i].row > result.unit[j].row ||
               (result.unit[i].row == result.unit[j].row && result.unit[i].col > result.unit[j].col)) {
                struct sparse temp = result.unit[i];
                result.unit[i] = result.unit[j];
                result.unit[j] = temp;
            }
        }
    }
    DisplaySparse(&result);
}

int main() {
    int rows1;
    int cols1;

    printf("Enter the number of rows in the first matrix : ");
    scanf("%d", &rows1);
    printf("Enter the number of colomns in the matrix : ");
    scanf("%d", &cols1);

    int *matrix1 = (int *)malloc((rows1 * cols1) * sizeof(int));

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            printf("Enter matrix1[%d][%d] : ", i, j);
            scanf("%d", &matrix1[i * cols1 + j]);
        }
    }

    int rows2;
    int cols2;

    printf("Enter the number of rows in the second matrix : ");
    scanf("%d", &rows2);
    printf("Enter the number of colomns in the matrix : ");
    scanf("%d", &cols2);

    if (rows1 != rows2 || cols1 != cols2) {
        printf("Matrix addition not possible. Dimensions must match.\n");
        return 1;
    }

    int *matrix2 = (int *)malloc((rows2 * cols2) * sizeof(int));

    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("Enter matrix2[%d][%d] : ", i, j);
            scanf("%d", &matrix2[i * cols2 + j]);
        }
    }

    struct sparsematrix sparse1;
    struct sparsematrix sparse2;

    ReadSparse(&sparse1, matrix1, rows1, cols1);
    ReadSparse(&sparse2, matrix2, rows2, cols2);

    printf("The first sparsematrix represented in the form of an array of structures is : ");
    DisplaySparse(&sparse1);
    printf("The second sparsematrix represented in the form of an array of structures is : ");
    DisplaySparse(&sparse2);

    printf("The sum of the two sparsematrices are : ");
    AddSparse(&sparse1, &sparse2);

    printf("The transpose of the first sparse matrix is : ");
    TransposeSparse(&sparse1);
    printf("The transpose of the second sparse matrix is : ");
    TransposeSparse(&sparse2);

    printf("Thank you for using my program ! :)\n");

    free(matrix1);
    free(matrix2);

    printf("Thank you for usign my program ! :)");
    return 0;
}
