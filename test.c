
// void flood_fill(char **map, int x, int y)
// {
//     if (map[y][x] == '1' || map[y][x] == 'V') // Si mur ou déjà visité, on arrête
//         return;

//     map[y][x] = 'V'; // Marquer la case comme visitée

//     // Appels récursifs dans les 4 directions
//     flood_fill(map, x + 1, y); // Droite
//     flood_fill(map, x - 1, y); // Gauche
//     flood_fill(map, x, y + 1); // Bas
//     flood_fill(map, x, y - 1); // Haut
// }