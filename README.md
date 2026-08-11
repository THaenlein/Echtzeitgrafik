# Echtzeitgrafik

Dieses Repository enthält Beispielprogramme und Hilfsdateien für Echtzeitgrafik-Experimente und -Übungen. Im Folgenden eine kurze Übersicht der Projektstruktur und Hinweise zum Bauen des Projekts.

## Projektstruktur (Auszug)

- CMakeLists.txt
  - Root-CMake-Konfiguration zum Erstellen der gesamten Lösung.
- src/
  - Quellcode-Verzeichnis. Enthält einzelne Beispielprojekte und Hilfsdateien.
  - Wichtige Unterverzeichnisse:
	- helper/
	  - RootDir.h.in — Template für die zur Build-Zeit erzeugte Header-Datei.
	- shared/
	  - Wiederverwendbare Header wie data.h und functions.h.
	- 01HelloWindow/
	  - Beispiel: main.cpp — Einfaches Fenster-Beispiel.
	- 02HelloTriangleImmediate/
	  - Beispiel: main.cpp — Einfaches Dreieck (Immediate).
	- 03HelloTriangleRetained/
	  - Beispiel: main.cpp — Einfaches Dreieck (Retained).
	- 04HelloRectangle/
	  - Beispiel: main.cpp — Rechteckdarstellung.
	- 05HelloRectangleIndexed/
	  - Beispiel: main.cpp — Indizierte Rechteck-Darstellung.
	- 06RotatingCube/
	  - Beispiel: main.cpp — Rotierender Würfel.
	- 07DebugCallback/
	  - Beispiel: main.cpp — Debug-Callback / Fehlerbehandlung.
	- 08Phong/
	  - Beispiel: main.cpp — Phong-Beleuchtungsmodell.
	- 09Texture/
	  - Beispiel: main.cpp — Einfache Textur-Anwendung.
	- 10Textures/
	  - Beispiel: main.cpp — Mehrere Texturen / Sampler.
	- 11ModelLoading/
	  - Beispiel: main.cpp — Laden von 3D-Modellen.
	- 12Font/
	  - Beispiel: main.cpp — Schrift-/Textdarstellung.
- include/
  - Dritthersteller-Header, z. B. `glm` (Mathematikbibliothek).
- out/
  - Build-Ausgaben und zur Build-Zeit erzeugte Dateien (z. B. generierte Header).

## Build-Voraussetzungen

- CMake >= 3.21
- Empfohlener Generator: Ninja
- Toolchain: MSVC (Visual Studio)
- C++ Standard: C++17

Beispiel (PowerShell):

```powershell
mkdir build
cd build
cmake -G "Ninja" -S .. -B .
cmake --build .
```

Oder mit Ninja direkt:

```powershell
cmake -G "Ninja" -S .. -B .
ninja
```

Die Build-Ausgabe landet im `out/`-Verzeichnis bzw. im vom CMake-Setup konfigurierten Build-Verzeichnis.

## Hinweise

- Beispiele sind als separate Unterprojekte in `src/` organisiert; die jeweiligen `main.cpp`-Dateien enthalten die Einstiegspunkte.
- Dateien mit der Endung `.in` (z. B. `src/helper/RootDir.h.in`) werden während des Builds als Vorlage verwendet und in generierte Header (z. B. `RootDir.h`) umgesetzt.
- Wenn zusätzliche Abhängigkeiten (z. B. Bild- oder Modellressourcen, Shader) verwendet werden, sind diese typischerweise in den jeweiligen Beispielordnern oder an einem dafür vorgesehenen Assets-Ordner abzulegen.
