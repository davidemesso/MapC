#ifndef MAP_H
#define MAP_H

#include "utility.h"

// Simple Map Node struct
typedef struct MapNode
{
  char* key;

  void* value;
  
  struct MapNode* next;  
} MapNode;

// Prototypes definitions
MapNode* m_NewMap (char* key, void* value, MapNode* next);
MapNode* m_GetLast (MapNode* start);
MapNode* m_AddCouple (MapNode* start, char* key, void* value);
void* m_GetValue (MapNode* start, char* key);
void** m_GetValuePointer (MapNode* start, char* key);
void  m_SetValue (MapNode* start, char* key, void* value);
unsigned int m_GetLength (MapNode* start);
bool m_ContainsKey (MapNode* start, char* key);
void m_RemoveElement (MapNode** start, char* key);       

MapNode* m_PrintMap (MapNode* start);

#endif // !MAP_H