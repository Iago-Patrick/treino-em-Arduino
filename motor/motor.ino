struct motorA
{
  //in1 e in2 e o motor A
  const int in1=1;//porta digita do arduino no in1.
  const int in2=2;//porta digita do arduino no in2.
};

struct motorB
{
  //in3 e in4 e o motor B.
  const int in3=3;//porta digita do arduino no in3.
  const int in4=4;//porta digita do arduino no in4.
};

struct sensor
{
  const int sensorUm=A0;//porta do sensor 1 no arduino.
  const int sensorDois=A1;//porta do sensor 2 no arduino. 
};
struct velocidade
{
  const int enA=10;//porta digital do arduino no en.
  const int enB=11;//porta digital do arduino na porta en.
};

int pwm1;
int pwm2;

motorA mA;
motorB mB;
sensor s;
velocidade v;

void setup() 
{
  //configuração dos pinos como saida
  pinMode(mA.in1, OUTPUT);
  pinMode(mA.in2, OUTPUT);
  pinMode(mB.in3, OUTPUT);
  pinMode(mB.in4, OUTPUT);
  pinMode(v.enA, OUTPUT);
  pinMode(v.enB, OUTPUT);
  //pinMode(s.sensorUm, INPUT);
  //pinMode(s.sensorDois, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  funcaoDir2();
}

void funcaoDir2(void)
{
  int valorUm = digitalRead(s.sensorUm);
  int valorDois = digitalRead(s.sensorDois);
  
  pwm1 = map(valorUm, 0, 1023, 0, 254);
  pwm2 = map(valorDois, 0, 1023, 0, 254);
  
  motoFrente();

  analogWrite(v.enA, pwm1);
  analogWrite(v.enB, pwm2); 
}

void funcaoDir(void)
{
  const int valorBranco = 500;
  const int valorPreto = 500;  
  int valorDois;
  int valorUm;

  motoFrente();

  analogWrite(v.enA,pwm1);
  analogWrite(v.enB,pwm2);
  //valorUm = digitalRead(s.sensorUm);
  //valorDois = digitalRead(s.sensorDois);
  
  valorUm = analogRead(s.sensorUm);
  valorDois = analogRead(s.sensorDois);

  
  Serial.println(valorUm); //como se monitora dois sensores diferentes?
  delay(100);
  Serial.println(valorDois);
  delay(100);
  
  if (valorUm>=valorBranco) //se sensor um ler branco.
  {
    if(valorDois<=valorPreto) // se o sensor dois ler preto.
    {
      pwm2--;
      analogWrite(v.enB, pwm2);
    }
  }
  
  if(valorDois>=valorBranco) // se o sensor dois ler branco. 
  {
    if(valorUm<=valorPreto) // se o sensor um ler preto.
    {
      pwm1--;
      analogWrite(v.enA, pwm1);
    }
  }
  
}

void motoFrente(void)//função para ir para frente.
{
  digitalWrite(mA.in1, LOW); 
  digitalWrite(mA.in2, HIGH);
  
  digitalWrite(mB.in3, LOW);
  digitalWrite(mB.in4, HIGH);
}

void motoEsquerda(void)//função para ir para esqueda.
{
  digitalWrite(mA.in1, LOW); 
  digitalWrite(mA.in2, LOW);
  
   
  digitalWrite(mB.in3, LOW);
  digitalWrite(mB.in4, HIGH); 
}

void motoDireita (void)//função para ir para direita.
{
  digitalWrite(mA.in1, LOW); 
  digitalWrite(mA.in2, HIGH);
  
  digitalWrite(mB.in3, LOW);
  digitalWrite(mB.in4, LOW);
}

void motoTras(void)//função para ir para tras.
{
  digitalWrite(mA.in1, HIGH); 
  digitalWrite(mA.in2, LOW);
  
  digitalWrite(mB.in3, HIGH);
  digitalWrite(mB.in4, LOW);
}
