int Left_p=2;
int Left_n=3;
int Right_p=6;
int Right_n=7;
int b=8;
int ll,c,rr,r,l;
void setup()
{
  pinMode(Left_p,OUTPUT);
  pinMode(Left_n,OUTPUT);
  pinMode(Right_p,OUTPUT);
  pinMode(Right_n,OUTPUT);
pinMode(b,OUTPUT);
pinMode(A0, INPUT);
pinMode(A2, INPUT);
pinMode(A4, INPUT);
pinMode(A1, INPUT);
pinMode(A3, INPUT);
Serial.begin(9600);

}
  

void loop()

{
  digitalWrite(b,HIGH);
  int ll=analogRead(A0);
  int c=analogRead(A2);
  int rr=analogRead(A4);
  int r=analogRead(A3);
  int l=analogRead(A1);
    digitalWrite(8,HIGH);
  digitalWrite(Left_n,LOW);
  digitalWrite(Left_p,LOW);
  digitalWrite(Right_n,LOW);
  digitalWrite(Right_p,LOW);
  
  if(c<550&&ll>550&&rr>550||c<550&&rr<550&&ll<550)
  {
    Serial.println("forward");
     digitalWrite(Left_p,HIGH);

     digitalWrite(Right_p,HIGH);
     
  }
  if(rr<550&&ll>550&&c>550 ||rr<550&&c<550&&ll>550||r<550&&c<550&&ll>550&&rr>550&&l>550||r<550&&c>550&&ll>550&&rr>550&&l>550)
  {
    Serial.println("right");
     digitalWrite(Right_p,HIGH);   

     
  }
  
if(ll<550&&c>550&&rr>550||ll<550&&c<550&&rr>550||l<550&&c<550&&rr>550&&r>550&&ll>550||l<550&&c>550&&rr>550&&r>550&&ll>550)
{
  Serial.println("left");
  digitalWrite(Left_p,HIGH);
 
     
         
}
if(rr>550&&ll>550&&l>550&&r>550&&c>550)
{
     digitalWrite(Left_p,1);
     digitalWrite(Right_n,0);
    digitalWrite(Left_n,0);
     digitalWrite(Right_p,1);
     delay(50);
           
}
if(rr<550&&ll<550&&l<550&&r<550&&c<550)
{
     digitalWrite(Left_p,1);
     digitalWrite(Right_n,0);
    digitalWrite(Left_n,0);
     digitalWrite(Right_p,1);
           
}

Serial.print(ll);
Serial.print(" ");
Serial.print(c);
Serial.print(" ");
Serial.println(rr);


}
