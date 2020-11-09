#ifndef MAP_C
#define MAP_C

#include <stdlib.h>
#include <stdio.h>

#include "map.h"

MapNode* m_NewMap(char* key, void* value, MapNode* next)
{
    MapNode* result = 
        (MapNode*)malloc(sizeof(MapNode));

    result->key = key;
    result->value = value;
    result->next = next;

    return result;
}

MapNode* m_GetLast (MapNode* start)
{
    if (start == NULL) return NULL;

    MapNode* current = start; 
    while (current->next != NULL)
        current = current->next;

    return current;
}

MapNode* m_AddCouple (MapNode* start, char* key, void* value)
{
    if (start == NULL) return NULL;

    MapNode* map = m_GetLast(start);

    MapNode * newMapNode = m_NewMap(key, value, NULL);
    map->next = newMapNode;
}

void* m_GetValue (MapNode* start, char* key)
{
    if (start == NULL) return NULL;

    MapNode* current = start;
    while (current != NULL && current->key != key)
        current = current->next;

    return (void*)(current->value);
}

void** m_GetValuePointer (MapNode* start, char* key)
{
    if (start == NULL) return NULL;

    MapNode* current = start;
    while (current != NULL && current->key != key)
        current = current->next;

    return &(current->value);
}

void m_SetValue (MapNode* start, char* key, void* value)
{
    if (start == NULL) return;

    MapNode* current = start;
    while (current != NULL && current->key != key)
        current = current->next;

    current->value = value;
}

unsigned int m_GetLength (MapNode* start)
{
    if (start == NULL)
        return 0;

    unsigned int count;
    MapNode* current;
    
    for (
        current = start, count = 1;
        current->next != NULL;
        current = current->next, count++);

    return count;
}

bool m_ContainsKey (MapNode* start, char* key)
{
    if (start == NULL) return false;

    MapNode* current;
  
    for (current = start; current != NULL; current = current->next)
        if (current->key == key)
            return true;
    return false;
}

void m_RemoveElement (MapNode** start, char* key)
{
    if (start == NULL) return;

    MapNode* current = *start;

    if (current->key == key)
    {
        *start = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->next->key != key)
        current = current->next;

    MapNode* nextMapNode = current->next->next;
    free(current->next);
    current->next = nextMapNode;

    return;
}

// ONLY WORKING FOR DEBUGGING STRING-STRING map
MapNode* m_PrintMap (MapNode* start)
{
    printf("MAP: \n");

    MapNode* current = start;
    while (current != NULL)
    {    
        printf("%s - %s\n", current->key, current->value);
        current = current->next;
    }
}

#endif // !MAP_H