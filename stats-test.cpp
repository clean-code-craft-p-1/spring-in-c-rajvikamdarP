#include "stats.h"

#include "gtest/gtest.h"
#include <stdlib.h>
#include <math.h>

TEST(Statistics, ReportsAverageMinMax) {
    float numberset[] = {1.5, 8.9, 3.2, 4.5};
    int setlength = sizeof(numberset) / sizeof(numberset[0]);
    Stats computedStats = compute_statistics(numberset, setlength);
    float epsilon = 0.001;
    EXPECT_LT(abs(computedStats.average - 4.525), epsilon);
    EXPECT_LT(abs(computedStats.max - 8.9), epsilon);
    EXPECT_LT(abs(computedStats.min - 1.5), epsilon);
}


TEST(Statistics, AverageNaNForEmpty) {
    Stats computedStats = compute_statistics(0, 0);
    //All fields of computedStats (average, max, min) must be
    //NAN (not-a-number), as defined in math.h
    
    //Design the EXPECT statement here.
    //Use https://stackoverflow.com/questions/1923837/how-to-use-nan-and-inf-in-c
}

TEST(Alert, AlertsWhenMaxExceeds) {
    alerter_funcptr alerters[] = {emailAlerter, ledAlerter};
    
    float numberset[] = {99.8, 34.2, 4.5};
    int setlength = sizeof(numberset) / sizeof(numberset[0]);
    Stats computedStats = compute_statistics(numberset, setlength);

    const float maxThreshold = 10.2;
    check_and_alert(maxThreshold, alerters, computedStats);
    
    EXPECT_EQ(true, EmailAlertSent.emailAlertSent);
    EXPECT_EQ(true, LedAlertSent.ledAlertOn);
}
