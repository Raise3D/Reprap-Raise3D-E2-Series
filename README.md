# Reprap-Raise3D-E2-Series  
Modified Reprap firmware for Raise3D E2 Series Printers.  

## Official website
* [Raise3D Official Website](https://www.raise3d.com)

## Update History:  

#### V0.2:  
* Fixed the problem that the z-axis is too high for pausing and resuming printing when the nozzle is switched.  
* Optimized the filter function of fracturing filament detection to reduce noise alarm.
* Increased the upper limit protection of heating temperature. When the current temperature exceeds the maximum allowable temperature, it will alarm and lower the temperature.
* Fixed the problem that the right nozzle is outside the platform when the model is printed against the edge of the platform in Mirror Mode.
* Fixed the problem that the temperature of the left and right nozzles drops when the printer starts printing in Duplication Mode and Mirror Mode.
* Fixed the problem that the printing flowrate setting does not take effect on the right nozzle in Duplication Mode and Mirror Mode 

## Compilation guide:  
### Instructions under windows
=================================================================

1.Download and install the gcc cross-compiler:
You need version 2018-q2-update.You can download an installer for this version from https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads.

2.Download and install Eclipse IDE for C/C++ Developers version 2018-09, from http://www.eclipse.org/downloads/eclipse-packages/. You do not need the Arduino add-on.

3.Download and install GNU Arm Eclipse from https://sourceforge.net/projects/gnuarmeclipse/files/Build%20Tools/gnuarmeclipse-build-tools-win64-2.6-201507152002-setup.exe/download. This provides versions of make.exe, rm.exe and other tools without the 8192-character command line limitation of some other versions.

4.Modify your PATH environment variable to include the 'bin' folder of the GNU ARM Eclipse installation. For example "C:\Program Files\GNU ARM Eclipse\Build Tools\2.6-201507152002\bin"

5.Run "which rm" and "which make" to make sure that rm and make will be fetched from that folder.

6.In Eclipse create new workspace C:/Eclipse/Firmware. Then exit Eclipse.

7.Download this github project as a zip file and unzip it into C:/Eclipse/Firmware.Don't unzip it into ReprapFirmware directory.

8.Load Eclipse and tell it to import all projects.

9.The build depends on the Eclipse workspace variable 'ArmGccPath" being set to the directory where your arm-none-eabi-g++ compiler resides. For example "C:\Program Files (x86)\GNU Tools ARM Embedded\7 2018-q2-update\bin" on Windows. To set it, go to Windows -> Preferences -> C/C++ -> Build -> Build Variables and click "Add..."

10.Build CoreNG first, also build FreeRTOS, RRFLibraries and CANlib if needed. Then clean and build RepRapFirmware (the clean step is needed to make Eclipse notice that the output library files in the other projects have been built). The Duet WiFi and Duet Ethernet builds of RRF use the SAM4E_RTOS builds of CoreNG and RRFLibraries and the SAM4E build of FreeRTOS. The Duet Maestro uses the SAM4S_RTOS build of CoreNG and RRFLibraries, and the SAM4S build of FreeRTOS. The Duet085 build of RRF (which also runs on the Duet06) uses the SAM3X build of CoreNG and RRFLibraries. The RADDS build of RRF uses the RADDS_RTOS build of CoreNG and the SAM3X_RTOS build of RRFLibraries.

Note: you do not need to build the DuetWiFiSocketServer project, but it does need to be in the workspace because the RepRapFirmware project uses one of its include fies.

### Instructions under macOS
=================================================================

Using Homebrew-Cask makes it very easy to install new software on macOS: https://caskroom.github.io/

1. Download and install the gcc-arm-embedded: brew cask install gcc-arm-embedded

3. Download and install Eclipse for C++ : brew cask install eclipse-cpp

4. Download or clone the RepRapFirmware, CoreNG, FreeRTOS and DuetWiFiSocketServer projects into your workspace. Keep the folder names as is.

5. Open Eclipse and import RepRapFirmware, FreeRTOS and CoreNG projects.

6. Right click "RepRapFirmware" project and select Properties. Go To "C/C++ Build -> Settings" and change the path: /usr/local/bin/ (or some other other path where arm-none-eabi-g++ and other binaries are located)

7. Do the same for CoreNG project.

8. Build CoreNG and FreeRTOS first, then RepRapFirmware. The Duet WiFi and Duet Ethernet builds of RRF use the SAM4E build of CoreNG. The Duet085 build of RRF (which also runs on the Duet06) uses the SAM3X build of CoreNG. The RADDS build of RRF has its own build of CoreNG.

### Important Notes:  
* Never change the serial port baudrate settings, this will cause the touchscreen cannot connect to the motion controller board.  
* Never change any serial communication protocol or it will make the touchscreen unresponding.  
* 
