// Script Gmsh pour un domaine carré maillé en triangles

// 1. Définir le domaine carré
L = 1; // Longueur du côté du carré
Point(1) = {0, 0, 0, L/10};  // Point en (0, 0)
Point(2) = {L, 0, 0, L/10};  // Point en (1, 0)
Point(3) = {L, L, 0, L/10};  // Point en (1, 1)
Point(4) = {0, L, 0, L/10};  // Point en (0, 1)

// 2. Définir les lignes du contour du carré
Line(1) = {1, 2};  // Ligne entre les points 1 et 2
Line(2) = {2, 3};  // Ligne entre les points 2 et 3
Line(3) = {3, 4};  // Ligne entre les points 3 et 4
Line(4) = {4, 1};  // Ligne entre les points 4 et 1

// 3. Définir la boucle du contour
Line Loop(1) = {1, 2, 3, 4};

// 4. Définir la surface du domaine
Plane Surface(1) = {1};

// 5. Paramètres du maillage
Mesh.Algorithm = 6;  // Delaunay pour générer un maillage triangulaire
//Mesh.Format = 1;     // Utiliser le format MSH 2.2 pour une meilleure compatibilité
Mesh 2;
//gmsh square.geo -2 -format msh1