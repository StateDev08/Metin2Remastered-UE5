# Metin2 Remastered — Unreal Engine 5

Ein Fan-Remake von Metin2 in Unreal Engine 5.1 (Blueprint-basiert).

## Projektstruktur

```
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

- **Unreal Engine 5.1** (Epic Games Launcher)
- Windows 10/11

## Projekt öffnen

1. UE 5.1 über den Epic Games Launcher installieren
2. Repository klonen: `git clone https://github.com/StateDev08/Metin2Remastered-UE5.git`
3. `Metin2Remastered.uproject` doppelklicken oder über den UE5 Browser öffnen
4. Standard-Map: `ThirdPersonMap` (Editor Startup Map)

## Aktivierte Plugins

- **ModelingToolsEditorMode** — 3D-Modellierung im Editor
- **Volumetrics** — Volumetrische Effekte (Wolken, Nebel)
- **Water** — Wasser-System

## Features

- 5 verschiedene Maps basierend auf Metin2-Gebieten
- Warrior-Charakter mit Combo-System (One-Hand Sword: 7 Combo-Animationen, 3 Montage-Level)
- Sura-Charakter mit eigenem Modell
- Hair-Changing-System
- Landscape-Materialien mit Virtual Textures
- Lumen Global Illumination & Virtual Shadow Maps

## Rendering-Einstellungen

- DirectX 12 (Standard-RHI)
- Lumen Reflections & Global Illumination
- Virtual Shadow Maps
- Virtual Textures
- Kein Ray-Tracing (deaktiviert)

## Hinweise

- **Kein C++ Code** — Das Projekt ist rein Blueprint-basiert
- **Git LFS empfohlen** — Bei großen Binary-Dateien (`.uasset`, `.umap`) empfiehlt sich die Einrichtung von Git LFS
- Die `.uproject`-Datei referenziert UE 5.1 — stelle sicher, dass diese Version installiert ist
