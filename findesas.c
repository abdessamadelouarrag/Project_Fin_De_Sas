#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//color 
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

struct InfoDeJoueur
{
    int id;
    char nom[100];
    char prenom[100];
    int age;
    int numeroMaillot;
    char poste[100];
    int buts;
};

struct InfoDeJoueur Joueurs[100] = {
    {1, "hakimi", "achraf", 25, 2, "defenseur", 5},
    {2, "bounou", "yassine", 33, 1, "gardien", 0},
    {3, "en-nesyri", "youssef", 28, 9, "attaquant", 12},
    {4, "amrabat", "sofyan", 29, 4, "milieu", 3},
    {5, "ziyech", "hakim", 32, 7, "milieu", 8},
    {6, "mazraoui", "noussair", 27, 3, "defenseur", 2},
    {7, "saiss", "romain", 35, 6, "defenseur", 1},
    {8, "ounahi", "azzedine", 24, 8, "milieu", 4},
    {9, "aboukhlal", "zakho", 26, 11, "attaquant", 10},
    {10, "el kaabi", "ayoub", 32, 17, "attaquant", 15}

};

int nextid = 11;
int NombreDeJoueurs = 10;

void clearscreen()
{
    system("cls || clear");
}

// fonction d'ajouter un joueur

void AjouterUnJoueur()
{

    clearscreen();

    int choixDePoste;

    printf("===== A J O U T E R  U N  J O U E U R =====\n");
    printf("\nEntrer le nom de joueur \n");
    printf("=> ");
    scanf(" %[^\n]", Joueurs[NombreDeJoueurs].nom);
    printf("Entrer le prenom de joueur :\n");
    printf("=> ");
    scanf(" %[^\n]", Joueurs[NombreDeJoueurs].prenom);
    printf("Entrer l\'age de joueur : \n");
    printf("=> ");
    scanf(" %d", &Joueurs[NombreDeJoueurs].age);

    // verifier age de joueur
    while (Joueurs[NombreDeJoueurs].age > 58 || Joueurs[NombreDeJoueurs].age < 16)
    {
        if (Joueurs[NombreDeJoueurs].age > 58)
        {
            printf("Etes-vous Kazuyoshi Miura !! \n");
            printf("Entrer l\'age de joueur : \n");
            printf("=> ");
            scanf(" %d", &Joueurs[NombreDeJoueurs].age);
        }
        else if (Joueurs[NombreDeJoueurs].age < 1)
        {
            printf("!!!! aga invalide !!!!\n");
            printf("Entrer l\'age de joueur : \n");
            printf("=> ");
            scanf(" %d", &Joueurs[NombreDeJoueurs].age);
        }

        else
        {
            printf("Le joueur est tres jeune !! \n");
            printf("Entrer l\'age de joueur : \n");
            printf("=> ");
            scanf(" %d", &Joueurs[NombreDeJoueurs].age);
        }
    }

    int numeroexiste;

    do
    {
        numeroexiste = 0;

        printf("Entrer numero de maillot (1 - 99): \n");
        printf("=> ");
        scanf(" %d", &Joueurs[NombreDeJoueurs].numeroMaillot);
    
        for (int i = 0; i < NombreDeJoueurs; i++)
        {
            if (Joueurs[NombreDeJoueurs].numeroMaillot == Joueurs[i].numeroMaillot)
            {
                printf("il ya un maillot avec se numero !!\n");
                numeroexiste = 1;
                break;
            }
            else if (Joueurs[NombreDeJoueurs].numeroMaillot < 1)
            {
               printf("invalide !!!");
            }
            
        }

    } while (numeroexiste);
    
    menu1:
    printf("--> Entrer le poste de joureur : \n");
    printf("\t1. pour le gardien\n");
    printf("\t2. pour le defenseur\n");
    printf("\t3. pour le milieu\n");
    printf("\t4. pour le attaquant\n");
    printf("Entrer Le Choix De poste :\n");
    printf("=> ");
    scanf(" %d", &choixDePoste);
    getchar();

    switch (choixDePoste)
    {
    case 1:
        strcpy(Joueurs[NombreDeJoueurs].poste, "gardien");
        break;
    case 2:
        strcpy(Joueurs[NombreDeJoueurs].poste, "defenseur");
        break;
    case 3:
        strcpy(Joueurs[NombreDeJoueurs].poste, "milieu");
        break;
    case 4:
        strcpy(Joueurs[NombreDeJoueurs].poste, "attaquant");
        break;
    default:
        printf("Choix invalide, poste par defaut 'inconnu'\n");
        goto menu1;
    }

    printf("Entrer Combien De Buts : ");
    scanf(" %d", &Joueurs[NombreDeJoueurs].buts);

    Joueurs[NombreDeJoueurs].id = nextid;
    nextid++;
    NombreDeJoueurs++;

    printf(ANSI_COLOR_GREEN "+++ Joueur ajoute avec succes +++\n" ANSI_COLOR_RESET);

    printf("\nappuyez sur entree pour retourner au menu...");
    getchar();
    getchar();

    clearscreen();
}

// fonction le choix d'ajouter un joueur
void ChoixDajouterJoueur()
{

    clearscreen();

    int choixDajouter;
    int CombienDeJoueur;

    printf(ANSI_COLOR_GREEN"========= Le choix d\'ajouter ========\n"ANSI_COLOR_RESET);
    printf("|                                    |\n");
    printf("| 1. pour un nouveau joueur          |\n");
    printf("| 2. pour ajouter plusieurs joueurs  |\n");
    printf("|                                    |\n");
    printf(ANSI_COLOR_GREEN"======================================\n"ANSI_COLOR_RESET);
    printf("=> Entrer le choix 1 ou 2 : ");
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

// fonction de tri par order alphabet
void trieParOrderAlphabet()
{
    struct InfoDeJoueur temp;
    // tri par order alphabe

    for (int i = 0; i < NombreDeJoueurs - 1; i++)
    {
        for (int j = 0; j < NombreDeJoueurs - i - 1; j++)
        {
            if (strcmp(Joueurs[j].nom, Joueurs[j + 1].nom) > 0)
            {
                temp = Joueurs[j];
                Joueurs[j] = Joueurs[j + 1];
                Joueurs[j + 1] = temp;
            }
        }
    }
}

// fonction de tri par order d'age
void trieParOrderAge()
{
    struct InfoDeJoueur temp;

    for (int i = 0; i < NombreDeJoueurs; i++)
    {
        for (int j = 0; j < NombreDeJoueurs - 1; j++)
        {
            if (Joueurs[j].age > Joueurs[j + 1].age)
            {
                temp = Joueurs[j];
                Joueurs[j] = Joueurs[j + 1];
                Joueurs[j + 1] = temp;
            }
        }
    }
}

// fonction afficher liste de joueurs
void AfficherLaListeDeLesJoueur()
{

    clearscreen();

    int choixDeTrie;
    int choixDePoste;

    printf(ANSI_COLOR_BLUE"============= A F F I C H E R  L E S  J O U E U R S =============\n\n"ANSI_COLOR_RESET);
    printf("| 1. Trier les joueurs par ordre alphabetique (Nom)             |\n");
    printf("| 2. Trier les joueurs par age                                  |\n");
    printf("| 3. Afficher les joueurs par poste                             |\n\n");
    printf(ANSI_COLOR_BLUE"=================================================================\n"ANSI_COLOR_RESET);
    printf("=> Votre choix : ");
    scanf(" %d", &choixDeTrie);

    clearscreen();

    if (choixDeTrie == 1)
    {

        trieParOrderAlphabet();

        // afficher avec le trie par order alphabet

        printf("===== LES JOUEURS AVEC ORDER ALPHABETIQUE =====\n");

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

        // afficher avec order age

        printf("===== LES JOUEURS AVEC ORDER D\'AGE =====\n");

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
        printf("==== L E  C H O I X  D E  P O S T E ====\n");
        printf("\n1. Pour afficher les gardiens  \n");
        printf("2. Pour afficher les defenseurs  \n");
        printf("3. Pour afficher les mileus  \n");
        printf("4. Pou afficher les attaquant  \n");
        printf("Entrer le choix de poste : ");
        scanf(" %d", &choixDePoste);

        if (choixDePoste == 1)
        {
            clearscreen();

            printf("=== Liste Gardian ===\n");

            for (int i = 0; i < NombreDeJoueurs; i++)
            {
                if (strcmp(Joueurs[i].poste, "gardien") == 0)
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

            clearscreen();

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

            clearscreen();

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

            clearscreen();

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
    printf(ANSI_COLOR_RED"\nappuyez sur entree pour retourneer au menu..."ANSI_COLOR_RESET);
    getchar();
    getchar();

    clearscreen();
}

// fonction de recherche un joueur
void RechercheUnJoueur()
{

    clearscreen();

    int ChoixDeRecherche;
    char nomPourRecherche[100];
    int idrecherche;
    int found = 0;
    int idfound = 0;

    printf(ANSI_COLOR_MAGENTA"==== L E  C H O I X  D E  R E C H E R C H E ====\n\n");
    printf("| 1. Pour Rechercher un joueur par Nom         |\n");
    printf("| 2. Pour Rechercher un joueur par Identifiant |\n\n");
    printf("================================================\n"ANSI_COLOR_RESET);
    printf("Entrer votre choix :");
    scanf(" %d", &ChoixDeRecherche);
    getchar();

    if (ChoixDeRecherche == 1)
    {
        printf("=> Entrer le nom de joueur : ");
        scanf(" %[^\n]", nomPourRecherche);
        getchar();

        for (int i = 0; i < NombreDeJoueurs; i++)
        {
            if (strcasecmp(Joueurs[i].nom, nomPourRecherche) == 0)
            {
                clearscreen();

                printf("=== Joueur Trouve ===\n");
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
    else if (ChoixDeRecherche == 2)
    {
        printf("Entrer Id de joueur : ");
        scanf(" %d", &idrecherche);
        getchar();

        for (int i = 0; i < NombreDeJoueurs; i++)
        {
            if (Joueurs[i].id == idrecherche)
            {
                clearscreen();

                printf("=== Joueur Trouve ===\n");
                printf("Id : %d\n", Joueurs[i].id);
                printf("\nLe nom de joueur : %s\n", Joueurs[i].nom);
                printf("Le prenom de joueur : %s\n", Joueurs[i].prenom);
                printf("L\'age de joueur : %d\n", Joueurs[i].age);
                printf("Numero de maillot de joueur : %d\n", Joueurs[i].numeroMaillot);
                printf("Le poste de joueur : %s\n", Joueurs[i].poste);
                printf("Nombre de buts : %d\n", Joueurs[i].buts);
                printf("\n");
                idfound = 1;
                break;
            }
        }
        if (idfound != 1)
        {
            printf("aucune joueur avec id de (%d)\n", idrecherche);
        }
    }
    else
    {
        printf("Choix invalide.\n");
    }

    printf(ANSI_COLOR_RED"\nappuyez sur entree pour retourneer au menu..."ANSI_COLOR_RESET);
    getchar();

    clearscreen();
}

// fonction modifier un joueur
void ModifierUnJoueur()
{

    clearscreen();

    char nomRecherche[100];
    char ouiNon;
    int modifierPosteJoueur;
    int found = 0;

    printf(ANSI_COLOR_YELLOW"======= M O D I F I E R  U N  J O U E U R =======\n"ANSI_COLOR_RESET);
    printf("=> Entrer le nom de joueur : \n");
    scanf(" %[^\n]", nomRecherche);
    getchar();

    for (int i = 0; i < NombreDeJoueurs; i++)
    {
        if (strcmp(Joueurs[i].nom, nomRecherche) == 0)
        {
            printf(ANSI_COLOR_GREEN"=== le joueur existe ===\n"ANSI_COLOR_RESET);
            printf("Modifier le poste d\'un joueur (O = oui / N = non) :");
            scanf(" %c", &ouiNon);
            getchar();

            if (ouiNon == 'o' || ouiNon == 'O')
            {
                printf("\t1. pour le gardien\n");
                printf("\t2. pour le defenseur\n");
                printf("\t3. pour le milieu\n");
                printf("\t4. pour le attaquant\n");
                printf("Entrer Le Choix De poste :\n");
                printf("=> ");
                scanf(" %d", &modifierPosteJoueur);
                getchar();

                switch (modifierPosteJoueur)
                {
                case 1:
                    strcpy(Joueurs[i].poste, "gardien");
                    break;
                case 2:
                    strcpy(Joueurs[i].poste, "defenseur");
                    break;
                case 3:
                    strcpy(Joueurs[i].poste, "milieu");
                    break;
                case 4:
                    strcpy(Joueurs[i].poste, "attaquant");
                    break;
                default:
                    printf("Choix invalide, poste non modifie.\n");
                }
            }

            printf("Modifier l\'age d\'un joueur (O = oui / N = non) :");
            scanf(" %c", &ouiNon);
            getchar();

            if (ouiNon == 'o' || ouiNon == 'O')
            {
                printf("Entrer Nouvelle Age :");
                scanf(" %d", &Joueurs[i].age);
                getchar();
            }

            printf("Modifier le nombre de buts marques par un  (O = oui / N = non) :");
            scanf(" %c", &ouiNon);
            getchar();

            if (ouiNon == 'o' || ouiNon == 'O')
            {
                printf("Entrer Nouveau Nombre De Buts :");
                scanf(" %d", &Joueurs[i].buts);
                getchar();
            }

            printf("Joueur modifie avec succes.\n");
            found = 1;
            printf(ANSI_COLOR_RED"\nappuyez sur entree pour retourneer au menu..."ANSI_COLOR_RESET);
            getchar();
            break; // fin boucle après modification
        }
    }

    if(found != 1)
    {
        printf(ANSI_COLOR_RED"!!! aucune joueur avec le nom (%s)"ANSI_COLOR_RESET, nomRecherche);
    }
    
    printf(ANSI_COLOR_RED"\nappuyez sur entree pour retourneer au menu..."ANSI_COLOR_RESET);
    getchar();

    clearscreen();
}

// fonction supprimer un joueur
void SupprimerUnJoueur()
{

    clearscreen();

    int idsupprimer;
    int foundsupprimer = 0;
    char ouiNon;

    printf(ANSI_COLOR_MAGENTA"====== S u p p r i m e r  U n  J o u e u r ======\n"ANSI_COLOR_RESET);
    printf("=> Entrer id de joueur pour supprimer : ");
    scanf(" %d", &idsupprimer);
    getchar();

    for (int i = 0; i < NombreDeJoueurs; i++)
    {
        if (idsupprimer == Joueurs[i].id)
        {
            printf(ANSI_COLOR_RED"! Vraiment tu va supprimer le joueur ? (O = oui / N = non) : \n"ANSI_COLOR_RESET);
            scanf(" %c", &ouiNon);
            getchar();

            if (ouiNon == 'O' || ouiNon == 'o')
            {
                for (int j = i; j < NombreDeJoueurs - 1; j++)
                {
                    Joueurs[j] = Joueurs[j + 1];
                }
                NombreDeJoueurs--;
                foundsupprimer = 1;
                printf(ANSI_COLOR_RED"Joueur supprime\n"ANSI_COLOR_RESET);

                break;
            }
        }
    }

    if (foundsupprimer != 1)
    {
        printf("Aucun Joueur Avec Id (%d)", idsupprimer);
    }

    printf(ANSI_COLOR_RED"\nappuyez sur entree pour retourneer au menu..."ANSI_COLOR_RESET);
    getchar();

    clearscreen();
}

// fonction statistiques
void Statistiques()
{

    clearscreen();

    int choixStatistiques;
    int ageTotal = 0;
    int ageMoyen;
    int choixDeButs;

    printf(ANSI_COLOR_GREEN"================= S T A T I S T I Q U E S =================\n\n"ANSI_COLOR_RESET);
    printf("| 1. Afficher le nombre total de joueurs dans l\'equipe    |\n");
    printf("| 2. Afficher l\'age moyen des joueurs                     |\n");
    printf("| 3. Afficher les joueurs ayant marque plus de buts       |\n");
    printf("| 4. Afficher le joueur le plus jeune et le plus age      |\n");
    printf("| 5. Afficher le meilleur buteur                          |\n");
    printf("| 0. quite les statistiques                               |\n\n");
    printf(ANSI_COLOR_GREEN"===========================================================\n"ANSI_COLOR_RESET);
    printf("=> Votre Choix : ");
    scanf(" %d", &choixStatistiques);
    getchar();

    if (choixStatistiques == 1)
    {
        clearscreen();

        printf("=== Le Nombre Total De Joueurs ====");
        printf("\n=>  %d Joueurs\n", NombreDeJoueurs);
    }

    else if (choixStatistiques == 2)
    {
        clearscreen();

        for (int i = 0; i < NombreDeJoueurs; i++)
        {
            ageTotal += Joueurs[i].age;
        }
        ageMoyen = ageTotal / NombreDeJoueurs;

        printf("==== l\'age moyen des joueurs ====\n");
        printf("=> %d ans", ageMoyen);
    }

    else if (choixStatistiques == 3)
    {
        clearscreen();

        printf("==== Afficher les joueurs ayant marque plus ====\n");

        printf("Entrer le nombre de buts pour filtrer : ");
        scanf(" %d", &choixDeButs);
        printf("Joueurs ayant marqué plus de %d buts :\n", choixDeButs);

        for (int i = 0; i < NombreDeJoueurs; i++)
        {
            if (Joueurs[i].buts > choixDeButs)
            {
                printf("=====================================\n");
                printf("Id : %d\n", Joueurs[i].id);
                printf("le nom de joueur : %s\n", Joueurs[i].nom);
                printf("le prenom de joueur : %s\n", Joueurs[i].prenom);
                printf("l\'age de joueur : %d\n", Joueurs[i].age);
                printf("le numero de maillot de joueur : %d\n", Joueurs[i].numeroMaillot);
                printf("le poste de joueur : %s\n", Joueurs[i].poste);
                printf("le total de buts de joueur : %d\n", Joueurs[i].buts);
            }
        }
    }

    else if (choixStatistiques == 4)
    {
        if (NombreDeJoueurs > 0)
        {
            trieParOrderAge();
            printf("****** L E  P L U S  J E U N E  E S T  L E  P L U S  A G E ******\n");
            printf("=== le joueur le plus jeune === \n ==> %s", Joueurs[0].nom);
            printf("\n=== le joueur le plus age === \n ==> %s", Joueurs[NombreDeJoueurs - 1].nom);
        }
        else if (NombreDeJoueurs == 0)
        {
            printf("Aucun joueur dans l\'equipe.\n");
        }
        else
            printf("Choix invalide.\n");
    }
    else if (choixStatistiques == 5)
    {
        int max = Joueurs[0].buts;
        int indexMax = 0;

        for (int i = 0; i < NombreDeJoueurs; i++)
        {
            if (Joueurs[i].buts > max)
            {
                max = Joueurs[i].buts;
                indexMax = i; // met à jour l'index du joueur avec le plus de buts
            }
        }
        printf("Le Joueur plus de buts : %d\n", Joueurs[indexMax].buts);
    }

    printf("\nappuyez sur entree pour retourner au menu...");
    getchar();

    clearscreen();
}

// fonction quiter
int Quiter()
{

    char ConfQuiter;

    clearscreen();

    printf(ANSI_COLOR_RED"===== Q U I T E R =====\n");

    printf("Voulez-vous vraiment quitter ?  (O = oui / N = non) : "ANSI_COLOR_RESET);
    scanf(" %c", &ConfQuiter);
    getchar();

    if (ConfQuiter == 'o' || ConfQuiter == 'O')
    {
        clearscreen();

        printf("\n");
        printf("* * * A U  R E V O I R * * *\n");
        printf("\n");
        return 0;
    }
    else if (ConfQuiter == 'n' || ConfQuiter == 'N')
    {
        clearscreen();

        printf("* * * Bienvenu A Nouveau * * *\n");
        printf("\n");

        printf("\nappuyez sur entree pour retourner au menu...");
        getchar();

        clearscreen();

        return 1;
    }
}

// main
int main()
{

    clearscreen();

    int choix;

    do
    {
        printf(ANSI_COLOR_MAGENTA "+=========================================================+\n");
        printf("|============ GESTION D'UNE EQUIPE DE FOOTBALL ===========|\n");
        printf( "+=========================================================+\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "|=============== M E N U  P R I N C I P A L ==============|\n" );
        printf("|                                                         |\n" );
        printf("|   1. Pour ajouter un joueur                             |\n" );
        printf("|   2. Pour afficher liste des joueurs                    |\n" );
        printf("|   3. Pour recherche un joueur                           |\n" );
        printf("|   4. Pour modifier un joueur                            |\n" );
        printf("|   5. Pour supprimer un joueur                           |\n" );
        printf("|   6. Pour les statistiques                              |\n" );
        printf("|   0. Quite                                              |\n" );
        printf("|                                                         |\n" );
        printf("=========================================================== \n" ANSI_COLOR_RESET);
        printf("==> Entrer votre choix : ");
        scanf(" %d", &choix);
        getchar();

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
        case 5:
            SupprimerUnJoueur();
            break;
        case 6:
            Statistiques();
            break;
        case 0:
            if (Quiter() == 1)
            {
                choix = 22; // pour sortir de la boucle
            }
            break;
        default:
            printf("Choix invalide, veuillez reessayer.\n");
            break;
        }
    } while (choix != 0);
}