'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.replace(/\s*$/, '')
        .split('\n')
        .map(str => str.replace(/\s*$/, ''));

    main();
});

function readLine() {
    return inputString[currentLine++];
}

// Complete the twoStrings function below.
function twoStrings(s1, s2) {
    var mMap = new Map();

    for(var i = 0; i < s1.length; i++){
        addOne(mMap, s1.charAt(i));
    }

    for(var i = 0; i < s2.length; i++){
        if(mMap.has(s2.charAt(i))){
            return "YES";
        }
    }
    return "NO";
}

function addOne(m, s){
    if(m.has(s)){
        m.set(s, m.get(s) + 1);
    } else{
        m.set(s, 1);
    }
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const q = parseInt(readLine(), 10);

    for (let qItr = 0; qItr < q; qItr++) {
        const s1 = readLine();

        const s2 = readLine();

        let result = twoStrings(s1, s2);

        ws.write(result + "\n");
    }

    ws.end();
}
