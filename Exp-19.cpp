#include <stdio.h>
struct Item
{
    int value;
    int weight;
};
int main()
{
    int W = 50; 
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);
    for (int i = 0; i < n - 1; i++)
	{
        for (int j = 0; j < n - i - 1; j++)
		{
            double r1 = (double)items[j].value / items[j].weight;
            double r2 = (double)items[j + 1].value / items[j + 1].weight;
            if (r1 < r2)
			{
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
    int curWeight = 0;
    double finalValue = 0.0;
    for (int i = 0; i < n; i++)
	{
        if (curWeight + items[i].weight <= W)
		{
            curWeight += items[i].weight;
            finalValue += items[i].value;
        } 
		else
		{
            int remain = W - curWeight;
            finalValue += items[i].value * ((double) remain / items[i].weight);
            break;
        }
    }
    printf("Maximum value we can obtain = %.2f\n", finalValue);
}
