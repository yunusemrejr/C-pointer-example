# Installation Guide

## C Pointer Demonstration Tool - Setup Instructions

This application requires a C compiler to build and run. Since the sandbox environment doesn't have a C compiler pre-installed, you'll need to compile and run this on your local machine.

## Prerequisites

You need one of the following C compilers:
- **GCC** (GNU Compiler Collection) - Recommended
- **Clang** - Alternative
- **MSVC** (Microsoft Visual C++) - For Windows

## Installation by Operating System

### Linux (Ubuntu/Debian)

```bash
# Install GCC and Make
sudo apt-get update
sudo apt-get install build-essential

# Verify installation
gcc --version
make --version
```

### Linux (Fedora/RHEL/Amazon Linux)

```bash
# Install GCC and Make
sudo dnf install gcc make

# Verify installation
gcc --version
make --version
```

### macOS

```bash
# Install Xcode Command Line Tools
xcode-select --install

# Verify installation
gcc --version
make --version
```

### Windows

**Option 1: MinGW-w64**
1. Download from: https://www.mingw-w64.org/
2. Install and add to PATH
3. Verify: `gcc --version`

**Option 2: Visual Studio**
1. Install Visual Studio Community (free)
2. Include "Desktop development with C++"
3. Use Developer Command Prompt

**Option 3: WSL (Windows Subsystem for Linux)**
1. Install WSL2
2. Follow Linux instructions above

## Building the Application

### Using Make (Recommended)

```bash
# Navigate to project directory
cd /path/to/pointer_demo

# Build the application
make

# Run the application
./pointer_demo
```

### Manual Compilation

```bash
# Compile with GCC
gcc -std=c11 -Wall -Wextra -Wpedantic -O2 -o pointer_demo main.c

# Run the application
./pointer_demo
```

### Windows (MinGW)

```cmd
gcc -std=c11 -Wall -Wextra -O2 -o pointer_demo.exe main.c
pointer_demo.exe
```

### Windows (MSVC)

```cmd
cl /W4 /O2 /Fe:pointer_demo.exe main.c
pointer_demo.exe
```

## Makefile Targets

Once you have Make installed, you can use these commands:

```bash
make          # Build the application
make clean    # Remove compiled files
make rebuild  # Clean and rebuild
make run      # Build and run
make debug    # Build with debug symbols
make memcheck # Run with valgrind (requires valgrind)
make help     # Show all available targets
```

## Troubleshooting

### "command not found" errors
- Ensure the compiler is installed
- Check that it's in your system PATH
- Try using the full path to the compiler

### Compilation errors
- Ensure you're using C11 or later standard
- Check that all source files are present
- Verify file permissions

### Permission denied when running
```bash
chmod +x pointer_demo
./pointer_demo
```

## Running Without Compilation

If you cannot install a C compiler, you can use online C compilers:

1. **OnlineGDB**: https://www.onlinegdb.com/online_c_compiler
2. **Replit**: https://replit.com/languages/c
3. **Programiz**: https://www.programiz.com/c-programming/online-compiler/

Simply copy the contents of `main.c` and `pointer_demo.h` into the online compiler.

## Verification

After successful compilation, you should see:

```
✓ Build successful!
Run with: ./pointer_demo
```

Then run the program and you'll see the interactive menu:

```
╔════════════════════════════════════════════════════════════╗
║        C POINTER DEMONSTRATION TOOL v2.0                   ║
║        Educational Interactive Pointer Examples            ║
╚════════════════════════════════════════════════════════════╝
```

## Support

If you encounter issues:
1. Check that your compiler supports C11 standard
2. Ensure all files are in the same directory
3. Verify file permissions
4. Check the README.md for additional information

---

**Note**: This application is designed to be educational and portable. It uses only standard C library functions and should compile on any system with a C11-compliant compiler.
