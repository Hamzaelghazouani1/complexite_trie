#include "../functions/triRapide.c"
#include "../functions/triInsertion.c"
#include "../functions/helper.c"

void triBulle(int [], int );
void triSelection(int [], int );
void triInsertion(int [], int );
void triRapide(int [], int );
void triFusion(int [], int );

void (*trier)(int [], int);