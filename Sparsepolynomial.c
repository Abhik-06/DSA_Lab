#include<stdio.h>
#include<stdlib.h>

#define MAX_TERMS 100
#define MAX_POLYS 10

struct term {
    int exp;
    int coeff;
};

struct polynomial {
    int total;
    struct term terms[MAX_TERMS];
};

// Function prototypes
int Choice();
void CreatePolynomial(struct polynomial *sparsehome, int *count);
void AddPolynomials(struct polynomial *sparsehome, int *count);
void SubtractPolynomials(struct polynomial *sparsehome, int *count);
void MultiplyPolynomials(struct polynomial *sparsehome, int *count);
void DisplayPolynomial(struct polynomial sparsehome[], int count);
void DeletePolynomial(struct polynomial *sparsehome, int *count);
void SortPolynomial(struct polynomial *poly);
void SimplifyPolynomial(struct polynomial *poly);

int main() {
    int choice = 1;
    struct polynomial sparsehome[MAX_POLYS];
    int count = 0;

    printf("=== Sparse Polynomial Calculator ===\n\n");

    while (choice == 1) {
        printf("\n--- Menu ---\n");
        printf("1. Create a sparse polynomial\n");
        printf("2. Add two polynomials\n");
        printf("3. Subtract two polynomials\n");
        printf("4. Multiply two polynomials\n");
        printf("5. Display a polynomial\n");
        printf("6. Delete a polynomial\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count >= MAX_POLYS) {
                    printf("Maximum polynomial limit reached! Remove polynomials to continue.\n");
                    printf("Would you like to delete a polynomial now? (1 for yes, 0 for no): ");
                    int deleteChoice;
                    scanf("%d", &deleteChoice);
                    if (deleteChoice == 1) {
                        DeletePolynomial(sparsehome, &count);
                    }
                } else {
                    CreatePolynomial(sparsehome, &count);
                }
                break;
            case 2:
                if (count < 2) {
                    printf("Need at least 2 polynomials for addition!\n");
                } else {
                    AddPolynomials(sparsehome, &count);
                }
                break;
            case 3:
                if (count < 2) {
                    printf("Need at least 2 polynomials for subtraction!\n");
                } else {
                    SubtractPolynomials(sparsehome, &count);
                }
                break;
            case 4:
                if (count < 2) {
                    printf("Need at least 2 polynomials for multiplication!\n");
                } else {
                    MultiplyPolynomials(sparsehome, &count);
                }
                break;
            case 5:
                if (count == 0) {
                    printf("No polynomials available to display!\n");
                } else {
                    DisplayPolynomial(sparsehome, count);
                }
                break;
            case 6:
                if (count == 0) {
                    printf("No polynomials available to delete!\n");
                } else {
                    DeletePolynomial(sparsehome, &count);
                }
                break;
            default:
                printf("Invalid choice!\n");
                choice = 0; // Exit the loop
                break;
        }

        if (choice >= 1 && choice <= 6) {
            choice = Choice();
        }
    }
    
    printf("Thank you for using the Sparse Polynomial Calculator! :)\n");
    return 0;
}

int Choice() {
    int choice;
    printf("\nDo you wish to continue? (1 for yes, 0 for no): ");
    scanf("%d", &choice);
    return choice;
}

void CreatePolynomial(struct polynomial *sparsehome, int *count) {
    int total;
    printf("\nEnter the number of terms in the new polynomial: ");
    scanf("%d", &total);

    if (total > MAX_TERMS) {
        printf("Too many terms! Maximum allowed is %d\n", MAX_TERMS);
        return;
    }

    sparsehome[*count].total = total;

    printf("Enter terms in descending order of exponents:\n");
    for (int i = 0; i < total; i++) {
        printf("Term %d - Coefficient: ", i + 1);
        scanf("%d", &sparsehome[*count].terms[i].coeff);
        printf("Term %d - Exponent: ", i + 1);
        scanf("%d", &sparsehome[*count].terms[i].exp);
    }

    // Sort and simplify the polynomial
    SortPolynomial(&sparsehome[*count]);
    SimplifyPolynomial(&sparsehome[*count]);
    
    printf("Polynomial %d created successfully!\n", *count);
    (*count)++;
}

void AddPolynomials(struct polynomial *sparsehome, int *count) {
    int poly1, poly2;
    
    printf("\nAvailable polynomials (0 to %d):\n", *count - 1);
    for (int i = 0; i < *count; i++) {
        printf("Polynomial %d: ", i);
        for (int j = 0; j < sparsehome[i].total; j++) {
            if (j > 0 && sparsehome[i].terms[j].coeff > 0) printf(" + ");
            else if (sparsehome[i].terms[j].coeff < 0) printf(" ");
            printf("%dx^%d", sparsehome[i].terms[j].coeff, sparsehome[i].terms[j].exp);
        }
        printf("\n");
    }
    
    printf("Enter the first polynomial index: ");
    scanf("%d", &poly1);
    printf("Enter the second polynomial index: ");
    scanf("%d", &poly2);

    if (poly1 < 0 || poly1 >= *count || poly2 < 0 || poly2 >= *count) {
        printf("Invalid polynomial indices!\n");
        return;
    }

    if (*count >= MAX_POLYS) {
        printf("Cannot store result. Maximum polynomial limit reached!\n");
        return;
    }

    struct polynomial *result = &sparsehome[*count];
    int i = 0, j = 0, k = 0;

    while (i < sparsehome[poly1].total && j < sparsehome[poly2].total) {
        if (sparsehome[poly1].terms[i].exp > sparsehome[poly2].terms[j].exp) {
            result->terms[k] = sparsehome[poly1].terms[i];
            i++;
        } else if (sparsehome[poly1].terms[i].exp < sparsehome[poly2].terms[j].exp) {
            result->terms[k] = sparsehome[poly2].terms[j];
            j++;
        } else {
            result->terms[k].exp = sparsehome[poly1].terms[i].exp;
            result->terms[k].coeff = sparsehome[poly1].terms[i].coeff + sparsehome[poly2].terms[j].coeff;
            i++;
            j++;
        }
        if (result->terms[k].coeff != 0) k++;
    }

    while (i < sparsehome[poly1].total) {
        result->terms[k++] = sparsehome[poly1].terms[i++];
    }

    while (j < sparsehome[poly2].total) {
        result->terms[k++] = sparsehome[poly2].terms[j++];
    }

    result->total = k;
    printf("Addition result stored as polynomial %d\n", *count);
    (*count)++;
}

void SubtractPolynomials(struct polynomial *sparsehome, int *count) {
    int poly1, poly2;
    
    printf("\nAvailable polynomials (0 to %d):\n", *count - 1);
    for (int i = 0; i < *count; i++) {
        printf("Polynomial %d: ", i);
        for (int j = 0; j < sparsehome[i].total; j++) {
            if (j > 0 && sparsehome[i].terms[j].coeff > 0) printf(" + ");
            else if (sparsehome[i].terms[j].coeff < 0) printf(" ");
            printf("%dx^%d", sparsehome[i].terms[j].coeff, sparsehome[i].terms[j].exp);
        }
        printf("\n");
    }
    
    printf("Enter the first polynomial index: ");
    scanf("%d", &poly1);
    printf("Enter the second polynomial index: ");
    scanf("%d", &poly2);

    if (poly1 < 0 || poly1 >= *count || poly2 < 0 || poly2 >= *count) {
        printf("Invalid polynomial indices!\n");
        return;
    }

    if (*count >= MAX_POLYS) {
        printf("Cannot store result. Maximum polynomial limit reached!\n");
        return;
    }

    struct polynomial *result = &sparsehome[*count];
    int i = 0, j = 0, k = 0;

    while (i < sparsehome[poly1].total && j < sparsehome[poly2].total) {
        if (sparsehome[poly1].terms[i].exp > sparsehome[poly2].terms[j].exp) {
            result->terms[k] = sparsehome[poly1].terms[i];
            i++;
        } else if (sparsehome[poly1].terms[i].exp < sparsehome[poly2].terms[j].exp) {
            result->terms[k].exp = sparsehome[poly2].terms[j].exp;
            result->terms[k].coeff = -sparsehome[poly2].terms[j].coeff;
            j++;
        } else {
            result->terms[k].exp = sparsehome[poly1].terms[i].exp;
            result->terms[k].coeff = sparsehome[poly1].terms[i].coeff - sparsehome[poly2].terms[j].coeff;
            i++;
            j++;
        }
        if (result->terms[k].coeff != 0) k++;
    }

    while (i < sparsehome[poly1].total) {
        result->terms[k++] = sparsehome[poly1].terms[i++];
    }

    while (j < sparsehome[poly2].total) {
        result->terms[k].exp = sparsehome[poly2].terms[j].exp;
        result->terms[k].coeff = -sparsehome[poly2].terms[j].coeff;
        j++;
        k++;
    }

    result->total = k;
    printf("Subtraction result stored as polynomial %d\n", *count);
    (*count)++;
}

void MultiplyPolynomials(struct polynomial *sparsehome, int *count) {
    int poly1, poly2;
    
    printf("\nAvailable polynomials (0 to %d):\n", *count - 1);
    for (int i = 0; i < *count; i++) {
        printf("Polynomial %d: ", i);
        for (int j = 0; j < sparsehome[i].total; j++) {
            if (j > 0 && sparsehome[i].terms[j].coeff > 0) printf(" + ");
            else if (sparsehome[i].terms[j].coeff < 0) printf(" ");
            printf("%dx^%d", sparsehome[i].terms[j].coeff, sparsehome[i].terms[j].exp);
        }
        printf("\n");
    }
    
    printf("Enter the first polynomial index: ");
    scanf("%d", &poly1);
    printf("Enter the second polynomial index: ");
    scanf("%d", &poly2);

    if (poly1 < 0 || poly1 >= *count || poly2 < 0 || poly2 >= *count) {
        printf("Invalid polynomial indices!\n");
        return;
    }

    if (*count >= MAX_POLYS) {
        printf("Cannot store result. Maximum polynomial limit reached!\n");
        return;
    }

    struct polynomial *result = &sparsehome[*count];
    int k = 0;

    // Multiply each term of first polynomial with each term of second polynomial
    for (int i = 0; i < sparsehome[poly1].total; i++) {
        for (int j = 0; j < sparsehome[poly2].total; j++) {
            result->terms[k].exp = sparsehome[poly1].terms[i].exp + sparsehome[poly2].terms[j].exp;
            result->terms[k].coeff = sparsehome[poly1].terms[i].coeff * sparsehome[poly2].terms[j].coeff;
            k++;
        }
    }

    result->total = k;
    
    // Sort and simplify the result
    SortPolynomial(result);
    SimplifyPolynomial(result);
    
    printf("Multiplication result stored as polynomial %d\n", *count);
    (*count)++;
}

void DisplayPolynomial(struct polynomial sparsehome[], int count) {
    int index;
    printf("\nEnter the index of the polynomial to display (0 to %d): ", count - 1);
    scanf("%d", &index);

    if (index < 0 || index >= count) {
        printf("Invalid polynomial index!\n");
        return;
    }

    printf("Polynomial %d: ", index);
    if (sparsehome[index].total == 0) {
        printf("0");
    } else {
        for (int i = 0; i < sparsehome[index].total; i++) {
            if (i > 0) {
                if (sparsehome[index].terms[i].coeff > 0) {
                    printf(" + ");
                } else {
                    printf(" ");
                }
            }
            if (sparsehome[index].terms[i].exp == 0) {
                printf("%d", sparsehome[index].terms[i].coeff);
            } else if (sparsehome[index].terms[i].exp == 1) {
                if (sparsehome[index].terms[i].coeff == 1) {
                    printf("x");
                } else if (sparsehome[index].terms[i].coeff == -1) {
                    printf("-x");
                } else {
                    printf("%dx", sparsehome[index].terms[i].coeff);
                }
            } else {
                if (sparsehome[index].terms[i].coeff == 1) {
                    printf("x^%d", sparsehome[index].terms[i].exp);
                } else if (sparsehome[index].terms[i].coeff == -1) {
                    printf("-x^%d", sparsehome[index].terms[i].exp);
                } else {
                    printf("%dx^%d", sparsehome[index].terms[i].coeff, sparsehome[index].terms[i].exp);
                }
            }
        }
    }
    printf("\n");
}

void DeletePolynomial(struct polynomial *sparsehome, int *count) {
    if (*count == 0) {
        printf("No polynomials to delete!\n");
        return;
    }

    int index;
    printf("\nEnter the index of the polynomial to delete (0 to %d): ", *count - 1);
    scanf("%d", &index);

    if (index < 0 || index >= *count) {
        printf("Invalid polynomial index!\n");
        return;
    }

    // Shift all polynomials after the deleted one
    for (int i = index; i < *count - 1; i++) {
        sparsehome[i] = sparsehome[i + 1];
    }
    
    (*count)--;
    printf("Polynomial deleted successfully!\n");
}

void SortPolynomial(struct polynomial *poly) {
    // Sort terms by exponent in descending order (bubble sort)
    for (int i = 0; i < poly->total - 1; i++) {
        for (int j = 0; j < poly->total - i - 1; j++) {
            if (poly->terms[j].exp < poly->terms[j + 1].exp) {
                struct term temp = poly->terms[j];
                poly->terms[j] = poly->terms[j + 1];
                poly->terms[j + 1] = temp;
            }
        }
    }
}

void SimplifyPolynomial(struct polynomial *poly) {
    if (poly->total <= 1) return;
    
    int writeIndex = 0;
    
    for (int readIndex = 0; readIndex < poly->total; readIndex++) {
        if (poly->terms[readIndex].coeff == 0) continue;
        
        // Check if this exponent already exists in the simplified part
        int found = 0;
        for (int i = 0; i < writeIndex; i++) {
            if (poly->terms[i].exp == poly->terms[readIndex].exp) {
                poly->terms[i].coeff += poly->terms[readIndex].coeff;
                found = 1;
                break;
            }
        }
        
        if (!found) {
            poly->terms[writeIndex] = poly->terms[readIndex];
            writeIndex++;
        }
    }
    
    // Remove terms with zero coefficient
    int finalIndex = 0;
    for (int i = 0; i < writeIndex; i++) {
        if (poly->terms[i].coeff != 0) {
            poly->terms[finalIndex] = poly->terms[i];
            finalIndex++;
        }
    }
    
    poly->total = finalIndex;
}