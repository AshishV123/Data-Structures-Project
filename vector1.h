#define VECTOR_INIT_CAPACITY 10

typedef struct vector {
    void **items;
    int capacity;
    int total;
} vector;

void vector_init(vector *);
int vector_total(vector *);
static void vector_resize(vector *, int);
void vector_add(vector *, void *);
void vector_set(vector *, int, void *);
void *vector_get(vector *, int);
void vector_delete(vector *, int);
int vector_free(vector *);
int h3()
{
    int i,op,data, j=0;
    vector v;
    vector_init(&v);
    system("cls");
    printf("### VECTORS ###\n");
    printf("Vector max capacity taken 10!!!!\n\n");
    int c[10];
    while(1){
            printf("\nPress:\n");
    printf("1.Push back\n2.Delete an element\n3.Set an element\n4.Get an element\n5.Resize\n6.Print entire vector\n7.free the vector\n8.To Exit to Main Menu\n");
    scanf("%d", &op);
    switch(op)
    {
    case 1:
             printf("Enter the number to add: ");
            scanf("%d", &c[j]);
            vector_add(&v, &c[j]);
            j++;
            break;
    case 2:
        printf("Enter the index: ");
        scanf("%d", &data);
        if(data>=vector_total(&v))
        {
            printf("\nIndex out of bound!!!\n\n");
            break;
        }
        vector_delete(&v, data);
        break;
    case 3:
        printf("Enter the index: ");
        scanf("%d", &data);
        if(data>=vector_total(&v))
        {
            printf("\nIndex out of bound!!!\n\n");
            break;
        }
        printf("Enter the number: ");
        scanf("%d", &c[j]);
        vector_set(&v, data, &c[j]);
        j++;
        break;
    case 4:
        printf("Enter the index: ");
        scanf("%d", &data);
        if(!(data<vector_total(&v)))
        {
            printf("\nIndex out of bound!!!\n\n");
            break;
        }
        printf("\n");
        printf("%d \n\n", *((int *) vector_get(&v, data)));
        break;
    case 5:
        printf("Enter size: ");
        scanf("%d", &data);
        vector_resize(&v, data);
        break;
    case 6:
        printf("\n");
        for (i = 0; i < vector_total(&v); i++)
        printf("%d ", *((int *) vector_get(&v, i)));
        printf("\n\n");
        break;
    case 7:
        op = vector_free(&v);
        if(op==1)
            vector_init(&v);
        else
            op=8;
        break;
    case 8:
        main();
        break;
    }
    if(op>=8)
        break;
    }

}
void vector_init(vector *v)
{
    v->capacity = VECTOR_INIT_CAPACITY;
    v->total = 0;
    v->items = malloc(sizeof(void *) * v->capacity);
}
int vector_total(vector *v)
{
    return v->total;
}
static void vector_resize(vector *v, int capacity)
{
    #ifdef DEBUG_ON
    printf("vector_resize: %d to %d\n", v->capacity, capacity);
    #endif

    void **items = realloc(v->items, sizeof(void *) * capacity);
    if (items) {
        v->items = items;
        v->capacity = capacity;
    }
}
void vector_add(vector *v, void *item)
{
    if (v->capacity == v->total)
        vector_resize(v, v->capacity * 2);
    v->items[v->total++] = item;
}

void vector_set(vector *v, int index, void *item)
{
    if (index >= 0 && index < v->total)
        v->items[index] = item;
}

void *vector_get(vector *v, int index)
{
    if (index >= 0 && index < v->total)
        return v->items[index];
    return NULL;
}

void vector_delete(vector *v, int index)
{
    int i;
    for (i = index; i < v->total - 1; i++) {
        v->items[i] = v->items[i + 1];
    }

    v->total--;

    if (v->total > 0 && v->total == v->capacity / 4)

        vector_resize(v, v->capacity / 2);

}

int vector_free(vector *v)
{
    int op;
    free(v->items);
    printf("\nWant to create another vector(1/0):  ");
    scanf("%d", &op);
    return op;
}


