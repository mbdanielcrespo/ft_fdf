# 🗺️ FDF (Fil de Fer)

![42 Badge](https://img.shields.io/badge/42-FDF-brightgreen)
![Score](https://img.shields.io/badge/Score-100%2F100-success)
![Language](https://img.shields.io/badge/Language-C-blue)
![Graphics](https://img.shields.io/badge/Graphics-MiniLibX-orange)
![Status](https://img.shields.io/badge/Status-Completed-success)

<p align="center">
  <img src="https://raw.githubusercontent.com/byaliego/42-project-badges/main/badges/fdfe.png" alt="FDF Badge" width="150" height="150">
</p>

## 📝 Introduction

**FDF** (Fil de Fer) is a 42 School graphics project that involves creating a simple 3D wireframe renderer. The program reads a map file containing height values and renders it as a 3D wireframe model with various projections.

> "This project is about creating a simplified 3D graphic representation of a relief landscape."

FDF introduces the fundamentals of graphics programming, including managing a window, handling events, and creating images with basic transformations.

## 🎯 Project Objectives

- Read and parse 3D map files
- Render 3D wireframe models from height maps
- Implement different projection types (isometric, parallel)
- Apply color gradients based on elevation
- Handle user input for model manipulation (rotation, zoom, translation)
- Efficiently draw lines between points
- Properly manage memory and graphical resources

## 🧩 Project Structure

```
fdf/
├── includes/
│   └── fdf.h        # Header with structures and function prototypes
├── src/
│   ├── color.c      # Color handling functions
│   ├── draw.c       # Line drawing algorithms
│   ├── god.c        # Main rendering and event handling
│   ├── init.c       # Initialization functions
│   ├── main.c       # Program entry point
│   ├── projections.c # Projection transformations
│   ├── read_file.c  # Map file parsing
│   ├── setters.c    # Setting various parameters
│   └── utils.c      # Utility functions
└── Makefile        # Compilation instructions
```

## 🛠️ Implementation Details

### **color.c**
Color handling and management:

| Function | Description |
|----------|-------------|
| **parse_color** | Converts hexadecimal color strings (like "0xFF0000") to integer color values |
| **get_default_color** | Assigns default colors based on height values for gradient coloring |

### **draw.c**
Core drawing algorithms:

| Function | Description |
|----------|-------------|
| **draw_line** | Implements Bresenham's line algorithm to draw lines between points |
| **put_pixel** | Places a pixel at specific coordinates in the image buffer |

### **god.c**
Main rendering and event handling:

| Function | Description |
|----------|-------------|
| **render_map** | Coordinates the drawing of all lines to create the complete wireframe |
| **handle_events** | Processes user inputs and updates the display parameters accordingly |

### **init.c**
Setup and initialization:

| Function | Description |
|----------|-------------|
| **init_fdf** | Sets up the main FDF structure with default values and settings |
| **init_mlx** | Initializes the MiniLibX graphical context and creates a window |

### **main.c**
Program entry point:

| Function | Description |
|----------|-------------|
| **main** | Parses command-line arguments, initializes structures, and starts the main loop |

### **projections.c**
3D to 2D coordinate transformations:

| Function | Description |
|----------|-------------|
| **apply_isometric** | Transforms 3D coordinates to isometric projection (30° rotation) |
| **apply_parallel** | Applies parallel (orthographic) projection to 3D coordinates |

### **read_file.c**
Map file parsing:

| Function | Description |
|----------|-------------|
| **read_map** | Reads the map file line by line and stores height values in data structure |
| **parse_line** | Parses individual lines into coordinate and color data |

### **setters.c**
Parameter adjustment:

| Function | Description |
|----------|-------------|
| **set_zoom** | Automatically adjusts the zoom level based on map dimensions |
| **set_offsets** | Calculates initial offsets to center the map in the window |

### **utils.c**
Utility functions:

| Function | Description |
|----------|-------------|
| **ft_atoi** | Converts string representations of numbers to integers |
| **error_exit** | Handles error messages and gracefully exits the program |

## 🎮 Features

- **Multiple Projections**: Switch between isometric and parallel views
- **Dynamic Coloring**: Height-based color gradients or custom colors from map files
- **Interactive Controls**:
  - Zoom in/out
  - Rotate model
  - Pan/translate
  - Adjust height factor
- **Automatic Scaling**: Adapts to different map sizes
- **Error Handling**: Robust handling of invalid inputs and file formats

## 🖼️ Supported Map Format

The program reads maps with the following format:
```
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```

Each number represents a point in 3D space:
- Position in the grid (x,y)
- Height value (z)
- Optional color in hexadecimal format: `10,0xFF0000` for a red point at height 10

## 🧠 Skills Developed

- Graphics programming fundamentals
- 3D to 2D projection mathematics
- Event-driven programming
- Memory management for graphics resources
- File parsing and validation
- Implementation of drawing algorithms
- User interface design for interactive graphics

---

<div align="center">
  
  ### 📊 Project Stats
  
  | Metric | Value |
  |--------|-------|
  | Final Score | 100/100 |
  | File Count | 9 |
  | Graphics Library | MiniLibX |
  | Projection Types | 2 |
  
</div>

<p align="center">
  <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/Graphics-3D-ff69b4?style=for-the-badge" alt="Graphics">
  <img src="https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white" alt="42">
</p>
