//Kayan Yazı Kodları
#include <DMDESP.h>

//font değiştirmek için buraya font'un dosya adını girin
#include <fonts/DejaVuSans9.h>


//Dikeyde ve yatayda kaç paneliniz var ise buraya onu girin. Sadece 1 panel olduğu için 1-1 girdim.
#define DISPLAYS_WIDE 1
#define DISPLAYS_HIGH 1
DMDESP Disp(DISPLAYS_WIDE, DISPLAYS_HIGH);
String text = "Bekleniyor";
//Kayan Yazı Kodları

//yeni yazı geldiğinde ekranı yenilemek için bir değişken
static bool restart = false;

//Wifi Kodları
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FS.h>
const char* ssid = "ESP_Erişim_Noktası";
const char* password = "12345678!";
ESP8266WebServer server(80);
//Wifi Kodları

void setup() {
  //Wifi Kodları
  Serial.begin(115200);

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  if (!SPIFFS.begin()) {
    Serial.println("SPIFFS dosya sistemi baslatilamadi!");
    while (1);
  }

  //index.html'i yüklüyoruz
  server.on("/", handleRoot);

  //css dosyasını yüklüyoruz.
  server.on("/css/main.css", handleCss);

  //resimleri yüklüyoruz
  server.on("/imgs/zzzriot.jpg", handleImage1);
  
  // /submit işlemi yapıldığında handleForm fonksiyonunu çağırıyoruz
  server.on("/submit", HTTP_POST, handleForm);

  //server'ı başlatıyoruz.
  server.begin();

  Serial.print("Erisim Noktasi Adi: ");
  Serial.println(ssid);
  Serial.print("IP Adresi: ");
  Serial.println(WiFi.softAPIP());
  //Wifi Kodları
  
  //Kayan Yazı Kodları
  Disp.start();
  Disp.setBrightness(30);
  Disp.setFont(DejaVuSans9);
  //Kayan Yazı Kodları
}

void loop() {
  //Wifi kodları
  server.handleClient();
  //Wifi kodları

  if(restart){
    Disp.refresh();
    Disp.swapBuffersAndCopy();
  }
  
  Disp.loop();
  
  //1.parametre y ekseni uzaklığı, 2. parametre kayma hızı.
  displayLoopLed(4,50);
  
  //Disp.drawText(0, 0, text);
}

//Kayan Yazı Kodları
void displayLoopLed(int yUzaklik, int kaymaHizi) {
  kayanYazi(yUzaklik, kaymaHizi);
}

void kayanYazi(int y, uint8_t kp) {
  static uint32_t pM;
  static uint32_t x;
  int width = Disp.width();

  char charArray[text.length() + 1];
  text.toCharArray(charArray, text.length() + 1);
  //Kayma işlemi için String'i Char dizisine çeviriyoruz.
  const char *textToChar = charArray;
  
  int fullScroll = Disp.textWidth(textToChar) + width;
  if((millis() - pM) > kp) { 
    pM = millis();
    if (x < fullScroll) {
      ++x;
    } else {
      x = 0;
      return;
    }
    Disp.drawText(width - x, y, textToChar);
  }  
}
//Kayan Yazı Kodları

//Wifi kodları
void handleForm() {

  //Yazdır butonuna basıldığında input içerisindeki veriyi alıp
  //ekranı yeniliyoruz.
  
  if (server.hasArg("input_text")) {
    String inputTextValue = server.arg("input_text");
    // input_text içerisindeki veriyi alın
    // istediğiniz işlemleri gerçekleştirin

    /*
    Serial.println(inputTextValue);
    */
    
    text = inputTextValue;
    restart = true;
    
  }
  //server.sendHeader("Location", "/"); // Başka sunucuya yönlendirme
  //server.send(302); // 302 Kodu: Yönlendirme işlemi

  server.send(200);
}

void handleRoot() {
  File file = SPIFFS.open("/index.html", "r");
  if (!file) {
    Serial.println("index.html dosyasi bulunamadi!");
    return;
  }

  server.streamFile(file, "text/html");
  file.close();
}
void handleCss() {
  File file = SPIFFS.open("/css/main.css", "r");
  if (!file) {
    Serial.println("main.css dosyası bulunamadı!");
    return;
  }
  
  server.streamFile(file, "text/css");
  file.close();
}

void handleImage1() {
  String contentType = "image/jpeg";
  String path = "/imgs/zzzriot.jpg";

  if (SPIFFS.exists(path)) {
    File file = SPIFFS.open(path, "r");
    server.streamFile(file, contentType);
    file.close();
  }
}
//Wifi kodları
