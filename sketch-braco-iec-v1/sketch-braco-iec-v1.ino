#include <Servo.h>

// Criação dos objetos Servo
Servo servoBase;
Servo servoBraco1;
Servo servoBraco2;
Servo servoGarra;

// Pinos de conexão dos servos
const int pinBase = 3;
const int pinBraco1 = 5;
const int pinBraco2 = 6;
const int pinGarra = 9;

// Variáveis para as posições dos servos
int posBase = 90;
int posBraco1 = 90;
int posBraco2 = 90;
int posGarra = 90;

void setup() {
  // Inicialização dos servos
  servoBase.attach(pinBase);
  servoBraco1.attach(pinBraco1);
  servoBraco2.attach(pinBraco2);
  servoGarra.attach(pinGarra);

  // Comunicação serial para controle e monitoramento
  Serial.begin(9600);

  // Inicializa os servos em suas posições iniciais
  servoBase.write(posBase);
  servoBraco1.write(posBraco1);
  servoBraco2.write(posBraco2);
  servoGarra.write(posGarra);

  Serial.println("Controle de 4 servos inicializado.");
  Serial.println("Comandos: base:<angulo>, braco1:<angulo>, braco2:<angulo>, garra:<angulo>");
}

void loop() {
  // Monitora a entrada via Serial para atualizar as posições dos servos
  if (Serial.available() > 0) {
    // Lê o comando enviado
    String comando = Serial.readStringUntil('\n');
    comando.trim(); // Remove espaços extras ou quebras de linha

    // Processa o comando para cada servo
    if (comando.startsWith("base:")) {
      posBase = comando.substring(5).toInt();
      if (posBase >= 0 && posBase <= 180) {
        servoBase.write(posBase);
        Serial.print("Base ajustada para: ");
        Serial.println(posBase);
      } else {
        Serial.println("Erro: Posicao da Base invalida. Informe entre 0 e 180.");
      }
    } else if (comando.startsWith("braco1:")) {
      posBraco1 = comando.substring(7).toInt();
      if (posBraco1 >= 0 && posBraco1 <= 180) {
        servoBraco1.write(posBraco1);
        Serial.print("Braco1 ajustado para: ");
        Serial.println(posBraco1);
      } else {
        Serial.println("Erro: Posicao do Braco1 invalida. Informe entre 0 e 180.");
      }
    } else if (comando.startsWith("braco2:")) {
      posBraco2 = comando.substring(7).toInt();
      if (posBraco2 >= 0 && posBraco2 <= 180) {
        servoBraco2.write(posBraco2);
        Serial.print("Braco2 ajustado para: ");
        Serial.println(posBraco2);
      } else {
        Serial.println("Erro: Posicao do Braco2 invalida. Informe entre 0 e 180.");
      }
    } else if (comando.startsWith("garra:")) {
      posGarra = comando.substring(6).toInt();
      if (posGarra >= 0 && posGarra <= 180) {
        servoGarra.write(posGarra);
        Serial.print("Garra ajustada para: ");
        Serial.println(posGarra);
      } else {
        Serial.println("Erro: Posicao da Garra invalida. Informe entre 0 e 180.");
      }
    } else {
      Serial.println("Comando invalido. Use: base:<angulo>, braco1:<angulo>, braco2:<angulo>, garra:<angulo>");
    }
  }

  // Pausa para estabilidade
  delay(1000);
}
