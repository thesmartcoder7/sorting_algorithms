#include "deck.h"
#include "stdio.h"


/**
 * sort_deck - this Sorts a deck of cards represented
 * as a doubly linked list.
 * @deck: The doubly linked list representing the deck.
 */

void sort_deck(deck_node_t **deck)
{
deck_node_t *sm_c;
size_t length;
deck_node_t *one, *two, *three, *four;

length = list_length_deck(*deck);

if (!deck || !*deck || length < 2)
	return;

sm_c = *deck;
while (sm_c)
{
	if (sm_c->prev && card_val(sm_c) < card_val(sm_c->prev))
	{
		one = sm_c->prev->prev;
		two = sm_c->prev;
		three = sm_c;
		four = sm_c->next;

		two->next = four;
		if (four)
			four->prev = two;
		three->next = two;
		three->prev = one;
		if (one)
			one->next = three;
		else
			*deck = three;
		two->prev = three;
		sm_c = *deck;
		continue;
	}
	else
		sm_c = sm_c->next;
}
}

/**
 * card_val - Returns the value of a card in a deck.
 * @node: The card in the deck.
 *
 * Return: value between 1 and 52
 */

int card_val(deck_node_t *node)
{
char *val[13] = {"Ace", "2", "3", "4", "5", "6",
	"7", "8", "9", "10", "Jack", "Queen", "King"};
char *kinds[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
int i, kind_val = 0;

for (i = 1; i <= 13; i++)
{
	if (!str_cpy(node->card->value, val[i - 1]))
		kind_val = i;
}

for (i = 1; i <= 4; i++)
{
	if (!str_cpy(kinds[node->card->kind], kinds[i - 1]))
		kind_val = kind_val + (13 * i);
}

return (kind_val);
}

/**
 * str_cpy - Compares two strings.
 * @string_1: The first string to compare.
 * @string_2: The second string to compare.
 *
 * Return: less than 0 if string_1 is less than string_2, 0 if they're equal,
 * more than 0 if string_1 is greater than string_2
 */

int str_cpy(const char *string_1, const char *string_2)
{
while (*string_1 == *string_2)
{
	if (*string_1 == '\0')
	{
		return (0);
	}
	string_1++;
	string_2++;
}
return (*string_1 - *string_2);
}

/**
 * list_length_deck - Computes the lengthgth of a linked list.
 * @list: head of list
 *
 * Return: lengthgth
 */

size_t list_length_deck(deck_node_t *list)
{
size_t length = 0;

while (list)
{
	length++;
	list = list->next;
}
return (length);
}
