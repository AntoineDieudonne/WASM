# WASM

## How to run

Clone this repo then enter this command to start the flask server.
```sh
git clone https://github.com/AntoineDieudonne/WASM.git
pip install flask
python WASM/server.py
```
then open this URL in your browser [http://127.0.0.1:5000/](http://127.0.0.1:5000/)


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
emcc functions.c -s WASM=1 -o converter.wasm --no-entry
```

### How does it works

Lorem ipsum

### About the pyodide folder

## What is it

[Pyodide](https://pyodide.org/en/stable/) is a tool that allows you to run python code in your browser. It is still in developement so I had some problems with RAM consumption and executing the scikit-learn library.

## How to run it

open the pages directly in your browser and press F12 to see the messages in the console.
