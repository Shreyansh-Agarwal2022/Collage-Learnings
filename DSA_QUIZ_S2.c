#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for Node of Linked List Data Type
typedef struct node
{
    char *word;
    int freq;
    struct node *next;
    struct node *prev;
} node;

// Function for adding word in Linked List
void add(node **head, char word[])
{
    // Points to current node
    node *temp;
    // For first element
    if (*head == NULL)
    {
        *head = (node *)malloc(sizeof(node));
        temp = *head;
        temp->word = (char *)malloc((strlen(word) + 1) * sizeof(char));
        strcpy(temp->word, word);
        temp->freq = 1;
        temp->next = NULL;
        temp->prev = NULL;
    }
    else
    {
        temp = *head;
        while (temp->next != NULL && strcmp(temp->word, word) != 0)
        {
            temp = temp->next;
        }
        // If word found in linked list
        if (strcmp(temp->word, word) == 0)
        {
            temp->freq += 1;
            return;
        }
        // If word not found in linked list add a new node to linked list
        else if (temp->next == NULL)
        {
            temp->next = (node *)malloc(sizeof(node));
            temp->next->prev = temp;
            temp = temp->next;
            temp->word = (char *)malloc((strlen(word) + 1) * sizeof(char));
            strcpy(temp->word, word);
            temp->freq = 1;
            temp->next = NULL;
            return;
        }
    }
}

// Printing the linked list
void print(node *head)
{
    int i = 0;
    node *temp = head;
    printf("\n\tPrinting List :\n\n");
    while (head != NULL)
    {
        i += 1;
        printf("\nFor Node %d :\n\n", i);
        printf("Word : %s\n", head->word);
        printf("Frequency : %d\n", head->freq);
        head = head->next;
    }

    /* //This is for printing Linked List in Reverse
    printf("\n\tNow in reverse :\n\n");
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        printf("\nFor Node %d :\n\n",i);
        printf("Word : %s\n",temp->word);
        printf("Frequency : %d\n",temp->freq);
        temp=temp->prev;
        i--;
    }
    */
}

// Our Main function
void main()
{
    // File Pointer
    FILE *fp;
    // For temporary storing the word read from file
    char word[50];
    // Our Linked List Head
    node *head = NULL;
    int i;
    // Opening the file
    fp = fopen("Footballnews.txt", "r");
    // If file not found
    if (fp == NULL)
    {
        printf("\n File does not exist");
        exit(0);
    }
    // Loop till file don't ends
    while (!feof(fp))
    {
        fscanf(fp, "%s", word);
        // This is because Last Word in file is not read twice
        /*if (feof(fp))
        {
            break;
        }*/
        // Converting the word to lower case
        for (i = 0; i < strlen(word); i++)
        {
            word[i] = tolower(word[i]);
        }
        add(&head, word);
        // printf("%s %ld\n",word,strlen(word));
    }
    // Printing the linked list
    print(head);
    fclose(fp);
}

/*
Contents of file :

Match women UK Pakistan
Women football seen risk Taliban some fear punish participate Football sport
Women Football final Women Pakistan goal win the worldcup
*/

/*
Q(Even). A text file named as “Footballnews.txt” contains the news of a World Cup football match.
Write C function for the following: [1+4+8+3+4]
a) To open the file in read mode.
b) To read the text from file one word at a time.
c) To create the doubly linked list of words such that each node contains the word as well as the frequency of the that word.
d) To Display the list of words with their frequency.
Note: There are 4 marks for the good and efficient programming practices.
The code to read from a text file is given below:
void main()
{
    FILE *fp;
    Char word[50];
    fp = fopen("Footballnews.txt", "r");
    if (fp == NULL)
    {
        printf("\n File does not exist");
        exit(0);
    }
    while (!feof(fp))
    {
        fscanf(fp, "%s", word);
        << write your code for the given question>>
    }
    fclose(fp);
}*/