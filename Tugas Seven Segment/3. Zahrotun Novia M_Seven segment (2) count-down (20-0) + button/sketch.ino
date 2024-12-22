int sega1 = 9;
int segb1 = 10;
int segc1 = 11;
int segd1 = 12;
int sege1 = 13;
int segf1 = A0;
int segg1 = A1;

int sega2 = 2;
int segb2 = 3;
int segc2 = 4;
int segd2 = 5;
int sege2 = 6;
int segf2 = 7;
int segg2 = 8;

int buttonPin = A2;

bool countdownStarted = false;

int numbers[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},  // 0
  {0, 1, 1, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1},  // 2
  {1, 1, 1, 1, 0, 0, 1},  // 3
  {0, 1, 1, 0, 0, 1, 1},  // 4
  {1, 0, 1, 1, 0, 1, 1},  // 5
  {1, 0, 1, 1, 1, 1, 1},  // 6
  {1, 1, 1, 0, 0, 0, 0},  // 7
  {1, 1, 1, 1, 1, 1, 1},  // 8
  {1, 1, 1, 0, 0, 1, 1}   // 9
};

void displayNumber(int segPins[], int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], numbers[num][i]);
  }
}

void setup() {
  // pin segmen puluhan untuk output
  for (int i = sega1; i <= segg1; i++) {
    pinMode(i, OUTPUT);
  }

  // pin segmen satuan untuk output
  for (int i = sega2; i <= segg2; i++) {
    pinMode(i, OUTPUT);
  }

  // pin tombol untuk input
  pinMode(buttonPin, INPUT);
}

void loop() {
  // untuk mengecek apakah tombol dipencet
  if (digitalRead(buttonPin) == HIGH && !countdownStarted) {
    countdownStarted = true;  
    delay(200);               
  }

  // ketika countdown sudah dimulai
  if (countdownStarted) {
    // Countdown dari 20 ke 0
    for (int i = 20; i >= 0; i--) {
      int tens = i / 10;      // angka puluhan
      int ones = i % 10;      // angka satuan

      // Tampilkan angka puluhan
      int tensPins[] = {sega1, segb1, segc1, segd1, sege1, segf1, segg1};
      displayNumber(tensPins, tens);

      // Tampilkan angka satuan
      int onesPins[] = {sega2, segb2, segc2, segd2, sege2, segf2, segg2};
      displayNumber(onesPins, ones);

      delay(1000);           // Tampilkan angka selama 1 detik
    }

    countdownStarted = false; // Reset countdown setelah selesai
  }
}