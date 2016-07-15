#include <Servo.h>
#include <stdint.h>


Servo index_finger;
Servo middle_finger;
Servo ring_finger;
Servo pinky_finger;
Servo thumb_finger;

//Finger - pin defs
int index_ = 3;
int middle_ = 6;
int ring_ = 11;
int pinky_ = 10;
int thumb_ = 9;
//Input pin definitions
int input_0 = 0;
int input_1 = 1;
int input_2 = 2;
int input_3 = 4;
int input_4 = 7;
int input_5 = 8;



struct hand_pos{
  uint8_t index;
  uint8_t middle;
  uint8_t ring;
  uint8_t pinky;
  uint8_t thumb;
};
void write_to_servo(hand_pos hand);
int get_input_byte();


hand_pos hand[4];

void setup(){
  
  
  hand[0] = (hand_pos){0, 0, 0, 0, 0};
  hand[1] = (hand_pos){128, 128, 128, 128, 128};
  hand[2] = (hand_pos){0, 200, 200, 200, 0};
  hand[3] = (hand_pos){0, 0, 200, 200, 0};
  pinMode(index_, OUTPUT);
  pinMode(middle_, OUTPUT);
  pinMode(ring_, OUTPUT);
  pinMode(pinky_, OUTPUT);
  pinMode(thumb_, OUTPUT);
  index_finger.attach(index_);
  middle_finger.attach(middle_);
  ring_finger.attach(ring_);
  pinky_finger.attach(pinky_);
  thumb_finger.attach(thumb_);
  
}

void loop(){
  switch((get_input_byte() & 0b11)){
    case 0:
      write_to_servo(hand[0]);
      break;
     case 1:
       write_to_servo(hand[1]);
       break;
     case 2:
       write_to_servo(hand[2]);
       break;
     case 3:
       write_to_servo(hand[3]);
  }
  
  delay(1000);
}


int get_input_byte(){
  return (digitalRead(input_0)) | (digitalRead(input_1) << 1) | (digitalRead(input_2) << 2) | (digitalRead(input_3) << 3) | (digitalRead(input_4) << 4) | (digitalRead(input_5) << 5);  
}

void write_to_servo(hand_pos hand){
  index_finger.write(hand.index);
  middle_finger.write(hand.middle);
  ring_finger.write(hand.ring);
  pinky_finger.write(hand.pinky);
  thumb_finger.write(hand.thumb);
}
