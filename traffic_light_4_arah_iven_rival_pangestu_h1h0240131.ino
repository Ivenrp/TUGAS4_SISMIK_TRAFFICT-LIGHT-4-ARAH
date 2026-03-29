//PIN SETUP
int utara[]  = {4, 3, 2};   // merah, kuning, hijau
int timur[]  = {7, 6, 5};
int selatan[] = {10, 9, 8};
int barat[]  = {13, 12, 11};

//SETUP
void setup() {
  for (int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
  setAllRed();
}

//LOOP
void loop() {
  aktifkanSimpang(utara);
  aktifkanSimpang(timur);
  aktifkanSimpang(selatan);
  aktifkanSimpang(barat);
}

//FUNGSI

// Semua merah nyala
void setAllRed() {
  int semuaPin[] = {4,7,10,13}; // semua merah
  for (int i = 0; i < 4; i++) {
    digitalWrite(semuaPin[i], HIGH);
  }
}

// Aktifkan satu simpang
void aktifkanSimpang(int lampu[]) {
  setAllRed();

  // Matikan merah simpang ini
  digitalWrite(lampu[0], LOW);

  // Nyalakan hijau
  digitalWrite(lampu[2], HIGH);
  delay(5000);

  // Matikan hijau
  digitalWrite(lampu[2], LOW);

  // Kuning kedip
  kedipKuning(lampu[1]);

  // Kembali merah
  digitalWrite(lampu[0], HIGH);
}

// Kuning kedip 3x (±2 detik)
void kedipKuning(int pinKuning) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(pinKuning, HIGH);
    delay(300);
    digitalWrite(pinKuning, LOW);
    delay(300);
  }
}
