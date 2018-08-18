/*
Name      : Sound.ino
Author    : Ariel Lima Andrade
Version   : 1.0
Project   : OpenGenius DIY game
Revisions : None

Purpose   : Configuring and making the "starting" and "game over" songs.

Copyright © 2018 Ariel Andrade. All rights reserved.

*/

void sound(char x, int tpn)
{
    switch (x) 
    {
        case 'G': //Green LED (C4)
            digitalWrite(led_green, 1);
            tone(buzzer, nC5, tpn);
            delay(tpn);
            digitalWrite(led_green, 0);
            break;
        case 'R': //Red LED (E4)
            digitalWrite(led_red, 1);
            tone(buzzer, nE5, tpn);
            delay(tpn);
            digitalWrite(led_red, 0);
            break;
        case 'B': //Blue LED (G4) 
            digitalWrite(led_blue, 1);
            tone(buzzer, nG5, tpn);
            delay(tpn);
            digitalWrite(led_blue, 0);
            break;
        case 'Y': //Yellow LED (C5)
            digitalWrite(led_yellow, 1);
            tone(buzzer, nC6, tpn);
            delay(tpn);
            digitalWrite(led_yellow, 0);
            break;
        case 'F': //Game over
            noTone(buzzer);
            tone(buzzer, nC7, time_song1);
            delay(time_song1);
            tone(buzzer, nB6, time_song1);
            delay(time_song1);
            tone(buzzer, nAS5, time_song1);
            delay(time_song1);
            tone(buzzer, nA5, 2*time_song1);
            delay(2*time_song1);
            break;
        case 'S': //Starting system
            noTone(buzzer);
            tone(buzzer, nC5, time_song2);
            digitalWrite(led_green, 1);
            delay(time_song2);
            tone(buzzer, nD5, time_song2);
            digitalWrite(led_green, 0);
            digitalWrite(led_red, 1);
            delay(time_song2);
            tone(buzzer, nE5, time_song2);
            digitalWrite(led_red, 0);
            digitalWrite(led_blue, 1);
            delay(time_song2);
            tone(buzzer, nC7, 2*time_song2);
            digitalWrite(led_blue, 0);
            digitalWrite(led_yellow, 1);
            delay(2*time_song2);
            digitalWrite(led_yellow, 0);
            break;
        default:
            noTone(buzzer);
    }
}
