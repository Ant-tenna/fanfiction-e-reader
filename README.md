
# Fanfiction e-reader

## What is it?
A mini e-reader using an esp32 that hides what you're reading when it detects something near.


![Fanfiction e-reader](screenshot.png)


> Built in [Breadboard](https://breadboard.hackclub.com), a Hack Club program. This project took ~6.5 hours of work.



## What It Does

A fanfiction e-reader that powers off if it detects motion! So no one else can see what you're reading >:)


## How It Works

The circuit is captured in `breadboard-project.json`, and the firmware that runs it is in the `firmware/` folder. The ESP32 connects to an oled screen, the 2 buttons and an Obstacle Avoidance Module. The firmware must be put on the ESP32, the code of the project was made to make the oled screen display text when the Obstacle Avoidance Module doesn't detect anything near, with the two buttons you can change drom one line to another. When something is near, the oled screen will stop drawing text on the screen and turn black until the thing that the Obstacle Avoidance Module was detecting moves away.


## How to use it?
First you want to set up something to read! You can keep the silly story i made in less than 5 minutes or change it to other short story in the firmware code. With the buttons you can move up and down to see more lines, with the text being displayed on the oled mini screen. And if something is near, the screen will turn black quickly, until the thing (or person) that was near, moves away.



## Demo

- **Simulate it live:** [https://breadboard.hackclub.com/share/84](https://breadboard.hackclub.com/share/84), runs the firmware in the Breadboard simulator
- **View the design:** [https://taniwankenobi.github.io/breadboard-plays/p/84/](https://taniwankenobi.github.io/breadboard-plays/p/84/)


## Schematic

The editor snapshot is in `breadboard-project.json`.


## Bill of Materials

| Part | Quantity |
| --- | --- |
| breadboard-full | 1 |
| obstacle-avoidance-module | 1 |
| pushbutton | 2 |
| ssd1306-i2c | 1 |


## Firmware

Firmware files are in the `firmware/` folder.


## Build Journal

Build journal entries are kept in [`journals.md`](journals.md).


## Why did i made it?
I made this as a way to get more into electronics. This was a silly idea i had in my mind since i'm not allowed anymore to use my phone in school and i can't read the stuff i used to, i made this with the sensor so it could be more fun and learn how to connect everything together. I really enjoyed making this project and I hope i can make a 2.0 version in the future, with more features such as an sd to store the text, bigger screen and lots of other stuff. This project made me realize i can do more stuff of what i think im capable of :3
---


*Made in [Breadboard](https://breadboard.hackclub.com) — 6.5h of work*



<p align="center"><img src="https://cdn.hackclub.com/019efae7-6857-75a2-8bc1-2618087b4eae/a%20bred%20tanuki%20(3).png" width="64" alt="Breadboard mascot" /></p>
