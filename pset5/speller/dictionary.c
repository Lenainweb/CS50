/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

#include "dictionary.h"


///////////////////////////////////////////
// Declaration of the structure of the trie element

typedef struct node
{
    // marker for end of word
    bool end_word;

    //pointers to other nodes
    struct node* next[27];
}
node;

// Variables for counting downloaded words from the dictionary.
//The first counts the current number, the second is zero until
//the entire dictionary is loaded, and then it will be equated first.
int size_d = 0;
int size_dict = 0;

//Pointer to the root element of a trie.
node *first = NULL;
/////////////////////////////////////////////////
/**
 * Returns true if word is in dictionary else false.
 * Возвращает true, если слово в словаре else false.
 */
bool check(const char *word)
{
    node *root = first;
    int index = 0;
    while (*(word + index) != '\0')
    {
        char c = tolower(*(word + index));
        if (root->next[c - 96] == NULL)
        {
            return false;
        }
        else
        {
            root = root->next[c - 96];
        }
        index++;
    }
    if (*(word + index) == '\0' &&  root->end_word == true)
    {
        return true;
    }
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 * Загружает словарь в память.
 * Возвращает true, если в противном случае false.
 */
bool load(const char *dictionary)
{
    FILE *ptrfile = fopen(dictionary, "r");
    node *root = calloc(sizeof(node),1);
    first = root;
    char c;

     while (fread(&c, sizeof(char), 1, ptrfile) == 1)
    {
        if (c  != '\n')
        {
            if (root->next[c - 96] != NULL)
            {
                root = root->next[c - 96];
            }
            else
            {
              node *child = calloc(sizeof(node),1);
              root->next[c - 96] = child;
              root = root->next[c - 96];
            }
        }
        else
        {
            root->end_word = true;
            size_dict ++;
            root = first;
        }
    }
    if (fscanf(ptrfile, "%c", &c) == EOF)
    {
        size_d = size_dict;
        fclose(ptrfile);
        return true;
    }
    return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 * Возвращает количество слов в словаре, если загружено else 0, если еще не загружено.
 */
unsigned int size(void)
{
    return size_dict;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 * Выгружает словарь из памяти. Возвращает true, если в противном случае false.
 */
void un (node *root)
{
    for (int i = 0; i < 27; i++)
    {
        if (root->next[i] != NULL)
        {
            un(root->next[i]);
        }
    }
    free(root);
    return;
}

bool unload(void)
{
    node *root = first;
    un (root);
    return true;
}


