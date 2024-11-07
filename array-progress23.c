#include <stdio.h>

void transactions(int ntransection,int transection[]);

void transactions(int ntransection,int transection[])
{
    int blance=1000;
    int tobeprocessed[50];
    int tbpsize=0;
    for (int i=0;i<ntransection;i++)
    {
        int currenttransection=transection[i];
        printf("current balance:%d aed\n",blance);
        if (currenttransection<0 && -currenttransection>blance)
        {
            printf ("not enough balance to go through with the transection\n");
            tobeprocessed[tbpsize++]= currenttransection;
            continue;
        }
        blance+=currenttransection;
        if (blance<=0)
        {
            printf("balance is zero");
            break;
        }
    }
    printf("inal balance:%d aed \n", blance);
    printf("unprocessed transactions");
    for(int i=0;i<tbpsize;i++)
    {
        printf("%d", tobeprocessed[i]);
    }
}
int main()
{
    int size;
    printf("Enter the number of transactions");
    scanf("%d",&size);
    int transection[size];
    for(int i=0;i<size;i++)
    {
        scanf("%d",&transection[i]);
    }
    transactions(size,transection);
    return 0;
}