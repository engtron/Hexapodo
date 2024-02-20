void mover_Direita(){

Serial.println("mover_direita n = 3");

// motor 1 = ombro  direita ------------  = - para frente e + para tras
// motor 2 = cocha  --------------------  = + para cima e - para baixo
// motor 3 = pata ----------------------  = + para fora e - para dentro

  //Impair Motor 2 -20 Motor 3 +20
  if (FM1 <= 20){    
    Leg1_Mot2.write(home_Leg1_Mot2 + FM1); 
    Leg1_Mot3.write(home_Leg1_Mot3 + FM1*2); 

    Leg2_Mot2.write(home_Leg2_Mot2 - FM1); 
    Leg2_Mot3.write(home_Leg2_Mot3 - FM1*2);

    Leg3_Mot2.write(home_Leg3_Mot2 + FM1);     
    Leg3_Mot3.write(home_Leg3_Mot3 + FM1*2); 
  
 

    Leg4_Mot2.write(home_Leg4_Mot2 + FM1); 
    Leg4_Mot3.write(home_Leg4_Mot3 - FM1*2);
    
    Leg5_Mot2.write(home_Leg5_Mot2 - FM1/2 );     
    Leg5_Mot3.write(home_Leg5_Mot3 + FM1*2); 

    Leg6_Mot2.write(home_Leg6_Mot2 + FM1/2); 
    Leg6_Mot3.write(home_Leg6_Mot3 - FM1*2);  
    FM1++;
  }  

  if(FM1 >= 20 && FM2 <= 20){

     Leg4_Mot2.write(home_Leg4_Mot2 - FM1  );// 
     Leg4_Mot3.write(home_Leg4_Mot3 + FM1*2 );//- FM2*2

     Leg2_Mot2.write(home_Leg2_Mot2 + FM1 );//+ FM2 
     Leg2_Mot3.write(home_Leg2_Mot3 - FM1*2 );//+ FM2*2

     Leg6_Mot2.write(home_Leg6_Mot2 - FM1 ); //  + FM2
     Leg6_Mot3.write(home_Leg6_Mot3 + FM1*2 );//- FM2*2
     FM2++;
  }

   if(FM2 >= 20 && FM3 <= 20){
    Leg1_Mot2.write(home_Leg1_Mot2 - FM1 ); //- FM1
    Leg1_Mot3.write(home_Leg1_Mot3 - FM1*2 );//- FM1 

    Leg5_Mot2.write(home_Leg5_Mot2 + FM1 );   // - FM3  
    Leg5_Mot3.write(home_Leg5_Mot3 - FM1*2 ); // - FM3
            
    Leg3_Mot2.write(home_Leg3_Mot2 - FM1); //- FM3    
    Leg3_Mot3.write(home_Leg3_Mot3 - FM1*2); // - FM3

    

  
    FM3++;
  }

  if(FM3 >= 20){
    FM1 = 0;
    FM2 = 0;
    FM3 = 0;
  }

}