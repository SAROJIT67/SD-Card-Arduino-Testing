#include <Arduino.h>
#include <SD.h>

#define SD_PIN D0

File myMPUFile, myGPSFile;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  delay(2000);

  Serial.print("Initializing SD card...");

  if (!SD.begin(SD_PIN)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  
  myGPSFile = SD.open("gps.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myGPSFile) {
    Serial.print("Writing to gps.txt...");
    myGPSFile.println("testing 1, 2, 3 ");
    // close the file:
    myGPSFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

  myMPUFile = SD.open("mpu.txt", FILE_WRITE);
  
    if (myMPUFile) {
    Serial.print("Writing to mpu.txt...");
    myMPUFile.println("testing 4, 5, 6 ");
    // close the file:
    myMPUFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

  // re-open the file for reading:
  myGPSFile = SD.open("gps.txt");
  if (myGPSFile) {
    Serial.println("gps.txt:");

    // read from the file until there's nothing else in it:
    while (myGPSFile.available()) {
      Serial.println(myGPSFile.readStringUntil('\n'));
    }
    // close the file:
    myGPSFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

  myMPUFile = SD.open("mpu.txt");
  if (myMPUFile) {
    Serial.println("mpu.txt:");

    // read from the file until there's nothing else in it:
    while (myMPUFile.available()) {
      String mpu_data = (myMPUFile.readStringUntil('\n'));
      Serial.println(mpu_data);
    }
    // close the file:
    myMPUFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
