#!/usr/bin/python3

"""
lists missing calls to raylib functions

usage: python3 see_missing.py
"""

import json
import sys
from pathlib import Path


def print_err(*args, **kwargs) -> None:
    print(*args, file=sys.stderr, **kwargs)


def main() -> int:
    raylib_api_path = Path("raylib_api.json")
    if not raylib_api_path.exists():
        print_err("raylib_api.json not found"
                  "\n\nget it at raylib/tools/rlparser/output")
        return 1

    raylib_api: dict[str, list] = json.loads(raylib_api_path.read_text())
    raylib_funcs: dict[str, dict] = {func["name"]: func for func in raylib_api["functions"]}

    raylib_cpp_files: list[Path] = list(Path("../include").glob("**/*.hpp"))
    raylib_cpp_combined: str = "\n".join(x.read_text() for x in raylib_cpp_files)

    found_func_calls: int = 0
    print("\n\nmissing calls for:\n")
    for func_name, func in raylib_funcs.items():
        if f"::{func_name}(" in raylib_cpp_combined:
            found_func_calls += 1
            continue
        params = ", ".join(f"{param["type"]} {param["name"]}" for param in func.get("params", {}))
        print_err(f"::{func_name}({params})")

    percentage: float = round((found_func_calls / len(raylib_funcs)) * 100, 2)
    print(f"\n{found_func_calls}/{len(raylib_funcs)} implemented ({percentage}%)")

    return 0


if __name__ == "__main__":
    sys.exit(main())
