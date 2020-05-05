#include "cap.h"
#include "setEther.h"
#include <unistd.h>
#include "sys/prctl.h"

#if 0

int main()
{
    pid_t pid;
    pid = fork();
    int ret = 0;

    if(pid == 0) {
        printf("in child pid = %d, child pid = %d, uid = %d, gid = %d\n", getpid(), pid, getuid(), getgid());
        showCap(getpid());
        char* pFile = "./main";
        showFileCap(pFile);
#if 0
        showCap(getpid());
        ret = prctl(PR_SET_KEEPCAPS, 1);
        if (ret) {
            perror("prctl");
            return -1;
       }
        showCap(getpid());
        clearFileCap(pFile);
        setFileCap(pFile);
        showFileCap(pFile);
        setgid(1000);
        setuid(1000);
        execve("./test", NULL, NULL);
#endif
        pause();


    }
    else {
        printf("in father pid = %d, child pid = %d, uid = %d, gid = %d\n", getpid(), pid, getuid(), getgid());
        showCap(getpid());
    
    }

    return 0;
}
#endif

// mian.c
#if 0
int main()
{
    printf("pid = %d, id = %d, gid = %d\n", getpid(), getuid(), getgid());
    //showCapInHex(getpid());
    //showCap(getpid());
    //setProcessCap(getpid());
    showCap(getpid());
    showFileCap("./test");
    execve("./test", NULL, NULL);
    pause();
    return 0;
}
#endif

#if 0
int main()
{
    printf("pid = %d, id = %d, gid = %d\n", getpid(), getuid(), getgid());
    cap_value_t cap = CAP_SYS_ADMIN;
    int res = cap_get_bound(cap);
    printf("get bound cap for %d, result = %d\n", cap, res);
    if (-1 == cap_drop_bound(cap)) {
        perror("set bound: ");
    }
    res = cap_get_bound(cap);
    printf("get bound cap for %d, result = %d\n", cap, res);

    pid_t pid;
    pid = fork();
    if(pid == 0) {
        printf("clild get bound cap for %d, result = %d\n", cap, res);
        execve("./boundingTest", NULL, NULL);
    }

    return 0;
}
#endif

#if 1
int main()
{
    uid_t ruid, euid, suid;
    showCap(getpid());

    if(0 > setreuid(0, 1000)) {
        perror("setreuid : ");
    }

    if(0 > getresuid(&ruid, &euid, &suid)) {
        perror("setreuid : ");
        return 0;
    }

    printf("ruid = %d, euid = %d, suid = %d\n", ruid, euid, suid);
    showCap(getpid());

    return 0;
}
#endif

#if 0
int main()
{
    showCap(getpid());

    cap_value_t cap = CAP_NET_ADMIN;
    int res = cap_get_bound(cap);
    printf("get bound cap for %d, result = %d\n", cap, res);
    if (-1 == cap_drop_bound(cap)) {
        perror("set bound: ");
    }
    res = cap_get_bound(cap);
    printf("get bound cap for %d, result = %d\n", cap, res);

    showCap(getpid());

    setProcessCap2(getpid());
    showCap(getpid());

    execve("./Arya", NULL, NULL);

    return 0;
}
#endif
