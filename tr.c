#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct InfoDeJoueur {
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

void clearscreen() {
    system("cls || clear");
}

// Ajouter un joueur
void AjouterUnJoueur() {
    clearscreen();

    int choixDePoste;

    printf("===== Ajouter un joueur =====\n");
    printf("Entrer le nom de joueur:\n=> ");
    scanf(" %s", Joueurs[NombreDeJoueurs].nom);
    printf("Entrer le prenom de joueur:\n=> ");
    scanf(" %s", Joueurs[NombreDeJoueurs].prenom);
    printf("Entrer l'age de joueur:\n=> ");
    scanf(" %d", &Joueurs[NombreDeJoueurs].age);
    printf("Entrer numero de maillot:\n=> ");
    scanf(" %d", &Joueurs[NombreDeJoueurs].numeroMaillot);
    printf("--> Entrer le poste de joueur:\n");
    printf("\t1. pour le gardien\n");
    printf("\t2. pour le defenseur\n");
    printf("\t3. pour le milieu\n");
    printf("\t4. pour l'attaquant\n");
    printf("Entrer Le Choix De poste :\n=> ");
    scanf(" %d", &choixDePoste);
    getchar();

    switch (choixDePoste) {
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
            strcpy(Joueurs[NombreDeJoueurs].poste, "inconnu");
    }

    printf("Combien de buts : ");
    scanf(" %d", &Joueurs[NombreDeJoueurs].buts);

    Joueurs[NombreDeJoueurs].id = nextid++;
    NombreDeJoueurs++;

    printf("Joueur ajouté avec succès.\n");

    printf("\nAppuyez sur entree pour retourner au menu...");
    getchar();
    getchar();

    clearscreen();
}

// Choix d'ajout multiple
void ChoixDajouterJoueur() {
    clearscreen();

    int choixDajouter;
    int CombienDeJoueur;

    printf("==== Le choix d'ajouter ====\n");
    printf("1. pour un nouveau joueur\n");
    printf("2. pour ajouter plusieurs joueurs\n");
    printf("Entrer le choix 1 ou 2 : ");
    scanf(" %d", &choixDajouter);
    getchar();

    if (choixDajouter == 1) {
        AjouterUnJoueur();
    } else if (choixDajouter == 2) {
        printf("Entrer combien de joueurs à ajouter : ");
        scanf(" %d", &CombienDeJoueur);
        for (int i = 0; i < CombienDeJoueur; i++) {
            AjouterUnJoueur();
        }
    }
}

// Tri par ordre alphabétique
void trieParOrderAlphabet() {
    struct InfoDeJoueur temp;
    for (int i = 0; i < NombreDeJoueurs - 1; i++) {
        for (int j = 0; j < NombreDeJoueurs - i - 1; j++) {
            if (strcmp(Joueurs[j].nom, Joueurs[j + 1].nom) > 0) {
                temp = Joueurs[j];
                Joueurs[j] = Joueurs[j + 1];
                Joueurs[j + 1] = temp;
            }
        }
    }
}

// Tri par ordre d'âge
void trieParOrderAge() {
    struct InfoDeJoueur temp;
    for (int i = 0; i < NombreDeJoueurs - 1; i++) {
        for (int j = 0; j < NombreDeJoueurs - i - 1; j++) {
            if (Joueurs[j].age > Joueurs[j + 1].age) {
                temp = Joueurs[j];
                Joueurs[j] = Joueurs[j + 1];
                Joueurs[j + 1] = temp;
            }
        }
    }
}

// Afficher la liste des joueurs
void AfficherLaListeDeLesJoueur() {
    clearscreen();

    int choixDeTrie;
    int choixDePoste;

    printf("======== Afficher les joueurs ========\n");
    printf("1. Trier par ordre alphabétique (Nom)\n");
    printf("2. Trier par âge\n");
    printf("3. Afficher par poste\n");
    printf("Votre choix : ");
    scanf(" %d", &choixDeTrie);

    switch (choixDeTrie) {
        case 1:
            trieParOrderAlphabet();
            printf("===== LES JOUEURS PAR NOM (ALPHABETIQUE) =====\n");
            for (int i = 0; i < NombreDeJoueurs; i++) {
                printf("-----------------------------------------\n");
                printf("Id : %d\n", Joueurs[i].id);
                printf("Nom : %s\n", Joueurs[i].nom);
                printf("Prenom : %s\n", Joueurs[i].prenom);
                printf("Age : %d\n", Joueurs[i].age);
                printf("Numero Maillot : %d\n", Joueurs[i].numeroMaillot);
                printf("Poste : %s\n", Joueurs[i].poste);
                printf("Buts : %d\n", Joueurs[i].buts);
            }
            break;
        case 2:
            trieParOrderAge();
            printf("===== LES JOUEURS PAR AGE =====\n");
            for (int i = 0; i < NombreDeJoueurs; i++) {
                printf("-----------------------------------------\n");
                printf("Id : %d\n", Joueurs[i].id);
                printf("Nom : %s\n", Joueurs[i].nom);
                printf("Prenom : %s\n", Joueurs[i].prenom);
                printf("Age : %d\n", Joueurs[i].age);
                printf("Numero Maillot : %d\n", Joueurs[i].numeroMaillot);
                printf("Poste : %s\n", Joueurs[i].poste);
                printf("Buts : %d\n", Joueurs[i].buts);
            }
            break;
        case 3:
            printf("==== Choix de poste ====\n");
            printf("1. Gardiens\n");
            printf("2. Defenseurs\n");
            printf("3. Milieux\n");
            printf("4. Attaquants\n");
            printf("Entrer le choix : ");
            scanf(" %d", &choixDePoste);
            clearscreen();

            const char* posteRecherche;
            switch (choixDePoste) {
                case 1:
                    posteRecherche = "gardien";
                    printf("=== Liste Gardiens ===\n");
                    break;
                case 2:
                    posteRecherche = "defenseur";
                    printf("=== Liste Defenseurs ===\n");
                    break;
                case 3:
                    posteRecherche = "milieu";
                    printf("=== Liste Milieux ===\n");
                    break;
                case 4:
                    posteRecherche = "attaquant";
                    printf("=== Liste Attaquants ===\n");
                    break;
                default:
                    printf("Choix invalide.\n");
                    return;
            }

            for (int i = 0; i < NombreDeJoueurs; i++) {
                if (strcmp(Joueurs[i].poste, posteRecherche) == 0) {
                    printf("-----------------------------------------\n");
                    printf("Id : %d\n", Joueurs[i].id);
                    printf("Nom : %s\n", Joueurs[i].nom);
                    printf("Prenom : %s\n", Joueurs[i].prenom);
                    printf("Age : %d\n", Joueurs[i].age);
                    printf("Numero Maillot : %d\n", Joueurs[i].numeroMaillot);
                    printf("Poste : %s\n", Joueurs[i].poste);
                    printf("Buts : %d\n", Joueurs[i].buts);
                }
            }
            break;
        default:
            printf("Choix invalide.\n");
    }

    printf("\nAppuyez sur entree pour retourner au menu...");
    getchar();
    getchar();
    clearscreen();
}

// Recherche d'un joueur
void RechercheUnJoueur() {
    clearscreen();

    int ChoixDeRecherche;
    char nomPourRecherche[100];
    int idrecherche;
    int found = 0;

    printf("==== CHOIX DE RECHERCHE ====\n");
    printf("1. Par nom\n");
    printf("2. Par ID\n");
    printf("Votre choix : ");
    scanf(" %d", &ChoixDeRecherche);
    getchar();

    if (ChoixDeRecherche == 1) {
        printf("Entrer le nom : ");
        scanf(" %s", nomPourRecherche);
        for (int i = 0; i < NombreDeJoueurs; i++) {
            if (strcmp(Joueurs[i].nom, nomPourRecherche) == 0) {
                clearscreen();
                printf("=== Joueur trouvé ===\n");
                printf("Id : %d\n", Joueurs[i].id);
                printf("Nom : %s\n", Joueurs[i].nom);
                printf("Prenom : %s\n", Joueurs[i].prenom);
                printf("Age : %d\n", Joueurs[i].age);
                printf("Numero Maillot : %d\n", Joueurs[i].numeroMaillot);
                printf("Poste : %s\n", Joueurs[i].poste);
                printf("Buts : %d\n", Joueurs[i].buts);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Aucun joueur avec le nom '%s'.\n", nomPourRecherche);
        }
    } else if (ChoixDeRecherche == 2) {
        printf("Entrer l'ID : ");
        scanf(" %d", &idrecherche);
        for (int i = 0; i < NombreDeJoueurs; i++) {
            if (Joueurs[i].id == idrecherche) {
                clearscreen();
                printf("=== Joueur trouvé ===\n");
                printf("Id : %d\n", Joueurs[i].id);
                printf("Nom : %s\n", Joueurs[i].nom);
                printf("Prenom : %s\n", Joueurs[i].prenom);
                printf("Age : %d\n", Joueurs[i].age);
                printf("Numero Maillot : %d\n", Joueurs[i].numeroMaillot);
                printf("Poste : %s\n", Joueurs[i].poste);
                printf("Buts : %d\n", Joueurs[i].buts);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Aucun joueur avec l'ID %d.\n", idrecherche);
        }
    } else {
        printf("Choix invalide.\n");
    }

    printf("\nAppuyez sur entree pour retourner au menu...");
    getchar();
    getchar();
    clearscreen();
}

// Modifier un joueur
void ModifierUnJoueur() {
    char nomRecherche[100];
    char ouiNon;
    int modifierPosteJoueur;

    printf("Entrer le nom du joueur à modifier : ");
    scanf(" %s", nomRecherche);
    getchar();

    for (int i = 0; i < NombreDeJoueurs; i++) {
        if (strcmp(Joueurs[i].nom, nomRecherche) == 0) {
            printf("=== Le joueur existe ===\n");

            printf("Modifier le poste ? (O/N) : ");
            scanf(" %c", &ouiNon);
            getchar();
            if (ouiNon == 'o' || ouiNon == 'O') {
                printf("\t1. pour le gardien\n");
                printf("\t2. pour la defenseur\n");
                printf("\t3. pour le milieu\n");
                printf("\t4. pour l'attaquant\n");
                printf("Entrer le choix : ");
                scanf(" %d", &modifierPosteJoueur);
                getchar();

                switch (modifierPosteJoueur) {
                    case 1: strcpy(Joueurs[i].poste, "gardien"); break;
                    case 2: strcpy(Joueurs[i].poste, "defenseur"); break;
                    case 3: strcpy(Joueurs[i].poste, "milieu"); break;
                    case 4: strcpy(Joueurs[i].poste, "attaquant"); break;
                    default: printf("Choix invalide, poste non modifié.\n");
                }
            }

            printf("Modifier l'âge ? (O/N) : ");
            scanf(" %c", &ouiNon);
            getchar();
            if (ouiNon == 'o' || ouiNon == 'O') {
                printf("Entrer la nouvelle âge : ");
                scanf(" %d", &Joueurs[i].age);
                getchar();
            }

            printf("Modifier le nombre de buts ? (O/N) : ");
            scanf(" %c", &ouiNon);
            getchar();
            if (ouiNon == 'o' || ouiNon == 'O') {
                printf("Entrer le nouveau nombre de buts : ");
                scanf(" %d", &Joueurs[i].buts);
                getchar();
            }

            printf("Joueur modifié avec succès.\n");
            printf("Appuyez sur entree...");
            getchar();
            getchar();
            break; // fin boucle après modification
        }
    }

    clearscreen();
}

// Supprimer un joueur
void SupprimerUnJoueur() {
    int idsupprimer;
    int foundsupprimer = 0;
    char ouiNon;

    printf("Entrer l'ID du joueur à supprimer : ");
    scanf(" %d", &idsupprimer);
    getchar();

    for (int i = 0; i < NombreDeJoueurs; i++) {
        if (Joueurs[i].id == idsupprimer) {
            printf("Voullez-vous vraiment supprimer ce joueur ? (O/N) : ");
            scanf(" %c", &ouiNon);
            getchar();

            if (ouiNon == 'O' || ouiNon == 'o') {
                for (int j = i; j < NombreDeJoueurs - 1; j++) {
                    Joueurs[j] = Joueurs[j + 1];
                }
                NombreDeJoueurs--;
                foundsupprimer = 1;
                printf("Joueur supprimé.\n");
            }
            break;
        }
    }

    if (foundsupprimer != 1) {
        printf("Aucun joueur avec ID %d.\n", idsupprimer);
    }

    printf("Appuyez sur entree pour retourner au menu...");
    getchar();
    getchar();
}

// Statistiques
void Statistiques() {
    clearscreen();

    int choixStatistiques;
    int ageTotal = 0;
    int ageMoyen;
    int choixDeButs;

    printf("===== STATISTIQUES =====\n");
    printf("1. Nombre total de joueurs\n");
    printf("2. Age moyen des joueurs\n");
    printf("3. Joueurs ayant marqué plus de buts\n");
    printf("4. Joueur le plus jeune et le plus age\n");
    printf("Votre choix : ");
    scanf(" %d", &choixStatistiques);
    getchar();

    switch (choixStatistiques) {
        case 1:
            printf("Nombre total de joueurs : %d\n", NombreDeJoueurs);
            break;
        case 2:
            for (int i = 0; i < NombreDeJoueurs; i++) {
                ageTotal += Joueurs[i].age;
            }
            ageMoyen = (NombreDeJoueurs > 0) ? (ageTotal / NombreDeJoueurs) : 0;
            printf("Âge moyen : %d ans\n", ageMoyen);
            break;
        case 3:
            printf("Entrer le nombre de buts pour filtrer : ");
            scanf(" %d", &choixDeButs);
            printf("Joueurs ayant marqué plus de %d buts :\n", choixDeButs);
            for (int i = 0; i < NombreDeJoueurs; i++) {
                if (Joueurs[i].buts > choixDeButs) {
                    printf("-----------------------------------------\n");
                    printf("Id : %d\n", Joueurs[i].id);
                    printf("Nom : %s\n", Joueurs[i].nom);
                    printf("Prenom : %s\n", Joueurs[i].prenom);
                    printf("Age : %d\n", Joueurs[i].age);
                    printf("Numero Maillot : %d\n", Joueurs[i].numeroMaillot);
                    printf("Poste : %s\n", Joueurs[i].poste);
                    printf("Buts : %d\n", Joueurs[i].buts);
                }
            }
            break;
        case 4:
            if (NombreDeJoueurs > 0) {
                trieParOrderAge();
                printf("=== Joueur le plus jeune : %s ===\n", Joueurs[0].nom);
                printf("=== Joueur le plus age : %s ===\n", Joueurs[NombreDeJoueurs - 1].nom);
            } else {
                printf("Aucun joueur dans l'équipe.\n");
            }
            break;
        default:
            printf("Choix invalide.\n");
    }

    printf("Appuyez sur entree pour retourner au menu...");
    getchar();
    getchar();
    clearscreen();
}

// Quitter
int Quiter() {
    char ConfQuiter;

    clearscreen();

    printf("===== QUITTER =====\n");
    printf("Voulez-vous vraiment quitter ? (O/N) : ");
    scanf(" %c", &ConfQuiter);
    getchar();

    if (ConfQuiter == 'O' || ConfQuiter == 'o') {
        clearscreen();
        printf("\n* * * A R R I V É * * *\n");
        return 0;
    } else {
        clearscreen();
        printf("* * * Bienvenue à nouveau * * *\n");
        printf("Appuyez sur entree...\n");
        getchar();
        getchar();
        clearscreen();
        return 1;
    }
}

// Main
int main() {
    clearscreen();

    int choix;

    do {
        printf(" =============== MENU PRINCIPAL =============== \n");
        printf("|                                            |\n");
        printf("|   1. Ajouter un joueur                     |\n");
        printf("|   2. Afficher la liste des joueurs          |\n");
        printf("|   3. Rechercher un joueur                   |\n");
        printf("|   4. Modifier un joueur                     |\n");
        printf("|   5. Supprimer un joueur                    |\n");
        printf("|   6. Statistiques                           |\n");
        printf("|   0. Quitter                                |\n");
        printf("|                                            |\n");
        printf(" ============================================ \n");
        printf("=> Entrer votre choix : ");
        scanf("%d", &choix);
        getchar();

        switch (choix) {
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
                if (Quiter() == 1) {
                    choix = -1; // pour sortir de la boucle
                }
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
                break;
        }
    } while (choix != -1);

    return 0;
}