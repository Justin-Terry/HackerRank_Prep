'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.replace(/\s*$/, '')
        .split('\n')
        .map(str => str.replace(/\s*$/, ''));

    main();
});

function readLine() {
    return inputString[currentLine++];
}

// Complete the makeAnagram function below.
function makeAnagram(a, b) {
    var mapA = setupMap(a);
    var mapB = setupMap(b);

    return calcDeletes(mapA, mapB);
}

function calcDeletes(m1, m2){
    var total = 0;
    m1.forEach(function (value, key){
        if(m2.has(key)){
            total += Math.abs(value - m2.get(key));
        }else{
            total += value;
        }
    });
    m2.forEach(function (value, key){
        if(!m1.has(key)){
            total += value;
        }
    });
    return total;
}

function setupMap(s){
    var m = new Map();
    for(var i = 0; i < s.length; i++){
        addOne(m, s.charAt(i));
    }
    return m;
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

    const a = readLine();

    const b = readLine();

    const res = makeAnagram(a, b);

    ws.write(res + '\n');

    ws.end();
}
