#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 5

typedef struct
{
    int nameCardID;
    char personName[20];
    char companyName[20];
} NameCard;
// Function Prototypes
void listNameCards(NameCard *list, int size);
void addNameCard(NameCard *list, int *size);
void removeNameCard(NameCard *list, int *size, char *target);
void getNameCard(NameCard *list, int *size, char *target);
// Main Function
int main()
{
    int choice, size=0;
    NameCard record[MAX];
    char *p, target[20], dummy;

    printf("NTU NAME CARD HOLDER MANAGEMENT PROGRAM:\n"
    "1: listNameCards()\n"
    "2: addNameCard()\n"
    "3: removeNameCard()\n"
    "4: getNameCard()\n"
    "5: quit\n");
    
    do
    {
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            printf("listNameCards():\n");
            listNameCards(record, size);
            break;

            case 2:
            printf("addNameCard():\n");
            addNameCard(record, &size);
            break;

            case 3:
            printf("removeNameCard():\n");
            printf("Enter personName:\n");
            scanf("%c", &dummy);
            fgets(target, 20, stdin);
            if (p = strchr(target, '\n'))
                *p = '\0';
            removeNameCard(record, &size, target);
            break;

            case 4:
            printf("getNameCard():\n");
            printf("Enter personName:\n");
            scanf("%c", &dummy);
            fgets(target, 20, stdin);
            if (p = strchr(target, '\n'))
                *p = '\0';
            getNameCard(record, &size, target);
        }
    } while (choice < 5);

    return 0;
}

// FUNCTIONS
void listNameCards(NameCard *list, int size)
{
    int i;
    // Check if holder is empty
    if (size == 0) 
        printf("The name card holder is empty\n");
    
    else {
        for (i = 0; i < size; i++){
            printf("nameCardID: %d\npersonName: %s\ncompanyName: %s\n",
            (list+i)->nameCardID, (list+i)->personName, (list+i)->companyName);
        }
    }
    return;
}

void addNameCard(NameCard *list, int *size)
{
    int i, check, position=0;
    char *p, dummy, name[20], company[20];

    // Store values temporarily to perform checks later
    printf("Enter nameCardID:\n");
    scanf("%d", &check);

    scanf("%c", &dummy);
    printf("Enter personName:\n");
    fgets(name, 20, stdin);
    if (p = strchr(name, '\n'))
        *p = '\0';

    printf("Enter companyName:\n");
    fgets(company, 20, stdin);
    if (p = strchr(company, '\n'))
        *p = '\0';

    // Check if still have available slots
    if (*size < MAX) {
        // Check if ID is unique
        for (i = 0; i < *size; i++) {
            if (check == (list+i)->nameCardID) {
                printf("The nameCardID has already existed\n");
                return;
            }
            // Find position of new namecard (ascending order)
            else if (check > (list+i)->nameCardID)
                position = i+1;
        }
        // All checks pass, make space for new name card
        for (i = *size; i >= position; i--) {
            (list+i+1)->nameCardID = (list+i)->nameCardID;
            strcpy((list+i+1)->personName, (list+i)->personName);
            strcpy((list+i+1)->companyName, (list+i)->companyName);
        }
        // Enter value into name card and insert name card into correct position
        (list+position)->nameCardID = check;
        strcpy((list+position)->personName, name);
        strcpy((list+position)->companyName, company);
        printf("The name card has been added successfully\n");
        // Update size of holder
        *size += 1;
        return;
    }
    else {
        printf("The name card holder is full\n");
        return;
    }
}

void removeNameCard(NameCard *list, int *size, char *target)
{
    int i, j, remove_slot;
    char holder[20];
    // Check if holder has any record
    if (*size > 0) {
        // Change target name to upper case
        for (i = 0; i < strlen(target); i++) {
            if (islower(target[i]))
                target[i] = toupper(target[i]);
        }
        // Check against records in namecard holder
        for (i = 0; i < *size; i++) {
        // Create a copy for comparison - don't change record itself
            strcpy(holder, (list+i)->personName);
            // Change name to upper case for comparison
            for (j = 0; j < strlen(holder); j++) {
                if (islower(holder[j]))
                    holder[j] = toupper(holder[j]);
            }
            // If match, remove namecard
            if (strcmp(target, holder) == 0) {
                // Store position of namecard to be removed
                remove_slot = i;
                // Announce details and removal of namecard
                printf("The name card is removed\n");
                printf("nameCardID: %d\npersonName: %s\ncompanyName: %s\n",
                (list+i)->nameCardID, (list+i)->personName, (list+i)->companyName);
                // Remove namecard and shift all namecards down
                for (i = remove_slot; i < *size-1; i++) {
                    (list+i)->nameCardID = (list+i+1)->nameCardID;
                    strcpy((list+i)->personName, (list+i+1)->personName);
                    strcpy((list+i)->companyName, (list+i+1)->companyName);
                }
                // Update size of card holder
                *size -= 1;
                return;
            }
        }
        printf("The target person name is not in the name card holder\n");
    }
    else {
        printf("The name card holder is empty\n");
        return;
    }
}

void getNameCard(NameCard *list, int *size, char *target)
{
    int i, j;
    char holder[20];
    // Change target name to upper case 
    for (i = 0; i < strlen(target); i++) {
        if (islower(target[i]))
            target[i] = toupper(target[i]);
    }
    // Check against namecard in card holder
    for (i = 0; i < *size; i++) {
        // Create a copy for comparison - don't change record itself
        strcpy(holder, (list+i)->personName);
        // Change name to upper case for comparison
        for (j = 0; j < strlen(holder); j++) {
            if (islower(holder[j]))
                holder[j] = toupper(holder[j]);
        }
        // If match, print namecard
        if (strcmp(holder, target) == 0) {
            printf("The target person name is found\n");
            printf("nameCardID: %d\npersonName: %s\ncompanyName: %s\n",
            (list+i)->nameCardID, (list+i)->personName, (list+i)->companyName);
            return;
        }
    }
    printf("The target person name is not found\n");
    return;
}