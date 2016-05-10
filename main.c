#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "SPID.h"

#define DESIRE_OUTPUT   10.0
#define KP  -0.8
#define KI  -0.4
#define KD  0.31

int main()
{
    char kbin = -1;

    SPID sPID;

    double output = 8;

    // Initialize: Zero Memory
    SPID_ZeroMemory(&sPID);

    // Set PID Weight
    SPID_SetWeight(&sPID, KP, KI, KD);

    // Controlling
    while(kbin != 27)
    {
        output = SPID_Control(&sPID, DESIRE_OUTPUT, output);
        printf("output = %lf, press ESC to exit...\n", output);

        kbin = getch();
    }

    return 0;
}
