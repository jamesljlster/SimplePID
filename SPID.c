#include <string.h>

#include <SPID.h>

int SPID_ZeroMemory(SPID* sPIDPtr)
{
    memset((void*)sPIDPtr, 0, sizeof(struct _SPID));

    return 0;
}

int SPID_SetWeight(SPID* sPIDPtr, double weightOfP, double weightOfI, double weightOfD)
{
    sPIDPtr->weightOfP = weightOfP;
    sPIDPtr->weightOfI = weightOfI;
    sPIDPtr->weightOfD = weightOfD;

    return 0;
}

extern double SPID_Control(SPID* sPIDPtr, double desireOutput)
{
    double calcTmp;
    double outputOfP, outputOfI, outputOfD;

    // Calculate error
    sPIDPtr->error = output - desireOutput;

    // Calculate partial output of P
    outputOfP = sPIDPtr->weightOfP * sPIDPtr->error;

    // Calculate partial output of  I
    sPIDPtr->errIntegral += sPIDPtr->error;
    outputOfI = sPIDPtr->weightOfI * sPIDPtr->errIntegral;

    // Calculate partial output of  D
    outputOfD = sPIDPtr->weightOfD * (sPIDPtr->error - sPIDPtr->preError);
    sPIDPtr->preError = sPIDPtr->error;

    // Calculate Output
    calcTmp = outputOfP + outputOfI + outputOfD;

    return calcTmp;
}

int SPID_ClearError(SPID* sPIDPtr)
{
    sPIDPtr->currentErr = 0;
    sPIDPtr->errIntegral = 0;

    return 0;
}
