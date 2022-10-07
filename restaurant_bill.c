// restaurant bill system by Aayush TC
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

struct items
{
    char item[20];
    float price;
    int qty;
};

struct order
{
    char costomer[50]; // name of the costomer
    char date[50]; //will fetch date form __DATE__
    int numOfItems;
    struct items itm[50];
};

// function to generate bills
int generateBillHeader(char name[50], char date[30])
{

    printf("\n\n");
    printf("\t    ADV. Restaurant");
    printf("\n\t    --------------------");
    printf("\nDate:%s", date);
    printf("\nInvoice to: %s", name);
    printf("\n");
    printf("---------------------------------------------\n");
    printf("Items\t\t");
    printf("Qty\t\t");
    printf("Total\t\t");
    printf("\n---------------------------------------------");
    printf("\n\n");
}

int generateBillBody(char item[30], int qty, float price)
{
    printf("%s\t\t", item);
    printf("%d\t\t", qty);
    printf("%.2f\t\t", qty * price);
    printf("\n");
}

int generateBillFooter(float total)
{
    printf("\n");
    float dis = 0.1 * total;
    float net_total = total - dis;
    float cgst = 0.09 * net_total;
    float grand_total = net_total + 2 * cgst;

    printf("-------------------------------\n");
    printf("Sub Total\t\t\t%.2f", total);
    printf("\nDiscount @10%s\t\t\t%.2f", "%", dis);
    printf("\n\t\t\t\t-------");
    printf("\n Net Total\t\t\t%.2f", net_total);
    printf("\n CGST @9\t\t\t%.2f", cgst);
    printf("\n SGST @9\t\t\t%.2f", cgst);
    printf("\n-------------------------------------");
    printf("\nGrand Total\t\t\t%.2f", grand_total);
    printf("\n---------------------------------------\n");
}

int main(int argc, char const *argv[])
{
    float total;
    int opt, n;
    struct order ord;  // particularly for file write
    struct order ord1; // particularly for file read
    char savebill = 'y';
    char contFlag = 'y';
    char name[50];
    FILE *fp;

    // dashboard
    while(contFlag == 'y'){
    float total = 0;
    int invoiceFound = 0;
    system("CLS");
    printf("\n\nPlease select ypur prefered option: ");
    printf("\n\n\t=============ADV. RESTAURANT=============");
    printf("\n\n1. Generate Invoice");
    printf("\n2. Show all Invoices");
    printf("\n3. Search Invoice");
    printf("\n4. Exit");
    printf("\n\nPLease select your choice here:\t");
    scanf("%d", &opt);
    fgetc(stdin); // to remove mixture error of scanf and fgets...

    switch (opt)
    {
    case 1:
        system("CLS");
        printf("\nPlease enter the name of a costomer:\t");
        fgets(ord.costomer, 50, stdin);
        ord.costomer[strlen(ord.costomer) - 1] = 0; // to esc extra \n created by scanf
        strcpy(ord.date, __DATE__);
        printf("\nPlease enter the number of Items:\t");
        scanf("%d", &n);
        ord.numOfItems = n;
        for (int i = 0; i < n; i++)
        {
            fgetc(stdin);
            printf("\n\n");
            printf("Please enter the item %d:\t", i + 1);
            fgets(ord.itm[i].item, 20, stdin); // items liine jati number halyo teti
            ord.itm[i].item[strlen(ord.itm[i].item) - 1] = 0;
            printf("Please enter the quantity:\t"); // quantity of particular item
            scanf("%d", &ord.itm[i].qty);
            printf("Please enter the unit price:\t"); // single price of a particular item
            scanf("%f", &ord.itm[i].price);
            total += ord.itm[i].qty * ord.itm[i].price;
        }

        generateBillHeader(ord.costomer, ord.date);

        for (int i = 0; i < ord.numOfItems; i++)
        {
            generateBillBody(ord.itm[i].item, ord.itm[i].qty, ord.itm[i].price);
        }

        generateBillFooter(total);
        printf("\nDO you want to save the invoice [y/n]:\t");
        scanf("%s", &savebill);
        if (savebill == 'y')
        {
            fp = fopen("invoices.txt", "a+");
            fwrite(&ord, sizeof(struct order), 1, fp);
            if (fwrite != 0)
            {
                printf("\nSuccessfully saved");
            }
            else
            {
                printf("\nError saving");
            }
            fclose(fp);
        }
        break;

    case 2:
        system("CLS");
        fp = fopen("invoices.txt", "r");
        printf("\n\n  ****Your Previous Invoices****\n");
        while (fread(&ord1, sizeof(struct order), 1, fp))
        {
            float tot = 0;
            generateBillHeader(ord1.costomer, ord1.date);
            for (int i = 0; i < ord1.numOfItems; i++)
            {
                generateBillBody(ord1.itm[i].item, ord1.itm[i].qty, ord1.itm[i].price);
                tot += ord1.itm[i].qty * ord1.itm[i].price;
            }
            generateBillFooter(tot);
        }
        fclose(fp);
        break;

    case 3:
        system("CLS");
        printf("\nPlease Enter the Name of the costomer:\t");
        // fgetc(stdin);
        fgets(name, 50, stdin);
        name[strlen(name) - 1] = 0;
        fp = fopen("invoices.txt", "r");
        printf("\n  ****Invoices Of %s****\n", name);
        while (fread(&ord1, sizeof(struct order), 1, fp))
        {
            float tot = 0;
            if (strcmp(ord1.costomer, name) == 0)
            {
                generateBillHeader(ord1.costomer, ord1.date);
                for (int i = 0; i < ord1.numOfItems; i++)
                {
                    generateBillBody(ord1.itm[i].item, ord1.itm[i].qty, ord1.itm[i].price);
                    tot += ord1.itm[i].qty * ord1.itm[i].price;
                }
                generateBillFooter(tot);
                invoiceFound = 1;
            }
        }
        if (!invoiceFound)
        {
            printf("\nSorry the invoice for %s doesn't exists", name);
        }
        fclose(fp);
        break;

    case 4:
        system("CLS");
        system("exit");
        break;
    default:
        printf("\nError");
        break;
    }
    printf("\nDo youn want to perform another operation [y/n]:\t");
    scanf("%s", contFlag);
}
    
    printf("\n\n");    
    return 0;
}