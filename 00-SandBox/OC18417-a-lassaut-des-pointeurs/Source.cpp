#include <stdio.h>
#include <stdlib.h>
#include <iostream>

/* Je mets le prototype en haut. Comme c'est un tout
petit programme je ne le mets pas dans un .h, mais
en temps normal (dans un vrai programme), j'aurais placé
le prototype dans un fichier .h bien entendu */

int main(int argc, char* argv[]);

void afficheTableau(int  tableau[], int tailleTableau);

void triplePointeur(int* pointeurSurNombre);
void decoupeMinutes(int heures, int minutes);
void decoupeMinutesPointeurs(int* heures, int* minutes);
int sommeTableau(int tableau[], int tailleTableau);
double moyenneTableau(int tableau[], int tailleTableau);
void copie(int tableauOriginal[], int tableauCopie[], int tailleTableau);
void maximumTableau(int tableau[], int tailleTableau, int valeurMax);

void ordonnerTableau(int tableau[], int tailleTableau);
void ranger_croissant(int a, int b);
void trie_bull(int tableau[], int tailleTableau); 
void tri(int ptableau[], int tailleTableau);
void ordonnerTableauBySelectionSort(int tableau[], int tailleTableau);


int main(int argc, char* argv[])
{
    int heures = 0, minutes = 90;

    printf("La valeur de la variable minutes est : %d", minutes); //90
    printf("\n L'adresse de la variable minutes est : %p \n", &minutes); // 003AF850

    // création d'un pointeur
    int* monPointeur = NULL;
    monPointeur = &minutes;
    printf("\n La valeur de monPointeur vaut l'adresse de la variable minutes est : %p \n", monPointeur); // 003AF850
    printf("\n La valeur pointée par monPointeur est *monPointeur: %d \n", *monPointeur); // 90
    printf("\n L'adresse à laquelle se trouve monPointeur est &monPointeur: %p \n", &monPointeur); // 90

    // envoyer un pointeur à une fonction
    int nombre = 5;
    printf("\nAvant l'appel a triplePointeur, nombre vaut %d", nombre); //5
    triplePointeur(&nombre);
    printf("\nAprès l'appel a triplePointeur, nombre vaut %d", nombre); // 15



    /* On a une variable minutes qui vaut 90.
    Après appel de la fonction, je veux que ma variable
    "heures" vaille 1 et que ma variable "minutes" vaille 30 */

    //decoupeMinutes(heures, minutes);
    decoupeMinutesPointeurs(&heures, &minutes);

    printf("\n\n Apres l'appel a decoupeMinutesPointeurs ");
    printf("%d heures et %d minutes", heures, minutes);

    //tableaux
    printf("\n\n ************** Les tableaux ********************");
    //int tableau[4];

    //tableau[0] = 10;
    //tableau[1] = 23;
    //tableau[2] = 505;
    //tableau[3] = 8;
    int tableau[4] = { 10, 23, 505, 8 };

    printf("\nAdresse du tableau:%p ", tableau);
    printf("\nPremiere valeur du tableau:%d ou %d", *tableau, tableau[0]);

    afficheTableau(tableau, 4);

    printf("\nSomme des elements du tableau:%d ", sommeTableau(tableau, 4));

    printf("\nMoyenne des elements du tableau:%f ", moyenneTableau(tableau, 4));
    std::cout << "\nMoyenne des elements du tableau: " << moyenneTableau(tableau, 4) << std::endl;

    printf("\n***** Copie du du tableau original vers le tableau cible *****");
    int tableauCible[4];
    printf("\nAvant la copie ");
    afficheTableau(tableauCible, 4);
    copie(tableau, tableauCible, 4);
    printf("\nApres la copie ");
    afficheTableau(tableauCible, 4);

    printf("\n***** Mise a zero de toutes les valeurs superieures a un maximum *****");
    printf("\nAvant la fonction ");
    afficheTableau(tableauCible, 4);
    maximumTableau(tableauCible, 4, 100);
    printf("\nApres la fonction ");
    afficheTableau(tableauCible, 4);

    printf("\n***** Ordonner les element d'un tableau *****");
    printf("\nAvant la fonction ");
    afficheTableau(tableauCible, 4);
    //ordonnerTableau(tableauCible, 4); // bubble sort
    ordonnerTableauBySelectionSort(tableauCible, 4);
    //trie_bull(tableauCible, 4);
    //tri(tableauCible, 4);
    printf("\nApres la fonction ");
    afficheTableau(tableauCible, 4);

    return 0;
}

void afficheTableau(int tableau[], int tailleTableau)
{
    for (size_t i = 0; i < tailleTableau; i++)
    {
        printf("\nValeur du tableau[%d]= %d", i, *(tableau + i));
    }
}

void afficheTableau(int  tableau[4])
{
    for (size_t i = 0; i < 4.; i++)
    {
        printf("\nValeur du tableau[%d]= %d", i, *(tableau + i));
    }
}

void triplePointeur(int* pointeurSurNombre)
{
    *pointeurSurNombre *= 3;
}

void decoupeMinutes(int heures, int minutes)
{
    heures = minutes / 60;  // 90 / 60 = 1
    minutes = minutes % 60; // 90 % 60 = 30
}

void decoupeMinutesPointeurs(int* heures, int* minutes)
{
    *heures = *minutes / 60;  // 90 / 60 = 1
    *minutes = *minutes % 60; // 90 % 60 = 30
}

int sommeTableau(int tableau[], int tailleTableau)
{
    int result = 0;
    for (size_t i = 0; i < tailleTableau; i++)
    {
        //result = result + tableau[i];
        result = result + *(tableau + i);
    }
    return result;
}

double moyenneTableau(int tableau[], int tailleTableau)
{
    double result = 0.0;
    result = sommeTableau(tableau, tailleTableau) / tailleTableau;
    return result;
}

void copie(int tableauOriginal[], int tableauCopie[], int tailleTableau)
{
    for (size_t i = 0; i < tailleTableau; i++)
    {
        *(tableauCopie + i) = *(tableauOriginal + i);
    }
}

void maximumTableau(int tableau[], int tailleTableau, int valeurMax)
{
    for (size_t i = 0; i < tailleTableau; i++)
    {
        if (*(tableau + i) < valeurMax)
        {
            //
        }
        else
        {
            *(tableau + i) = 0;
        }
    }
}

/// <summary>
/// bubble sort https://www.educba.com/sorting-in-c/
/// </summary>
/// <param name="tableau"></param>
/// <param name="tailleTableau"></param>
void ordonnerTableau(int tableau[], int tailleTableau)
{
    int counter, counter1, swap_var;
    for (counter = 0; counter < tailleTableau - 1; counter++)
    {
        for (counter1 = 0; counter1 < tailleTableau - counter - 1; counter1++)
        {
            if (tableau[counter1] > tableau[counter1 + 1]) /* For decreasing order use < */
            {
                swap_var = tableau[counter1];
                tableau[counter1] = tableau[counter1 + 1];
                tableau[counter1 + 1] = swap_var;
            }
        }
    }
}

/// <summary>
/// selection sort https://www.educba.com/sorting-in-c/
/// </summary>
/// <param name="tableau"></param>
/// <param name="tailleTableau"></param>
void ordonnerTableauBySelectionSort(int tableau[], int tailleTableau)
{
    int counter1, counter2, minimum, temp_value;
    for (counter1 = 0; counter1 < tailleTableau - 1; counter1++)
    {
        minimum = counter1;
        for (counter2 = counter1 + 1; counter2 < tailleTableau; counter2++)
        {
            if (tableau[minimum] > tableau[counter2])
                minimum = counter2;
        }
        if (minimum != counter1)
        {
            temp_value = tableau[counter1];
            tableau[counter1] = tableau[minimum];
            tableau[minimum] = temp_value;
        }
    }
}

void ranger_croissant(int a, int b)
{
    int aux;
    if (a > b)
    {
        aux = b;
        b = a;
        a = b;
    }
}

void trie_bull(int tableau[], int tailleTableau)
{
    int j, i;
    j = tailleTableau - 1;
    do
    {
        for (i = 0; i < j; i++)
        {
            ranger_croissant(tableau[i], tableau[i + 1]);
        }
        j--;
    } while (j >= 0);
    for (i = 0; i < tailleTableau; i++)
    {
        printf("\n \t %d", tableau[i]);
    }
}

void tri(int ptableau[], int tailleTableau) 
{
    int* debut = ptableau;
    int* precedent = ptableau;
    int temp;
    for (; ptableau - debut < tailleTableau; precedent = (++ptableau)) 
    {
        if (*ptableau < *(ptableau - 1)) 
        {
            for (; precedent > debut; precedent--) 
            {
                if (*precedent < *(precedent - 1)) 
                {
                    temp = *precedent;
                    *precedent = *(precedent - 1);
                    *(precedent - 1) = temp;
                }
                else 
                {
                    break;
                }
            }
        }
    }
}
