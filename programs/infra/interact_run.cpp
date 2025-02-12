#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int fd1[2], fd2[2];

void closing() {
    close(fd1[0]);
    close(fd1[1]);
    close(fd2[0]);
    close(fd2[1]);
}

int main() {
    pipe(fd2);
    pipe(fd1);
    if (!fork()) {
        dup2(fd1[0], 0);
        dup2(fd2[1], 1);
        closing();
        execlp("./jury", "jury", NULL);
        exit(-1);
    }
    if (!fork()) {
        dup2(fd2[0], 0);
        dup2(fd1[1], 1);
        closing();
        execlp("./solve", "solve", NULL);
        exit(-1);
    }
    closing();
    wait(NULL);
    wait(NULL);
    return 0;
}
