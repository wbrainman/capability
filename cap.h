
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/prctl.h>
#include <unistd.h>
 
#undef _POSIX_SOURCE
#include <sys/capability.h>
#include "libcap-2.33/libcap/libcap.h"

#define CAP_MAX  36
static unsigned s_capFullNum = CAP_MAX;
static cap_value_t s_capFullList[CAP_MAX] = {
    CAP_CHOWN,
    CAP_DAC_OVERRIDE,
    CAP_DAC_READ_SEARCH,
    CAP_FOWNER,
    CAP_FSETID,
    CAP_KILL,
    CAP_SETGID,
    CAP_SETUID,
    CAP_SETPCAP,
    CAP_LINUX_IMMUTABLE,
    CAP_NET_BIND_SERVICE,
    CAP_NET_BROADCAST,
    CAP_NET_ADMIN,
    CAP_NET_RAW,
    CAP_IPC_LOCK,
    CAP_IPC_OWNER,
    CAP_SYS_MODULE,
    CAP_SYS_RAWIO,
    CAP_SYS_CHROOT,
    CAP_SYS_PTRACE,
    CAP_SYS_PACCT,
    CAP_SYS_ADMIN,
    CAP_SYS_BOOT,
    CAP_SYS_NICE,
    CAP_SYS_RESOURCE,
    CAP_SYS_TIME,
    CAP_SYS_TTY_CONFIG,
    CAP_MKNOD,
    CAP_LEASE,
    CAP_AUDIT_WRITE,
    CAP_AUDIT_CONTROL,
    CAP_SETFCAP,
    CAP_MAC_OVERRIDE,
    CAP_MAC_ADMIN,
    CAP_SYSLOG,
    CAP_WAKE_ALARM
    //CAP_BLOCK_SUSPEND,
    //CAP_AUDIT_READ
};

extern void showCapInHex(pid_t pid);
extern void showCap(pid_t pid);
extern void setCap(pid_t pid);
extern void showFileCap(char* pFile);
extern void setFileCap(char* pFile);
extern void clearFileCap(char* pFile);
extern void setProcessCap1(pid_t pid);
extern void setProcessCap2(pid_t pid);
