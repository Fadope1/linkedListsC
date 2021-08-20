#pragma once
#include <stdbool.h>

#define pass {}

void liste_add(void* data);
void * liste_get();
bool liste_update(void *); // false -> Liste ist leer Erfolg ->true
bool liste_remove();

bool liste_movePrevious();
bool liste_moveNext();
bool liste_moveFirst();
bool liste_moveLast();


bool liste_isEmpty();
bool liste_isBOL(); // Begin Of List True wenn entweder die Liste leer ist ODER wir AUF dem ersten Satz stehen
bool liste_isEOL(); // Begin Of List True wenn entweder die Liste leer ist ODER wir AUF dem letzten Satz stehen