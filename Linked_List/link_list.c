/**
*  @author Fernhew
*  @date 12 Jul 2018
*
*  @brief operate and manipulate elements of list.
*
**/
#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"

// self-refrential structure
struct listNode
{
	char data;
	struct listNode *nextPtr;   // pointer to next node
	
};

// synonym for struct listNode
typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

int main(int argc, char const *argv[])
{
	ListNodePtr startPtr = NULL; // initially there arre no nodes
	int choice ;
	char item;

	instructions(); // print options
	printf("? ");
	scanf("%d", &choice);

	// loop while user does not choose 3.
	while( choice != 3 )
	{
		switch ( choice )
		{
			case 1:
			printf("Ener a characer: \n");
			scanf("%c ", &item);

			insert( &startPtr, item); // insert item in list
			printList(startPtr);

			break;

			case 2:
			if( !isEmpty( startPtr ))
			{
				printf("Enter character to be deleted: ", );
				scanf("%c", &item);

				// if character is found remove it.
				if( delete( &startPtr, item ))
				{
					printf("%c deleted\n", item );
					printList( startPtr );
				}
				else
				{
					printf("%c not found!", item);
				}
			}/* end if */
			else
			{
				printf("list is empty!\n\n");
			}/* end else */

			break;
		    
		    default:
		    printf("Invalid choice.\n\n");
		    instructions();

		    break;

		}/* end switch */

		printf(" ? : \n");
		scanf("%d", &choice);

	}/* end while */

	printf("End  of run. \n");
	return 0;
}/* end main() */

/*********function definitions*************/

/*************insert() definition**********
******************************************************************/

void insert(ListNodePtr *sPtr, char value)
{
	ListNodePtr newPtr;  
	ListNodePtr previousPtr;  // pointer to previous node of list.
	ListNodePtr currentPtr;

	newPtr = malloc( sizeof(ListNode));
    
    // is space available
	if(newPtr != NULL )
	{
		newPtr->data = value;  // place value in data
		newPtr->nextPtr = NULL;

		previousPtr = NULL;
		currentPtr = *sPtr;

		// loop to find correctllocation in the lsit
		while( currentPtr != NULL && value > currentPtr->data )
		{
			previousPtr = currentPtr;           //* walk to ...
			currentPtr = currentPtr->nextPtr;   //  next node

		}

		// insert new node at the beginning of list
		if( previousPtr = NULL )
		{
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		else
		{
			// insert new node between previousPtr and currentPtr
			previousPtr->newPtr = newPtr;
			newPtr->newPtr = currentPtr;
		}
	}/*end if*/
	else
	{
		printf( "%c not inserted. No memory available.\n", value );
	}
} /*end function insert*/

/*************delete() definition**********
************************************************************/

char delete(ListNodePtr *sPtr, char value)
{
	ListNodePtr previousPtr;
	ListNodePtr currentPtr;
	ListNodePtr tempPtr;

	// delete first node
	if( value == ( *sPtr )->data )
	{
		tempPtr = *sPtr; //hold onto node being removed
		*sPtr = ( *sPtr )->newPtr; //de-thread the node.
		free(tempPtr);

		return value;
	}/*end if*/
	else
	{
		previousPtr = *sPtr;
		currentPtr = ( *sPtr )->newPtr;

		// loop to find the correct location in the list
		while( currentPtr != NULL && currentPtr->data != value)
		{
			previousPtr = currentPtr;           // walk to ..
			currentPtr = currentPtr->nextPtr;   // next node
		}

		// delete node at current currentPtr
		if( currentPtr != NULL )
		{
			tempPtr = currentPtr;
			previousPtr->nextPtr = currentPtr->nextPtr;
			free( tempPtr );

			return value;
		}
	}/*end of else*/

	return '\0';
}/*end function delete*/

/*************isEmpty() definition**********
******************************************************************/

int isEmpty(ListNodePtr sPtr)
{
	return sPtr == NULL;
}/*end of isEmpty*/

/*************printList() definition**********
******************************************************************/

void printList(ListNodePtr currentPtr)
{
	// if lis is empty
	if( currentPtr == NULL )
	{
		printf("list id empty\n\n");
	}
	else
	{
		printf("the list is:\n");

		// while not the end of list
		while( currentPtr != NULL)
		{
			printf( "%c --> ", currentPtr->data );
            currentPtr = currentPtr->nextPtr;
		}

		printf("NULL\n\n", );

	}/*end of else*/
}/*end of function printlist()*/

/*************instructions() definition**********
******************************************************************/

void instructions( void )
{
	printf( "Enter your choice:\n"
            " 1 to insert an element into the list.\n"
            " 2 to delete an element from the list.\n"
            " 3 to end.\n" );

} /* end function instructions */