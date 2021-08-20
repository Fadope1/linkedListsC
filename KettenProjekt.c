// KettenProjekt.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <stdio.h>
#include <string.h>
#include "liste.h"

typedef struct
{
	char name[31];
	int gewicht;

} Schwein;

int main()
{
	//Schwein piggy = { "Miss Piggy", 10 };
	//liste_add(&piggy);

	Schwein *piggy = malloc(sizeof(Schwein));

	strcpy_s(piggy->name, 20, "Miss Piggy");
	piggy->gewicht = 10;
	liste_add(piggy);

	free(piggy);
}


