# 📑 tabbed - Generic Tabbed Interface

**Container für Tab-Unterstützung in XEmbed-Anwendungen**

> **🔄 Umzug zu Codeberg**: Die aktive Entwicklung und Kollaboration findet jetzt auf [Codeberg](https://codeberg.org/Sergius/tabbed) statt. GitHub dient nur als Mirror.
> 
> **📦 Hauptprojekt**: [SARBS](https://codeberg.org/Sergius/SARBS) - [Homepage](https://sarbs.xyz/sarbs/)

Minimalistischer Tab-Container für XEmbed-fähige Programme - funktioniert perfekt mit surf, st und mehr.

## ✨ Features

### Kern-Funktionalität
- **XEmbed-Support** - Container für einbettbare X-Anwendungen
- **Universal** - Funktioniert mit allen XEmbed-fähigen Programmen
- **Minimalistisch** - Suckless-Philosophie, kein UI-Overhead
- **Konfigurierbar** - Anpassbar über config.h

### Integration
- **surf** - Tabs für den Suckless-Browser
- **st** - Terminal mit Tab-Support
- **zathura** - PDF-Viewer mit Tabs
- **...und mehr** - Jedes XEmbed-fähige Programm!

## ⚡ Installation

### Automatisch mit SARBS (empfohlen)
Wird durch das [SARBS-Installationsskript](https://codeberg.org/Sergius/SARBS) automatisch eingerichtet.

### Manuell
```bash
git clone https://codeberg.org/Sergius/tabbed.git
cd tabbed
sudo make install
```

## 🛠️ Nutzung

### surf mit Tabs (Browser)

```bash
tabbed -c surf -e
```

In SARBS ist dies bereits als Standard-Browser konfiguriert!

### st mit Tabs (Terminal)

```bash
tabbed -c st -w
```

### Allgemeine Syntax

```bash
tabbed [OPTIONS] PROGRAM -e/-w
```

**Wichtige Optionen:**
- `-c` - Schließt tabbed wenn der letzte Tab geschlossen wird
- `-d` - Detach-Modus (tabbed bleibt im Hintergrund)
- `-n NAME` - Setzt den WM_CLASS Namen

## ⌨️ Tastenkombinationen

Die wichtigsten Keybindings (siehe [config.h](config.h) für alle):

- `Ctrl+Shift+Return` - Neuer Tab
- `Ctrl+Shift+h` - Vorheriger Tab
- `Ctrl+Shift+l` - Nächster Tab
- `Ctrl+Shift+j` - Ersten Tab wechseln
- `Ctrl+Shift+k` - Letzten Tab wechseln
- `Ctrl+Shift+q` - Tab schließen
- `Ctrl+Tab` - Letzten Tab
- `Ctrl+[1-9]` - Zu Tab 1-9 wechseln

## 🎨 Konfiguration

### Via config.h

Anpassungen in `config.h`:
- Farben (Background, Foreground, Selected Tab)
- Schriftart
- Keybindings
- Tab-Position
- Und mehr...

Nach Änderungen:
```bash
sudo make clean install
```

### Farben mit Xresources

tabbed kann Farben aus Xresources lesen (mit entsprechendem Patch):

```sh
tabbed.foreground: #ebdbb2
tabbed.background: #282828
tabbed.selfgcolor: #ebdbb2
tabbed.selbgcolor: #458588
```

## 🔧 Erweiterte Nutzung

### Als Standard-Browser in SARBS

In deiner `~/.config/mimeapps.list`:
```ini
[Default Applications]
text/html=surf.desktop
x-scheme-handler/http=surf.desktop
x-scheme-handler/https=surf.desktop
```

surf.desktop:
```desktop
[Desktop Entry]
Type=Application
Name=Surf Browser
Exec=tabbed -c surf -e
```

### Mit dmenu kombinieren

Neue URL in neuem Tab öffnen:
```bash
url=$(echo "" | dmenu -p "URL:") && xdotool search --class "surf" windowfocus key ctrl+shift+Return && xprop -id $(xdotool getactivewindow) -f _SURF_URI 8s -set _SURF_URI "$url"
```

## 📚 Weitere SARBS-Komponenten

- **[SARBS Hauptprojekt](https://codeberg.org/Sergius/SARBS)** - Auto-Rice Bootstrapping
- **[dotfiles](https://codeberg.org/Sergius/dotfiles)** - Konfigurationsdateien
- **[dwm](https://codeberg.org/Sergius/dwm)** - Window Manager
- **[surf](https://codeberg.org/Sergius/surf)** - Web Browser (perfekt mit tabbed!)
- **[st](https://codeberg.org/Sergius/st)** - Terminal Emulator
- **[dmenu](https://codeberg.org/Sergius/dmenu)** - Application Launcher

## 🤝 Credits

- **[suckless.org](https://tools.suckless.org/tabbed/)** - Original tabbed
- **Enno Boland** - Original Autor

## 📄 Lizenz

Siehe [LICENSE](LICENSE) Datei.

---

**📧 Kontakt**:
- [Codeberg Issues](https://codeberg.org/Sergius/tabbed/issues)
- [GitHub Issues](https://github.com/Sergi-us/tabbed/issues) (Mirror)
- [SARBS Homepage](https://sarbs.xyz/kontakt/)
