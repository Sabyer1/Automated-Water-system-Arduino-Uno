int trig = 9;
int echo = 8;
int gled = 7;
int bled = 6;
int rled = 5;
int buzz = 4;
int relay = 10;
float duration; 
float distance;



void setup()
{
	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);
	pinMode(buzz, OUTPUT);
        pinMode(gled, OUTPUT);
        pinMode(bled, OUTPUT);
        pinMode(rled, OUTPUT);
        pinMode(relay, OUTPUT);
        Serial.begin(9600);
                
}

void loop()
{
    digitalWrite(trig, LOW);
    delay(1);
	digitalWrite(trig, HIGH); 
	delay(1);
	digitalWrite(trig, LOW);
	duration = pulseIn(echo, HIGH);
	distance = (duration/2) / 29.1;
    Serial.print(distance);
    Serial.print("\n");

 
    if (distance >=31) {
    	digitalWrite(buzz, LOW);
        digitalWrite(gled, LOW);
        digitalWrite(bled, LOW);
        digitalWrite(rled, LOW);
        digitalWrite(relay, HIGH);
        }
    
    else if(distance >=21 && distance <= 30){
       
        digitalWrite(gled, HIGH);
        delay(1000);
        digitalWrite(gled, LOW);
        delay(1000);
        digitalWrite(bled, LOW);
        digitalWrite(rled, LOW);
        digitalWrite(relay, HIGH);
        }

    else if(distance >=11 && distance <= 20){

        digitalWrite(gled, LOW);
        digitalWrite(bled, HIGH);
        delay(500);
        digitalWrite(bled, LOW);
        delay(500);
        digitalWrite(rled, LOW);
        digitalWrite(relay, HIGH);
        }
   
    else if(distance <= 5){
        tone(buzz,5000);
        delay(200);
        noTone(buzz);
        delay(200);
        digitalWrite(gled, LOW);
        digitalWrite(bled, LOW);
        digitalWrite(rled, HIGH);
        delay(200);
        digitalWrite(rled, LOW);
        delay(200);
        digitalWrite(relay, LOW);
        }     
    }
    