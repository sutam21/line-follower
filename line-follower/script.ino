/*
* Robot pengikut garis (line follower)
* Pin 10 dan 11 adalah input sensor garis
* Pin 2 dan 3 untuk drive motor kiri
* Pin 4 dan 5 untuk drive motor kanan
* Pin 6 dan 7 untuk speed control motor
* dibuat oleh Rafli Setiawan
* SMK N 1 KEJOBONG
*/

#define motorkif 2 //motor kiri maju
#define motorkib 3 //motor kiri mundur
#define motorkaf 4 //motor kanan maju
#define motorkab 5 //motor kanan mundur
#define enA 6
#define enB 7
int motorSpeedA=0;
int motorSpeedB=0;

void setup() {
//Menentukan mode untuk masing-masing pin
pinMode(motorkif,OUTPUT);
pinMode(motorkib,OUTPUT);
pinMode(enA,OUTPUT);
pinMode(motorkaf,OUTPUT);
pinMode(motorkab,OUTPUT);
pinMode(enB,OUTPUT);
pinMode(10,INPUT);
pinMode(11,INPUT);
}

void loop() {
int sensorki=digitalRead(7); //baca sensor kiri
int sensorka=digitalRead(8); //baca sensor kanan
if((sensorki==LOW) && (sensorka==LOW))
{
//kedua sensor tidak mengenai garis hitam
//gerak maju
motorSpeedA=255;
motorSpeedB=255;
analogWrite(enA,motorSpeedA);
analogWrite(enB,motorSpeedB); 
digitalWrite(motorkaf,HIGH);
digitalWrite(motorkab,LOW);
digitalWrite(motorkif,HIGH);
digitalWrite(motorkib,LOW);
}
else if((sensorki==HIGH) && (sensorka==LOW))
{
//sensor kiri mendeteksi garis hitam
//belok kiri
motorSpeedA=255;
motorSpeedB=255;
analogWrite(enA,motorSpeedA);
analogWrite(enB,motorSpeedB);
digitalWrite(motorkaf,HIGH);
digitalWrite(motorkab,LOW);
digitalWrite(motorkif,LOW);
digitalWrite(motorkib,HIGH);
}
else if((sensorki==LOW) && (sensorka==HIGH))
{
//sensor kanan mendeteksi garis hitam
//belok kanan
motorSpeedA=255;
motorSpeedB=255;
analogWrite(enA,motorSpeedA);
analogWrite(enB,motorSpeedB);
digitalWrite(motorkaf,LOW);
digitalWrite(motorkab,HIGH);
digitalWrite(motorkif,HIGH);
digitalWrite(motorkib,LOW);
}
else
{
//kedua sensor mendeteksi garis
//stop
motorSpeedA=255;
motorSpeedB=255;
analogWrite(enA,motorSpeedA);
analogWrite(enB,motorSpeedB);
digitalWrite(motorkaf,LOW);
digitalWrite(motorkif,LOW);
digitalWrite(motorkab,LOW);
digitalWrite(motorkib,LOW);
}
}
