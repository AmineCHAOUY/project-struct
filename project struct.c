#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 50
#define NAME_LENGTH  50
#define NUMERO_LENGTH 50
#define EMAIL_LENGTH 50
#define NOMBRE_LENGTH 50

void clearBuffer();
void add_contact();
void modifier_contact();
void supprimer_contact();
void afficher_cantact();
void recherche_cantact();



typedef struct{
char name[NAME_LENGTH];
char number[NUMERO_LENGTH];
char email[EMAIL_LENGTH];
char nombre[NOMBRE_LENGTH];
}contact;

contact contacts[MAX_CONTACTS];
int cont_act =0;


int main(){
   int choice;

    while (1) {
        printf("\nCarnet de Contacts\n");
        printf("1. Ajouter un contact\n");
        printf("2. Modifier un contact\n");
        printf("3. Supprimer un contact\n");
        printf("4. Afficher tous les contacts\n");
        printf("5. Rechercher un contact\n");
        printf("6. Quitter\n");
        printf("Choisissez une option: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
               add_contact();
                break;
            case 2:
               modifier_contact();
                break;
            case 3:
               supprimer_contact();
                break;
            case 4:
               afficher_cantact();
                break;
            case 5:
               recherche_cantact();
                break;
            case 6:

             printf("Au revoir!\n");
              exit(0);
            default:
                printf("Option invalide. Veuillez réessayer.\n");
        }
    }

    return 0;
}

void add_contact() {
    if (cont_act >= MAX_CONTACTS) {
        printf("Le carnet de contacts est plein.\n");
        return;
    }

    contact Ajouter;
    printf("Entrez le nom: ");
    scanf("%s", Ajouter.name);
    printf("Entrez le numéro de téléphone: ");
    scanf("%s", Ajouter.number);
    printf("Entrez l'adresse e-mail: ");
    scanf("%s", Ajouter.email);
    printf("Entrez le Nombre : ");
    scanf("%s", Ajouter.nombre);
    contacts[cont_act++] = Ajouter;
    printf("Contact ajouté avec succès.\n");
}
void modifier_contact(){
int choix;
char name[NAME_LENGTH];
char nombre[NOMBRE_LENGTH];
do {
    printf("1.Modifier Sur Nom:\n");
    printf("2.Modifier Sur Nombre:\n");
    printf("3.RETURNER:\n");
    printf(" Entrez voter choice:\t");
    scanf("%d",&choix);
    if(choix == 1){
          printf("Entrez le nom du contact à modifier: ");
    scanf("%s", name);

    for (int i = 0; i < cont_act; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Modifier le numéro de téléphone (ancien: %s): ", contacts[i].number);
            scanf("%s", contacts[i].number);
            printf("Modifier l'adresse e-mail (ancienne: %s): ", contacts[i].email);
            scanf("%s", contacts[i].email);
             printf("Modifier l'adresse Nombre (ancienne: %s): ", contacts[i].nombre);
            scanf("%d", contacts[i].nombre);
            printf("Contact modifié avec succès.\n");

            return;
        }
    }

    printf("Contact non trouvé.\n");
    }
    if(choix == 2){
         printf("Entrez le nombre du contact à modifier: ");
    scanf("%d", nombre);

    for (int i = 0; i < cont_act; i++) {
        if (strcmp(contacts[i].nombre, nombre) == 0) {
            printf("Modifier le numéro de téléphone (ancien: %s): ", contacts[i].number);
            scanf("%s", contacts[i].number);
            printf("Modifier l'adresse e-mail (ancienne: %s): ", contacts[i].email);
            scanf("%s", contacts[i].email);
             printf("Modifier  Nom (ancienne: %s): ", contacts[i].name);
            scanf("%s", contacts[i].name);
            printf("Contact modifié avec succès.\n");

            return;
        }
    }

    printf("Contact non trouvé.\n");
    }
    }while(choix!=3);
    printf("Au revoir!\n");
    return ;
}
void supprimer_contact(){
int choix;
char name[NAME_LENGTH];
char nombre[NOMBRE_LENGTH];
do {
    printf("1.Supprimer Sur Nombre:\n");
    printf("2.Supprimer Sur Nom:\n");
    printf("3.RETURNER:\n");
    printf(" Entrez voter choice:\t");
    scanf("%d",&choix);
    if(choix == 1){
        printf("Entrez le nombre du contact à Supprimer: ");
    scanf("%s", nombre);
    for (int i = 0; i < cont_act; i++) {
        if (strcmp(contacts[i].nombre, nombre) == 0) {
            for (int j = i; j < cont_act - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            cont_act--;
            printf("Contact supprimé avec succès.\n");
            return;
        }
    }

    printf("Contact non trouvé.\n");
    }
    if(choix == 2){
        printf("Entrez le Nom du contact à Supprimer: ");
    scanf("%s", name);
    for (int i = 0; i < cont_act; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < cont_act - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            cont_act--;
            printf("Contact supprimé avec succès.\n");
            return;
        }
    }
    }
}while(choix!=3);
printf("Au revoir!\n");
return ;
}
void afficher_cantact(){
 if (cont_act == 0) {
        printf("Aucun contact à afficher.\n");
        return;
    }

    printf("Liste des contacts:\n");
    for (int i = 0; i < cont_act; i++) {
        printf("Nom: %s, Téléphone: %s, Email: %s, Nombre: %s\n", contacts[i].name,
                contacts[i].number, contacts[i].email,contacts[i].nombre);
    }
}
void recherche_cantact(){
int choix;
char name[NAME_LENGTH];
char nombre[NOMBRE_LENGTH];
do {
    printf("1.Recherche Sur Nom:\n");
    printf("2.Recherche Sur Nombre:\n");
    printf("3.RETURNER:\n");
    printf(" Entrez voter choice:\t");
    scanf("%d",&choix);
    if(choix == 1){
          printf("Entrez le Nom du contact à Recherche: ");
    scanf("%s", name);
     for (int i = 0; i < cont_act; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact trouvé: Nom: %s, Téléphone: %s, Email: %s, Nombre: %s\n", contacts[i].name,
                contacts[i].number, contacts[i].email,contacts[i].nombre);
            return;
        }
    }

    printf("Contact non trouvé.\n");
}
if(choix == 2){
    printf("Entrez le Nombre du contact à Recherche: ");
    scanf("%s", nombre);
     for (int i = 0; i < cont_act; i++) {
        if (strcmp(contacts[i].nombre, nombre) == 0) {
            printf("Contact trouvé: Nom: %s, Téléphone: %s, Email: %s, Nombre: %s\n", contacts[i].name,
                contacts[i].number, contacts[i].email,contacts[i].nombre);
            return;
        }
    }

    printf("Contact non trouvé.\n");
}
}while(choix!=3);
printf("Au revoir!\n");
return ;
}
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}