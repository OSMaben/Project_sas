#include "main.h"
// main function


todo todos; // rename the struct

int main(void)
{
    menu();
}

// menu function
void menu(void)
{
    int s;
    printf("============================");
    printf("\n***** TO DO LIST *****\n");
    printf("============================\n");

    printf("[1] Ajouter une nouvelle tache\n");
    printf("[2] Ajouter plusieurs nouvelles taches\n");
    printf("[3] Afficher la liste de toutes les taches\n");
    printf("[4] Modifier une tache\n");
    printf("[5] Supprimer une tache par identifiant\n");
    printf("[6] Rechercher les Taches\n");
    printf("[7] Statistiques\n ==>");

    scanf("%d", &s);

    switch (s)
    {
    case 1:
        ajoute();
        break;
    case 2:
        Ajouter_plusieurs();
        break;
    case 3:
        Afficher();
        break;
    case 4:
        Modifier();
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    default:
        break;
    }
    main();
}
void ajoute(void)
{

    date date;
    printf("Donne un ID pour la tache:\n$> ");
    scanf("%d", &todos.id);
    getchar(); // this is used to take the \n when the user press inter
    printf("La tache:\n$> ");
    gets(todos.tach);
    printf("Donne un titre:\n$> ");
    gets(todos.title);
    printf("Donne une description:\n$> ");
    gets(todos.discription);
    printf("Donne une deadline comme day/hour/minut:\n$> ");
    scanf("%d/%d/%d", &date.day, &date.hour, &date.minut);
    getchar();
    printf("Statut de la tache:\n$> ");
    gets(todos.statut);
    printf("\033[0;32m");
    printf("Done\n");
    printf("\033[0m");

    // add the info to a file

    // ... (previous code)

    FILE *file;
    file = fopen("info.txt", "a");
    if (file == NULL)
    {
        printf("Error!");
        exit(1);
    }
    fprintf(file, "la id: %d \nla tache: %s \nle titre: %s \nla discription: %s \ndeadline: %d:%d:%d \nStatus: %s\n",
            todos.id, todos.tach, todos.title, todos.discription, date.day, date.hour, date.minut, todos.statut);

    fclose(file);
}
void Ajouter_plusieurs(void)
{
    int s, i = 0;

    printf("inter le number des taches\n");
    scanf("%d", &s);
    while (i < s)
    {
        ajoute();
        i++;
    }
}
void Afficher(void)
{
    char yN; // yes or not
    int i, j, temp;
    int a; // for get which sort the user wants
    date date;

    FILE *info;
    info = fopen("info.txt", "r");
    char buffer[255];
    printf("\n\n \tHere Are The Info \n");
    // fgets takes 3 params the buffer to copy info
    //, the size of the chars, the file to read from
    while (fgets(buffer, 255, info) != NULL)
    {
        printf("%s", buffer);
    }
    fclose(info);

    // printf("\n\nDo you want them Sorted ? Y or N \n $>");
    // scanf("%s", &yN);

    // if (yN == 'Y')
    // {
    // }
    // else if (yN == 'N')
    // {
    //     printf("\033[0;32m");
    //     printf("Done\n");
    //     printf(" \033[0m");
    // }
    // else
    // {
    //     printf("\033[0;31m");
    //     printf("please choose either yes or no\n");
    //     printf(" \033[0m");
    // }
}
