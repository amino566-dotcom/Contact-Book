// Add a contact.
// Search by name.
// Update phone number.
// Delete a contact
// Display all contacts.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[20];
    char number[20];
}Contact;

void Add_contact(Contact **contacts,int *size ){
    
    Contact *temp = realloc(*contacts, *(size + 1) * sizeof(Contact));
    
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    *contacts = temp;

    printf("enter the name of the contact: ");
    scanf("%19s",(*contacts)[*size].name);
    printf("enter the number (10 degits): ");
    scanf("%s", (*contacts)[*size].number);
    (*size)++;
}

void search(Contact *contacts , int size){
    if(size ==0){
        printf("there is nocontact!");
        return;
    }
    char searchName[20];
    printf("enter the name of the contact: ");
    scanf("%s", searchName);
    
    for (int i = 0; i < size ; i++){
        if(strcmp(contacts[i].name, searchName) == 0){
            printf("the name: %s \n", contacts[i].name);
            printf("the number: %s", contacts[i].number);
        }
        else{
            printf("not Found!");
        }
    }
}

void UpdateNumber(Contact **contacts, int *size){
    char searchName[20];
    printf("enter the name of the contact: ");
    scanf("%s", searchName );
    for(int i = 0; i < *size; i++){
        if (strcmp((*contacts)[i].name, searchName) == 0){
            printf("Enter the new phone number: ");
            scanf("%19s", (*contacts)[i].number);
        }
    }

}

void deleteContact(Contact **contacts, int * size){
    if(*size ==0) {
        printf("ther is no contacts.");
        return;
    }
    char searchName[20];
    printf("enter the name of the contact: ");
    scanf("%s", searchName );
    for(int i = 0; i < *size -1 ; i++){
        if (strcmp((*contacts)[i].name, searchName) == 0){
            for(int j = i; j < *size; j++){
                (*contacts)[j] = (*contacts)[j+1];
            }

            (*size)--;
            if(*size == 0){
                free(contacts);
                *contacts = NULL;

            }
            else{
                Contact *temp = realloc(*contacts ,(*size) *sizeof(Contact) );

                if (temp != NULL)
                {
                    *contacts = temp;
                }
            }
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void display(Contact *contacts , int size){
    for(int i = 0 ; i < size ;i++){
        printf("the name: %s \n", contacts[i].name);
        printf("the number: %s \n", contacts[i].number);
    }
}

int main(void)
{
    Contact *contacts = NULL;
    int size = 0;
    int choice;

    while (1)
    {
        printf("\n===== CONTACT BOOK =====\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Update phone number\n");
        printf("4. Delete contact\n");
        printf("5. Display all contacts\n");
        printf("0. Exit\n");

        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input.\n");
            break;
        }

        switch (choice)
        {
            case 1:
                Add_contact(&contacts, &size);
                break;

            case 2:
                search(contacts, size);
                break;

            case 3:
                UpdateNumber(&contacts, &size);
                break;

            case 4:
                deleteContact(&contacts, &size);
                break;

            case 5:
                display(contacts, size);
                break;

            case 0:
                free(contacts);
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    free(contacts);
    return 1;
}
