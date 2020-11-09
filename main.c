#include <stdlib.h>
#include <stdio.h>

#include "map.h"

char* tostring(void* arg);

int main()
{
    MapNode* map = m_NewMap("Partecipants", "17", NULL);
    m_AddCouple(map, "Place", (void*)19);  //for complier note, not needed
    
    printf("%s\n", m_GetValue(map, "Partecipants"));
    printf("%d\n", m_GetValue(map, "Place"));

    m_SetValue(map, "Place", "via lol");
    printf("%s\n%d\n\n", m_GetValue(map, "Place"), m_GetLength(map));

    if(m_ContainsKey(map, "Partecipants"))
        printf("It does\n");
    if(!m_ContainsKey(map, "PhoneNumber"))
        printf("It does not\n");

    // Testing nested maps
    m_AddCouple(map, "PhoneBook", m_NewMap("Davido", "339333333", NULL));
    m_AddCouple(m_GetValue(map, "PhoneBook"), "Miri", "3333333333");
    m_AddCouple(m_GetValue(map, "PhoneBook"), "Cala", "3663333333");

    m_PrintMap(map);
    m_PrintMap(m_GetValue(map, "PhoneBook"));

    m_RemoveElement((MapNode**)m_GetValuePointer(map, "PhoneBook"), "Davido");
    m_RemoveElement((MapNode**)m_GetValuePointer(map, "PhoneBook"), "Cala");
    m_AddCouple(m_GetValue(map, "PhoneBook"), "Conte", "391999229");
    m_PrintMap(m_GetValue(map, "PhoneBook"));

    return 0;
}