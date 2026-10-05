#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

enum{max_participants=100};
typedef struct {
    char prenom[31];
    char nom[31];
    unsigned int identifiant;
} Participant;

Participant inscrire(char prenom[], char nom[], unsigned int nombre_paticipants) {
    Participant retour;
    strcpy(retour.prenom, prenom);
    strcpy(retour.nom, nom);
    retour.identifiant = nombre_paticipants;
    return retour;
}

int test_validite_inscrire(Participant liste_participants[], char prenom[], char nom[], unsigned int nombres_participants){
    for (int i = 0;i < nombres_participants;++i) {
        if (strcmp(liste_participants[i].prenom, prenom) == 0 &&
            strcmp(liste_participants[i].nom, nom) == 0){
            return 0;
        }
    }
    return 1;
}


int main()
{
    char commande[100];
    Participant liste_participant[max_participants];
    unsigned int nombre_participants = 0;
    char prenom[31];
    char nom[31];
    int validite;

    while (1)
    {
        printf("Entrez une commande\n");
        scanf("%s", &commande);
        if (strcmp(commande, "EXIT") == 0)
        {
            break;
        }
        if (strcmp(commande, "INSCRIRE") == 0)
        {
            scanf("%s %s", &prenom, &nom);
            validite=test_validite_inscrire(liste_participant, prenom, nom,nombre_participants);
            if (validite) {
                ++nombre_participants;
                Participant part;
                part = inscrire(
                    prenom,
                    nom,
                    nombre_participants);
                liste_participant[nombre_participants - 1] = part;
                printf("Inscription enregistree (%u)\n", nombre_participants);
            }
            else {
                printf("Nom incorrect\n");
            }
        }
    }

    return 0;
}
