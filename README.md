# WASM

## How to run

Clone this repo then enter this command to start the flask server.
```sh
git clone https://github.com/AntoineDieudonne/WASM.git
pip install flask
python WASM/server.py
```
then open this URL in your browser http://127.0.0.1:5000/

### Limits of the converter

If you put a really big number, there will be an integer overflow. A solution to this problem would be to split the values in an array.

## How to compile the C code to generate a WASM file

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
emcc functions.c -s WASM=1 -o converter.js --no-entry -s "EXPORTED_RUNTIME_METHODS=['UTF8ToString','lengthBytesUTF8','stringToUTF8']" -s "EXPORTED_FUNCTIONS=['_malloc','_free']" -s WASM_BIGINT
```
This generates a WASM file and the functions can be called with a `<script>` reference to the converter.js file in your html file. Then call the function from your JS script like this `Module._coucou()`.

#### Help about passing strings between C and JS

- [How to pass a char\* to a javascript string](https://medium.com/@scalevectors/webassembly-c-pointers-strings-7ad50dca2103)
- [How to pass a javascript string to a char\*](https://medium.com/@scalevectors/webassembly-c-pointers-strings-part-3-8e76d604fdfd)

### How does it works

Lorem ipsum

## About the pyodide folder

### What is it

[Pyodide](https://pyodide.org/en/stable/) is a tool that allows you to run python code in your browser. It is still in developement so I had some problems with RAM consumption and executing the scikit-learn library.

### How to run it

open the pages directly in your browser and press F12 to see the messages in the console.
