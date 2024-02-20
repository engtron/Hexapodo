void mover_Frente(){

Serial.println("mover_Frente n = 1"); 

/*
// motor 1 = ombro  direita ------------  = - para frente e + para tras
// motor 2 = cocha  --------------------  = + para cima e - para baixo
// motor 3 = pata ----------------------  = + para fora e - para dentro
*/


  //Impair Lift 10 deg  - indo para cima e dentro
  if (FM1 <=10){
    Leg1_Mot2.write(home_Leg1_Mot2 + FM1*2); 
    Leg1_Mot3.write(home_Leg1_Mot3 + FM1*2);
    Leg3_Mot2.write(home_Leg3_Mot2 + FM1*2); 
    Leg3_Mot3.write(home_Leg3_Mot3 + FM1*2);
    Leg5_Mot2.write(home_Leg5_Mot2 - FM1*2); 
    Leg5_Mot3.write(home_Leg5_Mot3 - FM1*2);
    FM1++;
  }  
    
  //Impair rote fwd 30 deg  -- indo para frente
  if (FM2 <= 30)
  {
    Leg1_Mot1.write(home_Leg1_Mot1 - FM2); 
    Leg3_Mot1.write(home_Leg3_Mot1 - FM2); 
    Leg5_Mot1.write(home_Leg5_Mot1 + FM2); 
    FM2++;
  }
  
  //Impair touch ground -10 deg  ---  indo para baixo
  if (FM2 > 20 && FM3 <=10){
    Leg1_Mot2.write(home_Leg1_Mot2 - FM3*2); 
    Leg1_Mot3.write(home_Leg1_Mot3 - FM3*2);
    Leg3_Mot2.write(home_Leg3_Mot2 - FM3*2); 
    Leg3_Mot3.write(home_Leg3_Mot3 - FM3*2);
    Leg5_Mot2.write(home_Leg5_Mot2 + FM3*2); 
    Leg5_Mot3.write(home_Leg5_Mot3 + FM3*2);
    FM3++;
  } 
  
  //Impair rotate bwd -30 deg  ---- para tras
  if (FM2 >= 30)
  {
    Leg1_Mot1.write(home_Leg1_Mot1 + FM4); 
    Leg3_Mot1.write(home_Leg3_Mot1 + FM4); 
    Leg5_Mot1.write(home_Leg5_Mot1 - FM4); 
    FM4++;
    Impair_start = true;
  }
  if(FM4 >= 30) {
    FM1 = 0;
    FM2 = 0;
    FM3 = 0;
    FM4 = 0;
  }
  
//////////////////////////////////
/*
// ombro primeira esquerda ---  = + para frente e - para tras
// cocha  --------------------  = - para cima e + para baixo
// pata ----------------------  = - para fora e + para dentro
*/

  if (Impair_start){
    //Pair Lift 10 deg - indo para cima e dentro
    if (FM5 <=10){
      Leg4_Mot2.write(home_Leg4_Mot2 - FM5*2); 
      Leg4_Mot3.write(home_Leg4_Mot3 - FM5*2);
      Leg6_Mot2.write(home_Leg6_Mot2 - FM5*2); 
      Leg6_Mot3.write(home_Leg6_Mot3 - FM5*2);
      Leg2_Mot2.write(home_Leg2_Mot2 + FM5*2); 
      Leg2_Mot3.write(home_Leg2_Mot3 + FM5*2);
      FM5++;
    }  
    //Pair rote fwd 30 deg -- indo para frente
    if (FM6 <= 30)
    {
      Leg4_Mot1.write(home_Leg4_Mot1 + FM6); 
      Leg6_Mot1.write(home_Leg6_Mot1 + FM6);
      Leg2_Mot1.write(home_Leg2_Mot1 - FM6);  
      FM6++;
    }
  
    //Pair touch ground -10 deg ---  indo para baixo
    if (FM6 > 20 && FM7 <=10){
      Leg4_Mot2.write(home_Leg4_Mot2 + FM7*2); 
      Leg4_Mot3.write(home_Leg4_Mot3 + FM7*2);
      Leg6_Mot2.write(home_Leg6_Mot2 + FM7*2); 
      Leg6_Mot3.write(home_Leg6_Mot3 + FM7*2);
      Leg2_Mot2.write(home_Leg2_Mot2 - FM7*2); 
      Leg2_Mot3.write(home_Leg2_Mot3 - FM7*2);
      FM7++;
    } 
  
    //Pair rotate bwd -30 deg  ---- para tras
    if (FM6 >= 30)
    {
      Leg4_Mot1.write(home_Leg4_Mot1 - FM8); 
      Leg6_Mot1.write(home_Leg6_Mot1 - FM8);
      Leg2_Mot1.write(home_Leg2_Mot1 + FM8);  
      FM8++;      
    }
    if(FM8 >= 30) {
      FM5 = 0;
      FM6 = 0;
      FM7 = 0;
      FM8 = 0;
    }    
  } 
}//End Rotate Right