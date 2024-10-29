# Project Setup Guide

Follow the steps below to set up your project environment with MinGW, Visual Studio, and SDL2.

---

## Step 1: Download and Install Required Tools

### 1.1 Install MinGW64 (64-bit)
Follow the tutorial to download and install MinGW64:
- [Watch Video Tutorial](https://youtu.be/qH-9UAsI9h8?si=exETwfP0_ZF_HKZa)

### 1.2 Install Visual Studio Community Version
Download and install the latest version of Visual Studio from the official website:
- [Download Visual Studio](https://visualstudio.microsoft.com/downloads/)

### 1.3 Install Necessary Workloads in Visual Studio
Make sure the following workloads are installed through the Visual Studio Installer:
- **.NET desktop development**
- **Desktop development with C++**

---

## Step 2: Set Up SDL2 Libraries

### 2.1 Download SDL2 Libraries
Download the SDL2 libraries and extract them directly to your `C:/` drive.  
**Note:** Make sure the path is exactly `C:/SDL2_libraries_` to avoid any issues.  
[Download SDL2 Libraries](https://github.com/DeveloperAmrit/learn_SDL/releases/download/v1.0/SDL2_libraries_.zip)  

### 2.2 Create a New Visual Studio C++ Project
1. Open Visual Studio.
2. Create a new **Blank C++ Project**.

### 2.3 Add a New `main.c` File
1. Right-click on the `Source Files` folder in **Solution Explorer**.
2. Select **Add > New Item**.
3. Create a file named `main.c` (ensure the file extension is `.c` and not `.cpp`).

---

## Step 3: Connect SDL to Your Project

### 3.1 Configure Project Properties
1. Click **project** in Topmost toolbar and select **Project Properties**.  
   **Note:** Ensure the option is **projectname Properties** and not just **Properties**. This only appears after creating `main.c`.

### 3.2 Add Include Directories
1. In **Project Properties**, under **Configuration Properties**:
   - Select **C/C++ > General**.
   - Set the **Configuration** to **All Configurations**.
2. Add the following paths to **Additional Include Directories**:
   - `C:\SDL2_libraries_\SDL2-devel-2.30.8-VC\SDL2-2.30.8\include`
   - `C:\SDL2_libraries_\SDL2_image-devel-2.8.2-VC\SDL2_image-2.8.2\include`
   - `C:\SDL2_libraries_\SDL2_mixer-devel-2.8.0-VC\SDL2_mixer-2.8.0\include`
   - `C:\SDL2_libraries_\SDL2_ttf-devel-2.22.0-VC\SDL2_ttf-2.22.0\include`
3. Click **OK** and then **Apply**.

### 3.3 Add Library Directories
1. Go to **Linker > General** in **Project Properties**.
2. Add the following paths to **Additional Library Directories**:
   - `C:\SDL2_libraries_\SDL2-devel-2.30.8-VC\SDL2-2.30.8\lib\x64`
   - `C:\SDL2_libraries_\SDL2_image-devel-2.8.2-VC\SDL2_image-2.8.2\lib\x64`
   - `C:\SDL2_libraries_\SDL2_mixer-devel-2.8.0-VC\SDL2_mixer-2.8.0\lib\x64`
   - `C:\SDL2_libraries_\SDL2_ttf-devel-2.22.0-VC\SDL2_ttf-2.22.0\lib\x64`
3. Click **OK** and then **Apply**.

### 3.4 Link SDL Libraries
1. Go to **Linker > Input** in **Project Properties**.
2. Add the following to **Additional Dependencies**:
   - `SDL2.lib; SDL2main.lib; SDL2_image.lib; SDL2_mixer.lib; SDL2_ttf.lib`
3. Click **OK** and **OK** again.


### 3.5 Copying dll files
1. Open the toCopy in SDL_libraries_ folder `C:/SDL_libraries/toCopy`
2. Copy all dll files from the toCopy folder
3. Open your project in visual studio
4. Right click on project name file (bold and 2nd from top)
5. Click on **open folder in file explorer**
6. Paste all dll files here 
---

### Step 4: Build and run your project
1. Write code in main.c
2. Click on **build** button in topmost toolbar > **build solution**
3. Now, Click on **run without debugging**
---

You have to do step 3 each and every time you create a sdl project in visual studio.

You are all set 🎉
