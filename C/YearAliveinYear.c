#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm *time_info;
    double seconds;

    time(&current_time);
    time_info = localtime(&current_time);

    printf("Enter your birth date (mm/dd/yyyy): ");
    int month, day, year;
    scanf("%d/%d/%d", &month, &day, &year);

    time_t birth_time = timegm(time_info);
    time_info->tm_year = year - 1900;
    time_info->tm_mon = month - 1;
    time_info->tm_mday = day;
    birth_time = timegm(time_info);

    seconds = difftime(current_time, birth_time);
    int days = (int)(seconds / 86400);
    printf("You are %d days old.\n", days);

    return 0;
}
