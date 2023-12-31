#include<allegro.h>
#include"personajes.h"
#include"disparos.h"
#include"diseno.h"

#define ANCHO 600
#define ALTO  600


void NAVE::inicia(char* ruta_nave, char* ruta_bala, int _ancho_b, int _alto_b,
                  int _ancho_p,int _alto_p,int _x,int _y,int _dir_bala,int _tipo,int _vida,int _max_disp){
     x=_x; y=_y;
     n_disp=0;
     max_disp=_max_disp;
     img_nav=load_bitmap(ruta_nave,NULL);
     img_bala=load_bitmap(ruta_bala,NULL);
     tick=0;
     ancho_b=_ancho_b;
     alto_b=_alto_b;
     ancho_p=_ancho_p;
     alto_p=_alto_p;
     dir_bala=_dir_bala;
     tipo=_tipo;
     vida=_vida;
     exp_enem=load_bitmap("Recursos/pum_enemigo.bmp",NULL);
     //game_over=load_bitmap("Recursos/game_over.bmp",NULL);
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
     if(vida>0)
     masked_blit(img_nav,buffer,ix*ancho_p,iy*alto_p,x,y,ancho_p,alto_p);
}


void NAVE::mueve(){
     if(key[KEY_LEFT]) x-=7;
     if(key[KEY_RIGHT]) x+=7;
}         


void NAVE::dispara(struct Balas disparos[], BITMAP* buffer){
         
         if(tipo && vida>0)
         crear_bala(n_disp,max_disp,disparos,x,y,dir_bala);
         pintar_bala(n_disp,max_disp,disparos,buffer,img_bala,ancho_b,alto_b);
         elimina_bala(n_disp,max_disp,disparos,ANCHO,ALTO);
};


void enemi(struct NAVE E[]){
     int indice=-1;
     int _tipo=0;
     for(int i=0;i<=4;i++){
             _tipo++;
             if(_tipo==4) _tipo=1;
             
     for(int j=0;j<=10;j++){
         indice++;
         E[indice].inicia("Recursos/enemigos.bmp","Recursos/Bala_enem.bmp",6,12,25,20,130+j*30,200+i*24,10,_tipo,1,2);
             
     }
     }
     }
     
void pint_ene(struct NAVE E[],BITMAP* buffer,int mov){
     int indice=-1;
     
     for(int i=0;i<=4;i++){
     for(int j=0;j<=10;j++){
         indice++;
         if(E[indice].vida>0)
         E[indice].pinta(buffer,mov,E[indice].tipo-1);
             
     }
     }
     }


void explo1(struct NAVE E,BITMAP* buffer){
     BITMAP* parche=create_bitmap(25,20);
     clear_to_color(parche,0x000000);
     blit(parche,buffer,0,0,E.x,E.y,25,20);
     masked_blit(E.exp_enem,buffer,0,0,E.x-10,E.y,41,34);
     rest(20);
     
}


void explo2(struct NAVE N,BITMAP* buffer,BITMAP* fondo){
     BITMAP* parche=create_bitmap(30,20);
     clear_to_color(parche,0x000000);
     for(int j=0;j<6;j++){
             for(int i=1;i<=2;i++){
     
     blit(parche,buffer,0,0,N.x,N.y,30,20);
     masked_blit(N.img_nav,buffer,i*30,0,N.x,N.y,30,20);
     imprimir_fondo(fondo,buffer);
     blit(buffer,screen,0,0,0,0,ANCHO,ALTO);
     rest(50);
             
             
             }
     }




}
/*

void iniciar_escudos(struct escudo muros []){
     int r=0;
     char pos_muros[3][22] = {
     "AEC AEC AEC AEC",
     "B D B D B D B D",
     };
     
     for(int i=0;i<21;i++){
     for(int j=0;j<2;j++){
     if(pos_muros[j][i] !=' '){
     muros[r].x=90+i*20;
     muros[r].y=450+j*15;
     muros[r].dan=0;
     if(pos_muros[j][i] == 'A') muros[r].tipo=0;
     if(pos_muros[j][i] == 'B') muros[r].tipo=1;
     if(pos_muros[j][i] == 'C') muros[r].tipo=2;
     if(pos_muros[j][i] == 'D') muros[r].tipo=3;
     if(pos_muros[j][i] == 'E') muros[r].tipo=4;
     r++;
     }
     
     }
}
}

void pintar_escudos(struct escudos ES[],BITMAP* img_mur,BITMAP* buffer){
for(int i=0;i<20;i++){
        if(ES[i].dan!=3)
        masket_blit(img_mur,buffer,ES[i]dan*20,ES[i].tipo*16,ES[i].x,ES[i].y,20,16);





}
*/


