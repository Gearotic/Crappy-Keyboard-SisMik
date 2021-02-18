// Osu!_Board

// Created by :
// Raihan Athallah Aditya             - 185150300111016 : Coding, error, repeat
// Aulia Nabih Rizqullah              - 185150300111017 : Coding, case modeling
// Dionisius Marcello Divito          - 185150300111029 : Soldering, PCB layout, coding, ngebrick :(
// Willy Septian Andreas Sigalingging - 185150307111012 : Funding, cari toko, sparepart, coding final

// Thx to Charles Garcia :^)

#include <Keyboard.h>  // Library Keyboard
#include <Bounce2.h>   // Library Switch Debouncing

// Biar gampang ganti-ganti key, jangan dihilangin
// Kode keyboard : https://www.arduino.cc/en/Reference/KeyboardModifiers
// Jika menggunakan non-special key pake format [#define BIND_X 'a']
#define BIND_0 217  // Binding panah bawah
#define BIND_1 215  // Binding panah kanan
#define BIND_2 218  // Binding panah atas
#define BIND_3 216  // Binding panah kiri

#define JUMLAH_TOMBOL 4

// i buat looping doang, pin buat nomor pin yang pengen dipake
int i = 0, pin[JUMLAH_TOMBOL] = {0, 1, 2, 3};

// Untuk attach debouncing
Bounce button[JUMLAH_TOMBOL];

void setup() {
	
	// Matiin indikator keypress
	// pinMode(LED_BUILTIN_TX, INPUT);
	
	// Software debouncing switch
	for(i = 0; i < JUMLAH_TOMBOL; i++) {
		button[i] = Bounce();
		button[i].attach(pin[i], INPUT_PULLUP);
		button[i].interval(5);
	}
	
	// Memulai fungsi keyboard
	Keyboard.begin();
	Serial.begin(115200);
	
}

void loop() {
	
	// Update keypresses
	for(i = 0; i < JUMLAH_TOMBOL; i++) {
		button[i].update();
	}
	
	// Cek keypresses
	if(button[0].fell()) {
		Keyboard.press(BIND_0);
	}
	if(button[0].rose()) {
		Keyboard.release(BIND_0);
	} 
	if(button[1].fell()) {
		Keyboard.press(BIND_1);
	}
	if(button[1].rose()) {
		Keyboard.release(BIND_1);
	}
	if(button[2].fell()) {
		Keyboard.press(BIND_2);
	}
	if(button[2].rose()) {
		Keyboard.release(BIND_2);
	}
	if(button[3].fell()) {
		Keyboard.press(BIND_3);
	}
	if(button[3].rose()) {
		Keyboard.release(BIND_3);
	}
}