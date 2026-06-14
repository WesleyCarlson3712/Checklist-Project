<<<<<<< HEAD
Checklist Project

A small console-based C++ checklist application. It stores a list of items (title, optional description, checked state) and supports add/remove/edit/toggle + save/load to a JSON file.

Requirements
- Windows, macOS, or Linux (source is portable but the included project is a Visual Studio .vcxproj)
- Visual Studio (recommended) with C++ workload: Visual Studio 2022 or newer (Visual Studio Community 2026 was used during development)
- A C++17-compatible compiler
- nlohmann/json (JSON for Modern C++) — header-only library

Getting the code
1. Clone the repository:
   git clone <repository-url>
   cd "Checklist-Project"

Installing the nlohmann/json dependency
You have multiple options:
- Install via vcpkg (recommended for Visual Studio):
  - Install vcpkg: https://github.com/microsoft/vcpkg
  - From the vcpkg root:
	  vcpkg install nlohmann-json
  - Integrate with Visual Studio (optional):
	  vcpkg integrate install
- Install via NuGet in Visual Studio:
  - In Solution Explorer, right-click the project -> Manage NuGet Packages -> Browse -> search for "nlohmann.json" and install.
- Or simply add the single-header file nlohmann/json.hpp into the project include path. The header can be downloaded from the library's GitHub releases.

Open and build with Visual Studio
1. Double-click Checklist-Project.vcxproj or open the folder/solution in Visual Studio.
2. Ensure the project includes an include path for the nlohmann/json header (if you added it manually) or that vcpkg/NuGet is set up.
3. Build (Debug or Release) from the IDE: Build -> Build Solution.

Build from the command line (MSBuild)
- Open a Developer Command Prompt for Visual Studio and run:
  msbuild Checklist-Project.vcxproj /p:Configuration=Release

Run the program
- From Visual Studio: Debug -> Start Without Debugging (Ctrl+F5) or run the compiled executable from the output folder (e.g., ./x64/Release/Checklist-Project.exe or ./Release/Checklist-Project.exe depending on configuration).
- From a terminal: execute the generated binary. The program runs in the console and displays a simple menu.

Usage
- The console menu supports:
  - Add item (enter title and optional description)
  - Remove item (by number)
  - Toggle item checked/unchecked
  - Edit item (change title/description)
  - Clear all items
  - Save items to a JSON file
  - Load items from a JSON file

Notes
- JSON files produced are human-readable and contain an array of items with fields: title, description, checked.
- The program uses zero-based indexing internally but displays items numbered starting at 1 to the user.

License
- No license file is included. Add one if you plan to publish the repository.

If you want, I can add a project-level vcpkg.json, a copy of the single-header for nlohmann/json, or a small CONTRIBUTING section. Let me know which you prefer.
=======
# Overview

The purpose of this project has been for me to learn to use the C++ programming language. Upon beginning this project I already had a small amount of C++ knowlege, but I have learned more in the time I have worked on this.
This program is a terminal based checklist that allows you to keep track of tasks with descriptions and completion statuses. The list can be manipulated in any way you need, and saved and loaded from your device.

[Software Demo Video](http://youtube.link.goes.here)

# Development Environment

I made this program entirely in visual studio using C++.
I used nlohmann/json to impliment the file saving and loading system.
It will need to be installed in order for this program to work

# Useful Websites

- [W3Schools C++ tutorial](https://www.w3schools.com/cpp/)
- [Copilot AI](https://copilot.microsoft.com/)

# Future Work

If I work on this more in the future I think it would be cool to create a graphical interface with proper buttons and displays.
>>>>>>> 85e558c3224c23426de8804e6dadc707a23edb52
