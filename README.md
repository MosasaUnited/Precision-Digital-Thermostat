# Precision Digital Thermostat 🌡️

![Precision Digital Thermostat](https://img.shields.io/badge/Download%20Latest%20Release-Click%20Here-blue?style=for-the-badge&logo=github)

Welcome to the **Precision Digital Thermostat** repository! This project features a three-zone thermostat designed to provide accurate temperature readings and control for your heating and cooling systems. It uses three DS18B20 temperature probes to monitor temperatures in real-time, displaying the information on an OLED screen. Users can easily navigate through zones and adjust setpoints with three push-buttons. This project is crafted by Bocaletto Luca.

## Table of Contents

- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Features

- **Three-Zone Control**: Monitor and control three different zones independently.
- **Real-Time Display**: View each zone's current temperature and setpoint on an OLED screen.
- **Easy Navigation**: Use three push-buttons to switch between zones and adjust setpoints.
- **Relay Outputs**: Control heating and cooling systems through three relay outputs.
- **Open Source**: This project is open for anyone to use and improve upon.

## Hardware Requirements

To build your own Precision Digital Thermostat, you will need the following hardware components:

- **Microcontroller**: An Arduino board (e.g., Arduino Uno or Nano).
- **Temperature Probes**: Three DS18B20 temperature sensors.
- **OLED Display**: A compatible OLED screen (e.g., 128x64).
- **Relay Module**: Three-channel relay module for controlling heating and cooling.
- **Push Buttons**: Three momentary push buttons for user input.
- **Breadboard and Jumper Wires**: For prototyping and connections.

## Software Requirements

Ensure you have the following software installed:

- **Arduino IDE**: The latest version of the Arduino IDE for coding and uploading.
- **Libraries**: Install the following libraries through the Library Manager:
  - **OneWire**: For communication with the DS18B20 sensors.
  - **DallasTemperature**: For easy temperature reading from the sensors.
  - **Adafruit GFX**: For graphics support on the OLED display.
  - **Adafruit SSD1306**: For controlling the OLED display.

## Installation

1. **Clone the Repository**:
   Open your terminal and run the following command:
   ```
   git clone https://github.com/MosasaUnited/Precision-Digital-Thermostat.git
   ```

2. **Install Required Libraries**:
   Open the Arduino IDE and navigate to `Sketch > Include Library > Manage Libraries`. Search for and install the required libraries mentioned above.

3. **Upload the Code**:
   Open the `PrecisionDigitalThermostat.ino` file in the Arduino IDE. Connect your Arduino board and select the correct board and port. Click on the upload button to upload the code to your Arduino.

4. **Connect Hardware**:
   Follow the schematic provided in the repository to connect the hardware components correctly.

5. **Run the Program**:
   Once everything is connected, power up your Arduino. The OLED display should show the temperatures for each zone.

## Usage

After installation, using the Precision Digital Thermostat is straightforward:

- **View Temperature**: The OLED screen will display the current temperature for each zone.
- **Adjust Setpoints**: Use the push buttons to navigate to the desired zone and adjust the setpoint.
- **Control Outputs**: The system will activate the relay outputs based on the setpoints and current temperatures.

For more detailed instructions and troubleshooting, check the **Releases** section [here](https://github.com/MosasaUnited/Precision-Digital-Thermostat/releases).

## Contributing

Contributions are welcome! If you would like to contribute to the Precision Digital Thermostat, please follow these steps:

1. **Fork the Repository**: Click the "Fork" button at the top right of the repository page.
2. **Create a New Branch**: Create a new branch for your feature or fix.
   ```
   git checkout -b feature/YourFeature
   ```
3. **Make Changes**: Implement your changes and commit them.
   ```
   git commit -m "Add your message here"
   ```
4. **Push Changes**: Push your changes to your forked repository.
   ```
   git push origin feature/YourFeature
   ```
5. **Create a Pull Request**: Go to the original repository and click on "New Pull Request".

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact

For any inquiries or feedback, feel free to reach out:

- **Author**: Bocaletto Luca
- **Email**: [bocaletto@example.com](mailto:bocaletto@example.com)
- **GitHub Profile**: [Bocaletto](https://github.com/Bocaletto)

## Additional Resources

For further information, please visit the [Releases](https://github.com/MosasaUnited/Precision-Digital-Thermostat/releases) section for downloadable files and updates.

![Thermostat Schematic](https://example.com/thermostat-schematic.png)

## Acknowledgments

Special thanks to the contributors and community members who have helped make this project a reality. Your support is invaluable.

---

Feel free to explore, modify, and enjoy your Precision Digital Thermostat!