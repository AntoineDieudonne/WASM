var wasm;
var wasmLoaded = false;

// Valeurs pour instancier WebAssembly
let wasmMemory = new WebAssembly.Memory({initial: 256, maximum: 256});
let wasmTable = new WebAssembly.Table({
    'initial': 1,
    'maximum': 1,
    'element': 'anyfunc'
});
let asmLibraryArg = { 
    "__handle_stack_overflow": ()=>{},
    "emscripten_resize_heap": ()=>{},
    "__lock": ()=>{}, 
    "__unlock": ()=>{},
    "memory": wasmMemory, 
    "table": wasmTable 
};
let info = {
	'env': asmLibraryArg,
	'wasi_snapshot_preview1': asmLibraryArg,
};

async function loadWasm(){
	let res = await fetch('static/converter.wasm');
	let buf = await res.arrayBuffer();
	let obj = await WebAssembly.instantiate(buf, info);
	wasm = obj.instance.exports;
	if(wasm !== undefined) wasmLoaded = true;
}

loadWasm();