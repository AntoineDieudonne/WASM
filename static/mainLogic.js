var bin = document.getElementById('bin');
var dec = document.getElementById('dec');
var hex = document.getElementById('hex');

// Quand la valeur binaire a changé
bin.oninput = function(){
	if(wasmLoaded){
		let binVal = bin.value;
		dec.value = wasm.binToDec(binVal);
	}
}

// Quand la valeur décimale a changé
dec.oninput = function(){
	if(wasmLoaded){
		let decVal = dec.value;
		bin.value = wasm.decToBin(decVal);
	}
}

// Quand la valeur décimale a changé
hex.oninput = function(){
	if(wasmLoaded){
		let hexVal = hex.value;
		dec.value = wasm.hexToDec('0x' + hexVal);
	}
}
