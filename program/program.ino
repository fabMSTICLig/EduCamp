#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <Servo.h> 
#include <Adafruit_NeoPixel.h>
#include <index.h>


/* Set these to your desired credentials. */
const char *ssid = "Amirobot";
const char *password = "Amirobot++";

ESP8266WebServer server(80);

Servo myservoL; 
Servo myservoR; 

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, D3, NEO_GRB + NEO_KHZ800);

void handleRoot() {
  server.send(200, "text/html", MAIN_page);
}

  
void ron() {
  server.send(200, "text/html", "<h1>Right on</h1>");
myservoR.write(10); 
}
void rron() {
  server.send(200, "text/html", "<h1>Right on</h1>");
myservoR.write(170); 
}
void roff() {
  server.send(200, "text/html", "<h1>Right off</h1>");
myservoR.write(90); 
}
void lon() {
  server.send(200, "text/html", "<h1>Left on</h1>");
myservoL.write(170); 
}
void lron() {
  server.send(200, "text/html", "<h1>Left on</h1>");
myservoL.write(10); 
}
void loff() {
  server.send(200, "text/html", "<h1>Left off</h1>");
myservoL.write(90); 
}

void setup() {
myservoL.attach(D1);; 
myservoR.attach(D2);
myservoL.write(90); 
myservoR.write(90); 

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.on("/ron", ron);
  server.on("/rron", rron);
  server.on("/roff", roff);
  server.on("/lon", lon);
  server.on("/lron", lron);
  server.on("/loff", loff);
  server.begin();
  Serial.println("HTTP server started");
}
int cycle=0;
void loop() {
  server.handleClient();
  cycle++;
  switch(cycle){
    case 1 : strip.setPixelColor(0, strip.Color(100, 0, 0)); strip.show();
    break;
    case 50 : strip.setPixelColor(0, strip.Color(0, 100, 0)); strip.show();
    break;
    case 100 : strip.setPixelColor(0, strip.Color(0, 0, 100)); strip.show();
    break;
    case 150 : cycle=0;
    break;
  }    
  delay(10);
}
