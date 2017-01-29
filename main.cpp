#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grille.hpp"


using namespace sf;
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(595, 595), "Reversi!");// 8*70+7*5

    for (int p=0;p<7;p++){
        sf::RectangleShape line1v(sf::Vector2f(5,600));
        line1v.setFillColor(sf::Color::Green);
        line1v.setPosition(70*(p+1)+p*5,0);
        sf::RectangleShape line1h(sf::Vector2f(600,5));
        line1h.setFillColor(sf::Color::Green);
        line1h.setPosition(0,70*(p+1)+p*5);
        window.draw(line1v);
        window.draw(line1h);
    }


    Grille grille;
    for (int i=0; i<8; i++){     //a revoir
        for (int j=0; j<8; j++){
            if ((i==3 && j==3) || (i==4 &&j==4)){
                grille.G[i][j].setCouleur(Color::Magenta);
            }
            if ((i==4 && j==3) || (i==3 &&j==4)){
                grille.G[i][j].setCouleur(Color::Blue);
            }

        }
    }
    for (int i=0; i<8; i++){     //a revoir
        for (int j=0; j<8; j++){
            sf::CircleShape cercle(25);
            cercle.setFillColor(grille.G[i][j].getCouleur());
            cercle.setPosition(11+i*70+5*i,11+70*j+5*j);
            window.draw(cercle);
        }
    }
    window.display();
    cout<<"on joue le Magenta"<<endl;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
              {  window.close();}

            if (event.type == (sf::Event::MouseButtonPressed))
            {
                window.clear();
                for (int p=0;p<7;p++){
                    sf::RectangleShape line1v(sf::Vector2f(5,600));
                    line1v.setFillColor(sf::Color::Green);
                    line1v.setPosition(70*(p+1)+p*5,0);
                    sf::RectangleShape line1h(sf::Vector2f(600,5));
                    line1h.setFillColor(sf::Color::Green);
                    line1h.setPosition(0,70*(p+1)+p*5);
                    window.draw(line1v);
                    window.draw(line1h);
                }

                int n;
                int m;
                for (int k=0;k<8;k++){
                         if ((event.mouseButton.button == sf::Mouse::Left) && (event.mouseButton.x<(70*(k+1)+5*k)&&event.mouseButton.x>(70*(k)+5*k)))
                            {m=k;}
                }
                for (int k=0;k<8;k++){
                         if ((event.mouseButton.button == sf::Mouse::Left)&&(event.mouseButton.y<(70*(k+1)+5*k)&&event.mouseButton.y>(70*(k)+5*k)))
                            {n=k;}
                }
                grille.effectuerTour(m,n);
                for (int i=0; i<8; i++){     //a revoir
                    for (int j=0; j<8; j++){
                            sf::CircleShape cercle(25);
                            cercle.setFillColor(grille.G[i][j].getCouleur());
                            cercle.setPosition(11+i*70+5*i,11+70*j+5*j);
                            window.draw(cercle);
                        }
                }
                window.display();


            }

        }
    }

    return 0;
}
