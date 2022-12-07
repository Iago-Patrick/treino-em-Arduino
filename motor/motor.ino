 
struct motorA
{
//in1 e in2 e o motor A
int in1;//porta digita do arduino no in1.
int in2;//porta digita do arduino no in2.
};

struct motorB
{
//in3 e in4 e o motor B
int in3;//porta digita do arduino no in3.
int in4;//porta digita do arduino no in4.
};

motorA mA;
motorB mB;

void setup() 
{
  //configuração dos pinos como saida
  pinMode(mA.in1, OUTPUT);
  pinMode(mA.in2, OUTPUT);
  pinMode(mB.in3, OUTPUT);
  pinMode(mB.in4, OUTPUT);
}

void loop() 
{
  
}

void motoEsquerda()
{
  digitalWrite(mA.in1, LOW); 
  digitalWrite(mA.in2, LOW);
  
  digitalWrite(mB.in3, LOW);
  digitalWrite(mB.in4, HIGH);
}

void motoFrente()
{
  digitalWrite(mA.in1, LOW); 
  digitalWrite(mA.in2, HIGH);
  
  digitalWrite(mB.in3, LOW);
  digitalWrite(mB.in4, HIGH);
}

void motoDireita ()
{
  digitalWrite(mA.in1, LOW); 
  digitalWrite(mA.in2, HIGH);
  
  digitalWrite(mB.in3, LOW);
  digitalWrite(mB.in4, LOW);
}

void motoTras()
{
  digitalWrite(mA.in1, HIGH); 
  digitalWrite(mA.in2, LOW);
  
  digitalWrite(mB.in3, HIGH);
  digitalWrite(mB.in4, LOW);
}
