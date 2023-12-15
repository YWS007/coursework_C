void display_order(struct order *odr, int k);
void input_order(struct order *odr, struct menu *item, int i, int booking, char *id, float *total, int *k);

//Function for customer login
int user_login()
{
    //Pointer to file
    FILE* p1;
    //Declare variables
    int usrFound = 0, user_num;
    char username[30], pword[30];
    struct user usr[1000];
    int g=0;

    system("cls");
    fflush(stdin);
    printf("\n  **********************  CUSTOMER LOGIN  *************************\n  ");
    printf(" \n                         ID: ");
    fgets(username,30,stdin);
    username[strlen(username) -1] = 0;
    printf(" \n                      PASSWORD: ");
    fgets(pword,30,stdin);
    pword[strlen(pword) -1] = 0;

    //Open file to read
    p1 = fopen("user.txt","r");
    if(p1==NULL)
    {
        printf("File open Fail!\n");
    }
    else
    {
        //While loop until the end of the file
         while(!feof(p1))
        {
            //read data from file and save to struct user *usr
            fscanf(p1, "%29[^,],%29[^,],%29[^,],%4[^,],%49[^,],%4[^,],%4[^,],%d,%29[^,],%f\n", usr[g].id, usr[g].first, usr[g].last, usr[g].gender, usr[g].phone, usr[g].day, usr[g].month, &usr[g].year, usr[g].pswd, &usr[g].balance);
            //If usr[g].id match with username and usr[g].pswd match with pword
            if(strcmp(usr[g].id,username)==0 && strcmp(usr[g].pswd,pword)==0)
            {
                //display
                printf("Login!");
                system("cls");
                printf("\n\n\t\t\t Sign in to customer page....");
                Sleep(1000);
                //assign value to user_num
                user_num = g;
                break;
            }
            g++;
        }
        //Close file
        fclose(p1);
        //If usr[g].id not match with username or usr[g].pswd not match with pword
        if(strcmp(usr[g].id,username)!=0 || strcmp(usr[g].pswd,pword)!=0)
        {
            //display
            printf("\nLogin error!\n");
            printf("\nPlease try again.\n");
            Sleep(1000);
            //call user_login function, go back to the beginning of this function
            user_login();
        }
    }
    //return user_num value
    return user_num;
}


//Function for go back to customer page by pressing enter key
void back_customer_page()
{
    printf("\n\nPress enter key to back to customer page\n");
    getch();
    system("cls");
    printf("\nGo back to customer page\n");
    Sleep(1000);
}


//Function for customer chooses options
void customerOpt(int user_num)
{
    //Declare variables
    int opt=1;
    //Loop for user to access different tasks
    while(opt!=0)
    {
        system("cls");
        //call customerPage function
        customerPage();
        //Ask user input opt
        printf("\n\n\t\t\t Please choose [0-3] numbers: ");
        scanf("%d", &opt);
        system("cls");
        //switch for user choose option
        switch (opt)
        {
            case 1:
                //call view_menu function
                view_menu();
                //call back_customer_page function
                back_customer_page();
                break;
            case 2:
                //call customer_order function
                customer_order(user_num);
                //call back_customer_page function
                back_customer_page();
                break;
            case 3:
                //call modify_info function
                modify_info(user_num);
                //call back_customer_page function
                back_customer_page();
                break;
            case 0:
                //Exit customer page
                system("cls");
                printf("\n\n\t\t\t Sign out from customer page....");
                Sleep(1000);
                system("cls");
                return (0);
                break;
            default:
                printf("Key in error, please key in again: ");
                getch();
        }
    }
}


//Function for delete order
void delete_order(struct order *odr, float *total, int k, int booking)
{
    //Declare variables
    char item_num[30];
    int c, j;
    fflush(stdin);
    //Ask user input item_num
    printf("\nWhich item do you want to delete? \n");
    fgets(item_num,sizeof(item_num), stdin);
    item_num[strlen(item_num)-1]=0;
    for(j=0;j<k;j++)
    {
        //If odr[j].item_code match with item_num
        if(strcmp(odr[j].item_code, item_num) == 0)
        {
            //Calculate pointer total
            *total = *total - odr[j].amount;
            //Loop for passing value from odr[c+1] to odr[c]
            for (c=j;c<k-1;c++)
            {
                odr[c].booking_num = booking;
                strcpy(odr[c].user_id, odr[c+1].user_id);
                strcpy(odr[c].item_code, odr[c+1].item_code);
                strcpy(odr[c].item_name, odr[c+1].item_name);
                odr[c].quantity = odr[c+1].quantity;
                odr[c].price = odr[c+1].price;
                odr[c].amount = odr[c+1].amount;
            }
        }
    }
}


//Function for customer make payment
float make_payment(float total, struct user *usr, int user_num)
{
    //Declare variables
    int choose;
    float topup;
    printf("\n\nLets proceed to the payment!");
    //Loop for top-up wallet until the balance >= total
    while(usr[user_num].balance < total)
    {
        //Display usr[user_num].balance
        printf("\n\nWallet balance: RM %.2f", usr[user_num].balance);
        printf("\nInsufficient balance.");
        //Ask user input topup
        printf("\nPlease top-up: RM ");
        scanf("%f",&topup);
        //Calculate usr[user_num].balance
        usr[user_num].balance = topup + usr[user_num].balance;
    }
    //Display usr[user_num].balance
    printf("\nWallet balance: RM %.2f", usr[user_num].balance);
    printf("\nBalance is enough.");
    //Ask user whether wants to make payment now
    printf("\nMake payment now? 1. yes  2. no\n");
    scanf("%d",&choose);
    //If choose "yes"
    if(choose==1)
    {
       //Calculate usr[user_num].balance
       usr[user_num].balance = usr[user_num].balance-total;
       printf("\n\nPayment successful.");
       //Display usr[user_num].balance
       printf("\nWallet balance: RM %.2f ", usr[user_num].balance);
    }
    else
    {
       printf("\nPayment failed.");
       printf("\nYour orders will be added to cart.");
    }
    // return value of usr[user_num].balance
    return usr[user_num].balance;
}


//Function for display receipt
void print_receipt(float total, struct order *odr, int booking, int k)
{
    //Declare variables
    int j;
    time_t t;
    time(&t);
    //Display
    printf("\n*******************************************************");
     printf("\n                  DOSTA COFFEE SHOP          ");
    printf("\n*******************************************************");
    printf("\n Bill No: %d                   %s", booking, ctime(&t));
    printf("\n-------------------------------------------------------");
    printf("\n Items \t\t\t\tQty  \tTotal(RM) ");
    printf("\n-------------------------------------------------------\n");
    //Loop for display order details
    for(j=0;j<k;j++)
    {
        printf(" %-30s%d\t%.2f\n", odr[j].item_name, odr[j].quantity, odr[j].amount);
    }
    printf("\n-------------------------------------------------------");
    //Display total
    printf("\n Total: RM %.2f", total);
    printf("\n\nThank you for your purchase.\n");
}


//Function for customer place order
void customer_order(int user_num)
{
    //Declare variables
    struct user usr[100];
    struct menu item[100];
    struct order odr[100];
    char item_num[30], choice;
    int i=0, k=0, j, x=0, con, quantity, g=0, booking =100, del;
    float total=0, amount = 0;
    //call read_user_data, read_menu, read_order, and view_manu function
    read_user_data(usr, &x);
    read_menu(item, &i);
    read_order(odr, &g);
    view_menu();
    //Assign value to booking
    booking = odr[g-1].booking_num +1;
    //Call input_order function
    input_order(odr, item, i, booking, usr[user_num].id, &total, &k);
     //Ask user whether wants to delete item
     printf("\nDo you want to delete any items? 1.yes  2.no \n");
     scanf("%d", &del);
     //If confirmed, delete item
     if(del == 1)
     {
         //call delete_order function
         delete_order(odr, &total, k, booking);
         k=k-1;
     }
     printf("\nYour order: \n");
     //call display_order function
     display_order(odr, k);
     //call write_order function
     write_order(odr, k, "a");
     printf("\nTotal: RM %.2f", total);
     //call make_payment function
     usr[user_num].balance = make_payment(total, usr, user_num);
     printf("\nYour receipt: \n");
     //call print_receipt function
     print_receipt(total, odr, booking, k);
     //call write_user_data function
     write_user_data(usr, x, "w");
}


//Function for customer modify personal information
void modify_info(int user_num)
{
    //Declare variables
    struct user usr[100];
    int i=0, con, choose;
    //call read_user_data function
    read_user_data(usr, &i);
    //Loop for ask user whether to continue
     do
     {
         //Ask user input choose
         printf("\nWhich information do you want to modify? \n");
         printf("1. Password\n");
         printf("2. Name\n");
         printf("3. Phone\n");
         scanf("%d",&choose);
         //Switch for user choose items that he or she wants to modify
         switch(choose)
         {
            case 1:
                fflush(stdin);
                //Ask user input usr[user_num].pswd
                printf("Enter new password: \n");
                fgets(usr[user_num].pswd,sizeof(usr[user_num].pswd), stdin);
                usr[user_num].pswd[strlen(usr[user_num].pswd)-1]=0;
                break;
            case 2:
                fflush(stdin);
                //Ask user input usr[user_num].last
                printf("Enter new last name: \n");
                fgets(usr[user_num].last,sizeof(usr[user_num].last), stdin);
                usr[user_num].last[strlen(usr[user_num].last)-1]=0;
                //Ask user input usr[user_num].first
                printf("Enter new first name: \n");
                fgets(usr[user_num].first,sizeof(usr[user_num].first), stdin);
                usr[user_num].first[strlen(usr[user_num].first)-1]=0;
                break;
            case 3:
                fflush(stdin);
                //Ask user input usr[user_num].phone
                printf("Enter new phone number: \n");
                fgets(usr[user_num].phone,sizeof(usr[user_num].phone), stdin);
                usr[user_num].phone[strlen(usr[user_num].phone)-1]=0;
                break;
         }
         printf("\nContinue modify? 1.yes   2.no \n");
         scanf("%d", &con);
     }while(con==1);
     //call write_user_data function
    write_user_data(usr, i, "w");
}






