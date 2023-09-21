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
        Supprimer();
        break;
    case 6:
        Rechercher();
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
char *sort_by_alpha(void)
{
    int i;
    int j;
    char *temp;
    FILE *temp_file;
    temp_file = fopen("temp.txt", "w");

    FILE *file;
    file = fopen("info.txt", "r");
    if (temp_file == NULL || file == NULL)
    {
        printf("Error!");
        exit(EXIT_SUCCESS);
    }

    i = 0;
    // while (fgets(temp_file, 255, file) != NULL)
    // {
    // 	j = 1;
    // 	if (strcmp(todos.tach, todos.tach + 1) > 0)
    // 	{
    // 		    temp = todos.tach + 1;
    // 			todos.tach + 1 = todos.tach;
    // 			todos.tach = temp;
    // 	}
    // 	i++;
    // }
}
void Modifier(void)
{
    system("cls");

    typedef struct
    {
        int id;
        char tach[SIZE];
        char title[30];
        char discription[50];
        char statut[40];
    } temp_todo;

    typedef struct
    {
        int day;
        int hour;
        int minut;
    } temp_date;

    temp_todo todo;     // for general info
    temp_date new_date; // for date
    date dates;
    FILE *file = fopen("info.txt", "r");
    FILE *temp_file = fopen("temp.txt", "w");

    int id, choice;
    printf("Enter the ID of the task you want to modify: ");
    scanf("%d", &id);

    if (file == NULL || temp_file == NULL)
    {
        printf("Error opening files.\n");
        exit(EXIT_FAILURE);
    }

    int found = 0; // Flag to check if the ID was found

    while (fscanf(file, "la id: %d \nla tache: %[^\n] \nle titre: %[^\n] \nla discription: %[^\n] \ndeadline: %d:%d:%d \nStatus: %[^\n]\n",
                  &todo.id, todo.tach, todo.title, todo.discription, &new_date.day, &new_date.hour, &new_date.minut, todo.statut) == 8)
    {
        if (id == todo.id)
        {
            found = 1;

            printf("Task found. What do you want to update?\n");
            printf("1. Description\n");
            printf("2. Statut\n");
            printf("3. Deadline\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            getchar(); // Clear the newline character

            if (choice == 1)
            {
                printf("Enter the new description: ");
                fgets(todo.discription, sizeof(todo.discription), stdin);
                strtok(todo.discription, "\n"); // remove newline if present
            }
            else if (choice == 2)
            {
                printf("Enter the new statut: ");
                fgets(todo.statut, sizeof(todo.statut), stdin);
                strtok(todo.statut, "\n"); // remove newline if present its like the split function it takes a pointer and delimter
            }
            else if (choice == 3)
            {
                printf("Enter the new deadline (day-hour-minut): ");
                scanf("%d-%d-%d", &new_date.day, &new_date.hour, &new_date.minut);
                getchar(); // Clear the newline character
            }

            // Write the updated information to temp_file
            fprintf(temp_file, "la id: %d \nla tache: %s \nle titre: %s \nla discription: %s \ndeadline: %d:%d:%d \nStatus: %s\n",
                    todo.id, todo.tach, todo.title, todo.discription, new_date.day, new_date.hour, new_date.minut, todo.statut);
        }
        else
        {
            // Write unchanged information to temp_file
            fprintf(temp_file, "la id: %d \nla tache: %s \nle titre: %s \nla discription: %s \ndeadline: %d:%d:%d \nStatus: %s\n",
                    todo.id, todo.tach, todo.title, todo.discription, new_date.day, new_date.hour, new_date.minut, todo.statut);
        }
    }

    fclose(file);
    fclose(temp_file);

    if (found)
    {
        remove("info.txt");
        rename("temp.txt", "info.txt");
        printf("Task with ID %d modified successfully.\n", id);
    }
    else
    {
        remove("temp.txt"); // Remove the temp file if the task was not found
        printf("Task with ID %d not found.\n", id);
    }
}

void Supprimer(void)
{
    system("cls");
    typedef struct date
    {
        int day;
        int hour;
        int minut;
    } dates;

    typedef struct todo_list
    {
        int id;
        char tach[SIZE];
        char title[30];
        char discription[50];
        char statut[40];
    } todo_s;

    dates new_date;
    todo_s new_todo;

    FILE *file = fopen("info.txt", "r");
    FILE *temp_file = fopen("temp.txt", "w");

    if (file == NULL || temp_file == NULL)
    {
        printf("error happned while opening the file");
        exit(EXIT_FAILURE);
    }

    int id, choice;
    printf("give the id of the task\n  $> ");
    scanf("%d", &id);

    while (fscanf(file, "la id: %d \nla tache: %[^\n] \nle titre: %[^\n] \nla discription: %[^\n] \ndeadline: %d:%d:%d \nStatus: %[^\n]\n",
                  &new_todo.id, new_todo.tach, new_todo.title, new_todo.discription, &new_date.day, &new_date.hour, &new_date.minut, new_todo.statut) == 8)
    {
        if (id != new_todo.id)
        {
            fprintf(temp_file, "la id: %d \nla tache: %s \nle titre: %s \nla discription: %s \ndeadline: %d:%d:%d \nStatus: %s\n",
                    new_todo.id, new_todo.tach, new_todo.title, new_todo.discription, new_date.day, new_date.hour, new_date.minut, new_todo.statut);
        }
        else
        {
            continue;
        }
    }
    fclose(file);
    fclose(temp_file);
    remove("info.txt");
    rename("temp.txt", "info.txt");
    printf("Task with ID %d deleted successfully.\n", id);
}

void Rechercher(void)
{
    typedef struct date
    {
        int day;
        int hour;
        int minut;
    } dates;

    typedef struct todo_list
    {
        int id;
        char tach[SIZE];
        char title[30];
        char discription[50];
        char statut[40];
    } todo_s;

    dates new_dates;
    todo_s todo_l;

    int choice, id;
    char title[30];
    printf("which method you want to use to search:\n");
    printf("[1]. Identifiant\n");
    printf("[2]. Titre\n");
    scanf("%d", &choice);

    FILE *file = fopen("info.txt", "r");
    FILE *file2 = fopen("temp.txt", "w");

    while (fscanf(file, "la id: %d \nla tache: %[^\n] \nle titre: %[^\n] \nla discription: %[^\n] \ndeadline: %d:%d:%d \nStatus: %[^\n]\n",
                  &todo_l.id, todo_l.tach, todo_l.title, todo_l.discription, &new_dates.day, &new_dates.hour, &new_dates.minut, todo_l.statut) == 8)
    {
        if(choice == 1)
        {
            printf("give the ID of the task\n");
            scanf("%d", &id);
            if(id == todo_l.id)
            {
                printf( "la id: %d \nla tache: %s \nle titre: %s \nla discription: %s \ndeadline: %d:%d:%d \nStatus: %s\n",
                  todo_l.id, todo_l.tach, todo_l.title, todo_l.discription, new_dates.day, new_dates.hour, new_dates.minut, todo_l.statut);
            }
            else
                printf("The Id %d Does Not Exist",id);
                continue;
        }
        if(choice == 2)
        {
            printf("give the title of the task\n");
            gets(title);
            if(strcmp(title, todo_l.title) == 0)
            {
                printf("la id: %d \nla tache: %s \nle titre: %s \nla discription: %s \ndeadline: %d:%d:%d \nStatus: %s\n",
                  todo_l.id, todo_l.tach, todo_l.title, todo_l.discription, new_dates.day, new_dates.hour, new_dates.minut, todo_l.statut);
            }
            else
                printf("The title %s Does Not Exist\n",title);
                continue;
        }
    }

   
}
