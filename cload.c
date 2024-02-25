#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <err.h>

bool displayLoadingProgress(int durationInSeconds);

bool displayLoadingProgress(int durationInSeconds) {
    if(durationInSeconds < 0){
        errx(1, "Invalid duration: negative value provided");
        return false;
    }

    for (int i = 0; i <= 100; i++) {
        printf("%d%% ", i);
        fflush(stdout);
        usleep(10000 * durationInSeconds);
        if (i < 10)
            printf("\b\b\b");
        else if (i <= 99)
            printf("\b\b\b\b");
    }
    return true;
}

int main() {
    printf("Loading ");
    if(displayLoadingProgress(5))
        printf("\nLoading complete.");
    return 0;
}
