typedef int ArbolEntry;
typedef struct nodo
{
    ArbolEntry info;
    struct nodo *izquierda;
    struct nodo *derecha;
} NodoArbol;
typedef NodoArbol *Arbol;


void crearArbol(NodoArbol **root) // Alt: crearArbol(Arbol *)
{
    *root = NULL;
}
NodoArbol *crearNodoArbol(ArbolEntry valor)
{
    NodoArbol *nuevo = (NodoArbol *) malloc(sizeof(NodoArbol));
    if(nuevo == NULL)
    {
        printf("No hay memoria disponible");
        exit(-1);
    }
    nuevo->izquierda = nuevo->derecha = NULL;
    nuevo->info = valor;
    return nuevo;
}
void agregarNodo(NodoArbol **root, ArbolEntry val)
{
    NodoArbol *nuevonodo;
    if(*root == NULL)
    {
        nuevonodo = crearNodoArbol(val);
        *root = nuevonodo;
        nuevonodo = NULL;
        return;
    }
    if(val < (*root)->info)
        agregarNodo(&((*root)->izquierda), val);
    else if(val > (*root)->info)
        agregarNodo(&((*root)->derecha), val);
    else
        printf("\tValor duplicado\n");
}
void imprimirInOrder(NodoArbol *root)
{
    if(root)
    {
        imprimirInOrder(root->izquierda);
        printf("%d\n", root->info);
        imprimirInOrder(root->derecha);
    }
}
void imprimirPreOrder(NodoArbol *root)
{
    if(root)
    {
        printf("%d\n", root->info);
        imprimirInOrder(root->izquierda);
        imprimirInOrder(root->derecha);
    }
}
void imprimirPostOrder(NodoArbol *root)
{
    if(root)
    {
        imprimirInOrder(root->izquierda);
        imprimirInOrder(root->derecha);
        printf("%d\n", root->info);
    }
}
int numNodos(NodoArbol *root)
{
    int nodos = 0, i = 0, d = 0;
    if(root)
    {
        nodos = 1;
        i = numNodos(root->izquierda);
        d = numNodos(root->derecha);
    }
    return nodos + i + d;
}
int numHojas(NodoArbol *root)
{
    int hojas = 0, i = 0, d = 0;
    if(root)
    {
        if(root->izquierda == NULL && root->derecha == NULL)
            hojas = 1;
        i = numHojas(root->izquierda);
        d = numHojas(root->derecha);
    }
    return hojas + i + d;
}
void copiarArbol(NodoArbol *origen, NodoArbol **destino)
{
    if(origen)
    {
        agregarNodo(destino, origen->info);
        copiarArbol(origen->izquierda, &((*destino)->izquierda));
        copiarArbol(origen->derecha, &((*destino)->derecha));
    }
}
int buscarValor(NodoArbol *root, ArbolEntry v)
{
    if(root)
    {
        if(root->info == v)
            return 1;
        else
        {
            if(buscarValor(root->izquierda, v) == 1)
                return 1;
            if(buscarValor(root->derecha, v) == 1)
                return 1;
        }
    }
    return 0;
}
int compararArboles(NodoArbol *a, NodoArbol *b)
{
    if(!a && !b) // Comparación de punteros: 0 = NULL
        return 1;
    else if(!a || !b)
        return 0;
    else if(a && b)
    {
        if(a->info == b->info)
        {
            if(!compararArboles(a->izquierda, b->izquierda) || !compararArboles(a->derecha, b->derecha))
                return 0;
            else
                return 1;
        }
        else
            return 0;
    }
    return 1;
}
int getAlturaArbol(NodoArbol *root)
{
    int a = 0, i = 0, d = 0;
    if(root)
    {
        a = 1;
        i = a + getAlturaArbol(root->izquierda);
        d = a + getAlturaArbol(root->derecha);
        if(i > d)
            return i;
        else if(i < d)
            return d;
        else
            return i;
    }
    return a;
}
int alturaArbol(NodoArbol *r)
{
    return getAlturaArbol(r) - 1;
}
void imprimirPerLvl(NodoArbol *root)
{
    if(root)
    {
        if(root->izquierda)
            printf("%d\n", root->izquierda->info);
        if(root->derecha)
            printf("%d\n", root->derecha->info);
        imprimirPerLvl(root->izquierda);
        imprimirPerLvl(root->derecha);
    }
}
void imprimirPorNivel(NodoArbol *r)
{
    if(r)
    {
        printf("%d\n", r->info);
        imprimirPerLvl(r);
    }
}
int numNodosInteriores(NodoArbol *root)
{
    int nodosint = 0, i = 0, d = 0;
    if(root)
    {
        if(root->izquierda != NULL || root->derecha != NULL)
            nodosint = 1;
        i = numNodosInteriores(root->izquierda);
        d = numNodosInteriores(root->derecha);
    }
    return nodosint + i + d;
}
void mirrorArbol(NodoArbol *origen, NodoArbol **destino)
{
    if(origen)
    {
        agregarNodo(destino, origen->info);
        mirrorArbol(origen->izquierda, &((*destino)->derecha));
        mirrorArbol(origen->derecha, &((*destino)->izquierda));
    }
}
void reemplazarNodo(NodoArbol **r, NodoArbol **aux)
{
    if((*r)->derecha == NULL)
    {
        (*aux)->info = (*r)->info;
        *aux = *r;
        *r = (*r)->izquierda;
    }
    else
        reemplazarNodo(&(*r)->derecha, aux);
}
void borrarNodo(NodoArbol **root, ArbolEntry v)
{
    NodoArbol *aux;
    if(*root == NULL)
        return;
    if((*root)->info < v)
        borrarNodo(&(*root)->derecha, v);
    else if((*root)->info > v)
        borrarNodo(&(*root)->izquierda, v);
    else if((*root)->info == v)
    {
        aux = *root;
        if((*root)->izquierda == NULL)
            *root = (*root)->derecha;
        else if((*root)->derecha == NULL)
            *root = (*root)->izquierda;
        else
            reemplazarNodo(&(*root)->izquierda, &aux);
        free(aux);
    }
}
