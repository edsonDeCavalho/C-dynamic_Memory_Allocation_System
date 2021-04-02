//
// Created by nudian on 01/04/2021.
//

struct Operation{
    int variable;
    void* value;
    int operation;
    int reallocValue;
};

struct TestInstructions{
    int typeMenu;
    int taille;
    int nBoperations;
    struct Operation *operations[];
};


int getTille(struct TestInstructions testinstructions);
int getNbOperations(struct TestInstructions testinstructions);
struct Operation creationOfAnOperation();
void reallocOperation(void* variable,int valeur);
void Test(struct Operation operation);
void freeOperation(void*variable);

void menuInteractif();
void menuBash();
void menuFile();
void menuLigneCommande();