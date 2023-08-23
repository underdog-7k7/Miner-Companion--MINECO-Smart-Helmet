# Smart-Helmet-for-Miners-with-Warning-System

ANIMESH PANDEY 

Working team: Animesh Pandey,Anirudh Vadera , Om Dhapodkar


This project aims at enhancing the existing wearable safety helmets for the mining industry with the concept of Internet of things and Miners in the mining area are prone to dangers that can't be detected by normal human senses (such as Carbon monoxide pocket leaks). A Smart Mining Helmet will be able to alert the miner whenever the area around him becomes unsafe with poisonous gases or unusually high temperature. The primary danger in the mines is mainly due to air quality around the miner, many toxic gases in the mine and some nontoxic gases present in the vicinity of the miner Which can greatly harm the miner health over the long term of his life. Our project focuses on a mine supervising system monitor using IOT with sensors attached on top of the helmet to give real-time surveillance with early-warning system on various harmful gases using a small buzzer and LED. In addition to that, once a area becomes unsafe the helmet acts as a broadcasting device which gives necessary warning to other helmets as well about the potential danger which are interconnected to each other using a real time Ad-hoc network of helmets.

The helmets would be equipped with An ESP MCU with wireless communication modules and multiple sensors that detect the nearby surroundings , the sensors will be able to detect the current situation of the nearby environment of the miner and send the data to the ESP MCU embedded on the helmet , The ESP MCU Will then decide whether the situation is dangerous or not for the miner , if the situation is not appropriate and there is a gas leak or abnormal temperature then the buzzer installed on the helmet will activate along with a red LED that will tell the miner that he should evacuate the area along with this the MCU Will transmit a SOS Broadcast message to other miner helmets and tell them to evacuate too, basically following a bottom up approach on warning the other miners , the SOS Will be flooded to the Ad hoc network analogous to a nuclear reaction where one SOS broadcast will lead to the entire mining group being warned without any 3rd party assistance such as a server or administrator. 

Technical Specification
Hardware Required:
1)ESP8266: The ESP8266 is a low-cost Wi-Fi microchip, with built-in TCP/IP networking software, and microcontroller capability, produced by Espressif Systems in Shanghai, China. The chip was popularized in the English-speaking maker community in August 2014 via the ESP-01 module, made by a third-party.
The ESP8266 module enables microcontrollers to connect to 2.4 GHz Wi-Fi, using IEEE 802.11 bgn. It can be used with ESP-AT firmware to provide Wi-Fi connectivity to external host MCUs, or it can be used as a self-sufficient MCU by running an RTOS-based SDK.
 
2)DHT11: The DHT11 is a basic, ultra-low-cost digital temperature and humidity sensor. It uses a capacitive humidity sensor and a thermistor to measure the surrounding air and spits out a digital signal on the data pin (no analog input pins needed). It's fairly simple to use but requires careful timing to grab data.
This sensor is used in various applications such as measuring humidity and temperature values in heating, ventilation and air conditioning systems. Weather stations also use these sensors to predict weather conditions. The humidity sensor is used as a preventive measure in homes where people are affected by humidity.
 
3)MQ135: The MQ-135 Gas sensor can detect gases like Ammonia (NH3), sulfur (S), Benzene (C6H6), CO2, and other harmful gases and smoke. Similar to other MQ series gas sensor, this sensor also has a digital and analog output pin.
 
4)Buzzer: A buzzer or beeper is an audio signaling device, which may be mechanical, electromechanical, or piezoelectric (piezo for short). Typical uses of buzzers and beepers include alarm devices, timers, train and confirmation of user input such as a mouse click or keystroke.
 When power is applied, current runs through the coil of wire inside the buzzer, which produces a magnetic field. The flexible ferromagnetic disk is attracted to the coil when the magnetic field is activated, then returns to rest when the magnetic field is off.
 
5)LED: The major uses of LED (Light Emitting Diodes) are to illuminate objects and even places. Its application is everywhere due to its compact size, low consumption of energy, extended lifetime, and flexibility in terms of use in various applications. Applications and uses of LEDs can be seen in: TV Backlighting.
 

6)Breadboard: A breadboard (sometimes called a plugblock) is used for building temporary circuits. It is useful to designers because it allows components to be removed and replaced easily. It is useful to the person who wants to build a circuit to demonstrate its action, then to reuse the components in another circuit


##FLOW DISCUSSED IN PROJECT DOC
![image](https://user-images.githubusercontent.com/110458390/202319510-fe8f112f-788e-49c3-9353-4107f857ab27.png)

TinkerCAD model simulation: https://www.tinkercad.com/things/4fPJXSMQtZN

3D-Model prototype: ![image](https://github.com/underdog-7k7/Smart-Helmet-for-Miners-with-Warning-System/assets/110458390/d1f90fe8-9e15-42fb-8a3d-b8472dd09b1d)

Images taken of the assembled helmet:
![image](https://github.com/underdog-7k7/Smart-Helmet-for-Miners-with-Warning-System/assets/110458390/a356be60-2435-426b-99a0-34899ad7a556)

