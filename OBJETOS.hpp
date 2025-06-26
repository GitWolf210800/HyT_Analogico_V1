WiFiClient espClient; //objetos para la gestión del MQTT
HTTPClient http_client;
PubSubClient client(espClient); //objetos para la gestión del MQTT

WebServer server(80); //objeto para la gestion de la página web

File myDataFile;
File configFile;
File calibradoFile;

//SSD1306Wire  display(0x3c, D2, D1);  //D2=SDK  D1=SCK  As per labeling on NodeMCU
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

const int timeZone = -3;

WiFiUDP Udp;
unsigned int localPort = 8888;  // local port to listen for UDP packets
time_t prevDisplay = 0;
