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
    int numItems;
    int first, last;
} Queue;

int inverterOrdemElementosLinhaK(int *v, int n, int m, int l) {
    if (v == NULL || n <= 0 || m <= 0 || l < 1 || l > n) {
        return FALSE;
    }

    Stack *s = stackCreate(m);
    if (s == NULL) {
        return FALSE;
    }

    for (int i = 0; i < m; i++) {
        stackPush(s, (void *) &v[m * (l - 1) + i]);   
    }

    for (int i = 0; i < m; i++) {
        v[m * (l - 1) + i] = *(int *) stackPop(s);
    }

    return TRUE;
}

int incCirc(Queue *q, int k) {
    return (q->first + k) % q->maxItems;
}

void punePrimeiro(Queue *q) {
    if (q == NULL) {
        return;
    }

    void *item = q->items[q->first];
    int h = q->numItems / 2;
    for (int i = 0; i < h; i++) {
        q->items[incCirc(q, i)] = q->items[incCirc(q, i + 1)]
    }

    q->items[incCirc(q, h)] = item;
}

void removePares(Stack *s) {
    if (s == NULL)  {
        return;
    }

   int w = 0;
    for (int r = s->top % 2; r <= s->top; r += 2) {
        s->items[w] = s->items[r];
        w++;
    }

    s->top = w - 1;
}

char *converteString(char *str, int n) {
    if (str == NULL || n < 1) {
        return NULL;
    }

    char *aux = (char *) malloc(sizeof(char) * (n + 1));
    if (aux == NULL) {
        return NULL;
    }

    Stack *s = stackCreate(n);
    if (s == NULL) {
        free(aux);
        return NULL;
    }

    int idx = 0;
    int word = 0;
    for (int i == n - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            for (int j = 0; j < word; j++) {
                aux[idx] = *(char *) stackPop(s);
                idx++;
            }
            aux[idx] = ' ';
            idx++;
            word = 0;
    
        } else {
            stackPush(s, (void *) &str[i]);
            word++;
        }
    }

    for (int i = 0; i < word; i++) {
        aux[idx] = *(char *) stackPop(s);
        idx++;
    }

    aux[idx] = '\0';

    stackDestroy(s);
    return aux;
}
