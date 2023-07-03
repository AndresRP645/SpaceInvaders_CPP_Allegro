#include<allegro.h>
#ifndef PERSONAJES_H_INCLUDED
#define PERSONAJES_H_INCLUDED


struct NAVE{
       int x,y;
       int n_disp;
       int max_disp;
       int tick;
       int ancho_b, alto_b;
       int ancho_p, alto_p;
       int dir_bala;
       int tipo;
       int vida;
       
       BITMAP* img_nav;
       BITMAP* img_bala;
       BITMAP* exp_enem;
       BITMAP* game_over;
       
         
       
void inicia(char* ruta_nave, char* ruta_bala,int _ancho_b, int  _alto_b,
int _ancho_p, int _alto_p,int _x,int _y,int _dir_bala,int _tipo,int _vida,int _max_disp);

bool tempo(int tiempo);
void pinta (BITMAP* buffer,int xi,int yi);
void mueve ();
void dispara(struct Balas disparos[], BITMAP* buffer);

};

void enemi(struct NAVE E[]);
void pint_ene(struct NAVE E[],BITMAP* buffer,int mov);
void explo1(struct NAVE E,BITMAP* buffer);
void explo2(struct NAVE N,BITMAP* buffer,BITMAP* fondo);

struct escudos{
int x,y;
int dan;
int tipo;
};

//void iniciar_escudos(struct escudo muros []);
//void pintar_escudos(struct escudos ES[],BITMAP* img_mur,BITMAP* buffer);


#endif // PERSONAJES_H_INCLUDED
