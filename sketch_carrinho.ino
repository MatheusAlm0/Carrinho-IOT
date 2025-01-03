int ENA = 10; 
int IN1 = 9; 
int IN2 = 8; 
int IN3 = 7; 
int IN4 = 6; 
int ENB = 5; 
char direcao;
void setup() {
  Serial.begin(9600); 
  Serial.println("-- CONTROLE DE MOTORES DC COM DRIVER PONTE H L298N --");
  Serial.println("Digite: \n 1: para ligar os motores em uma direcao;\n 2: para mudar a direção; \n Qualquer outro valor: para parar os motores");
  pinMode(ENA, OUTPUT); 
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT); 
  pinMode(ENB, OUTPUT); 
}
void loop() {
  if (Serial.available()) { 
    direcao = Serial.read(); 
    Serial.println(direcao); 
    switch (direcao) {
      case '1': 
        ligar(); 
         Serial.println("andar");
        break;
      case '2': 
        mudar(); 
        Serial.println("mudar");
        break;
      default:  
        parar(); 
        Serial.println("parar");
        break;
    }
  }
}
void ligar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
 
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  delay(5000);
}
void mudar() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  delay(5000);
}
void parar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(1000);
}
