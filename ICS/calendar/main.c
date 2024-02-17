#include <stdio.h>

int main() {
    printf("input a valid date as day/month/year: ");

    int day, month, year;
    int first_weekday_of_month, last_day_of_month;
    scanf("%d/%d/%d", &day, &month, &year);

    int ERROR = 0, LEAP = 0;

    /*

    prints the starting part of the template
    */
    printf("\n");
    printf("______________________________________________________________________________\n");

    /*

    month names are generated using
    `figlet -f cyberlarge`

    */

    /*

    this block of code checks if the inputted date is valid or not.
    and sets the last date of the month.
    */
    if(year > 0) {                                 // checks for non-zero value
        if(month > 0 && month <= 12 && day > 0) {  // check if the month is between 1-12
            // check if the day matches according to the month
            if(month == 1 && day <= 31) {
                last_day_of_month = 31;

                printf("         _____ _______ __   _ _     _ _______  ______ __   __\n");
                printf("           |   |_____| | \\  | |     | |_____| |_____/   \\_/\n");
                printf("         __|   |     | |  \\_| |_____| |     | |    \\_    |\n\n");
            } else if(month == 2) {
                // check if leap year
                if(year % 400 == 0)
                    LEAP = 1;
                else if(year % 100 == 0)
                    LEAP = 0;
                else if(year % 4 == 0)
                    LEAP = 1;
                else
                    LEAP = 0;

                if((LEAP == 1 && day <= 29) || (LEAP == 0 && day <= 28)) {
                    // sets the last day of the month based on leap year
                    if(LEAP == 1)
                        last_day_of_month = 29;
                    else
                        last_day_of_month = 28;

                    printf("       _______ _______ ______   ______ _     _ _______  ______ __   __\n");
                    printf("       |______ |______ |_____] |_____/ |     | |_____| |_____/   \\_/\n");
                    printf("       |       |______ |_____] |    \\_ |_____| |     | |    \\_    |\n\n");
                } else
                    ERROR = 1;
            } else if(month == 3 && day <= 31) {
                last_day_of_month = 31;

                printf("               _______ _______  ______ _______ _     _\n");
                printf("               |  |  | |_____| |_____/ |       |_____|\n");
                printf("               |  |  | |     | |    \\_ |_____  |     |\n\n");
            } else if(month == 4 && day <= 30) {
                last_day_of_month = 30;

                printf("                 _______  _____   ______ _____\n");
                printf("                 |_____| |_____] |_____/   |   |\n");
                printf("                 |     | |       |    \\_ __|__ |_____\n\n");
            } else if(month == 5 && day <= 31) {
                last_day_of_month = 31;

                printf("                       _______ _______ __   __\n");
                printf("                       |  |  | |_____|   \\_/\n");
                printf("                       |  |  | |     |    |\n\n");
            } else if(month == 6 && day <= 30) {
                last_day_of_month = 30;

                printf("                     _____ _     _ __   _ _______\n");
                printf("                       |   |     | | \\  | |______\n");
                printf("                     __|   |_____| |  \\_| |______\n\n");
            } else if(month == 7 && day <= 31) {
                last_day_of_month = 31;

                printf("                     _____ _     _        __   __\n");
                printf("                       |   |     | |        \\_/\n");
                printf("                     __|   |_____| |_____    |\n\n");
            } else if(month == 8 && day <= 31) {
                last_day_of_month = 31;

                printf("             _______ _     _  ______ _     _ _______ _______\n");
                printf("             |_____| |     | |  ____ |     | |______    |\n");
                printf("             |     | |_____| |_____| |_____| ______|    |\n\n");
            } else if(month == 9 && day <= 30) {
                last_day_of_month = 30;

                printf("    _______ _______  _____  _______ _______ _______ ______  _______  ______\n");
                printf("    |______ |______ |_____]    |    |______ |  |  | |_____] |______ |_____/\n");
                printf("    ______| |______ |          |    |______ |  |  | |_____] |______ |    \\_\n\n");
            } else if(month == 10 && day <= 31) {
                last_day_of_month = 31;

                printf("        _____  _______ _______  _____  ______  _______  ______\n");
                printf("       |     | |          |    |     | |_____] |______ |_____/\n");
                printf("       |_____| |_____     |    |_____| |_____] |______ |    \\_\n\n");
            } else if(month == 11 && day <= 30) {
                last_day_of_month = 30;

                printf("      __   _  _____  _    _ _______ _______ ______  _______  ______\n");
                printf("      | \\  | |     |  \\  /  |______ |  |  | |_____] |______ |_____/\n");
                printf("      |  \\_| |_____|   \\/   |______ |  |  | |_____] |______ |    \\_\n\n");
            } else if(month == 12 && day <= 31) {
                last_day_of_month = 31;

                printf("    ______  _______ _______ _______ _______ ______  _______  ______\n");
                printf("    |     \\ |______ |       |______ |  |  | |_____] |______ |_____/\n");
                printf("    |_____/ |______ |_____  |______ |  |  | |_____] |______ |    \\_\n\n");
            } else
                ERROR = 1;
        } else
            ERROR = 1;
    } else
        ERROR = 1;

    /*

    print if there is any error
    */
    if(ERROR == 1) {
        printf("\n");
        printf("ERROR: the date you inputted is wrong :(\n");
        printf("       please input a valid one.\n");
        printf("\n");
        printf("______________________________________________________________________________\n");

        return 1;  // exit with an error code 1
    }

    /*

    prints the year
    and a simple template
    */
    printf("                                 %d\n", year);
    printf("______________________________________________________________________________\n");
    printf("      Sun      Mon      Tue      Wed      Thu      Fri      Sat\n      ");

    /*

    calculate the weekday where
    0 = Sunday, 1 = Monday, 2 = Tuesday, 3 = Wednesday, 4 = Thursday, 5 = Friday, 6 = Saturday
    */
    int a, y, m, d;

    a                      = (14 - month) / 12;
    y                      = year - a;
    m                      = month + (12 * a) - 2;
    d                      = 1;
    first_weekday_of_month = (d + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

    // printf("----%d\n\n", first_weekday_of_month);

    /*

    prints space until it is time to print the days
    */
    int newline_tracker = first_weekday_of_month;
    for(int j = 0; j < newline_tracker; j++)
        printf("         ");

    /*

    prints everyday dates until the end of the month
    */
    for(int i = 1; i <= last_day_of_month; i++, newline_tracker++) {

        /*

        prints a newline before every sunday.
        and
        if the `newline_tracker` starts with 0,
        no need to print a new line.
        */
        if((newline_tracker % 7) == 0 && newline_tracker != 0)
            printf("\n      ");

        /*

        if `i` is the input date
        then print it with some flare
        */
        if(day == i)
            printf("[%2d]     ", i);
        else
            printf("%3d      ", i);
    }

    /*

    prints the end part of the template
    */
    printf("\n");
    printf("______________________________________________________________________________\n");
    printf("\n");

    return 0;
}
