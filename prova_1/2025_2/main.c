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
    if (m1 != NULL && m2 != NULL && n > 0) {
        int *md = (int *) malloc(sizeof(int) * n * n); 
        if (md != NULL) {
            for (int i = 0; i < n * n; i++) {
                md[i] = 0;
            }

            for (int i = 0; i < n; i++) {
                int pos = i * n + i;
                md[pos] = m1[pos] + m2[pos];
            }

            return md;
        }
    } 

    return NULL;
}

int rotacionalFilaK(Queue *q, int k) {
    if (q != NULL) {
        void **aux = (void **) malloc(sizeof(void *) * k);
        if (aux != NULL) {
            for (int i = 0; i < k; i++) {
                aux[i] = q->items[(q->first + i) % q->maxItems];
            }

            for (int i = 0; i < q->numItems - k; i++) {
                q->items[(q->first + i) % q->maxItems] = q->items[(q->first + i + k) % q->maxItems];
            }

            for (int i = 0; i < k; i++) {
                q->items[(q->first + q->numItems + i - k) % q->maxItems] = aux[i];
            }

            free(aux);
            return TRUE;
        }
    }

    return FALSE;
}

int remOcurrStack(Stack *s, void *key, (*cmp)(*void, *void)) {
    if (s != NULL) {
        int w = 0;
        for (int i = 0; i <= s->top; i++) {
            if (!cmp(key, s->items[i])) {
                s->items[w] = s->items[i];
                w++
            }
        }

        return s->top - w;
    }

    return FALSE;
}

int main() {
    return 0;
}
