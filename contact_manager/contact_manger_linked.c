#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <assert.h>

/**
 * @file
 * @implementing a contact manager using linked list inc
 * https://github.com/AliSinaYOusofi/DSA-C
 * @details
 * using malloc for memory allocation
 * @author [Name](https://github.com/AliSinaYOusofi)
 * @see related functions in side contact_manager.c
 */

/* This Project Was Made Using Linked List 
   This Project Is Contact Manager Like the ones we use on our phones
   But This Project Has No Grpahical InterFace it Is Command Line
   Contact Manager Has five fields 1: firstName 2: lastName 3: phonenumber 4:Id 5: next
   the next variable is used to store the address of the next contact.
   Author: AlCoder
   Data: 20/Feb/2021
   Project Name: 786?
*/

/**
 * @brief
 * creating a struct to store user data
 */
 
struct node
{
    char firstName[15]; // user firstName of type char
    char lastName[30]; // user lastName of type char
    char phoneNumber[30]; // user phonenumber of type char
    int ID; // user id of type char. generated inside functions
    struct node *next; // pointing to our next data/user
};

/**
 * @brief
 * creating a struct to store user data
 * at start is is set to null(no data is stored)
 */
struct node *start = NULL;


/**
 * @brief CreateContact creates a new struct to store user data
 * @param param1 is a struct pointer
 * @returns start struct pointer if user data is valid
 */
struct node *CreateContact(struct node *start)
{
    struct node *new_node, *ptr;
    new_node = (struct node *) malloc(sizeof(struct node));

    printf("\n [1]: Enter Contact First Name: ");
    scanf("%s", new_node -> firstName);
    printf("\n [2]: Enter Contact Last Name: ");
    scanf("%s", new_node -> lastName);
    printf("\n [3]: Enter Contact PhoneNumber: ");
    scanf("%s", new_node -> phoneNumber);
    printf("\n [4]: Enter Contact ID: ");
    scanf("%d", &new_node -> ID);
    
    if (start == NULL)
    {
        start = new_node;
        new_node -> next = NULL;
    }

    else
    {
        ptr = start;
        while (ptr -> next != NULL)
            ptr = ptr -> next;
        ptr -> next = new_node;
        new_node -> next = NULL;
    }
    return start;
}

/**
 * @brief DisplayAllContacts iterates through all linked list and displays every user data
 * @param param1 is a struct pointer(pointing at the start of the linked list)
 * @returns 'void'
 */
void DisplayAllContacts(struct node *start)
{
    struct node *ptr;
    ptr = start;

    if (start == NULL)
    {
        printf("\n [_^_]: Contact List Is Empty.");
    }

    else
    {
        while (ptr != NULL)
        {
            printf("\n ****************Contact Lumber %d***************", ptr -> ID);
            printf("\n [%d]: Contact Name: %s", ptr -> ID,ptr -> firstName);
            printf("\n [%d]: Contact Last Name: %s", ptr -> ID,ptr -> lastName);
            printf("\n [%d]: Contact PhoneNumber: %s", ptr -> ID, ptr -> phoneNumber);
            printf("\n \n \n");
            ptr = ptr -> next;
        }
    }
    
}   

/**
 * @brief DeleteContact  deletes a contact based on contact id.
 * @param param1 is a struct pointer
 * @returns start (struct pointer)
 */
struct node *DeleteContact(struct node *start)
{
    struct node *ptr, *preptr;
    int ID;
    printf("\n [*]: Enter Contact ID To Delete: ");
    scanf("%d", &ID);
    if (start == NULL)
    {
        printf("\n [-]: Contact List Is Empty.");
    }

    else
    {
        ptr = start;
        while (ptr -> ID != ID)
        {
            preptr = ptr;
            ptr = ptr -> next;
        }
        preptr -> next = ptr -> next;
        free(ptr);
    }
    return start;
}

/**
 * @brief DeleteAfterAGivenID deletes a user after a given.
 * @param param1 is a struct pointer
 * @param param2 is the user id which they want to delete after that
 * @returns start struct pointer if user data is valid
 */
 
struct node *DeleteAfterAGivenID(struct node *start, int ID)
{
    struct node *ptr, *preptr;
    if (start == NULL)
    {
        printf("\n [-]: Contact List Is Empty.");
    }

    else
    {
        ptr = start;
        while (preptr -> ID != ID)
        {
            preptr = ptr;
            ptr = ptr -> next;
        }
        preptr -> next = ptr -> next;
        free(ptr);
    }
    return start;

}

/**
 * @brief DeleteFirstContact deletes a user that is at the start of the linked list.
 * @param param1 is a struct pointer
 * @returns start struct pointer if user data is valid
 */
struct node *DeleteFirstContact(struct node *start)
{
    struct node *ptr;
    if (start == NULL)
        printf("\n [_^_]: Contact List Empty.");
    
    else
    {
        ptr = start;
        start = start -> next; 
        free(ptr);
    }
    return start;
}

/**
 * @brief DeleteLastContact deletes the last contact in the linked list.
 * @param param1 is a struct pointer
 * @returns start struct pointer if user is deleted
 */
 
struct node *DeleteLastContact(struct node *start)
{
    struct node *ptr, *preptr;
    if (start == NULL)
    {
        printf("\n [*]: Contact List Is Empty.");
    }

    else
    {
        ptr = start;
        while (ptr -> next != NULL)
        {
            preptr = start;
            ptr = ptr -> next;
        }
        preptr -> next = NULL;
        free(ptr);
    }
    return start;
}

/**
 * @brief AddAfterAGivenID inserts new data at the start of the linked list.
 * @param param1 is a struct pointer
 * @returns start struct pointer if user id deleted
 */
 
struct node *AddAtFirstContact(struct node *start)
{
    struct node *new_node;
    new_node = (struct node *) malloc(sizeof(struct node));
    printf("\n [*]: Enter Contact First Name: ");
    scanf("%s", new_node -> firstName);
    printf("\n [*]: Enter Contact Last Name: ");
    scanf("%s", new_node -> lastName);
    printf("\n [*]: Enter Contact PhoneNumber: ");
    scanf("%s", new_node -> phoneNumber);
    printf("\n [*]: Enter Contact ID Number: ");
    scanf("%d", &new_node -> ID);

    new_node -> next = start;
    start = new_node;
    return start;
}


/**
 * @brief AddAsLastContact Adds a user at the end of the linked list.
 * @param param1 is a struct pointer
 * @returns 'start struct' pointer if user data is added
 */
struct node *AddAsLastContact(struct node *start)
{
    struct node *new_node, *ptr;
    new_node = (struct node *) malloc(sizeof(struct node));
    printf("\n [*]: Enter Contact First Name: ");
    scanf("%s", new_node -> firstName);
    printf("\n [*]: Enter Contact Last Name: ");
    scanf("%s", new_node -> lastName);
    printf("\n [*]: Enter Contact PhoneNumber: ");
    scanf("%s", new_node -> phoneNumber);
    printf("\n [*]: Enter Contact ID Number: ");
    scanf("%d", new_node -> ID);
    ptr = start;

    while (ptr -> next != NULL)
    {
        ptr = ptr -> next;
    }
    new_node -> next = NULL;
    ptr -> next = new_node;

    return start;
}

/**
 * @brief AddBeforAGivenID adds new user before a provied id.
 * @param param1 is a struct pointer
 * @param param2 is the user id which they want to add before it.
 * @returns start struct pointer if user data is valid and added.
 */
struct node *AddBeforAGivenID(struct node *start, int ID)
{
    if (start == NULL)
    {
        printf("\n [*]: Adding Contact As First Contact Since Contact List Is Empty.");
        CreateContact(start);
    }

    else
    {
        struct node *new_node, *ptr, *pre_ptr;
        new_node = (struct node *)malloc(sizeof(struct node));
        printf("\n [*]: Enter Contact First Name: ");
        scanf("%s", new_node -> firstName);
        printf("\n [*]: Enter Contact Last Name: ");
        scanf("%s", new_node -> lastName);
        printf("\n [*]: Enter Contact PhoneNumber: ");
        scanf("%s", new_node -> phoneNumber);
        printf("\n [*]: Enter Contact ID Number: ");
        scanf("%d", &new_node -> ID);

        ptr = start;
            while(ptr -> ID != ID)
            {
                pre_ptr = ptr;
                ptr = ptr -> next;
            }
        pre_ptr -> next = new_node;
        new_node -> next = ptr;
        return start;
    }
    
}

/**
 * @brief AddAfterAGivenID deletes a user after a given.
 * @param param1 is a struct pointer
 * @param param2 is the user id which they want to add after.
 * @returns start struct pointer if user data is valid and added.
 */
 
struct node *AddAfterAGivenID(struct node *start, int ID)
{
    if (start == NULL)
    {
        printf("\n [*]: Adding Contact As First Contact Since Contact List Is Empty.");
        CreateContact(start);
    }

    else
    {
        struct node *new_node, *ptr, *pre_ptr;
        new_node = (struct node *)malloc(sizeof(struct node));
        printf("\n [*]: Enter Contact First Name: ");
        scanf("%s", new_node -> firstName);
        printf("\n [*]: Enter Contact Last Name: ");
        scanf("%s", new_node -> lastName);
        printf("\n [*]: Enter Contact PhoneNumber: ");
        scanf("%s", new_node -> phoneNumber);
        printf("\n [*]: Enter Contact ID Number: ");
        scanf("%d", &new_node -> ID);

        ptr = start;
            while(pre_ptr -> ID != ID)
            {
                pre_ptr = ptr;
                ptr = ptr -> next;
            }
        pre_ptr -> next = new_node;
        new_node -> next = ptr;
        return start;
    }
    
}

/**
 * @brief searchContact searches a user based on a given id.
 * @param param1 is a struct pointer
 * @param param2 is the user id which they want to delete.
 * @returns 'void'
 */
void searchContact(struct node *start, int ID)
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("\n [*]: Contact List Is Empty.");
    }

    else if (start -> ID == ID)
    {
        printf("\n \n[+]: Contact Found In The List.");
        printf("\n [%d]: Contact First Name: %s.", start -> ID,start -> firstName);
        printf("\n [%d]: Contact Last Name: %s.", start -> ID, start -> lastName);
        printf("\n [%d]: Contact PhoneNumber: %s \n", start -> ID, start -> phoneNumber);
    }

    else
    {
        ptr = start;
        int flag = 0;
        while (ptr -> ID != ID)
        {
            if (ptr -> ID == ID)
            {
                flag = 1;
                break;
            }
            else
            {
                flag = 0;
                break;
            }
            ptr = ptr -> next;
        }

        if (flag == 0)
        {
            printf("\n [-]: Contact Not Found");
        }
        else 
        {
            printf("\n [+]: Contact Found In The List.");
            printf("\n [%d]: Contact First Name: %s.", ptr -> ID, ptr -> firstName);
            printf("\n [%d]: Contact Last Name: %s.", ptr -> ID, ptr -> lastName);
            printf("\n [%d]: Contact PhoneNumber: %s. \n", ptr -> ID, ptr -> phoneNumber);
        }

    }
    
}

/**
 * @brief deleteContactList deletes the linked list.
 * @param param1 is a struct pointer
 * @returns start struct pointer
 */
struct node *deleteContactList(struct node *start)
{
    struct node *ptr;
    if (start == NULL)
    {
        printf(
            "\n [_:^:_]: Contact List Is Empty."
        );
    }

    else
    {
        ptr = start;
        while (ptr != NULL)
        {
            start = DeleteFirstContact(ptr);
            ptr = start;
        }
    }
    return start;
}

/**
 * @brief editContact deletes a user after a given.
 * @param param1 is a struct pointer
 * @param param2 is the user id which they want to edit.
 * @returns start struct pointer if user data is edited on success.
 */
 
struct node *editContact(struct node *start, int ID)
{
    int flag;
    struct node *ptr;

    if (start == NULL)
    {
        printf("\n [*]: Contact List Is Empty.");
    }

    else
    {
        printf("\n [+*+]: Searching Contact...");
        ptr = start;
        while (ptr -> ID != ID)
        {
            if (ptr -> ID == ID)
            {
                flag = 1;
                break;
            }

            else
            {
                flag = 0;
                break;
            }
            ptr = ptr -> next;
        }
    }
    printf("\n ****************************************Searching Contact******************************************");
    if (flag == 0)
    {
        printf("\n [-]: Contact Not Found Found.");
        printf("\n ***************************************End Of Search*******************************");
    }

    else
    {
        printf("\n [+]: Contact Found.");
        printf("\n [+]: Contact Name: %s", ptr -> firstName);
        printf("\n [+]: Contact Last Name: %s", ptr -> lastName);
        printf("\n [+]: Contact PhoneNumber: %s", ptr -> phoneNumber);
        printf("\n [+]: Contact ID: %d", ptr -> ID);
        printf("\n ***********************************End Of Search**************************************");
        
        printf("\n ***************************EDITING CONTACT*********************************");
        printf("\n [*]: Enter Contact New First Name: ");
        scanf("%s", ptr -> firstName);
        printf("\n [*]: Enter Contact New Last Name: ");
        scanf("%s", ptr -> lastName);
        printf("\n [*]: Enter Contact New PhoneNumber: ");
        scanf("%s", ptr -> phoneNumber);
        printf("\n [*]: Enter Contact New ID: ");
        scanf("%d", &ptr -> ID);
        printf("\n [+_+]: Contact Updated");
    }
    return start;
}

int main()
{
    int ID;
    int option;
    do 
    {
        printf("\n *************************************Main Menu*********************************************");
        printf("\n [1]: Add New Contact.");
        printf("\n [2]: List All Contacts.");
        printf("\n [3]: Delete A Contact By A Given ID.");
        printf("\n [4]: Delete After An ID.");
        printf("\n [5]: Delete Last Contact.");
        printf("\n [6]: Delete First Contact.");
        printf("\n [7]: Add Contact As First Contact.");
        printf("\t [8]: Add Contact As Last Contact.");
        printf("\n [9]: Add Contact Before A Given ID.");
        printf("\n [10]: Add Contact After A Given ID.");
        printf("\n [11]: Search Contact With A Given ID.");
        printf("\n [12]: Delete Contact List.");
        printf("\n [13]: Edit Contact With A Given ID.");
        printf("\n [14]: Exit Program.");
        
        printf("\n \n [*]: Enter Option ->: ");
        scanf("%d", &option);

        switch(option)
        {
            
            case 1: start = CreateContact(start);
                    printf("\n ******************************CONTACT ADDED************************************ \n");
                    break;
            
            case 2: DisplayAllContacts(start);
                    printf("\n ********************************END OF CONTACT LIST**************************** \n");
                    break;
            
            case 3: start = DeleteContact(start);
                    printf("\n *******************************CONTACT DELETED******************************* \n");
                    break;
            
            case 4: printf("\n [*]: Enter Contact ID To Delete After It: "); 
                    scanf("%d", &ID);
                    start = DeleteAfterAGivenID(start, ID);
                    printf("\n *******************************CONTACT DELETED******************************* \n");
                    break;
            
            case 5: start = DeleteLastContact(start);
                    printf("\n *******************************CONTACT DELETED******************************* \n");
                    break;
            
            case 6:start = DeleteFirstContact(start);
                    printf("\n*******************************CONTACT DELETED******************************** \n");
                    break;
            
            case 7:start = AddAtFirstContact(start);
                    printf("\n ******************************CONTACT ADDED************************************ \n");
                    break;
            
            case 8:start = AddAsLastContact(start);
                    printf("\n ******************************CONTACT ADDED************************************ \n");
                    break;
            
            case 9:printf("\n [*]: Enter Contact ID To Insert Before That Contact: ");
                    scanf("%d", &ID);
                    start = AddBeforAGivenID(start, ID);
                    printf("\n ******************************CONTACT ADDED************************************ \n");
                    break;
            
            case 10:printf("\n [*]: Enter Cotact ID TO Insert After That."); 
                    scanf("%d", &ID);
                    start = AddAfterAGivenID(start, ID);
                    printf("\n ******************************CONTACT ADDED************************************ \n");
                    break;
            
            case 11:printf("\n [*]: Enter Contact ID To Search: ");
                    scanf("%d", &ID);
                    searchContact(start, ID);
                    break;
            
            case 12:start = deleteContactList(start);
                    printf("\n [+++]: Contact List Deleted.");
                    break;
            
            case 13:printf("\n [+]: Enter Contact ID To Edit: ");
                    scanf("%d", &ID);
                    start = editContact(start, ID);
                    break;
        }
    
    }while(option != 14);   
    return 0;
}