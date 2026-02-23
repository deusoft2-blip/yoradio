#ifndef STATUSLEDS_H
#define STATUSLEDS_H

#include "../../pluginsManager/pluginsManager.h"

class statusLeds : public Plugin {
public:
  statusLeds();
  void on_setup() override;
  void on_start_play() override;
  void on_stop_play() override;
  void on_connect() override;
  void on_ticker() override;

private:
  bool _blueBlinkState;
<<<<<<< codex/implement-radio-led-control-plugin-y9d5pr
  bool _isPlaying;
=======
>>>>>>> main
  void applyStates(bool fromTicker = false);
  void writeLed(uint8_t pin, bool value, bool invert);
};

#endif // STATUSLEDS_H
