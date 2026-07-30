# Fanfiction e-reader



![Fanfiction e-reader](screenshot.png)


> Built in [Breadboard](https://breadboard.hackclub.com), a Hack Club program. This project took ~7 hours of work.



## What It Does

A fanfiction e-reader that powers off if it detects motion! So no one else can see what you're reading >:)


## How It Works

The circuit is captured in `breadboard-project.json`, and the firmware that runs it is in the `firmware/` folder.


## How To Use It

With the buttons you can move up and down to see more lines, with the text being displayed on the oled mini screen while also showing how is the light for reading. And if something is near, the screen will turn on a panic mode, displaying the actual temperature on the screen, until the thing (or person) that was near, moves away. You can also activate this with the black button. Also each time you change the "page" or panic mode is activated a buzzer emits a "beep" sound.


## Demo

- **Simulate it live:** [https://breadboard.hackclub.com/share/84](https://breadboard.hackclub.com/share/84), runs the firmware in the Breadboard simulator
- **View the design:** [https://taniwankenobi.github.io/breadboard-plays/p/84/](https://taniwankenobi.github.io/breadboard-plays/p/84/)


## Schematic

The editor snapshot is in `breadboard-project.json`.


## Bill of Materials

| Part | Quantity |
| --- | --- |
| breadboard-full | 1 |
| buzzer-active | 1 |
| dht11 | 1 |
| led-red | 1 |
| obstacle-avoidance-module | 1 |
| photoresistor-sensor | 1 |
| pushbutton | 3 |
| resistor | 1 |
| ssd1306-i2c | 1 |


## Firmware

Firmware files are in the `firmware/` folder.


## Build Journal

Build journal entries are kept in [`journals.md`](journals.md).


---



*Made in [Breadboard](https://breadboard.hackclub.com) — 7h of work*



<p align="center"><img src="https://cdn.hackclub.com/019efae7-6857-75a2-8bc1-2618087b4eae/a%20bred%20tanuki%20(3).png" width="64" alt="Breadboard mascot" /></p>