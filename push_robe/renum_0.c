typedef struct s_stack
{
	int	*a;
	int	*b;
    int mosse;
    int *copy;
    int last_a;
    int last_b;
    int move;
    int posa;
    int posb;
	int defm;
    int defa;
    int defb;
    int cmp;
    int tmp; //per renum
	int tmp2; //per renum
	int tmpp2; //per renum
	int limit; // per renum
    int min;
	int mid;
    int max;
	int stck;
	int i; //per sotituire gli indici in generale
}	t_stack;



void renum(t_stack *stack, int ac)
{
	int max;

    renum1(stack, ac, max);
    renum2(stack, ac, max);
    while (stack->tmp <= stack->limit)
    {
        stack->i = 0;
        while (stack->i <= stack->last_a)
        {
            if (stack->a[stack->i] == stack->tmp)
                stack->a[stack->i] = stack->tmp - stack->min + 1;
            stack->i++;
        }
        stack->tmp++;
    }   
}


void renum1(t_stack *stack, int ac, int max)
{
	stack->tmpp2 = 0;
	stack->i = 0;
    stack->tmp = stack->a[0];
    max = stack->tmp;
    while (stack->i < ac - 2)
    {
        if (stack->a[stack->i] < stack->tmp)
            stack->tmp = stack->a[stack->i];
        stack->i++;
    }
    stack->min = stack->tmp;
    stack->limit = stack->tmp + (ac - 2);
    stack->i = 0;
     while (stack->i < ac - 2)
    {
        if (stack->a[stack->i] > max)
            max = stack->a[stack->i];
        stack->i++;
    }
}
void renum2(t_stack *stack, int ac, int max)
{
	 while (stack->tmp < stack->limit)
    {
        stack->tmp2 = max;
        stack->i = 0;
        stack->tmpp2 = stack->i;
        while( stack->i <= ac - 2)
        {
            if (stack->a[stack->i] <= stack->tmp2 && stack->a[stack->i] > stack->tmp)
            {
                stack->tmp2 = stack->a[stack->i];
                stack->tmpp2 = stack->i;
            }
            stack->i++;
        }
        stack->tmp++;
        stack->a[stack->tmpp2] = stack->tmp; 
    }
    stack->tmp = stack->min;
    stack->max = stack->limit;
}

//funzioni per versione alternativa di renum
void lookingfor(t_stack *stack, int stack->tmp2, int a)
{
     while (stack->i <= ac - 2)
    {
        if (stack->copy[stack->i] = stack->tmp2)
        {
    
