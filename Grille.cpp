#include "Grille.hpp"
#include <iostream>
using namespace std;

//Case Grille :: getG(){
 //   return G ;}
void Grille :: setCouleurjouee(Color c){
    couleurjouee=c;
}
Color Grille :: getCouleurjouee(){
    return couleurjouee;
}

int trouverLigne(int x){
    for (int i=0;i<8;i++){
            int a=i*(70+5);
        if (x>a && x<a+75){
            return i;
        }
    }
}
int trouverColonne(int y){
    for (int j=0;j<8;j++){
            int b=j*(70+5);
        if (y>b && y<b+75){
            return j;
        }
    }
}

void Grille :: effectuerTour(int i, int j){
    int L[8]; //on crée une liste de taille 8 qui contient les infos sur les axes à explorer
    for (int k=0;k<8;k++){
        L[k]=1;
    } //on remplit cette liste de 1

    // on va regarder les états des cases qui entourent la case sur laquelle on a cliqué ; si la case est vide ou de la même couleur que celle que l'on joue, cela ne sert à rien d'explorer l'axe et on passe donc à 0 l'emplacement de L correspondant
    // L[0] correspond à l'axe vertical montant, L[1] à l'axe diagonal montant droit, etc. en faisant le tour dans le sens des aiguilles d'une montre
    // pour chaque case, on commence par un if qui permet de vérifier si la case observée existe ou pas (ie si on sort de la grille ou pas)

    if (j-1<0){L[0]=0;}
    if (j+1>7){L[4]=0;}
    if (i-1<0){L[6]=0;}
    if (i+1>7){L[3]=0;}

    if (G[i][j-1].getCouleur() == Color::Black || G[i][j-1].getCouleur() == couleurjouee){ //si la case est vide ou bien si elle est de la même couleur que celle que l'on joue
        L[0]=0; // alors on va pas explorer l'axe qui va par là
    }

    // on regarde la case en diagonale montante droite
    if (G[i+1][j-1].getCouleur() == Color::Black || G[i+1][j-1].getCouleur() == couleurjouee){
        L[1]=0;
    }

    // on regarde la case à droite
    if (G[i+1][j].getCouleur() == Color::Black || G[i+1][j].getCouleur() == couleurjouee){
        L[2]=0;
    }
    // on regarde la case en diagonale descendante droite
    if (G[i+1][j+1].getCouleur() == Color::Black || G[i+1][j+1].getCouleur() == couleurjouee){
        L[3]=0;
    }

    // on regarde la case en dessous
    if (G[i][j+1].getCouleur() == Color::Black || G[i][j+1].getCouleur() == couleurjouee){
        L[4]=0;
    }

    // on regarde la case en diagonale descendante gauche
    if (G[i-1][j+1].getCouleur() == Color::Black || G[i-1][j+1].getCouleur() == couleurjouee){
        L[5]=0;
    }

    // on regarde la case à gauche
    if (G[i-1][j].getCouleur() == Color::Black || G[i-1][j].getCouleur() == couleurjouee){
        L[6]=0;
    }

    // on regarde la case en diagonale montante gauche
    if (G[i-1][j-1].getCouleur() == Color::Black || G[i-1][j-1].getCouleur() == couleurjouee){
        L[7]=0;
    }
   /////////////////////////////////////////////////////////////////////////////////BLOC 2
    int k=0;
    while (k<8){ //on parcourt la liste L pour explorer successivement les axes
        if (L[k]==0){ //si l'élément k de la liste L est nul
            k=k+1; //alors on explore pas l'axe et on passe au suivant
        }

        else{ //sinon alors on doit explorer l'axe
            if(k==0){ //si il s'agit du premier élément, on explore l'axe vertical montant
                int jcourant = j-1; //initialisation de jcourant
                int n=0; //initialisation du compteur n
                while (L[k]==1){ //tant qu'on considère que l'axe peut encore apporter retournement
                    if (jcourant<0 || G[i][jcourant].getCouleur()==Color::Black){ //si on a atteint le bord de la grille sans avoir trouvé de case vide ou de couleur opposée
                        L[k]=0;//alors on arrête d'observer cet axe et on sort de la boucle while
                        n=0;
                        cout<<"Impossible de jouer ici !"<<endl;
                    }
                    else if (G[i][jcourant].getCouleur()==couleurjouee){ //si la case comparée est de la même couleur ou vide
                        L[k]=0; //il devient inutile d'observer plus loin, donc on sort de la boucle while
                    }
                    else { //sinon si la case comparée est de l'autre couleur
                        jcourant = jcourant-1; //on continue à explorer plus loin dans l'axe
                        n=n+1; //on rajoute une case à retourner au compteur
                    }
                }

                for(int m=1;m<=n;m++){
                    G[i][j-m].setCouleur(couleurjouee);
                    G[i][j].setCouleur(couleurjouee);
                }

                k=k+1; //on passe à l'axe suivant
            }


            else if(k==1){ //axe diagonal montant droit
                int icourant = i+1; //initialisation de icourant
                int jcourant = j-1;
                int n=0; //initialisation du compteur n
                while (L[k]==1){ //tant qu'on considère que l'axe peut encore apporter retournement
                    if (icourant>7 || jcourant<0 || G[icourant][jcourant].getCouleur()==Color::Black){ //si on a atteint le bord de la grille sans avoir trouvé de case vide ou de couleur opposée
                        L[k]=0;//alors on arrête d'observer cet axe et on sort de la boucle while
                        n=0;
                        cout<<"Impossible de jouer ici !"<<endl;
                    }
                    else if (G[icourant][jcourant].getCouleur()==couleurjouee){ //si la case comparée est de la même couleur ou vide
                        L[k]=0; //il devient inutile d'observer plus loin, donc on sort de la boucle while
                    }
                    else { //sinon si la case comparée est de l'autre couleur
                        icourant = icourant+1;
                        jcourant = jcourant-1; //on continue à explorer plus loin dans l'axe
                        n=n+1; //on rajoute une case à retourner au compteur
                    }
                }

                for(int m=1;m<=n;m++){
                    G[i+m][j-m].setCouleur(couleurjouee);
                    G[i][j].setCouleur(couleurjouee);
                }

                k=k+1; //on passe à l'axe suivant
            }

            else if(k==2){ //axe horizontal droit
                int icourant = i+1; //initialisation de icourant
                int n=0; //initialisation du compteur n
                while (L[k]==1){ //tant qu'on considère que l'axe peut encore apporter retournement
                    if (icourant>7 || G[icourant][j].getCouleur()==Color::Black){ //si on a atteint le bord de la grille sans avoir trouvé de case vide ou de couleur opposée
                        L[k]=0;//alors on arrête d'observer cet axe et on sort de la boucle while
                        n=0;
                        cout<<"Impossible de jouer ici !"<<endl;
                    }
                    else if (G[icourant][j].getCouleur()==couleurjouee){ //si la case comparée est de la même couleur ou vide
                        L[k]=0; //il devient inutile d'observer plus loin, donc on sort de la boucle while
                    }
                    else { //sinon si la case comparée est de l'autre couleur
                        icourant = icourant+1; //on continue à explorer plus loin dans l'axe
                        n=n+1; //on rajoute une case à retourner au compteur
                    }
                }

                for(int m=1;m<=n;m++){
                    G[i+m][j].setCouleur(couleurjouee);
                    G[i][j].setCouleur(couleurjouee);
                }

                k=k+1; //on passe à l'axe suivant
            }

            else if(k==3){ //axe diagonal descendant droit
                int icourant = i+1; //initialisation de icourant
                int jcourant = j+1;
                int n=0; //initialisation du compteur n
                while (L[k]==1){ //tant qu'on considère que l'axe peut encore apporter retournement
                    if (icourant>7 || jcourant>7 || G[icourant][jcourant].getCouleur()==Color::Black){ //si on a atteint le bord de la grille sans avoir trouvé de case vide ou de couleur opposée
                        L[k]=0;//alors on arrête d'observer cet axe et on sort de la boucle while
                        n=0;
                        cout<<"Impossible de jouer ici !"<<endl;
                    }
                    else if (G[icourant][jcourant].getCouleur()==couleurjouee){ //si la case comparée est de la même couleur ou vide
                        L[k]=0; //il devient inutile d'observer plus loin, donc on sort de la boucle while
                    }
                    else { //sinon si la case comparée est de l'autre couleur
                        icourant = icourant+1;
                        jcourant = jcourant+1; //on continue à explorer plus loin dans l'axe
                        n=n+1; //on rajoute une case à retourner au compteur
                    }
                }

                for(int m=1;m<=n;m++){
                    G[i+m][j+m].setCouleur(couleurjouee);
                    G[i][j].setCouleur(couleurjouee);
                }

                k=k+1; //on passe à l'axe suivant
            }

            else if(k==4){ //axe vertical descendant
                int jcourant = j+1; //initialisation de jcourant
                int n=0; //initialisation du compteur n
                while (L[k]==1){ //tant qu'on considère que l'axe peut encore apporter retournement
                    if (jcourant>7 || G[i][jcourant].getCouleur()==Color::Black){ //si on a atteint le bord de la grille sans avoir trouvé de case vide ou de couleur opposée
                        L[k]=0;//alors on arrête d'observer cet axe et on sort de la boucle while
                        n=0;
                        cout<<"Impossible de jouer ici !"<<endl;
                    }
                    else if (G[i][jcourant].getCouleur()==couleurjouee){ //si la case comparée est de la même couleur ou vide
                        L[k]=0; //il devient inutile d'observer plus loin, donc on sort de la boucle while
                    }
                    else { //sinon si la case comparée est de l'autre couleur
                        jcourant = jcourant+1; //on continue à explorer plus loin dans l'axe
                        n=n+1; //on rajoute une case à retourner au compteur
                    }
                }

                for(int m=1;m<=n;m++){
                    G[i][j+m].setCouleur(couleurjouee);
                    G[i][j].setCouleur(couleurjouee);
                }

                k=k+1; //on passe à l'axe suivant
            }

            else if(k==5){ //axe diagonal descendant gauche
                int icourant = i-1; //initialisation de icourant
                int jcourant = j+1;
                int n=0; //initialisation du compteur n
                while (L[k]==1){ //tant qu'on considère que l'axe peut encore apporter retournement
                    if (icourant<0 || jcourant>7 || G[icourant][jcourant].getCouleur()==Color::Black){ //si on a atteint le bord de la grille sans avoir trouvé de case vide ou de couleur opposée
                        L[k]=0;//alors on arrête d'observer cet axe et on sort de la boucle while
                        n=0;
                        cout<<"Impossible de jouer ici !"<<endl;
                    }
                    else if (G[icourant][jcourant].getCouleur()==couleurjouee){ //si la case comparée est de la même couleur ou vide
                        L[k]=0; //il devient inutile d'observer plus loin, donc on sort de la boucle while
                    }
                    else { //sinon si la case comparée est de l'autre couleur
                        icourant = icourant-1;
                        jcourant = jcourant+1; //on continue à explorer plus loin dans l'axe
                        n=n+1; //on rajoute une case à retourner au compteur
                    }
                }

                for(int m=1;m<=n;m++){
                    G[i-m][j+m].setCouleur(couleurjouee);
                    G[i][j].setCouleur(couleurjouee);
                }

                k=k+1; //on passe à l'axe suivant
            }

            else if(k==6){ //axe horizontal gauche
                int icourant = i-1; //initialisation de icourant
                int n=0; //initialisation du compteur n
                while (L[k]==1){ //tant qu'on considère que l'axe peut encore apporter retournement
                    if (icourant<0 || G[icourant][j].getCouleur()==Color::Black){ //si on a atteint le bord de la grille sans avoir trouvé de case vide ou de couleur opposée
                        L[k]=0;//alors on arrête d'observer cet axe et on sort de la boucle while
                        n=0;
                        cout<<"Impossible de jouer ici !"<<endl;
                    }
                    else if (G[icourant][j].getCouleur()==couleurjouee){ //si la case comparée est de la même couleur ou vide
                        L[k]=0; //il devient inutile d'observer plus loin, donc on sort de la boucle while
                    }
                    else { //sinon si la case comparée est de l'autre couleur
                        icourant = icourant-1; //on continue à explorer plus loin dans l'axe
                        n=n+1; //on rajoute une case à retourner au compteur
                    }
                }

                for(int m=1;m<=n;m++){
                    G[i-m][j].setCouleur(couleurjouee);
                    G[i][j].setCouleur(couleurjouee);
                }

                k=k+1; //on passe à l'axe suivant
            }

            else if(k==7){ //axe diagonal montant gauche
                int icourant = i-1; //initialisation de icourant
                int jcourant = j-1;
                int n=0; //initialisation du compteur n
                while (L[k]==1){ //tant qu'on considère que l'axe peut encore apporter retournement
                    if (icourant<0 || jcourant<0 || G[icourant][jcourant].getCouleur()==Color::Black){ //si on a atteint le bord de la grille sans avoir trouvé de case vide ou de couleur opposée
                        L[k]=0;//alors on arrête d'observer cet axe et on sort de la boucle while
                        n=0;
                        cout<<"Impossible de jouer ici !"<<endl;
                    }
                    else if (G[icourant][jcourant].getCouleur()==couleurjouee){ //si la case comparée est de la même couleur ou vide
                        L[k]=0; //il devient inutile d'observer plus loin, donc on sort de la boucle while
                    }
                    else { //sinon si la case comparée est de l'autre couleur
                        icourant = icourant-1;
                        jcourant = jcourant-1; //on continue à explorer plus loin dans l'axe
                        n=n+1; //on rajoute une case à retourner au compteur
                    }
                }

                for(int m=1;m<=n;m++){
                    G[i-m][j-m].setCouleur(couleurjouee);
                    G[i][j].setCouleur(couleurjouee);
                }


                k=k+1; //on passe à l'axe suivant
            }

        }
    }
    if (couleurjouee==Color::Blue){
        couleurjouee=Color::Magenta;
        cout<<"on joue mntnt le magenta"<<endl;
    }
    else if (couleurjouee==Color::Magenta){
        couleurjouee=Color::Blue;
        cout<<"on joue mntnt le bleu"<<endl;
    }
}

Grille::Grille(){
    couleurjouee=Color::Magenta;


}
