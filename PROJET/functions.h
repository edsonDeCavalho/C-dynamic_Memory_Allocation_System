//
// Created by nudian on 28/03/2021.
//
struct DonnesProgramme {
    char *AdresseMemoireInitiale;
    char *AdresseMemoireMax;
    char *AdresseMemoireAcuelle;
    int taillePageDuSysteme;
    int tailleMemoireTotal;
};

void initMemory(int nbytes);
void* myalloc(int nBytes);



void affichageStatusMemoire();
void initUtils(int nBytes);
void setTailleDePageSysteme();
int calculTaille(int tailleVariable);
void * calculPourLaPage(char *ancienneAdresse, int nBytes);
struct DonnesProgramme createDetailsProgrmme(int nBytes);