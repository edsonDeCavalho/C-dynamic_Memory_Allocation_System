//
// Created by nudian on 01/04/2021.
//

struct Operation{
    int variable;
    char valueChar;
    int valueInt;
    int operation;
    int reallocValue;
};

struct Operation entryOftheOperation();

struct TestInstructions{
    int nBoperations;
    struct Operation operations[4];
};




void MainTest(struct Operation *operation);
struct TestInstructions readFile(const char *file);




void menuInteractif();
void menuBash();
void menuFile();
void menuLigneCommande();