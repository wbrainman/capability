#include "cap.h"

//boundingTest

int main (int argc, char** argv)
{
    cap_value_t cap = CAP_SYS_ADMIN;
    int res = cap_get_bound(cap);
    printf("in boudingTest: \n");
    printf("get bound cap for %d, result = %d\n", cap, res);
    return 0;
}
