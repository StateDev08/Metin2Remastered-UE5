# Metin2 Remastered — Unreal Engine 5.8

Ein Fan-Remake von Metin2 in Unreal Engine 5.8 mit C++ und Blueprints.

## Projektstruktur

```
Source/
├── Metin2Remastered.Target.cs          — Game Build Target
├── Metin2RemasteredEditor.Target.cs    — Editor Build Target
└── Metin2Remastered/
    ├── Metin2Remastered.Build.cs       — Module Build Rules
    ├── Public/
    │   ├── Metin2Remastered.h          — Module Header
    │   ├── Metin2GameMode.h            — Base Game Mode
    │   ├── Metin2Character.h           — Base Character (Stats, Input, Combat)
    │   └── Characters/
    │       ├── Metin2Warrior.h         — Warrior (Combo-System)
    │       └── Metin2Sura.h            — Sura (Magic-System)
    └── Private/
        ├── Metin2Remastered.cpp        — Module Implementation
        ├── Metin2GameMode.cpp
        ├── Metin2Character.cpp
        └── Characters/
            ├── Metin2Warrior.cpp
            └── Metin2Sura.cpp

Content/
├── Characters/
│   └── Metin_Characters/
│       └── Male/
│           ├── Warrior/   — Modell, Animationen (Idle/Walk/Run/Hit-Combo), Blueprint
│           └── Sura/      — Modell, Haare, Blueprint
├── Maps/
│   ├── OrcValley/         — Orc-Tal Map
│   ├── Firelands/         — Feuerland Map
│   ├── GhostForest/       — Geisterwald Map
│   ├── IceMountain/       — Eisberg Map
│   └── YongbiDesert/      — Yongbi-Wüste Map
├── Materials/             — Landscape-Materialien pro Map
├── Metin-Systems/         — HairChangingSystem
├── Megascans/             — Quixel Megascans Assets
├── AutoLandscape/         — Landscape-Materialien & Texturen
└── Blueprints/            — Zusätzliche Blueprints (BP_Hair_War_Male)
```

## Voraussetzungen

- **Unreal Engine 5.8** (Epic Games Launcher)
- **Visual Studio 2022** (mit C++ Game Development Workload)
- Windows 10/11

## Projekt öffnen

1. UE 5.8 über den Epic Games Launcher installieren
2. Visual Studio 2022 mit "Game Development with C++" Workload installieren
3. Repository klonen: `git clone https://github.com/StateDev08/Metin2Remastered-UE5.git`
4. `Metin2Remastered.uproject` Rechtsklick → "Generate Visual Studio project files"
5. Projekt in UE5 öffnen oder `.sln` in Visual Studio öffnen
6. Standard-Map: `ThirdPersonMap` (Editor Startup Map)

## C++ Architektur

### Module: `Metin2Remastered`

| Klasse | Beschreibung |
|--------|-------------|
| `AMetin2GameMode` | Basis-GameMode für Spielregeln und Spawning |
| `AMetin2Character` | Basis-Charakter mit Stats (HP/MP/ATK/DEF), Enhanced Input, Combat |
| `AMetin2Warrior` | Warrior — Nahkampf-Klasse mit Combo-System (bis 7 Hits) |
| `AMetin2Sura` | Sura — Hybrid-Klasse mit Magie-System (Mana, Spell Casting) |

### Abhängigkeiten

- `EnhancedInput` — Neues Input-System (UE5 Standard)
- `GameplayAbilities` / `GameplayTags` / `GameplayTasks` — GAS-Vorbereitung
- `UMG` / `Slate` / `SlateCore` — UI-Framework

## Aktivierte Plugins

- **ModelingToolsEditorMode** — 3D-Modellierung im Editor
- **Volumetrics** — Volumetrische Effekte (Wolken, Nebel)
- **Water** — Wasser-System
- **EnhancedInput** — Neues Input-System

## Features

- 5 verschiedene Maps basierend auf Metin2-Gebieten
- C++ Basis-Klassen für alle Charaktere mit Stats-System
- Warrior mit Combo-System (One-Hand Sword: 7 Combo-Animationen, Timer-basierter Reset)
- Sura mit Magie-System (Mana-Management, Spell Casting)
- Enhanced Input Integration (WASD, Maus, Attack-Action)
- Damage-System mit Defense-Berechnung
- Hair-Changing-System (Blueprint)
- Landscape-Materialien mit Virtual Textures
- Lumen Global Illumination & Virtual Shadow Maps

## Rendering-Einstellungen

- DirectX 12 (Standard-RHI) mit SM5 + SM6 Support
- Lumen Reflections & Global Illumination
- Virtual Shadow Maps
- Virtual Textures
- Mesh Distance Fields
- Kein Ray-Tracing (deaktiviert, für Performance)

## Build

```bash
# Visual Studio Solution generieren (Windows)
# Rechtsklick auf .uproject → "Generate Visual Studio project files"

# Oder über UnrealBuildTool:
UnrealBuildTool.exe Metin2Remastered Win64 Development
```

## Hinweise

- Das Projekt nutzt sowohl C++ als auch Blueprints — C++ für Gameplay-Logik, Blueprints für Level-Design und Asset-Referenzen
- **Git LFS empfohlen** — Bei großen Binary-Dateien (`.uasset`, `.umap`)
- Stelle sicher, dass UE **5.8** installiert ist — ältere Versionen sind nicht kompatibel
- Bei Compile-Fehlern: Rechtsklick auf `.uproject` → "Generate Visual Studio project files" neu ausführen
