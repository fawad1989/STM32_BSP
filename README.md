# STM32L432KC — Bare-Metal Driver Development Journal
> **Goal:** Build a complete LL / Driver / HAL stack from scratch for a UGV with motors, addressable LEDs, and I2C sensors. Eventually run FreeRTOS and explore swarm robotics.
> 
> **Hardware:** STM32L432KC (Cortex-M4, 256KB Flash, 64KB SRAM)  
> **Host OS:** Ubuntu  
> **Editor:** VSCode  
> **Toolchain:** arm-none-eabi-gcc + CMake + Ninja + OpenOCD  

---

## Journal Index

| Day | Date | Topic | Status |
|-----|------|--------|--------|
| 1 | 17-09-2026 | Toolchain Setup | ✓ Done |
| 2 | 18-09-2026 | Folder structure setup | ✓ Done |

---

## Day 1 — 17/09/2026 · Toolchain Setup

###  Objective
Install and verify the complete bare-metal development toolchain on Ubuntu without relying on STM32CubeIDE.

---

###  Toolchain Architecture

```
[ VSCode ]               ← Editor + UI
[ CMake ]                ← Build system (describes WHAT to build)
[ Ninja ]                ← Build executor (fast, runs the actual build)
[ arm-none-eabi-gcc ]    ← Cross compiler (compiles for ARM, runs on x86)
[ OpenOCD ]              ← On-chip debugger (bridges GDB ↔ ST-Link)
[ GDB / gdb-multiarch ]  ← Debugger frontend
[ ST-Link tools ]        ← USB probe access + flashing utility
```

**Debug chain at runtime:**
```
VSCode → GDB → :3333 → OpenOCD → ST-Link USB → SWD pins → STM32L432
```

---

### Step 1 — Install Core Packages

```bash
sudo apt update

# ARM cross-compiler + binutils
sudo apt install gcc-arm-none-eabi binutils-arm-none-eabi

# Build system
sudo apt install cmake ninja-build make

# On-chip debugger
sudo apt install openocd

# GDB (multiarch version since arm-none-eabi-gdb may not be in apt)
sudo apt install gdb-multiarch

# ST-Link CLI tools (for flashing + probing without OpenOCD)
sudo apt install stlink-tools
```

---

### Step 2 — USB Access (udev Rules)

> ⚡ **Check before applying.** If ST-Link works without `sudo`, skip this step entirely.

**Test first (board plugged in, no sudo):**
```bash
st-info --probe
openocd -f interface/stlink.cfg -f target/stm32l4x.cfg
```

**If it works → skip to Step 3.**

**If you get permission errors → apply udev rules:**
```bash
sudo cp /usr/share/openocd/contrib/60-openocd.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules
sudo udevadm trigger
sudo usermod -aG plugdev $USER
# Log out and log back in, then re-test
```

> **What udev rules do:** When you plug in a USB device, Linux checks `/etc/udev/rules.d/` for matching rules by vendor:product ID. ST-Link uses `VID:PID 0483:374B`. The rule grants `plugdev` group members read/write access without needing root.

---

### Step 3 — VSCode Extensions

```bash
code --install-extension ms-vscode.cpptools       # C/C++ IntelliSense
code --install-extension ms-vscode.cmake-tools    # CMake integration
code --install-extension marus25.cortex-debug     # ARM debug via OpenOCD/GDB
code --install-extension twxs.cmake               # CMake syntax highlighting
```

---

### Step 4 — Probe Test

```bash
openocd -f interface/stlink.cfg -f target/stm32l4x.cfg
# Ctrl+C to exit after confirming output
```

> **Note:** OpenOCD is a server — it sits and waits for GDB to connect on port 3333. You don't need it running until you're debugging. Normal workflow:
> - Terminal 1: `openocd` (leave running)
> - Terminal 2: `gdb-multiarch` (connects to :3333)
> - Or: VSCode Cortex-Debug manages both automatically on F5.

---

### Step 5 — Final Verification

```bash
arm-none-eabi-gcc --version
gdb-multiarch --version
cmake --version
ninja --version
```

---

###  Verification Results

| Tool | Version | Status |
|------|---------|--------|
| arm-none-eabi-gcc | 13.2.1 (15:13.2.rel1-2) | ✓ |
| gdb-multiarch | — | ✓ (use instead of arm-none-eabi-gdb) |
| cmake | 3.28.3 | ✓ |
| ninja | 1.11.1 | ✓ |
| openocd | 0.12.0 | ✓ |
| st-info --probe | Detected STM32L41x_L42x | ✓ |

---

###  Probe Output (Reference)

```
Found 1 stlink programmers
  version:    V2J48S35
  serial:     066FFF565382515067075022
  flash:      262144 (pagesize: 2048)
  sram:       49152
  chipid:     0x435
  dev-type:   STM32L41x_L42x
```

```
Info : STLINK V2J48M35 (API v2) VID:PID 0483:374B
Info : Target voltage: 3.256131
Info : [stm32l4x.cpu] Cortex-M4 r0p1 processor detected
Info : [stm32l4x.cpu] target has 6 breakpoints, 4 watchpoints
Info : starting gdb server for stm32l4x.cpu on 3333
Info : Listening on port 3333 for gdb connections
```

**What this tells us about the chip:**

| Field | Value | Meaning |
|-------|-------|---------|
| `VID:PID 0483:374B` | ST-Link v2 | USB identity used by udev rules |
| `Target voltage: 3.256V` | ~3.3V | Chip is powered correctly |
| `Cortex-M4 r0p1` | Core revision | Compiler flag: `-mcpu=cortex-m4` |
| `6 breakpoints` | Hardware BP | Can pause at 6 locations simultaneously |
| `4 watchpoints` | Hardware WP | Can watch 4 memory addresses for changes |
| `flash: 262144` | 256 KB | Our code space |
| `sram: 49152` | 48 KB | Our RAM (stack + heap + globals) |

---

###  Known Issues & Notes

- `arm-none-eabi-gdb` is **not available** via apt on this Ubuntu version. Use `gdb-multiarch` instead — it supports ARM targets identically.
- udev rules were **not needed** — ST-Link was accessible without sudo out of the box.

---

###  Next Session — Day 2

- [✓] Create project folder structure
- [ ] Write `CMakeLists.txt` for STM32L432KC
- [ ] Understand the linker script (`.ld`) and startup file (`.s`)
- [ ] Understand STM32 memory map (Flash at `0x08000000`, SRAM at `0x20000000`)
- [ ] First build: compile an empty `main.c` and produce a `.elf`

Step : 1 - Folder structure
Execute the following command in the terminal 
```
mkdir -p BASE_FOLDER/stm32l432kc/{cmake,linker,startup}
mkdir -p BASE_FOLDER/stm32l432kc/Core/{Inc,Src}
mkdir -p BASE_FOLDER/stm32l432kc/Drivers/CMSIS/Include
mkdir -p BASE_FOLDER/stm32l432kc/Drivers/MyLL/{Inc,Src}
mkdir -p BASE_FOLDER/stm32l432kc/Drivers/MyDrivers/{Inc,Src}
mkdir -p BASE_FOLDER/stm32l432kc/UGV/{Inc,Src}
mkdir -p BASE_FOLDER/stm32l432kc/Middleware
mkdir -p BASE_FOLDER/stm32l432kc/build

touch BASE_FOLDER/stm32l432kc/CMakeLists.txt
touch BASE_FOLDER/stm32l432kc/openocd.cfg
touch BASE_FOLDER/stm32l432kc/cmake/stm32l432kc.cmake
touch BASE_FOLDER/stm32l432kc/Core/Inc/main.h
touch BASE_FOLDER/stm32l432kc/Core/Src/main.c
```
---
