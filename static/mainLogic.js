var bin = document.getElementById('bin');
var dec = document.getElementById('dec');
var hex = document.getElementById('hex');

// When the binary value changed
bin.oninput = function(){
	let binVal = bin.value;
	dec.value = Module._binToDec(binVal);
	hex.value = Module.UTF8ToString(Module._binToHex(binVal));

	checkValues();
}

// When the decimal value changed
dec.oninput = function(){
	let decVal = dec.value;
	bin.value = Module._decToBin(decVal);
	hex.value = Module.UTF8ToString(Module._decToHex(decVal));

	checkValues();
}

// When the hexadecimal value changed
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
	checkValues();
}

function checkValues(){
	if(bin.value.match(/^([0-1]+)$/) || bin.value===''){
		document.getElementById('binError').hidden = true;
	}
	else{
		document.getElementById('binError').hidden = false;
		bin.value = '';
	}
	if(dec.value.match(/^([0-9]+)$/) || dec.value===''){
		document.getElementById('decError').hidden = true;
	}
	else{
		document.getElementById('decError').hidden = false;
		dec.value = '';
	}
	if(dec.value.match(/^([0-9A-Fa-f]+)$/) || hex.value===''){
		document.getElementById('hexError').hidden = true;
	}
	else{
		document.getElementById('hexError').hidden = false;
		hex.value = '';
	}
}
