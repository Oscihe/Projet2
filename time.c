#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
int time( struct Goutte gouttes, struct Grille grilles, int number_case, double steadyflow_speed, struct GpsPoint point){
// Apres réflexion j'ai remarqué que pour normaliser la pente, on peut la considérer comme une valeur normalisée d'angle variant de [0,pi/2]
// Ainsi, slope_tot=tan(x*pi/2), en isolant x (l'angle), x=arctan(slope_tot)/pi/2
  int riviere_speed_factor=//???
  for (i=0;i<number_case;i++){
    if (grilles.riviere[i]==1){
      //faire attention de prendre en compte le signe des pentes.
      double pente_normalisée_x = ((-1)*atan(grilles[i].slope_x))/(M_PI/2);
      double pente_normalisée_y = ((-1)*atan(grilles[i].slope_y))/(M_PI/2);
      double distance_x = pente_normalisée_x*riviere_speed_factor*200;
      double distance_y = pente_normalisée_y*riviere_speed_factor*200;
      double time = distance
    // ici je rajoute 100, car on pose les gouttes entre 2 cases de malloc qui font 200 metres.
      double distance_tot_x = point.longitude[i] + 100 + distance_x;
      double distance_tot_y = point.latitude[i] + 100 + distance_y;
    }
    else{
      double distance_x = steadyflow_speed*pente_normalisée_x;
      double distance_y = steadyflow_speed*pente_normalisée_y;
    }
  }
}
