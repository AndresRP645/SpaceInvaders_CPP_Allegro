#include "disparos.h"
#include <allegro.h>

bool coli(int x1,int y1,int w1,int h1,
          int x2,int y2,int w2,int h2){

return((x1<x2+w2) && (x2<x1-w1) && (y1<y2+h2) && (y2<y1+h1));



}    





void crear_bala(int& n_disparos, const int max_disparos ,struct Balas disparos[] ,
                const int X, const int Y , const int dy)
{

              if( n_disparos < max_disparos-1){ // n -1 disparos permitidos
                   n_disparos++;

                   disparos[n_disparos].x  = X+11;
                   disparos[n_disparos].y  = Y;
                   disparos[n_disparos].dx = 0;
                   disparos[n_disparos].dy = dy;
               }

}

void pintar_bala(int& n_disparos, const int max_disparos,struct Balas disparos[],
                 BITMAP* buffer, BITMAP* bala, int ancho, int alto)
{

     if ( n_disparos > 0 && n_disparos < max_disparos){
            for ( int cont = 1; cont <= n_disparos; cont++){
                       disparos[cont].x += disparos[cont].dx;
                       disparos[cont].y += disparos[cont].dy;
                       masked_blit( bala, buffer, 0, 0, disparos[cont].x, disparos[cont].y, ancho, alto);
            }
     }

}




             

     


void elimina_bala(int& n_disparos, const int max_disparos,struct Balas disparos[],
                  const int ANCHO, const int ALTO)
{
Balas Btemp;
      
      if ( n_disparos > 0 && n_disparos < max_disparos){
           
            for ( int cont = 1; cont <= n_disparos; cont++){
                
                      if ( disparos[cont].y > ALTO || disparos[cont].y < 0 ||
                           disparos[cont].x > ANCHO|| disparos[cont].x < 0  ){
                           
                            Btemp = disparos[cont];
              disparos[cont] = disparos[n_disparos];
              disparos[n_disparos] = Btemp;
              n_disparos--;
              if ( n_disparos < 0 ) n_disparos=0;
                           
                       

                       }
            }
      }


}


//void elimina_bala_objeto(struct NAVE& N,struct NAVE& E,struct Balas[]){
     

     
     
     
     
     
     
     
     
    //           }

