#include <DHT.h>
#include <LiquidCrystal.h>
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);
LiquidCrystal lcd(3,4,5,6,7,8);
const int led1 = 9;
const int led2 = 10;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  lcd.begin(16, 2);

  dht.begin();

  lcd.print("Station meteo");
  delay(2000);
  lcd.clear();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidite = dht.readHumidity();

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C °  ");

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(humidite);
  lcd.print(" %   ");

  if (temperature > 30) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  } else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }

  delay(2000);
}
