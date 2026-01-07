
![ReichLogo](.github/assets/icon.png)

Reich is a minimal and simple operating system created purely for educational purposes.  
This project does not provide any practical functionality and is mainly designed to help understand the basics of booting, kernel development, and text-mode display.

---

## ✨ Features

- 🚀 Bootable via GRUB  
- 💻 Simple kernel written in C++  
- 🖥️ Displays **"Hello from C++ Kernel!"** centered on the screen  
- 👨‍💻 Shows author credit below the main message  
- 🌈 Animated colorful progress bar at the bottom of the screen  

---

## 🎯 Project Purpose

This project is meant as a learning exercise to explore:

- 📀 How to create a bootable ISO file  
- 🔧 Basics of bootloaders and the Multiboot standard  
- 🛠️ Using assembly for early boot stages  
- 🚧 Writing a freestanding C++ kernel  
- 🖱️ Direct output to video memory in text mode  

---

## ▶️ How to Run

### Prerequisites:

- 🧩 `nasm`  
- ⚙️ `g++` with `-m32` support  
- 🐧 `grub-mkrescue`  
- 🕹️ `qemu-system-i386` for running the OS  

### Running the project:

```bash
make run
