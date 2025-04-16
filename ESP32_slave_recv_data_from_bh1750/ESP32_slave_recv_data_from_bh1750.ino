#include <esp_now.h>
#include <WiFi.h>

// Định nghĩa struct dữ liệu giống bên Master
typedef struct struct_message {
    float lux;
} struct_message;

struct_message myData;

// Hàm callback mới đúng định nghĩa ESP32 Core v2.0.14+
void OnDataRecv(const esp_now_recv_info *info, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Cuong do anh sang: ");
  Serial.print(myData.lux, 2);
  Serial.println(" lux");
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Loi khoi tao ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
  
}



























//thêm LCD

  // #include <esp_now.h>
  // #include <WiFi.h>

  // //oled
  // #include <Wire.h>
  // #include <U8g2lib.h>

  // // Khởi tạo OLED 1.3" SH1106, dùng giao tiếp I2C
  // // Chân SDA, SCL mặc định của ESP32 là GPIO 21 (SDA), GPIO 22 (SCL)
  // U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

  // // Định nghĩa struct dữ liệu giống bên Master
  // typedef struct struct_message {
  //   float lux;
  // } struct_message;

  // struct_message myData;

  // // Hàm callback mới đúng định nghĩa ESP32 Core v2.0.14+
  // void OnDataRecv(const esp_now_recv_info *info, const uint8_t *incomingData, int len) {
  //   memcpy(&myData, incomingData, sizeof(myData));

  //   // In ra Serial
  //   Serial.print("Cuong do anh sang: ");
  //   Serial.print(myData.lux, 2);
  //   Serial.println(" lux");

  //   //oled
  //   u8g2.clearBuffer();                         // Xóa bộ đệm
  //   u8g2.setFont(u8g2_font_ncenB08_tr);         // Chọn font
  //   u8g2.drawStr(0, 20, "Cuong do anh sang:");  // In dòng đầu
  //   char buffer[20];
  //   sprintf(buffer, "%.2f lux", myData.lux);    // Chuyển số sang chuỗi
  //   u8g2.drawStr(0, 40, buffer);                // In dòng thứ hai
  //   u8g2.sendBuffer();                          // Gửi dữ liệu ra màn hình
  // }

  // void setup() {
  //   Serial.begin(115200);
  //   WiFi.mode(WIFI_STA);

  //   //oled
  //   u8g2.begin();                               // Khởi động màn hình

  //   if (esp_now_init() != ESP_OK) {
  //     Serial.println("Loi khoi tao ESP-NOW");
  //     return;
  //   }

  //   esp_now_register_recv_cb(OnDataRecv);
  // }

  // void loop() {
  //   // Không cần làm gì trong loop, đợi dữ liệu từ ESP-NOW
  // }
