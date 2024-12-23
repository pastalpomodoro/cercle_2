#include "push_swap.h"

void print(t_num *pile)
{
    while (pile != NULL)
    {
        ft_printf("%d  ", pile->num);
        pile = pile->next;
    }
    ft_printf("\n");
}
int find_biggher(t_num *pile)
{
    t_num *temp;

    temp = pile;
    while (pile)
    {
        if (if_bigger(temp, pile->num))
            return (pile->num);
        pile = pile->next;
    }
    return (0);
}
int find_upper(t_num *pile, int n)
{
    int big;

    big = 2147483647;
    while (pile != NULL)
    {
        if (pile->num > n && big >= pile->num)
            big = pile->num;
        pile = pile->next;
    }
    return (big);
}
int find_under(t_num *pile, int n)
{
    int small;

    small = -2147483648;
    while (pile != NULL)
    {
        if (pile->num < n && small <= pile->num)
            small = pile->num;
        pile = pile->next;
    }
    return (small);
}
int small_sort(t_num **pile_a)
{
    int count;
    t_num *temp;

    count = 0;
    if (if_bigger(*pile_a, pile_a[0]->num))
    {
        ra(pile_a);
        count++;
    }
    temp = pile_a[0]->next;
    if (if_bigger(*pile_a, temp->num))
    {
        rra(pile_a);
        count++;
    }
    temp = pile_a[0]->next;
    if (pile_a[0]->num > temp->num)
    {
        sa(pile_a);
        count++;
    }
    return (count);
}
int p_to_a(t_num **pile_a, t_num **pile_b)
{
    int count;
    int temp;

    count = 0;
    while (my_lstlen(pile_b) != 0)
    {
        temp = pile_a[0]->num;
        if (pile_b[0]->num == find_under(*pile_b, find_biggher(*pile_b)))
            pa(pile_a, pile_b);
        else if (if_bigger(*pile_b, pile_b[0]->num))
            pa(pile_a, pile_b);
        else if (find_index_biggher(*pile_b) > my_lstlen(pile_b) / 2)
            rrb(pile_b);
        else
            rb(pile_b);
        if (pile_a[0]->num > temp)
        {
            sa(pile_a);
            count++;
        }
        count++;
    }
    return (count);
}
int find_fives_bigghers(int nums[10], t_num *pile_a)
{
    int small;
    t_num *temp;

    small = find_index_smaller(pile_a) + 1;
    temp = pile_a;
    while (small--, small > 0)
        pile_a = pile_a->next;
    small = pile_a->num;
    nums[0] = small;
    nums[1] = find_upper(temp, nums[0]);
    nums[2] = find_upper(temp, nums[1]);
    nums[3] = find_upper(temp, nums[2]);
    nums[4] = find_upper(temp, nums[3]);
    nums[5] = find_upper(temp, nums[4]);
    nums[6] = find_upper(temp, nums[5]);
    nums[7] = find_upper(temp, nums[6]);
    nums[8] = find_upper(temp, nums[7]);
    nums[9] = find_upper(temp, nums[8]);
    return (small);
}
int gold_finder(int nums[10], int n)
{
    while (*nums)
    {
        if (n == *nums)
            return (1);
        nums++;
    }
    return (0);
}
int p_to_b(t_num **pile_a, t_num **pile_b)
{
    int count;
    int nums[10];
    int small;

    count = 0;
    small = find_fives_bigghers(nums, *pile_a);
    while (my_lstlen(pile_a) > 3)
    {
        if (find_index(*pile_a, small) == -1)
            small = find_fives_bigghers(nums, *pile_a);
        if (gold_finder(nums, pile_a[0]->num) == 1)
            pb(pile_a, pile_b);
        else
            ra(pile_a);
        count++;
    }
    count += p_to_a(pile_a, pile_b);
    return (count);
}

void test(t_num **pile_a, t_num **pile_b)
{
    int count;

    count = p_to_b(pile_a, pile_b);
    ft_printf("\n");
    print(*pile_a);
    print(*pile_b);
    ft_printf("COUNT: %d", count);
}
