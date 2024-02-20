void loop_org(){

/*A bateria está totalmente carregada em 12,6 V. 
Queremos habilitar o LED quando a bateria estiver 
abaixo de 8,5V. O divisor é 1k/3K então 0,33 * 8,5 = 2,83 volts -> em 10 bits = 580
  */

  if(analogRead(bat) < 580)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }

  
  if(bluetooth.available()>0)           //Se recebermos algo, entramos neste loop
  {
    Received = bluetooth.read();        //Armazenamos o número do byte recebido
    Serial.println(Received);         // Imprime para depuração..
   
    if (Received == 0)                  //Se recebermos o número "0", modo = 1
    {
      MODE = 0;              //Altera o modo para 0 (posição inicial)
      Impair_start = false;   //Redefinir variáveis  
      FM1 = 0;                //Reset values...
      FM2 = 0;                //Reset values...
      FM3 = 0;                //Reset values...
      FM4 = 0;                //Reset values...
      FM5 = 0;                //Reset values...
      FM6 = 0;                //Reset values...
      FM7 = 0;                //Reset values...
      FM8 = 0;                //Reset values...
    }
    if (Received == 1)        //Se recebermos um 1, mude o modo para 1 e assim por diante...
    {
      MODE = 1;
    }
    if (Received == 2)
    {
      MODE = 2;
    }
    if (Received == 3)
    {
      MODE = 3;
    }
    if (Received == 4)
    {
      MODE = 4;
    }
    if (Received == 5)
    {
      MODE = 5;
    }
    if (Received == 6)
    {
      MODE = 6;
    }
/*Se o número recebido for maior que 11, então recebemos os valores do controle deslizante, 
isso mudará a velocidade do movimento alterando o atraso do loop*/
    if (Received >= 12)
    {
      DELAY = map(Received,15,100,5,80); // Atraso do mapa de 5 a 80 ms
    }
   }

  

  //Home position
  if(MODE == 0){
    set_home_pos();
  }

  //Move Forward
  if(MODE == 1){
    move_frwd();
  }

  //Move Backwards
  if(MODE == 2){
    move_bwd();
  }
  
  //Move Right
  if(MODE == 3){
    move_right();
  }
   
  //Move Left
  if(MODE == 4){
    move_left();
  }

  //Rotate Left
  if(MODE == 5){
    rotate_left();
  }

  //Rotate Right
  if(MODE == 6){
    rotate_right();
  }
 
delay(DELAY);         //Adiciona delay do loop, isso vai controlar a velocidade
}



/////////////////////////////DEFINIR POSIÇÃO INICIAL
void set_home_pos()
{
  Leg1_Mot1.write(home_Leg1_Mot1); 
  Leg1_Mot2.write(home_Leg1_Mot2); 
  Leg1_Mot3.write(home_Leg1_Mot3); 

  Leg2_Mot1.write(home_Leg2_Mot1); 
  Leg2_Mot2.write(home_Leg2_Mot2); 
  Leg2_Mot3.write(home_Leg2_Mot3); 

  Leg3_Mot1.write(home_Leg3_Mot1); 
  Leg3_Mot2.write(home_Leg3_Mot2); 
  Leg3_Mot3.write(home_Leg3_Mot3); 

  Leg4_Mot1.write(home_Leg4_Mot1); 
  Leg4_Mot2.write(home_Leg4_Mot2); 
  Leg4_Mot3.write(home_Leg4_Mot3); 

  Leg5_Mot1.write(home_Leg5_Mot1); 
  Leg5_Mot2.write(home_Leg5_Mot2); 
  Leg5_Mot3.write(home_Leg5_Mot3); 

  Leg6_Mot1.write(home_Leg6_Mot1); 
  Leg6_Mot2.write(home_Leg6_Mot2); 
  Leg6_Mot3.write(home_Leg6_Mot3); 
}




/////////////////////////////MOVE FORWARD
void move_frwd(){
  mover_Frente();
}//End Move Forward


/////////////////////////////MOVE Backwards
void move_bwd(){ 
  mover_Tras();
}//End Move Backwards



/////////////////////////////Rotate Left
void rotate_left(){
  girar_Esquerda();
}//End Rotate Left


/////////////////////////////Rotate Right
void rotate_right(){ 
 girar_Direita();
}

/////////////////////////////Move Right
void move_right(){
  mover_Direita();

}

/////////////////////////////Move Left
void move_left(){
  mover_Esquerda();
}