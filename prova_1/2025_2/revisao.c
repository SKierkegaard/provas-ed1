
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct {
    void **items;
    int maxItems, numItems;
    int first, last;
} Queue;

typedef struct {
    void **items;
    int maxItems;
    int top;
} Stack;

int *somaDiagonaisPrincipais(int *m1, int *m2, int n) {
    if (m1 == NULL || m2 == NULL || n <= 0) {
        return NULL;
    }

    int *m3 = (int *) malloc(sizeof(int) * n * n);
    if (m3 == NULL) {
        return NULL;
    }

    for (int i = 0; i < n * n; i++) {
        m3[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int idx = n * i + i;
        m3[idx] = m1[idx] + m2[idx];
    }

    return m3;
}

int incCirc(Queue *q, int k) {
    return (q->first + k) % q->maxItems;
}

int rotacionalFilaK(Queue *q, int k) {
    if (q == NULL) {
        return FALSE;
    }

    void **aux = (void **) malloc(sizeof(void *) * k);
    if (aux == NULL) {
        return FALSE;
    }

    for (int i = 0; i < k; i++) {
        aux[i] = q->items[incCirc(q, i)];
    }

    for (int i = 0; i < q->numItems - k; i++) {
        q->items[incCirc(q, i)] = q->items[incCirc(q, i + k)];
    }

    for (int i = 0; i < k; i++) {
        q->items[incCirc(q, q->numItems + i - k)] = aux[i];
    }

    free(aux);
    return TRUE;
}


int remOcurrStack(Stack *s, void *key, (*cmp)(void *, void *)) {
    if (s == NULL || cmp == NULL) {
        return FALSE;
    }

    int occur = 0;
    for (int i = 0; i <= s->top; i++) {
        if (cmp(key, s->items[i])) {
            for (int j = i; j < s->top; j++) {
                s->items[j] = s->items[j + 1];
            }

            occur++;
            s->top--;
            i--;
        }
    }

    return occur;
}


int verificaStrings(char *s1, int  n1, char *s2, int n2) {
    if (s1 == NULL || s2 == NULL || n1 != n2) {
        return FALSE;
    }

    Stack *s = stackCreate(n2);
    if (s == NULL) {
        return 0;
    }

    int k = 0;
    for (int i = 0; i <= n2 + 1; i++) {
        if (s2[i] == ' ' || s2[i] == '\0') {
            for (; k <= i; k++) {
                if (*(char *) stackRemove(s) != s1[k]) {
                    stackDestroy(s);
                    return FALSE;
                }
            } 

            if (s1[k] != s2[i]) {
                stackDestroy(s);
                return FALSE;
            }
            k++;
        } else {
            stackInsert(s, &s2[i]);
        }
    }

    stackDestroy(s);
    return TRUE;
}
