#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// Structure
struct GpsPoint {
 double latitude;
 double longitude;
 float altitude;
};

// Lire une ligne et remplir la structure
int lireLigne(char * ligne, struct GpsPoint * point) {
 char * virgule1 = strchr(ligne, ' ');
 if (virgule1 == NULL) return 0;
 char * virgule2 = strchr(virgule1 + 1, ' ');
 if (virgule2 == NULL) return 0;
 double v1=atof(ligne);
 double v2=atof(virgule1+1);
 double v3=atof(virgule2+1);
 if(v1 >= 592800.00 && v1 <= 600000.00 && v2 >= 095200.00 && v2 <= 103800.00){
  point->latitude = v1;
  point->longitude = v2;
  point->altitude = v3;
  //printf("%f, %f, %f\n",point->latitude,point->longitude,point->altitude);
  return 1;
 }
 return 0;
}

int lireFichier(char * nomFichier, struct GpsPoint * tableauARemplir, int longueur) {
 // Ouvrir le fichier
 FILE * file = fopen(nomFichier, "r");
 if (file == NULL) return -1;

 // Lire ligne par ligne
 int n = 0;
 char buffer[100];
 while (fgets(buffer, 100, file) != NULL) {
  if (n >= longueur) break;
  int ok = lireLigne(buffer, &tableauARemplir[n]);
  if (ok) {
   n = n + 1;
  }
 }

 // Fermer le fichier et renvoyer le nombre de lignes lues
 fclose(file);
 return n;
}
/*
bool writeCsv(char * filename, double * values, int sizeX, int sizeY) {
 FILE * file = fopen(filename, "w");
 if (file == NULL) {
  fprintf(stderr, "File %s not found.", filename);
  return false;
 }

 for (int y = 0; y < sizeY; y++) {
  for (int x = 0; x < sizeX; x++) {
   if (x > 0) fprintf(file, ", ");
   fprintf(file, "%f", values[y * sizeX + x]);
  }
  fprintf(file, "\n");
 }

 fclose(file);
 return true;
}
*/
struct Grille {
 double lat;
 double longi;
 double pluie;
 double alt;
 int lac;
 int catch;
 double time;
};

int indexing(int x,int y){
 int i=(103800-y)/200*37+(x-592800)/200;
 //printf("%d\n",i);
 return i;
}
void initialisation(double *malloc_hauteur,int compteur,double quantite_precip,double lac_lat_max,double lac_lat_min,double lac_long_min,double lac_long_max,struct Grille *grilles){
 //int lenxp=37;
 //int lenyp=44;
 //int total=lenxp*lenyp;
 for (int k=0;k<compteur;k++){
  grilles[k].longi=103800-200*(k/37);
  grilles[k].lat=592800+200*((37+k)%37);
  //x = latitude et y = longitude
  grilles[k].pluie=quantite_precip;
  grilles[k].alt=malloc_hauteur[k];
  //printf("%f\n",grilles[k].alt);
  //printf("%f, %f, %f\n",grilles[k].alt,grilles[k].lat,grilles[k].longi);

  //pour le moment, le if et le else font la même chose (mettre pluie à 1)
  //et on a déjà mis les grilles[compteur].pluie=quantite_precip...
  double c1 = grilles[k].longi;
  double c2 = grilles[k].lat;
  if (c1<lac_long_max && c1>lac_long_min && lac_lat_max>c2 && lac_lat_min<c2){
   grilles[k].pluie=1;
  }
  else{
   grilles[k].pluie=1;
  }
 }
}

double  accumulation (int compteur1,struct Grille *grilles) {
 //int z=indexing(grilles[compteur1].long,grilles[compteur1].lat)
 int pos_x=grilles[compteur1].lat;
 int pos_y=grilles[compteur1].longi;
 //x=latitude et y=longitude
 int y_min = 0;
 int x_min = 0;
 int h_min=0;
 while(pos_x!=592800||pos_y!=95200||pos_x!=600000||pos_y != 103800){
  //pas sûr que ce soit correct
  //printf("ok");
  //print que 1 ok
  for (int x= -200; x<7200; x=x+200){
    for (int y= -200; y<8600; y=y+200){
    //est-ce que les bornes sont ok ?!
    //il ne faudrait pas plutôt aller de "-200" à "+200" ?!
    //est-ce que c'est la bonne méthode ?! (car cf corr midterm)
      int i=indexing(pos_x+x,pos_y+y);
    //printf("%f\n",grilles[i].alt);
      if (h_min > grilles[i].alt){
     //printf("%s","hello");
      h_min = grilles[i].alt;
      x_min = grilles[i].lat;
      y_min = grilles[i].longi;
     //printf("%d",i);
     //printf("ok");
     //ça ne print pas "ok"
    }

    pos_x = x_min;
    pos_y = y_min;

    if (grilles[indexing(x_min,y_min)].lac==1){
     grilles[compteur1].catch=1;
     printf("%d\n",grilles[compteur1].catch);
     //printf("ok");
     //ne print pas
    }
   }
  }
  //pos_x = x_min;
  //pos_y = y_min;
 }
 //if
//(grilles[indexing(x_min,y_min)].lac==1){
  //grilles[compteur1].catch=1;
  //printf("%d\n",grilles[compteur1].catch);
  //printf("ok");
  //ne print pas et comme si boucle infinie...
 //}
// return 0;
//}
int main(int argc, char * argv[]) {
  struct Grille grilles[37*44];
  struct GpsPoint points[1628];
  int nbPoints = lireFichier("DHM200.xyz", points, 1628*sizeof(double));
  //printf("%d",nbPoints);
  if (nbPoints == -1) {
    printf("Erreur: Le fichier n'existe pas ou n'est pas accessible.\n");
    return 1;
   } else if (nbPoints == 0) {
    printf("Erreur: Le fichier est vide ou pas dans le bon format.\n");
    return 1;
   }
   double xmin = points[0].latitude;
   double ymax = points[0].longitude;
   for(int i=1; i<nbPoints; i++){
    if(points[i].latitude<xmin){
     xmin=points[i].latitude;
     //printf("ok");
     //ne print pas, normal car il s'agit déjà de xmin !
    }
   }
   for(int i=1; i<nbPoints; i++){
    //print = ok
    if(points[i].longitude>ymax){
     ymax=points[i].longitude;
     //printf("ok");
     //ne print pas, normal car il s'agit déjà de ymax !
    }
   }

   //Création du malloc contenant les altitudes :
   double * altitudes = malloc(1628*sizeof(double));
   for(int i=0; i<nbPoints; i++){
    altitudes[(((int) ymax- (int) points[i].longitude)/200)*37 + (((int) points[i].latitude- (int) xmin)/200)] = points[i].altitude;
   }

   //writeCsv("altitudes.csv", altitudes, 37, 44);

   free(altitudes);
   //Imprimer les valeurs des altitudes se trouvant dans le malloc
   /*
   printf("%d\n", nbPoints);
   for(int i=0; i<nbPoints; i++){
    //ça n'imprime pas l'altitude de la case 0 du malloc (ça mais 0m)... (alors qu'elle est dans le CSV...) -> ?
    printf("%f\n", altitudes[i]);
   }
   */

   //int lenxp=37;
   //int lenyp=44;
   //int total=lenxp*lenyp;
   double quantite=0;
   //struct Grille grilles[total];
   //for (int l=0;l<total;l++){
   initialisation(altitudes,1628,1,598000,597200,98000,103200,grilles);
   //latitude = x et longitude = y
  for(int m=0;m<1628;m++){
    printf("ok");
    //ça print que 1 ok...
    accumulation(m,grilles);
    //printf("ok");
    //ne print pas
    if (grilles[m].catch==1){
      quantite=quantite+grilles[m].pluie;
      printf("%f",quantite);
     //printf("ok");
     //ne print pas, surement car nous n'avons pas encore défini la zone du lac (=> "struct".lac = 1)
    }

   double volume_tot=quantite/1000*200;
   printf("Le volume totale d'eau est: %f",volume_tot);
   //printf("ok");
   //ne print pas
   return 0;
}
