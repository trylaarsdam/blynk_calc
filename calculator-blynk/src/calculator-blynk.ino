#include <blynk.h>

#define blynk_0 V0
#define blynk_1 V1
#define blynk_2 V2
#define blynk_3 V3
#define blynk_4 V4
#define blynk_5 V5
#define blynk_6 V6
#define blynk_7 V7
#define blynk_8 V8
#define blynk_9 V9
#define blynk_decimal V10
#define blynk_addition V11
#define blynk_subtraction V12
#define blynk_multiplication V13
#define blynk_division V14
#define blynk_equals V15
#define blynk_clear V16
#define blynk_clearEverything V17
#define blynk_backspace V18
#define blynk_display V19

uint16_t currentOperator = 0; //0 == null, 1 == add, 2 == sub, 3 == mult, 4 == div
uint32_t currentValue = 0; // current value of the "screen" or current entry
uint32_t currentValue2 = 0; //value that will be operated 
uint32_t completedValue = 0; 
uint16_t lastDigit = 0; //for use with backspace key

void setup() {
  Blynk.begin("74b8982979ac48d2b49c1e32adcf79e3",IPAddress(167,99,150,124),8080); 
  Serial.begin(9600);
}

void execute_operation(){
  if(currentOperator == 1){
    add();
    Serial.println("add");
  }
  if(currentOperator == 2){
    subtract();
    Serial.println("sub");
  }
  if(currentOperator == 3){
    multiply();
    Serial.println("mult");
  }
  if(currentOperator == 4){
    divide();
    Serial.println("div");
  }
}

void display_completed(int value){
  //displays completedValue
  Blynk.virtualWrite(blynk_display, value);
  Serial.println("screenwrite");
}

void add() {
  //add numbers in array
  completedValue = currentValue2 + currentValue;
  display_completed(completedValue);
}

void subtract() {
  //subtract numbers in array
  completedValue = currentValue2 - currentValue;
  display_completed(completedValue);
}

void multiply() {
  //multiply numbers in array
  completedValue = currentValue2 * currentValue;
  display_completed(completedValue);
}

void divide() {
  //divide numbers in array
  completedValue = currentValue2 / currentValue;
  display_completed(completedValue);
}

void clear_all() {
  //clear everything (aka reset)
  currentOperator = 0;
  currentValue = 0;
  currentValue2 = 0;
  completedValue = 0;
  display_completed(completedValue);
  Serial.println("clearall");
}

void clear_display() {
  //clear display
  Serial.println("cleardisplay");
}

void backspace() {
  //remove last digit
  currentValue = currentValue - lastDigit;
  currentValue = currentValue / 10;
  display_completed(currentValue);
  Serial.println("backspace");
}

void take_input(int input) {

  //if number, append to current value
  if(input < 10){
    currentValue = currentValue * 10;
    currentValue = currentValue + input;
    lastDigit = input;
    display_completed(currentValue);
    Serial.println("numericalInput");
  }
  //-----if operator, send current value to operator value, set operator-----
    //THIS IS DETERMINED IN operator_decision()

  //-----if equals, call operator_decision-----
    //THIS IS DETERMINED IN operator_decision()
  
}

void operator_decision() {  //0 == null, 1 == add, 2 == sub, 3 == mult, 4 == div
  if(blynk_addition == 1){
    currentOperator = 1;
    currentValue = currentValue2;
    Serial.println("addition-set");
  }
  if(blynk_subtraction == 1){
    currentOperator = 2;
    currentValue = currentValue2;
    Serial.println("subtraciton-set");
  }
  if(blynk_multiplication == 1){
    currentOperator = 3;
    currentValue = currentValue2;
    Serial.println("mult-set");
  }
  if(blynk_division == 1){
    currentOperator = 4;
    currentValue = currentValue2;
    Serial.println("div-set");
  }
  if(blynk_equals == 1){
    if (currentOperator == 1){
      add();
      Serial.println("equals-add");
    }
    if (currentOperator == 2){
      subtract();
      Serial.println("equals-sub");
    }
    if (currentOperator == 3){
      multiply();
      Serial.println("mult-sub");
    }
    if (currentOperator == 4){
      divide();
      Serial.println("div-sub");
    }
  }
  
}

void determine_input(){
  if(blynk_0 == 1){
    take_input(0);
    Serial.println("0");
  }
  if(blynk_1 == 1){
    take_input(1);
    Serial.println("1");
  }
  if(blynk_2 == 1){
    take_input(2);
    Serial.println("2");
  }
  if(blynk_3 == 1){
    take_input(3);
    Serial.println("3");
  }
  if(blynk_4 == 1){
    take_input(4);
    Serial.println("4");
  }
  if(blynk_5 == 1){
    take_input(5);
    Serial.println("5");
  }
  if(blynk_6 == 1){
    take_input(6);
    Serial.println("6");
  }
  if(blynk_7 == 1){
    take_input(7);
    Serial.println("7");
  }
  if(blynk_8 == 1){
    take_input(8);
    Serial.println("8");
  }
  if(blynk_9 == 1){
    take_input(9);
    Serial.println("9");
  }
  else{
    operator_decision();
    Serial.println("operator-decision-set");
  }
}

void loop() {
  Blynk.run();
  determine_input();
}