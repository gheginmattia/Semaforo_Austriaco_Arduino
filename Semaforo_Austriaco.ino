int sr=2,sg=3,sv=4,dr=5,dg=6,dv=7;
int d_lamp=500, d_rs=6000,d_g=3000, ser_beg=9600;
int q_lamp;
void tempi(void);
void semaforo_dx(void);
void lampeggio_dx(void);
void semaforo_sx(void);
void lampeggio_sx(void);

void setup() {
pinMode(sr,OUTPUT);
pinMode(sg,OUTPUT);
pinMode(sv,OUTPUT);
pinMode(dr,OUTPUT);
pinMode(dg,OUTPUT);
pinMode(dv,OUTPUT);
Serial.begin(ser_beg);
  Serial.println("inserisci in millisecondi la durata del rosso");
  while(Serial.available()==0){}
  d_rs=Serial.readString().toInt();
  Serial.println(d_rs);
  Serial.println("inserisci in millisecondi la durata del giallo");
   while(Serial.available()==0){}
  d_g=Serial.readString().toInt();
  Serial.println(d_g);
  Serial.println("inserisci in millisecondi il tempo tra un lampeggio ad un altro");
   while(Serial.available()==0){}
  d_lamp=Serial.readString().toInt();
  Serial.println(d_lamp);
  Serial.println("inserisci quanti lampeggi deve fare il verde");
    while(Serial.available()==0){}
    q_lamp=Serial.readString().toInt();
      Serial.println(q_lamp);
}
void semaforo_dx(void){
digitalWrite(sr,HIGH);
digitalWrite(dv,HIGH);
delay(d_rs);
}
void lampeggio_dx(void){
  for(int i=0; i<=q_lamp; i++)
  {
  digitalWrite(dv,LOW);
delay(d_lamp);
digitalWrite(dv,HIGH);
  }
    digitalWrite(dv,LOW);
digitalWrite(dg,HIGH);
digitalWrite(sg,HIGH);
delay(d_g);
digitalWrite(sr,LOW);
digitalWrite(sg,LOW);
digitalWrite(dg,LOW);
}
void semaforo_sx(void){
  digitalWrite(dr,HIGH);
digitalWrite(sv,HIGH);
delay(d_rs);
}
void lampeggio_sx(void){
  for (int i=0; i<=q_lamp; i++)
 {
  digitalWrite(sv,LOW);
delay(d_lamp);
digitalWrite(sv,HIGH);
}
  digitalWrite(sv,LOW);
digitalWrite(dg,HIGH);
digitalWrite(sg,HIGH);
delay (d_g);
digitalWrite(sg,LOW);
digitalWrite(dg,LOW);
digitalWrite(dr,LOW);
}
void loop() {
semaforo_dx();
lampeggio_dx();
semaforo_sx();
lampeggio_sx();
}
