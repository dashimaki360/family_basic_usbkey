
/*

 */

// set pin numbers for the five buttons:
const int d_1 = 2;
const int d_2 = 3;
const int d_3 = 4;
const int d_4 = 5;
const int out_0 = 9;
const int out_1 = 10;
const int out_2 = 11;
const int KEY_SIZE = 72;
int key[KEY_SIZE];

void ResetKey(int* key){
  for(int i =0; i<KEY_SIZE; i++){
    key[i] = 0;
  }
}

void ReadKey(int* key){
  //all key = 0
  ResetKey(key);
  digitalWrite(out_1, LOW);  
  digitalWrite(out_0, HIGH);  
  delayMicroseconds(24d);
  digitalWrite(out_0, LOW); 
  //read keys
  for(int i=0; i<9; i++){
    digitalWrite(out_1, LOW);  
    delayMicroseconds(24);
 
    if(digitalRead(d_1) == HIGH) key[i*8+0] = 1;
    if(digitalRead(d_2) == HIGH) key[i*8+1] = 1;
    if(digitalRead(d_3) == HIGH) key[i*8+2] = 1;
    if(digitalRead(d_4) == HIGH) key[i*8+3] = 1;

    digitalWrite(out_1, HIGH);  
  
    delayMicroseconds(24);

    if(digitalRead(d_1) == HIGH) key[i*8+4] = 1;
    if(digitalRead(d_2) == HIGH) key[i*8+5] = 1;
    if(digitalRead(d_3) == HIGH) key[i*8+6] = 1;
    if(digitalRead(d_4) == HIGH) key[i*8+7] = 1;
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
  Serial.begin(9600);
}

void loop() {
  ReadKey(key);
  for(int i=0; i<KEY_SIZE; i++){
    Serial.print(key[i]);
  }
  Serial.print('\n');
}



