/*!
 * \file utils.h
 * \brief File who contains all the declaration of structures and functions to help doing the differents
 * \author De Carvalho Edson , Wang Alexandre
 * \date 3 April 2021
 * \version 2.7
 */
/**
 * \struct Operation utils.h "Operation"
 * \brief This structure represent an operation to do.
 *
 * This structure is shared throughout the project contains
 * it's the values of a future test to the test.
 */
struct Operation{
    int variable; /*!< Represents the type of variable that the users ca choose. */
    char valueChar;
    int valueInt;
    int operation;  /*!< Object who store the operation choosen by the user. */
    int reallocValue; /*!< Object who store the value of an reallc. */
};

struct Operation entryOftheOperation();

/**
 * \struct TestInstructions utils.h "Set of tests"
 * \brief This structure represent an set of tests.
 *
 * This structure store a set of Operation objects who are
 * made in the Bash mode.
 */

struct TestInstructions{
    int nBoperations; /*!< Store the number of operations presents in the array of Operations. */
    struct Operation operations[4]; /*!< Store all of the operations to do. */
};

void MainTest(struct Operation *operation);
struct TestInstructions readFile(const char *file);
int numberOfLines(const char *file);
void menuInteractif();
