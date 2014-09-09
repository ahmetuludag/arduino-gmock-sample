// Copyright 2014 http://switchdevice.com

#include "gtest/gtest.h"
#include "arduino-mock/Arduino.h"
#include "arduino-mock/Serial.h"
Serial_ Serial;

#include "../DigitalReadSerial.ino"

using ::testing::Return;
TEST(loop, pushed) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  SerialMock* serialMock = serialMockInstance();
  EXPECT_CALL(*arduinoMock, digitalRead(2))
    .WillOnce(Return(1));
  EXPECT_CALL(*serialMock, println(1, 10));
  EXPECT_CALL(*arduinoMock, delay(1));
  loop();
  delete serialMock;
  delete arduinoMock;
}