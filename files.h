//Function read user information
void read_user_data(struct user *usr, int *x)
{
   int i=0;
   //Pointer to file
   FILE *f;
   //Open text file to read
   f = fopen("user.txt", "r");
    if(f==NULL)
    {
        printf("Could not create");
    }
     else
     {
         //While loop until the end of the file
         while (!feof(f))
         {
             //read data from file and save to struct user *usr
             fscanf(f,"%29[^,],%29[^,],%29[^,],%4[^,],%49[^,],%4[^,],%4[^,],%d,%29[^,],%f\n", usr[i].id, usr[i].first, usr[i].last, usr[i].gender, usr[i].phone, usr[i].day, usr[i].month, &usr[i].year, usr[i].pswd, &usr[i].balance);
             i++;
         }
         //Close file
         fclose(f);
         *x = i;
     }
}

//Function read menu
void read_menu(struct menu *item, int *x)
{
   int i=0;
   //Pointer to file
   FILE *f;
   //Open text file to read
   f = fopen("menu.txt", "r");
    if(f==NULL)
    {
        printf("Could not create");
    }
     else
     {
         //While loop until the end of the file
         while (!feof(f))
         {
             //read data from file and save to struct menu *item
             fscanf(f,"%9[^,],%49[^,],%49[^,],%f\n", item[i].code, item[i].name, item[i].type, &item[i].price);
             i++;
         }
         //Close file
         fclose(f);
         *x = i;
     }
}

//Function read order
void read_order(struct order *odr, int *x)
{
   int i=0;
   //Pointer to file
   FILE *f;
   //Open text file to read
   f = fopen("order.txt", "r");
    if(f==NULL)
    {
        printf("Could not create");
    }
     else
     {
         //While loop until the end of the file
         while (!feof(f))
         {
             //read data from file and save to struct order *odr
             fscanf(f,"%d,%29[^,],%29[^,],%49[^,],%d,%f,%f\n", &odr[i].booking_num, odr[i].user_id, odr[i].item_code, odr[i].item_name, &odr[i].quantity, &odr[i].price, &odr[i].amount);
             i++;
         }
         //Close file
         fclose(f);
         *x = i;
     }
}

//Function write order to text file
void write_order(struct order *odr, int x, char *type)
{
    int j;
    //Pointer to file
    FILE *f;
    //Open text file to write or append
    f = fopen("order.txt", type);
    if(f==NULL)
    {
        printf("Could not create");
    }
     else
    {
        //For loop to write all data in struct order *odr to text file
        for(j=0;j<x;j++)
        {
            fprintf(f, "%d,%s,%s,%s,%d,%.2f,%.2f\n", odr[j].booking_num, odr[j].user_id, odr[j].item_code, odr[j].item_name, odr[j].quantity, odr[j].price, odr[j].amount);
        }
    }
    //Close file
    fclose(f);
}


//Function write user information to text file
void write_user_data(struct user *usr, int x, char *type)
{
    int j;
    //Pointer to file
    FILE *f;
    //Open text file to write or append
    f = fopen("user.txt", type);
    if(f==NULL)
    {
        printf("Could not create");
    }
     else
    {
        //For loop to write all data in struct order *odr to text file
        for(j=0;j<x;j++)
        {
            fprintf(f, "%s,%s,%s,%s,%s,%s,%s,%d,%s,%.2f\n", usr[j].id, usr[j].first, usr[j].last, usr[j].gender, usr[j].phone, usr[j].day, usr[j].month, usr[j].year, usr[j].pswd, usr[j].balance);
        }
    }
    //Close file
    fclose(f);
}

//Function write menu to text file
void write_menu(struct menu *item, int x, char *type)
{
    int j;
    //Pointer to file
    FILE *f;
    //Open text file to write or append
    f = fopen("menu.txt", type);
    if(f==NULL)
    {
        printf("Could not create");
    }
     else
    {
        //For loop to write all data in struct order *odr to text file
        for(j=0;j<x;j++)
        {
            fprintf(f,"%s,%s,%s,%.2f\n",item[j].code, item[j].name, item[j].type, item[j].price);
        }
    }
    //Close file
    fclose(f);
}


