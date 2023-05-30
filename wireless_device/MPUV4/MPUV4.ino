#include <Wire.h>
#include <Wire.h>
#include <BluetoothSerial.h>
#define ejex 0x3B
#define ejey 0x3D
#define ejez 0x3F
#define rotx 0x43
#define roty 0x45
#define rotz 0x47
BluetoothSerial SerialBT;
int datox, datoy, datoz;
const int pulsador = 12;
const int buzzer = 2;
volatile bool flag = false;
int ax, ay, az;
int gx, gy, gz;

int acel(int eje) {
  short A, B, daton;
  Wire.beginTransmission(0x68);
  Wire.write(eje);
  Wire.endTransmission(false);
  Wire.requestFrom(0x68, 2);

  while (!Wire.available()) {}
  A = Wire.read();
  while (!Wire.available()) {}
  B = Wire.read();

  daton = (A << 8) | B;
  return daton;
}

void IRAM_ATTR detectarp() {
  flag = true;
}

void setup() {
  Serial.begin(9600);
  pinMode(pulsador, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  SerialBT.begin("ESP32_BT"); // Nombre del dispositivo Bluetooth
  Wire.begin();
  Wire.beginTransmission(0x68);
  Wire.write(0x6B); // Registro PWR_MGMT_1
  Wire.write(0);    // Activar el MPU6050
  Wire.endTransmission(true);
  attachInterrupt(digitalPinToInterrupt(pulsador), detectarp, RISING);
}

void loop() {
  if (flag) {
    Serial.println("Boton pulsado");
    Serial.println("-----------------");
    SerialBT.print("{\"fire\":");
    SerialBT.print('1');
    SerialBT.print(",\"gx\":");
    SerialBT.print(gx);
    SerialBT.print(",\"g y\":");
    SerialBT.print(gy);
    SerialBT.println("}");
    flag = false;
  }
  ax = acel(ejex);
  ay = acel(ejey);
  az = acel(ejez);
  gx = acel(rotx);
  gy = acel(roty);
  gz = acel(rotz);
  /* Serial.print("X:");
    short accelX = acel(ejex);
    Serial.println(accelX);

    Serial.print("Y:");
    short accelY = acel(ejey);
    Serial.println(accelY);

    Serial.print("Z:");
    short accelZ = acel(ejez);
    Serial.println(accelZ);

    Serial.print("Rotacion X:");
    short gyroX = acel(rotx);
    Serial.println(gyroX);

    Serial.print("Rotacion Y:");
    short gyroY = acel(roty);
    Serial.println(gyroY);

    Serial.print("Rotacion Z:");
    short gyroZ = acel(rotz);
    Serial.println(gyroZ);
    Serial.println("Boton NO pulsado");
    Serial.println("-------------------------------------------");
  */
  /*// Enviar datos por Bluetooth
    byte data[12];
    data[0] = (accelX >> 8) & 0xFF;
    data[1] = accelX & 0xFF;
    data[2] = (accelY >> 8) & 0xFF;
    data[3] = accelY & 0xFF;
    data[4] = (accelZ >> 8) & 0xFF;
    data[5] = accelZ & 0xFF;
    data[6] = (gyroX >> 8) & 0xFF;
    data[7] = gyroX & 0xFF;
    data[8] = (gyroY >> 8) & 0xFF;
    data[9] = gyroY & 0xFF;
    data[10] = (gyroZ >> 8) & 0xFF;
    data[11] = gyroZ & 0xFF;

    for (int i = 0; i < sizeof(data); i += 2) {
    byte packet[2];
    packet[0] = data[i];
    packet[1] = data[i + 1];
    SerialBT.write(packet, sizeof(packet));
    delay(100); // Pequeña pausa entre paquetes
    }*/
  Serial.print(gx);//"{\"fire\":1}"
  Serial.print(",");
  /*  Serial.print("Y:");*/
  Serial.println(gy);

  // Enviar datos por Bluetooth
  SerialBT.print("{\"gx\":");
  SerialBT.print(gx);
  SerialBT.print(",\"gy\":");
  SerialBT.print(gy);
  SerialBT.println("}");
  delay(1000);
}
