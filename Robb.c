#include "cap.h"
#include "setEther.h"


int main (int argc, char** argv)
{
    printf("in Robb\n");

    char *pFile = "./main";

    setFileCap(pFile);
    showFileCap(pFile);
    
    pFile = "./Arya";
    setFileCap(pFile);
    showFileCap(pFile);

    return 0;
}
