#define TimeDelay 5

int ledPin = 13;
bool led = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() == true){
    char e = Serial.read();
    delay(TimeDelay);
    Serial.println(e);
    if(led){
      digitalWrite(ledPin, HIGH);
      led = false;
    }else{
      digitalWrite(ledPin, LOW);
      led = true;
    }
  }
}
