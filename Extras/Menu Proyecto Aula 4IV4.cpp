/* #####################################################################
   ###############                                       ###############
   ###############  Desarrollado por Ortega Ortuño Eder  ###############
   ###############                                       ###############
   ###############          Menu de Proyecto Aula        ###############
   ###############                                       ###############
   ###############            4IV4 @ CECyT 3             ###############
   ###############                                       ###############
   ###############         Programacion Modular          ###############
   ###############                                       ###############
   ###############        http://blogsh32.com.ar/        ###############
   ###############                                       ###############
   ###############               By H@cK.32              ###############
   ###############                                       ###############
   ##################################################################### */

// Este programa corresponde al menu de Proyecto Aula - 4IV4

#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "hack32.h"
#define enter 13

int main(void)
{
      char n;
      int x=10,y=10;
      clrscr();
      textbackground(0);
      ipn();
      Sleep(600);
      voca3();
      Sleep(1000);
      marco();
      textcolor(10);
      Sleep(200);
      textbackground(0);
      gotoxy(10,11);
      printf("Altas");
      Sleep(200);
      gotoxy(10,12);
      textbackground(0);
      printf("Bajas");
      Sleep(200);
      gotoxy(10,13);
      textbackground(0);
      printf("Modificaciones");
      Sleep(200);
      textbackground(0);
      gotoxy(10,14);
      printf("Consultas");
      Sleep(200);
      gotoxy(10,15);
      textbackground(0);
      printf("Reportes");
      Sleep(200);
      gotoxy(10,16);
      textbackground(0);
      printf("Salir");
      Sleep(500);
      about();

      do
      {
             n = tolower(getch());
             switch(n)
             {
                      case 'w':
                           if(y<=16 && y>=12)
                           {
                                    y=y-1;
                                    menu(&x,&y);
                                    about();
                           }
                           else
                           {
                               Beep(9000,300);
                               if(y==12)
                               {
                                        y=9;
                                        menu(&x,&y);
                                        about();
                               }
                           }
                           break;

                      case 's':
                           if(y<=15 && y>=10)
                           {
                                    y=y+1;
                                    menu(&x,&y);
                                    about();
                           }
                           
                           else
                           {
                               y=16;
                               Beep(9000,300);
                               menu(&x,&y);
                               about();
                           }
                           break;

                      case enter:
                           if(y==11)
                           {
                                    daralta();
                           }
                           if(y==12)
                           {
                                    darbaja();
                           }
                           if(y==13)
                           {
                                    modificaciones();
                           }
                           if(y==14)
                           {
                                    consultas();
                           }
                           if(y==15)
                           {
                                    reportes();
                           }
                           if(y==16)
                           {
                                    salir();
                           }
                           break;
                      
             }  
      }
      while(n !='v');
}
