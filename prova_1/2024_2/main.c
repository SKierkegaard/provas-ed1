#include <stdlib.h>
#define TRUE 1
#degine FALSE 0

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


int inverteElementosLinhaK(int *v, int n, int k) {
    if (v == NULL || n < 1 ||  k > n) {
        return FALSE;
    }
    
    Stack *s = stackCreate(n);
    if (s == NULL) {
        return FALSE;
    }
    for (int i = 0; i < n; i++) {
        stackPush(s, (void *) &v[n * i + (k - 1)]); 
    }

    for (int i = 0; i < n; i++) {
        v[n * i + (k - 1)] = *(int *) stackPop(s);
    }

    stackDestroy(s);
    return TRUE;
}

int incCirc(Queue *q, int k) {
    return (q->first + k) % q->maxItems;
}

void moveDoMeioProInicio(Queue *q) {
    if (q == NULL) {
        return;
    }

    int h = q->numItems / 2;
    void *item = q->items[incCirc(q, h)];

    for (int i = h; h > 0; i--) {
        q->items[incCirc(q, i)] = q->items[incCirc(q, i - 1)];
    }

    q->items[q->first] = item;
}

void removePares(Stack *s) {
    if (s == NULL) {
        return;
    }

    if  (s->top < 0) {
        return;
    }

    int w = 0;
    for (int i = s->top % 2; i <= s->top; i += 2) {
        s->items[w] = s->items[i];
        w++;
    }

    s->top = w - 1;
}
