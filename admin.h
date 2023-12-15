void delete_order(struct order *odr, float *total, int k, int booking);
void print_receipt(float total, struct order *odr, int booking, int k);

//Function for staff login
int admin_login()
{
    //declare variables
	int try,i=0,x=0;
	char id[10]="user";
    char pswd[10]="123456";
    char idInput[10],c=' ';
    char pswdInput[10];

    //do...while loop for admin only can enter error for 3 times
    do
    {
        system("cls");

        printf("\n  ********************  ADMIN LOGIN  **************************  ");
        //Ask user to input idInput
        printf(" \n                         ID: ");
        scanf("%s", &idInput);
        printf(" \n                      PASSWORD: ");
        //Input password and display on screen with symbol ******
        while(i<10)
        {
            pswdInput[i]=getch();
            c=pswdInput[i];
            if(c==13) break;
            else printf("*");
            i++;
        }
        pswdInput[i]='\0';
        i=0;
        //If idInput match with id and pswdInput match with pswd
        if(strcmp(idInput,id)==0 && strcmp(pswdInput,pswd)==0)
        {
            printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL");
            x=0;
            break;
        }
        else
        {
            printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
            try++;
            getch();
        }
    }
	while(try<=2);
	//If user try to key in more than 3 times
	if (try>2)
	{
		printf("\nSorry you have entered over 3 times!!!");
		x=1;
		getch();
    }
    return x;
    system("cls");
}


//Function for go back to admin page by pressing enter key
void back_admin_page()
{
    printf("\n\nPress enter key to back to admin page\n");
    getch();
    system("cls");
    printf("\nGo back to admin page\n");
    Sleep(1000);
}


//Function for admin chooses options
void admin_opt()
{
    int opt=1;
    //Loop for user to access different tasks
    while (opt!=0)
    {
        system("cls");
        //call adminPage function
        adminPage();
        //Ask user input opt
        printf("\n\n\t\t\t Please choose [0-6] numbers: ");
        scanf("%d", &opt);
        system("cls");
        //switch for user choose option
        switch (opt)
        {
            case 1:
                //call add_menu function
                add_menu();
                //call back_admin_page function
                back_admin_page();
                break;
            case 2:
                //call view_menu function
                view_menu();
                //call back_admin_page function
                back_admin_page();
                break;
            case 3:
                //call modify_menu function
                modify_menu();
                //call back_admin_page function
                back_admin_page();
                break;
            case 4:
                //call delete_menu function
                delete_menu();
                //call back_admin_page function
                back_admin_page();
                break;
            case 5:
                //call search_customer_order function
                search_customer_order();
                //call back_admin_page function
                back_admin_page();
                break;
            case 6:
                //call admin_order function
                admin_order();
                //call back_admin_page function
                back_admin_page();
                break;
            case 0:
                //Exit admin page
                system("cls");
                printf("\n\n\t\t\t Sign out from admin page....");
                Sleep(1000);
                fflush(stdin);
                system("cls");
                return (0);
                break;
            default:
                printf("Key in error, please key in again: ");
                getch();
        }
    }
}


//Function for add menu item
void add_menu()
{
    //Declare variables
    int con, i=0, j;
    struct menu item[100];
    system("cls");
    //Loop for ask user whether to continue
    do
    {
        fflush(stdin);
        //Ask user to input item's information
        printf("Please enter item's details: \n");
        printf("Item's code: ");
        fgets(item[i].code,sizeof(item[i].code), stdin);
        item[i].code[strlen(item[i].code)-1]=0;
        printf("Name: ");
        fgets(item[i].name,sizeof(item[i].name), stdin);
        item[i].name[strlen(item[i].name)-1]=0;
        printf("Type: ");
        fgets(item[i].type,sizeof(item[i].type), stdin);
        item[i].type[strlen(item[i].type)-1]=0;
        printf("Price: RM ");
        scanf("%f", &item[i].price);
        //Ask user whether want to continue
        printf("Do you want to continue? 1.yes   2.no \n");
        scanf("%d", &con);
        i++;
    }while(con==1);
    //call write_menu function
    write_menu(item, i, "a");
    printf("\n Add Successful!\n");
}


//Function for modify menu
void modify_menu()
{
    //Declare variables
    struct menu item[100];
    int i=0, j, confirm, con;
    float price;
    char code[10];
    //call read_menu function
    read_menu(item, &i);
    //Loop for ask user whether to continue
     do
     {
         fflush(stdin);
         //Ask user to input code
         printf("\nPlease enter item's code for modify: \n");
         fgets(code,sizeof(code), stdin);
         code[strlen(code)-1]=0;
         for(j=0;j<i;j++)
         {
             //If strcmp(item[j].code match with code
             if(strcmp(item[j].code, code) == 0)
             {
                 printf("\nCode: %s",item[j].code);
                 printf("\nName: %s",item[j].name);
                 printf("\nType: %s",item[j].type);
                 printf("\nPrice: %.2f",item[j].price);
                //Ask user to confirm item
                printf("\nIs this the item that you want to modify? 1.Yes  2.No\n");
                scanf("%d",&confirm);
                //If confirmed, key in new information
                if(confirm == 1)
                {
                    fflush(stdin);
                    printf("Please enter new information:\n");
                    printf("Item's code: ");
                    fgets(item[j].code,sizeof(item[j].code), stdin);
                    item[j].code[strlen(item[j].code)-1]=0;
                    printf("Name: ");
                    fgets(item[j].name,sizeof(item[j].name), stdin);
                    item[j].name[strlen(item[j].name)-1]=0;
                    printf("Type: ");
                    fgets(item[j].type,sizeof(item[j].type), stdin);
                    item[j].type[strlen(item[j].type)-1]=0;
                    printf("Price: RM ");
                    scanf("%f", &price);
                    item[j].price = price;
                    printf("\nModify successfully! \n");
                }
                else if(confirm == 2)
                {
                    break;
                }
                else
                {
                    printf("No this options. \n");
                    break;
                }
             }
         }
         printf("\nDo you want to continue modify item? 1.yes   2.no \n");
         scanf("%d", &con);
     }while(con==1);
    //call write_menu function
    write_menu(item, i, "w");
}


//Function for display menu
void view_menu()
{
    //Declare variables
    struct menu item[100];
    int i=0, j, confirm, con;
    char hot_drinks[] = "hot drinks", cold_drinks[] = "cold drinks", sandwiches[] = "sandwiches", cakes[] = "cakes", snacks[] = "snacks";

     //Display
     printf("\t--------------------------------------------------\n");
     printf("\t                       Menu                  ");
     printf("\n\t--------------------------------------------------");
     printf("\n\t               == Hot Drinks ==                 ");
     printf("\n");
     printf("\n\tCode \tItem  \t\t\t\tPrice(RM) ");
     printf("\n");
     //call display_category function
     display_category(hot_drinks);
     printf("\n");
     printf("\n\t               == Cold Drinks ==                 ");
     printf("\n");
     printf("\n\tCode \tItem  \t\t\t\tPrice(RM) ");
     printf("\n ");
     //call display_category function
     display_category(cold_drinks);
     printf("\n");
     printf("\n\t              ==  Sandwiches ==                ");
     printf("\n");
     printf("\n\tCode \tItem  \t\t\t\tPrice(RM) ");
     printf("\n ");
     //call display_category function
     display_category(sandwiches);
     printf("\n");
     printf("\n\t             ==  Cakes & Pastries ==               ");
     printf("\n");
     printf("\n\tCode \tItem  \t\t\t\tPrice(RM) ");
     printf("\n ");
     //call display_category function
     display_category(cakes);
     printf("\n");
     printf("\n\t                == Snacks  ==              ");
     printf("\n");
     printf("\n\tCode \tItem  \t\t\t\tPrice(RM) ");
     printf("\n ");
     //call display_category function
     display_category(snacks);

}


//Function for display items in menu
void display_category(char* category)
{
    //Declare variables
    struct menu item[100];
    int i=0,j;
    //call read_menu function
    read_menu(item, &i);
    for(j=0;j<i;j++)
    {
        //If item[j].type match with category
        if(strcmp(item[j].type, category) == 0)
        {
            //Display item's details
            printf("\t%s\t%-20s\t\t%-30.2f\n",item[j].code, item[j].name, item[j].price);
        }
    }
}


//Function for admin to search customer order
void search_customer_order()
{
    //Declare variables
     int i=0, j, con;
     char id[30];
     struct order odr[100];
     read_order(odr, &i);
     //Loop for ask user whether to continue
     do
     {
         fflush(stdin);
         //Ask user input id
         printf("\nPlease enter customer id: ");
         fgets(id,sizeof(id), stdin);
         id[strlen(id)-1]=0;

         printf("\nBooking number          Item                   Qty    Total(RM) \n");
         printf("\n");
         for(j=0;j<i;j++)
         {
             //If odr[j].user_id match with id
            if(strcmp(odr[j].user_id, id) == 0)
            {
                //Display order details
                printf("\t%-10d\t%-20s\t%d\t%.2f\n", odr[j].booking_num, odr[j].item_name, odr[j].quantity, odr[j].amount);

            }
         }
         printf("\nDo you want to continue searching? 1.yes   2.no \n");
         scanf("%d", &con);
     }while(con==1);
}


//Function for delete menu
void delete_menu()
{
    //Declare variables
    struct menu item[100];
    char code[10];
    int i=0, j, k, x, confirm, con;
    float price;

    read_menu(item, &i);
    //Loop for ask user whether to continue
     do
     {
         fflush(stdin);
         //Ask user input code
         printf("\nPlease enter item's code for delete: \n");
         fgets(code,sizeof(code), stdin);
         code[strlen(code)-1]=0;
         for(j=0;j<i;j++)
         {
             //If item[j].code match with code
             if(strcmp(item[j].code, code) == 0)
             {
                 //Display item's details
                 printf("\nCode: %s",item[j].code);
                 printf("\nName: %s",item[j].name);
                 printf("\nType: %s",item[j].type);
                 printf("\nPrice: %.2f",item[j].price);
                 //Ask user to confirm
                 printf("\nIs this the item that you want to delete? 1.Yes  2.No\n");
                 scanf("%d",&confirm);
                 //If confirmed, delete item
                 if(confirm == 1)
                 {
                     //Loop to pass the value form position item[k+1] to item[k]
                     for(k=j;k<i-1;k++)
                     {
                         strcpy(item[k].code, item[k+1].code);
                         strcpy(item[k].name, item[k+1].name);
                         strcpy(item[k].type, item[k+1].type);
                         item[k].price = item[k+1].price;
                     }
                     printf("\nDelete successfully! \n");
                     i=i-1;
                 }
                 else if(confirm == 2)
                 {
                     break;
                 }
                 else
                 {
                     printf("No this options. \n");
                     break;
                 }
              }
         }
         printf("\nDo you want to continue delete item? 1.yes   2.no \n");
         scanf("%d", &con);
      }while(con==1);
      //call write_menu function
      write_menu(item, i, "w");
}


// Function for display order items
void display_order(struct order *odr, int k)
{
    //Declare variables
    int j;
    printf("\n Code\tItem\t\t\t\tQty\tPrice\t\tTotal\n");
    for(j=0;j<k;j++)
    {
        printf(" %s\t%-30s\t%d\t%.2f\t\t%-30.2f\n", odr[j].item_code, odr[j].item_name, odr[j].quantity, odr[j].price, odr[j].amount);
    }
}


//Function for admin receive payment from customer
void admin_payment(float total)
{
    //Declare variables
    float pay, change;
    //Display total
    printf("\nTotal: %.2f", total);
    //Ask user input pay
    printf("\nPay: ");
    scanf("%f",&pay);
    //Calculate change
    change = pay - total;
    //Display change
    printf("\nYour change: %.2f", change);
}


//Function for user input information to place order
void input_order(struct order *odr, struct menu *item, int i, int booking, char *id, float *total, int *k)
{
    //Declare variables
    int j, con, quantity, h=0;
    char item_num[30];
    do
    {
        fflush(stdin);
        //Ask user input item_num and quantity
        printf("\nPlease enter the item's number: ");
        fgets(item_num,sizeof(item_num), stdin);
        item_num[strlen(item_num)-1]=0;
        printf("Quantity: ");
        scanf("%d",&quantity);
        for(j=0;j<i;j++)
        {
            //If item[j].code match with item_num
            if(strcmp(item[j].code, item_num) == 0)
            {
                //assign value to odr
                odr[h].booking_num = booking;
                strcpy(odr[h].user_id, id);
                strcpy(odr[h].item_code, item[j].code);
                strcpy(odr[h].item_name, item[j].name);
                odr[h].quantity = quantity;
                odr[h].price = item[j].price;
                odr[h].amount = quantity * item[j].price;
                //calculate total
                *total = *total + odr[h].amount;
                h++;
            }
        }
        //Ask user whether to continue
        printf("\nContinue order? 1.yes  2.no \n");
        scanf("%d", &con);
    }while(con==1);
    //Ask user to check order
    printf("\nPlease check your order: \n");
    //call display_order function
    display_order(odr, h);
    *k = h;
}


//Function for admin help customer place order
void admin_order()
{
    //Declare variables
    struct user usr[100];
    struct menu item[100];
    struct order odr[100];
    char item_num[30], choice, id[30];
    int i=0, k=0, j, x=0, con, quantity, g=0, booking =100, del, h;
    float total=0, amount = 0, pay, change=0;
    //call read_user_data, read_menu, read_order, and view_manu function
    read_user_data(usr, &x);
    read_menu(item, &i);
    read_order(odr, &g);
    view_menu();
    //Assign value to booking
    booking = odr[g-1].booking_num +1;

    fflush(stdin);
    //Ask user to input id
    printf("\nPlease enter customer id: ");
    fgets(id,sizeof(id), stdin);
    id[strlen(id)-1]=0;
    for(j=0; j<x; j++)
    {
        //If id match with usr[j].id
        if (strcmp(id, usr[j].id) == 0)
        {
            //call input_order function
             input_order(odr, item, i, booking, id, &total, &k);
             //Ask user whether wants to delete item
             printf("\nDo you want to delete any items? 1.yes  2.no \n");
             scanf("%d", &del);
             //If confirmed, delete item
             if(del == 1)
             {
                 //call delete_order function
                 delete_order(odr, &total, k, booking);
                 k = k-1;
             }
             printf("\nYour order: \n");
             //call display_order function
             display_order(odr, k);
             //call write_order function
             write_order(odr, k, "a");
             //call admin_payment function
             admin_payment(total);
             printf("\n\nYour receipt:\n");
             //call print_receipt function
             print_receipt(total, odr, booking, k);
        }
    }
}

