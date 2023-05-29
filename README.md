# ESP8266 + WiFi + P10 Panel
-> Esp8266 ile WiFi üzerinden P10 LED Panel üzerindeki yazıyı değiştirme
\n
--> MALZEMELER <-- \n
-ESP8266\n
-P10 PANEL\n
-Adaptör 5V-1A\n

--> KURULUM <--\n

-> Arduino IDE 1.8.19 sürümünü kullandım, 2.1.0 sürümünde sketch yüklerken sıkıntı ile karşılaştım.\n

-> https://www.arduino.cc/en/software bu sayfadan Arduino IDE 1.8.x sürümünü indirebilirsiniz.\n

-> ESP8266 kartı ile P10 panel'in çalışması için gerekli kütüphaneleri içeren bu repo'yu https://github.com/busel7/DMDESP indirin.\n
-> Bilgisayarınızda belgeler/arduino/libraries bölümüne gidin. Bu klasörün içerisine indirdiğiniz repo'nun hepsini kopyalayın. Arduino'yu yeniden başlatmanız gerekebilir.\n

-> P10 Panelin arka tarafında bulunan pinleri ESP8266 kartına bağlamak için yukarıda verdiğim repoyu inceleyebilirsiniz.\n
-> Yine o repo'dan kabloların bağlandığı ekran görüntüsü https://github.com/busel7/DMDESP/blob/master/wiring.jpg\n
-> PinMode ile pin tanımlamaya gerek yok çünkü dmdesp kütüphanesi zaten bunu yapmış. Resimdeki gibi kabloları bağlarsanız doğru şekilde çalışacaktır.\n

-> Arduino IDE'yi açın. Şimdi Esp8266 kartını Arduino'ya tanıtalım. Üst menüden Dosya -> Tercihler'e tıklayın. Açılan Tercihler penceresinde "Ek Devre Kartları Yöneticisi URL'leri" yerine http://arduino.esp8266.com/stable/package_esp8266com_index.json bu linki yapıştırın. Tamam'a basıp çıkın.\n
-> Yine üst menüden Araçlar -> Kart -> Kart Yöneticisi butonuna tıklayın. Açılan "Kart Yöneticisi" penceresinde arama yerine "esp8266" yazarak gerekli kütüphaneyi kurun.\n
-> Tekrardan Araçlar -> Kart bölümüne geldiğinizde ESP8266 BOARDS butonunu göreceksiniz, ESP8266 BOARDS butonuna tıklayın. Uygun kartı seçin. Benim kartım NodeMCU 1.0 ESP-12E MODULE olduğu için onu seçtim.\n

-> Html sayfasını ESP8266'nın içerisine yüklemek için https://github.com/esp8266/arduino-esp8266fs-plugin/releases/tag/0.5.0 bu plugin'e ihtiyacımız var.\n
-> ESP8266FS-0.5.0.zip'i indirip içerisindeki ESP8266FS dosyasını belgeler/arduino/tools bölümüne kopyalamanız lazım. belgeler/arduino klasörü içerisinde tools klasörü yok ise oluşturup zip'ten çıkardığınız klasörü yapıştırın. Arduino'yu yeniden başlatmanız gerekebilir.\n

-> Plugin'i kurduktan sonra Araçlar üst menüsüne geldiğinizde "ESP8266 Sketch Data Upload" adında bir buton görünüyor olması lazım. Bu html sayfamızı yüklemek için kullanacağımız buton olacak.\n
-> Bu repo içerisindeki esp_p10 klasörünü masaüstüne taşıyın. Ardından içerisinde bulunan esp_p10.ino dosyasını Arduino ile açın. Arduino IDE içerisinde Taslak -> Çalışma Klasörünü Göster dediğinizde sizi esp_p10 klasörüne yönlendirmesi gerekiyor.\n
-> Kartınızı usb ile bilgisayarınıza bağlayın, bulunduğu COM'u seçin. Üst menüde Araçlar'a gelin. Ardından "ESP8266 Sketch Data Upload" butonuna tıklayın, data klasöründe bulunan html sayfası ESP8266'nın içerisine yüklenecektir.\n
-> Son olarak esp_p10.ino içerisindeki kodları karta yükleyin.\n

-> Telefon veya Laptop ile Wi-Fi kısmına gelip kartın adını bulun, "ESP_Erişim_Noktası". Ardından şifreyi girin: 12345678!\n
-> Bir tarayıcı açıp adres satırına 192.168.4.1/ yazın bu sizi direk index.html sayfasına yönlendirecektir. html'de input alanına istediğiniz kelimeyi veya cümleyi yazıp test edin.\n
-> IP adresi kartınızda farklı olabilir bunun için seri port ekranında dinleme yapabilirsiniz.\n

--> PROBLEMLER <--\n

X - Türkçe karakterlerle alakalı sorun yaşanıyor, ı,ğ,ü,ş,ö,ç gibi.\n
? - Olası çözüm font dosyaları ile alakalı olmalı. C dili ve hexadecimal ile yazıldığı için pek uğraşmak istemedim.\n

X - Tek bir model var o da sağdan sola kayma.\n
? - Olası çözüm panel setup tarzı uygulamalar olabilir.\n
