# statusLeds plugin

Индикация состояния радио на трех отдельных светодиодах:

- Зеленый (SMD2832): горит, когда идет воспроизведение.
- Синий (SMD2832): горит при подключении к Wi‑Fi, мигает 1 раз/сек при отсутствии Wi‑Fi (можно отключить).
- Красный: горит, пока устройство включено (плагин активен).

## Настройка

1. Плагин уже находится в `src/plugins/statusLeds`, дополнительных действий для подключения не требуется.
2. Укажите пины в `myoptions.h`:

```cpp
#define STATUS_LED_GREEN_PIN    16
#define STATUS_LED_BLUE_PIN     17
#define STATUS_LED_RED_PIN      5
#define STATUS_LED_BLUE_BLINK_WHEN_DISCONNECTED true
```

Опционально можно инвертировать уровни для «active-low» подключения:

```cpp
#define STATUS_LED_GREEN_INVERT true
#define STATUS_LED_BLUE_INVERT  true
#define STATUS_LED_RED_INVERT   true
```

Если какой-то светодиод не нужен, установите его пин в `255`.
