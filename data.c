
#include <stdlib.h>
#include <string.h>
#include "data.h"

void** new_record_list()
{
	record_node **ppRecord_head;

	ppRecord_head = (record_node **)malloc(sizeof(ppRecord_head));

	if (ppRecord_head == NULL)
		return NULL;

	*ppRecord_head = NULL;

	return (void**)ppRecord_head;
}

// deletes the entire record list
void destroy_record_list(record_node ** ppRecord_head)
{
	record_node *pTemp;
	record_node *pNode;

	if (ppRecord_head == NULL)
		return;

	pNode = *ppRecord_head;

	// loop through the entire record list, deleting each node
	while (pNode != NULL)
	{
		// remove the node from the list
		pTemp = pNode;
		pNode = pNode->pNext;

		// free up the memory used by the node
		free(pTemp->szKey);
		free(pTemp->szVal);
		free(pTemp);
	}

	// Set the top of the list to null
	*ppRecord_head = NULL;
}

// Removes all keys from the record list with the matching value.
// This function returns after the first value that matches.
void del_keys_by_val(record_node ** ppRecord_head, const char *szVal)
{
	record_node *pTemp;
	record_node *pNode;

	// make sure the list even exists
	if (ppRecord_head == NULL)
		return;

	// if the head of the record list is null, then return
	if (*ppRecord_head == NULL)
		return;

	// check if the head of the record list is the one we're looking for
	// if it is, then remove it, check the new head.
	while (!strcmp((*ppRecord_head)->szVal, szVal))
	{
		// remove the node from the list
		pTemp = *ppRecord_head;
		*ppRecord_head = (*ppRecord_head)->pNext;

		// free up the memory used by the node
		free(pTemp->szKey);
		free(pTemp->szVal);
		free(pTemp);
		pTemp = NULL;

		// If the new head is null, we're finished
		if (*ppRecord_head == NULL)
			return;
	}

	pNode = *ppRecord_head;

	// loop to the end of the list, making sure we don't hit a null node
	while (pNode->pNext != NULL)
	{
		// check the next node to see if it's the key we're looking for
		if (!strcmp((pNode->pNext)->szVal, szVal))
		{
			// remove the node from the list
			pTemp = pNode->pNext;
			pNode->pNext = pTemp->pNext;

			// free up the memory used by the node
			free(pTemp);
			pTemp = NULL;

			// Skip itterating
			continue;
		}

		pNode = pNode->pNext;
	}
}

// removes szKey from the record list
void del_key(record_node ** ppRecord_head, const char *szKey)
{
	record_node *pTemp;
	record_node *pNode;

	// make sure the list even exists
	if (ppRecord_head == NULL)
		return;

	// if the head of the record list is null, then return
	if (*ppRecord_head == NULL)
		return;

	// check if the head of the record list is the one we're looking for
	if (!strcmp((*ppRecord_head)->szKey, szKey))
	{
		// remove the node from the list
		pTemp = *ppRecord_head;
		*ppRecord_head = (*ppRecord_head)->pNext;

		// free up the memory used by the node
		free(pTemp->szKey);
		free(pTemp->szVal);
		free(pTemp);
		pTemp = NULL;

		return;
	}

	// loop to the end of the list, making sure we don't hit a null node
	for (pNode = *ppRecord_head; pNode->pNext != NULL; pNode = pNode->pNext)
	{
		// check the next node to see if it's the key we're looking for
		if (!strcmp((pNode->pNext)->szKey, szKey))
		{
			// remove the node from the list
			pTemp = pNode->pNext;
			pNode->pNext = pTemp->pNext;

			// free up the memory used by the node
			free(pTemp);
			pTemp = NULL;

			return;
		}
	}

}

// add the szKey and iVal pairing to the record list
void add_key(record_node ** ppRecord_head, const char *szKey, const char *szVal)
{
	record_node *pNode;

	// make sure the list even exists
	if (ppRecord_head == NULL)
		return;

	// if the head of the record list is null, then start it
	if (*ppRecord_head == NULL)
	{
		*ppRecord_head = (record_node *)malloc(sizeof(record_node));

		if (ppRecord_head == NULL)
			return;

		(*ppRecord_head)->szKey = (char *)malloc(sizeof(char) * strlen(szKey) + 1);
		(*ppRecord_head)->szVal = (char *)malloc(sizeof(char) * strlen(szVal) + 1);

		strcpy((*ppRecord_head)->szKey, szKey);
		strcpy((*ppRecord_head)->szVal, szVal);
		(*ppRecord_head)->pNext = NULL;
		return;
	}

	// loop to the end of the list, checking if the key already exists
	for (pNode = *ppRecord_head; pNode->pNext != NULL; pNode = pNode->pNext)
	{
		// if so, replace and exit
		if (!strcmp(pNode->szKey, szKey))
		{
			pNode->szVal = realloc(pNode->szVal, sizeof(char) * strlen(szVal) + 1);
			strcpy(pNode->szVal, szVal);
			return;
		}
	}

	// check the last node
	if (!strcmp(pNode->szKey, szKey))
	{
		pNode->szVal = realloc(pNode->szVal, sizeof(char) * strlen(szVal) + 1);
		strcpy(pNode->szVal, szVal);
		return;
	}

	// key not found in list

	// add a new record node at the end of list
	pNode->pNext = malloc(sizeof(record_node));
	pNode = pNode->pNext;

	pNode->szKey = malloc(sizeof(char) * strlen(szKey) + 1);
	pNode->szVal = malloc(sizeof(char) * strlen(szVal) + 1);
	strcpy(pNode->szKey, szKey);
	strcpy(pNode->szVal, szVal);
	pNode->pNext = NULL;
}

// checks if the key exists in the record list
int is_key(const record_node * ppRecord_head, const char *szKey)
{
	const record_node *pNode;
	int i;

	// loop through the record list, checking for the matching key
	for (i = 1, pNode = ppRecord_head; pNode != NULL; i++, pNode = pNode->pNext)
	{
		if (!strcmp(pNode->szKey, szKey))
			return i;
	}
	return 0;
}

// checks if the value exists in the record list
int is_val(const record_node * ppRecord_head, const char *szVal)
{
	const record_node *pNode;
	int i;

	// loop through the record list, checking for the matching key
	for (i = 1, pNode = ppRecord_head; pNode != NULL; i++, pNode = pNode->pNext)
	{
		if (!strcmp(pNode->szVal, szVal))
			return i;
	}
	return 0;
}

// returns the number of items in the list
int num_keys(const record_node * ppRecord_head)
{
	const record_node *pNode;
	int i;

	for (i = 0, pNode = ppRecord_head; pNode != NULL; i++, pNode = pNode->pNext);

	return i;
}

// returns the first item from the list and removes it from the list
// returned pointer will have to be freed at some point
record_node *pop_key(record_node ** ppRecord_head)
{
	record_node *pNode;

	// make sure the list exists
	if (ppRecord_head == NULL)
		return NULL;

	pNode = *ppRecord_head;

	if (pNode != NULL)
		*ppRecord_head = (*ppRecord_head)->pNext;

	return pNode;
}

// returns the value of the key in the record list
const char *get_val(const record_node * pRecord_head, const char *szKey)
{
	const record_node *pNode;

	// loop through the record list, checking for the matching key
	for (pNode = pRecord_head; pNode != NULL; pNode = pNode->pNext)
	{
		if (!strcmp(pNode->szKey, szKey))
			return pNode->szVal;
	}
	return "";
}

// displays the record list with szDelim printed after each key/val pairing
void print_record_list(const record_node * pRecord_head, const char *szDelim)
{
	const record_node *pNode;

	// loop through the list, printing each key/val pair
	for (pNode = pRecord_head; pNode != NULL; pNode = pNode->pNext)
	{
		clientf((char *)pNode->szKey);
		clientf("=");
		clientf((char *)pNode->szVal);
		clientf((char *)szDelim);
	};
}

// displays the string list with szDelim printed after each item
void print_record_list_to_buf(const record_node * pRecord_head, const char *szDelim, char * buf)
{
	const record_node *pNode;

	strcpy(buf, "");

	// print the first pair
	if (pRecord_head != NULL)
	{
		strcat(buf, pRecord_head->szKey);
		strcat(buf, "=");
		strcat(buf, pRecord_head->szVal);

		// loop through the rest list, printing each key/val pair
		for (pNode = pRecord_head->pNext; pNode != NULL; pNode = pNode->pNext)
		{
			strcat(buf, szDelim);
			strcat(buf, pNode->szKey);
			strcat(buf, "=");
			strcat(buf, pNode->szVal);
		}
	}
}

void** new_string_list()
{
	string_node **ppString_head;

	ppString_head = malloc(sizeof(ppString_head));

	*ppString_head = NULL;

	return (void**)ppString_head;
}

// deletes the entire string list
void destroy_string_list(string_node ** ppString_head)
{
	string_node *pTemp;
	string_node *pNode;

	// make sure the list exists
	if (ppString_head == NULL)
		return;

	pNode = *ppString_head;

	// loop through the entire record list, deleting each node
	while (pNode != NULL)
	{
		// remove the node from the list
		pTemp = pNode;
		pNode = pNode->pNext;

		// free up the memory used by the node
		free(pTemp->szItem);
		free(pTemp);
	}

	// Set the top of the list to null
	*ppString_head = NULL;
}

void push_item(string_node ** ppString_head, const char *szItem)
{
	string_node *pNode;

	// make sure the list exists
	if (ppString_head == NULL)
		return;

	// if the head of the string list is null, then start it
	if (*ppString_head == NULL)
	{
		*ppString_head = malloc(sizeof(string_node));

		(*ppString_head)->szItem = malloc(sizeof(char) * (strlen(szItem) + 1));
		strcpy((*ppString_head)->szItem, szItem);
		(*ppString_head)->pNext = NULL;
		return;
	}

	// loop to the end of the list, checking if the string already exists
	for (pNode = *ppString_head; pNode->pNext != NULL; pNode = pNode->pNext)
	{
		// if so, exit
		if (!strcmp(pNode->szItem, szItem))
			return;
	}

	pNode = malloc(sizeof(string_node));
	pNode->szItem = malloc(sizeof(char) * (strlen(szItem) + 1));

	strcpy(pNode->szItem, szItem);
	pNode->pNext = *ppString_head;

	*ppString_head = pNode;
}

void push_item_dup(string_node ** ppString_head, const char *szItem)
{
	string_node *pNode;

	// make sure the list exists
	if (ppString_head == NULL)
		return;

	// if the head of the string list is null, then start it
	if (*ppString_head == NULL)
	{
		*ppString_head = malloc(sizeof(string_node));

		(*ppString_head)->szItem = malloc(sizeof(char) * (strlen(szItem) + 1));
		strcpy((*ppString_head)->szItem, szItem);
		(*ppString_head)->pNext = NULL;
		return;
	}

	pNode = malloc(sizeof(string_node));
	pNode->szItem = malloc(sizeof(char) * (strlen(szItem) + 1));

	strcpy(pNode->szItem, szItem);
	pNode->pNext = *ppString_head;

	*ppString_head = pNode;
}


// removes szItem from the string list ppString_head
void del_item(string_node ** ppString_head, const char *szItem)
{
	string_node *pTemp;
	string_node *pNode;

	// make sure the list exists
	if (ppString_head == NULL)
		return;

	// if the head of the string list is null, then return
	if (*ppString_head == NULL)
		return;

	// check if the head of the string list is the one we're looking for
	if (!strcmp((*ppString_head)->szItem, szItem))
	{
		// remove the node from the list
		pTemp = *ppString_head;
		*ppString_head = (*ppString_head)->pNext;

		// free up the memory used by the node
		free(pTemp->szItem);
		free(pTemp);
		pTemp = NULL;

		return;
	}

	// loop to the end of the list, making sure we don't hit a null node
	for (pNode = *ppString_head; pNode->pNext != NULL; pNode = pNode->pNext)
	{
		// check the next node to see if it's the key we're looking for
		if (!strcmp((pNode->pNext)->szItem, szItem))
		{
			// remove the node from the list
			pTemp = pNode->pNext;
			pNode->pNext = pTemp->pNext;

			// free up the memory used by the node
			free(pTemp->szItem);
			free(pTemp);
			pTemp = NULL;

			return;
		}
	}

}

// removes the iNum from the string list ppString_head
void del_nitem(string_node ** ppString_head, int iNum)
{
	string_node *pTemp;
	string_node *pNode;
	int i;

	// make sure the list exists
	if (ppString_head == NULL)
		return;

	// if the head of the string list is null, then return
	if (*ppString_head == NULL)
		return;

	// check if the head of the string list is the one we're looking for
	if (iNum == 1)
	{
		// remove the node from the list
		pTemp = *ppString_head;
		*ppString_head = (*ppString_head)->pNext;

		// free up the memory used by the node
		free(pTemp->szItem);
		free(pTemp);
		pTemp = NULL;

		return;
	}

	// loop to the iNum-1 item in the list, making sure we don't hit a null node
	for (pNode = *ppString_head, i = 1; pNode->pNext != NULL && i < iNum; pNode = pNode->pNext);

	// make sure we're on iNum-1 and that the iNum item exist
	if (i == iNum - 1 && pNode->pNext != NULL)
	{
		// remove the iNum node from the list
		pTemp = pNode->pNext;
		pNode->pNext = pTemp->pNext;

		// free up the memory used by the node
		free(pTemp->szItem);
		free(pTemp);
		pTemp = NULL;
	}
}

// add szItem to the string list ppString_head
void add_item(string_node ** ppString_head, const char *szItem)
{
	string_node *pNode;

	// make sure the list exists
	if (ppString_head == NULL)
		return;

	// if the head of the string list is null, then start it
	if (*ppString_head == NULL)
	{
		*ppString_head = malloc(sizeof(string_node));

		(*ppString_head)->szItem = malloc(sizeof(char) * (strlen(szItem) + 1));
		strcpy((*ppString_head)->szItem, szItem);
		(*ppString_head)->pNext = NULL;
		return;
	}

	// loop to the end of the list, checking if the string already exists
	for (pNode = *ppString_head; pNode->pNext != NULL; pNode = pNode->pNext)
	{
		// if so, exit
		if (!strcmp(pNode->szItem, szItem))
			return;
	}

	// check the last node
	if (!strcmp(pNode->szItem, szItem))
		return;

	// string not found in list

	// add a new string node at the end of list
	pNode->pNext = malloc(sizeof(string_node));
	pNode = pNode->pNext;

	pNode->szItem = malloc(sizeof(char) * strlen(szItem) + 1);
	strcpy(pNode->szItem, szItem);
	pNode->pNext = NULL;
}

// add szItem to the string list ppString_head, allows duplicates
void add_item_dup(string_node ** ppString_head, const char *szItem)
{
	string_node *pNode;

	// make sure the list exists
	if (ppString_head == NULL)
		return;

	// if the head of the string list is null, then start it
	if (*ppString_head == NULL)
	{
		*ppString_head = malloc(sizeof(string_node));

		(*ppString_head)->szItem = malloc(sizeof(char) * strlen(szItem) + 1);
		strcpy((*ppString_head)->szItem, szItem);
		(*ppString_head)->pNext = NULL;
		return;
	}

	// loop to the end of the list
	for (pNode = *ppString_head; pNode->pNext != NULL; pNode = pNode->pNext);

	// add a new string node at the end of list
	pNode->pNext = malloc(sizeof(string_node));
	pNode = pNode->pNext;

	pNode->szItem = malloc(sizeof(char) * strlen(szItem) + 1);
	strcpy(pNode->szItem, szItem);
	pNode->pNext = NULL;
}

// replaces the nth item in the list, if there is no nth item, does nothing
void replace_nitem(string_node ** ppString_head, int iNum, const char *szItem)
{
	string_node *pNode;
	int i;

	// make sure the list exists
	if (ppString_head == NULL)
		return;

	// if the head of the string list is null, then return
	if (*ppString_head == NULL)
		return;

	// loop to the nth item in the list
	for (pNode = *ppString_head, i = 1; pNode != NULL && i <= iNum; pNode = pNode->pNext, i++);

	// if we're at iNum and the node exists, then replace the string
	if (i == iNum && pNode)
	{
		free(pNode->szItem);
		pNode->szItem = _strdup(szItem);
	}

	return;
}

// checks if the string szItem exists in the string list ppString_head
int is_member(const char *szItem, const string_node * ppString_head)
{
	const string_node *pNode;
	int i;

	// loop through the affliction list, checking for the affliction
	for (i = 1, pNode = ppString_head; pNode != NULL; i++, pNode = pNode->pNext)
	{
		if (!strcmp(pNode->szItem, szItem))
			return i;
	}
	return 0;
}



// returns the nth item of string list ppString_head
const char *get_item(const string_node * ppString_head, int szNum)
{
	const string_node *pNode;
	int i;

	// loop through the affliction list, checking for the affliction
	for (i = 1, pNode = ppString_head; pNode != NULL; i++, pNode = pNode->pNext)
	{
		if (i == szNum)
			return pNode->szItem;
	}
	return "";
}

// returns the first item from the list and removes it from the list
// returned pointer will have to be freed at some point
string_node *pop_item(string_node ** ppString_head)
{
	string_node *pNode;

	// make sure the list exists
	if (ppString_head == NULL)
		return NULL;

	pNode = *ppString_head;

	if (pNode != NULL)
		*ppString_head = (*ppString_head)->pNext;

	return pNode;
}

// duplicates the string list and returns the pointer to the head of the new list
string_node *duplicate_string_list(const string_node * pString_head)
{
	const string_node *pNode;
	string_node *pNewString_head, *pNewNode;

	if (pString_head == NULL)
		return NULL;

	// copy the first item
	pNewString_head = malloc(sizeof(string_node));
	pNewString_head->szItem = malloc(sizeof(char) * strlen(pString_head->szItem) + 1);
	strcpy(pNewString_head->szItem, pString_head->szItem);
	pNewString_head->pNext = NULL;

	// copy the rest
	for (pNode = pString_head, pNewNode = pNewString_head; pNode->pNext != NULL; pNode = pNode->pNext, pNewNode = pNewNode->pNext)
	{
		pNewNode->pNext = malloc(sizeof(string_node));

		pNewNode->pNext->szItem = malloc(sizeof(char) * strlen((pNode->pNext)->szItem) + 1);
		strcpy((pNewNode->pNext)->szItem, (pNode->pNext)->szItem);
		(pNewNode->pNext)->pNext = NULL;
	}

	return pNewString_head;
}

// displays the string list with szDelim printed after each item
void print_string_list(const string_node * ppString_head, const char *szDelim)
{
	const string_node *pNode;

	// loop through the list, printing each key/val pair
	for (pNode = ppString_head; pNode != NULL; pNode = pNode->pNext)
	{
		clientf((char *)pNode->szItem);
		clientf((char *)szDelim);
	}
}

// returns the number of items in the list
int num_items(const string_node * ppString_head)
{
	const string_node *pNode;
	int i;

	for (i = 0, pNode = ppString_head; pNode != NULL; i++, pNode = pNode->pNext);

	return i;
}

void** new_lookup_table()
{
	lookup_table_node **ppLookupTable_head;

	ppLookupTable_head = malloc(sizeof(ppLookupTable_head));

	*ppLookupTable_head = NULL;

	return (void**)ppLookupTable_head;
}

void destroy_lookup_table(lookup_table_node ** ppLookupTable_head)
{
	lookup_table_node *pTemp;
	lookup_table_node *pNode;

	if (ppLookupTable_head == NULL)
		return;

	pNode = *ppLookupTable_head;

	// loop through the entire record list, deleting each node
	while (pNode != NULL)
	{
		// remove the node from the list
		pTemp = pNode;
		pNode = pNode->pNext;

		// free up the memory used by the node
		free(pTemp->szName);
		free(pTemp);
	}

	// Set the top of the list to null
	*ppLookupTable_head = NULL;
}

void add_data(lookup_table_node ** ppLookupTable_head, const char *szName, void** ppData)
{
	lookup_table_node *pNode;

	// make sure the table exists
	if (ppLookupTable_head == NULL)
		return;

	// if the head of the record list is null, then start it
	if (*ppLookupTable_head == NULL)
	{
		*ppLookupTable_head = malloc(sizeof(lookup_table_node));

		(*ppLookupTable_head)->szName = malloc(sizeof(char) * strlen(szName) + 1);
		strcpy((*ppLookupTable_head)->szName, szName);
		(*ppLookupTable_head)->ppData = ppData;
		(*ppLookupTable_head)->pNext = NULL;
		return;
	}

	// loop to the end of the list, checking if the name already exists
	for (pNode = *ppLookupTable_head; pNode->pNext != NULL; pNode = pNode->pNext)
	{
		// if so, replace and exit
		if (!strcmp(pNode->szName, szName))
		{
			pNode->ppData = ppData;
			return;
		}
	}

	// check the last node
	if (!strcmp(pNode->szName, szName))
	{
		pNode->ppData = ppData;
		return;
	}

	// name not found in list

	// add a new data node at the end of list
	pNode->pNext = malloc(sizeof(lookup_table_node));
	pNode = pNode->pNext;

	pNode->szName = malloc(sizeof(char) * strlen(szName) + 1);
	strcpy(pNode->szName, szName);
	pNode->ppData = ppData;
	pNode->pNext = NULL;
}

void *get_data(const lookup_table_node * pDataLookupTable_head, const char *szName)
{
	const lookup_table_node *pNode;

	// loop through the table, checking for the data
	for (pNode = pDataLookupTable_head; pNode != NULL; pNode = pNode->pNext)
	{
		if (!strcmp(pNode->szName, szName))
		{
			return *(pNode->ppData);
		}
	}

	return NULL;
}

int does_data_exist(const lookup_table_node * pDataLookupTable_head, const char *szName)
{
	const lookup_table_node *pNode;

	// loop through the table, checking for the data
	for (pNode = pDataLookupTable_head; pNode != NULL; pNode = pNode->pNext)
	{
		if (!strcmp(pNode->szName, szName))
		{
			return 1;
		}
	}

	return 0;
}

// removes szName from a lookup table
void remove_data(lookup_table_node ** ppLookupTable_head, const char *szName)
{
	lookup_table_node *pTemp;
	lookup_table_node *pNode;

	// make sure the list even exists
	if (ppLookupTable_head == NULL)
		return;

	// if the head of the record list is null, then return
	if (*ppLookupTable_head == NULL)
		return;

	// check if the head of the record list is the one we're looking for
	if (!strcmp((*ppLookupTable_head)->szName, szName))
	{
		// remove the node from the list
		pTemp = *ppLookupTable_head;
		*ppLookupTable_head = (*ppLookupTable_head)->pNext;
		return;
	}

	// loop to the end of the list, making sure we don't hit a null node
	for (pNode = *ppLookupTable_head; pNode->pNext != NULL; pNode = pNode->pNext)
	{
		// check the next node to see if it's the key we're looking for
		if (!strcmp((pNode->pNext)->szName, szName))
		{
			// remove the node from the list
			pTemp = pNode->pNext;
			pNode->pNext = pTemp->pNext;

			return;
		}
	}

}

void **get_pdata(const lookup_table_node * pDataLookupTable_head, const char *szName)
{
	const lookup_table_node *pNode;

	// loop through the table, checking for the data
	for (pNode = pDataLookupTable_head; pNode != NULL; pNode = pNode->pNext)
	{
		if (!strcmp(pNode->szName, szName))
		{
			return pNode->ppData;
		}
	}

	return NULL;
}

void replace_char(char * szString, char chOrig, char chRepl)
{
	char *pChar;

	if (szString == NULL)
		return;

	for (pChar = szString; *pChar != '\0'; pChar++)
	{
		if (*pChar == chOrig)
			*pChar = chRepl;
	}
}

void words(const char *szString, int iNum, const char *szDelim, char * szWord)
{
	int i, iLenDelim;
	const char *szSubstr;

	if (szString == NULL)
		return;

	iLenDelim = strlen(szDelim);

	// Find the first character that isn't cDelim
	for (szSubstr = szString; !strncmp(szSubstr, szDelim, iLenDelim) && *szSubstr != '\0'; szSubstr++);

	for (i = 1; i < iNum; i++)
	{
		szSubstr = strstr(szSubstr, szDelim);

		if (!szSubstr)
			break;

		szSubstr += iLenDelim;
	}

	if (szSubstr)
		strcpy(szWord, szSubstr);
	else
		strcpy(szWord, "");
}

void word(const char *szString, int iNum, const char *szDelim, char * szWord)
{
	int i, iLenDelim;
	const char *szSubstr, *szSubstr2;

	if (szString == NULL)
		return;

	iLenDelim = strlen(szDelim);

	// Find the first character that isn't cDelim
	for (szSubstr = szString; !strncmp(szSubstr, szDelim, iLenDelim) && *szSubstr != '\0'; szSubstr++);

	for (i = 1; i < iNum; i++)
	{
		szSubstr = strstr(szSubstr, szDelim);

		if (!szSubstr)
			break;

		szSubstr += iLenDelim;
	}

	if (szSubstr)
	{
		szSubstr2 = strstr(szSubstr, szDelim);

		if (szSubstr2)
		{
			strncpy(szWord, szSubstr, szSubstr2 - szSubstr);
			szWord[szSubstr2 - szSubstr] = '\0';
		}
		else
			strcpy(szWord, szSubstr);
	}
	else
		strcpy(szWord, "");
}

void* deref(void **pData)
{
	return *pData;
}