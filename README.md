# Project Setup Guide

## Step 1: Download and Install Required Tools

### 1.1 Download MinGW64 (64-bit)
Follow the video tutorial to install MinGW64:
- [Download MinGW64](https://youtu.be/qH-9UAsI9h8?si=exETwfP0_ZF_HKZa)

### 1.2 Download Visual Studio Community Version
Download Visual Studio Community version from the official website:
- [Download Visual Studio](https://visualstudio.microsoft.com/downloads/)

### 1.3 Install Necessary Workloads in Visual Studio
Open the Visual Studio Installer and make sure to install the following workloads:
- **.NET desktop development**
- **Desktop development with C++**

### 1.4 Download vcpkg for Package Management
Download and install vcpkg, a tool to manage C++ libraries:
- [Download vcpkg](https://github.com/microsoft/vcpkg)

Store `vcpkg` in: `C:\the_vcpkg_folder\<here>`

### 1.5 Install SDL2 Using vcpkg
Follow this video to install SDL2 via vcpkg:
- [Install SDL2](https://youtu.be/MTIUfkkbxSE?si=NFkwy1zaZH3t8s0k)

---

## Step 2: Setting Up the Project in Visual Studio

### 2.1 Create a New Blank C++ Project
Open Visual Studio and create a new blank C++ project.

### 2.2 Setup Libraries and Console

1. **Open Project Properties:**
   - Right-click on the project folder name in the Solution Explorer.
   - Select **Properties** (at the bottom).

2. **Select All Configurations:**
   - From the top-left dropdown menu, select **All Configurations**.

3. **Linker Settings:**
   - Go to **Linker > System**.
   - Ensure that the **Subsystem** is set to **Console**. If not, select **Console** from the dropdown.
   - Click **Apply**.

4. **Input Settings (Debug Configuration):**
   - From the top-left configuration dropdown menu, select **Debug**.
   - Go to **Linker > Input**.
   - Add `SDL2maind.lib` to **Additional Dependencies**.
   - Click **Apply**.

5. **Input Settings (Release Configuration):**
   - From the top-left configuration dropdown menu, select **Release**.
   - Go to **Linker > Input**.
   - Add `SDL2main.lib` to **Additional Dependencies**.
   - Click **Apply**.
   - Click **OK** to save and close the properties.

---

## Step 3: Creating the `main.c` File

1. Right-click on **Source Files** in the Solution Explorer.
2. Select **Add > New Item**.
3. Choose **C++ File (.cpp)**, name it `main.c`.

---

## Step 4: Writing Code and Running the Project

Write your code in `main.c`, then run the project using the **Run Without Debugging** button in Visual Studio.

---

You're all set! 🎉
