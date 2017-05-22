/*Pinagem do arduino*/
 
//motor A
int IN1 = 12 ;
int IN2 = 11 ;
 
//motor B
int IN3 = 10 ;
int IN4 = 9 ;

int enabA = 13;
int enabB = 8;
 
//Inicializa Pinos
void setup(){
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
 pinMode(IN3,OUTPUT);
 pinMode(IN4, OUTPUT);
 pinMode(enabA,OUTPUT);
  pinMode(enabB,OUTPUT);

  digitalWrite(enabA, HIGH);
  digitalWrite(enabB, HIGH);
}
 
void loop(){
 
 /*Inicio dos Estados do motor A*/
 
 //Sentido Horario
 digitalWrite(IN1,HIGH);
 digitalWrite(IN2,LOW);
 delay(5000); 
 
 //Freia Motor
 digitalWrite(IN1,HIGH);
 digitalWrite(IN2,HIGH);
 delay(5000);
 
 //Sentido Anti-Horario
 digitalWrite(IN1,LOW);
 digitalWrite(IN2,HIGH);
 delay(5000);
 
 digitalWrite(IN1,HIGH);
 digitalWrite(IN2,HIGH);
 delay(5000);
 /*Fim dos Estados do motor A*/
 
 /*Inicio dos Estados do motor B*/
 
 //Sentido Horario
 digitalWrite(IN3,HIGH);
 digitalWrite(IN4,LOW);
 delay(5000); 
 
 //Freia Motor
 digitalWrite(IN3,HIGH);
 digitalWrite(IN4,HIGH);
 delay(5000);
 
 //Sentido Anti-Horario
 digitalWrite(IN3,LOW);
 digitalWrite(IN4,HIGH);
 delay(5000);
 

 digitalWrite(IN3,HIGH);
 digitalWrite(IN4,HIGH);
 delay(5000);
}
