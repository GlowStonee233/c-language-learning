#include <stdio.h>
struct Date 
{
    int year;
    int month;
    int day;
};
int isLeapYear(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int getDaysInMonth(int year, int month) 
{
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) -
    {
        return 29;
    }
    return daysInMonth[month - 1];
}
void nextDay(struct Date *d) 
{
    d->day++;
    if (d->day > getDaysInMonth(d->year, d->month)) 
    {
        d->day = 1;
        d->month++;
        if (d->month > 12) 
        {
            d->month = 1;
            d->year++;
        }
    }
}
int isEqual(struct Date d1, struct Date d2) 
{
    return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;
}

int main() 
{
    struct Date date1, date2;
    int days = 0;
    scanf("%d %d %d", &date1.year, &date1.month, &date1.day);
    scanf("%d %d %d", &date2.year, &date2.month, &date2.day);
    while (!isEqual(date1, date2)) 
    {
        nextDay(&date1);
        days++;
    }
    printf("%d\n", days);
    return 0;
}