#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define done "done"
#define doing "doing"
#define SIZE 100

typedef struct date
{
   int day;
   int hour;
   int minut;
}date;


typedef struct todo_list
{
    int id;
    char tach[SIZE];
    char title[30];
    char discription[50];
    char statut[40];
}todo;

// green color \033[0;32m
// red color \033[0;31m
//white \033[0m

//time to see the deadline for each task
// = localtime(&now);
// t->tm_mday;  //for the day
// t->tm_hour; // for hour
// t->tm_min; // for minut

//used functions
void menu(void);
void ajoute(void);
void Afficher(void);
void Ajouter_plusieurs(void);
void sort_by_alpha(void);
void Modifier();
void Supprimer(void);
void Rechercher(void);
void Statistiques(void);
#endif
