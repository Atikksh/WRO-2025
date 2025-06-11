# include <array>
# include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

std::array<std::array<uint8_t, 12>,8> grid = {{
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, 
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, 
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, 
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, 
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
    }};

void setup() {
  // put your setup code here, to run once:
  //
  

  // Mode
    pinMode(2, INPUT);
    
  // State
    pinMode(3, INPUT); // MSB
    pinMode(4, INPUT); // LSB

  // IR Sensors
    pinMode(5, INPUT);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(8, INPUT);
  
  // Motor Drivers
    pinMode(9 , OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);

  // LEDs (1 - 8)
    pinMode(13, OUTPUT); // L1
    pinMode(A0, OUTPUT); // L2
    pinMode(A1, OUTPUT); // L3 
    pinMode(A2, OUTPUT); // L4
    pinMode(A3, OUTPUT); // L5
    pinMode(A4, OUTPUT); // L6
    pinMode(A5, OUTPUT); // L7
    pinMode(0 , OUTPUT); // L8

    
}

// LED Pin Vars (For convenience)
    uint8_t l1 = 13;
    uint8_t l2 = A0;
    uint8_t l3 = A1;
    uint8_t l4 = A2;
    uint8_t l5 = A3;
    uint8_t l6 = A4;
    uint8_t l7 = A5;
    uint8_t l8 = 0 ;

bool t_first = 0;

void blink (uint8_t pin){
  digitalWrite(pin, HIGH);
  delay(20);
  digitalWrite(pin, LOW);
}

int decode (int i1, int i2){
  return i1 * 2 + i2 + 1;
}

int a = 0;

void loop() {
  // put your main code here, to run repeatedly:
  a = decode(digitalRead(3), digitalRead(4));
  
  if(digitalRead(2) == 0){
    switch(a){
      case 1:
        digitalWrite(l5, HIGH);
        digitalWrite(l6, LOW );
        digitalWrite(l7, LOW );

        grid = {{
    {{0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0}}, 
    {{0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0}},
    {{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}}, 
    {{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}}, 
    {{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}}, 
    {{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}},
    }};
    grid[0][0] == 0;
    grid[0][1] == 0;
    grid[1][0] == 0;
    grid[1][1] == 0;
  matrix.renderBitmap(grid, 8, 12);
        break;

      case 2:
        digitalWrite(l5, LOW );
        digitalWrite(l6, HIGH);
        digitalWrite(l7, LOW );
        grid = {{
    {{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}}, 
    {{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}}, 
    {{0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0}},
    {{0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0}}, 
    {{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}}, 
    {{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}},
    }};
    grid[0][0] == 0;
    grid[0][1] == 0;
    grid[1][0] == 0;
    grid[1][1] == 0;
  matrix.renderBitmap(grid, 8, 12);
        break;

      case 3:
        digitalWrite(l5, LOW );
        digitalWrite(l6, LOW );
        digitalWrite(l7, HIGH);
        digitalWrite(l5, LOW );
        digitalWrite(l6, HIGH);
        digitalWrite(l7, LOW );
        grid = {{
    {{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}}, 
    {{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}}, 
    {{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}}, 
    {{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0}}, 
    {{0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0}},
    }};
    grid[0][0] == 0;
    grid[0][1] == 0;
    grid[1][0] == 0;
    grid[1][1] == 0;
  matrix.renderBitmap(grid, 8, 12);
        break;

      case 4:
        digitalWrite(l5, LOW );
        digitalWrite(l6, LOW );
        digitalWrite(l7, LOW );
        grid = {{
    {{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}}, 
    {{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}}, 
    {{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}}, 
    {{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}}, 
    {{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}},
    }};
    grid[0][0] == 0;
    grid[0][1] == 0;
    grid[1][0] == 0;
    grid[1][1] == 0;
  matrix.renderBitmap(grid, 8, 12);
        break;
    }
  } else if(digitalRead(2) == 1){
    if(t_first){
    grid = {{
    {{0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0}}, 
    {{0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0}},
    {{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}}, 
    {{0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0}},
    {{0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0}}, 
    {{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0}}, 
    {{0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0}},
    }};
    grid[0][0] == 1;
    grid[0][1] == 1;
    grid[1][0] == 1;
    grid[1][1] == 1;
  matrix.renderBitmap(grid, 8, 12);
  delay(1000);
  grid = {{
    {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}}, 
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, 
    {{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}}, 
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, 
    {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}},
    }};
    matrix.renderBitmap(grid, 8, 12);
    delay(1000);
  }
    switch(a){
      case 1:
        digitalWrite(l8, HIGH);
        break;

      default:
        digitalWrite(l8, LOW);
    }

    if(digitalRead(5) == HIGH){
      grid[0][0] == 1;
      grid[0][1] == 1;
      grid[1][0] == 1;
      grid[1][1] == 1;
      digitalWrite(9,HIGH);
    }else{
      grid[0][0] == 0;
      grid[0][1] == 0;
      grid[1][0] == 0;
      grid[1][1] == 0;
      digitalWrite(9,LOW);
    }

  if(digitalRead(6) == HIGH){
      grid[2][0] == 1;
      grid[2][1] == 1;
      grid[3][0] == 1;
      grid[3][1] == 1;
      digitalWrite(10,HIGH);
    }else{
      grid[2][0] == 0;
      grid[2][1] == 0;
      grid[3][0] == 0;
      grid[3][1] == 0;
      digitalWrite(10,LOW);
    }

    if(digitalRead(7) == HIGH){
      grid[0][2] == 1;
      grid[0][3] == 1;
      grid[1][2] == 1;
      grid[1][3] == 1;
      digitalWrite(11,HIGH);
    }else{
      grid[0][2] == 0;
      grid[0][3] == 0;
      grid[1][2] == 0;
      grid[1][3] == 0;
      digitalWrite(11,LOW);
    }

    if(digitalRead(8) == HIGH){
      grid[2][2] == 1;
      grid[2][3] == 1;
      grid[3][2] == 1;
      grid[3][3] == 1;
      digitalWrite(12,HIGH);
    }else{
      grid[2][2] == 0;
      grid[2][3] == 0;
      grid[3][2] == 0;
      grid[3][3] == 0;
      digitalWrite(12,LOW);
    }

  }

}
