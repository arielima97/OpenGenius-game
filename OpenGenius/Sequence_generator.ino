/*
Name      : Sequence_generator.ino
Author    : Ariel Lima Andrade
Version   : 1.0
Project   : OpenGenius DIY game
Revisions : None

Purpose   : Generating the next note to be played by the user.

Copyright © 2018 Ariel Andrade. All rights reserved.

*/

void seq_gen()
{
    seq[nseq] = random(1,5); //Add a new note to the sequence randomly
    nseq++; 
}
