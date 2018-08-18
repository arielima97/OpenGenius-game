/*
Name      : OpenGenius.ino
Author    : Ariel Lima Andrade
Version   : 1.0
Project   : OpenGenius DIY game
Revisions : None

Purpose   : Build the Genius game on Arduino using only some LEDs, pushbuttons and a buzzer.

Copyright © 2018 Ariel Andrade. All rights reserved.

*/

#include "Notes.h" //Contains the frequency of the notes  
#define time_song1 250 //Time between notes "game over" song
#define time_song2 120 //Time between notes "starting" song
#define SPEED 300   //Game speed

int b_green = 2;    //Green LED button
int b_red = 4;      //Red LED button
int b_blue = 7;     //Blue LED button
int b_yellow = 8;   //Yellow LED button

int led_green = 3;  //Green LED
int led_red = 5;    //Red LED
int led_blue = 6;   //Blue LED
int led_yellow = 9; //Yellow LED

int buzzer = 10;    //Buzzer
bool RST = 0;       //Reset the game
byte seq[100];      //Stored sequence - MÁX 100
byte nseq = 0;      //Sequence index

void setup() {                
    pinMode(b_green, INPUT);     
    pinMode(b_red, INPUT);
    pinMode(b_blue, INPUT);
    pinMode(b_yellow, INPUT); 

    pinMode(led_green, OUTPUT);     
    pinMode(led_red, OUTPUT);
    pinMode(led_blue, OUTPUT);
    pinMode(led_yellow, OUTPUT);
    pinMode(buzzer, OUTPUT);    
}

void loop() {
    sound('S',0); //"Start" song
    delay(2000); //Wait 2 seconds
    RST = 0; //Allows the game start
    nseq = 0; //Reset the sequence
    while(RST==0)
    {      
        seq_gen(); //Add one more note to the sequence
        delay(300); //Wait 300ms
        fading_led(1); //Blink the LEDs once
        delay(50); //Wait 50ms
        
        //----------Playing the sequence------------

        for (int i = 0; i < nseq; ++i)
        {
            switch (seq[i]) 
            {
                case 1:
                    sound('G',max(SPEED,200)); //Play the green note
                    break;
                case 2:
                    sound('R',max(SPEED,200)); //Play the red note
                    break;
                case 3:
                    sound('B',max(SPEED,200)); //Play the blue note
                    break;
                case 4:
                    sound('Y',max(SPEED,200)); //Play the yellow note
                    break;
                default:
                    noTone(buzzer);
            }
            delay(SPEED);
        }

        //------------------------------------------

        delay(1000); //Wait 1 second
        byte sw = 0; //Read note (1=G, 2=R, 3=B, 4=Y)
        for (int i = 0; i < nseq; ++i) //Checking sequence inserted by the user
        {
            //-------Waiting for a note pressed----------
            while(!sw)
            {
                byte sw_g = 1*digitalRead(b_green);
                byte sw_r = 2*digitalRead(b_red);
                byte sw_b = 3*digitalRead(b_blue);
                byte sw_y = 4*digitalRead(b_yellow);
                sw = max(sw_g,max(sw_r,max(sw_b,sw_y)));
            }
            //-------------------------------------------

            //----------Play the note pressed------------
            switch (sw) 
            {
                case 1:
                    sound('G',max(SPEED,200)); //Green note has been played
                    break;
                case 2:
                    sound('R',max(SPEED,200)); //Red note has been played
                    break;
                case 3:
                    sound('B',max(SPEED,200)); //Blue note has been played
                    break;
                case 4:
                    sound('Y',max(SPEED,200)); //Yellow note has been played
                    break;
                default:
                    noTone(buzzer);
            }
            //-------------------------------------------



            if (sw!=seq[i]) //Checking if the user missed a note
            {
                //------------------Turn all the LEDs on------------------------
                analogWrite(led_green, 255);   
                analogWrite(led_red, 255);
                analogWrite(led_blue, 255);
                analogWrite(led_yellow, 255);
                sound('F',0); //"Game over" song
                fading_led(5); //Blink the LEDs 5 times       
                RST = 1; //It'll make the while function stops
                break; //Stop the checking for loop, and go to restart the game
            }

            //----------Waiting for the user realeases the note----------
            while(sw)
            {
                byte sw_g = 1*digitalRead(b_green);
                byte sw_r = 2*digitalRead(b_red);
                byte sw_b = 3*digitalRead(b_blue);
                byte sw_y = 4*digitalRead(b_yellow);
                sw = max(sw_g,max(sw_r,max(sw_b,sw_y)));
            }
            //-----------------------------------------------------------

            delay(min(SPEED,100));
        }       
    }   
}


