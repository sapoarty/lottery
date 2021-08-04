#include <stdio.h>
#include "lottery.h"

void check_ticket(const int *winner_numbers)
{
    int input_num;
    int win_num_ind;
    int cur_num;
    int match_qty;

    match_qty = 0;
    for(input_num = 0; input_num < TICKET_NUM_QTY; input_num++)
    {
        scanf("%d", &cur_num);
        if (match_qty < NUM_QTY_TO_WIN)
        {
            for (win_num_ind = 0; win_num_ind < WIN_NUMS_QTY; win_num_ind++)
            {
                if (winner_numbers[win_num_ind] == cur_num)
                {
                    /* If num is found in the win list we increase the match and check next num */
                    match_qty++;
                    break;
                }
            }
        }
    }
    if (match_qty >= NUM_QTY_TO_WIN)
        printf(WIN_MSG);
    else
        printf(LOSE_MSG);
}

int main()
{
    int n;
    int winner_numbers[WIN_NUMS_QTY];
    int tickets_qty;

    /* Read winner numbers */
    for(n = 0; n < WIN_NUMS_QTY; n++)
    {
        scanf("%d", &winner_numbers[n]);
    }

    scanf("%d", &tickets_qty);

    /* Check all the tickets */
    for(n = 0; n < tickets_qty; n++)
    {
        check_ticket(winner_numbers);
    }
    return (0);
}
