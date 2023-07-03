#include<allegro.h>
#include<stdlib.h>
#include<time.h>
#include"inicia.h"
#include"disparos.h"
//#include"ini.h"
//#include"dispa.h"

#define ANCHO 600
#define ALTO  600

struct NAVE{
       int x,y;
       int n_disp;
       int max_disp;
       int tick;
       int ancho_b, alto_b;
       int ancho_p, alto_p;
       int dir_bala;
       int tipo;
       
       BITMAP* img_nav;
       BITMAP* img_bala;
       
void inicia(char* ruta_nave, char* ruta_bala,int _ancho_b, int  _alto_b,
int _ancho_p, int _alto_p,int _x,int _y,int _dir_bala,int _tipo);

bool tempo(int tiempo);
void pinta (BITMAP* buffer,int xi,int yi);
void mueve ();
void dispara(struct Balas disparos[], BITMAP* buffer);


};

void NAVE::inicia(char* ruta_nave, char* ruta_bala, int _ancho_b, int _alto_b,
                  int _ancho_p,int _alto_p,int _x,int _y,int _dir_bala,int _tipo){
     x=_x; y=_y;
     n_disp=0; max_disp=2;
     img_nav=load_bitmap(ruta_nave,NULL);
     img_bala=load_bitmap(ruta_bala,NULL);
     tick=0;
     ancho_b=_ancho_b;
     alto_b=_alto_b;
     ancho_p=_ancho_p;
     alto_p=_alto_p;
     dir_bala=_dir_bala;
     tipo=_tipo;
};


bool NAVE::tempo(int tiempo){
     tick++;
     if(tick==tiempo){
        tick=0;
        return true;
        }
        return false;

};



void NAVE::pinta(BITMAP* buffer,int ix,int iy){
     masked_blit(img_nav,buffer,ix*ancho_p,iy*alto_p,x,y,ancho_p,alto_p);
};


void NAVE::mueve(){
     if(key[KEY_LEFT]) x-=7;
     if(key[KEY_RIGHT]) x+=7;
};         


void NAVE::dispara(struct Balas disparos[], BITMAP* buffer){
         
         if(tipo)
         crear_bala(n_disp,max_disp,disparos,x,y,dir_bala);
         pintar_bala(n_disp,max_disp,disparos,buffer,img_bala,ancho_b,alto_b);
         elimina_bala(n_disp,max_disp,disparos,ANCHO,ALTO);
};
