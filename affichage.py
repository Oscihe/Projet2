#Affichage du terrain
import csv
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.colors import LightSource
from matplotlib import cm

#Lecture du fichier

print("Lecture du fichier")
terrain = np.genfromtxt('altitudes.csv', delimiter = ',', dtype = None)
#chaque case du tableau contient l'altitude

coord_x_inv = []
for i in range(0, len(terrain[0, :])):
    coord_x_inv.append(i*200)
    #chaque case est en réalité espacée de 200m

coord_x = list(reversed(coord_x_inv))

#idem pour les coordonnées y :
coord_y = []
for i in range(len(terrain[:, 0])):
    coord_y.append(i*200)

#je crée un tableau avec les coordonnées x de chaque case
x = np.zeros((len(coord_y), len(coord_x)))
for i in range(0, len(coord_y)):
    x[i, :]=coord_x

#je crée un tableau avec les coordonnées y de chaque case
y = np.zeros((len(coord_y), len(coord_x)))
for i in range(0, len(coord_x)):
    y[:, i]=coord_y

alt_min = np.min(terrain)
alt_max = np.max(terrain)
coord_z = np.linspace(alt_min, alt_max)
#donc les altitudes vont de alt_min à alt_max

#pour afficher le terrain en 3D, j'utilise la fonction plot_surface
#Graphique de la zone considérée
fig, ax = plt.subplots(subplot_kw=dict(projection='3d'))
ls = LightSource(270, 45)
rgb = ls.shade(terrain, cmap=cm.gist_earth, vert_exag=0.1, blend_mode='soft')
surf = ax.plot_surface(x, y, terrain, rstride=1, cstride=1, facecolors=rgb, linewidth=0, antialiased=False, shade=False)
plt.show()
#L'axe des x est inversé (le 0 devrait se trouver à l'opposé), mais les altitudes se trouvent au bon endroit sur le graphe
