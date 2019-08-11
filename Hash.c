/*
  Implements a simple Hash Function and combines Array for speed and Linked List for Scalability.
*/


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


typedef struct node
{
    char data[20];
    struct node* next;

} node;

const node* LIST[26];

int main(void){

    node* temp = NULL;
    node* traverse = NULL;

    //make all pointer of LIST = NULL
    int i = 0;
    while(i < 26)
    {
        LIST[i] = NULL;
        i++;
    }

    while(1) {

        temp = malloc(sizeof(node));

        scanf("%s", temp->data);
        temp->next = NULL;

        //break
        if (strcmp(temp->data, "q") == 0)
        {
            break;
        } else{

            traverse = LIST[(temp->data[0] - 'a') % 26];
            if(traverse == NULL)
            {
                traverse = temp;
                LIST[(temp->data[0] - 'a') % 26] = traverse;
            } else {
                while (traverse->next != NULL) {
                    traverse = traverse->next;
                }
                traverse->next = temp;
            }
        }
    }

        for (int i = 0; i < 26; i++) {

            traverse = LIST[i];
            if(traverse == NULL)
            {
                printf("No item with %c \n", 'a' + i);
            } else {

                printf("Item with %c:  ",'a' + i);
                while (traverse != NULL) {
                    printf("%s | ", traverse->data);
                    traverse = traverse->next;
                }
                printf("\n");

            }

        }

}


