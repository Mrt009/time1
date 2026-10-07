#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, mode;
    float loc[100], kloc;
    float effort[100], time[100];
    float persons[100], productivity[100];
    char modeName[100][20];

    float totalEffort = 0;
    float maxEffort = 0;
    int maxProject = 0;

    printf("Enter number of projects: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\n===== Project %d =====\n", i + 1);

        printf("Enter project size in LOC: ");
        scanf("%f", &loc[i]);

        kloc = loc[i] / 1000;

        printf("\nSelect Project Mode:\n");
        printf("1. Organic\n");
        printf("2. Semi-Detached\n");+
        printf("3. Embedded\n");
        printf("Enter choice: ");
        scanf("%d", &mode);

        if(mode == 1)
        {
            effort[i] = 2.4 * pow(kloc, 1.05);
            time[i] = 2.5 * pow(effort[i], 0.38);

            sprintf(modeName[i], "Organic");
        }
        else if(mode == 2)
        {
            effort[i] = 3.0 * pow(kloc, 1.12);
            time[i] = 2.5 * pow(effort[i], 0.35);

            sprintf(modeName[i], "Semi-Detached");
        }
        else if(mode == 3)
        {
            effort[i] = 3.6 * pow(kloc, 1.20);
            time[i] = 2.5 * pow(effort[i], 0.32);

            sprintf(modeName[i], "Embedded");
        }
        else
        {
            printf("Invalid choice! Enter project again.\n");
            i--;
            continue;
        }

        persons[i] = effort[i] / time[i];

        productivity[i] = loc[i] / effort[i];

        totalEffort = totalEffort + effort[i];

        if(effort[i] > maxEffort)
        {
            maxEffort = effort[i];
            maxProject = i;
        }
    }

    /* Display Results */

    printf("\n\n==================== PROJECT RESULTS ====================\n");

    printf("%-10s %-12s %-16s %-12s %-12s %-12s %-15s\n",
           "Project", "LOC", "Mode", "Effort", "Time",
           "Persons", "Productivity");

    printf("-------------------------------------------------------------------------------\n");

    for(i = 0; i < n; i++)
    {
        printf("%-10d %-12.0f %-16s %-12.2f %-12.2f %-12.2f %-15.2f\n",
               i + 1,
               loc[i],
               modeName[i],
               effort[i],
               time[i],
               persons[i],
               productivity[i]);
    }

    printf("\nTotal Effort = %.2f Person-Months\n", totalEffort);

    printf("Project with Maximum Effort = Project %d\n", maxProject + 1);

    printf("Maximum Effort = %.2f Person-Months\n", maxEffort);

    return 0;
}
