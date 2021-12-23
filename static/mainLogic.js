var bin = document.getElementById('bin');
var dec = document.getElementById('dec');

// Quand la valeur binaire a changé
function binChanged(){
	if(wasmLoaded){
		let binVal = bin.value;
		dec.value = wasm.binToDec(binVal);
	}
}

// Quand la valeur décimale a changé
function decChanged(){
	if(wasmLoaded){
		let decVal = dec.value;
		bin.value = wasm.decToBin(decVal);
	}
}