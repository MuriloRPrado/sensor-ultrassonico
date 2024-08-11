#define trigger 2                                                   // pino que dispara os pulsos
#define echo 3                                                      // pino de leitura do sensor
#define som 7                                                       // pino do buzzer
#define led1 9                                                      // pino do LED
#define led2 10                                                     // pino do LED

float tEcho = 0;                                                    // variável tempo do eco
const float velSom_mpus = 0.000340;                                 // velocidade em metros por microssegundos

void setup() {

  pinMode(trigger, OUTPUT);
  digitalWrite(trigger, LOW);
  pinMode(echo, INPUT);
  pinMode(som, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);                                               // inicializar o monitor serial
  delay(100);

}

void loop() {

  disparaPulso();                                                   // dispara pulso

  tEcho = pulseIn(echo, HIGH);                                      // mede a duração do pulso HIGH de eco em microssegundos

  Serial.print("Distancia em metros: ");
  Serial.println(calDistancia(tEcho));                              // reflete o cálculo da distância em metros

  Serial.print("Distancia em centimentros: ");
  Serial.println(calDistancia(tEcho) * 100);                        // reflete cálculo da distância em centimetros
 
  delay(500);

  if((calDistancia(tEcho) * 100) <= 10){

    somDisparado();
    ligaLed();

  }
  else{
    desligaLed();

  }
  
}

// Função que dispara os pulsos
void disparaPulso(){

  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
}

// Função que calcula a distância em metros
float calDistancia(float temp_us){

  return ((temp_us * velSom_mpus) / 2);
}

// Função que emite o som no buzzer
void somDisparado(){

  tone(som, 494, 250);
  
}

// Função que liga os LEDs
void ligaLed(){

  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);

}

// Funcção que desliga os LEDs
void desligaLed(){

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);

}