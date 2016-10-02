#ifndef SPID_H_INCLUDED
#define SPID_H_INCLUDED

struct _SPID
{
    double weightOfP;
    double weightOfI;
    double weightOfD;

    double error;
    double preError;
    double errIntegral;
};

typedef struct _SPID SPID;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

extern double SPID_Control(SPID* sPIDPtr, double desireOutput, double realOutput);

extern int SPID_ZeroMemory(SPID* sPIDPtr);

extern int SPID_SetWeight(SPID* sPIDPtr, double weightOfP, double weightOfI, double weightOfD);

extern int SPID_ClearError(SPID* sPIDPtr);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // SPID_H_INCLUDED
