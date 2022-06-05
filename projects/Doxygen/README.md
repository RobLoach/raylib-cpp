# raylib-cpp Doxygen

To build the docs, your first need the `doxygen-awesome` css theme:

```sh
# At the root of the project
git submodule add https://github.com/jothepro/doxygen-awesome-css.git
cd doxygen-awesome-css
git checkout v2.0.3
```

Then you can just build the docs
```sh
# Also at the root of the project
doxygen projects/Doxygen/Doxyfile
```
