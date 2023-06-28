#include "deck.h"
#include <stdio.h>

void swap(deck_node_t **deck, deck_node_t *card_1, deck_node_t *card_2);
void sort_suit(deck_node_t **deck);
void sort_by_val(deck_node_t **deck);
int card_val_compare(const card_t *card_1, const card_t *card_2);
void sort_deck(deck_node_t **deck);


/**
 * swap - swaps 2 consecutive cards of a doubly linked list
 * Used in the insertion algorithm
 * @deck: Head node for the deck
 * @card_1: The first card to swap
 * @card_2: The second card to swap
 */
void swap(deck_node_t **deck, deck_node_t *card_1, deck_node_t *card_2)
{
	deck_node_t *prev, *next;

	prev = card_1->prev;
	next = card_2->next;

	if (prev != NULL)
		prev->next = card_2;
	else
		*deck = card_2;
	card_1->prev = card_2;
	card_1->next = next;
	card_2->prev = prev;
	card_2->next = card_1;
	if (next)
		next->prev = card_1;
}



/**
 * sort_suit - sorts a 52 card deck by suit
 * @deck: deck to sort
 */
void sort_suit(deck_node_t **deck)
{
	deck_node_t *f, *tmp;

	for (f = (*deck)->next; f && f->prev; f = f->next)
	{
		for (; f && f->prev && f->card->kind <
			     f->prev->card->kind; f = f->prev)
		{
			tmp = f->prev;
			swap(deck, tmp, f);
			f = f->next;
		}
	}
}


/**
 * sort_by_val - sorts a 52 card deck staticly by value
 * @deck: deck to sort
 */
void sort_by_val(deck_node_t **deck)
{
	deck_node_t *f, *tmp;

	for (f = (*deck)->next; f && f->prev; f = f->next)
	{
		for (; f && f->prev && card_compare(f->card, f->prev->card) &&
			     f->card->kind == f->prev->card->kind;
		     f = f->prev)
		{
			tmp = f->prev;
			swap(deck, tmp, f);
			f = f->next;
		}
	}
}



/**
 * card_val_compare - compares 2 card values
 * @card_1: The first card to compare
 * @card_2: The second card to compare
 *
 * Description: compares two cards by their values
 * Return: 1 if less than, 0 if greater or equal to
 */
int card_val_compare(const card_t *card_1, const card_t *card_2)
{
	char one = card_1->value[0], char2 = card_2->value[0];
	const char *ord[14] = {"Ac", "1", "2", "3", "4", "5", "6",
			       "7", "8", "9", "10", "Ja", "Qu", "Ki"};
	int idx1 = 0, idx2 = 0, i;

	if ((one >= 48 && one <= 57) && (char2 >= 49 &&
					     char2 <= 57))
	{
		if (card_1->value[1] == '0')
			one = 58;
		if (card_2->value[1] == '0')
			char2 = 58;
		return (one < char2);
	}
	else
	{
		for (i = 0; i < 14; i++)
		{
			if (card_1->value[0] == ord[i][0] &&
			    card_1->value[1] == ord[i][1])
				idx1 = i;
			if (card_2->value[0] == ord[i][0] &&
			    card_2->value[1] == ord[i][1])
				idx2 = i;
		}
		return (idx1 < idx2);
	}
}


/**
 * sort_deck - sorts a 52 card deck
 * @deck: deck to sort
 *
 * Return: Always 0 (ok)
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL)
		return;
	sort_suit(deck);
	sort_by_val(deck);
}
