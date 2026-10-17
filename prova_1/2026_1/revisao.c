#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct {
    void **items;
    int maxItems;
    int top;
} Stack;

typedef struct {
    void **items;
    int maxItems;
    int nItems;
    int first;
    int last;
} Queue;

int subtraiAPorTransposta(int n, int m, int *va, int *vb, int *vc) {
    if (n != m) {
        return FALSE;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vc[i * m + j] = va[i * m + j] - vb[j * m + i];
        }
    }

    return TRUE;
}

char *inverterPalavrasNasPosImpares(char *s, int n) {
    char *res = (char *) malloc(sizeof(char) * (n + 1));
    if (res == NULL) {
        return NULL;
    }
    Stack *pilha = stkCreate(n);

    int i = 0;
    int k = 0;
    int pos = 1;
    while (s[i] != '\0') {
        if (s[i] = ' ') {
            res[k] = s[i];
            i++;
            k++;
        } else {
            int inicio = i;
            while (i < n && [i] != ' ') {
                i++;
            }

            if (pos % 2 == 1) {
                for (int j = inicio; j < i; j++) {
                    stkPush(pilha, (void *) &s[j]);
                }
                
                while (stkTop(pilha) >= 0) {
                    s[k] = *(char *) stkPop(pilha);
                    k++;
                }
            } else {
                for (int j = inicio; j < i; j++) {
                    res[k] = s[j];
                    k++;
                }
            }
        }

        pos++;
    }

    res[k] = '\0';
    stkDestroy(pilha);
    return res;
}


int moveNEsimoParaFundo(Stack *s, int n) {
    if (n - 1 > s->top) {
        return FALSE;
    }

    int idx = s->top - n + 1;
    void *item = s->items[idx];
    for (int i = idx; i > 0; i--) {
        s->items[i] = s->items[i - 1];
    }

    s->items[0] = item;
    return TRUE;
}

int incCircular(Queue *q, int k) {
    return (q->first + q->maxItems + k - 1) % q->maxItems;
}

int moveKEsimoParaUltimo(Queue *q, int k) {
    if (q == NULL) {
        return FALSE;
    }
    
    if (k > q->nItems || k < 1) {
        return FALSE;
    }

    void *item = q->items[incCircular(q, k)];
    for (int i = k; i < q->nItems; i++) {
        q->items[incCircular(q, i)] = q->items[incCircular(q, i + 1)];
    }

    q->items[q->last] = item;
    return TRUE;
}
