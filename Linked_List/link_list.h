/**
*  @author Fernhew
*  @date 12 Jul, 2018
*
*  @brief function prototypes to manipulate a link-list
*
**/

/***************function prototypes*****************/

/**
 @brief insert a new value into the list in sorted order

 function insert takes 'sPtr'(address of list) and 'value'(a character)
 as inputs.it inserts value in the list in sorted form.

 @param sPtr: address of the list.
 @param value: character to be inserted in list.
 
**/
void insert(ListNodePtr *sPtr, char value);

/**
 @brief delete a character from the list.

 function delete takes 'sPtr'(address of list) and 'value'(a character)
 as inputs.it deletes the input character from the list.

 @param sPtr: address of pointer to the start of list.
 @param char: returned character that was deleted.
 
**/
char delete( ListNodePtr *sPtr, char value );

/**
 @brief determines if the list is empty.

 function isEmpty takes 'sPtr'(address of list) and return 1 
 if the list is empty, 0 otherwise.

 @param sPtr: address of pointer to the start of list.
 @param int: return 0 or 1.
 
**/
int isEmpty( ListNodePtr sPtr );

/**
 @brief print the list.

 function printList receives a pointer to the start of list and prints 
 the elements of list. if the list is empty printList displays a message.

 @param sPtr: address of pointer to the start of list.
 
**/
void printList( ListNodePtr currentPtr );

/**
 @brief displays program instruction to the user.

**/
void instructions( void );