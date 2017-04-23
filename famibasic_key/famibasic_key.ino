
/*

 */

#include <Keyboard.h>

// set pin numbers for the five buttons:
const int d_1 = 2;
const int d_2 = 3;
const int d_3 = 4;
const int d_4 = 5;
const int out_0 = 7;
const int out_1 = 8;
const int out_2 = 9;
const int KEY_SIZE = 72;
const int U_DELAY = 50;
bool key[KEY_SIZE];
bool key_pre[KEY_SIZE];
const char KEY[KEY_SIZE]={
  '1',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a', //10
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a', //10
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a', //10
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a', //10
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a', //10
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a', //10
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a',
  'a', //10
  'a',
  'a'
};


void ResetKey(bool* _key){
  for(int i =0; i<KEY_SIZE; i++){
    _key[i] = 0;
  }
}

void SendKey(bool* _key, bool* _key_pre){
  for(int i =0; i<KEY_SIZE; i++){
    if(_key_pre[i]==0 && _key[i]==1 ){
      Keyboard.press(KEY[i]);
      _key_pre[i] = 1;
      //Serial.print("press A \n");
    }else if(_key_pre[i]==1 && _key[i]==0 ){
      Keyboard.release(KEY[i]);
      _key_pre[i] = 0;  
      //Serial.print("release A \n");
    }
  }
}

void ReadKey(bool* _key){
  //all key = 0
  ResetKey(_key);
  digitalWrite(out_1, LOW);  
  digitalWrite(out_0, HIGH);  
  delayMicroseconds(U_DELAY);
  digitalWrite(out_0, LOW); 
  //read keys
  for(int i=0; i<9; i++){
    digitalWrite(out_1, LOW);  
    delayMicroseconds(U_DELAY);
 
    if(digitalRead(d_1) == HIGH) _key[i*8+0] = 1;
    if(digitalRead(d_2) == HIGH) _key[i*8+1] = 1;
    if(digitalRead(d_3) == HIGH) _key[i*8+2] = 1;
    if(digitalRead(d_4) == HIGH) _key[i*8+3] = 1;

    digitalWrite(out_1, HIGH);  
  
    delayMicroseconds(U_DELAY);

    if(digitalRead(d_1) == HIGH) _key[i*8+4] = 1;
    if(digitalRead(d_2) == HIGH) _key[i*8+5] = 1;
    if(digitalRead(d_3) == HIGH) _key[i*8+6] = 1;
    if(digitalRead(d_4) == HIGH) _key[i*8+7] = 1;
  }
  return;
}

void setup() { // initialize the buttons' inputs:
  pinMode(d_1, INPUT);  
  pinMode(d_2, INPUT);
  pinMode(d_3, INPUT);
  pinMode(d_4, INPUT); 
  
  pinMode(out_0, OUTPUT);
  pinMode(out_1, OUTPUT);
  pinMode(out_2, OUTPUT);

  //set key bord
  digitalWrite(out_2, HIGH);
  Keyboard.begin();
  Serial.begin(9600);

  ResetKey(key);
  ResetKey(key_pre);
}

void loop() {
  ReadKey(key);
  SendKey(key, key_pre);
 /* for debag sirial monitor
  for(int i=0; i<KEY_SIZE; i++){
    Serial.print(key[i]);
  }
  Serial.print('\n');
*/
}

