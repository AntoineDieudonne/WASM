# WASM

## How to run

Clone this repo then enter this command to start the flask server
```bat
git clone https://github.com/AntoineDieudonne/WASM.git
pip install flask
python WASM/server.py
```
then open this URL in your browser [http://127.0.0.1:5000/](http://127.0.0.1:5000/)


## How to compile the C code

### Install emscripten

follow these tutorials : 
- https://emscripten.org/docs/getting_started/downloads.html
- https://developer.mozilla.org/en-US/docs/WebAssembly/C_to_wasm

### Command line used to generate the WASM file from functions.c

entrer cette ligne pour compiler le fichier en C vers du WASM :
```bat
emcc functions.c -s WASM=1 -o converter.wasm --no-entry
```

## 