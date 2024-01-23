#include <stdlib.h>
#include <stdio.h>
#include "deck.h"

/**
 * compare_cards - Compare two cards for qsort
 * @card1: Pointer to the first card
 * @card2: Pointer to the second card
 *
 * Return: Difference between card values
 */
int compare_cards(const void *card1, const void *card2)
{
    return (*(char *)card1 - *(char *)card2);
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Double pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    size_t i;
    char *values[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    deck_node_t *node = *deck;
    char *deck_values[52];

    if (!deck || !*deck)
        return;

    i = 0;
    while (node)
    {
        deck_values[i] = (char *)node->card->value;
        node = node->next;
        i++;
    }

    qsort(deck_values, 52, sizeof(char *), compare_cards);

    node = *deck;
    i = 0;
    while (node)
    {
        node->card->value = deck_values[i];
        node = node->next;
        i++;
    }
}
