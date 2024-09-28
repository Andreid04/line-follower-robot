//f inainte b inapoi l left r right
// out 2 si 3 sunt pt inainte la motoare, out 1 si 4 sunt pt inapoi, 1,2 - motor dreapta, 3,4 - motor stanga
// sl si sr sunt pe invers dar si citirea e pe invers low = negru si high = alb
int mrf = 7;
int mlf = 9;
int mrb = 8;
int mlb = 12;
int sr = 3;
int sl = 5;
int near = 2;

int svr = 0;  //read values
int svl = 0;
int nearv = 0;

int led = 13;
int enr = 11;
int enl = 10;

int tspeed = 180;

void setup() {

  pinMode(mrf, OUTPUT);
  pinMode(mlf, OUTPUT);
  pinMode(mrb, OUTPUT);
  pinMode(mlb, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(enr, OUTPUT);
  pinMode(enl, OUTPUT);
  pinMode(sr, INPUT);
  pinMode(sl, INPUT);
  pinMode(near, INPUT);

  delay(5000);

  Serial.begin(9600);
}

void loop() {
  svr = digitalRead(sr);
  svl = digitalRead(sl);
  nearv = digitalRead(near);  //low = no obstacle 

  if(svl==LOW && svr==LOW)
  {
  stop(); 
  }

  if(svl==HIGH && svr==LOW)
  {
  left();
  }
 
  if(svl==LOW && svr==HIGH)
  { 
  right();
  }
  
  if(svl==HIGH && svr==HIGH)
  {
  forward(); 
  }
  //basic line following capabilities until now ))

  if(nearv==HIGH)// object needs to be heavy enough to not move
   // when in contact with the vehicle
  {
    stop();
    delay(1000);

    backward();
    delay(800);

    lefts();
    delay(1400);//avoid obstacle by going left

    forward();
    delay(1300);

    rights();
    delay(1000);

    forward();
    delay(2100);//get in front of the obstacle

    rights();
    delay(650);//reach the line again at slight right angle

    while(svl==HIGH)//left is actually right sensor!!!!
    {
      forward();
      delay(50);
     svl = digitalRead(sl);
    }

      stop();
      delay(1000);//for debug

      lefts(); 
      delay(100);     
    //get over the line

    stop();

  }

}

void forward()
 {
  digitalWrite(mrf,HIGH);//7 in2
  digitalWrite(mlf,HIGH);//9 in3
  digitalWrite(mrb,LOW);//8 in1
  digitalWrite(mlb,LOW);//12 in4
  analogWrite (enr,tspeed);
  analogWrite (enl,tspeed);
 } 

void backward()
{
  digitalWrite(mrf,LOW);//7 in2
  digitalWrite(mlf,LOW);//9 in3
  digitalWrite(mrb,HIGH);//8 in1
  digitalWrite(mlb,HIGH);//12 in4
  analogWrite (enr,tspeed);
  analogWrite (enl,tspeed);
}

void rights()
 {
  digitalWrite(mrf,LOW);
  digitalWrite(mlf,HIGH);
  digitalWrite(mrb,LOW);
  digitalWrite(mlb,LOW);
  analogWrite (enr,tspeed);
  analogWrite (enl,tspeed);
 } 

void lefts()
 {
  digitalWrite(mrf,HIGH);
  digitalWrite(mlf,LOW);
  digitalWrite(mrb,LOW);
  digitalWrite(mlb,LOW);
  analogWrite (enr,tspeed);
  analogWrite (enl,tspeed);
 }  

 void right()
 {
  digitalWrite(mrf,LOW);
  digitalWrite(mlf,HIGH);
  digitalWrite(mrb,HIGH);
  digitalWrite(mlb,LOW);
  analogWrite (enr,tspeed);
  analogWrite (enl,tspeed);
 } 

void left()
 {
  digitalWrite(mrf,HIGH);
  digitalWrite(mlf,LOW);
  digitalWrite(mrb,LOW);
  digitalWrite(mlb,HIGH);
  analogWrite (enr,tspeed);
  analogWrite (enl,tspeed);
 }  

void stop()
 {
  analogWrite (enr,0);
  analogWrite (enl,0);
 }

