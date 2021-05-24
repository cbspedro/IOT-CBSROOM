#include <Arduino_JSON.h>
#include <WiFiManager.h>
#include <HTTPClient.h>

// const variaveis 
WiFiClient wifiClient;
const int Power = 22;
const int ledconnect =  2;
const int luz = 13;
const int pc = 26;
const int fmonitor =27;
const int tomadas = 14;
String testluz;
String testpc;
String testmonitor;
String testtomadas;
void setup() {

  // pin mode 
    pinMode(ledconnect, OUTPUT);
    pinMode(luz, OUTPUT);
    pinMode(pc, OUTPUT);
    pinMode(fmonitor, OUTPUT);
    pinMode(tomadas, OUTPUT);
    WiFi.mode(WIFI_STA);
    Serial.begin(115200);
    WiFiManager wm;

    // set high

    digitalWrite(luz, HIGH);
    digitalWrite(pc, HIGH);
    digitalWrite(fmonitor, HIGH);
    digitalWrite(tomadas, HIGH);
    
    //reset settings - wipe credentials for testing
   // wm.resetSettings();
    bool res;
     res = wm.autoConnect("AutoConnectAP"); // anonymous ap
    //res = wm.autoConnect("AutoConnectAP","password"); // password protected ap

    if(!res) {
        Serial.println("Erro na conexão :(");
         ESP.restart();
    } 
    else {
        //if you get here you have connected to the WiFi    
        Serial.println("Conectadoo uhullll :)");
         digitalWrite(ledconnect, HIGH);
    }

}

void loop() {
    HTTPClient http;
    http.begin("https://wip.reino.cc/pedro/room/status.php");
    int httpResponseCode = http.GET();
    String Retorno_Funcoa_GET = "{}";
    if (httpResponseCode > 0) {
      Retorno_Funcoa_GET = http.getString();
    }
    else {
      Serial.print("Código de Erro HTTP: ");
      Serial.println(httpResponseCode);
    }
    http.end();
    JSONVar Objeto_Json = JSON.parse(Retorno_Funcoa_GET);

    //teste luz
    testluz = Objeto_Json["luz"];
    if (testluz == "1") {
      Serial.println("----------------------------------");
      Serial.println("luz Acesa");
      digitalWrite(luz, LOW);
    }
    if (testluz == "0") {
       Serial.println("----------------------------------");
      Serial.println("luz Apagada");
      digitalWrite(luz, HIGH);
    }

     //teste pc
    testpc = Objeto_Json["pc"];
    if (testpc == "1") {
      Serial.println("pc ligado");
      digitalWrite(pc, LOW);
    }
    if (testpc == "0") {
      Serial.println("pc desligado");
      digitalWrite(pc, HIGH);
    }

     //teste monitor
    testmonitor = Objeto_Json["monitor"];
    if (testmonitor == "1") {
      Serial.println("monitor ligado");
      digitalWrite(fmonitor, LOW);
    }
    if (testmonitor == "0") {
      Serial.println("monitor desligado");
      digitalWrite(fmonitor, HIGH);
    }

     //teste tomadas
    testtomadas = Objeto_Json["tomadas"];
    if (testtomadas == "1") {
      Serial.println("tomadas ligadas");
      digitalWrite(tomadas, LOW);
    }
    if (testtomadas == "0") {
      Serial.println("tomadas desligadas");
      digitalWrite(tomadas, HIGH);
    }
  }
