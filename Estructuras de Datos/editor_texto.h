#define MAX 200
#define MAX_PER_PAL 30
#define XD -32767
#define ESC VK_ESCAPE
#define ARRIBA VK_UP
#define ABAJO VK_DOWN
#define IZQUIERDA VK_LEFT
#define DERECHA VK_RIGHT

// Pilas: letras
typedef struct nodoChar
{
    char info;
    struct nodoChar *next;
} NodoC;
typedef struct pilaChar
{
    NodoC *tope;
} PilaC;
void createChar(PilaC *p)
{
    p->tope = NULL;
}
NodoC* hacerNodoChar(char val)
{
    NodoC *n;
    n = (NodoC *) malloc(sizeof(NodoC));
    if(n == NULL)
    {
        printf("\tError: no se pudo asignar memoria\n");
    }
    else
    {
        n->info = val;
        n->next = NULL;
    }
    return n;
}
int isEmptyChar(PilaC *p)
{
    return p->tope == NULL;
}
void pushChar(PilaC *p, char dato)
{
    NodoC *n;
    n = hacerNodoChar(dato);
    n->next = p->tope;
    p->tope = n;
    n = NULL;
}
void popChar(PilaC *p, char *val)
{
    NodoC *aux;
    if(isEmptyChar(p))
    {
        printf("\tError: Pila vacia\n");
    }
    else
    {
        aux = p->tope;
        *val = aux->info;
        p->tope = aux->next;
    }
    free(aux);
}
void printStackChar(PilaC *pi)
{
    PilaC aux;
    char c;
    int x = 0;

    while(!isEmptyChar(pi))
    {
        popChar(pi, &c);
        pushChar(&aux, c);
        x++;
    }
    while(x != 0)
    {
        popChar(&aux, &c);
        printf("%c", c);
        pushChar(pi, c);
        x--;
    }
    printf("\n");
}

// Pilas: palabras
typedef struct nodoString
{
    char info[MAX_PER_PAL];
    struct nodoString *next;
} NodoS;
typedef struct pilaString
{
    NodoS *tope;
} PilaS;
void createString(PilaS *p)
{
    p->tope = NULL;
}
NodoS* hacerNodoString(char val[])
{
    NodoS *n;
    n = (NodoS *) malloc(sizeof(NodoS));
    if(n == NULL)
    {
        printf("\tError: no se pudo asignar memoria\n");
    }
    else
    {
        strcpy(n->info, val);
        n->next = NULL;
    }
    return n;
}
int isEmptyString(PilaS *p)
{
    return p->tope == NULL;
}
void pushString(PilaS *p, char dato[])
{
    NodoS *n;
    n = hacerNodoString(dato);
    n->next = p->tope;
    p->tope = n;
    n = NULL;
}
void popString(PilaS *p, char val[])
{
    NodoS *aux;
    if(isEmptyString(p))
    {
        printf("\tError: Pila vacia\n");
    }
    else
    {
        aux = p->tope;
        strcpy(val, aux->info);
        p->tope = aux->next;
    }
    free(aux);
}
void printStackString(PilaS *pi)
{
    PilaS aux;
    char c[MAX_PER_PAL];
    int x = 0;

    while(!isEmptyString(pi))
    {
        popString(pi, c);
        pushString(&aux, c);
        x++;
    }
    while(x != 0)
    {
        popString(&aux, c);
        puts(c);
        pushString(pi, c);
        x--;
    }
    printf("\n");
}

// Editor
void separarLetras(PilaC *p, char c[])
{
    int x;
    for(x = 0; x < strlen(c); x++)
        pushChar(p, c[x]);
}
void separarPalabras(PilaS *p, char c[])
{
    char cadena[MAX_PER_PAL], *tok = NULL;
    tok = strtok(c, " ");
    while(tok != NULL)
    {
        pushString(p, tok);
        tok = strtok(NULL, " ");
    }
}
void retrocederLetra(PilaC *l, PilaC *l_aux)
{
    char c;
    if(!isEmptyChar(l))
    {
        system("cls");
        Beep(10000, 50);
        popChar(l, &c);
        pushChar(l_aux, c);
        printStackChar(l);
    }
}
void avanzarLetra(PilaC *l, PilaC *l_aux)
{
    char c;
    if(!isEmptyChar(l_aux))
    {
        system("cls");
        Beep(10000, 50);
        popChar(l_aux, &c);
        pushChar(l, c);
        printStackChar(l);
    }
}
void retrocederPalabra(PilaS *p, PilaS *p_aux)
{
    char c[MAX_PER_PAL];
    if(!isEmptyString(p))
    {
        system("cls");
        Beep(5000, 50);
        popString(p, c);
        pushString(p_aux, c);
        printStackString(p);
    }
}
void avanzarPalabra(PilaS *p, PilaS *p_aux)
{
    char c[MAX_PER_PAL];
    if(!isEmptyString(p_aux))
    {
        system("cls");
        Beep(5000, 50);
        popString(p_aux, c);
        pushString(p, c);
        printStackString(p);
    }
}
