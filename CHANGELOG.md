# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [vX.X.X] - Unreleased
### Added
- `Model.Draw()`
- `Model.DrawWires()`
- `models_first_person_maze.cpp` example
- Error correction when unloading images, materials, models and meshes

## [v3.5.0-alpha1] - 2020-12-26
### Changed
- Update to raylib 3.5.0

### Added
- Documentation

### Removed
- Static inline Color variables (like `raylib::Color::RayWhite`). Instead, use `::RAYWHITE`.
