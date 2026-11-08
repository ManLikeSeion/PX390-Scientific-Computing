# PX390 - Scientific Computing

C exercises and workshop work for the PX390 Scientific Computing module.

## Layout

- `src/` - current coursework and quiz solutions
- `legacy/srcs/` - earlier exercises retained for reference
- `legacy/builds/` - historical build output (ignored by Git)
- `build/` - local build output (ignored by Git)
- `.vscode/` - VS Code build and debugging configuration

## Building

The project uses GCC. From VS Code, open a `.c` file and run the default
**Build** task. The executable is written to `build/`.

To compile a source file manually:

```powershell
gcc src\quiz2q1.c -o build\quiz2q1.exe
```

Generated executables are intentionally excluded from version control.
