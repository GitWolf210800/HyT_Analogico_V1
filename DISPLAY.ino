void drawTem() {
  // clear the display
  char tem[5];
  dtostrf(t, 3, 1, tem);
  u8g2.clearBuffer();          // clear the internal memory
  u8g2.setFont(u8g2_font_logisoso24_tr); // choose a suitable font
  u8g2.drawStr(0,55,"T:");  // write something to the internal memory
  u8g2.setFont(u8g2_font_logisoso42_tr); // choose a suitable font
  u8g2.drawStr(22,55,tem);  // write something to the internal memory
  u8g2.setFont(u8g2_font_logisoso24_tr); // choose a suitable font
  u8g2.drawStr(115,55,"°C");  // write something to the internal memory
  u8g2.sendBuffer();          // transfer internal memory to the display
  }
 void drawHum() {
  // clear the display
  char hum[5];
  dtostrf(h, 3, 1, hum);
  u8g2.clearBuffer();          // clear the internal memory
  u8g2.setFont(u8g2_font_logisoso24_tr); // choose a suitable font
  u8g2.drawStr(0,55,"H:");  // write something to the internal memory
  u8g2.setFont(u8g2_font_logisoso42_tr); // choose a suitable font
  u8g2.drawStr(22,55,hum);  // write something to the internal memory
  u8g2.setFont(u8g2_font_logisoso24_tr); // choose a suitable font
  u8g2.drawStr(115,57,"%");  // write something to the internal memory
  u8g2.sendBuffer();  
  }
