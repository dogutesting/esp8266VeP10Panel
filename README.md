# NodeMCU ESP8266 + WiFi + P10 Panel
<h2>NodeMCU Esp8266 ile WiFi üzerinden P10 LED Panel üzerindeki yazıyı değiştirme</h2> <br />
<b>Video:</b> <br>

https://github.com/dogutesting/esp8266VeP10Panel/assets/80362520/b0f4d939-fdf4-45e9-a022-9b8e50bc3e9d

<br/>

<h3> --> MALZEMELER <-- <h3>
<ul>
  <li>NodeMCU ESP8266</li>
  <li>P10 PANEL</li>
  <li>Adaptör 5V-1A</li>
</ul>
<br/>
<h3>--> KURULUM <--</h3><br/>
<br/>
-> Arduino IDE 1.8.19 sürümünü kullandım, 2.1.0 sürümünde sketch yüklerken sıkıntı ile karşılaştım.<br/>
<br/>
-> https://www.arduino.cc/en/software bu sayfadan Arduino IDE 1.8.x sürümünü indirebilirsiniz.<br/>
<br/>
-> ESP8266 kartı ile P10 panel'in çalışması için gerekli kütüphaneleri içeren bu repo'yu https://github.com/busel7/DMDESP indirin.<br/>
-> Bilgisayarınızda belgeler/arduino/libraries bölümüne gidin. Bu klasörün içerisine indirdiğiniz repo'nun hepsini kopyalayın. Arduino'yu yeniden başlatmanız gerekebilir.<br/>
<br/>
-> P10 Panelin arka tarafında bulunan pinleri ESP8266 kartına bağlamak için yukarıda verdiğim repoyu inceleyebilirsiniz.<br/>
-> Yine o repo'dan kabloların bağlandığı ekran görüntüsü https://github.com/busel7/DMDESP/blob/master/wiring.jpg <br/><br/>
<table>
<thead>
<tr>
<th>DMD P10</th>
<th>NODEMCU</th>
</tr>
</thead>
<tbody>
<tr>
<td>A</td>
<td>D0</td>
</tr>
<tr>
<td>B</td>
<td>D6</td>
</tr>
<tr>
<td>CLK</td>
<td>D5</td>
</tr>
<tr>
<td>SCK</td>
<td>D3</td>
</tr>
<tr>
<td>R</td>
<td>D7</td>
</tr>
<tr>
<td>NOE</td>
<td>D8</td>
</tr>
<tr>
<td>GND</td>
<td>GND</td>
</tr>
</tbody>
</table> <br/>
-> PinMode ile pin tanımlamaya gerek yok çünkü dmdesp kütüphanesi zaten bunu yapmış. Resimdeki gibi kabloları bağlarsanız doğru şekilde çalışacaktır.
<br/>
-> Arduino IDE'yi açın. Şimdi Esp8266 kartını Arduino'ya tanıtalım. Üst menüden Dosya -> Tercihler'e tıklayın. Açılan Tercihler penceresinde "Ek Devre Kartları Yöneticisi URL'leri" yerine http://arduino.esp8266.com/stable/package_esp8266com_index.json bu linki yapıştırın. Tamam'a basıp çıkın.<br/>
-> Yine üst menüden Araçlar -> Kart -> Kart Yöneticisi butonuna tıklayın. Açılan "Kart Yöneticisi" penceresinde arama yerine "esp8266" yazarak gerekli kütüphaneyi kurun.<br/>
-> Tekrardan Araçlar -> Kart bölümüne geldiğinizde ESP8266 BOARDS butonunu göreceksiniz, ESP8266 BOARDS butonuna tıklayın. Uygun kartı seçin. Benim kartım NodeMCU 1.0 ESP-12E MODULE olduğu için onu seçtim.<br/>
<br/>
-> Html sayfasını ESP8266'nın içerisine yüklemek için https://github.com/esp8266/arduino-esp8266fs-plugin/releases/tag/0.5.0 bu plugin'e ihtiyacımız var.<br/>
-> ESP8266FS-0.5.0.zip'i indirip içerisindeki ESP8266FS dosyasını belgeler/arduino/tools bölümüne kopyalamanız lazım. belgeler/arduino klasörü içerisinde tools klasörü yok ise oluşturup zip'ten çıkardığınız klasörü yapıştırın. Arduino'yu yeniden başlatmanız gerekebilir.<br/>
<br/>
-> Plugin'i kurduktan sonra Araçlar üst menüsüne geldiğinizde "ESP8266 Sketch Data Upload" adında bir buton görünüyor olması lazım. Bu html sayfamızı yüklemek için kullanacağımız buton olacak.<br/>
-> Bu repo içerisindeki esp_p10 klasörünü masaüstüne taşıyın. Ardından içerisinde bulunan esp_p10.ino dosyasını Arduino ile açın. Arduino IDE içerisinde Taslak -> Çalışma Klasörünü Göster dediğinizde sizi esp_p10 klasörüne yönlendirmesi gerekiyor.<br/>
-> Kartınızı usb ile bilgisayarınıza bağlayın, bulunduğu COM'u seçin. Üst menüde Araçlar'a gelin. Ardından "ESP8266 Sketch Data Upload" butonuna tıklayın, data klasöründe bulunan html sayfası ESP8266'nın içerisine yüklenecektir.<br/>
-> Son olarak esp_p10.ino içerisindeki kodları karta yükleyin.<br/>
<br/>
-> Telefon veya Laptop ile Wi-Fi kısmına gelip kartın adını bulun, <b>"ESP_Erişim_Noktası"</b>. Ardından şifreyi girin: <b>12345678!</b><br/>
-> Bir tarayıcı açıp adres satırına 192.168.4.1/ yazın bu sizi direk index.html sayfasına yönlendirecektir. html'de input alanına istediğiniz kelimeyi veya cümleyi yazıp test edin.<br/>
-> IP adresi kartınızda farklı olabilir bunun için seri port ekranında dinleme yapabilirsiniz.<br/>
<br/>
<h2>--> PROBLEMLER <--</h2>
<br/>
X - Türkçe karakterlerle alakalı sorun yaşanıyor, ı,ğ,ü,ş,ö,ç gibi.<br/>
? - Olası çözüm font dosyaları ile alakalı olmalı. C dili ve hexadecimal ile yazıldığı için pek uğraşmak istemedim.<br/>
<br/>
X - Tek bir model var o da sağdan sola kayma.<br/>
? - Olası çözüm panel setup tarzı uygulamalar olabilir.<br/>
