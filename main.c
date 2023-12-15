#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>
#include"structure.h"
#include"files.h"
#include"admin.h"
#include"title.h"
#include"new_customer.h"
#include"customer.h"


int main()
{
    int opt, user_id, x;
    opt = 1;
    while (opt != 0)
    {
        system("cls");
        welcomePage();
        printf("\n");
        printf("Please choose [0-3] numbers: ");
        scanf("%d", &opt);

        switch(opt)
        {
        case 1:
            x=admin_login();
            if(x == 0)
            {
                admin_opt();
                break;
            }
            else
            {
                break;
            }
        case 2:
            printf("login: ");
            user_id = user_login();
            customerOpt(user_id);
            break;

        case 3:
            user_register();
            break;

        case 0:
            system("cls");
            printf("Loading to exit....");
            Sleep(1000);
            fflush(stdin);
            system("cls");
            printf("You already exit from system! (Enter any key to close)\n");
            printf("\n\n\t Welcome again ^^!");
            exit(0);
            break;

        default:
            printf("Key in error, please key in again: ");
            getch();
        }
    }

    return 0;
}








