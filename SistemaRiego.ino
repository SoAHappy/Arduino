#include <LiquidCrystal.h>  
#include <DHT.h>
#include <DHT_U.h>
//Alamacen de Potenciometro
long  valor;
//Pines
int bomba = 8;      // pin DATA de DHT22
int SensorTemp = 5;
//Variables
int temp;
int hum;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  // pines RS, E, D4, D5, D6, D7 
DHT dht(SensorTemp, DHT11);

void setup(){
  dht.begin();      // inicializacion de sensor
  lcd.begin(16, 2);     // inicializa a display de 16 columnas y 2 lineas
  pinMode(bomba, OUTPUT);// initialize digital pin LED_BUILTIN as an output.

}

void loop(){
  //Potenciometro
   valor = analogRead(A0);
//Sensor
temp = dht.readTemperature(); 
hum = dht.readHumidity();    
  
//Pantalla
  lcd.setCursor(0, 0);      // ubica cursor en columna 0, linea 0
  lcd.print("Temperatura: "+ String(temp)+ "C");  
  lcd.setCursor(0, 1);      // ubica cursor en columna 0, linea 1
  lcd.print("Humedad: "+ String(hum)+"%");      
  
  if(temp>=25&&hum<=20){
    
    digitalWrite(bomba, LOW);
    lcd.setCursor(0, 0);
    lcd.print("*****Regando*****");
    lcd.setCursor(0, 1);
    lcd.print("*********"); 
    delay(5000);
          }else if(valor >= 512 && valor <=767){
    digitalWrite(bomba, LOW);
    lcd.setCursor(0, 0);
    lcd.print("*****Regando*****");
    lcd.setCursor(0, 1);
    lcd.print("*********"); 
    delay(5000);
    
  }else{
  digitalWrite(bomba, HIGH);    
}
//Si no recibe informacion del sensor
  if(temp==0&&hum==0){
     lcd.setCursor(0,0);
     lcd.print("*****ERROR******"); // Mostrar en la pantalla LCD
     lcd.setCursor(0,1);
     lcd.print("***SIN SENSOR***");
     delay(1000); //Actualizacion cada segundo
  }
}
