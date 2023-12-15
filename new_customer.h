//Function for new customer register
void user_register()
{
    //Declare variable
    struct user usr;
    char cpassword_again[21];
    system("cls");

    //Ask user to input information and store information to struct usr
    fflush(stdin);
    printf("Enter your first name: ");
    fgets(usr.first, 30, stdin);
    usr.first[strlen(usr.first) -1] = 0;
    printf("Enter your last name: ");
    fgets(usr.last, 30, stdin);
    usr.last[strlen(usr.last) -1] = 0;
    printf("Enter your gender (m/f): \n");
    fgets(usr.gender, 5, stdin);
    usr.gender[strlen(usr.gender) -1] = 0;
    printf("Enter your phone no: ");
    fgets(usr.phone, 50, stdin);
    usr.phone[strlen(usr.phone) -1] = 0;
    printf("Enter your date of birth: \n");
    printf("Day: ");
    fgets(usr.day, 5, stdin);
    usr.day[strlen(usr.day) -1] = 0;
    printf("Month: ");
    fgets(usr.month, 5, stdin);
    usr.month[strlen(usr.month) -1] = 0;
    printf("Year: ");
    scanf("%d", &usr.year);
    usr.balance = 0.00;

    printf("\nThank you for your information.");
    //Copy string from usr.last to usr.id
    strcpy(usr.id,usr.last);
    //Combine usr.id with the first character in usr.first
    strncat(usr.id,usr.first,1);
    //Set usr.id to lower case
    strlwr(usr.id);
    //Combine usr.id with usr.month
    strcat(usr.id,usr.month);
    //Combine usr.id with usr.day
    strcat(usr.id,usr.day);
    printf("\nThis is your user id: %s", usr.id);

    //While loop to make sure password match with re-enter password
    while(1)
    {
        fflush(stdin);
        //Ask user input usr.pswd
        printf("\nEnter your password(6-20 characters): ");
        fgets(usr.pswd,21,stdin);
        usr.pswd[strlen(usr.pswd) -1] = 0;
        //Ask user input cpassword_again
        printf("Re-enter password: ");
        fgets(cpassword_again,21,stdin);
        cpassword_again[strlen(cpassword_again) -1] = 0;
        //If the length of usr.pswd is <6 or >20
		if (strlen(usr.pswd)<6 || strlen(usr.pswd)>20)
		{
			printf("Incorrect password (6-20 characters) \n");
			continue;
		}
		else
        {
            //If usr.pswd and cpassword_again not the same
            if (strcmp(usr.pswd,cpassword_again)!= 0)
            {
                printf("Password not match! \n");
                continue;
            }
            else
            {
                break;
            }
        }
    }

    printf("\nRegister success!\n");
    //Go back to main page when press enter key
    printf("\n\nPress enter key to back to main page\n");
    getch();
    system("cls");
    printf("\nGo back to main page\n");
    Sleep(1000);

    //Pointer to file
    FILE *f;
    //Open text file
    f = fopen("user.txt", "a");
    if(f==NULL)
    {
        printf("Could not create");
    }
     else
    {
        //Write information to text file
        fprintf(f, "%s,%s,%s,%s,%s,%s,%s,%d,%s,%.2f\n", usr.id, usr.first, usr.last, usr.gender, usr.phone, usr.day, usr.month, usr.year, usr.pswd, usr.balance);
    }
    //close file
    fclose(f);

}


