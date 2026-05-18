# osFree Janus Version (winver)

![Language: C](https://img.shields.io/badge/language-C%2062.2%25-blue)
![License: LGPL-2.1](https://img.shields.io/badge/license-LGPL%202.1-green)
![Platform: Win16](https://img.shields.io/badge/platform-Win16-lightgrey)
![Status: Alpha](https://img.shields.io/badge/status-alpha-red)

A clone of the classic Windows 3.x "About" utility (winver). This is part of the [osFree Win16 Personality](https://github.com/osfree-project/WIN16) project — an open-source implementation of the 16-bit Windows environment.

## 📖 About

This application displays the standard "About" dialog, extracting information from the system library `SHELL.DLL`. The dialog's appearance depends on the specific system implementation. It is a component of the **osFree Janus** project to create an open-source clone of Windows 3.0.

The project continues the original idea by Marcel Baur (1997) and is currently maintained by the osFree team.

## ✨ Features

- **Prioritized loading from SHELL.DLL**: The application attempts to load the `ShellAbout` function from the original library. If successful, it uses the system dialog.
- **Standalone mode**: If `SHELL.DLL` is unavailable, the application creates its own dialog with version, operating mode, and debug information.
- **Windows mode detection**: Correctly identifies and displays the system's operating mode:
  - `Real Mode`
  - `Standard Mode`
  - `386 Enhanced Mode`
- **Localization**: Supports English (`En.rc`) and Russian (`Ru.rc`) languages. Contributions for additional languages are welcome.
- **Debug support**: When a debug version of the system is present, a `DEBUG` prefix is shown.

## 🧩 Project Structure

| File | Description |
| :--- | :--- |
| `winver.c` | Main application source code |
| `winver.h` | Header file with resource identifiers |
| `makefile` | Build file for Open Watcom Make |
| `rsrc.rc` | Main resource file that includes language modules |
| `En.rc` | Resources for English |
| `Ru.rc` | Resources for Russian |
| `_wcc.cmd` / `_wcc.sh` | Auxiliary build scripts |

## 🤝 Contributing

We welcome your contributions! Please keep the following in mind:

- **Bug reports**: Create issues in the [Issues](https://github.com/osfree-project/winver/issues) section.
- **Pull requests**: Send your improvements and fixes.
- **Documentation and localization**: Help translating the interface into other languages is highly valuable.

## 📜 License

Distributed under the **GNU Lesser General Public License v2.1 (LGPL-2.1)**. See [LICENSE](LICENSE) for more details.

## 🔗 Related Projects

- [osFree Win16 Personality (WIN16)](https://github.com/osfree-project/WIN16) — the main project to create an open-source clone of Windows 3.x
- [osFree Project](https://github.com/osfree-project) — the parent project for an open-source OS/2 clone
- [Notepad](https://github.com/osfree-project/notepad) — a clone of Notepad
- [Taskman](https://github.com/osfree-project/taskman) — a clone of Task Manager

## 👤 Copyright

- Copyright (C) 1997 Marcel Baur
- Copyright (C) 2023 Yuri Prokushev and the [osFree](https://github.com/osfree-project) team

---

*Last updated: May 18, 2026*
