# Asio Async TCP Chat

This is a simple asynchronous TCP chat application using [Asio](https://think-async.com/) and C++. It includes both a client and server using `asio::async_read_some` and `asio::async_write`.

## 🔧 Requirements

- CMake (3.15+)
- [vcpkg](https://github.com/microsoft/vcpkg)
- A C++17 compatible compiler

## 📦 Dependencies

This project uses:

- `asio` (header-only)
- `Threads` (standard with most platforms)

Install Asio with vcpkg:

```bash
vcpkg install asio
```

## 🛠️ Building the Project

### Step 1: Clone the repository and enter the directory

```bash
git clone https://github.com/penguiza/asio-async-tcp.git
cd asio-async-tcp
```

### Step 2: Configure with CMake

```bash
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=C:/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
```

### Step 3: Build

```bash
cmake --build build
```

## 🚀 Running

Open two terminals:

### Terminal 1 (server)

```bash
./build/async_server
```

### Terminal 2 (client)

```bash
./build/async_client
```

## 📄 License

MIT License
