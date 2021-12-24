var bin = document.getElementById('bin');
var dec = document.getElementById('dec');
var hex = document.getElementById('hex');

// Quand la valeur binaire a changé
bin.oninput = function(){
	let binVal = bin.value;
	dec.value = Module._binToDec(binVal);
	hex.value = Module.UTF8ToString(Module._binToHex(binVal));
}

// Quand la valeur décimale a changé
dec.oninput = function(){
	let decVal = dec.value;
	bin.value = Module._decToBin(decVal);
	hex.value = Module.UTF8ToString(Module._decToHex(decVal));
}

// Quand la valeur hexadécimale a changé
hex.oninput = function(){
	let hexVal = hex.value;

	// Convert the js string to a char*
	const hexLen = Module.lengthBytesUTF8(hexVal) + 1;
	hexArg = Module._malloc(hexLen);
	Module.stringToUTF8(hexVal, hexArg, hexLen);

	dec.value = Module._hexToDec(hexArg);
	bin.value = Module._hexToBin(hexArg);

	// Free the memory taken by the string
	Module._free(hexArg);
}
