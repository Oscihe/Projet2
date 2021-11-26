import numpy as np
"""
#Copier-coller d'une partie du code de l'exercice Suisse:
# Lire le fichier
print('Lecture du fichier')
dhm200 = np.genfromtxt('DHM200.xyz', delimiter = ' ', dtype = None)

# Transformer les colonnes (x, y, h) en tableau
print('Transformation')
x = dhm200[:, 0]
y = dhm200[:, 1]
h = dhm200[:, 2]

xMin = np.min(x)
yMin = np.min(y)
xIndex = (x - xMin) / 200
yIndex = (y - yMin) / 200
xIndexInt = xIndex.astype('int32')
yIndexInt = yIndex.astype('int32')
xCount = xIndexInt.max() + 1
yCount = yIndexInt.max() + 1
xp = xMin + np.arange(0, xCount) * 200
yp = yMin + np.arange(0, yCount) * 200

altitudes = np.zeros((yCount, xCount))
altitudes[yIndexInt, xIndexInt] = h

#Toutes les coordonnées réelles x (dans toute la Suisse) sont les xp
#toutes les coordonnées réelles y (dans toute la Suisse) sont les yp

x_list = []
for i in range(0, len(xp)):
    if 592800.00 <= xp[i] <= 600000.00:
        x_list.append(i)

y_list = []
for i in range(0, len(yp)):
    if 095200.00 <= yp[i] <= 103800.00:
        y_list.append(i)

print(len(dhm200))
"""
"""
alt_list = []
for i in range(0, len(h)):

#faire en c : un malloc avec les points et comme terrain
"""
"""
#le document contient toutes les altitudes en Suisse, dans des carrés de 200x200 m
print("Lecture du document")
dhm200 = np.genfromtxt('DHM200.xyz', delimiter = ' ', dtype = None)

#Prendre que les données qui sont dans notre zones autour de la Grande Dixence:
#la zone rectangulaire (autour du Lac des Dix) que l'on considère est entre ces coordonnées :
#limite Nord-Ouest : 2'600'002.7, 1'095'486.2
#Limite Nord-Est : 2'600'002.7, 1'095'298.2
#Limite Sud-Est : 2'593'045.2, 1'095'298.2
#Limite Sud-Ouest : 2'593'045.2, 1'095'486.2

#Essais :

x_tout = dhm200[:, 0]
y_tout = dhm200[:, 1]
alt_tout = dhm200[:, 2]

x_list = []
y_list = []
for i in range(0, len(x_tout)):
    if 593000.00 <= x_tout[i] <= 600000.00:
        x_list.append(i)

for i in range(0, len(y_tout)):
    if 593000.00 <= y_tout[i] <= 600000.00:
        xylist.append(i)

x = np.array(x_list)
#y = np.array(y_list)

#comme dans l'exercice Suisse :
xmin = np.min(x)
#ymin = np.min(y)

index_x = (x-xmin)/200
#index_y = (y-ymin)/200



taille_x = int(np.max(index_x))+1
#taille_y = int(np.max(index_y))+1

print(f"{index_x}")
"""
"""
altitudes = np.zeros((taille_y, taille_x))

altitudes[(index_y.astype('int32')), (index_x.astype('int32'))] = alt
"""


"""
indices_x = []
indices_y = []
for i in range(0, len(coordx_tout)):
    if 593045.2 <= coordx_tout[i] <= 600002.7:
        indices_x.append(i)

for i in range(0, len(coordy_tout)):
    if 095298.2 <= coordy_tout[i] <= 095486.2:
        indices_y.append(i)

indice_xmin = np.min(indices_x)
indice_ymin = np.min(indices_y)

#On initialise les indices du tableau initial pour avoir les indices du tableau de notre zone:
x_tabl = []
y_tabl = []
for i in range(0, len(indices_x)):
    x_tabl.append((indices_x[i]-indice_xmin))
for i in range(0, len(indices_y)):
    y_tabl.append((indices_y[i]-indice_ymin))


#print(f"{indices_x}\n\n")
#x_tabl_tri = x_tabl.sort()
print(f"{coordx_tout}")
"""
