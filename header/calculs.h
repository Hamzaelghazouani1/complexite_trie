void randomInit(int[], int);
float mesurer(void (*trie)(int[], int), int[], int);
void lisserMesures(float**, int, int);

#define NB_PTS_MAX 10000
#define NB_METH_MAX 10

float mesures[NB_PTS_MAX][NB_METH_MAX];

int nb_points = 0, nb_methode = 0;