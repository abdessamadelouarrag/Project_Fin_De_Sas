#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct InfoDeJoueur{
    int id;
    char nom[100];
    char prenom[100];
    int numeroMaillot;
    char poste[100];
    int age;
    int buts;
};

struct InfoDeJoueur Joueurs[100];

int NombreDeJoueurs = 0;

void clearscreen(){
    system("cls || clear");
}

// fonction d'ajouter un joueur 

void AjouterUnJoueur(){

    clearscreen();

    int choixDePoste;

    printf("Entrer le nom de joueur :\n");
    scanf(" %s", Joueurs[NombreDeJoueurs].nom);
    printf("Entrer le prenom de joueur :\n");
    scanf(" %s", Joueurs[NombreDeJoueurs].prenom);
    printf("Entrer l\'age de joueur : \n");
    scanf(" %d", &Joueurs[NombreDeJoueurs].age);
    printf("Entrer numero de maillot : \n");
    scanf(" %d", &Joueurs[NombreDeJoueurs].numeroMaillot);
    printf("--> Entrer le poste de joureur : \n");
    printf("1. pour le gardien\n");
    printf("2. pour le defenseur\n");
    printf("3. pour le milieu\n");
    printf("4. pour le attaquant\n");
    printf("Entrer Le Choix De poste :");
    scanf(" %d", &choixDePoste);
    getchar();

    if (choixDePoste == 1)
    {
        char gardian[] = "gardian";
        strcpy(Joueurs[NombreDeJoueurs].poste, gardian);
    }
    else if (choixDePoste == 2)
    {
        char defonseur[] = "defenseur";
        strcpy(Joueurs[NombreDeJoueurs].poste, defonseur);
    }
    else if (choixDePoste == 3)
    {
        char milieu[] = "milieu";
        strcpy(Joueurs[NombreDeJoueurs].poste, milieu);
    }
    else if (choixDePoste == 4)
    {
        char attaquant[] = "attaquant";
        strcpy(Joueurs[NombreDeJoueurs].poste, attaquant);
    }
    else
    printf("Le Choix invalide ! \n");

    printf("Entrer Combien De Buts : ");
    scanf(" %d", &Joueurs[NombreDeJoueurs].buts);

    NombreDeJoueurs++;
}

void ChoixDajouterJoueur(){

    int choixDajouter;
    int CombienDeJoueur;

    printf("1. pour un nouveau joueur \n");
    printf("2. pour ajouter plusieurs joueurs \n");
    scanf(" %d", &choixDajouter);

    if (choixDajouter == 1)
    {
        AjouterUnJoueur();
    }

    else if (choixDajouter == 2)
    {
        printf("Entrer combien de joueur pour ajouter : ");
        scanf(" %d", &CombienDeJoueur);

        for (int i = 0; i < CombienDeJoueur; i++)
        {
            AjouterUnJoueur();
        }
    }
}

void trieParOrderAlphabet(){

    char temp[100];

    //tri par order alphabe

    for (int i = 0; i < NombreDeJoueurs; i++)
    {
        for (int j = 0; j < NombreDeJoueurs - 1 ; j++)
        {
            if (strcmp(Joueurs[j].nom, Joueurs[j + 1].nom) > 0)
            {
                strcpy(temp, Joueurs[j].nom);
                strcpy(Joueurs[j].nom, Joueurs[j+1].nom);
                strcpy(Joueurs[j+1].nom, temp);
            }
        }
    }
}

void trieParOrderAge(){

    int temp;

    for (int i = 0; i < NombreDeJoueurs; i++)
    {
        for (int j = 0; j < NombreDeJoueurs - 1 ; j++)
        {
            if (Joueurs[j].age > Joueurs[j+1].age)
            {
                temp = Joueurs[j].age;
                Joueurs[j].age = Joueurs[j+1].age;
                Joueurs[j+1].age = temp;
            }
            
        }
        
    }
    
}


void AfficherLaListeDeLesJoueur(){

    clearscreen();

    int choixDeTrie;
    int choixDePoste;

    printf("1. Trier les joueurs par ordre alphabetique (Nom)\n");
    printf("2. Trier les joueurs par age\n");
    printf("3. Afficher les joueurs par poste\n");
    printf("Entrer le choix :");
    scanf(" %d", &choixDeTrie);

    if (choixDeTrie == 1)
    {

        trieParOrderAlphabet();

        //afficher avec le trie par order alphabet 
    
        for (int i = 0; i < NombreDeJoueurs; i++)
        {
            printf("-----------------------------------------\n");
            printf("le nom de joueur : %s\n", Joueurs[i].nom);
            printf("le prenom de joueur : %s\n", Joueurs[i].prenom);
            printf("l\'age de joueur : %d\n", Joueurs[i].age);
            printf("le numero de maillot de joueur : %d\n", Joueurs[i].numeroMaillot);
            printf("le poste de joueur : %s\n", Joueurs[i].poste);
            printf("le total de buts de joueur : %d\n", Joueurs[i].buts);
        }
    }
    else if (choixDeTrie == 2)
    {

        trieParOrderAge();

        //afficher avec order age 
    
        for (int i = 0; i < NombreDeJoueurs; i++)
        {
            printf("-----------------------------------------\n");
            printf("le nom de joueur : %s\n", Joueurs[i].nom);
            printf("le prenom de joueur : %s\n", Joueurs[i].prenom);
            printf("l\'age de joueur : %d\n", Joueurs[i].age);
            printf("le numero de maillot de joueur : %d\n", Joueurs[i].numeroMaillot);
            printf("le poste de joueur : %s\n", Joueurs[i].poste);
            printf("le total de buts de joueur : %d\n", Joueurs[i].buts);
        }
    }
    else if (choixDeTrie == 3)
    {
        printf("1. Pour afficher les gardiens  \n");
        printf("2. Pour afficher les defenseurs  \n");
        printf("3. Pour afficher les mileus  \n");
        printf("4. Pou afficher les attaquant  \n");
        printf("Entrer le choix de poste : ");
        scanf(" %d", &choixDePoste);

        if (choixDePoste == 1)
        {
            printf("=== Liste Gardian ===\n");

            for (int i = 0; i < NombreDeJoueurs; i++)
            {
                if (strcmp(Joueurs[i].poste, "gardian") == 0)
                {
                    printf("le nom de joueur : %s\n", Joueurs[i].nom);
                    printf("le prenom de joueur : %s\n", Joueurs[i].prenom);
                    printf("l\'age de joueur : %d\n", Joueurs[i].age);
                    printf("le numero de maillot de joueur : %d\n", Joueurs[i].numeroMaillot);
                    printf("le poste de joueur : %s\n", Joueurs[i].poste);
                    printf("le total de buts de joueur : %d\n", Joueurs[i].buts);
                    printf("-----------------------------------------\n");

                }
            }
        }
        else if (choixDePoste == 2)
        {
            printf("=== Liste Defenseur ===\n");

            for (int i = 0; i < NombreDeJoueurs; i++)
            {
                if (strcmp(Joueurs[i].poste, "defenseur") == 0)
                {
                    printf("le nom de joueur : %s\n", Joueurs[i].nom);
                    printf("le prenom de joueur : %s\n", Joueurs[i].prenom);
                    printf("l\'age de joueur : %d\n", Joueurs[i].age);
                    printf("le numero de maillot de joueur : %d\n", Joueurs[i].numeroMaillot);
                    printf("le poste de joueur : %s\n", Joueurs[i].poste);
                    printf("le total de buts de joueur : %d\n", Joueurs[i].buts);
                    printf("-----------------------------------------\n");

                }
            }
        }
        else if (choixDePoste == 3)
        {
            printf("=== Liste Milieu ===\n");

            for (int i = 0; i < NombreDeJoueurs; i++)
            {
                if (strcmp(Joueurs[i].poste, "milieu") == 0)
                {
                    printf("le nom de joueur : %s\n", Joueurs[i].nom);
                    printf("le prenom de joueur : %s\n", Joueurs[i].prenom);
                    printf("l\'age de joueur : %d\n", Joueurs[i].age);
                    printf("le numero de maillot de joueur : %d\n", Joueurs[i].numeroMaillot);
                    printf("le poste de joueur : %s\n", Joueurs[i].poste);
                    printf("le total de buts de joueur : %d\n", Joueurs[i].buts);
                    printf("-----------------------------------------\n");

                }
            }
        }
        else if (choixDePoste == 4)
        {
            printf("=== Liste Attaquant ===\n");

            for (int i = 0; i < NombreDeJoueurs; i++)
            {
                if (strcmp(Joueurs[i].poste, "attaquant") == 0)
                {
                    printf("le nom de joueur : %s\n", Joueurs[i].nom);
                    printf("le prenom de joueur : %s\n", Joueurs[i].prenom);
                    printf("l\'age de joueur : %d\n", Joueurs[i].age);
                    printf("le numero de maillot de joueur : %d\n", Joueurs[i].numeroMaillot);
                    printf("le poste de joueur : %s\n", Joueurs[i].poste);
                    printf("le total de buts de joueur : %d\n", Joueurs[i].buts);
                    printf("-----------------------------------------\n");

                }
            }
        }
    } 
}
int main(){

    int choix;

    do
    {
        printf("====== M E N U ======\n");
        printf("1. pour ajouter un joueur\n");
        printf("2. pour afficher liste des joueurs\n");
        printf("entrer votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            ChoixDajouterJoueur();
            break;
        case 2:
            AfficherLaListeDeLesJoueur();
            break;
        default:
            break;
        }
    } while (choix != 0);
    
}