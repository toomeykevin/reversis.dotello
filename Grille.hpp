#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>
#include "Case.hpp"

using namespace sf;

class Grille{

    private :

        Color couleurjouee;
    public :
        Case G[8][8];
        Case getG();
        void setCouleurjouee(Color);
        Color getCouleurjouee();

        int trouverLigne(int);
        int trouverColonne(int);
        void effectuerTour(int, int);

        Grille();


};
