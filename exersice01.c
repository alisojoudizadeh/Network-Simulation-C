#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    srand(time(NULL));
    FILE *f = fopen("output.txt", "w");

    float arrival_random_digit_assignment[][2] = {{1, 125}, {126, 250}, {251, 375}, {376, 500}, {501, 625}, {626, 750}, {751, 875}, {876, 1000}};
    float service_random_digit_assignment[][2] = {{1, 10}, {11, 30}, {31, 60}, {61, 85}, {86, 95}, {96, 100}};

    fprintf(f, "A - Customer\n");
    fprintf(f, "B - Time Since Last Arrival (Minutes)\n");
    fprintf(f, "C - Arrival Time\n");
    fprintf(f, "D - Service Time (Minutes)\n");
    fprintf(f, "E - Time Service Begins\n");
    fprintf(f, "F - Time Customer Waits in Queue (Minutes)\n");
    fprintf(f, "G - Time Service Ends\n");
    fprintf(f, "H - Time Customer Spends in System (Minutes)\n");
    fprintf(f, "I - Idle Time of Server\n\n");

    fprintf(f, "A\tB\tC\tD\tE\tF\tG\tH\tI\n\n");

    int arrival_time = 0;
    int begins_time = 0;

    int arrival_list[20];
    int service_list[20];

    int last_service_end = 0;

    for (int i = 1; i <= 20; i++)
    {
        int arrival_index;
        int service_index;

        int arrival_digit = (rand() % 1000) + 1;
        int service_digit = (rand() % 100) + 1;

        for (arrival_index = 1; arrival_index <= sizeof(arrival_random_digit_assignment) / sizeof(float); arrival_index++)
        {
            if (arrival_digit >= arrival_random_digit_assignment[arrival_index - 1][0] && arrival_digit <= arrival_random_digit_assignment[arrival_index - 1][1])
            {
                break;
            }
        }

        for (service_index = 1; service_index <= sizeof(service_random_digit_assignment) / sizeof(float); service_index++)
        {
            if (service_digit >= service_random_digit_assignment[service_index - 1][0] && service_digit <= service_random_digit_assignment[service_index - 1][1])
            {
                break;
            }
        }

        if (i == 1)
        {
            arrival_index = 0;
        }
        arrival_time += arrival_index;

        arrival_list[i - 1] = arrival_time;
        service_list[i - 1] = service_index + arrival_time;

        int lse = last_service_end;

        fprintf(f, "%i\t", i);

        if (arrival_index == 0)
        {
            fprintf(f, "-\t");
        }
        else
        {
            fprintf(f, "%i\t", arrival_index);
        }

        fprintf(f, "%i\t", arrival_time);
        fprintf(f, "%i\t", service_index);

        if (i == 1)
        {
            fprintf(f, "0\t0\t");
            last_service_end = service_index;
        }
        else if (arrival_time < last_service_end)
        {
            fprintf(f, "%i\t", last_service_end);
            fprintf(f, "%i\t", last_service_end - arrival_time);
            last_service_end += service_index;
        }
        else
        {
            fprintf(f, "%i\t0\t", arrival_time);
            last_service_end = arrival_time + service_index;
        }

        fprintf(f, "%i\t", last_service_end);
        fprintf(f, "%i\t", last_service_end - arrival_time);
        fprintf(f, "%i\n", lse < arrival_time ? arrival_time - lse : 0);
    }
    fprintf(f, "\n");
}