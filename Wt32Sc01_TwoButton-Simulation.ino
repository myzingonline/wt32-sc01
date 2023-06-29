
/*
    Simple Touch Drawing sample for WT32-SC01
*/
#define LGFX_AUTODETECT  // Autodetect board
#define LGFX_USE_V1      // set to use new version of library

#include <LovyanGFX.hpp>  // main library

static LGFX lcd;  // declare display variable

// Variables for touch x,y
static int32_t x, y;
static int32_t xBox = 20, yBox = 20, xWidth = 80, yHeight = 40, marginRight = 30;

bool btn1Clicked = true;
const int noOfButton = 2;  //2
boolean btn1ClickColl[noOfButton];
void setup(void) {
  Serial.begin(115200);
  lcd.init();

  // Setting display to landscape
  if (lcd.width() < lcd.height()) lcd.setRotation(lcd.getRotation() ^ 1);

  lcd.setCursor(0, 0);
  lcd.printf("Ready to touch & draw!");

  /*Button drawing logic*/
  // for (int i = 1; i <= noOfButton; i++) {
  btn1ClickColl[0] = true;
  //drawRect      ( x, y, w, h   , color);  // 矩形の外周
  uint16_t green = 0x07E0;
  lcd.fillRect(xBox, yBox, xWidth, yHeight, 0xF800);
  int box1TextX = xBox + 10;
  int box1TextY = yBox + 10;
  lcd.setCursor(box1TextX, box1TextY);
  lcd.println("RF1");
  xBox = (xBox + xWidth) + marginRight;

  btn1ClickColl[1] = true;
  //drawRect      ( x, y, w, h   , color);  // 矩形の外周
  green = 0x07E0;
  lcd.fillRect(xBox, yBox, xWidth, yHeight, 0xF800);
  box1TextX = xBox + 10;
  box1TextY = yBox + 10;
  lcd.setCursor(box1TextX, box1TextY);
  lcd.println("RF2");
  xBox = (xBox + xWidth) + marginRight;


  // }
}

void loop() {
  xBox = 20;
  if (lcd.getTouch(&x, &y)) {
    Serial.printf("Rect Touch:(%03d,%03d)", x, y);
    //lcd.fillRect(x-2, y-2, 5, 5, TFT_RED);
    //Btn 1 detected
    /*Below loop is checking button region for each section*/

    //Button 1 test
    if ((x >= xBox && x <= xBox + xWidth) && (y >= yBox && y <= yBox + yHeight)) {
      Serial.println("Box Touched");
      if (btn1ClickColl[0]) {
        Serial.println("Box Register");
        lcd.fillRect(xBox, yBox, xWidth, yHeight, 0x07E0);  //Green
        int box1TextX = xBox + 10;
        int box1TextY = yBox + 10;
        lcd.setCursor(box1TextX, box1TextY);
        lcd.println("RF Selected");
        //btn1Clicked =false;
      } else {
        Serial.println("Box NOt Register");
        lcd.fillRect(xBox, yBox, xWidth, yHeight, 0xF800);  //red color
        int box1TextX = xBox + 10;
        int box1TextY = yBox + 10;
        lcd.setCursor(box1TextX, box1TextY);
        lcd.println("RF 1");
      }
      btn1ClickColl[0] = !btn1ClickColl[0];
      lcd.setCursor(180, 110);
      lcd.printf("Rect Touch:(%03d,%03d)", x, y);
      delay(1000);
    } else {
      lcd.setCursor(180, 110);
      lcd.printf("Not touched");
    }

    // Import as it will move x axis cursor to right for new btn render
    xBox = (xBox + xWidth) + marginRight;

    //Button 2 test
    if ((x >= xBox && x <= xBox + xWidth) && (y >= yBox && y <= yBox + yHeight)) {
      Serial.println("Box Touched");
      if (btn1ClickColl[1]) {
        Serial.println("Box Register");
        lcd.fillRect(xBox, yBox, xWidth, yHeight, 0x07E0);  //Green
        //btn1Clicked =false;
      int box1TextX = xBox + 10;
      int box1TextY = yBox + 10;
      lcd.setCursor(box1TextX, box1TextY);
      lcd.println("RF Selected");
      } else {
        Serial.println("Box NOt Register");
        lcd.fillRect(xBox, yBox, xWidth, yHeight, 0xF800); //Red
        int box1TextX = xBox + 10;
        int box1TextY = yBox + 10;
        lcd.setCursor(box1TextX, box1TextY);
        lcd.println("RF 2");
      }
      btn1ClickColl[1] = !btn1ClickColl[1];
 

      lcd.setCursor(180, 110);
      lcd.printf("Rect Touch:(%03d,%03d)", x, y);
      delay(1000);
    } else {
      lcd.setCursor(180, 110);
      lcd.printf("Not touched");
    }
  }

  lcd.setCursor(380, 0);
  lcd.printf("Touch:(%03d,%03d)", x, y);
}
// delay(1000);
