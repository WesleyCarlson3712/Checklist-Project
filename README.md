# Overview

The purpose of this project has been for me to learn to use the C++ programming language. Upon beginning this project I already had a small amount of C++ knowlege, but I have learned more in the time I have worked on this.
This program is a terminal based checklist that allows you to keep track of tasks with descriptions and completion statuses. The list can be manipulated in any way you need, and saved and loaded from your device.

[Software Demo Video](https://youtu.be/IYkUsYt63j8)

# Development Environment

I made this program entirely in visual studio using C++.
I used nlohmann/json to impliment the file saving and loading system.
It will need to be installed in order for this program to work

# Getting Started

Download the project and install dependencies with these commands.

## 1) Download the project from GitHub (recommended):
   click Code -> Download ZIP, then extract the ZIP to a folder.
   
## 2) Install nlohmann/json:

### Windows (PowerShell)
```powershell
git clone https://github.com/microsoft/vcpkg.git
.\vcpkg\bootstrap-vcpkg.bat
.\vcpkg\vcpkg install nlohmann-json
.\vcpkg\vcpkg integrate install
```

### macOS / Linux (bash)
```bash
git clone https://github.com/microsoft/vcpkg.git
./vcpkg/bootstrap-vcpkg.sh
./vcpkg/vcpkg install nlohmann-json
./vcpkg/vcpkg integrate install
```

## 3) Run the code:
Open the project in Visual Studio and build.

# Useful Websites

- [W3Schools C++ tutorial](https://www.w3schools.com/cpp/)
- [Copilot AI](https://copilot.microsoft.com/)

# Future Work

If I work on this more in the future I think it would be cool to create a graphical interface with proper buttons and displays.
