/*
 Lendo o Módulo Acelerômetro e Giroscópio MPU-6050
*/
//Carrega a biblioteca Wire para comunicação com o módulo
#include<Wire.h>
//variável com o endereco I2C do MPU6050
const int MPU=0x68;
//Variaveis para armazenar valores dos sensores presentes no módulo
int AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
// configuração inicial
void setup()
{
 // inicialização do monitor serial em 9600 baudrates
 Serial.begin(9600);
 // inicialização da comunicação com o módulo
 Wire.begin();
 Wire.beginTransmission(MPU);
 Wire.write(0x6B);

 // inicialização do módulo
 Wire.write(0);
 Wire.endTransmission(true);

}
// loop infinito, tudo que estiver dentro será repetido indefinidamente
void loop()
{
 // Configuração do módulo
 Wire.beginTransmission(MPU);
 Wire.write(0x3B);
 Wire.endTransmission(false);

 // Solicita os dados do sensor
 Wire.requestFrom(MPU,14,true);

 // Armazena o valor dos sensores nas variaveis correspondentes
 AcX=Wire.read()<<8|Wire.read(); //0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
 AcY=Wire.read()<<8|Wire.read(); //0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)

AcZ=Wire.read()<<8|Wire.read(); //0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
 Tmp=Wire.read()<<8|Wire.read(); //0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
 GyX=Wire.read()<<8|Wire.read(); //0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
 GyY=Wire.read()<<8|Wire.read(); //0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
 GyZ=Wire.read()<<8|Wire.read(); //0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

 // Mostra os valores no monitor serial
 Serial.print("Acel. X = "); Serial.print(AcX);
 Serial.print(" | Y = "); Serial.print(AcY);
 Serial.print(" | Z = "); Serial.print(AcZ);
 Serial.print(" | Gir. X = "); Serial.print(GyX);
 Serial.print(" | Y = "); Serial.print(GyY);
 Serial.print(" | Z = "); Serial.print(GyZ);
 Serial.print(" | Temp = ");
Serial.println(Tmp/340.00+36.53);

 // Aguarda 300 milisegundos e reinicia o processo
 delay(300);
}
