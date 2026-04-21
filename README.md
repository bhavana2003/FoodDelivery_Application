# FoodDelivery_Application

This is a food delivery application model. Small system design project written in C++ that demonstrates common design patterns (Factory, Singleton, Strategy) and a layered structure (models, managers, factories, services, strategies, utils).

## Project Structure

```
FoodDelivery/
├── main.cpp                # Application entry point
├── Foody.h                 # Top-level facade
├── factories/              # Order creation (Instant / Scheduled)
├── managers/               # Singletons: Order & Restaurant managers
├── models/                 # Domain types: User, Restaurant, MenuItem, Cart, Order...
├── services/               # NotificationService
├── strategies/payment/     # Card / UPI payment strategies
└── utils/                  # Time helpers
```

## Prerequisites

- A C++ compiler with C++11 (or later) support:
  - **Windows**: [MinGW-w64](https://www.mingw-w64.org/) (`g++`) or MSVC (`cl.exe`)
  - **Linux/macOS**: `g++` or `clang++`
- No external libraries — only the C++ standard library.

Verify your compiler:

```powershell
g++ --version
```

## Build & Run

Open a terminal in the project root (`FoodDelivery/`).

### Windows (PowerShell, with g++)

```powershell
g++ -std=c++17 main.cpp -o foody.exe
.\foody.exe
```

### Windows (cmd)

```cmd
g++ -std=c++17 main.cpp -o foody.exe
foody.exe
```

### Linux / macOS

```bash
g++ -std=c++17 main.cpp -o foody
./foody
```

> All other source files are header-only (`.h`) and are pulled in via `#include` from `main.cpp` and `Foody.h`, so only `main.cpp` needs to be passed to the compiler.

### Build with VS Code

If you are using the C/C++ extension, open `main.cpp` and run:

- **Terminal → Run Build Task…** → *C/C++: g++.exe build active file*

The resulting executable is placed next to `main.cpp`.

## Expected Flow

When you run the application, `main.cpp` simulates a happy-path user journey:

1. Initializes the `Foody` app with a few sample restaurants and menus.
2. Creates a `User` and searches restaurants near their address.
3. Selects a restaurant and prints its menu.
4. Adds a few menu items to the cart (`M001`, `M004`, `M005`) and prints the cart.
5. Checks out instantly via UPI payment and prints the order notification.

You should see output sections separated by `------` lines for each step, ending with the order confirmation from `NotificationService`.

## Troubleshooting

- **`undefined reference` or missing symbols**: make sure you compiled `main.cpp` (not an individual header) and that you are using C++11 or newer.
- **Garbled `₹` characters in the console**: switch the terminal to UTF-8 (PowerShell: `chcp 65001`).
- **Many "Destroying MenuItem:" lines**: expected — `~MenuItem()` prints on every destruction, including temporaries created when items are added to vectors. Remove the `cout` in `~MenuItem()` to silence it.

