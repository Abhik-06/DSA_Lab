#include <stdio.h>

struct Term {
    int coeff;
    int exp;
};

struct Polynomial {
    int numTerms;
    struct Term terms[100];
};

void ReadPolynomial(struct Polynomial* p) {
    printf("Enter number of terms: ");
    scanf("%d", &p->numTerms);
    for (int i = 0; i < p->numTerms; i++) {
        printf("Enter coefficient for term %d: ", i + 1);
        scanf("%d", &p->terms[i].coeff);
        printf("Enter exponent for term %d: ", i + 1);
        scanf("%d", &p->terms[i].exp);
    }
}

void DisplayPolynomial(struct Polynomial* p) {
    for (int i = 0; i < p->numTerms; i++) {
        printf("%dx^%d", p->terms[i].coeff, p->terms[i].exp);
        if (i != p->numTerms - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

struct Polynomial AddPolynomials(struct Polynomial* p1, struct Polynomial* p2) {
    struct Polynomial result;
    result.numTerms = 0;

    int i = 0, j = 0;

    while (i < p1->numTerms && j < p2->numTerms) {
        if (p1->terms[i].exp > p2->terms[j].exp) {
            result.terms[result.numTerms++] = p1->terms[i++];
        } else if (p1->terms[i].exp < p2->terms[j].exp) {
            result.terms[result.numTerms++] = p2->terms[j++];
        } else {
            int sum = p1->terms[i].coeff + p2->terms[j].coeff;
            if (sum != 0) {
                result.terms[result.numTerms].coeff = sum;
                result.terms[result.numTerms].exp = p1->terms[i].exp;
                result.numTerms++;
            }
            i++;
            j++;
        }
    }

    while (i < p1->numTerms) {
        result.terms[result.numTerms++] = p1->terms[i++];
    }

    while (j < p2->numTerms) {
        result.terms[result.numTerms++] = p2->terms[j++];
    }

    return result;
}

int main() {
    struct Polynomial poly1, poly2, sum;

    printf("Enter first polynomial:\n");
    ReadPolynomial(&poly1);

    printf("Enter second polynomial:\n");
    ReadPolynomial(&poly2);

    printf("First polynomial: ");
    DisplayPolynomial(&poly1);

    printf("Second polynomial: ");
    DisplayPolynomial(&poly2);

    sum = AddPolynomials(&poly1, &poly2);

    printf("Sum polynomial: ");
    DisplayPolynomial(&sum);

    printf("Thank you dor using my program ! :)");
    return 0;
}
