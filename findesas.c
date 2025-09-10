#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct InfoDeJoueur{
    int id;
    char nom[100];
    char prenom[100];
    int age;
    int numeroMaillot;
    char poste[100];
    int buts;
};

struct InfoDeJoueur Joueurs[100] = {
    {1,"hakimi","achraf",25,2,"defenseur",5},
    {2,"bounou","yassine",33,1,"gardian",0},
    {3,"en-nesyri","youssef",28,9,"attaquant",12},
    {4,"amrabat","sofyan",29,4,"milieu",3},
    {5,"ziyech","hakim",32,7,"milieu",8},
    {6,"mazraoui","noussair",27,3,"defenseur",2},
    {7,"saiss","romain",35,6,"defenseur",1},
    {8,"ounahi","azzedine",24,8,"milieu",4},
    {9,"aboukhlal","zakho",26,11,"attaquant",10},
    {10,"el kaabi","ayoub",32,17,"attaquant",15}

};

int nextid = 11;

int NombreDeJoueurs = 10;

void clearscreen(){
    system("cls || clear");
}

// fonction d'ajouter un joueur 

void AjouterUnJoueur(){

    clearscreen();

    int choixDePoste;

    printf("===== Ajouter un joueur =====\n");
    printf("Entrer le nom de joueur \n");
    printf("=> ");
    scanf(" %s", Joueurs[NombreDeJoueurs].nom);
    printf("Entrer le prenom de joueur :\n");
    printf("=> ");
    scanf(" %s", Joueurs[NombreDeJoueurs].prenom);
    printf("Entrer l\'age de joueur : \n");
    printf("=> ");
    scanf(" %d", &Joueurs[NombreDeJoueurs].age);
    printf("Entrer numero de maillot : \n");
    printf("=> ");
    scanf(" %d", &Joueurs[NombreDeJoueurs].numeroMaillot);
    printf("--> Entrer le poste de joureur : \n");
    printf("\t1. pour le gardien\n");
    printf("\t2. pour le defenseur\n");
    printf("\t3. pour le milieu\n");
    printf("\t4. pour le attaquant\n");
    printf("Entrer Le Choix De poste :\n");
    printf("=> ");
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

    printf("tu a ajouter un joueur...\n");

    printf("appuyez sur entre...");
    getchar();
    getchar();

    Joueurs[NombreDeJoueurs].id = nextid;
    nextid++;

    NombreDeJoueurs++;

    clearscreen();
}

void ChoixDajouterJoueur(){

    clearscreen();

    int choixDajouter;
    int CombienDeJoueur;

    printf("==== Le choix d\'ajouter ====\n");

    printf("1. pour un nouveau joueur \n");
    printf("2. pour ajouter plusieurs joueurs \n");
    printf("Entrer le choix 1 ou 2 : ");
    scanf(" %d", &choixDajouter);
    getchar();

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

        struct InfoDeJoueur temp;

        //tri par order alphabe

        for (int i = 0; i < NombreDeJoueurs; i++)
        {
            for (int j = 0; j < NombreDeJoueurs - 1 ; j++)
            {
                if (strcmp(Joueurs[j].nom, Joueurs[j + 1].nom) > 0)
                {
                    temp = Joueurs[j];
                    Joueurs[j] =Joueurs[j+1];
                    Joueurs[j+1] = temp;
                }
            }
        }
    }

    void trieParOrderAge(){

        clearscreen();

        struct InfoDeJoueur temp;

        for (int i = 0; i < NombreDeJoueurs; i++)
        {
            for (int j = 0; j < NombreDeJoueurs - 1 ; j++)
            {
                if (Joueurs[j].age > Joueurs[j+1].age)
                {
                    temp = Joueurs[j];
                    Joueurs[j] = Joueurs[j+1];
                    Joueurs[j+1] = temp;
                }
            }  
        } 
    }


void AfficherLaListeDeLesJoueur(){

    clearscreen();

    int choixDeTrie;
    int choixDePoste;

    printf("======== Afficher les joueurs ========\n");
    printf("1. Trier les joueurs par ordre alphabetique (Nom)\n");
    printf("2. Trier les joueurs par age\n");
    printf("3. Afficher les joueurs par poste\n");
    printf("Entrer le choix :");
    scanf(" %d", &choixDeTrie);

    clearscreen();

    if (choixDeTrie == 1)
    {

        trieParOrderAlphabet();

        //afficher avec le trie par order alphabet 
    
        for (int i = 0; i < NombreDeJoueurs; i++)
        {
            printf("-----------------------------------------\n");
            printf("Id : %d\n", Joueurs[i].id);
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
            printf("Id : %d\n", Joueurs[i].id);
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
                    printf("Id : %d\n", Joueurs[i].id);
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
                    printf("Id : %d\n", Joueurs[i].id);
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
                    printf("Id : %d\n", Joueurs[i].id);
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
                    printf("Id : %d\n", Joueurs[i].id);
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
    printf("appuyez sur entre...");
    getchar();
    getchar();

    clearscreen();
}

void RechercheUnJoueur(){

    clearscreen();

    int ChoixDeRecherche;
    char nomPourRecherche[100];
    int idrecherche;
    int found = 0;
    int idfound = 0;


    printf("1. Pour Rechercher un joueur par Nom\n");
    printf("2. Pour Rechercher un joueur par Identifiant\n");
    printf("Entrer votre choix :");
    scanf(" %d", &ChoixDeRecherche);

    if (ChoixDeRecherche == 1)
    {
        printf("Entrer le nom de joueur : \n");
        scanf(" %s", nomPourRecherche);

        for (int i = 0; i < NombreDeJoueurs; i++)
        {
            if (strcmp(Joueurs[i].nom, nomPourRecherche) == 0)
            {
                printf("=== Le nom de joueur est trouve ===\n");
                printf("Id : %d\n", Joueurs[i].id);
                printf("\nLe nom de joueur : %s\n", Joueurs[i].nom);
                printf("Le prenom de joueur : %s\n", Joueurs[i].prenom);
                printf("L\'age de joueur : %d\n", Joueurs[i].age);
                printf("Numero de maillot de joueur : %d\n", Joueurs[i].numeroMaillot);
                printf("Le poste de joueur : %s\n", Joueurs[i].poste);
                printf("Nombre de buts : %d\n", Joueurs[i].buts);
                printf("\n");
                found = 1;
            }
        }
        if (found != 1)
        {
            printf("aucune joueur avec le nom de (%s) !\n", nomPourRecherche);
        }
    }
    if (ChoixDeRecherche == 2)
    {
        printf("Entrer Id de joueur :\n");
        scanf(" %d", &idrecherche);

        for (int i = 0; i < NombreDeJoueurs; i++)
        {
            if (Joueurs[i].id == idrecherche)
            {
                printf("=== le joueur est trouve ===\n");
                printf("Id : %d\n", Joueurs[i].id);
                printf("\nLe nom de joueur : %s\n", Joueurs[i].nom);
                printf("Le prenom de joueur : %s\n", Joueurs[i].prenom);
                printf("L\'age de joueur : %d\n", Joueurs[i].age);
                printf("Numero de maillot de joueur : %d\n", Joueurs[i].numeroMaillot);
                printf("Le poste de joueur : %s\n", Joueurs[i].poste);
                printf("Nombre de buts : %d\n", Joueurs[i].buts);
                printf("\n");
                idfound = 1;
            }  
        }
        if (idfound != 1)
        {
            printf("aucune joueur avec id de (%d)\n", idrecherche);
        }
        
        
    }
    
}

void ModifierUnJoueur(){

    char nomRecherche[100];
    char ouiNon;

    printf("Entrer le nom de joueur : \n");
    scanf(" %s", nomRecherche);

    for (int i = 0; i < NombreDeJoueurs; i++)
    {
        if (strcmp(Joueurs[i].nom, nomRecherche) == 0)
        {
            printf("=== le joueur existe ===\n");
            printf("Modifier le poste d\'un joueur (O = oui / N = non) :");
            scanf(" %c", &ouiNon);

            if (ouiNon == 'o' || ouiNon == 'O')
            {
                printf("\t1. pour le gardien\n");
                printf("\t2. pour le defenseur\n");
                printf("\t3. pour le milieu\n");
                printf("\t4. pour le attaquant\n");
                printf("Entrer Le Choix De poste :\n");
                printf("=> ");
                scanf(" %s", Joueurs[i].poste);
            }

            printf("Modifier l\'age d\'un joueur (O = oui / N = non) :");
            scanf(" %c", &ouiNon);

            if (ouiNon == 'o' || ouiNon == 'O')
            {
                printf("Entrer Nouvelle Age :");
                scanf(" %d", &Joueurs[i].age);
            }

            printf("Modifier le nombre de buts marques par un  (O = oui / N = non) :");
            scanf(" %c", &ouiNon);

            if (ouiNon == 'o' || ouiNon == 'O')
            {
                printf("Entrer Nouveau Nombre De Buts :");
                scanf(" %d", &Joueurs[i].buts);
            }
        }
    }
}
int main(){

    clearscreen();

    int choix;

    do
    {

        printf(" =============== M E N U ============= \n");
        printf("| 1. pour ajouter un joueur           |\n");
        printf("| 2. pour afficher liste des joueurs  |\n");
        printf("| 3. pour recherche un joueur         |\n");
        printf("| 4. pour modifier un joueur          |\n");
        printf("| 5. pour supprimer un joueur         |\n");
        printf("| 6. pour les statistiques            |\n");
        printf(" ===================================== \n");
        printf("==> Entrer votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            ChoixDajouterJoueur();
            break;
        case 2:
            AfficherLaListeDeLesJoueur();
            break;
        case 3:
            RechercheUnJoueur();
            break;
        case 4:
            ModifierUnJoueur();
            break;
        default:
            printf("AU REVOIR !");
            break;
        }
    } while (choix != 0);
    
}