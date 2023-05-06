#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct item
{
 int id,Quantity;
 char name[20];
 float price;
}items[100],sales[100];
struct customer
{
    int id;
    int grandtotal;
    char name[30];
}custom[100];
int choice,posoption,invoption,salesoption,total,salestotal,totalsales[100],money=0;
int totalprice[100];
void mainmenu()
{
 printf("*****************************\n");
 printf("             MENU\n");
 printf("*****************************\n");
 printf("\n");
 printf("1. Point of Sales\n");
 printf("2. Total Sales and Inventory\n");
 printf("3. Inventory Control System\n");
 printf("4. Exit\n");
 scanf("%d",&choice);
}
void POSmenu()
{
 printf("*****************************\n");
 printf("           POS MENU\n");
 printf("*****************************\n");
 printf("\n");
printf("1. New Sale\n");
printf("2. Edit Sale\n");
printf("3. Delete Sale\n");
printf("4. Search Sale\n");
printf("5. Back To Previous Menu\n");
scanf("%d",&posoption);
}
void InvMenu()
{
 printf("*****************************\n");
 printf("           INV MENU\n");
 printf("*****************************\n");
 printf("\n");
printf("1. Add New Item\n");
printf("2. Edit Item\n");
printf("3. Delete Item\n");
printf("4. Search Item\n");
printf("5. Back To Previous Menu\n");
scanf("%d",&invoption);
}
void salesmenu()
{
 printf("*****************************\n");
 printf("       TOTAL SALES MENU\n");
 printf("*****************************\n");
 printf("\n");
 printf("1. Total Sales\n");
 printf("2. Total Cash\n");
 printf("3. Total Inventory Left\n");
 printf("4. Back To Previous Menu\n");
 scanf("%d",&salesoption);
}
void additem()
{
int addid;
char continuechoice;
FILE *add;
add=fopen("listofitems.txt","a+");
fprintf(add,"*********************************************************************************************\n");
fprintf(add,"                                   LIST OF ITEMS\n");
fprintf(add,"*********************************************************************************************\n");
    do
    {
    total++;
    printf("Enter ID\n");
    scanf("%d",&items[total].id);
    printf("Enter Name\n");
    fflush(stdin);
    gets(items[total].name);
    printf("Enter Quantity\n");
    scanf("%d",&items[total].Quantity);
    printf("Enter Price\n");
    scanf("%f",&items[total].price);
    fprintf(add,"\nID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n",items[total].id,items[total].name,items[total].Quantity,items[total].price);
    fprintf(add,"---------------------------------------------------------------------------------\n");
    printf("DO YOU WANT TO CONTINUE ADDING ITEMS? [Y/N]\n");
    fflush(stdin);
    scanf("%c",&continuechoice);
    if((continuechoice=='N')||(continuechoice=='n'))
    {
        break;
    }
    }while((continuechoice=='Y')||(continuechoice=='y'));
    fclose(add);
}
void searchitem()
{
    int searchid;
    char searching;
    printf("Enter Search ID\n");
    scanf("%d",&searchid);
    for (int i=0;i<=total;i++)
    {
        if (items[i].id==searchid)
        {
            printf("\nID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n",items[i].id,items[i].name,items[i].Quantity,items[i].price);
            printf("Do you want to search more items\n");
            fflush(stdin);
            scanf("%c",&searching);
            if ((searching=='y')||(searching=='Y'))
            {
                searchitem();
            }
            else
            {
               break;
            }
        }
    }
}
void edititem()
{
    int editid,num,newid,newquantity;
    float newprice;
    char newname[20];
    FILE *ptr;
    ptr=fopen("listofitems.txt","a");
 printf("Enter ID to edit\n");
 scanf("%d",&editid);
 for (int j=0;j<=total;j++)
    {
        if (items[j].id==editid)
        {
        printf("Enter what do you want to edit?\n");
        printf("1. ID\n");
        printf("2. Name\n");
        printf("3. Quantity\n");
        printf("4. Price\n");
        printf("Enter choice\n");
        scanf("%d",&num);
        if (num==1)
        {
            printf("ENTER NEW ID\n");
            scanf("%d",&newid);
            items[j].id=newid;
            printf("\nID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n",items[j].id,items[j].name,items[j].Quantity,items[j].price);
            remove("listofitems.txt");
            FILE *edit;
            edit=fopen("listofitems.txt","a");
            fprintf(edit,"*********************************************************************************************\n");
            fprintf(edit,"                                   LIST OF ITEMS\n");
            fprintf(edit,"*********************************************************************************************\n");
            for (int a=0;a<=total;a++)
            {
                fprintf(edit,"\nID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n",items[a].id,items[a].name,items[a].Quantity,items[a].price);
                fprintf(edit,"---------------------------------------------------------------------------------\n");
            }
            fclose(edit);
        }
        else if (num==2)
        {
            printf("ENTER NEW NAME\n");
            fflush(stdin);
            gets(newname);
            printf("\nID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n",items[j].id,items[j].name,items[j].Quantity,items[j].price);
            strcpy(items[j].name,newname);
            remove("listofitems.txt");
            FILE *edit1;
            edit1=fopen("listofitems.txt","a");
            fprintf(edit1,"*********************************************************************************************\n");
            fprintf(edit1,"                                   LIST OF ITEMS\n");
            fprintf(edit1,"*********************************************************************************************\n");
            for (int a=0;a<=total;a++)
            {
                fprintf(edit1,"\nID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n",items[a].id,items[a].name,items[a].Quantity,items[a].price);
                fprintf(edit1,"---------------------------------------------------------------------------------\n");
            }
            fclose(edit1);
        }
        else if (num==3)
        {
            printf("ENTER NEW QUANTITY\n");
            scanf("%d",&newquantity);
            items[j].Quantity=newquantity;
            remove("listofitems.txt");
            FILE *edit2;
            edit2=fopen("listofitems.txt","a");
            fprintf(edit2,"*********************************************************************************************\n");
            fprintf(edit2,"                                   LIST OF ITEMS\n");
            fprintf(edit2,"*********************************************************************************************\n");
            for (int a=0;a<=total;a++)
            {
                fprintf(edit2,"\nID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n",items[a].id,items[a].name,items[a].Quantity,items[a].price);
                fprintf(edit2,"---------------------------------------------------------------------------------\n");
            }
            fclose(edit2);
        }
        else if (num==4)
        {
            printf("ENTER NEW PRICE\n");
            scanf("%d",&newprice);
            printf("\nID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n",items[j].id,items[j].name,items[j].Quantity,items[j].price);
            items[j].price=newprice;
            remove("listofitems.txt");
            FILE *edit3;
            edit3=fopen("listofitems.txt","a");
            fprintf(edit3,"*********************************************************************************************\n");
            fprintf(edit3,"                                   LIST OF ITEMS\n");
            fprintf(edit3,"*********************************************************************************************\n");
            for (int a=0;a<=total;a++)
            {
                fprintf(edit3,"\nID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n",items[a].id,items[a].name,items[a].Quantity,items[a].price);
                fprintf(edit3,"---------------------------------------------------------------------------------\n");
            }
            fclose(edit3);
        }
        }
    }

}
void deleteitem()
{
int deleteid=0,k;
FILE *del;
 del=fopen("listofitems.txt","a");
 printf("Enter Search ID\n");
 scanf("%d",&deleteid);
  for (k=0;k<=100;k++)
    {
        if (items[k].id==deleteid)
        {
         printf("\nID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n",items[k].id,items[k].name,items[k].Quantity,items[k].price);
         for (int c=k;c<=99;c++)
        {
            items[c].id=items[c+1].id;
            strcpy(items[c].name,items[c+1].name);
            items[c].Quantity=items[c+1].Quantity;
            items[c].price=items[c+1].price;
        }
fclose(del);
        FILE *deli;
        deli=fopen("copy2.txt","a");
        for (int b=0;b<=99;b++)
        {
                fprintf(deli,"\nID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n",items[b].id,items[b].name,items[b].Quantity,items[b].price);
                fprintf(deli,"---------------------------------------------------------------------------------\n");
        }
        fclose(deli);
        }
        break;
    }


}
void newsale()
{
    int day,month,year;
    char addoption,recieptoption,finaltotal=0,tax=0,discount=0,disvalue=0,paid=0,change=0;
    FILE *sale;
    sale=fopen("sales.txt","a");
    fprintf(sale,"***********************************************************************************************\n");
    fprintf(sale,"                                        SALES\n");
    fprintf(sale,"***********************************************************************************************\n");
    int cus;
    for (cus=0;cus<100;cus++)
    {
        fprintf(sale,"Customer %d\n",cus+1);
    for(salestotal=0;salestotal<100;salestotal++)
    {
       printf("ENTER PRODUCT ID\n");
       scanf("%d",&sales[salestotal].id);
       if (sales[salestotal].id==0)
       {
           pointofsales();
       }
       else
       {
       for(int q=0;q<=total;q++)
       {
          if (items[q].id=sales[salestotal].id)
          {
              custom[cus].id=cus;
              strcpy(sales[salestotal].name,items[q].name);
              printf("ENTER QUANTITY\n");
              scanf("%d",&sales[salestotal].Quantity);
              items[q].Quantity=items[q].Quantity-sales[salestotal].Quantity;
              sales[salestotal].price=items[q].price;
              fprintf(sale,"\nID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n",sales[salestotal].id,sales[salestotal].name,sales[salestotal].Quantity,sales[salestotal].price);
              printf("DO YOU ADD MORE ITEMS TO CART\n");
              fflush(stdin);
              scanf("%c",&addoption);
              if ((addoption=='Y')||(addoption=='y'))
              {
                  break;
              }
              else
              {
                  fclose(sale);
                printf("DO YOU WANT RECIEPT?\n");
                fflush(stdin);
                scanf("%c",&recieptoption);
                if ((recieptoption=='Y')||(recieptoption=='y'))
                {
                printf("Wait while your receipt is being processed\n");
                FILE *rec;
                rec=fopen("Receipt.txt","a");
                fprintf(rec,"\n");
                fprintf(rec,"************************************************\n");
                fprintf(rec,"                 CUSTOMER RECEIPT                    \n");
                fprintf(rec,"************************************************\n");
                fprintf(rec,"\n");
                printf("Enter Customer Name:\n");
                fflush(stdin);
                gets(custom[cus].name);
                printf("Enter Date:\n");
                scanf("%d/%d/%d",&day,&month,&year);
                fprintf(rec,"Customer Name:%s\t Date:%d/%d/%d\n",custom[cus].name,day,month,year);
                fprintf(rec,"\n");
                for (int v=0;v<=salestotal;v++)
            {
                totalprice[v]=sales[v].Quantity*sales[v].price;
                fprintf(rec,"\nID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\nTotal Price:%.2f\n",sales[v].id,sales[v].name,sales[v].Quantity,sales[v].price,totalprice[v]);
                finaltotal=finaltotal+totalprice[v];
            }
                fprintf(rec,"\n");
                fprintf(rec,"\n");
                fprintf(rec,"Total Before Tax=%.2f\n",finaltotal);
                tax=finaltotal*0.17;
                custom[cus].grandtotal=0;
                custom[cus].grandtotal=finaltotal+tax;
                printf("Any discount?\n");
                scanf("%d",&discount);
                disvalue=(custom[cus].grandtotal)*discount;
                custom[cus].grandtotal=custom[cus].grandtotal-disvalue;
                fprintf(rec,"Discount:-%d\nTax=%d\n",disvalue,tax);
                printf("PLEASE PAY %d\n",custom[cus].grandtotal);
                totalsales[cus]=totalsales[cus]+custom[cus].grandtotal;
                printf("Enter Amount paid\n");
                scanf("%d",&paid);
                change=paid-custom[cus].grandtotal;
                  if (change<0)
                 {
                printf("Please pay %d more\n",change);
                }
                else
                {
                  printf("Change=%d\n",change);
                }
                money=money+paid-change-tax;
                fprintf(rec,"Total After Tax=%.2f\n",custom[cus].grandtotal);
                }
            else
            {
                for (int m=0;m<=salestotal;m++)
            {
                totalprice[m]=sales[m].Quantity*sales[m].price;
                finaltotal=finaltotal+totalprice[m];
            }
                tax=finaltotal*0.17;
                custom[cus].grandtotal=0;
                custom[cus].grandtotal=finaltotal+tax;
                printf("How much discount?\n");
                scanf("%d",&discount);
                disvalue=(custom[cus].grandtotal)*discount;
                custom[cus].grandtotal=custom[cus].grandtotal-disvalue;
                printf("PLEASE PAY %d\n",custom[cus].grandtotal);
                totalsales[cus]=0;
                totalsales[cus]=totalsales[cus]+custom[cus].grandtotal;
                printf("Enter Amount paid\n");
                scanf("%d",&paid);
                change=paid-custom[cus].grandtotal;
                  if (change<0)
                 {
                printf("Please pay %d more\n",change);
                }
                else
                {
                  printf("Change=%d\n",change);
                }
                money=money+paid-change-tax;
            }
            }
            break;
            break;
              }
              }
          }
       }
    }
}
void searchsale()
{
    int searchcustomer;
printf("ENTER CUSTOMER ID:\n");
scanf("%d",&searchcustomer);
for (int w=0;w<100;w++)
{
    if (custom[w].id==searchcustomer)
    {
      printf("ID: %d\nName: %s\nTotal Sale: %d\n",custom[w].id,custom[w].name,custom[w].grandtotal);
    }
    else
    {
        break;
    }
}
}
void editsale()
{
    char editoption;
int searchcustom,seaid,newquantity;
printf("ENTER CUSTOMER ID:\n");
scanf("%d",&searchcustom);
for (int w=0;w<100;w++)
{
    if (custom[w].id==searchcustom)
    {
        for (int t=0;t<100;t++)
        {
            printf("ENTER PRODUCT ID:\n");
            scanf("%d",&seaid);
            if (seaid==0)
            {
                break;
                break;
                pointofsales();
            }
            else if (sales[t].id==seaid)
            {
                printf("Enter New Quantity?\n");
                scanf("%d",&newquantity);
                totalprice[t]=totalprice[t]-(sales[t].price*sales[t].Quantity);
                sales[t].Quantity=newquantity;
                totalprice[t]=totalprice[t]+(sales[t].price*newquantity);
                totalsales[t]=totalsales[t]-(sales[t].price*newquantity);
                custom[w].grandtotal=custom[w].grandtotal-(sales[t].price*newquantity);
                money=money-(sales[t].price*newquantity);
                printf("DO YOU WANT TO EDIT MORE SALES?");
                fflush(stdin);
                scanf("%c",&editoption);
                if ((editoption=='n')||(editoption=='N'))
                {
                   break;
                   break;
                   editsale();
                }
                else if ((editoption=='Y')||(editoption=='y'))
                {
                FILE *ed;
                ed=fopen("sales.txt","a");
                remove("sales.txt");
                FILE *ed2;
                ed2=fopen("sales.txt","a");
                for (int r=0;r<100;r++)
                {
                    fprintf(ed2,"Customer %d\n",r+1);
                    for(int x=0;x<100;x++)
                    {
                        fprintf(ed2,"\nID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\nTotal Price:%.2f\n",sales[x].id,sales[x].name,sales[x].Quantity,sales[x].price,totalprice[x]);
                    }
                }
                fclose(ed2);
                break;
                break;
            }
    }
    else if (seaid==0)
    {
        break;
    }
}
}
}
}
void deletesale()
{
    char searchcust;
 int searcust,searid;
 FILE *fp2;
 fp2=fopen("sales.txt","a");
printf("ENTER CUSTOMER ID:\n");
scanf("%d",&searchcust);
for (int p=0;p<100;p++)
{
    if (custom[p].id==searchcust)
    {
        for (int e=0;e<100;e++)
        {
            printf("ENTER PRODUCT ID:\n");
            scanf("%d",&searid);
            if (sales[e].id==searid)
            {
             custom[p].grandtotal=custom[p].grandtotal-totalprice[e];
             totalsales[e]=totalsales[e]-totalprice[e];
             money=money-totalprice[e];
             sales[e].id=sales[e+1].id;
             strcpy(sales[e].name,sales[e+1].name);
             sales[e].Quantity=sales[e+1].Quantity;
             sales[e].price=sales[e+1].price;
             totalprice[e]=totalprice[e];
             totalsales[e]=totalsales[e+1];
            }
            break;
        }
      break;
    }
}
fclose(fp2);
FILE *fp3;
fp3=fopen("copy.txt","a");
for (int l=0;l<100;l++)
{
    printf("Customer %d",l+1);
    for(int h=0;h<99;h++)
    {
fprintf(fp3,"\nID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\nTotal Price:%.2f\n",sales[h].id,sales[h].name,sales[h].Quantity,sales[h].price,totalprice[h]);
    printf("\nID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\nTotal Price:%.2f\n",sales[h].id,sales[h].name,sales[h].Quantity,sales[h].price,totalprice[h]);
    }
}
fclose(fp3);
}
void pointofsales()
{
    POSmenu();
    if (posoption==1)
    {
        newsale();
        pointofsales();
    }
    else if (posoption==2)
    {
        editsale();
        pointofsales();
    }
    else if (posoption==3)
    {
        deletesale();
        pointofsales();
    }
    else if (posoption==4)
    {
        searchsale();
        pointofsales();
    }
    else
    {
        printf("Invalid Input\n");
        pointofsales();
    }
}
void InventorySystem()
{
InvMenu();
if (invoption==1)
{
additem();
InventorySystem();
}
else if (invoption==2)
{
edititem();
InventorySystem();
}
else if (invoption==3)
{
deleteitem();
InventorySystem();
}
else if (invoption==4)
{
searchitem();
InventorySystem();
}
else if(invoption==5)
{
InventorySystem();
}
}
void arrayintialize()
{
    items[0].id=1;
   strcpy(items[0].name,"Safeguard Soap");
   items[0].Quantity=30;
   items[0].price=35;
   items[1].id=2;
   strcpy(items[1].name,"Dettol");
   items[1].Quantity=35;
   items[1].price=28;
   items[2].id=3;
   strcpy(items[2].name,"Lux");
   items[2].Quantity=50;
   items[2].price=45;
   items[3].id=4;
   strcpy(items[3].name,"Sunsilk");
   items[3].Quantity=18;
   items[3].price=38;
   items[4].id=5;
   strcpy(items[4].name,"Olpers");
   items[4].Quantity=80;
   items[4].price=120;
   items[5].id=6;
   strcpy(items[5].name,"MilkPak");
   items[5].Quantity=70;
   items[5].price=100;
   items[6].id=7;
   strcpy(items[6].name,"Dairy Milk");
   items[6].Quantity=70;
   items[6].price=25;
   items[7].id=8;
   strcpy(items[7].name,"Mars");
   items[7].Quantity=97;
   items[7].price=45;
   items[8].id=9;
   strcpy(items[8].name,"Oil");
   items[8].Quantity=48;
   items[8].price=135;
   items[9].id=10;
   strcpy(items[9].name,"Sugar");
   items[9].Quantity=89;
   items[9].price=90;
   items[10].id=11;
   strcpy(items[10].name,"Salt");
   items[10].Quantity=98;
   items[10].price=67;
   items[11].id=12;
   strcpy(items[11].name,"Rice");
   items[11].Quantity=29;
   items[11].price=170;
   items[12].id=13;
   strcpy(items[12].name,"Noodles");
   items[12].Quantity=61;
   items[12].price=80;
   items[13].id=14;
   strcpy(items[13].name,"Tooth Brush");
   items[13].Quantity=49;
   items[13].price=28;
   items[14].id=15;
   strcpy(items[14].name,"Lays");
   items[14].Quantity=78;
   items[14].price=30;
   items[15].id=16;
   strcpy(items[15].name,"Coca Cola");
   items[15].Quantity=100;
   items[15].price=90;
   items[16].id=17;
   strcpy(items[16].name,"Pepsi");
   items[16].Quantity=120;
   items[16].price=88;
   items[17].id=18;
   strcpy(items[17].name,"Cornetto");
   items[17].Quantity=57;
   items[17].price=60;
   items[18].id=19;
   strcpy(items[18].name,"Magnum");
   items[18].Quantity=56;
   items[18].price=130;
   items[19].id=20;
   strcpy(items[19].name,"Egg");
   items[19].Quantity=156;
   items[19].price=130;
   items[20].id=21;
   strcpy(items[20].name,"Bread");
   items[20].Quantity=89;
   items[20].price=45;
}
void tsales()
{
FILE *totalsale;
totalsale=fopen("totalsales.txt","a");
for (int u=0;u<100;u++)
{
    printf("CUSTOMER ID:%d\nCUSTOMER NAME:%s\nCUSTOMER SALE:%d",custom[u].id,custom[u].name,custom[u].grandtotal);
    printf("---------------------------------------------------------------------------------\n");
    fprintf(totalsale,"CUSTOMER ID:%d\nCUSTOMER NAME:%s\nCUSTOMER SALE:%d",custom[u].id,custom[u].name,custom[u].grandtotal);
    fprintf(totalsale,"---------------------------------------------------------------------------------\n");
}
}
void totalcash()
{
    int smoney;
printf("ENTER STARTING MONEY\n");
scanf("%d",smoney);
smoney=smoney+money;
printf("MONEY AT THE END:%d\n",smoney);
}
void totalinventory()
{
    FILE *remain;
    remain=fopen("inventoryremaining.txt","a");
    for(int y=0;y<100;y++)
    {
    printf("\nID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n",items[y].id,items[y].name,items[y].Quantity,items[y].price);
    fprintf(remain,"\nID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n",items[y].id,items[y].name,items[y].Quantity,items[y].price);
    fprintf(remain,"---------------------------------------------------------------------------------\n");
    }
}
void totalsalesmoney()
{
if (salesoption==1)
{
tsales();
salesmenu();
}
else if (salesoption==2)
{
totalcash();
salesmenu();
}
else if (salesoption==3)
{
totalinventory();
salesmenu();
}
else if (salesoption==4)
{
salesmenu();
}
else
{
    printf("Invalid Input\n");
    salesmenu();
}
}
void main()
{
arrayintialize();
mainmenu();
if (choice==1)
{
pointofsales();
}
else if (choice==2)
{
totalsalesmoney();
}
else if (choice==3)
{
InventorySystem();
}
else if (choice==4)
{
exit(0);
}
else
{
    printf("Invalid Input\n");
    main();
}
}


