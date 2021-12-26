# WASM


## How to run

Download or clone this repo then enter this command to start the flask server. (you need to have python installed)
```sh
git clone https://github.com/AntoineDieudonne/WASM.git
pip install flask
python WASM/server.py
```
then open this URL in your browser http://127.0.0.1:5000/

### Limits of the converter

If you put a really big number, there will be an integer overflow. A solution to this problem would be to split the values in an array to allow unlimited size.


## How to compile the C code to generate a WASM file

If you want to edit the [functions coded in C](https://github.com/AntoineDieudonne/WASM/blob/main/static/functions.c), you'll need to install emscripten to compile the C to WASM.

### Install emscripten

follow these tutorials : 
1. https://emscripten.org/docs/getting_started/downloads.html
2. https://developer.mozilla.org/en-US/docs/WebAssembly/C_to_wasm

### Commands used to generate the WASM file from functions.c

```sh
# In your emsdk folder (this is the command for windows OS)
# Do this every time you open a console
emsdk_env.bat

# Then enter this in the WASM/Static folder
emcc functions.c -s WASM=1 -o converter.js --no-entry -s WASM_BIGINT -s "EXPORTED_RUNTIME_METHODS=['UTF8ToString','lengthBytesUTF8','stringToUTF8']" -s "EXPORTED_FUNCTIONS=['_malloc','_free']"
```
This generates a WASM file and the functions can be called with a `<script>` reference to the converter.js file in your html file. Then call the function from your JS script like this `Module._coucou()`.

#### Details about the emcc command arguments

- Like gcc, the `emcc functions.c -o converter.js` compiles the .c file into the converter.js file.
- The `-s WASM=1` generates a WASM file in addition to the javascript file.
- The `--no-entry` allows emcc to compile a C file without a main function.
- the `-s WASM_BIGINT` is necesary in order to have 64-bit coded integers.
- `-s "EXPORTED_RUNTIME_METHODS=['UTF8ToString','lengthBytesUTF8','stringToUTF8']"` adds the named functions into the js module generated.
- `-s "EXPORTED_FUNCTIONS=['_malloc','_free']"` exports the C functions malloc and free to manage the memory from the JS.

If you don't need arrays in your code, you can remove the functions exports, only generate a .wasm file with a command like thet : `emcc functions.c -o converter.wasm`.Then instantiate the module yourself like I did originally in [initWasm.js](https://github.com/AntoineDieudonne/WASM/blob/main/static/initWasm.js). However, if you need to export runtime methods, it is easier to let emscripten generate the js module.

#### Help about passing strings between C and JS

- [How to pass a char\* to a javascript string](https://medium.com/@scalevectors/webassembly-c-pointers-strings-7ad50dca2103)
- [How to pass a javascript string to a char\*](https://medium.com/@scalevectors/webassembly-c-pointers-strings-part-3-8e76d604fdfd)


## About the pyodide folder

### What is it

[Pyodide](https://pyodide.org/en/stable/) is a tool that allows you to run python code in your browser. It is still in developement so I had some problems with RAM consumption and executing the scikit-learn library.

### How to run it

open the pages directly in your browser and press F12 to see the messages in the console.
