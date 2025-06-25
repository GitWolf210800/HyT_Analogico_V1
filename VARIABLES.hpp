String strlectura;
String payload;

String calibracion_recepcion;
String calibracion;
float valor_calibracion_temp;
float valor_calibracion_hum;
String FCHstring;
String FCTstring;
char FCHchar[20];
char FCTchar[20];
float FCTfloat =  1;
float FCHfloat =  1;
float fac_calTemp_server;
float fac_calHum_server;
/*char FCH1char[20];
  char FCT1char[20];
*/

/*String hum_realstring;
  String tem_realstring;


  float FCH1float;
  float FCT1float;
  float FCH2float;
  float FCT2float;
  float hum_realfloat;
  float tem_realfloat;
*/

int turno;
//const char* ssid = "AP_Arduino-F601";
bool j = 0;
long m = 0;
float presion;
float hu;
float te;
float h;
float t;
float h1;
float t1;
float h2;
float t2;
float h3;
float t3;
float h4;
float t4;
float h5;
float t5;
float h6;
float t6;
float h7;
float t7;
float h8;
float t8;
float h9;
float t9;
float h10;
float t10;
bool l1 = 0;
bool l2 = 0;
bool l3 = 0;
bool l4 = 0;
bool l5 = 0;
bool l6 = 0;
bool l7 = 0;
bool l8 = 0;
bool l9 = 0;
int hr;
int mn;
int sg;
int di;
int me;
int an;
float FCt = 1;
float FCh = 1;
long tm = 1; //tiempo de muestreo entre cada registro
long tiempoUltimaLectura = 0; //Para guardar el tiempo de la última lectura
int idmq = 700;
const char* idtm = "Tttal";
const char* idhm = "Hola";
char filereg [] = "/registros.txt";
char fileCal [] = "/calibradoHist.txt";
String temper = "nop";
String humed = "nop";
String MAC = "AAA";

String jsonMqtt;
unsigned long tempMQTT;
unsigned long tiempoMQTT = 1000;