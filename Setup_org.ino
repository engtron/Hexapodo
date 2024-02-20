void setup_org(){

  Serial.begin(9600);     // Usamos o monitopr do Arduino para depuração...
  bluetooth.begin(9600);  // Minha taxa de transmissão padrão do HC06, a sua pode ser diferente
  pinMode(LED, OUTPUT);
  pinMode(bat, INPUT);
  digitalWrite(LED, LOW);

  Serial.println("Lincoln");

  
  //Selecione os pinos digitais do MEGA para cada moto "12 e a 9 Bluetooth" - nao funciona estas portas corretamente 23 24 26 27 28 ------

// ------ Lado Direito -----
  Leg1_Mot1.attach(13);// ombro Primeira direita  ---  = - para frente e + para tras
  Leg1_Mot2.attach(11);// cocha  --------------------  = + para cima e - para baixo
  Leg1_Mot3.attach(10);// pata ----------------------  = + para fora e - para dentro

  Leg2_Mot1.attach(8);// ombro Segunda direita
  Leg2_Mot2.attach(7);// cocha
  Leg2_Mot3.attach(6);// pata

  Leg3_Mot1.attach(5);// ombro Terceira direita
  Leg3_Mot2.attach(4);// cocha
  Leg3_Mot3.attach(3);// pata

// ---- Lado Esquerdo -----
  Leg4_Mot1.attach(22);// ombro primeira esquerda ---  = + para frente e - para tras
  Leg4_Mot2.attach(25);// cocha  --------------------  = - para cima e + para baixo
  Leg4_Mot3.attach(29);// pata ----------------------  = - para fora e + para dentro

  Leg5_Mot1.attach(30);// ombro segunda esquerda
  Leg5_Mot2.attach(31);// cocha 
  Leg5_Mot3.attach(32);// pata

  Leg6_Mot1.attach(33); // ombro terceira esquerda
  Leg6_Mot2.attach(34); // cocha
  Leg6_Mot3.attach(35); // pata
  /*/////////////////////////////////////////////////////////////////*/ 
  
  set_home_pos();       //Iniciar todos os motores
}