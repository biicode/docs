#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <drogon/wiringpi/wiringpi/wiringpi.h>
#include <drogon/wiringpi/wiringpi/softservo.h>

int main ()
{
    if (wiringPiSetup () == -1)
    {
        fprintf (stdout, "oops: %s\n", strerror (errno));
        return 1 ;
    }

    softServoSetup (0, 1, 2, 3, 4, 5, 6, 7) ;

    softServoWrite (0,  500);

    int range = 500;
    int vel = 10;

    for (;;){
        softServoWrite (0,  range);
        range += vel;
        if (range > 1250 || range < -250)
            vel = -vel;

        delay (10);
    }
}