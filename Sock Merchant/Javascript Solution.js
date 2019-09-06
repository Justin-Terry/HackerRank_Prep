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

function getvalue(values) {
    console.log(values);
    return value;
}

// Complete the sockMerchant function below.
function sockMerchant(n, ar) {
    var socks = new Map();
    var numOfPairs = 0;

    for (var i = 0; i < n; i++) {
        if (socks.has(ar[i])) {
            socks.set(ar[i], socks.get(ar[i]) + 1);
        } else {
            socks.set(ar[i], 1);
        }
    }

    let values = Array.from(socks.values());
    for (var i in values) {
        numOfPairs += Math.floor(values[i] / 2.0);
    }

    return numOfPairs;
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const n = parseInt(readLine(), 10);

    const ar = readLine().split(' ').map(arTemp => parseInt(arTemp, 10));

    let result = sockMerchant(n, ar);

    ws.write(result + "\n");

    ws.end();
}
