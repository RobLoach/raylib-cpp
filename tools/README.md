## `see_missing.py`

### Usage

[Download](https://github.com/raysan5/raylib/blob/master/tools/rlparser/output/raylib_api.json) or generate a `raylib_api.json` file (via [rlparser](https://github.com/raysan5/raylib/tree/master/tools/rlparser)) and place it in the `/tools` directory.

Run the script with an appropriate Python 3 executable:

```shell
$ python3 see_missing.py
```

The script will list all raylib functions it couldn't find in the `.hpp` files under `/include`, along with their parameters.

It searches for `::<name>(`. Make sure to prefix downstream raylib calls with `::`.
