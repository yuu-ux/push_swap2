











# include "h_push_swap.h"

int get_max_bit(strhdr stack)
{
    int max;
    int max_bits;
    int i;

    i = 0;
    max = stack.data[0].index;
    max_bits = 0;
    while (i < stack.len)
    {
        if (stack.data[i].index > max)
            max = stack.data[i].index;
        i++;
    }
    while ((max >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

void    radix_sort(strhdr *stacka, strhdr *stackb)
{
    int i;
    int j;
    int max_bits;
    int size;

    i = 0;
    max_bits = get_max_bit(*stacka);
    size = stacka->len;
    while (i < max_bits)
    {
        j = 0;
        // 比較したあとにインクリメントされるから回る回数に影響はない
        // ただ、処理の中でjを使用する場合、挙動が変わってくるので注意が必要
        while (j++ < size)
        {
            if (((stacka->data[0].index >> i) & 1) == 1)
                operate_ra(*stacka);
            else
                operate_pb(stacka, stackb);
        }
        while (stackb->len != 0)
            operate_pa(stacka, stackb);
        i++;
    }
}
