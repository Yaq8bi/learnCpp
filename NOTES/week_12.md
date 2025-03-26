- cmake crash course izle
-  https://www.youtube.com/watch?v=nlKcXPUJGwA
-  https://www.youtube.com/watch?v=SYKj6XZ8y2o
-  basit bir 
-  

# Evde bunu yap
## ESP32-C6
- ESP32-c6 devkit 1 n8,te UART C-portuna bağla
- PlatformIO, Upload & Monitor, terminal acar ve ony kullanarak ESP32nin terminalini izle/monitor.

## MCXN236
- usten, saddaki C-Portuna bagla. [Label'i MCU-Link olan port]
- MCUXpresso[vscode side panel], import repo, zephyr.
/*
Repository:
Zephyr   (https://github.com/zephyrproject-rtos/zephyr)
Revision:
v4.1.0   
Manifest file:
Enter the manifest file name (optional)
Name:
zephyr
Location: home/yaq8bi[Home folder]
*/

### X'e config project.
[X'e bas,proje folderi ustunde right click, confugure, zephyrSDK path]


---

# Alignment for data types importance for Microcontrollers
uint8_t  - 1 byte
uint16_t - 2 byte

```c++
struct BadAlignment {
    uint8_t a;
    uint16_t b;
    uint8_t c;
};

struct GoodAlignment {
    uint16_t a; /2byte
    uint8_t b;
    uint8_t c;
}
```

NON-Volatile memory examples include: Flash memory(SD-card), EEPROM(Electrically Erasable Programmable O Memory) and ROM.
Volatile memory examples include: RAM and Cache memory.
