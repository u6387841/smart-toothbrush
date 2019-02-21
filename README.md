# The Smart Toothbrush - README
## Introduction
My artefact is called the Smart Toothbrush. This toothbrush is essential for everyone to have as it motivates people to develop healthy brushing habits. Everytime you brush your teeth, this toothbrush uses the accelerometer attached to the end of the toothbrush to detect changes in movement and then posts this data to a webserver which can also be accessed by your designated dentist. This way through the concept of public shaming, users will want to make sure that they brush 2 - 3 times a day just to please the dentist and to maintain a positive self-image.

INCLUDE A PHOTO OF THE TOOTHBRUSH HERE

## Software
I used the esp-idf environment for this project instead of arduino because I found it easier to follow and it had all the required functions that was needed for this project.

In order to build and run this project, the esp-idf repository needs to be downloaded to your local computer. Then, a path to the repository must be added before the project can be run. The code below is what I used to export the path:
"export IDF_PATH=~esp/esp-idf"
"export PATH=$PATH:$HOME/esp/xtensa-esp32-elf/bin"

Platform IO will also be need to run this code and use the ESP 32 on the local machine. The toolchain that I used for this project can be found on the espressif website which is called the xtensa-esp32-elf toolchain. Once you start your project, you will need to update the Path to this folder as shown above. Some required python pacakges must also be installed. Furthermore, a driver may be need to be downloaded in order to detect the ESP 32 input on the machine depending on the machine that is being used. I used VSCode as my IDE when I was working on this project but any IDE with Platform IO capabilities can be used.

All the information on how to get started with the esp 32 with esp-idf can be found on the following website:
https://docs.espressif.com/projects/esp-idf/en/latest/get-started/index.html#get-esp-idf

In order to run this project, you will need the following commands. make menuconfig allows you to configure any settings and set up the ports on the machine. make flash will build and upload the project and make monitor will the run the project on your machine.

## Hardware
Required parts/tools:
1. ESP 32 microcontroller
2. Micro-B USB Cable (to connect to your machine)
3. Accelerometer GY 61
4. 5 jumper wires
5. Toothbrush (any type of toothbrush will work)
6. Hot glue to attach the accelerometer to the toothbrush
7. Soldering kit 

## How can this artefact be improved

## Contact Details
Please contact me if you would like to get involved. I can be contacted using the following email address:
u6387841@anu.edu.au 



licensing
does your project include a licence?
is your licence compatible with the rest of the ecosystem?