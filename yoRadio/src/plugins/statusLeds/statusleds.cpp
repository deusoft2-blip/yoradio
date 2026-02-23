#include "statusleds.h"

#include <WiFi.h>

<<<<<<< codex/implement-radio-led-control-plugin-y9d5pr
=======
#include "../../core/player.h"

>>>>>>> main
#ifndef STATUS_LED_GREEN_PIN
  #define STATUS_LED_GREEN_PIN 255
#endif

#ifndef STATUS_LED_BLUE_PIN
  #define STATUS_LED_BLUE_PIN 255
#endif

#ifndef STATUS_LED_RED_PIN
  #define STATUS_LED_RED_PIN 255
#endif

#ifndef STATUS_LED_GREEN_INVERT
  #define STATUS_LED_GREEN_INVERT false
#endif

#ifndef STATUS_LED_BLUE_INVERT
  #define STATUS_LED_BLUE_INVERT false
#endif

#ifndef STATUS_LED_RED_INVERT
  #define STATUS_LED_RED_INVERT false
#endif

#ifndef STATUS_LED_BLUE_BLINK_WHEN_DISCONNECTED
  #define STATUS_LED_BLUE_BLINK_WHEN_DISCONNECTED true
#endif

statusLeds ledStatusPlugin;

<<<<<<< codex/implement-radio-led-control-plugin-y9d5pr
statusLeds::statusLeds() : _blueBlinkState(false), _isPlaying(false) {
=======
statusLeds::statusLeds() : _blueBlinkState(false) {
>>>>>>> main
  registerPlugin();
  log_i("statusLeds plugin is registered");
}

void statusLeds::writeLed(uint8_t pin, bool value, bool invert) {
  if (pin == 255) return;
  digitalWrite(pin, invert ? !value : value);
}

void statusLeds::applyStates(bool fromTicker) {
<<<<<<< codex/implement-radio-led-control-plugin-y9d5pr
  const bool isWifiConnected = WiFi.status() == WL_CONNECTED;

  writeLed(STATUS_LED_GREEN_PIN, _isPlaying, STATUS_LED_GREEN_INVERT);
=======
  const bool isPlaying = player.status() == PLAYING;
  const bool isWifiConnected = WiFi.status() == WL_CONNECTED;

  writeLed(STATUS_LED_GREEN_PIN, isPlaying, STATUS_LED_GREEN_INVERT);
>>>>>>> main

  if (isWifiConnected) {
    _blueBlinkState = true;
    writeLed(STATUS_LED_BLUE_PIN, true, STATUS_LED_BLUE_INVERT);
  } else if (STATUS_LED_BLUE_BLINK_WHEN_DISCONNECTED && fromTicker) {
    _blueBlinkState = !_blueBlinkState;
    writeLed(STATUS_LED_BLUE_PIN, _blueBlinkState, STATUS_LED_BLUE_INVERT);
  } else {
    _blueBlinkState = false;
    writeLed(STATUS_LED_BLUE_PIN, false, STATUS_LED_BLUE_INVERT);
  }

  // Device powered => keep red LED ON while firmware is running.
  writeLed(STATUS_LED_RED_PIN, true, STATUS_LED_RED_INVERT);
}

void statusLeds::on_setup() {
  if (STATUS_LED_GREEN_PIN != 255) pinMode(STATUS_LED_GREEN_PIN, OUTPUT);
  if (STATUS_LED_BLUE_PIN != 255) pinMode(STATUS_LED_BLUE_PIN, OUTPUT);
  if (STATUS_LED_RED_PIN != 255) pinMode(STATUS_LED_RED_PIN, OUTPUT);

  applyStates();
}

void statusLeds::on_start_play() {
<<<<<<< codex/implement-radio-led-control-plugin-y9d5pr
  _isPlaying = true;
=======
>>>>>>> main
  applyStates();
}

void statusLeds::on_stop_play() {
<<<<<<< codex/implement-radio-led-control-plugin-y9d5pr
  _isPlaying = false;
=======
>>>>>>> main
  applyStates();
}

void statusLeds::on_connect() {
  applyStates();
}

void statusLeds::on_ticker() {
  applyStates(true);
}
