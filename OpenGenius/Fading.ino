/*
Name      : Fading.ino
Author    : Ariel Lima Andrade
Version   : 1.0
Project   : OpenGenius DIY game
Revisions : None

Purpose   : Blinking the LEDs n times, fading in and out.

Copyright © 2018 Ariel Andrade. All rights reserved.

*/

void fading_led(int n)
{    
 
    for (int j = 0; j < n; ++j)
        {
            for (int i = 0; i < 255; ++i)
            {
                analogWrite(led_green, i);
                analogWrite(led_red, i);
                analogWrite(led_blue, i);
                analogWrite(led_yellow, i);
                delay(1);
            }
            for (int i = 0; i < 255; ++i)
            {
                analogWrite(led_green, 255-i);
                analogWrite(led_red, 255-i);
                analogWrite(led_blue, 255-i);
                analogWrite(led_yellow, 255-i);
                delay(2);
            }
        }
    analogWrite(led_green, 0);
    analogWrite(led_red, 0);
    analogWrite(led_blue, 0);
    analogWrite(led_yellow, 0);
}
