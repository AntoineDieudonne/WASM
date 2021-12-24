var bin = document.getElementById('bin');
var dec = document.getElementById('dec');
var hex = document.getElementById('hex');

// Quand la valeur binaire a changé
bin.oninput = function(){
	let binVal = bin.value;
	dec.value = Module._binToDec(binVal);
	// Add binToHex
}

// Quand la valeur décimale a changé
dec.oninput = function(){
	let decVal = dec.value;
	bin.value = Module._decToBin(decVal);
	hex.value = Module.UTF8ToString(Module._decToHex(decVal));
}

// Quand la valeur décimale a changé
hex.oninput = function(){
	let hexVal = hex.value;
	dec.value = Module._hexToDec();
	// Add hexToBin
}
