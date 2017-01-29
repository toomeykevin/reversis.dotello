#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>

using namespace sf;

class Case{

    private :
        Color couleur;
    public :
        void setCouleur(Color);
        Color getCouleur();

        Case(Color couleur=Color::Black);


};
