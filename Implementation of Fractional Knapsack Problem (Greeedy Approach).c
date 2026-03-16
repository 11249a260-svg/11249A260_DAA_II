#include <stdio.h>
struct Item 
{
    int value;
    float weight;
    float profit_ratio;
};

void sort(struct Item items[],int n)
{
    struct Item temp;
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (items[j].profit_ratio<items[j+1].profit_ratio)
            {
                temp=items[j];
                items [j]=items[j+1];
                items [j+1]= temp;
            }
        }
    }
    printf("Items sorted by Value/Weight ratio :\n");
    for (int i=0;i<n;i++)
    {
        printf("Item %d: Weight = %f, value = %d, ratio =%.2f\n", i+1, items[i].weight, items[i].value, items[i].profit_ratio);
    }
}

int main()
{
    int n,capacity;
    float total_profit=0;
    printf("Enter the Number of items :");
    scanf("%d",&n);
    struct Item items[n];
    printf("Enter the Weight and Profit of the Items");
    for (int i=0;i<n;i++)
    {
        printf("\nFor %d item",i+1);
        printf("\tWeight");
        scanf("%f",&items[i].weight);
        printf("\tProfit");
        scanf("%d",&items[i].value);
        items[i].profit_ratio = (float)items[i].value/items[i].weight;
    }
    printf("Enter the Capacity of the Knapsack:");
    scanf("%d",&capacity);
    sort(items, n);
    for (int i=0;i<n;i++)
    {
        if (items[i].weight<capacity)
        {
            total_profit += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            total_profit += items[i].profit_ratio * capacity;
            break;
        }
    }
    printf("Maximum profit : %2f",total_profit);
    return 0;
}
