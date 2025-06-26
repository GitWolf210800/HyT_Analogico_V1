void sensado() {
  if(millis()-tiempoUltimaLectura >30000){        
    h10=analogRead(HumedadSensor);
    t10=analogRead(TemperaturaSensor);
    
    if (isnan(h10) || isnan(t10) || h10>90 || t10<10){
      h10 = h9;
      t10 = h9;
    }
    tiempoUltimaLectura = millis(); //actualizamos el tiempo de la última lectura
  
    h=FCHfloat*(h1+h2+h3+h4+h5+h6+h7+h8+h9+h10)/10;
    t=FCTfloat*(t1+t2+t3+t4+t5+t6+t7+t8+t9+t10)/10;
    l1=0;
    l2=0;
    l3=0;
    l4=0;
    l5=0;
    l6=0;
    l7=0;
    l8=0;
    l9=0;
    Serial.print("h10: ");
    Serial.print(h10);
    Serial.print(", h: ");
    Serial.println(h);
    delay(100);
  }
  else if((millis()-tiempoUltimaLectura>27000)&&(l9==0)){    
    if (isnan(h9) || isnan(t9) || h9>90 || t9<10){
      h9 = h8;
      t9 = h8;
    }
    h9=analogRead(HumedadSensor);
    t9=analogRead(TemperaturaSensor);
    h=FCHfloat*(h1+h2+h3+h4+h5+h6+h7+h8+h9+h10)/10;
    t=FCTfloat*(t1+t2+t3+t4+t5+t6+t7+t8+t9+t10)/10;
    Serial.print("h9: ");
    Serial.print(h9);
    Serial.print(", h: ");
    Serial.println(h);
    l9=1;
    delay(100);
  }
  else if((millis()-tiempoUltimaLectura>24000)&&(l8==0)){
    if (isnan(h8) || isnan(t8) || h8>90 || t8<10){
      h8 = h7;
      t8 = h7;
    }    
    h8=analogRead(HumedadSensor);
    t8=analogRead(TemperaturaSensor);
    h=FCHfloat*(h1+h2+h3+h4+h5+h6+h7+h8+h9+h10)/10;
    t=FCTfloat*(t1+t2+t3+t4+t5+t6+t7+t8+t9+t10)/10;
    Serial.print("h8: ");
    Serial.print(h8);
    Serial.print(", h: ");
    Serial.println(h);
    l8=1;
    delay(100);
  }
  else if((millis()-tiempoUltimaLectura>21000)&&(l7==0)){
    if (isnan(h7) || isnan(t7) || h7>90 || t7<10){
      h7 = h6;
      t7 = h6;
    }    
    h7=analogRead(HumedadSensor);
    t7=analogRead(TemperaturaSensor);
    h=FCHfloat*(h1+h2+h3+h4+h5+h6+h7+h8+h9+h10)/10;
    t=FCTfloat*(t1+t2+t3+t4+t5+t6+t7+t8+t9+t10)/10;
    Serial.print("h7: ");
    Serial.print(h7);
    Serial.print(", h: ");
    Serial.println(h);
    l7=1;
    delay(100);
  }
  else if((millis()-tiempoUltimaLectura>18000)&&(l6==0)){
    if (isnan(h6) || isnan(t6) || h6>90 || t6<10){
      h6 = h5;
      t6 = h5;
    }    
    h6=analogRead(HumedadSensor);
    t6=analogRead(TemperaturaSensor);
    h=FCHfloat*(h1+h2+h3+h4+h5+h6+h7+h8+h9+h10)/10;
    t=FCTfloat*(t1+t2+t3+t4+t5+t6+t7+t8+t9+t10)/10;
    Serial.print("h6: ");
    Serial.print(h6);
    Serial.print(", h: ");
    Serial.println(h);
    l6=1;
    delay(100);
  }
  else if((millis()-tiempoUltimaLectura>15000)&&(l5==0)){
    if (isnan(h5) || isnan(t5) || h5>90 || t5<10){
      h5 = h4;
      t5 = h4;
    }    
    h5=analogRead(HumedadSensor);
    t5=analogRead(TemperaturaSensor);
    h=FCHfloat*(h1+h2+h3+h4+h5+h6+h7+h8+h9+h10)/10;
    t=FCTfloat*(t1+t2+t3+t4+t5+t6+t7+t8+t9+t10)/10;
    Serial.print("h5: ");
    Serial.print(h5);
    Serial.print(", h: ");
    Serial.println(h);
    l5=1;
    delay(100);
  }
  else if((millis()-tiempoUltimaLectura>12000)&&(l4==0)){
    if (isnan(h4) || isnan(t4) || h4>90 || t4<10){
      h4 = h3;
      t4 = h3;
    }    
    h4=analogRead(HumedadSensor);
    t4=analogRead(TemperaturaSensor);
    h=FCHfloat*(h1+h2+h3+h4+h5+h6+h7+h8+h9+h10)/10;
    t=FCTfloat*(t1+t2+t3+t4+t5+t6+t7+t8+t9+t10)/10;
    Serial.print("h4: ");
    Serial.print(h4);
    Serial.print(", h: ");
    Serial.println(h);
    l4=1;
    delay(100);
  }
  else if((millis()-tiempoUltimaLectura>9000)&&(l3==0)){
    if (isnan(h3) || isnan(t3) || h3>90 || t3<10){
      h3 = h2;
      t3 = h2;
    }    
    h3=analogRead(HumedadSensor);
    t3=analogRead(TemperaturaSensor);
    h=FCHfloat*(h1+h2+h3+h4+h5+h6+h7+h8+h9+h10)/10;
    t=FCTfloat*(t1+t2+t3+t4+t5+t6+t7+t8+t9+t10)/10;
    Serial.print("h3: ");
    Serial.print(h3);
    Serial.print(", h: ");
    Serial.println(h);
    l3=1;
    delay(100);
  }
  else if((millis()-tiempoUltimaLectura>6000)&&(l2==0)){
    if (isnan(h2) || isnan(t2) || h2>90 || t2<10){
      h2 = h1;
      t2 = h1;
    }    
    h2=analogRead(HumedadSensor);
    t2=analogRead(TemperaturaSensor);
    h=FCHfloat*(h1+h2+h3+h4+h5+h6+h7+h8+h9+h10)/10;
    t=FCTfloat*(t1+t2+t3+t4+t5+t6+t7+t8+t9+t10)/10;
    Serial.print("h2: ");
    Serial.print(h2);
    Serial.print(", h: ");
    Serial.println(h);
    l2=1;
    delay(100);
  }
  else if((millis()-tiempoUltimaLectura>3000)&&(l1==0)){
    if (isnan(h9) || isnan(t9) || h9>90 || t9<10){
      h1 = h10;
      t1 = h10;
    }    
    h1=analogRead(HumedadSensor);
    t1=analogRead(TemperaturaSensor);
    h=FCHfloat*(h1+h2+h3+h4+h5+h6+h7+h8+h9+h10)/10;
    t=FCTfloat*(t1+t2+t3+t4+t5+t6+t7+t8+t9+t10)/10;
    Serial.print("h1: ");
    Serial.print(h1);
    Serial.print(", h: ");
    Serial.println(h);
    l1=1;
    delay(100);
  }
}