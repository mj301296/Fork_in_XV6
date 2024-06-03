#include "types.h"
#include "user.h"

#define P_LOOP_CNT 0x01000000
#define C_LOOP_CNT 0x03000000

void do_parent(void)
{
    volatile int cnt = 0;
    volatile int tmp = 0;

    while (cnt < P_LOOP_CNT)
    {
        tmp += cnt;
        cnt++;
    }
}

void do_child(void)
{
    volatile int cnt = 0;
    volatile int tmp = 0;

    while (cnt < C_LOOP_CNT)
    {
        tmp += cnt;
        cnt++;
    }

    exit();
}

void example_test_code()
{
    int pid = 0;

    pid = fork();
    if (pid < 0)
    {
        printf(1, "fork() failed!\n");
        exit();
    }
    else if (pid == 0) // child
    {
        // sleep(100);
        do_child();
    }
    else // parent
    {
        do_parent();
        if (wait() < 0)
        {
            printf(1, "wait() failed!\n");
        }
    }

    printf(1, "\n");
}

int main(int argc, char *argv[])
{
    enable_sched_trace(1);

    /* ---------------- start: add your test code ------------------- */

    if (argc == 2)
    {
        if ((atoi(argv[1]) == 0) || (atoi(argv[1]) == 1))
            set_sched(atoi(argv[1]));
        else
        {
            printf(1, "Enter argument 0 for RoundRobin or 1 for Priority-based scheduling\n");
            enable_sched_trace(0);
            exit();
        }
    }
    else
    {
        printf(1, "Enter argument 0 for RoundRobin or 1 for Priority-based scheduling\n");
        enable_sched_trace(0);
        exit();
    }
    example_test_code();

    /* ---------------- end: add your test code ------------------- */

    enable_sched_trace(0);
    exit();
}
