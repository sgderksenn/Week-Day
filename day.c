/* day.c
   CSC 111 - Fall 2019 - Assignment 3

 Sydney Derksen/27/09/19

 This program is designed to determine what weekday a given month/day/year occurs on
 (inputted by user), given that it is a valid date.

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    /* INPUT DATA */
    /* You may modify the values of each variable below, but DO NOT
       rename the variables, change their type or move the declarations. */

    int year = 2019;
    int month = 12;
    int day = 9;

    /* END OF INPUT DATA */
    /* Implement your solution below this line */
    /* (you may also add new functions above main() if needed) */

    if(year < 1){
        printf("Error: Invalid year\n");
        return 0;
    }else if(year > 10000){
        printf("Error: Invalid year\n");
        return 0;
    }else if(month < 1){
        printf("Error: Invalid month\n");
        return 0;
    }else if(month > 12){
        printf("Error: Invalid month\n");
        return 0;
    }else if(day < 1){
        printf("Error: Invalid day\n");
        return 0;
    }else if(month == 1){
        if(day > 31){
            printf("Error: Invalid day\n");
            return 0;
        }
    }else if(month == 2){
        if(year%4 != 0){
            //year is not a leap year
            if(day > 28){
                printf("Error: Invalid day\n");
                return 0;
            }
        }else if(year%100 != 0){
            //year is a leap year
            if(day > 29){
                printf("Error: Invalid day\n");
                return 0;
            }
        }else if(year%400 != 0){
            //year is not a leap year
            if(day > 28){
                printf("Error: Invalid day\n");
                return 0;
            }
        }else{
            //year is a leap year
           if(day > 29){
               printf("Error: Invalid day\n");
               return 0;
           }
        }
    }else if(month == 3){
        if(day > 31){
            printf("Error: Invalid day\n");
            return 0;
        }
    }else if(month == 4){
        if(day > 30){
            printf("Error: Invalid day\n");
            return 0;
        }
    }else if(month == 5){
        if(day > 31){
            printf("Error: Invalid day\n");
            return 0;
        }
    }else if(month == 6){
        if(day > 30){
            printf("Error: Invalid day\n");
            return 0;
        }
    }else if(month == 7){
        if(day > 31){
            printf("Error: Invalid day\n");
            return 0;
        }
    }else if(month == 8){
        if(day > 31){
            printf("Error: Invalid day\n");
            return 0;
        }
    }else if(month == 9){
        if(day > 30){
            printf("Error: Invalid day\n");
            return 0;
        }
    }else if(month == 10){
        if(day > 31){
            printf("Error: Invalid day\n");
            return 0;
        }
    }else if(month == 11){
        if(day > 30){
            printf("Error: Invalid day\n");
            return 0;
        }
    }else if(month ==12){
        if(day > 31){
            printf("Error: Invalid day\n");
            return 0;
        }
    }




    int running_total;

    //calculate last two digits of year
    running_total = year%100;

    //integer division by 4
    running_total = running_total/4;

    //add day of the month
    running_total = running_total + day;

    //add specified amount based on month
    if(month == 1){
        running_total = running_total + 1;
    }else if(month == 2){
        running_total = running_total + 4;
    }else if(month == 3){
        running_total = running_total + 4;
    }else if(month == 5){
        running_total = running_total + 2;
    }else if(month == 6){
        running_total = running_total + 5;
    }else if(month == 8){
        running_total = running_total + 3;
    }else if(month == 9){
        running_total = running_total + 6;
    }else if(month == 10){
        running_total = running_total + 1;
    }else if(month == 11){
        running_total = running_total + 4;
    }else if(month == 12){
        running_total = running_total + 6;
    }

    //determine if year is a leap year; if yes and month is 1 or 2 then subtract 1 form running total
    if(year%4 != 0){
        //year is not a leap year
    }else if(year%100 != 0){
        //year is a leap year
        if(month ==1){
            running_total = running_total - 1;
        }else if(month == 2){
            running_total = running_total - 1;
        }
    }else if(year%400 != 0){
        //year is not a leap year
    }else{
        //year is a leap year
        if(month ==1){
            running_total = running_total - 1;
        }else if(month == 2){
            running_total = running_total - 1;
        }
    }

   //determine total to subtract from running total
    int subtract_total;
    subtract_total = year/100;
    subtract_total = subtract_total%4;
    subtract_total = subtract_total*2;

    //subtract from running
    running_total = running_total - subtract_total;

    //compute last two digits of year and add to running total
    int year_notation;
    year_notation = year%100;
    running_total = running_total + year_notation;

    //add 12 to the running total
    running_total = running_total + 12;

    //get remainder of running total divided by seven to get day of week
    int week_day;
    week_day = running_total%7;

    //print out date and week day
    if(week_day == 0){
        printf("%d/%d/%d: Sunday\n", year, month, day);
    }else if(week_day == 1){
        printf("%d/%d/%d: Monday\n", year, month, day);
    }else if(week_day == 2){
        printf("%d/%d/%d: Tuesday\n", year, month, day);
    }else if(week_day == 3){
        printf("%d/%d/%d: Wednesday\n", year, month, day);
    }else if(week_day == 4){
        printf("%d/%d/%d: Thursday\n", year, month, day);
    }else if(week_day == 5){
        printf("%d/%d/%d: Friday\n", year, month, day);
    }else if(week_day == 6){
        printf("%d/%d/%d: Saturday\n", year, month, day);
    }


    return 0;
}

