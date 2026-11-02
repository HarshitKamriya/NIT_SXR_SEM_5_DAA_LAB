#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int deadline;
    int profit;
} Job;

int compare_jobs(const void *first, const void *second) {
    const Job *job_a = first;
    const Job *job_b = second;

    if (job_a->profit < job_b->profit) return 1;
    if (job_a->profit > job_b->profit) return -1;
    return 0;
}

int main(void) {
    int n;

    printf("Enter the number of jobs: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of jobs.\n");
        return 1;
    }

    Job *jobs = malloc((size_t)n * sizeof(*jobs));
    int *schedule = calloc((size_t)n, sizeof(*schedule));
    if (jobs == NULL || schedule == NULL) {
        printf("Unable to allocate memory.\n");
        free(jobs);
        free(schedule);
        return 1;
    }

    printf("Enter deadline and profit for each job:\n");
    for (int i = 0; i < n; i++) {
        jobs[i].id = i + 1;
        if (scanf("%d %d", &jobs[i].deadline, &jobs[i].profit) != 2) {
            printf("Invalid job data.\n");
            free(jobs);
            free(schedule);
            return 1;
        }
    }

    qsort(jobs, (size_t)n, sizeof(*jobs), compare_jobs);

    int total_profit = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline <= 0 || jobs[i].profit <= 0) {
            continue;
        }

        int last_slot = jobs[i].deadline < n ? jobs[i].deadline : n;
        for (int slot = last_slot - 1; slot >= 0; slot--) {
            if (schedule[slot] == 0) {
                schedule[slot] = jobs[i].id;
                total_profit += jobs[i].profit;
                break;
            }
        }
    }

    printf("\nScheduled jobs:\n");
    for (int slot = 0; slot < n; slot++) {
        if (schedule[slot] != 0) {
            printf("Slot %d: Job %d\n", slot + 1, schedule[slot]);
        }
    }
    printf("Maximum profit: %d\n", total_profit);

    free(jobs);
    free(schedule);
    return 0;
}