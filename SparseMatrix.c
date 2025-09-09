#include <stdio.h>
#include <stdlib.h>

struct matrix {
    int row;
    int col;
    int value;
};

struct sparsematrix {
    int numValues;
    struct matrix elements[100];
};

// Function to enter a sparse matrix
void EnterMatrix(struct sparsematrix *s) {
    printf("Enter number of non-zero values: ");
    scanf("%d", &s->numValues);

    for (int i = 0; i < s->numValues; i++) {
        printf("Enter row, col, value for element %d: ", i + 1);
        scanf("%d %d %d", &s->elements[i].row, &s->elements[i].col, &s->elements[i].value);
    }
}

// Function to display sparse matrix in triplet form
void DisplayMatrix(struct sparsematrix s) {
    printf("Row Col Value\n");
    for (int i = 0; i < s.numValues; i++) {
        printf("%d   %d   %d\n", s.elements[i].row, s.elements[i].col, s.elements[i].value);
    }
}

// Function to add two sparse matrices
struct sparsematrix AddMatrix(struct sparsematrix a, struct sparsematrix b) {
    struct sparsematrix result;
    result.numValues = 0;

    int i = 0, j = 0;
    while (i < a.numValues && j < b.numValues) {
        if (a.elements[i].row == b.elements[j].row &&
            a.elements[i].col == b.elements[j].col) {
            result.elements[result.numValues].row = a.elements[i].row;
            result.elements[result.numValues].col = a.elements[i].col;
            result.elements[result.numValues].value = a.elements[i].value + b.elements[j].value;
            result.numValues++;
            i++;
            j++;
        }
        else if (a.elements[i].row < b.elements[j].row ||
                (a.elements[i].row == b.elements[j].row && a.elements[i].col < b.elements[j].col)) {
            result.elements[result.numValues++] = a.elements[i++];
        }
        else {
            result.elements[result.numValues++] = b.elements[j++];
        }
    }

    while (i < a.numValues) result.elements[result.numValues++] = a.elements[i++];
    while (j < b.numValues) result.elements[result.numValues++] = b.elements[j++];

    return result;
}

// Function to subtract two sparse matrices
struct sparsematrix SubtractMatrix(struct sparsematrix a, struct sparsematrix b) {
    struct sparsematrix result;
    result.numValues = 0;

    int i = 0, j = 0;
    while (i < a.numValues && j < b.numValues) {
        if (a.elements[i].row == b.elements[j].row &&
            a.elements[i].col == b.elements[j].col) {
            result.elements[result.numValues].row = a.elements[i].row;
            result.elements[result.numValues].col = a.elements[i].col;
            result.elements[result.numValues].value = a.elements[i].value - b.elements[j].value;
            result.numValues++;
            i++;
            j++;
        }
        else if (a.elements[i].row < b.elements[j].row ||
                (a.elements[i].row == b.elements[j].row && a.elements[i].col < b.elements[j].col)) {
            result.elements[result.numValues++] = a.elements[i++];
        }
        else {
            result.elements[result.numValues] = b.elements[j];
            result.elements[result.numValues].value = -b.elements[j].value; // subtract → negate b
            result.numValues++;
            j++;
        }
    }

    while (i < a.numValues) result.elements[result.numValues++] = a.elements[i++];
    while (j < b.numValues) {
        result.elements[result.numValues] = b.elements[j];
        result.elements[result.numValues].value = -b.elements[j].value;
        result.numValues++;
        j++;
    }

    return result;
}

int main() {
    struct sparsematrix m1, m2, result;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enter Matrix 1\n");
        printf("2. Enter Matrix 2\n");
        printf("3. Display Matrix 1\n");
        printf("4. Display Matrix 2\n");
        printf("5. Add Matrices\n");
        printf("6. Subtract Matrices (M1 - M2)\n");
        printf("7. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Matrix 1:\n");
                EnterMatrix(&m1);
                break;
            case 2:
                printf("Enter Matrix 2:\n");
                EnterMatrix(&m2);
                break;
            case 3:
                printf("Matrix 1:\n");
                DisplayMatrix(m1);
                break;
            case 4:
                printf("Matrix 2:\n");
                DisplayMatrix(m2);
                break;
            case 5:
                result = AddMatrix(m1, m2);
                printf("Result of Addition:\n");
                DisplayMatrix(result);
                break;
            case 6:
                result = SubtractMatrix(m1, m2);
                printf("Result of Subtraction (M1 - M2):\n");
                DisplayMatrix(result);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
