#include <stdio.h>
#include <stdlib.h>
#define COMPARE(x, y) (x <= y? (x == y? 0 : -1) : 1)
#define MAX_TERMS 100
// a + bx + cx^2 + dx^3 +...

// void addPolynomials(TERM*, int, int, int, int, int*, int*);
// void printPolynomial(TERM*, int, int);
// void insert(TERM* terms, int avail, float coeff, int exp);
typedef struct {
    int exp;
    float coeff;
} TERM;

void printPolynomial(TERM* terms, int start, int finish) {
    for(int i = start; i <= finish; i++) {
        TERM term = terms[i];
        if(term.exp == 0) {
            printf("%.2f", term.coeff);
        }
        else if(term.exp == 1) {
            printf("%.2fx", term.coeff);
        }
        else printf("%.2fx^%d", term.coeff, term.exp);
        printf(i < finish? " + ":" ");
    }
}

void insert(TERM *terms, int avail, float coeff, int exp) {
    if(avail >= MAX_TERMS) {
        printf("Polynomials are too big.");
        exit(1);
    }
    terms[avail].coeff = coeff;
    terms[avail].exp = exp;
}

void addPolynomials(TERM* terms, int starta, int finisha, int startb, int finishb, int *startd, int *finishd) {
    int avail = finishb + 1;
    int i = starta, j = startb;
    *startd = avail;
    while(i <= finisha && j <= finishb) {
        switch(COMPARE(terms[i].exp, terms[j].exp)) {
            case 0: 
                insert(terms, avail, terms[i].coeff + terms[j].coeff, terms[i].exp);
                i++; j++;
                avail++;
                break;
            case -1:
                insert(terms, avail, terms[j].coeff, terms[j].exp);
                j++;
                avail++;
                break;
            case 1:
                insert(terms, avail, terms[i].coeff, terms[i].exp);
                i++;
                avail++;
                break;
        }
    }
    while(i <= finisha) {
        insert(terms, avail, terms[i].coeff, terms[i].exp);
        avail++;
        i++;
    }

    while(j <= finishb) {
        insert(terms, avail, terms[j].coeff, terms[j].exp);
        avail++;
        j++;
    }

    *finishd = avail - 1;
    return;
} 


int main() {
    TERM terms[100] = { // 3x^2 + 2x - 1, 16x^4 + 8x^3 + 4x^2 + 2x
        {2, 3},
        {1, 2},
        {0, -1},
        {4, 16},
        {3, 8},
        {2, 4},
        {1, 2}
    };
    int starta = 0, finisha = 2, startb = 3, finishb = 6;
    int startd, finishd;

    addPolynomials(terms, starta, finisha, startb, finishb, &startd, &finishd);

    printPolynomial(terms, starta, finisha);
    printf("\n");
    printPolynomial(terms, startb, finishb);
    printf("\n----------------------------------------------\n");
    printPolynomial(terms, startd, finishd);
    return 0;
}

