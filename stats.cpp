#include "stats.h"
#include <cmath>

EmailAlertSent Emailsent;
LedAlertSent LedOn;

Stats compute_statistics(const float* numberset, int setlength) {
    Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    int i = 0;
    float sum = 0.0;
    if(numberset == NULL)
    {
        s.average = NAN;
        s.min = NAN;
        s.max = NAN;
        return s;
    }

    if(0 == setlength%2)
    {
            if(numberset[0] > numberset[1])
            {
                s.max = numberset[0];
                s.min = numberset[1];
            }
            else
            {
                s.max = numberset[1];
                s.min = numberset[0];
            }
    }
    else
    {
        s.max = numberset[0];
        s.min = numberset[0];
        i=1;
    }

    while( i < (setlength-1))
    {
        if(numberset[i] > numberset[i+1])
        {
                if(numberset[i] > s.max)
                {
                   s.max = numberset[i];
                }
                if(numberset[i+1] < s.min)
                {
                   s.min = numberset[i+1];
                }
        }
        else
        {
                if(numberset[i+1] > s.max)
                {
                   s.max = numberset[i+1];
                }
                if(numberset[i] < s.min)
                {
                  s.min = numberset[i];
                }
        }
        i+=2;
    }

    for(i=0; i<setlength; i++)
    {
            sum += numberset[i];

    }
    s.average = sum/(float)setlength;
    return s;
}

//Turning the LED on
void emailAlerter(void)
{
    printf("inside 1\n");
   Emailsent.emailAlertSent = true;
}

// Email alert sent
void ledAlerter(void)
{
    printf("inside 2\n");
    LedOn.ledAlertOn = true;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], Stats computedStats)
{
    int i=0;
    bool result = false;
    alerters[0] = emailAlerter;
    alerters[1] = ledAlerter;
    if(computedStats.max > maxThreshold)
    {
        printf("inside max threshold\n");
        for(i=0; i<=2; i++)
        {
            (&alerters[i]);
        }
    }
}
