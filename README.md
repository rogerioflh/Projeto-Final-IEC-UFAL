# Projeto de Manipualação de Objetos com Braço Robótico

## Descrição:

O projeto consiste na manipulação de objetos utilizando um braço robótico com 4 eixos, onde o mesmo executaria movimentos simples de pegar, mover, largar o objeto e repetir o processo.
Como materias, foram utilizados:
- 1 - Arduino Uno;
- 4 - Servo morotes MG90S;
- 1 - Capacitor eletrolítico 16 V 220uF;
- 1 - Protoboard;
- 1 - Kit de Jumpers;
- 1 - Base de Madeira 27x27cm;
- 1 - Kit de braço robótico de acrílico;

## Observações:

1. Mesmo usando um capacitor para filtar a corrente e diminuir a trepidação, os servos motores ainda apresentavam instabilidade na hora de realizar os movimentos.
2. A ideia inicial era que o usuário setasse os posições manualmente para cada um dos servos motores, e após isso, o braço entraria em um loop, onde ele iria automaticamente para as posições pre definidas.
3. Como os servos motores recebem apenas um pulso PWM, ao setar as posições diretamente, os servos acabavam avançando abruptamente, o que fazia com que eles perdessem a posição ou simplesmente derrubassem o objeto ao avançarem para agarra-lo.
4. Uma das maneiras idealizadas para resolver esse problema foi colocar cada valor dentro de um laço **for**, onde os servos iam avançando grau a grau, suavemente, para evitar os tipos de situações antes mencionadas.

## Instalação:

1. Clone o repositório  `git clone https://github.com/rogerioflh/Projeto-Final-IEC-UFAL.git`.
2. Navegue até o arquivo `cd Projeto-Final-IEC-UFAL/sketch-braco-iec-v1` e execute o código em sua IDE do Arduino.
3. Para mais dúvidas, consulte o arquivo `RELATÓRIO BRAÇO ROBÓTICO - PROJETO FINAL IEC - IC-UFAL - PROF THIAGO CORDEIRO`.
