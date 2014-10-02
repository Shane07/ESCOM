#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "editor_texto.h"
int main()
{
    char st[MAX];
    PilaC letras, letras_aux;
    PilaS palabras, palabras_aux;
    createChar(&letras);
    createChar(&letras_aux);
    createString(&palabras);
    createString(&palabras_aux);
    printf("Introduce la cadena: ");
    gets(st);
    system("cls");
    puts(st);
    separarLetras(&letras, st);
    separarPalabras(&palabras, st);
    while(GetAsyncKeyState(ESC) != XD)
    {
        if(GetAsyncKeyState(ABAJO) == XD)
            retrocederLetra(&letras, &letras_aux);
        else if(GetAsyncKeyState(ARRIBA) == XD)
            avanzarLetra(&letras, &letras_aux);
        else if(GetAsyncKeyState(IZQUIERDA) == XD)
            retrocederPalabra(&palabras, &palabras_aux);
        else if(GetAsyncKeyState(DERECHA) == XD)
            avanzarPalabra(&palabras, &palabras_aux);
        else
            continue;
    }
    system("cls");
    Beep(4000, 800);
    return 0;
}
