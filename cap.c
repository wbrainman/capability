#include "cap.h"
#include "sys/prctl.h"
  

void showCapInHex(pid_t pid)
{
     struct __user_cap_header_struct cap_header_data;
     cap_user_header_t cap_header = &cap_header_data;

     struct __user_cap_data_struct cap_data_data;
     cap_user_data_t cap_data = &cap_data_data;

     cap_header->pid = pid;
     cap_header->version = _LINUX_CAPABILITY_VERSION_1;

     if (capget(cap_header, cap_data) < 0) {
         perror("Failed capget");
         exit(1);
     }
     printf("pid %d, effective 0x%x, permitted 0x%x, inheritable 0x%x\n",
        pid,cap_data->effective, cap_data->permitted, cap_data->inheritable);

}

void showCap(pid_t pid)
{
    cap_t caps = cap_get_pid(pid);
    ssize_t y = 0;
    printf("The pid %d was give capabilities %s\n",pid, cap_to_text(caps, &y));
    fflush(0);
    cap_free(caps);
}

void setProcessCap1(pid_t pid)
{
    cap_t caps = cap_init();
    cap_value_t capList[1] ={CAP_SETPCAP};
    unsigned num_caps = 1;

    cap_set_flag(caps, CAP_EFFECTIVE, num_caps, capList, CAP_SET);
    cap_set_flag(caps, CAP_PERMITTED, num_caps, capList, CAP_SET);
    cap_set_flag(caps, CAP_INHERITABLE, num_caps, capList, CAP_SET);
    //cap_set_flag(caps, CAP_PERMITTED, s_capFullNum, s_capFullList, CAP_SET);
     
    if (cap_set_proc(caps)) {
        perror("capset()");
    }
    cap_free(caps);
}

void setProcessCap2(pid_t pid)
{
    cap_t caps = cap_init();
    cap_value_t capList[1] ={CAP_NET_ADMIN};
    unsigned num_caps = 1;

    //cap_set_flag(caps, CAP_EFFECTIVE, num_caps, capList, CAP_SET);
    //cap_set_flag(caps, CAP_PERMITTED, num_caps, capList, CAP_SET);
    cap_set_flag(caps, CAP_INHERITABLE, num_caps, capList, CAP_SET);
     
    if (cap_set_proc(caps)) {
        perror("capset()");
    }
    cap_free(caps);
}

void setCap(pid_t pid)
{
     struct __user_cap_header_struct cap_header_data;
     cap_user_header_t cap_header = &cap_header_data;

     struct __user_cap_data_struct cap_data_data;
     cap_user_data_t cap_data = &cap_data_data;

     cap_header->pid = pid;
     cap_header->version = _LINUX_CAPABILITY_VERSION_1;

     if (capget(cap_header, cap_data) < 0) {
         perror("Failed capget");
         exit(1);
     }

#if 1
    cap_data->permitted &= ~(1 << CAP_NET_ADMIN);
    //cap_data->effective &= ~(1 << CAP_NET_ADMIN);
    cap_data->effective = cap_data->permitted;
    cap_data->inheritable &= ~(1 << CAP_NET_ADMIN);
#endif
    printf("setCap pid %d, Cap data 0x%x, 0x%x, 0x%x\n", pid,cap_data->effective, cap_data->permitted, cap_data->inheritable);

     if (capset(cap_header, cap_data) < 0) {
         perror("Failed capset");
         exit(1);
     }
}

void showFileCap(char* pFile)
{
    if(!pFile) {
        printf("pFile is null"); 
        return;
    }

    cap_t caps = cap_get_file(pFile);
    ssize_t y = 0;
    printf("The file %s was give capabilities %s\n",pFile, cap_to_text(caps, &y));
    fflush(0);
    cap_free(caps);
}

void setFileCap(char* pFile)
{
    if(!pFile) {
        printf("pFile is null"); 
        return;
    }

    cap_t caps = cap_init();
    cap_value_t capList[2] ={ CAP_NET_ADMIN, CAP_SETPCAP} ;
    unsigned num_caps = 2;

    cap_set_flag(caps, CAP_EFFECTIVE, num_caps, capList, CAP_SET);
    cap_set_flag(caps, CAP_INHERITABLE, num_caps, capList, CAP_SET);
    cap_set_flag(caps, CAP_PERMITTED, num_caps, capList, CAP_SET);
     
    if (cap_set_file(pFile,caps)) {
        perror("capset()");
        return;
    }
    cap_free(caps);
}

void clearFileCap(char* pFile)
{
    if(!pFile) {
        printf("pFile is null"); 
        return;
    }

    cap_t caps = cap_init();
    cap_clear(caps);

     
    if (cap_set_file(pFile,caps)) {
        perror("capset()");
        return;
    }
    cap_free(caps);
}



