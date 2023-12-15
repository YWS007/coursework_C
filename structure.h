//Structure for order
struct order
{
    char user_id[30], item_name[50], item_code[30];
    int quantity, booking_num;
    float price, amount;
};

//Structure for user
struct user
{
    char first[30], last[30], gender[5], id[30], pswd[30], phone[50], day[5], month[5];
    float balance;
    int year;
};

//Structure for menu
struct menu
{
    char code[10], name[50], type[50];
    float price;
};





