 int F = 6;  
 int G = 7;  
 int E = 5;  
 int D = 4;  
 int C = 3;  
 int B = 2;  
 int A = 1; 
 int de= 1200;
 void setup() {  
  pinMode(F, OUTPUT);  
  pinMode(G, OUTPUT);  
  pinMode(E, OUTPUT);  
  pinMode(D, OUTPUT);  
  pinMode(C, OUTPUT);  
  pinMode(B, OUTPUT);  
  pinMode(A, OUTPUT);  
 }  
 void loop()   
 {  
  digitalWrite(A,1);   
  digitalWrite(B,1);   
  digitalWrite(C,1);   
  digitalWrite(D,1);   
  digitalWrite(E,1);   
  digitalWrite(F,1);   
  digitalWrite(G,0);  // 0  
  delay(de);   
  digitalWrite(A,0);   
  digitalWrite(B,1);   
  digitalWrite(C,1);   
  digitalWrite(D,0);   
  digitalWrite(E,0);   
  digitalWrite(F,0);   
  digitalWrite(G,0);  // 1  
  delay(de);  
  digitalWrite(A,1);   
  digitalWrite(B,1);   
  digitalWrite(C,0);   
  digitalWrite(D,1);   
  digitalWrite(E,1);   
  digitalWrite(F,0);   
  digitalWrite(G,1);  // 2  
  delay(de);  
  digitalWrite(A,1);   
  digitalWrite(B,1);   
  digitalWrite(C,1);   
  digitalWrite(D,1);   
  digitalWrite(E,0);   
  digitalWrite(F,0);   
  digitalWrite(G,1);  // 3  
  delay(de);   
  digitalWrite(A,0);   
  digitalWrite(B,1);   
  digitalWrite(C,1);   
  digitalWrite(D,0);   
  digitalWrite(E,0);   
  digitalWrite(F,1);   
  digitalWrite(G,1);  // 4  
  delay(de);    
  digitalWrite(A,1);   
  digitalWrite(B,0);   
  digitalWrite(C,1);   
  digitalWrite(D,1);   
  digitalWrite(E,0);   
  digitalWrite(F,1);   
  digitalWrite(G,1);  // 5  
  delay(de);   
   digitalWrite(A,1);   
  digitalWrite(B,0);   
  digitalWrite(C,1);   
  digitalWrite(D,1);   
  digitalWrite(E,1);   
  digitalWrite(F,1);   
  digitalWrite(G,1);  // 6  
  delay(de);   
  digitalWrite(A,1);   
  digitalWrite(B,1);   
  digitalWrite(C,1);   
  digitalWrite(D,0);   
  digitalWrite(E,0);   
  digitalWrite(F,0);   
  digitalWrite(G,0);  // 7  
  delay(de);   
  digitalWrite(A,1);   
  digitalWrite(B,1);   
  digitalWrite(C,1);   
  digitalWrite(D,1);   
  digitalWrite(E,1);   
  digitalWrite(F,1);   
  digitalWrite(G,1);  // 8  
  delay(de);   
  digitalWrite(A,1);   
  digitalWrite(B,1);   
  digitalWrite(C,1);   
  digitalWrite(D,1);   
  digitalWrite(E,0);   
  digitalWrite(F,1);   
  digitalWrite(G,1);  // 9  
  delay(de);    
 } 
