# Exercism Solutions

This repository contains solutions for Exercism exercises in multiple languages.

## Setup

### Ubuntu (WSL)

- Run `setup.sh` included in folder. The script will install exercism CLI binary into `~/.local/bin` then configure the workspace to current dir.
  - Current Exercism version is a fixed constant, please update the link accordingly for newer versions (current: 3.3.0).
  - Remember to manually configure the Exercism token.

## Testing

### C

```bash
make test && make memcheck && make clean
```

### C++

```bash
cmake -G "Unix Makefiles" -B build . && make -C build && rm -rf build
```

### Zig

```bash
zig test test_*.zig
```
