
// define the Stats structure here. See the tests to infer its properties
// define the Stats structure here. See the tests to infer its properties
typedef struct
{
        float average;
        float max;
        float min;
}Stats;

Stats compute_statistics(const float* numberset, int setlength);
// If the email Alert has been sent
bool emailAlertSent = FALSE;
// If the led has turned on
bool LedAlertOn = FALSE;
typedef void (*alerter_funcptr)();
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], Stats computedStats);
//Function for LedAlerter
void emailAlerter(void);
//Function for Email Alert sent
void ledAlerter(void);
