#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#define DISPLAY_X 800
#define DISPLAY_Y 600

typedef ALLEGRO_DISPLAY aDisplay;
typedef ALLEGRO_EVENT aEvento;
typedef ALLEGRO_EVENT_QUEUE aColaEvento;
typedef ALLEGRO_FONT aFuente;

aDisplay *dis = NULL;
aEvento evento;
aColaEvento *queue_evento;
aFuente *fuente;

void inicializar(void)
{
    if(!al_init())
    {
        al_show_native_message_box(NULL, "Error", "Error al inicializar Allegro.", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
        exit(-1);
    }
    if(!al_init_primitives_addon())
    {
        al_show_native_message_box(NULL, "Error", "Error al inicializar el addon de primitivas.", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
        exit(-2);
    }
    al_init_font_addon();
    if(!al_init_ttf_addon())
    {
        al_show_native_message_box(NULL, "Error", "Error al inicializar el addon de fuentes TrueType.", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
        exit(-3);
    }

    dis = al_create_display(DISPLAY_X, DISPLAY_Y);
    queue_evento = al_create_event_queue();
    al_register_event_source(queue_evento, al_get_display_event_source(dis));
    fuente = al_load_ttf_font("quicksand.otf", 16, 0);

    if(!fuente)
    {
        perror("Error fuente");
        exit(-3);
    }
}
void tituloVentana()
{
	al_set_window_title(dis, "Grafo automata - multiaportes.com");
}
void about(void)
{
    al_show_native_message_box(dis, "Acerca de", "Grafo automata", "Programa escrito por:\n\nOrtega Ortuno Eder\n\nwww.multiaportes.com", NULL, ALLEGRO_MESSAGEBOX_WARN);
}
void finalizar()
{
	al_destroy_event_queue(queue_evento);
    al_shutdown_font_addon();
    al_shutdown_primitives_addon();
    al_destroy_display(dis);
}
void colorearPantalla()
{
    al_clear_to_color(al_map_rgb_f(1.0, 1.0, 1.0));
    al_flip_display();
}
void estadoCualquiera(float x, float y, const char *q)
{
	al_draw_circle(x, y, 40.0, al_map_rgb_f(1.0, 0.0, 1.0), 0.0);
	al_draw_text(fuente, al_map_rgb_f(1.0, 0.0, 0.0), x-15.0, y-10.0, 0, q);
}
void estadoFinal(float x, float y, const char *q)
{
	estadoCualquiera(x, y, q);
	al_draw_circle(x, y, 50.0, al_map_rgb_f(1.0, 0.0, 1.0), 0.0);
}
void grafoDirigido(float x1, float y1, float x2, float y2, int flag, const char *msg)
{
	if(flag == 0)
	{
		al_draw_text(fuente, al_map_rgb_f(0.0, 0.0, 0.0), x1, y1-40, 0, msg);
		al_draw_arc(x1, y1, 20.0, 0.0, -3.0, al_map_rgb_f(0.0, 0.0, 0.0), 0.0);
		al_draw_filled_circle(x1-20.0, y1, 4.0, al_map_rgb_f(0.0, 0.0, 0.0));
	}
	else if(flag == 1)
	{
		al_draw_text(fuente, al_map_rgb_f(0.0, 0.0, 0.0), (x1+x2)/2, y1-20, 0, msg);
		al_draw_line(x1, y1, x2, y2, al_map_rgb_f(0.0, 0.0, 0.0), 0.0);
		al_draw_filled_circle(x2, y2, 4.0, al_map_rgb_f(0.0, 0.0, 0.0));
	}
	else if(flag == -1)
	{
		al_draw_text(fuente, al_map_rgb_f(0.0, 0.0, 0.0), (x1+x2)/2, y1-20, 0, msg);
		al_draw_line(x1, y1, x2, y2, al_map_rgb_f(0.0, 0.0, 0.0), 0.0);
		al_draw_filled_circle(x1, y1, 4.0, al_map_rgb_f(0.0, 0.0, 0.0));
	}
	else if(flag == 11)
	{
		al_draw_text(fuente, al_map_rgb_f(0.0, 0.0, 0.0), x1-20, (y1+y2)/2, 0, msg);
		al_draw_line(x1, y1, x2, y2, al_map_rgb_f(0.0, 0.0, 0.0), 0.0);
		al_draw_filled_circle(x2, y2, 4.0, al_map_rgb_f(0.0, 0.0, 0.0));
	}
	else if(flag == -11)
	{
		al_draw_text(fuente, al_map_rgb_f(0.0, 0.0, 0.0), x1-20, (y1+y2)/2, 0, msg);
		al_draw_line(x1, y1, x2, y2, al_map_rgb_f(0.0, 0.0, 0.0), 0.0);
		al_draw_filled_circle(x1, y1, 4.0, al_map_rgb_f(0.0, 0.0, 0.0));
	}
}