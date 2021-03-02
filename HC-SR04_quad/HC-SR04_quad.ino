const int trigPin1 = D2;    //Trig 핀 할당
const int trigPin2 = D4;
const int trigPin3 = D6;
const int trigPin4 = D8;

const int echoPin1 = D3;    //Echo 핀 할당
const int echoPin2 = D5;
const int echoPin3 = D7;
const int echoPin4 = D9;

long distance[4];
long duration[4];
 
void setup()
{
    Serial.begin(115200);
    
    pinMode(trigPin1, OUTPUT);    //Trig 핀 output으로 세팅
    pinMode(trigPin2, OUTPUT);    //Trig 핀 output으로 세팅
    pinMode(trigPin3, OUTPUT);    //Trig 핀 output으로 세팅
    pinMode(trigPin4, OUTPUT);    //Trig 핀 output으로 세팅
    
    pinMode(echoPin1, INPUT);    //Echo 핀 input으로 세팅
    pinMode(echoPin2, INPUT);    //Echo 핀 input으로 세팅
    pinMode(echoPin3, INPUT);    //Echo 핀 input으로 세팅
    pinMode(echoPin4, INPUT);    //Echo 핀 input으로 세팅
}

long HC_SR04(int trigPin, int echoPin)
{
    long distance;
    long duration;
    digitalWrite(trigPin, LOW);        
      
    delayMicroseconds(2);            //2us 유지
    digitalWrite(trigPin, HIGH);    
    
    delayMicroseconds(10);            //10us 유지
    digitalWrite(trigPin, LOW);       
  
    //Echo 핀으로 들어오는 펄스의 시간 측정
    duration = pulseIn(echoPin, HIGH);        //pulseIn함수가 호출되고 펄스가 입력될 때까지의 시간. us단위로 값을 리턴.
  
  
    //음파가 반사된 시간을 거리로 환산
    //음파의 속도는 340m/s 이므로 1cm를 이동하는데 약 29us.
    //따라서, 음파의 이동거리 = 왕복시간 / 1cm 이동 시간 / 2 이다.
    distance = duration / 29 / 2;        //센치미터로 환산  
    return distance;
}
 
void loop()
{
    distance[0] = HC_SR04(trigPin1, echoPin1);
    delay(5);
    
    distance[1] = HC_SR04(trigPin2, echoPin2);
    delay(5);
    
    distance[2] = HC_SR04(trigPin3, echoPin3);
    delay(5);
    
    distance[3] = HC_SR04(trigPin4, echoPin4);
    delay(5);
    
    Serial.print(distance[0]);
    Serial.print(" ");
    Serial.print(distance[1]);
    Serial.print(" ");
    Serial.print(distance[2]);
    Serial.print(" ");
    Serial.print(distance[3]);
    Serial.println();
    delay(30);
}
