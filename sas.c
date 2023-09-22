#include "main.h"
// main function

todo todos; // rename the struct
date dates;

time_t now;
struct tm *t;

int main(void)
{
    menu();
}

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
    printf("[7] Statistiques\n");
    printf("[8] Quit\n ==>");

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
        Statistiques();
        break;
    case 8:
    return;
        break;
    default:
        break;
    }
    main();
}
void ajoute(void)
{
    FILE *file1 = fopen("info.txt", "r");
    time(&now);
    t = localtime(&now);
    int day = t->tm_mday;
    int hour = t->tm_hour;
    int minut = t->tm_min;

    date date;
    printf("Donne un ID pour la tache:\n$> ");
    scanf("%d", &todos.id);
    if(todos.id)
    {
        while(fscanf(file1, "la id: %d \nla tache: %[^\n] \nle titre: %[^\n] \nla discription: %[^\n] \ndeadline: %d:%d:%d \nStatus: %[^\n]\n",
                        &todos.id, todos.tach, todos.title, todos.discription, &dates.day, &dates.hour, &dates.minut, todos.statut) == 8)
            {
                if (todos.id  == todos.id)
                {
                   printf("this ID is Already Exists\n");
                   printf("give an other ID \n $> ");
                    scanf("%d", &todos.id);
                   break;
                }
                else
                    continue;
            }
    }
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
            todos.id, todos.tach, todos.title, todos.discription, date.day + day, date.hour + hour, date.minut + minut, todos.statut);

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

    printf("\n\nDo you want them Sorted ? Y or N \n $>");
    scanf("%s", &yN);

    if (yN == 'Y')
    {
        sort_by_alpha();
    }
    else if (yN == 'N')
    {
        printf("\033[0;32m");
        printf("Done\n");
        printf(" \033[0m");
    }
    else
    {
        printf("\033[0;31m");
        printf("please choose either yes or no\n");
        printf(" \033[0m");
    }
}
void sort_by_alpha(void)
{
    system("cls");
    typedef struct todo_list
    {
        int id;
        char tach[SIZE];
        char title[30];
        char discription[50];
        date dates;
        char statut[40];
    } todo_s;

    todo_s *tab;
    todo_s temp_list;

    if (tab != NULL)
    {
        free(tab);
    }

    time(&now);
    t = localtime(&now);
    int day = t->tm_mday;
    int hour = t->tm_hour;
    int minut = t->tm_min;

   
    int choice;
    char *temp;
    char buffer[255];
    FILE *temp_file;
    FILE *file;

    file = fopen("info.txt", "r");
    if (temp_file == NULL || file == NULL)
    {
        printf("Error!");
        exit(EXIT_SUCCESS);
    }

    printf("which why you want to use to sort\n");
    printf("[1]. Trier les tâches par ordre alphabétique.\n");
    printf("[2]. Trier les tâches par deadline.\n");
    printf("[3]. Afficher les tâches dont le deadline est dans 3 jours ou moins.\n $> ");
    scanf("%d", &choice);

    if (choice == 1)
    {
    int n = 0; // Initialize n to 0
    tab = (todo_s *)malloc(100 * sizeof(todo_s));  // Allocate memory for tab

    while (fscanf(file, "la id: %d \nla tache: %[^\n] \nle titre: %[^\n] \nla discription: %[^\n] \ndeadline: %d:%d:%d \nStatus: %[^\n]\n",
                    &tab[n].id, tab[n].tach, tab[n].title, tab[n].discription, &tab[n].dates.day, &tab[n].dates.hour, &tab[n].dates.minut, tab[n].statut) == 8)
    {
        n++;
    }
    // Sorting logic
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(tab[j].tach, tab[j + 1].tach) > 0)
            {
                temp_list = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp_list;
            }
        }
    }

    // Printing tasks
    for (i = 0; i < n; i++)
    {
        printf("==================================================\n");
        printf("la id: %d \nla tache: %s \nle titre: %s \nla discription: %s \ndeadline: %d:%d:%d \nStatus: %s\n",
                tab[i].id, tab[i].tach, tab[i].title, tab[i].discription, tab[i].dates.day, tab[i].dates.hour, tab[i].dates.minut, tab[i].statut);
    }

    // Free allocated memory for tab
    free(tab);
    }

    if(choice == 2)
    {
        int n = 0;
         tab = (todo_s *)malloc(100 * sizeof(todo_s));  // Allocate memory for tab
        while(fscanf(file, "la id: %d \nla tache: %[^\n] \nle titre: %[^\n] \nla discription: %[^\n] \ndeadline: %d:%d:%d \nStatus: %[^\n]\n",
                    &tab[n].id, tab[n].tach, tab[n].title, tab[n].discription, &tab[n].dates.day, &tab[n].dates.hour, &tab[n].dates.minut, tab[n].statut) == 8)
        {
            n++;
        }

        int i = 0;
        while(i < n)
        {
           int j = 0;
            while(j < n)
            {
                if(tab[j].dates.day > tab[j + 1].dates.day)
                {
                    temp_list = tab[j];
                    tab[j] = tab[j + 1];
                    tab[j + 1] = temp_list;
                }
                j++;
            }
            i++;
        }
        i = 0;
        while(i < n)
        {
            printf("=======================================\n");
            printf("la id: %d \nla tache: %s \nle titre: %s \nla discription: %s \ndeadline: %d:%d:%d \nStatus: %s\n",
                tab[i].id, tab[i].tach, tab[i].title, tab[i].discription, tab[i].dates.day, tab[i].dates.hour, tab[i].dates.minut, tab[i].statut);
            i++;
        }
        free(tab);
    }

    if (choice == 3)
    {
        while (fscanf(file, "la id: %d \nla tache: %[^\n] \nle titre: %[^\n] \nla discription: %[^\n] \ndeadline: %d:%d:%d \nStatus: %[^\n]\n",
                      &todos.id, todos.tach, todos.title, todos.discription, &dates.day, &dates.hour, &dates.minut, todos.statut) == 8)
        {
            if (dates.day <= 3)
            {
                printf("====================================================\n");
                printf("la id: %d \nla tache: %s \nle titre: %s \nla discription: %s \ndeadline: %d:%d:%d \nStatus: %s\n",
                       todos.id, todos.tach, todos.title, todos.discription, dates.day, dates.hour, dates.minut, todos.statut);
            }
            else
            {
                printf("\033[0;32m");
                printf("this task is more then 2 days\n");
                printf("\033[0m");
            }
        }
    }
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
    char *title;
    title = (char *)malloc(50 * sizeof(char));
    printf("which method you want to use to search:\n");
    printf("[1]. Identifiant\n");
    printf("[2]. Titre\n");
    scanf("%d", &choice);

    FILE *file = fopen("info.txt", "r");
    FILE *file2 = fopen("temp.txt", "w");

    if (choice == 2)
    {
        while (fscanf(file, "la id: %d \nla tache: %[^\n] \nle titre: %[^\n] \nla discription: %[^\n] \ndeadline: %d:%d:%d \nStatus: %[^\n]\n",
                      &todo_l.id, todo_l.tach, todo_l.title, todo_l.discription, &new_dates.day, &new_dates.hour, &new_dates.minut, todo_l.statut) == 8)
        {
            printf("give the title of the task\n");
            scanf("%s", title);
            if (strcmp(title, todos.title) == 0)
            {
                printf("====================================================\n");
                printf("la id: %d \nla tache: %s \nle titre: %s \nla discription: %s \ndeadline: %d:%d:%d \nStatus: %s\n",
                       todo_l.id, todo_l.tach, todo_l.title, todo_l.discription, new_dates.day, new_dates.hour, new_dates.minut, todo_l.statut);
            }
            else
            {
                printf("The title %s Does Not Exist\n", title);
                continue;
            }
        }

        while (fscanf(file, "la id: %d \nla tache: %[^\n] \nle titre: %[^\n] \nla discription: %[^\n] \ndeadline: %d:%d:%d \nStatus: %[^\n]\n",
                      &todo_l.id, todo_l.tach, todo_l.title, todo_l.discription, &new_dates.day, &new_dates.hour, &new_dates.minut, todo_l.statut) == 8)
        {
            if (choice == 1)
            {
                printf("give the ID of the task\n");
                scanf("%d", &id);
                if (id == todo_l.id)
                {
                    printf("====================================================\n");
                    printf("la id: %d \nla tache: %s \nle titre: %s \nla discription: %s \ndeadline: %d:%d:%d \nStatus: %s\n",
                           todo_l.id, todo_l.tach, todo_l.title, todo_l.discription, new_dates.day, new_dates.hour, new_dates.minut, todo_l.statut);
                }
                else
                    printf("The Id %d Does Not Exist", id);
                continue;
            }
        }
    }
    fclose(file);
    fclose(file2);
    remove("info.txt");
    rename("temp.txt", "info.txt");
}
void Statistiques(void)
{
    int exists = 0;
    int dn = 0, dng = 0;
    int choice;
    printf("1. Afficher le nombre total des tâches.\n");
    printf("2. Afficher le nombre de tâches complètes et incomplètes.\n");
    printf("3. Afficher le nombre de jours restants jusqu'au délai de chaque tâche.\n");
    scanf("%d", &choice);

    FILE *file = fopen("info.txt", "r");

    if (choice == 1)
    {
        while (fscanf(file, "la id: %d \nla tache: %[^\n] \nle titre: %[^\n] \nla discription: %[^\n] \ndeadline: %d:%d:%d \nStatus: %[^\n]\n",
                      &todos.id, todos.tach, todos.title, todos.discription, &dates.day, &dates.hour, &dates.minut, todos.statut) == 8)
        {
            if (todos.id)
            {
                exists++;
            }
            else
            {
                printf("there is not ID\n");
                break;
            }
        }
        printf("\nthe number of taches is $> %d\n", exists);
    }
    if (choice == 2)
    {
        while (fscanf(file, "la id: %d \nla tache: %[^\n] \nle titre: %[^\n] \nla discription: %[^\n] \ndeadline: %d:%d:%d \nStatus: %[^\n]\n",
                      &todos.id, todos.tach, todos.title, todos.discription, &dates.day, &dates.hour, &dates.minut, todos.statut) == 8)
        {
            if (strcmp(todos.statut, doing) == 0)
            {
                dng++;
            }
            else if (strcmp(todos.statut, done) == 0)
            {
                dn++;
            }
            else
            {
                printf("\033[0;32m");
                printf("the tasks are done\n");
                printf("\033[0m");
            }
        }
        printf("here is the number of tasks doing %d\n", dng);
        printf("here is the number of task done %d\n", dn);
    }

    else if (choice == 3)
    {
        // time_t now;
        // struct tm *t;

        time(&now);
        t = localtime(&now);
        int day = t->tm_mday;
        int hour = t->tm_hour;
        int minut = t->tm_min;

        while (fscanf(file, "la id: %d \nla tache: %[^\n] \nle titre: %[^\n] \nla discription: %[^\n] \ndeadline: %d:%d:%d \nStatus: %[^\n]\n",
                      &todos.id, todos.tach, todos.title, todos.discription, &dates.day, &dates.hour, &dates.minut, todos.statut) == 8)
        {
            printf("====================================================\n");
            printf("la id: %d \nla tache: %s \nle titre: %s \nla discription: %s \ndeadline: %d:%d:%d \nStatus: %s\n",
                   todos.id, todos.tach, todos.title, todos.discription, abs(dates.day - day), abs(dates.hour - hour), abs(dates.minut - minut), todos.statut);
        }
        // printf("Tâche ID: %d, Jours restants: %d\n", todos.id, daysDifference);
    }
}
