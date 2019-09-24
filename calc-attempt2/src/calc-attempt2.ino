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

int num_0 = 0;
int num_1 = 0;
int num_2 = 0;
int num_3 = 0;
int num_4 = 0;
int num_5 = 0;
int num_6 = 0;
int num_7 = 0;
int num_8 = 0;
int num_9 = 0;
int decimal = 0;
int addButton = 0;
int subtractButton = 0;
int multiplyButton = 0;
int divideButton = 0;
int equalsButton = 0;
int clearButton = 0;
int clearAllButton = 0;
int backspaceButton = 0;

BLYNK_WRITE(blynk_0){
  if(param.asInt()){
    num_0 = 1;
  }
  else{
    num_0 = 0;
  }
}
BLYNK_WRITE(blynk_1){
num_1 = param.asInt();
}
BLYNK_WRITE(blynk_2){
num_2 = param.asInt();
}
BLYNK_WRITE(blynk_3){
num_3 = param.asInt();
}
BLYNK_WRITE(blynk_4){
num_4 = param.asInt();
}
BLYNK_WRITE(blynk_5){
num_5 = param.asInt();
}
BLYNK_WRITE(blynk_6){
num_6 = param.asInt();
}
BLYNK_WRITE(blynk_7){
num_7 = param.asInt();
}
BLYNK_WRITE(blynk_8){
num_8 = param.asInt();
}
BLYNK_WRITE(blynk_9){
num_9 = param.asInt();
}
BLYNK_WRITE(blynk_decimal){
decimal = param.asInt();
}
BLYNK_WRITE(blynk_addition){
addButton = param.asInt();
}
BLYNK_WRITE(blynk_subtraction){
subtractButton = param.asInt();
}
BLYNK_WRITE(blynk_multiplication){
multiplyButton = param.asInt();
}
BLYNK_WRITE(blynk_division){
divideButton = param.asInt();
}
BLYNK_WRITE(blynk_equals){
equalsButton = param.asInt();
}
BLYNK_WRITE(blynk_clear){
clearButton = param.asInt();
}
BLYNK_WRITE(blynk_clearEverything){
clearAllButton = param.asInt();
}

float value1 = 0;
float value2 = 0;
//double answer = 0;
enum selected_operator {add,subtract,multiply,divide,none};
enum selected_operator selectedOperator;
uint16_t delay_amount = 400;
void setup() {
  Blynk.begin("74b8982979ac48d2b49c1e32adcf79e3",IPAddress(167,99,150,124),8080); 
  Serial.begin(9600);
}

void determine_input(){
  if(num_0 == 1){
    Serial.println("0");
    value2 = ((value2 * 10) + 0);
    Serial.println((float) value2);
    Blynk.virtualWrite(blynk_display, value2);   
    delay(delay_amount);
  }
  else if(num_1 == 1){
    Serial.println("1");
    value2 = ((value2 * 10) + 1);
    Serial.println((float) value2);
    Blynk.virtualWrite(blynk_display, value2);   
    delay(delay_amount);
  }
  else if(num_2 == 1){
    Serial.println("2");
    value2 = ((value2 * 10) + 2);
    Serial.println((float) value2);
    Blynk.virtualWrite(blynk_display, value2);      
    delay(delay_amount);
  }
  else if(num_3 == 1){
    Serial.println("3");
    value2 = ((value2 * 10) + 3);
    Serial.println((float) value2);
    Blynk.virtualWrite(blynk_display, value2); 
    delay(delay_amount);
  }
  else if(num_4 == 1){
    Serial.println("4");
    value2 = ((value2 * 10) + 4);
    Serial.println((float) value2);
    Blynk.virtualWrite(blynk_display, value2); 
    delay(delay_amount); 
  }
  else if(num_5 == 1){
    Serial.println("5");
    value2 = ((value2 * 10) + 5);
    Serial.println((float) value2);
    Blynk.virtualWrite(blynk_display, value2); 
    delay(delay_amount);
  }
  else if(num_6 == 1){
    Serial.println("6");
    value2 = ((value2 * 10) + 6);
    Serial.println((float) value2);
    Blynk.virtualWrite(blynk_display, value2); 
    delay(delay_amount);
  }
  else if(num_7 == 1){
    Serial.println("7");
    value2 = ((value2 * 10) + 7);
    Serial.println((float) value2);
    Blynk.virtualWrite(blynk_display, value2); 
    delay(delay_amount);
  }
  else if(num_8 == 1){
    Serial.println("8");
    value2 = ((value2 * 10) + 8);
    Serial.println((float) value2);
    Blynk.virtualWrite(blynk_display, value2); 
    delay(delay_amount);
  }
  else if(num_9 == 1){
    Serial.println("9");
    value2 = ((value2 * 10) + 9);
    Serial.println((float) value2);
    Blynk.virtualWrite(blynk_display, value2); 
    delay(delay_amount);
  }
  else if(addButton == 1){
    Serial.println("Add Selected");
    value1 = value2;
    Serial.println((float) value1);
    value2 = 0;
    Blynk.virtualWrite(blynk_display, value2);
    selectedOperator = add;
    delay(delay_amount);
  }
  else if(subtractButton == 1){
    Serial.println("Subtract Selected");
    value1 = value2;
    Serial.println((float) value1);
    value2 = 0;
    Blynk.virtualWrite(blynk_display, value2);
    selectedOperator = subtract;
    delay(delay_amount);
  }
  else if(multiplyButton == 1){
    Serial.println("Multiply Selected");
    value1 = value2;
    Serial.println((float) value1);
    value2 = 0;
    Blynk.virtualWrite(blynk_display, value2);
    selectedOperator = multiply;
    delay(delay_amount);
  }
  else if(divideButton == 1){
    Serial.println("Divide Selected");
    value1 = value2;
    Serial.println((float) value1);
    value2 = 0;
    Blynk.virtualWrite(blynk_display, value2);
    selectedOperator = divide;
    delay(delay_amount);
  }
  else if(equalsButton == 1){
    Serial.println("Equals Selected");
    if(selectedOperator == add){
      Serial.println("Addition in Progress");
      value2 = value1 + value2;
      Blynk.virtualWrite(blynk_display, value2);
      selectedOperator = none;
      delay(delay_amount);
    }
    else if(selectedOperator == subtract){
      Serial.println("Subtraction in Progress");
      value2 = value1 - value2;
      Blynk.virtualWrite(blynk_display, value2);
      selectedOperator = none;
      delay(delay_amount);
    }
    else if(selectedOperator == multiply){
      Serial.println("Multiplication in Progress");
      Serial.println((float) value1);
      Serial.println((float) value2);
      value2 = value1 * value2;
      Blynk.virtualWrite(blynk_display, value2);
      selectedOperator = none;
      delay(delay_amount);
    }
    else if(selectedOperator == divide){
      Serial.println("Division in Progress");
      value2 = value1 / value2;
      Blynk.virtualWrite(blynk_display, value2);
      selectedOperator = none;
      delay(delay_amount);
    }
    else{
      Serial.println("Equals resulted in full clear");
      value1 = 0;
      value2 = 0;
      selectedOperator = none;
      Blynk.virtualWrite(blynk_display, value2);
      delay(delay_amount);
    }
  }
}

void take_input(int value){}

void loop() {
  Blynk.run();
  determine_input();
}