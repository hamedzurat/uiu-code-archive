#include <stdio.h>

// int mmm(int m, int c) {
//   int X = 0;
//   X = m / c;

//   printf("%d note(s) of %d\n", X, c);

//   return m % c;
// }

int main(void) {
    // printf("money: ");
    int money = 0;
    scanf("%d", &money);
    printf("input: %d\n", money);

    int amount_of_500 = 0;
    int amount_of_100 = 0;
    int amount_of_50  = 0;
    int amount_of_10  = 0;
    int amount_of_5   = 0;
    int amount_of_1   = 0;
    int reminders     = 0;

    amount_of_500 = money / 500;
    reminders     = money % 500;

    amount_of_100 = reminders / 100;
    reminders     = reminders % 100;

    amount_of_50 = reminders / 50;
    reminders    = reminders % 50;

    amount_of_10 = reminders / 10;
    reminders    = reminders % 10;

    amount_of_5 = reminders / 5;
    reminders   = reminders % 5;

    amount_of_1 = reminders;

    printf("%d note(s) of 500\n", amount_of_500);
    printf("%d note(s) of 100\n", amount_of_100);
    printf("%d note(s) of 50\n", amount_of_50);
    printf("%d note(s) of 10\n", amount_of_10);
    printf("%d note(s) of 5\n", amount_of_5);
    printf("%d note(s) of 1\n", amount_of_1);

    // mmm(mmm(mmm(mmm(mmm(mmm(money, 500), 100), 50), 10), 5), 1);

    return 0;
}
