#include <stdio.h>
#include <string.h>
#include "liste.h"

typedef struct kettenglied
{
	struct kettenglied *vor, *nach;
	void* daten;

} Kettenglied;


static Kettenglied* start = NULL;
static Kettenglied* actual = NULL;

void liste_add(void* data)
{
	Kettenglied* neu = malloc(sizeof(Kettenglied));
	memset(neu, 0,sizeof(Kettenglied));
	neu->daten = data;
	if(liste_isEmpty())
	{
		start  = neu;
	} else
	{
		liste_moveLast();
		actual->nach = neu;
		neu->vor = actual;
	}
	actual = neu;
}

void list_insert(void* value) // insert value between actual and actual->nach
{
	// !!!!!!  Experimental  !!!!!! //

	// length(list) <= 1 oder ende der liste
	if (liste_isBOL() || liste_isEOL())
	{
		liste_add(value);
		return;
	}

	// middle of list:

	// turn this into a function -> create kettenglied()
	Kettenglied* neu = malloc(sizeof(Kettenglied));
	memset(neu, 0, sizeof(Kettenglied));
	neu->daten = value;
	// end funtion

	actual->vor->nach = neu;
	actual->nach->vor = neu;
}

void* liste_get() // return data for current pointer if not empty:NULL
{
	return liste_isEmpty() ? NULL : actual->daten;
}

bool liste_update(void* value) // change value at current position
{
	if (liste_isEmpty()) {
		return false;
	}

	actual->daten = value;

	return true;
}

bool liste_remove() // remove current part from chain
{
	if (liste_isEmpty()) // liste ist leer
		return false;

	Kettenglied* toDelete = actual;

	if (liste_isEOL() && liste_isBOL()) { // nur 1 objekt in liste
		start = NULL;
		actual = NULL;
	}
	else if (liste_isEOL()) { // ende der liste
		liste_movePrevious();
		actual->nach = NULL;
	}
	else if (liste_isBOL()) { // anfang der liste
		liste_moveNext();
		start = actual;
		actual->vor = NULL;
	}
	else {
		// middle of list
		actual->vor->nach = actual->nach;
		actual->nach->vor = actual->vor;
		liste_moveNext();
	}

	// clear actual
	free(toDelete); // löscht den eintrag an der stelle &toDelete

	return true;
}

void liste_removeAll() // remove all chain part of list
{
	while(liste_remove()) {}
}

bool liste_moveNext()
{
	if (liste_isEOL())
		return false; // no more chainpart

	actual = actual->nach;

	return true;
}

bool liste_movePrevious()
{
	if (liste_isBOL())
		return false; // no more chainpart

	actual = actual->vor;

	return true;
}

bool liste_moveFirst()
{
	// return liste_isEmpty() ? false : true;

	if (liste_isEmpty())
		return false;

	while (liste_movePrevious()) {}

	return true;

	/*
	parameter = int index
	liste_movePrevious();
	return list_isEmpty() ? false : liste_isBOL() ? true : liste_moveFirst(index + 1);
	*/
}

bool liste_moveLast()
{
	if (liste_isEmpty())
		return false;

	while (liste_moveNext()) {}

	return true;
}

bool liste_isEmpty()
{
	return start;
}

bool liste_isBOL()
{
	return start == actual;
}

bool liste_isEOL(){
	return liste_isEmpty() || actual->nach;
}