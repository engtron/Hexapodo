/* Hexapod robot code for Arduino MEGA Electronoobs 25/04/2020
 * Tutorial: https://electronoobs.com/eng_robotica_tut17.php
 * Schematic: https://electronoobs.com/eng_robotica_tut17_sch1.php
 * Code: https://electronoobs.com/eng_robotica_tut17_code1.php
 * 3D files: https://electronoobs.com/eng_robotica_tut17_stl1.php
 * Video: https://www.youtube.com/watch?v=HRC5HrN8KD0
*/


#include <SoftwareSerial.h>      // Usamos serial de software nos pinos D12 e D8 para HC06
SoftwareSerial bluetooth(12, 9);  // Arduino RX 12 e TX 9 -> HC-06 Bluetooth TX RX
#include <Servo.h>               //Usaremos a biblioteca servo


//Variables
int Received = 0;             //aqui armazenamos o número do byte recebido do Bluetooth
int DELAY = 5;                //Atraso em ms para o loop principal, quanto maior, mais lento o movimento do robô
int MODE = 0;                 //O modo de partida é 0, então todos os motores -> posição inicial
bool Impair_start = false;    //Para adicionar rotação de fase entre as pernas, usamos esta variável
int FM1 = 0;                  //O loop de movimento da perna tem diferentes estágios
int FM2 = 0;                  //Cada uma dessas variáveis ​​será usada nessas etapas
int FM3 = 0;                  //Usamos estes como contadores para contar graus
int FM4 = 0;                  //...
int FM5 = 0;                  //...
int FM6 = 0;                  //...
int FM7 = 0;                  //...
int FM8 = 0;                  //...

int alt = 0;



/*/////////////////Posição inicial inicial em graus////////////////// 
A primeira perna é a perna dianteira esquerda visto de frente O primeiro motor
 de cada perna é o mais próximo do corpo do robô*/

int home_Leg1_Mot1 = 30;//Ombro 75      Primeira Direita
int home_Leg1_Mot2 = 130;//Coxa 90   
int home_Leg1_Mot3 = 130;//Pata 100  

int home_Leg2_Mot1 = 100;//Ombro 70      Segunda Direita
int home_Leg2_Mot2 = 130;//Coxa 90
int home_Leg2_Mot3 = 130;//Pata      

int home_Leg3_Mot1 = 130;//Ombro 70     Ultima Direita
int home_Leg3_Mot2 = 130;//Coxa 90
int home_Leg3_Mot3 = 130;//Pata  100



int home_Leg4_Mot1 = 145;//Ombro 105     Primeira Esquerda
int home_Leg4_Mot2 = 50;//Coxa 90     
int home_Leg4_Mot3 = 30;//Pata 110     

int home_Leg5_Mot1 = 90;//Ombro 75      Segunda Esquerda
int home_Leg5_Mot2 = 50;//Coxa 90
int home_Leg5_Mot3 = 30;//Pata 90     

int home_Leg6_Mot1 = 40;//Ombro 110      Ultima Esquerda
int home_Leg6_Mot2 = 50;//Coxa 100
int home_Leg6_Mot3 = 50;//Pata 115    

/*/////////////////////////////////////////////////////////////////*/

//fazer um if else aqui

/*//////////////////////Declare the Servos/////////////////////////*/
Servo Leg1_Mot1, Leg1_Mot2, Leg1_Mot3;    //Motors 1,2 and 3 of leg 1
Servo Leg2_Mot1, Leg2_Mot2, Leg2_Mot3;    //Motors 1,2 and 3 of leg 2 
Servo Leg3_Mot1, Leg3_Mot2, Leg3_Mot3;    //Motors 1,2 and 3 of leg 3 
Servo Leg4_Mot1, Leg4_Mot2, Leg4_Mot3;    //Motors 1,2 and 3 of leg 4 
Servo Leg5_Mot1, Leg5_Mot2, Leg5_Mot3;    //Motors 1,2 and 3 of leg 5 
Servo Leg6_Mot1, Leg6_Mot2, Leg6_Mot3;    //Motors 1,2 and 3 of leg 6 
int LED = 17;
int bat = A1;
/*/////////////////////////////////////////////////////////////////*/ 


void setup() {
  setup_org();
}

void loop() {
  loop_org();

}
