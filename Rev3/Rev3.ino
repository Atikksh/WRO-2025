#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

// Stores frequency read by the photodiodes
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
int redF = 0;
int greenF = 0;
int blueF = 0;

// Stores the red. green and blue colors
int redColor = 0;
int greenColor = 0;
int blueColor = 0;

//Stores the max and min value during calibration eariler for mapping
int red1 = 0;
int green1 = 0;
int blue1 = 0;

int red2 = 0;
int green2 = 0;
int blue2 = 0;

int red3 = 0;
int green3 = 0;
int blue3 = 0;   

int cIter = 0;

void calibrateSend(){
  digitalWrite(11,LOW);
}

void sortingSend(){
  digitalWrite(11,HIGH);
}

void sendState(int s){
  if(s == 1){
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
  }else if(s == 2){
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
  }else if(s == 3){
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
  }else if(s == 4){
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
  }
}

void setup() {
  // Colour sensor
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  // ----- Arduino UNO R4 ----- {
  // State
  pinMode(9,OUTPUT);  // MSB
  pinMode(10,OUTPUT); // LSB
  // Mode
  pinMode(11,OUTPUT); // MODE
  pinMode(12,OUTPUT);

  // IR Sensor Output
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  // ----- Arduino UNO R4 ----- }

  //LEDs (9,10)
  pinMode(A4, OUTPUT); // L9
  pinMode(A5, OUTPUT); // L10

  // IR Sensor Input
  pinMode(0,INPUT);
  pinMode(1,INPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  
  // Setting the sensorOut as an input
  pinMode(sensorOut, INPUT);
  
  // Setting frequency scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  // Begins serial communication
  Serial.begin(9600);
  Serial.println("Calibration Begin");
  calibrateSend();

  // ------------------------------------------ C1 ----------------------------------------------- //
  Serial.println("Fetch C1 object");
  sendState(1);
  delay(500);
  sendState(4);
  delay(500);
  sendState(1);
  delay(500);
  sendState(4);
  delay(500);
  sendState(1);
  delay(500);
  sendState(4);
  delay(500);
  sendState(1);
  
  Serial.println("Show C1 object");
  while(cIter < 70){
    // Read red
    cIter++;
    digitalWrite(S2,LOW);
    digitalWrite(S3,LOW);
    redFrequency = pulseIn(sensorOut, LOW);
    
    if(cIter > 100){
      if(redFrequency >= (3/4)*red1 && redFrequency <= (5/4*red1)){
        red1 *= cIter - 1;
        red1 += redFrequency;
        red1 /= cIter;
      }else{
        red1 *= cIter - 1;
        red1 += red1;
        red1 /= cIter;
      }
      }else{
      red1 *= cIter - 1;
        red1 += redFrequency;
        red1 /= cIter;
    }

    digitalWrite(S2,LOW);
    digitalWrite(S3,HIGH);
    blueFrequency = pulseIn(sensorOut, LOW);
    
    if(cIter > 100){
      if(blueFrequency >= (3/4)*blue1 && blueFrequency <= (5/4*blue1)){
        blue1 *= cIter - 1;
        blue1 += blueFrequency;
        blue1 /= cIter;
      }else{
        blue1 *= cIter - 1;
        blue1 += blue1;
        blue1 /= cIter;
      }
      }else{
        blue1 *= cIter - 1;
        blue1 += blueFrequency;
        blue1 /= cIter;
    }

     digitalWrite(S2,HIGH);
    digitalWrite(S3,HIGH);
    greenFrequency = pulseIn(sensorOut, LOW);

    if(cIter > 100){
      if(greenFrequency >= (3/4)*green1 && greenFrequency <= (5/4*green1)){
        green1 *= cIter - 1;
        green1 += greenFrequency;
        green1 /= cIter;
      }else{
        green1 *= cIter - 1;
        green1 += green1;
        green1 /= cIter;
      }
      }else{
      green1 *= cIter - 1;
        green1 += greenFrequency;
        green1 /= cIter;
    }

    Serial.print(" <--- C1 ---> ");
    Serial.print("RGB: ");
    Serial.print(redFrequency);
    Serial.print(",");
    Serial.print(greenFrequency);
    Serial.print(",");
    Serial.print(blueFrequency);
    Serial.print("| Running Average (RGB): ");
    Serial.print(red1);
    Serial.print(",");
    Serial.print(green1);
    Serial.print(",");
    Serial.print(blue1);
    Serial.print("| Iteration: ");
    Serial.print(cIter);
    Serial.println("");
  }
  cIter = 0;

  // ------------------------------------------ C2 ----------------------------------------------- //
  Serial.println("Fetch C2 object");
  sendState(2);
  delay(500);
  sendState(4);
  delay(500);
  sendState(2);
  delay(500);
  sendState(4);
  delay(500);
  sendState(2);
  delay(500);
  sendState(4);
  delay(500);
  sendState(2);
  Serial.println("Show C2 object");
  while(cIter < 70){
    // Read red
    cIter++;
    digitalWrite(S2,LOW);
    digitalWrite(S3,LOW);
    redFrequency = pulseIn(sensorOut, LOW);
    
    if(cIter > 100){
      if(redFrequency >= (3/4)*red2 && redFrequency <= (5/4*red2)){
        red2 *= cIter - 1;
        red2 += redFrequency;
        red2 /= cIter;
      }else{
        red2 *= cIter - 1;
        red2 += red1;
        red2 /= cIter;
      }
      }else{
      red2 *= cIter - 1;
        red2 += redFrequency;
        red2 /= cIter;
    }

    digitalWrite(S2,LOW);
    digitalWrite(S3,HIGH);
    blueFrequency = pulseIn(sensorOut, LOW);
    
    if(cIter > 100){
      if(blueFrequency >= (3/4)*blue2 && blueFrequency <= (5/4*blue2)){
        blue2 *= cIter - 1;
        blue2 += blueFrequency;
        blue2 /= cIter;
      }else{
        blue2 *= cIter - 1;
        blue2 += blue1;
        blue2 /= cIter;
      }
      }else{
        blue2 *= cIter - 1;
        blue2 += blueFrequency;
        blue2 /= cIter;
    }

    digitalWrite(S2,HIGH);
    digitalWrite(S3,HIGH);
    greenFrequency = pulseIn(sensorOut, LOW);
    
    if(cIter > 100){
      if(greenFrequency >= (3/4)*green2 && greenFrequency <= (5/4*green2)){
        green2 *= cIter - 1;
        green2 += greenFrequency;
        green2 /= cIter;
      }else{
        green2 *= cIter - 1;
        green2 += green1;
        green2 /= cIter;
      }
     }else{
      green2 *= cIter - 1;
        green2 += greenFrequency;
        green2 /= cIter;
    }

    Serial.print(" <--- C2 ---> ");
    Serial.print("RGB: ");
    Serial.print(redFrequency);
    Serial.print(",");
    Serial.print(greenFrequency);
    Serial.print(",");
    Serial.print(blueFrequency);
    Serial.print("| Running Average (RGB): ");
    Serial.print(red2);
    Serial.print(",");
    Serial.print(green2);
    Serial.print(",");
    Serial.print(blue2);
    Serial.print("| Iteration: ");
    Serial.print(cIter);
    Serial.println("");
  }
  cIter = 0;

  // ------------------------------------------ C3 ----------------------------------------------- //
  Serial.println("Fetch C3 object");
  sendState(3);
  delay(500);
  sendState(4);
  delay(500);
  sendState(3);
  delay(500);
  sendState(4);
  delay(500);
  sendState(3);
  delay(500);
  sendState(4);
  delay(500);
  sendState(3);
  Serial.println("Show C3 object");
  while(cIter < 70){
    // Read red
    cIter++;
    digitalWrite(S2,LOW);
    digitalWrite(S3,LOW);
    redFrequency = pulseIn(sensorOut, LOW);
    
    if(cIter > 100){
      if(redFrequency >= (3/4)*red3 && redFrequency <= (5/4*red3)){
        red3 *= cIter - 1;
        red3 += redFrequency;
        red3 /= cIter;
      }else{
        red3 *= cIter - 1;
        red3 += red1;
        red3 /= cIter;
      }
      }else{
        red3 *= cIter - 1;
        red3 += redFrequency;
        red3 /= cIter;
    }

    digitalWrite(S2,LOW);
    digitalWrite(S3,HIGH);
    blueFrequency = pulseIn(sensorOut, LOW);
    
    if(cIter > 100){
      if(blueFrequency >= (3/4)*blue3 && blueFrequency <= (5/4*blue3)){
        blue3 *= cIter - 1;
        blue3 += blueFrequency;
        blue3 /= cIter;
      }else{
        blue3 *= cIter - 1;
        blue3 += blue1;
        blue3 /= cIter;
      }
      }else{
        blue3 *= cIter - 1;
        blue3 += blueFrequency;
        blue3 /= cIter;
    }

    digitalWrite(S2,HIGH);
    digitalWrite(S3,HIGH);
    greenFrequency = pulseIn(sensorOut, LOW);
    
    if(cIter > 100){
      if(greenFrequency >= (3/4)*green3 && greenFrequency <= (5/4*green3)){
        green3 *= cIter - 1;
        green3 += greenFrequency;
        green3 /= cIter;
      }else{
        green3 *= cIter - 1;
        green3 += green1;
        green3 /= cIter;
      }
      }else{
        green3 *= cIter - 1;
        green3 += greenFrequency;
        green3 /= cIter;
    }

    Serial.print(" <--- C3 ---> ");
    Serial.print("RGB: ");
    Serial.print(redFrequency);
    Serial.print(",");
    Serial.print(greenFrequency);
    Serial.print(",");
    Serial.print(blueFrequency);
    Serial.print("| Running Average (RGB): ");
    Serial.print(red3);
    Serial.print(",");
    Serial.print(green3);
    Serial.print(",");
    Serial.print(blue3);
    Serial.print("| Iteration: ");
    Serial.print(cIter);
    Serial.println("");
  }
  cIter = 0;

  // ------------------------- Calibration Finished ---------------------------- //
  Serial.println("<--------------- Calibration Finished ------------------>");
  
  Serial.println("<-- C1 RGB VALUES -->");
  Serial.print("Red: ");
  delay(100);
  Serial.println(red1);
  delay(50);
  Serial.print("Green: ");
  delay(100);
  Serial.println(green1);
  delay(50);
  Serial.print("Blue: ");
  delay(100);
  Serial.println(blue1);
  delay(50);
  Serial.print("RGB: ");
  delay(100);
  Serial.print(red1);
  Serial.print(",");
  Serial.print(green1);
  Serial.print(",");
  Serial.println(blue1);
  delay(50);

  Serial.println("<-- C2 RGB VALUES -->");
  Serial.print("Red: ");
  delay(100);
  Serial.println(red2);
  delay(50);
  Serial.print("Green: ");
  delay(100);
  Serial.println(green2);
  delay(50);
  Serial.print("Blue: ");
  delay(100);
  Serial.println(blue2);
  delay(50);
  Serial.print("RGB: ");
  delay(100);
  Serial.print(red2);
  Serial.print(",");
  Serial.print(green2);
  Serial.print(",");
  Serial.println(blue2);
  delay(50);

  Serial.println("<-- C3 RGB VALUES -->");
  Serial.print("Red: ");
  delay(100);
  Serial.println(red3);
  delay(50);
  Serial.print("Green: ");
  delay(100);
  Serial.println(green3);
  delay(50);
  Serial.print("Blue: ");
  delay(100);
  Serial.println(blue3);
  delay(50);
  Serial.print("RGB: ");
  delay(100);
  Serial.print(red3);
  Serial.print(",");
  Serial.print(green3);
  Serial.print(",");
  Serial.println(blue3);
  delay(5000);

  sortingSend();
  sendState(4);
  Serial.print("Initializing...");
  delay(1000);
  Serial.print("5");
  delay(1000);
  Serial.print("4");
  delay(1000);
  Serial.print("3");
  delay(1000);
  Serial.print("2");
  delay(1000);
  Serial.print("1");
  delay(1000);
  Serial.print("Starting");
  
}

void loop() { 
  digitalWrite(A0,((digitalRead(0)) * -1) + 1);
  digitalWrite(A1,((digitalRead(1)) * -1) + 1);
  digitalWrite(A2,((digitalRead(2)) * -1) + 1);
  digitalWrite(A3,((digitalRead(3)) * -1) + 1);
  
  digitalWrite(S2,LOW); 
  digitalWrite(S3,LOW);
  
  redF = pulseIn(sensorOut, LOW);
  
  Serial.print("R = ");
  Serial.print(redF);
  delay(100);
  
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  greenF = pulseIn(sensorOut, LOW);
  
  Serial.print(" G = ");
  Serial.print(greenF);
  delay(100);
 
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  blueF = pulseIn(sensorOut, LOW);
  
  // Printing the BLUE (B) value 
  Serial.print(" B = ");
  Serial.print(blueF);
  delay(100);
  if(diff(redF,greenF,blueF,red1,green1,blue1) < diff(redF,greenF,blueF,red2,green2,blue2) && diff(redF,greenF,blueF,red1,green1,blue1) < diff(redF,greenF,blueF,red3,green3,blue3)){
      Serial.println(" - C1 detected!");
      sendState(1);
  }
  if(diff(redF,greenF,blueF,red2,green2,blue2) < diff(redF,greenF,blueF,red1,green1,blue1) && diff(redF,greenF,blueF,red2,green2,blue2) < diff(redF,greenF,blueF,red3,green3,blue3)){
    Serial.println(" - C2 detected!");
    sendState(2);
    digitalWrite(A4, HIGH);
    digitalWrite(A5, LOW);
  }
  if(diff(redF,greenF,blueF,red3,green3,blue3) < diff(redF,greenF,blueF,red2,green2,blue2) && diff(redF,greenF,blueF,red3,green3,blue3) < diff(redF,greenF,blueF,red1,green1,blue1)){
    Serial.println(" - C3 detected!");
    sendState(3);  
    digitalWrite(A5, HIGH);
    digitalWrite(A4, LOW);
  }
}

int diff(int r, int g, int b, int rRef, int gRef, int bRef){
  int dif = (dist(r,rRef) + dist(g,gRef) + dist(b,bRef)) / 3;
  return dif;
}

int dist(int i, int j){
  int t = i - j;
  if(t < 0){
    t *= -1;
  }
  return(t);
}
