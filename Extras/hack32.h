/* #####################################################################
   ###############                                       ###############
   ###############  Desarrollado por Ortega Ortuño Eder  ###############
   ###############                                       ###############
   ###############            Header "hack32.h"          ###############
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

// Esta libreria contiene absolutamente todas las funciones utilizadas en el Menu de Proyecto Aula 4IV4 @ CECyT 3

// ***** Prototipos de las funciones *****

int main(void);

void menu(int *, int *);
void daralta(void);
void darbaja(void);
void modificaciones(void);
void consultas(void);
void reportes(void);
void salir(void);

void marco(void);
void ipn(void);
void voca3(void);
void about(void);

void progreso_altas(void);
void progreso_bajas(void);
void progreso_modif(void);
void progreso_consultas(void);
void progreso_reportes(void);

// ***** Estructuras utilizadas *****

struct datos1
{
       char nombre[50];
       char paterno[50];
       char materno[50];
};

struct datos2
{
       char direccion[70];
       char telefono[15];
       char postal[15];
};

struct datos3
{
       char colonia[60];
       char sexo[10];
       char ocupacion[50];
};

// ***** Funciones *****

void menu(int *x, int *y)
{
     clrscr();
     textbackground(0);
     gotoxy(*x,*y);
     printf("               ");
     if(*y==11)
     {
               clrscr();
               voca3();
               about();
               marco();
               textbackground(9);
               gotoxy(*x,*y);
               printf("Altas");
               textbackground(0);
               gotoxy(40,12);
               textcolor(7);
               printf("Permite registrarse en el sistema");
               textcolor(10);
               gotoxy(*x,*y+1);
               textbackground(0);
               printf("Bajas");
               gotoxy(*x,*y+2);
               textbackground(0);
               printf("Modificaciones");
               textbackground(0);
               gotoxy(*x,*y+3);
               printf("Consultas");
               gotoxy(*x,*y+4);
               textbackground(0);
               printf("Reportes");
               gotoxy(*x,*y+5);
               textbackground(0);
               printf("Salir");
               ipn();
     }
     if(*y==12)
     {
               clrscr();
               voca3();
               about();
               marco();
               textbackground(0);
               gotoxy(40,12);
               textcolor(7);
               printf("Permite suprimirse del sistema");
               textcolor(10);
               gotoxy(*x,*y-1);
               printf("Altas");
               gotoxy(*x,*y);
               textbackground(9);
               printf("Bajas");
               gotoxy(*x,*y+1);
               textbackground(0);
               printf("Modificaciones");
               textbackground(0);
               gotoxy(*x,*y+2);
               printf("Consultas");
               gotoxy(*x,*y+3);
               textbackground(0);
               printf("Reportes");
               gotoxy(*x,*y+4);
               textbackground(0);
               printf("Salir");
               ipn();
     }
     if(*y==13)
     {
               clrscr();
               voca3();
               about();
               marco();
               textbackground(0);
               gotoxy(40,12);
               textcolor(7);
               printf("Permite modificar datos existentes");
               textcolor(10);
               gotoxy(*x,*y-2);
               printf("Altas");
               gotoxy(*x,*y-1);
               textbackground(0);
               printf("Bajas");
               gotoxy(*x,*y);
               textbackground(9);
               printf("Modificaciones");
               textbackground(0);
               gotoxy(*x,*y+1);
               printf("Consultas");
               gotoxy(*x,*y+2);
               textbackground(0);
               printf("Reportes");
               gotoxy(*x,*y+3);
               textbackground(0);
               printf("Salir");
               ipn();
     }
     if(*y==14)
     {
               clrscr();
               voca3();
               about();
               marco();
               textbackground(0);
               gotoxy(40,12);
               textcolor(7);
               printf("Permite consultar datos registrados");
               textcolor(10);
               gotoxy(*x,*y-3);
               printf("Altas");
               gotoxy(*x,*y-2);
               textbackground(0);
               printf("Bajas");
               gotoxy(*x,*y-1);
               textbackground(0);
               printf("Modificaciones");
               textbackground(9);
               gotoxy(*x,*y);
               printf("Consultas");
               gotoxy(*x,*y+1);
               textbackground(0);
               printf("Reportes");
               gotoxy(*x,*y+2);
               textbackground(0);
               printf("Salir");
               ipn();
     }
     if(*y==15)
     {
               clrscr();
               voca3();
               about();
               marco();
               textbackground(0);
               gotoxy(40,12);
               textcolor(7);
               printf("Permite generar reportes de datos");
               textcolor(10);
               gotoxy(*x,*y-4);
               printf("Altas");
               gotoxy(*x,*y-3);
               textbackground(0);
               printf("Bajas");
               gotoxy(*x,*y-2);
               textbackground(0);
               printf("Modificaciones");
               textbackground(0);
               gotoxy(*x,*y-1);
               printf("Consultas");
               gotoxy(*x,*y);
               textbackground(9);
               printf("Reportes");
               gotoxy(*x,*y+1);
               textbackground(0);
               printf("Salir");
               ipn();
     }
     if(*y==16)
     {
               clrscr();
               voca3();
               about();
               marco();
               textbackground(0);
               gotoxy(40,12);
               textcolor(7);
               printf("Salir del programa");
               textcolor(10);
               gotoxy(*x,*y-5);
               printf("Altas");
               gotoxy(*x,*y-4);
               textbackground(0);
               printf("Bajas");
               gotoxy(*x,*y-3);
               textbackground(0);
               printf("Modificaciones");
               textbackground(0);
               gotoxy(*x,*y-2);
               printf("Consultas");
               gotoxy(*x,*y-1);
               textbackground(0);
               printf("Reportes");
               gotoxy(*x,*y);
               textbackground(9);
               printf("Salir");
               ipn();
     }
}

void daralta(void)
{
       struct datos1 guardar1;
       struct datos2 guardar2;
       struct datos3 guardar3;
       FILE *archivo1, *archivo2, *archivo3;
       char namefile[20], nuevo, ruta1[30]={"C:/4IV4/base1/"}, ruta2[30]={"C:/4IV4/base2/"}, ruta3[30]={"C:/4IV4/base3/"};
       
       clrscr();
                                    
       gotoxy(19,3);
       textcolor(14);
       printf("Formulario para darse de ALTA en el sistema");

       gotoxy(5,10);
       textbackground(0);
       textcolor(10);
       printf("Nombre: ");
       textbackground(15);
       printf("              ");

       gotoxy(32,10);
       textbackground(0);
       textcolor(10);
       printf("A.P.: ");
       textbackground(15);
       printf("              ");

       gotoxy(59,10);
       textbackground(0);
       textcolor(10);
       printf("A.M.: ");
       textbackground(15);
       printf("              ");

       gotoxy(10,12);
       textbackground(0);
       textcolor(10);
       printf("Direccion: ");
       textbackground(15);
       printf("                        ");

       gotoxy(50,12);
       textbackground(0);
       textcolor(10);
       printf("Telefono: ");
       textbackground(15);
       printf("          ");

       gotoxy(5,14);
       textbackground(0);
       textcolor(10);
       printf("C.P.: ");
       textbackground(15);
       printf("     ");

       gotoxy(27,14);
       textbackground(0);
       textcolor(10);
       printf("Colonia: ");
       textbackground(15);
       printf("                    ");

       gotoxy(67,14);
       textbackground(0);
       textcolor(10);
       printf("Sexo: ");
       textbackground(15);
       printf("  ");

       gotoxy(22,16);
       textbackground(0);
       textcolor(10);
       printf("Ocupacion: ");
       textbackground(15);
       printf("                         ");

       gotoxy(15,7);
       textcolor(11);
       textbackground(0);
       printf("Introduzca su nombre.");
       textcolor(12);
       gotoxy(13,10);
       textbackground(15);
       fflush(stdin);
       gets(guardar1.nombre);
       gotoxy(15,7);
       textbackground(0);
       textcolor(11);
       printf("Introduzca su apellido paterno.");
       textcolor(12);
       gotoxy(38,10);
       textbackground(15);
       fflush(stdin);
       gets(guardar1.paterno);
       gotoxy(15,7);
       textbackground(0);
       textcolor(11);
       printf("Introduzca su apellido materno.");
       textcolor(12);
       gotoxy(65,10);
       textbackground(15);
       fflush(stdin);
       gets(guardar1.materno);
       gotoxy(15,7);
       textbackground(0);
       textcolor(11);
       printf("Introduzca su domicilio.        ");
       textcolor(12);
       gotoxy(21,12);
       textbackground(15);
       fflush(stdin);
       gets(guardar2.direccion);
       gotoxy(15,7);
       textbackground(0);
       textcolor(11);
       printf("Introduzca su telefono.   ");
       textcolor(12);
       gotoxy(60,12);
       textbackground(15);
       fflush(stdin);
       gets(guardar2.telefono);
       gotoxy(15,7);
       textbackground(0);
       textcolor(11);
       printf("Introduzca su codigo postal.   ");
       textcolor(12);
       gotoxy(11,14);
       textbackground(15);
       fflush(stdin);
       gets(guardar2.postal);
       gotoxy(15,7);
       textbackground(0);
       textcolor(11);
       printf("Introduzca su colonia.        ");
       textcolor(12);
       gotoxy(36,14);
       textbackground(15);
       fflush(stdin);
       gets(guardar3.colonia);
       gotoxy(15,7);
       textbackground(0);
       textcolor(11);
       printf("Introduzca su sexo: M/F.        ");
       textcolor(12);
       gotoxy(73,14);
       textbackground(15);
       fflush(stdin);
       gets(guardar3.sexo);
       gotoxy(15,7);
       textbackground(0);
       textcolor(11);
       printf("Introduzca su ocupacion.         ");
       textcolor(12);
       gotoxy(33,16);
       textbackground(15);
       fflush(stdin);
       gets(guardar3.ocupacion);
       
       textbackground(0);
       gotoxy(25,21);
       textcolor(13);
       printf("Introduce el nombre del archivo: ");
       fflush(stdin);
       gets(namefile);

       archivo1=fopen(strcat(ruta1,strcat(namefile,".h32")),"wb");
       fwrite(&guardar1,sizeof(guardar1),1,archivo1);
       fclose(archivo1);
       
       archivo2=fopen(strcat(ruta2,namefile),"wb");
       fwrite(&guardar2,sizeof(guardar2),1,archivo2);
       fclose(archivo2);
       
       archivo3=fopen(strcat(ruta3,namefile),"wb");
       fwrite(&guardar3,sizeof(guardar3),1,archivo3);
       fclose(archivo3);

       progreso_altas();
       
       reint_altas:
                         clrscr();
                         textcolor(10);
                         gotoxy(20,16);
                         textbackground(0);
                         printf("Desea agregar nuevos datos? s/n: ");
                         scanf("%c",&nuevo);
                         nuevo=tolower(nuevo);
                         if(nuevo=='s')
                         {
                          daralta();
                         }
                         else if(nuevo=='n')
                         {
                          main();
                         }
                         else
                         {
                          goto reint_altas;
                         }
}

void darbaja(void)
{
       struct datos1 leer1;
       struct datos2 leer2;
       struct datos3 leer3;
       FILE *archivo1, *archivo2, *archivo3;
       char namefile[20], contenido[500], reintentar, borrar, ruta1[30]={"C:/4IV4/base1/"}, ruta2[30]={"C:/4IV4/base2/"}, ruta3[30]={"C:/4IV4/base3/"}, ruta4[30]={"C:/4IV4/base1/"}, ruta5[30]={"C:/4IV4/base2/"}, ruta6[30]={"C:/4IV4/base3/"}; //Ruta en red: //Lp119-pc/4iv4/base3/
 
       fflush(stdin);
       clrscr();
                                    
       gotoxy(19,3);
       textcolor(14);
       printf("Formulario para darse de BAJA en el sistema");
       
       gotoxy(15,9);
       textcolor(10);
       printf("Introduzca el nombre del archivo a eliminar: ");
       gets(namefile);
       archivo1=fopen(strcat(ruta1,strcat(namefile,".h32")),"rb");
       archivo2=fopen(strcat(ruta2,namefile),"rb");
       archivo3=fopen(strcat(ruta3,namefile),"rb");
       
       if(archivo1==NULL || archivo2==NULL || archivo3==NULL)
       {
                         gotoxy(25,14);
                         textcolor(11);
                         printf("El archivo \"");
                         textcolor(13);
                         printf("%s",namefile);
                         textcolor(11);
                         printf("\" no existe");
                         reint_nullfile:
                                               gotoxy(35,17);
                                               textcolor(12);
                                               printf("Reintentar? s/n: ");
                                               fflush(stdin);
                                               scanf("%c",&reintentar);
                                               reintentar=tolower(reintentar);
                                               if(reintentar=='s')
                                               {
                                                darbaja();
                                               }
                                               else if(reintentar=='n')
                                               {
                                                main();
                                               }
                                               else
                                               {
                                                clrscr();
                                                goto reint_nullfile;
                                               }
       }

       if(archivo1!=NULL)
       {
                         clrscr();
                         gotoxy(19,3);
                         textcolor(14);
                         printf("Formulario para darse de BAJA en el sistema");
                         
                         gotoxy(25,6);
                         textcolor(11);
                         printf("Informacion almacenada en ");
                         textcolor(13);
                         printf("%s",namefile);
                         
                         fread(&leer1,sizeof(leer1),1,archivo1);
                         
                         gotoxy(5,10);
                         textbackground(0);
                         textcolor(10);
                         printf("Nombre: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer1.nombre);

                         gotoxy(32,10);
                         textbackground(0);
                         textcolor(10);
                         printf("A.P.: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer1.paterno);

                         gotoxy(59,10);
                         textbackground(0);
                         textcolor(10);
                         printf("A.M.: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer1.materno);
                                       
                         fclose(archivo1);
       }
       
       if(archivo2!=NULL)
       {
                         fread(&leer2,sizeof(leer2),1,archivo2);

                         gotoxy(10,12);
                         textbackground(0);
                         textcolor(10);
                         printf("Direccion: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer2.direccion);

                         gotoxy(50,12);
                         textbackground(0);
                         textcolor(10);
                         printf("Telefono: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer2.telefono);

                         gotoxy(5,14);
                         textbackground(0);
                         textcolor(10);
                         printf("C.P.: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer2.postal);
                                       
                         fclose(archivo2);
       }
       
       if(archivo3!=NULL)
       {
                         fread(&leer3,sizeof(leer3),1,archivo3);

                         gotoxy(27,14);
                         textbackground(0);
                         textcolor(10);
                         printf("Colonia: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer3.colonia);

                         gotoxy(67,14);
                         textbackground(0);
                         textcolor(10);
                         printf("Sexo: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer3.sexo);

                         gotoxy(22,16);
                         textbackground(0);
                         textcolor(10);
                         printf("Ocupacion: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer3.ocupacion);
                                       
                         fclose(archivo3);
       }

                         textbackground(0);
                         gotoxy(15,23);
                         textcolor(12);
                         printf("Realmente desea eliminar los datos del sistema? s/n: ");
                         fflush(stdin);
                         scanf("%c",&borrar);
                         borrar=tolower(borrar);
                         if(borrar=='s')
                         {
                                        clrscr();
                                        remove(strcat(ruta4,namefile));
                                        remove(strcat(ruta5,namefile));
                                        remove(strcat(ruta6,namefile));
                                        progreso_bajas();
                                        gotoxy(25,18);
                                        textcolor(14);
                                        printf("Archivo borrado satisfactoriamente");
                                        reint_siborrar:
                                                           gotoxy(20,21);
                                                           textcolor(12);
                                                           printf("Desea eliminar otro archivo? s/n: ");
                                                           fflush(stdin);
                                                           scanf("%c",&reintentar);
                                                           reintentar=tolower(reintentar);
                                                           if(reintentar=='s')
                                                           {
                                                            darbaja();
                                                           }
                                                           else if(reintentar=='n')
                                                           {
                                                            main();
                                                           }
                                                           else
                                                           {
                                                            clrscr();
                                                            goto reint_siborrar;
                                                           }
                       }
                       else
                       {
                                      clrscr();
                                      gotoxy(25,13);
                                      textcolor(14);
                                      printf("El archivo no fue borrado");
                                      reint_noborrar:
                                                     gotoxy(20,17);
                                                     textcolor(12);
                                                     printf("Desea borrar otro archivo? s/n: ");
                                                     fflush(stdin);
                                                     scanf("%c",&reintentar);
                                                     reintentar=tolower(reintentar);
                                                     if(reintentar=='s')
                                                     {
                                                      darbaja();
                                                     }
                                                     else if(reintentar=='n')
                                                     {
                                                      main();
                                                     }
                                                     else
                                                     {
                                                      clrscr();
                                                      goto reint_noborrar;
                                                     }
                       }
                       getch();
}

void modificaciones(void)
{
       struct datos1 leer1, guardar1;
       struct datos2 leer2, guardar2;
       struct datos3 leer3, guardar3;
       FILE *archivo1, *archivo2, *archivo3;
       char namefile[20], contenido[500], reintentar, modif, ruta1[30]={"C:/4IV4/base1/"}, ruta2[30]={"C:/4IV4/base2/"}, ruta3[30]={"C:/4IV4/base3/"}, tecla;
 
       fflush(stdin);
       clrscr();
                                    
       gotoxy(19,3);
       textcolor(14);
       printf("Formulario para MODIFICACIONES en el sistema");
       
       gotoxy(15,9);
       textcolor(10);
       printf("Introduzca el nombre del archivo a modificar: ");
       fflush(stdin);
       gets(namefile);
       archivo1=fopen(strcat(ruta1,strcat(namefile,".h32")),"rb+");
       archivo2=fopen(strcat(ruta2,namefile),"rb+");
       archivo3=fopen(strcat(ruta3,namefile),"rb+");
       
       if(archivo1==NULL || archivo2==NULL || archivo3==NULL)
       {
                         gotoxy(25,14);
                         textcolor(11);
                         printf("El archivo \"");
                         textcolor(13);
                         printf("%s",namefile);
                         textcolor(11);
                         printf("\" no existe");
                         reint_nullfile:
                                        gotoxy(35,17);
                                        textcolor(12);
                                        printf("Reintentar? s/n: ");
                                        fflush(stdin);
                                        scanf("%c",&reintentar);
                                        reintentar=tolower(reintentar);
                                        if(reintentar=='s')
                                        {
                                         modificaciones();
                                        }
                                        else if(reintentar=='n')
                                        {
                                         main();
                                        }
                                        else
                                        {
                                         clrscr();
                                         goto reint_nullfile;
                                        }
       }

       if(archivo1!=NULL)
       {
                         clrscr();
                         gotoxy(19,3);
                         textcolor(14);
                         printf("Formulario para MODIFICACIONES en el sistema");
                         
                         gotoxy(25,6);
                         textcolor(11);
                         printf("Informacion almacenada en ");
                         textcolor(13);
                         printf("%s",namefile);
                         
                         fread(&leer1,sizeof(leer1),1,archivo1);
                         
                         gotoxy(5,10);
                         textbackground(0);
                         textcolor(5);
                         printf("N");
                         gotoxy(6,10);
                         textcolor(10);
                         printf("ombre: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer1.nombre);

                         gotoxy(32,10);
                         textbackground(0);
                         textcolor(10);
                         printf("A.");
                         gotoxy(34,10);
                         textcolor(5);
                         printf("P.");
                         gotoxy(35,10);
                         textcolor(10);
                         printf(".: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer1.paterno);

                         gotoxy(59,10);
                         textbackground(0);
                         textcolor(10);
                         printf("A.");
                         gotoxy(61,10);
                         textcolor(5);
                         printf("M");
                         gotoxy(62,10);
                         textcolor(10);
                         printf(".: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer1.materno);
       }
       
       if(archivo2!=NULL)
       {
                         fread(&leer2,sizeof(leer2),1,archivo2);

                         gotoxy(10,12);
                         textbackground(0);
                         textcolor(5);
                         printf("D");
                         gotoxy(11,12);
                         textcolor(10);
                         printf("ireccion: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer2.direccion);

                         gotoxy(50,12);
                         textbackground(0);
                         textcolor(5);
                         printf("T");
                         gotoxy(51,12);
                         textcolor(10);
                         printf("elefono: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer2.telefono);

                         gotoxy(5,14);
                         textbackground(0);
                         textcolor(5);
                         printf("C");
                         gotoxy(6,14);
                         textcolor(10);
                         printf(".P.: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer2.postal);
       }
       
       if(archivo3!=NULL)
       {
                         fread(&leer3,sizeof(leer3),1,archivo3);

                         gotoxy(27,14);
                         textbackground(0);
                         textcolor(10);
                         printf("Co");
                         gotoxy(29,14);
                         textcolor(5);
                         printf("L");
                         gotoxy(30,14);
                         textcolor(10);
                         printf("onia: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer3.colonia);

                         gotoxy(67,14);
                         textbackground(0);
                         textcolor(5);
                         printf("S");
                         gotoxy(68,14);
                         textcolor(10);
                         printf("exo: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer3.sexo);

                         gotoxy(22,16);
                         textbackground(0);
                         textcolor(5);
                         printf("O");
                         gotoxy(23,16);
                         textcolor(10);
                         printf("cupacion: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer3.ocupacion);
       }
       
                         teclacampo:
                         gotoxy(10,20);
                         textbackground(0);
                         textcolor(14);
                         printf("Oprime la tecla del campo a modificar. Pulsa 'Q' para salir");
                         textcolor(9);
                         fflush(stdin);
                         tecla=getch();
                         tecla=tolower(tecla);
                         if(tecla=='n')
                         {
                                       fflush(stdin);
                                       gotoxy(13,10);
                                       textbackground(15);
                                       fflush(stdin);
                                       gets(guardar1.nombre);
                                       fseek(archivo1,0,SEEK_SET);
                                       fwrite(&guardar1.nombre,sizeof(guardar1.nombre),1,archivo1);
                                       goto teclacampo;
                         }
                         else if(tecla=='p')
                         {
                                       fflush(stdin);
                                       gotoxy(38,10);
                                       textbackground(15);
                                       fflush(stdin);
                                       gets(guardar1.paterno);
                                       fseek(archivo1,50,SEEK_SET);
                                       fwrite(&guardar1.paterno,sizeof(guardar1.paterno),1,archivo1);
                                       goto teclacampo;
                         }
                         else if(tecla=='m')
                         {
                                       fflush(stdin);
                                       gotoxy(65,10);
                                       textbackground(15);
                                       fflush(stdin);
                                       gets(guardar1.materno);
                                       fseek(archivo1,100,SEEK_SET);
                                       fwrite(&guardar1.materno,sizeof(guardar1.materno),1,archivo1);
                                       goto teclacampo;
                         }
                         else if(tecla=='d')
                         {
                                       fflush(stdin);
                                       gotoxy(21,12);
                                       textbackground(15);
                                       fflush(stdin);
                                       gets(guardar2.direccion);
                                       fseek(archivo2,0,SEEK_SET);
                                       fwrite(&guardar2.direccion,sizeof(guardar2.direccion),1,archivo2);
                                       goto teclacampo;
                         }
                         else if(tecla=='t')
                         {
                                       fflush(stdin);
                                       gotoxy(60,12);
                                       textbackground(15);
                                       fflush(stdin);
                                       gets(guardar2.telefono);
                                       fseek(archivo2,70,SEEK_SET);
                                       fwrite(&guardar2.telefono,sizeof(guardar2.telefono),1,archivo2);
                                       goto teclacampo;
                         }
                         else if(tecla=='c')
                         {
                                       fflush(stdin);
                                       gotoxy(11,14);
                                       textbackground(15);
                                       fflush(stdin);
                                       gets(guardar2.postal);
                                       fseek(archivo2,85,SEEK_SET);
                                       fwrite(&guardar2.postal,sizeof(guardar2.postal),1,archivo2);
                                       goto teclacampo;
                         }
                         else if(tecla=='l')
                         {
                                       fflush(stdin);
                                       gotoxy(36,14);
                                       textbackground(15);
                                       fflush(stdin);
                                       gets(guardar3.colonia);
                                       fseek(archivo3,0,SEEK_SET);
                                       fwrite(&guardar3.colonia,sizeof(guardar3.colonia),1,archivo3);
                                       goto teclacampo;
                         }
                         else if(tecla=='s')
                         {
                                       fflush(stdin);
                                       gotoxy(73,14);
                                       textbackground(15);
                                       fflush(stdin);
                                       gets(guardar3.sexo);
                                       fseek(archivo3,60,SEEK_SET);
                                       fwrite(&guardar3.sexo,sizeof(guardar3.sexo),1,archivo3);
                                       goto teclacampo;
                         }
                         else if(tecla=='o')
                         {
                                       fflush(stdin);
                                       gotoxy(33,16);
                                       textbackground(15);
                                       fflush(stdin);
                                       gets(guardar3.ocupacion);
                                       fseek(archivo3,70,SEEK_SET);
                                       fwrite(&guardar3.ocupacion,sizeof(guardar3.ocupacion),1,archivo3);
                                       goto teclacampo;
                         }
                         else if(tecla=='q')
                         {
                                  fclose(archivo1);
                                  fclose(archivo2);
                                  fclose(archivo3);
                                  progreso_modif();
                         reint_newmodif:
                                  clrscr();
                                  textbackground(0);
                                  gotoxy(15,23);
                                  textcolor(12);
                                  printf("Desea modificar otro archivo? s/n: ");
                                  fflush(stdin);
                                  scanf("%c",&modif);
                                  modif=tolower(modif);
                                  if(modif=='s')
                                  {
                                   modificaciones();
                                  }
                                  else if(modif=='n')
                                  {
                                   main();
                                  }
                                  else
                                  {
                                   clrscr();
                                   goto reint_newmodif;
                                  }
                         }

}

void consultas(void)
{
       struct datos1 leer1;
       struct datos2 leer2;
       struct datos3 leer3;
       FILE *archivo1, *archivo2, *archivo3;
       char namefile[20], contenido[500], reintentar, consulta, ruta1[30]={"C:/4IV4/base1/"}, ruta2[30]={"C:/4IV4/base2/"}, ruta3[30]={"C:/4IV4/base3/"};
 
       fflush(stdin);
       clrscr();
                                    
       gotoxy(19,3);
       textcolor(14);
       printf("Formulario para CONSULTAS en el sistema");
       
       gotoxy(15,9);
       textcolor(10);
       printf("Introduzca el nombre del archivo a consultar: ");
       gets(namefile);
       archivo1=fopen(strcat(ruta1,strcat(namefile,".h32")),"rb");
       archivo2=fopen(strcat(ruta2,namefile),"rb");
       archivo3=fopen(strcat(ruta3,namefile),"rb");
       
       if(archivo1==NULL || archivo2==NULL || archivo3==NULL)
       {
                         gotoxy(25,14);
                         textcolor(11);
                         printf("El archivo \"");
                         textcolor(13);
                         printf("%s",namefile);
                         textcolor(11);
                         printf("\" no existe");
                         reint_nullfile:
                                        gotoxy(35,17);
                                        textcolor(12);
                                        printf("Reintentar? s/n: ");
                                        fflush(stdin);
                                        scanf("%c",&reintentar);
                                        reintentar=tolower(reintentar);
                                        if(reintentar=='s')
                                        {
                                         consultas();
                                        }
                                        else if(reintentar=='n')
                                        {
                                         main();
                                        }
                                        else
                                        {
                                         clrscr();
                                         goto reint_nullfile;
                                        }
       }

       if(archivo1!=NULL)
       {
                         progreso_consultas();
                         clrscr();
                         gotoxy(19,3);
                         textcolor(14);
                         printf("Formulario para CONSULTAS en el sistema");
                         
                         gotoxy(25,6);
                         textcolor(11);
                         printf("Informacion almacenada en ");
                         textcolor(13);
                         printf("%s",namefile);
                         
                         fread(&leer1,sizeof(leer1),1,archivo1);
                         
                         gotoxy(5,10);
                         textbackground(0);
                         textcolor(10);
                         printf("Nombre: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer1.nombre);

                         gotoxy(32,10);
                         textbackground(0);
                         textcolor(10);
                         printf("A.P.: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer1.paterno);

                         gotoxy(59,10);
                         textbackground(0);
                         textcolor(10);
                         printf("A.M.: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer1.materno);
                                       
                         fclose(archivo1);
       }
       
       if(archivo2!=NULL)
       {
                         fread(&leer2,sizeof(leer2),1,archivo2);

                         gotoxy(10,12);
                         textbackground(0);
                         textcolor(10);
                         printf("Direccion: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer2.direccion);

                         gotoxy(50,12);
                         textbackground(0);
                         textcolor(10);
                         printf("Telefono: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer2.telefono);

                         gotoxy(5,14);
                         textbackground(0);
                         textcolor(10);
                         printf("C.P.: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer2.postal);
                                       
                         fclose(archivo2);
       }
       
       if(archivo3!=NULL)
       {
                         fread(&leer3,sizeof(leer3),1,archivo3);

                         gotoxy(27,14);
                         textbackground(0);
                         textcolor(10);
                         printf("Colonia: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer3.colonia);

                         gotoxy(67,14);
                         textbackground(0);
                         textcolor(10);
                         printf("Sexo: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer3.sexo);

                         gotoxy(22,16);
                         textbackground(0);
                         textcolor(10);
                         printf("Ocupacion: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer3.ocupacion);
                                       
                         fclose(archivo3);
       }

                         reint_newquery:
                                  textbackground(0);
                                  gotoxy(15,23);
                                  textcolor(12);
                                  printf("Desea realizar otra consulta? s/n: ");
                                  fflush(stdin);
                                  scanf("%c",&consulta);
                                  consulta=tolower(consulta);
                                  if(consulta=='s')
                                  {
                                   consultas();
                                  }
                                  else if(consulta=='n')
                                  {
                                   main();
                                  }
                                  else
                                  {
                                   clrscr();
                                   goto reint_newquery;
                                  }
}

void reportes(void)
{
       struct datos1 leer1;
       struct datos2 leer2;
       struct datos3 leer3;
       FILE *archivo1, *archivo2, *archivo3, *archivo4;
       char namefile[20], contenido[500], reintentar, imprimir, ruta1[30]={"C:/4IV4/base1/"}, ruta2[30]={"C:/4IV4/base2/"}, ruta3[30]={"C:/4IV4/base3/"}, ruta4[30]={"C:/4IV4/base1/"}; //Ruta en red: //Lp119-pc/4iv4/base3/
 
       fflush(stdin);
       clrscr();
                                    
       gotoxy(19,3);
       textcolor(14);
       printf("Formulario para realizar REPORTES en el sistema");
       
       gotoxy(15,9);
       textcolor(10);
       printf("Introduzca el nombre del archivo a imprimir: ");
       gets(namefile);
       archivo1=fopen(strcat(ruta1,strcat(namefile,".h32")),"rb");
       archivo2=fopen(strcat(ruta2,namefile),"rb");
       archivo3=fopen(strcat(ruta3,namefile),"rb");
       
       if(archivo1==NULL || archivo2==NULL || archivo3==NULL)
       {
                         gotoxy(25,14);
                         textcolor(11);
                         printf("El archivo \"");
                         textcolor(13);
                         printf("%s",namefile);
                         textcolor(11);
                         printf("\" no existe");
                         reint_imprimir:
                                               gotoxy(35,17);
                                               textcolor(12);
                                               printf("Reintentar? s/n: ");
                                               fflush(stdin);
                                               scanf("%c",&reintentar);
                                               reintentar=tolower(reintentar);
                                               if(reintentar=='s')
                                               {
                                                reportes();
                                               }
                                               else if(reintentar=='n')
                                               {
                                                main();
                                               }
                                               else
                                               {
                                                clrscr();
                                                goto reint_imprimir;
                                               }
       }

       if(archivo1!=NULL)
       {
                         clrscr();
                         progreso_consultas();
                         clrscr();
                         gotoxy(19,3);
                         textcolor(14);
                         printf("Formulario para realizar REPORTES en el sistema");
                         
                         gotoxy(25,6);
                         textcolor(11);
                         printf("Informacion almacenada en ");
                         textcolor(13);
                         printf("%s",namefile);
                         
                         fread(&leer1,sizeof(leer1),1,archivo1);
                         
                         gotoxy(5,10);
                         textbackground(0);
                         textcolor(10);
                         printf("Nombre: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer1.nombre);

                         gotoxy(32,10);
                         textbackground(0);
                         textcolor(10);
                         printf("A.P.: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer1.paterno);

                         gotoxy(59,10);
                         textbackground(0);
                         textcolor(10);
                         printf("A.M.: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer1.materno);
                                       
                         fclose(archivo1);
       }
       
       if(archivo2!=NULL)
       {
                         fread(&leer2,sizeof(leer2),1,archivo2);

                         gotoxy(10,12);
                         textbackground(0);
                         textcolor(10);
                         printf("Direccion: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer2.direccion);

                         gotoxy(50,12);
                         textbackground(0);
                         textcolor(10);
                         printf("Telefono: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer2.telefono);

                         gotoxy(5,14);
                         textbackground(0);
                         textcolor(10);
                         printf("C.P.: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer2.postal);
                                       
                         fclose(archivo2);
       }
       
       if(archivo3!=NULL)
       {
                         fread(&leer3,sizeof(leer3),1,archivo3);

                         gotoxy(27,14);
                         textbackground(0);
                         textcolor(10);
                         printf("Colonia: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer3.colonia);

                         gotoxy(67,14);
                         textbackground(0);
                         textcolor(10);
                         printf("Sexo: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer3.sexo);

                         gotoxy(22,16);
                         textbackground(0);
                         textcolor(10);
                         printf("Ocupacion: ");
                         textbackground(15);
                         textcolor(9);
                         puts(leer3.ocupacion);
                                       
                         fclose(archivo3);
       }

                         textbackground(0);
                         gotoxy(15,23);
                         textcolor(12);
                         printf("Desea imprimir los datos? s/n: ");
                         fflush(stdin);
                         scanf("%c",&imprimir);
                         imprimir=tolower(imprimir);
                         if(imprimir=='s')
                         {
                                        clrscr();
                                        archivo4 = fopen(strcat(ruta4,"imprimir.txt"),"w");
                                        fprintf(archivo4,"A.P.: ");
                                        fputs(leer1.paterno,archivo4);
                                        fprintf(archivo4,"\n");
                                        fprintf(archivo4,"A.M.: ");
                                        fputs(leer1.materno,archivo4);
                                        fprintf(archivo4,"\n");
                                        fprintf(archivo4,"Nombre.: ");
                                        fputs(leer1.nombre,archivo4);
                                        fprintf(archivo4,"\n");
                                        fprintf(archivo4,"Direccion: ");
                                        fputs(leer2.direccion,archivo4);
                                        fprintf(archivo4,"\n");
                                        fprintf(archivo4,"Colonia: ");
                                        fputs(leer3.colonia,archivo4);
                                        fprintf(archivo4,"\n");
                                        fprintf(archivo4,"C.P.: ");
                                        fputs(leer2.postal,archivo4);
                                        fprintf(archivo4,"\n");
                                        fprintf(archivo4,"Telefono: ");
                                        fputs(leer2.direccion,archivo4);
                                        fprintf(archivo4,"\n");
                                        fprintf(archivo4,"Sexo: ");
                                        fputs(leer3.sexo,archivo4);
                                        fprintf(archivo4,"\n");
                                        fprintf(archivo4,"Ocupacion: ");
                                        fputs(leer3.ocupacion,archivo4);
                                        fprintf(archivo4,"\n");
                                        fclose(archivo4);
                                        system("Type imprimir.txt>PRN");
                                        progreso_reportes();
                                        gotoxy(25,18);
                                        textcolor(14);
                                        printf("Archivo impreso correctamente.");
                                        remove(ruta4);
                                        reint_siimprimir:
                                                           gotoxy(20,21);
                                                           textcolor(12);
                                                           printf("Desea imprimir otro archivo? s/n: ");
                                                           fflush(stdin);
                                                           scanf("%c",&reintentar);
                                                           reintentar=tolower(reintentar);
                                                           if(reintentar=='s')
                                                           {
                                                            reportes();
                                                           }
                                                           else if(reintentar=='n')
                                                           {
                                                            main();
                                                           }
                                                           else
                                                           {
                                                            clrscr();
                                                            goto reint_siimprimir;
                                                           }
                       }
                       else
                       {
                                      clrscr();
                                      gotoxy(25,13);
                                      textcolor(14);
                                      printf("El archivo no fue impreso");
                                      reint_noimprimir:
                                                     gotoxy(20,17);
                                                     textcolor(12);
                                                     printf("Desea imprimir otro archivo? s/n: ");
                                                     fflush(stdin);
                                                     scanf("%c",&reintentar);
                                                     reintentar=tolower(reintentar);
                                                     if(reintentar=='s')
                                                     {
                                                      reportes();
                                                     }
                                                     else if(reintentar=='n')
                                                     {
                                                      main();
                                                     }
                                                     else
                                                     {
                                                      clrscr();
                                                      goto reint_noimprimir;
                                                     }
                       }
                       getch();
}

void salir(void)
{
               int x, y, i, tiempo, color, vez, start=10, end=14;
               char bye[30] = {"Gracias por su atencion!!"};
               tiempo = time(NULL);
               srand(tiempo);
               gotoxy(40,12);
               printf("                  ");
               textbackground(9);
               textcolor(10);
               gotoxy(10,16);
               Sleep(200);
               textbackground(0);
               printf("     ");
               gotoxy(10,15);
               textbackground(0);
               Sleep(200);
               printf("        ");
               gotoxy(10,14);
               textbackground(0);
               Sleep(200);
               printf("         ");
               textbackground(0);
               gotoxy(10,13);
               Sleep(200);
               printf("              ");
               gotoxy(10,12);
               textbackground(0);
               Sleep(200);
               printf("     ");
               gotoxy(10,11);
               textbackground(0);
               Sleep(200);
               printf("     ");
               for(y=18;y>=9;y--)
               {
                                 gotoxy(26,y);
                                 Sleep(30);
                                 printf(" ");
               }
               for(x=26;x>=7;x--)
               {
                                gotoxy(x,9);
                                Sleep(30);
                                printf(" ");
               }
               for(y=9;y<=18;y++)
               {
                                 gotoxy(7,y);
                                 Sleep(30);
                                 printf(" ");
               }
               for(x=7;x<=26;x++)
               {
                                gotoxy(x,18);
                                Sleep(30);
                                printf(" ");
               }
               for(x=60;x>=17;x--)
               {
                                  gotoxy(x,5);
                                  Sleep(30);
                                  printf(" ");
               }
               for(x=55;x>=23;x--)
               {
                                  gotoxy(x,3);
                                  Sleep(30);
                                  printf(" ");
               }
               x=28;
               vez = 1;
               while(vez<=3)
               {
                            color = rand()%(end-start+1)+start;
                            for(i=0;i<=24;i++)
                            {
                                              gotoxy(x,14);
                                              textcolor(14);
                                              Sleep(20);
                                              textcolor(color);
                                              printf("%c",bye[i]);
                                              x++;
                            }
                            vez++;
                            x=28;
                            Sleep(50);
               }
               Sleep(1000);
               exit(1);
}


void marco(void)
{
     int marx, mary;
     textcolor(11);
     for(marx=7;marx<=26;marx++)
     {
                                gotoxy(marx,9);
                                printf("*");
                                gotoxy(marx,18);
                                printf("*");
     }
     
     for(mary=9;mary<=18;mary++)
     {
                                 gotoxy(7,mary);
                                 printf("*");
                                 gotoxy(26,mary);
                                 printf("*");
     }
     textcolor(10);
}

void ipn(void)
{
     gotoxy(25,3);
     textbackground(4);
     textcolor(15);
     printf("I");
     gotoxy(35,3);
     textbackground(4);
     textcolor(15);
     printf("P");
     gotoxy(47,3);
     textbackground(4);
     textcolor(15);
     printf("N");
     Sleep(1000);
     gotoxy(26,3);
     textbackground(15);
     textcolor(4);
     printf("nstituto");
     textbackground(0);
     gotoxy(36,3);
     textbackground(15);
     textcolor(4);
     printf("olitecnico");
     textbackground(0);
     gotoxy(48,3);
     textbackground(15);
     textcolor(4);
     printf("acional");
}

void voca3(void)
{
     textbackground(0);
     textcolor(14);
     gotoxy(19,5);
     printf("C.E.C.y.T No. 3 \"Estanislao Ramirez Ruiz\"");
}

void about(void)
{
     textbackground(0);
     gotoxy(25,21);
     textcolor(12);
     printf("Por Ortega Ortu\xA4o Eder | 4IV4"); // \x Mostrar codigo hexadecimal - A4 = ñ [Hexadecimal]
     gotoxy(26,23);
     textcolor(15);
     printf("http://www.blogsh32.com.ar/");
}

void progreso_altas(void)
{
       char x='%';
       clrscr();
       gotoxy(25,6);
       textcolor(11);
       printf("Guardando archivo...");
       Sleep(150);
       gotoxy(20,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("10%c",x);
       Sleep(150);
       gotoxy(24,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("20%c",x);
       Sleep(150);
       gotoxy(28,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("30%c",x);
       Sleep(150);
       gotoxy(32,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("40%c",x);
       Sleep(150);
       gotoxy(36,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("50%c",x);
       Sleep(150);
       gotoxy(40,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(38,14);
       textbackground(15);
       printf("60%c",x);
       Sleep(150);
       gotoxy(44,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(38,14);
       textbackground(15);
       printf("70%c",x);
       Sleep(150);
       gotoxy(48,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(38,14);
       textbackground(15);
       printf("80%c",x);
       Sleep(150);
       gotoxy(52,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(38,14);
       textbackground(15);
       printf("90%c",x);
       Sleep(150);
       gotoxy(56,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(37,14);
       textbackground(15);
       printf("100%c",x);
       textbackground(0);
       Sleep(150);
}

void progreso_bajas(void)
{
       char x='%';
       clrscr();
       gotoxy(25,6);
       textcolor(11);
       printf("Borrando archivo...");
       Sleep(150);
       gotoxy(20,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("10%c",x);
       Sleep(150);
       gotoxy(24,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("20%c",x);
       Sleep(150);
       gotoxy(28,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("30%c",x);
       Sleep(150);
       gotoxy(32,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("40%c",x);
       Sleep(150);
       gotoxy(36,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("50%c",x);
       Sleep(150);
       gotoxy(40,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(38,14);
       textbackground(15);
       printf("60%c",x);
       Sleep(150);
       gotoxy(44,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(38,14);
       textbackground(15);
       printf("70%c",x);
       Sleep(150);
       gotoxy(48,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(38,14);
       textbackground(15);
       printf("80%c",x);
       Sleep(150);
       gotoxy(52,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(38,14);
       textbackground(15);
       printf("90%c",x);
       Sleep(150);
       gotoxy(56,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(37,14);
       textbackground(15);
       printf("100%c",x);
       textbackground(0);
       Sleep(150);
}

void progreso_modif(void)
{
       char x='%';
       clrscr();
       gotoxy(25,6);
       textcolor(11);
       printf("Guardando los cambios...");
       Sleep(150);
       gotoxy(20,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("10%c",x);
       Sleep(150);
       gotoxy(24,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("20%c",x);
       Sleep(150);
       gotoxy(28,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("30%c",x);
       Sleep(150);
       gotoxy(32,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("40%c",x);
       Sleep(150);
       gotoxy(36,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("50%c",x);
       Sleep(150);
       gotoxy(40,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(38,14);
       textbackground(15);
       printf("60%c",x);
       Sleep(150);
       gotoxy(44,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(38,14);
       textbackground(15);
       printf("70%c",x);
       Sleep(150);
       gotoxy(48,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(38,14);
       textbackground(15);
       printf("80%c",x);
       Sleep(150);
       gotoxy(52,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(38,14);
       textbackground(15);
       printf("90%c",x);
       Sleep(150);
       gotoxy(56,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(37,14);
       textbackground(15);
       printf("100%c",x);
       textbackground(0);
       Sleep(150);
}

void progreso_consultas(void)
{
       char x='%';
       clrscr();
       gotoxy(25,6);
       textcolor(11);
       printf("Leyendo archivo...");
       Sleep(150);
       gotoxy(20,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("10%c",x);
       Sleep(150);
       gotoxy(24,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("20%c",x);
       Sleep(150);
       gotoxy(28,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("30%c",x);
       Sleep(150);
       gotoxy(32,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("40%c",x);
       Sleep(150);
       gotoxy(36,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("50%c",x);
       Sleep(150);
       gotoxy(40,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(38,14);
       textbackground(15);
       printf("60%c",x);
       Sleep(150);
       gotoxy(44,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(38,14);
       textbackground(15);
       printf("70%c",x);
       Sleep(150);
       gotoxy(48,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(38,14);
       textbackground(15);
       printf("80%c",x);
       Sleep(150);
       gotoxy(52,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(38,14);
       textbackground(15);
       printf("90%c",x);
       Sleep(150);
       gotoxy(56,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(37,14);
       textbackground(15);
       printf("100%c",x);
       textbackground(0);
       Sleep(150);
}

void progreso_reportes(void)
{
       char x='%';
       clrscr();
       gotoxy(25,6);
       textcolor(11);
       printf("Imprimiendo archivo...");
       Sleep(150);
       gotoxy(20,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("10%c",x);
       Sleep(150);
       gotoxy(24,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("20%c",x);
       Sleep(150);
       gotoxy(28,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("30%c",x);
       Sleep(150);
       gotoxy(32,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("40%c",x);
       Sleep(150);
       gotoxy(36,14);
       textbackground(15);
       printf("    ");
       textcolor(14);
       gotoxy(38,14);
       textbackground(0);
       printf("50%c",x);
       Sleep(150);
       gotoxy(40,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(38,14);
       textbackground(15);
       printf("60%c",x);
       Sleep(150);
       gotoxy(44,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(38,14);
       textbackground(15);
       printf("70%c",x);
       Sleep(150);
       gotoxy(48,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(38,14);
       textbackground(15);
       printf("80%c",x);
       Sleep(150);
       gotoxy(52,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(38,14);
       textbackground(15);
       printf("90%c",x);
       Sleep(150);
       gotoxy(56,14);
       textbackground(15);
       printf("    ");
       textcolor(9);
       gotoxy(37,14);
       textbackground(15);
       printf("100%c",x);
       textbackground(0);
       Sleep(150);
}

// Source desarrollado por Ortega Ortuño Eder - 4IV4 @ CECyT No. 3 [Año 2011] | http://www.blogsh32.com.ar/
