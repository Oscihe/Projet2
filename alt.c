#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
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

	if(atof(ligne) >= 592800.00 && atof(ligne) <= 600000.00 && atof(virgule1 + 1) >= 095200.00 && atof(virgule1 + 1) <= 103800.00){
		//Le compilateur ne comprend pas les deux conditions "<="
		point->latitude = atof(ligne);
		point->longitude = atof(virgule1 + 1);
		point->altitude = atof(virgule2 + 1);s

		printf("%f\n", point->longitude);
	}
    return 1;
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
        if (ok) n = n + 1;
    }

    // Fermer le fichier et renvoyer le nombre de lignes lues
    fclose(file);
    return n;
}

int main(int argc, char * argv[]) {
    // Lire le fichier
    struct GpsPoint * points = malloc(1628*sizeof(struct GpsPoint));
    int nbPoints = lireFichier("DHM200.xyz", points, 1628);

    if (nbPoints == -1) {
        printf("Erreur: Le fichier n'existe pas ou n'est pas accessible.\n");
        return 1;
    } else if (nbPoints == 0) {
        printf("Erreur: Le fichier est vide ou pas dans le bon format.\n");
        return 1;
    }
    printf("%f\n", points[0].altitude);

    return 0;
}
*/
