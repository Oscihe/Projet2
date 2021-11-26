#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
//Voir comment importer d'autres fichiers c dans celui là
//#include "barrage.c"

//Ce fichier contient la fonction main pour tout notre projet
//Nous importons les autres fichiers c (contenant toutes les fonctions, structures, ...)

//coord et alt de chaque case
struct GpsPoint {
 double latitude;
 double longitude;
 float altitude;
};

//Pour les gouttes qui vont dans le lac, avec le temps qu'elles mettent jusqu'au lac
struct Goutte{
  double x;
  double y;
  double time;
};

//caractéristiques de chaque case
struct Grille {
 int lac;
 int catch;
 double slope_x;
 double slope_y;
 //temps par case?
};
struct Grilles grilles[1628];
int main(int argc, char * argv[]) {

  return 0;
}
